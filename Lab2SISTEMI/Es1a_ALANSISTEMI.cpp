#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int norma_infinito(vector<vector<int>>);

int main (){
    vector<vector<int>> V1={
        {3,  1, -1,  0},
        {0,  7, -3,  0},
        {0, -3,  9, -2},
        {0,  0,  4, -10}
    };

    cout<< "La norma infinito della prima matrice V1 e': "<< norma_infinito(V1) << endl;

    vector<vector<int>> V2={
        {2,  4, -2,  0},
        {1,  3, -0,  1},
        {3, -1,  1,  2},
        {0, -1,  2,  1}
    };

    cout<< "La norma infinito della seconda matrice V2 e': "<< norma_infinito(V2) << endl;
}

int norma_infinito(vector<vector<int>> V){
    //Variabile che tiene conto della massima riga incontrata
	int SommaMax = 0;

	// itero sulle righe
	for(int m=0; m<V.size(); m++){
		int sommaRiga = 0;
				
		// calcolo la somma dei moduli degli elementi della riga
		for(int n=0; n<V[m].size(); n++)
			sommaRiga += abs(V[m][n]);

		if(sommaRiga > SommaMax)
			SommaMax = sommaRiga; 
	}

	return SommaMax;
}