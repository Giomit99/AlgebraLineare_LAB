#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Costante per la dimensione della matrice di pascal
const int dim= 10;

/***************************************************/
//Funzione per la generazione della matrice di pascal
vector<vector<double>> genMatrice(int);
//Funzione per il calcolo del fattoriale
double fattoriale(double);
//Funzione per il calcolo della norma infinito
double norma_infinito(vector<vector<double>>);
/***************************************************/

int main(){
    vector<vector<double>> pascalV= genMatrice(dim);

    cout<< "La norma infinito della matrice di pascal con N= " << dim << " e': " << norma_infinito(pascalV)<< endl;
}

vector<vector<double>> genMatrice(int n){
    vector<vector<double>> vP;

    for(int i= 1; i<=n; ++i){
        vector<double> vTemp;

        for(int j=1; j<=n; ++j){
            double num= fattoriale(i + j - 2);
            
            double den= fattoriale(i - 1) * fattoriale(j - 1);

            double ris= num/den;

            vTemp.push_back(ris);
        }

        vP.push_back(vTemp);
    }

    return vP;
}

double fattoriale(double n){
    double somma= 1;

    for(int i=n; i>0; --i)
        somma= somma* i;

    return somma;
}

double norma_infinito(vector<vector<double>> V){
    //Variabile che tiene conto della massima riga incontrata
	double SommaMax = 0;

	// itero sulle righe
	for(int m=0; m<V.size(); m++){
		double sommaRiga = 0;
				
		// calcolo la somma dei moduli degli elementi della riga
		for(int n=0; n<V[m].size(); n++)
			sommaRiga += abs(V[m][n]);

		if(sommaRiga > SommaMax)
			SommaMax = sommaRiga; 
	}

	return SommaMax;
}