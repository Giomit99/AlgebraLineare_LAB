#include <iostream>
#include <cmath>

using namespace std;
/*
    1° Laboratorio ALAN svolto da
        -Gjorche Mitkov 5025307
        -Francesco Filippone 2293006
        -Nicolò Vizzini 5013791
    Esercizio 1:

    Considerare il numero di matricola in ordine alfabetico.
    d0 -> ultima cifra
    d1 -> penultima cifra

    a = (d0 +1)·10^i con i = 0,1,...,6
    b = (d1 +1)·1020
    c = −b

    calcolare (a+b)+c e a+(b+c)

    Matricola: 2293006
    d0 = 6
    d1 = 0
*/

//matricola: 2293006
const int d0= 6;
const int d1= 0;

int main() {
    //Siccome b e c sono indipendenti dalla variabile i li calcolo a priori
    double a, b = (d1 + 1) * pow(10, 20), c = -b;

    cout<< "Valori di b= " << b << " valore di c= "<< c << endl << endl;

    for (int i = 0; i < 7; i++) {
        cout<< "CICLO NUMERO: " << i << endl;
        //calcolo a
        a = (d0 + 1) * pow(10, i);

        cout<< "a= "<< a << endl;
    
        cout << "(a+b)+c vale: " << (a + b) + c << endl;
        cout << "a+(b+c) vale: " << a + (b + c) << endl << endl;
    }

    cout << "***************************************************************";
}