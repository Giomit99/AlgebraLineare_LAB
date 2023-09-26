#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/***************************************************/
//Funzione per la generazione della matrice di pascal
vector<vector<double>> genMTri(int);
//Funzione per il calcolo del fattoriale
double fattoriale(double);
//Funzione per il calcolo della norma infinito
double norma_infinito(vector<vector<double>>);
/***************************************************/

int main(){
    //Matricola= ***07
    int d1= 0, d0= 7;

    //Dimensione della matrice, matricola=***07
    int dim= 10*(d1+1)+d0;

    vector<vector<double>> T = genMTri(dim);

    cout<< "La norma infinito della matrice con N= " << dim << " e': " << norma_infinito(T) << endl;
}

vector<vector<double>> genMTri(int n){
    vector<vector<double>> vTriang;

    for(int i= 1; i<=n; ++i){
        vector<double> vTemp;

        for(int j=1; j<=n; ++j){
            if(i == j) 
                vTemp.push_back(2);

            else if (abs(i - j) == 1) 
                vTemp.push_back(-1);

            else vTemp.push_back(0);
        }

        vTriang.push_back(vTemp);
    }

    return vTriang;
}

double norma_infinito(vector<vector<double>> V){
    //Variabile che tiene conto della massima riga incontrata
	double sommaMax = 0;

	// itero sulle righe
	for(int m=0; m<V.size(); m++){
		double sommaRiga = 0;
				
		// calcolo la somma dei moduli degli elementi della riga
		for(int n=0; n<V[m].size(); n++)
			sommaRiga += abs(V[m][n]);
		
		if(sommaRiga > sommaMax)
			sommaMax = sommaRiga; 
	}

	return sommaMax;
}