/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 10 de mayo de 2023, 05:43 PM
 */

#include <cstdlib>
#include <iostream>
#include "cola.h"
#include "listaSimple.h"
using namespace std;

void generaLista( Lista &L1, int n){
    for(int i=2;i<=n;i++)
        insertarFinal(L1, i);
}

void generaCola( Lista &L1, Nodo *p, Cola &C, int i){
    if(p==NULL){
        return;
    }
    Nodo *sigAux=p->sig;
    if(p->elem%i == 0 && p->elem!=i){
        Elemento aux=p->elem;
        
        encolar(&C, aux);
        sigAux=p->sig;
        eliminar(&L1, aux);
    }
    generaCola(L1, sigAux, C, i);
}

void imprimeFinal(Nodo *p){
    if(p==NULL) return;
    cout<<"Numero procesado: "<<p->elem<<", no tiene números tachados. ";
    imprimeFinal(p->sig);
}

void criba( Lista &L1, Nodo *p, int n){
    if(p->elem*p->elem>n || p==NULL){
        imprimeFinal(p);
        return;
    }
    Cola C;
    construir(&C);
    generaCola(L1, p, C, p->elem);
    cout<<"Numero procesado "<<p->elem<<endl;
    cout<<"Numeros tachados para el "<<p->elem<<": ";
    mostrar(C);
    criba( L1, p->sig, n);
}

int main(int argc, char** argv) {
    Lista L1;
    construir(L1);
    int n=15;
    generaLista(L1, n);
    
    criba(L1, L1.cabeza, n);
    
    return 0;
}
