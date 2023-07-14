
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 13 de julio de 2023, 11:36 PM
 */

#include <cstdlib>
#include <iostream>
#include "AB.h"

using namespace std;
void creaNivel(AB &A1,int arr[],int i,int n){
    if(i==n){
        return;
    }
    Elemento e;
    e.peso = arr[i];
    
    e.cromo=0;
    insertaHizq(A1, e);
    e.cromo=1;
    insertaHder(A1, e);
    
    creaNivel(A1->hizq, arr, i+1, n);
    creaNivel(A1->hder, arr, i+1, n);
}


void crearArbol(AB &A1, int arr[], int n){
    construir(A1);
    Elemento e;
    e.cromo=0; e.peso=0;
    creaPivot(A1, e);
    creaNivel(A1, arr, 0, n);
}

int hallaCombinaciones(AB A1, int peso){
    if(A1->hizq==NULL && A1->hder==NULL){
        peso = peso - A1->e.cromo * A1->e.peso;
        if(peso==0)
            return 1;
        else
            return 0;
    }
    else{
        peso = peso-A1->e.cromo*A1->e.peso;
        return hallaCombinaciones(A1->hizq, peso) + hallaCombinaciones(A1->hder, peso);
    }
}

int main(int argc, char** argv) {
    AB A1;
    int arr[]={10, 50, 20, 30, 40};
    int n=5;
    crearArbol(A1, arr, n);
    
    mostrarEnOrden(A1);
    cout<<endl;
    int peso=70;
    cout<<"Se hallaron "<<hallaCombinaciones(A1, peso)<< " combinaciones"<<endl;
    return 0;
}

