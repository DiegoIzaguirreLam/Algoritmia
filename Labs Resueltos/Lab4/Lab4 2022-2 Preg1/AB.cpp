/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cstdlib>

#include "AB.h"

using namespace std;

void construir(AB &pA){
    pA = NULL;
}

NodoAB* crearNodo(Elemento elem){
    NodoAB *p;
    p = new NodoAB;
    p->e=elem;
    p->hizq=NULL;
    p->hder=NULL;
    return p;
}

void creaPivot(AB &pA, Elemento e){
    pA = crearNodo(e);
}

void insertaHizq(AB &pA, Elemento e){
    pA->hizq = crearNodo(e);
}

void insertaHder(AB &pA, Elemento e){
    pA->hder = crearNodo(e);
}

void mostrarEnOrden( NodoAB *pR )  // pR: puntero a la raiz del árbol
{
    NodoAB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnOrden( pAI);  // se recorre en orden el subarbol izquierdo
        cout << pR->e.cromo << "-"<<pR->e.peso<<" ";  // se visita la raiz
        mostrarEnOrden( pAD);  // se recorre en orden el subarbol derecho
    }
}

