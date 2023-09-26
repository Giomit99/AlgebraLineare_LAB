#include <iostream>
#include <cmath> 

using namespace std;
/*
    1 Laboratorio ALAN svolto da
        -Gjorche Mitkov 5025307
        -Francesco Filippone 2293006
        -Nicolò Vizzini 5013791


    ESERCIZIO 3:
        Calcolo della precisione di macchina 'eps'
        eps = 2^{-d} con d piu' grande intero positivo t.c. 1+2^{-d} > 1
        calcolare eps in singola precisione e doppia precisione
 */

int main() {
    int t=0;

    float eps_singola = 0; // eps in singola precisione
    double eps_doppia = 0; // eps in doppia precisione

    float d_singola; // d in singola precisione
    double d_doppia; // d in doppia precisione
    
    do{
        eps_singola= pow(2, -t);
        d_singola= 1+ eps_singola;
        t++;
    }while(d_singola > 1);

    t=0;

    do{
        eps_doppia= pow(2, -t);
        d_doppia= 1+ eps_doppia;
        t++;
    }while(d_doppia > 1);

    cout << "\nConfronto tra esp con singola precisione ed esp con doppia precisione\n";
    cout<< "eps con singola precisione: " << eps_singola << endl;
    cout<< "eps con doppia precisione: " << eps_doppia << endl << endl;
}