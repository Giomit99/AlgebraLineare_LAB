#include <iostream> 
#include <cmath> 
#include <iomanip> 

using namespace std;
/*
    1° Laboratorio ALAN svolto da
        -Gjorche Mitkov 5025307
        -Francesco Filippone 2293006
        -Nicolò Vizzini 5013791

    Esercizio 2:
        Calcolo di exp(x) con math.h e serie di Taylor:
            - x assume valori: { 0.5, 30, -0,5, -30 }
            - Espansione di Taylor con approssimazioni 0->n di { 3, 10, 50, 100 e 150 }
 */

 /*****************************************PROTOTIPI DELLE FUNZIONI******************************************/
double fattoriale(double);
double taylor(double, double);

const int sizeX= 4;
const int sizeN= 5;

int main() {
    const double x[sizeX] = { 0.5, 30, -0.5, -30 }; // valori di x da calcolare
    const double N[sizeN] = { 3, 10, 50, 100, 150 }; // numero di passi di taylor
    
//Primo algoritmo 
	cout << endl << "Algoritmo 1:\n";

	for(int i=0; i<sizeX; i++){
		cout<< "x= " << x[i] << endl;

		for(int j=0; j<sizeN; j++){
			double esp = exp(x[i]);
			double res = taylor(x[i], N[j]); 

			double err_assoluto = res - esp;	
			double err_relativo = (res - esp) / esp;

			cout << "Errore assoluto con x=" << x[i] << " e N=" << N[j] << ": " << err_assoluto << endl;
			cout << "Errore relativo con x=" << x[i] << " e N=" << N[j] << ": " << err_relativo << endl << endl;
		}	

		cout << "***************************************************" << endl;
	}

	//Secondo algoritmo
	cout << "\nAlgoritmo 2:\n";

	// lo trovo solo per 0.5 e 30 per poi fare il reciproco
	for(int i=0; i<2; i++){
		cout << "x= " << x[i+2] << endl;

		for(int j=0; j<sizeN; j++){
			// confronto l'esp dei negativi (shifto i di 2)
			double esp = exp(x[i+2]);

			// con il reciproco del risultato della taylor sui positivi
			double res = 1/taylor(x[i], N[j]); 

			double err_assoluto = res - esp;
			double err_relativo = (res - esp) / esp;

			cout << "Errore assoluto con x=" << x[i+2] << " e N=" << N[j] << ": " << err_assoluto << endl;
			cout << "Errore relativo con x=" << x[i+2] << " e N=" << N[j] << ": " << err_relativo << endl << endl;
		}	

		cout << "***************************************************" << endl;
	}
}

/*****************************************FUNZIONI******************************************/
//Funzione fattoriale ricorsiva n!
double fattoriale(double n) {
    if (n > 1)
        return n * fattoriale(n - 1);
    else
        return 1;
}

// Serie di Taylor
double taylor(double x, double n) {
    double somma = 0;

    for (int i = 0; i <= n; i++)
        somma += pow(x, i) / fattoriale(i);

    return somma;
}