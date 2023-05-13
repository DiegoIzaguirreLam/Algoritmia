/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 12 de mayo de 2023, 10:47 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "listaSimple.h"
#include "pila.h"

using namespace std;

void insertaEnOrden(Lista &pL, Elemento e){
    NodoL *p, *pA, *pU;
    p = crearNodoL( e, NULL);
    if ( esListaVacia(pL) )
        pL.cabeza = p;
    else
    {
        if(pL.cabeza->elem.numPed > e.numPed){
            p->sig=pL.cabeza;
            pL.cabeza = p;
        }
        else{
            pA=pL.cabeza;
            while(pA->sig!=NULL){
                if(pA->elem.numPed< e.numPed && pA->sig->elem.numPed>e.numPed) break;
                pA=pA->sig;
            }
            if(pA->sig==NULL){
                pA->sig=p;
            }
            else{
                p->sig=pA->sig;
                pA->sig=p;
            }
        }
    }
    pL.longitud++;
}

void leePed(Lista &L1){
    ifstream archPed("Pedidos.txt", ios::in);
    Elemento e;
    if(!archPed.is_open()){
        cout<<"error al abrir el archivo Pedidos.txt"<<endl;
        exit(1);
    }
    while(1){
        archPed>>e.numPed>>e.estado;
        if(archPed.eof()) break;
        insertaEnOrden(L1, e);
    }
    mostrar(L1);
    archPed.close();
}

void llenarPila(Lista &L1, Pila &P1){
    NodoL *p=L1.cabeza, *aux;
    while(p!=NULL){
        aux=p->sig;
        if(p->elem.estado=='C' || p->elem.estado=='F'){
            apilar(&P1, p->elem);
            eliminar(&L1, p->elem);
        }
        p=aux;
    }
}

void separaPila(Pila &P1, Pila &pilaC, Pila &pilaF){
    Elemento e;
    while(!esPilaVacia(P1)){
        e=desapilar(&P1);
        if(e.estado=='C') apilar(&pilaC, e);
        else apilar(&pilaF, e);
    }
}

int main(int argc, char** argv) {
    Lista L1;
    construir(L1);
    Pila P1, pilaC, pilaF;
    construir(&P1);
    construir(&pilaC);
    construir(&pilaF);
    leePed(L1);
    llenarPila(L1, P1);
    mostrar(P1);
    separaPila(P1, pilaC, pilaF);
    
    mostrar(pilaC);
    cout<<endl;
    mostrar(pilaF);
    
    return 0;
}

