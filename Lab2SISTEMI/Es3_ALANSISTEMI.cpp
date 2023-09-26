#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/***********************************************/
vector<vector<float>> genMatrice(int); //Generare la matrice di Pascal
float fattoriale(float);  
vector<vector<float>> genMTri(int);    //Generare la matrice Tridiagnonale
void printM(vector<vector<float>>);    //Stampa la matrice
vector<float> calcoloB(vector<vector<float>>, vector<int>);
vector<int> soluzS(int);
vector<float> calcGauss(vector<vector<float>>, vector<float>);  //Esegue la riduzione di gauss
void swap(vector<vector<float>> &, int, int);
void printV(vector<float>);
vector<float> calcPert_B_(vector<float>);
vector<float> addVector(vector<float> v, vector<float> w);
/***********************************************/

int main(){
	for(;;){
        //Costruisco la matrice A (senza richiedere all'utante di immettere direttamente gli elementi) ma scegliendo una delle 4 matrici
		// —  costruisca la matrice A (senza richiedere all’utente di immettere direttamente gli elementi);
		int MatrS;

		cout << "Scegli quale matrice usare (da 1 a 4): " << endl;
		cout << "1: Matrice A standard." << endl;
		cout << "2: Matrice B standard." << endl;
		cout << "3. Matrice di Pascal." << endl;
		cout << "4. Matrice Tridiagonale." << endl;
		cout << "Oppure un valore diverso per uscire dal programma." << endl;
        cout << "Inserisci: ";
		cin >> MatrS;

		vector<vector<float>> A;
		int N= 4;

		switch (MatrS) {
            case 1: 
                A={
                    {3,  1, -1,  0},
                    {0,  7, -3,  0},
                    {0, -3,  9, -2},
                    {0,  0,  4, -10}
                };
                break;

            case 2: 
                A={
                    {2,  4, -2,  0},
                    {1,  3, -0,  1},
                    {3, -1,  1,  2},
                    {0, -1,  2,  1}
                };
                break;

            case 3: 
                N = 10;
                A = genMatrice(N);
                break;
            
            case 4: 
                N = 17;
                A = genMTri(N);
                break;

            default: 
                cout << "Non hai inserito un numero valido." << endl;
                exit(EXIT_FAILURE);
		}

		cout << "\n\nLa matrice A: " << endl;
		printM(A);
		cout << endl << endl;

		// —  assumendo nota la soluzione del sistema ̄x= (1,1,...,1)^t, calcoli il corrispondente termine noto dato dal prodotto b = A· ̄x;
        //Vettore delle soluzioni x
        vector<int> xTild = soluzS(N);
		
		vector<float> b = calcoloB(A, xTild);
		 cout<< "Il vettore b: \n";
        printV(b);

        // —  risolva in precisione singola il sistema Ax=b tramite l’algoritmo di eliminazione Gaussiana.
		vector<float> xRidG = calcGauss(A, b);
        cout<< "\nIl vettore x tramite l'algoritmo Gauss: \n";
        printV(xRidG);

		/*******************3° PARTE******************/
		cout<<"\n/*******************3 PARTE******************/";
		vector<float> b_pert = calcPert_B_(b);
		cout << "\nIl vettore b perturbato: " << endl;
		printV(b_pert);

		vector<float> b_sum = addVector(b, b_pert);
		cout << "\nIl vettore b sommato a b perturbato: " << endl;
		printV(b_sum);

		vector<float> x_pert = calcGauss(A, b_sum);
		cout << "\nIl vettore x perturbato: " << endl;
		printV(x_pert);

		cout<<"/********************************************************************/\n\n";
	}
}

//Matrice di Pascal
vector<vector<float>> genMatrice(int n){
    vector<vector<float>> vP;

    for(int i= 1; i<=n; ++i){
        vector<float> vTemp;

        for(int j=1; j<=n; ++j){
            float num= fattoriale(i + j - 2);
            
            float den= fattoriale(i - 1) * fattoriale(j - 1);

            float ris= num/den;

            vTemp.push_back(ris);
        }

        vP.push_back(vTemp);
    }

    return vP;
}

