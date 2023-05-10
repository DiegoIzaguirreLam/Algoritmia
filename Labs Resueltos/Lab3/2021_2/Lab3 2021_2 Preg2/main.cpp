/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 8 de mayo de 2023, 03:45 PM
 */
#include <iostream>
#include <cstdlib>
#include "cola.h"
#include "pila.h"

using namespace std;

void hanoi(int n, Pila *pOrig, Pila *pDest, Pila *pAux){
    if(n==0) return;
    hanoi(n-1, pOrig, pAux, pDest);
    apilar(pDest, desapilar(pOrig));
    hanoi(n-1, pAux, pDest, pOrig);
}

void merge(int A[], int inicial, int medio, int final){
	int longitud1, longitud2, i, p, q;
	
	longitud1=(medio+1)-inicial;//primera mitad del arreglo
	longitud2=final-medio;//segunda mitad del arreglo
	
	int P[longitud1+1];
	int Q[longitud2+1];
	
	//agrego los valores mayores de ambos arreglos
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	//copiamos los valores desde A hacia los arreglos auxiliares P y Q
	for (i=inicial;i<=medio;i++)
		P[i-inicial]=A[i];
	for (i=medio+1;i<=final;i++)
		Q[i-(medio+1)]=A[i];
	
	p=q=0;
	for (i=inicial;i<=final;i++)
		if (P[p]<Q[q])
			A[i]=P[p++];
		else
			A[i]=Q[q++];
}

void mergesort(int A[], int inicial, int final){
	if (inicial==final)
		return;
	int medio=(inicial+final)/2;
	mergesort(A,inicial, medio);//logn
	mergesort(A,medio+1, final);//logn
	merge(A, inicial, medio, final);
}

int main(int argc, char** argv) {
    Cola C1;
    Pila P1, PAux, PAux2;
    construir(&C1);
    construir(&P1);
    construir(&PAux);
    construir(&PAux2);
    
    int memoria[10], i, elem, posmem=0;
    encolar(&C1, 2);
    encolar(&C1, 8);
    encolar(&C1, 10);
    encolar(&C1, 8);
    encolar(&C1, 5);
    encolar(&C1, 3);
    
    while(!esColaVacia(C1)){
        elem=desencolar(&C1);
        for(i=0;i<posmem;i++)
            if(memoria[i]>elem) break;
        hanoi(i, &P1, &PAux, &PAux2);
        apilar(&P1, elem);
        hanoi(i, &PAux, &P1, &PAux2);
        memoria[posmem]=elem;
        mergesort(memoria, 0, posmem);// se ordena la memoria
        posmem++;
    }
    mostrar(P1);
    return 0;
}

