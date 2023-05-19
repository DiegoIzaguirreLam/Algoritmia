
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 18 de mayo de 2023, 12:26 AM
 */

#include <cstdlib>
#include <iostream>
#include "listaSimple.h"
#include "pila.h"
#include "cola.h"
using namespace std;



void unirListas(Lista &L1, Lista &L2){
    L1.cola->sig=L2.cabeza;
    L1.cola=L2.cola;
    L1.longitud += L2.longitud;
    L2.cabeza=NULL;//faja2 vaciada
    L2.cola=NULL;
    L2.longitud=0;
}


int cuentaUnos(int arr[], int ini, int fin, int cont, int flag){
    if(ini==fin){
        return cont+arr[ini];
    }
    if(ini>fin) return cont;
    
    int med=(ini+fin)/2;
    
    if(arr[med]==1 && flag==0){
        return cuentaUnos(arr, ini, med-1, cont+fin-med+1, flag);
    }
    else if(arr[med]==1 && flag==1){
        return cuentaUnos(arr, med+1, fin, cont+med-ini+1, flag);
    }
    else if(arr[med]==0 && flag==0){
        return cuentaUnos(arr, med+1, fin, cont, flag);
    }
    else if(arr[med]==0 && flag==1){
        return cuentaUnos(arr, ini, med-1, cont, flag);
    }
}

void pasarAPilas(Lista &L1, Pila &pAme, Pila &pPep, Pila &pHaw){
    Nodo *p=L1.cabeza, *aux;
    while(p!=NULL){
        aux=p->sig;
        if(p->elem==1) apilar(pAme, p->elem);
        else if(p->elem==2) apilar(pPep, p->elem);
        else if(p->elem==3) apilar(pHaw, p->elem);
        delete p;
        p=aux;
    }
    L1.cabeza=NULL;
    L1.longitud=0;
}

void pasarCola(Cola &Cempaq, Pila &pAme, Pila &pPep, Pila &pHaw){
    while(!esPilaVacia(pAme) && !esPilaVacia(pPep) && !esPilaVacia(pHaw)){
        encolar(Cempaq, desapilar(pAme));
        encolar(Cempaq, desapilar(pPep));
        encolar(Cempaq, desapilar(pHaw));
    }
}


int main(int argc, char** argv) {
	int n=7;
	int arr1[]={1,1,1,0,0,0,0};
        int pro1[]={2,1,3,2,3,1,1};
        
	int arr2[]={1,1,1,1,1,1,0};
        int pro2[]={1,2,3,3,3,2,1};
        
	int arr3[]={1,1,1,1,1,0,0};
        int pro3[]={1,2,1,1,3,1,2};
        
	int arr4[]={0,0,1,1,1,1,1};
        int pro4[]={3,1,3,2,3,3,1};
        cout<<"Para bandeja  1: "<<cuentaUnos(arr1, 0, n-1, 0, arr1[0])<<endl;
        cout<<"Para bandeja  2: "<<cuentaUnos(arr2, 0, n-1, 0, arr2[0])<<endl;
        cout<<"Para bandeja  3: "<<cuentaUnos(arr3, 0, n-1, 0, arr3[0])<<endl;
        cout<<"Para bandeja  4: "<<cuentaUnos(arr4, 0, n-1, 0, arr4[0])<<endl;
        
        Lista L1, L2, L3, L4;
        construir(L1);
        construir(L2);
        construir(L3);
        construir(L4);
        for(int i=0;i<7;i++)
            if(arr1[i]) insertarFinal(L1, pro1[i]);
        for(int i=0;i<7;i++)
            if(arr2[i]) insertarFinal(L2, pro2[i]);
        for(int i=0;i<7;i++)
            if(arr3[i]) insertarFinal(L3, pro3[i]);
        for(int i=0;i<7;i++)
            if(arr4[i]) insertarFinal(L4, pro4[i]);
        
        mostrar(L1); mostrar(L2); mostrar(L3); mostrar(L4);
        
        unirListas(L1, L2);
        unirListas(L1, L3);
        unirListas(L1, L4);
        
        mostrar(L1); mostrar(L2); mostrar(L3); mostrar(L4);
        
        Cola Cempaq;
        construir(Cempaq);
        Pila pAme, pPep, pHaw;
        construir(pAme); construir(pPep); construir(pHaw);
        
        pasarAPilas(L1, pAme, pPep, pHaw);
        
        pasarCola(Cempaq, pAme, pPep, pHaw);
        mostrar(Cempaq);
        mostrar(pAme);
        mostrar(pPep);
        mostrar(pHaw);
    return 0;
}

