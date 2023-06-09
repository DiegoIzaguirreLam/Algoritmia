/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "cola.h"

using namespace std;


void construir( Cola *pC )
{
    pC->frente = NULL;
    pC->final = NULL;
    pC->ultC = NULL;
    pC->ultV = NULL;
    pC->longitud = 0;
    // la cola empieza vacia
}

bool esColaVacia( Cola C )
{
    return C.frente == NULL;
    // return C.final == NULL;
    // return C.longitud == 0;
}

int obtenerLongitud( Cola C )
{
    return C.longitud;
}

NodoC* crearNodo( Elemento e, NodoC *s )
{
    NodoC *p;
    p = new NodoC; // se crea el nuevo nodo
    p->elem.tipo = e.tipo;
    p->elem.nOrd = e.nOrd;
    p->sig = s;
    return p; // retorna la direccion del nodo creado
} 

void mostrar( Cola C )
{
    NodoC *p;
    int i;
    if ( esColaVacia(C) )
        cout << "Cola vacia" << endl;
    else
    {
        p = C.frente;
        for(i=1; i<=C.longitud; i++)
        {
            cout << p->elem.tipo << " " << p->elem.nOrd<<", ";
            p = p->sig;
        }
        cout << endl;
    }
}

void encolar( Cola *pC, Elemento e )
{
    NodoC *p, *pU;
    p=crearNodo(e,NULL);
    if(e.tipo=='V'){
        if(esColaVacia(*pC)){//no hay vips o la cola esta vacia
            p->sig=pC->frente;
            pC->frente=p;
            pC->final=p;
        }
        else if(pC->ultV==NULL){
            p->sig=pC->frente;
            pC->frente=p;
        }
        else if(pC->ultV!=NULL){
            if(pC->ultV->sig==NULL) pC->final = p;
            p->sig=pC->ultV->sig;
            pC->ultV->sig=p;
        }
        else
            p->sig=pC->ultV->sig;
        pC->ultV=p;
    }
    else if(e.tipo=='C'){
        if(esColaVacia(*pC)){
            p->sig=pC->frente;
            pC->frente=p;
            pC->final=p;
        }
        else if(pC->ultV==NULL && pC->ultC==NULL){
            p->sig=pC->frente;
            pC->frente=p;
        }
        else if(pC->ultV!=NULL && pC->ultC==NULL){
            if(pC->ultV->sig==NULL) pC->final = p;
            p->sig=pC->ultV->sig;
            pC->ultV->sig=p;
        }
        else if(pC->ultC!=NULL){
            if(pC->ultC->sig==NULL) pC->final = p;
            p->sig=pC->ultC->sig;
            pC->ultC->sig=p;
        }
        else{
            p->sig=pC->ultC->sig;
        }
        pC->ultC=p;
    }
    else{
        if(esColaVacia(*pC)){
            pC->frente=p;
        }
        else{
            pC->final->sig=p;
        }
        pC->final=p;
    }
    pC->longitud++;
}

// esta funcion solo sera invocada si la cola no esta vacia
Elemento desencolar( Cola *pC )
{
    NodoC *p;
    Elemento x;
    p = pC->frente;
    x = p->elem;
    pC->frente = p->sig;
    if ( pC->frente == NULL )
        pC->final = NULL;
    if ( p==pC->ultV ){
        pC->ultV=NULL;
    }
    if ( p==pC->ultC ){
        pC->ultC=NULL;
    }
    pC->longitud--;
    delete p; // elimina el Nodo
    return x;
}

void destruir( Cola *pC )
{
    NodoC *p, *q;
    int i;
    if ( !esColaVacia(*pC) )
    {
        p = pC->frente;
        for(i=1; i<=pC->longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        pC->frente = NULL;
        pC->final = NULL;
        pC->longitud = 0;
    }
}
