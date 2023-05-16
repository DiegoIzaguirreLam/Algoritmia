
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 15 de mayo de 2023, 02:42 PM
 */

#include <cstdlib>
#include <iostream>
#include "pila.h"
using namespace std;

Elemento cima(Pila P){
    return P.cima->elem;
}

void calculaIntervalo(int arr[], int res[], int n){
    Pila P;
    construir(&P);
    int i=0;
    while(i<n){
        if(!esPilaVacia(P) && arr[i]>=arr[cima(P)])
            desapilar(&P);
        else{
            if(esPilaVacia(P))
                res[i]=i;
            else
                res[i]=i-cima(P)-1;
            apilar(&P, i);
            i++;
        }
    }
}

int main(int argc, char** argv) {
    int n=8;
    int arr[]={10, 20, 15, 10, 12, 10, 13, 18};
    int res[8]={};
    
    calculaIntervalo(arr, res, n);
    for(int i=0;i<8;i++) cout<<res[i]<<" ";
    return 0;
}