float fattoriale(float n){
    float sum= 1;

    for(int i=n; i>0; --i){
        sum= sum* i;
    }

    return sum;
}

//Matrice Triadiagonale
vector<vector<float>> genMTri(int n){
    vector<vector<float>> vTriang;

    for(int i= 1; i<=n; ++i){
        vector<float> vTemp;

        for(int j=1; j<=n; ++j){
            if(i == j) vTemp.push_back(2);

            else if (abs(i - j) == 1) vTemp.push_back(-1);

            else vTemp.push_back(0);
        }

        vTriang.push_back(vTemp);
    }

    return vTriang;
}

void printM(vector<vector<float>> V){
    for (int i= 0; i< V.size(); ++i){
        for(int j= 0; j < V[i].size(); ++j){
            if(j != 0)
                cout << "\t";

            cout << V[i][j];
        }
        cout << endl;
    }
}

vector<int> soluzS(int N){
    vector<int> x;

    for(int i= 0; i<N; ++i)
        x.push_back(1);

    return x;
}
	
vector<float> calcoloB(vector<vector<float>> v, vector<int> x){
	// dichiaro il vettore che poi sarà restituito
	vector<float> res;

	// itero su righe e colonne e calcolo b
	for(int i = 0; i<v.size(); i++)
	{
		// b è la somma degli elementi della riga
		int b = 0;

		for(int j = 0; j<v.size(); j++)
			b += v[i][j] * x[j];	
		
		// metto b nel vettore
		res.push_back(b);
	}

	return res;
}

vector<float> calcGauss(vector<vector<float>> a, vector<float> b){
	int N = a.size();
	float m;

	//creo un vettore d'appoggio che mi serve per calcolare la riduzione di gauss
	vector<vector<float>> v;

	// itero su righe e colonne
	for(int k=0; k<N-1; k++){
		for(int i=k+1; i<N; i++){
			if(a[k][k] == 0){			
				swap(a, k, k); 

				// ritorno all'iterazione precedente
				k--;
				break;
			}

			m = a[i][k] / a[k][k];

			for(int j = k; j<N; j++)
				a[i][j] = a[i][j] - m * a[k][j];
			
			b[i] = b[i] - m * b[k];
		}
	}

	vector<float> x(N);
 
	x[N-1] = b[N-1] / a[N-1][N-1];
                  
	for(int i = N-2; i>=0; i--){
		float temp = b[i];

		for(int k=i+1; k<N; k++)
			temp = temp - a[i][k] * x[k];

		x[i] = temp / a[i][i];
	}

	//Ritorno i valori delle incognite
	return x;
}

void swap(vector<vector<float>> &v, int r, int c){
	int indexSwap=-1;

	for(int i=r; i<v.size(); i++){
		if(v[i][c] != 0)
			indexSwap = i;
	}

	if(indexSwap == -1) {
		cout << "Colonna composta da soli zeri." << endl;
		exit(EXIT_FAILURE);		
	}

	else
		for(int i=0; i<v.size(); i++){
			int temp=v[r][i];

			v[r][i] = v[indexSwap][i];
			v[indexSwap][i] = temp;
		}
}

void printV(vector<float> v){
    for(int i=0; i<v.size(); ++i)
        cout << v[i] << "\t";

    cout << endl;
}

/*******************3° PARTE******************/
vector<float> calcPert_B_(vector<float> v){
	// dichiaro il vettore che poi sarà restituito
	vector<float> res;

	float n_inf = INT_MIN;         

	for(int i=0; i<v.size(); i++)
		if(abs(v[i]) > n_inf)
			n_inf = abs(v[i]);

	for(int i=0; i<v.size(); i++){
		if(i%2 == 0)
			res.push_back(n_inf*(-0.01));
		else
			res.push_back(n_inf*(0.01));
	}

	return res;
}

vector<float> addVector(vector<float> v, vector<float> w){
	// dichiaro il vettore che poi sarà restituito
	vector<float> res;

	// se le size non sono uguali torno un errore
	if(v.size() != w.size())
		cerr << "I due vettori hanno diverse dimensione!" << endl;
		
	for(int i=0; i<v.size(); i++)
		res.push_back((v[i]+w[i]));

	return res;
}