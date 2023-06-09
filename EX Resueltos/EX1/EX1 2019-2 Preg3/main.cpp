/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 24 de mayo de 2023, 06:22 PM
 */

#include <cstdlib>
#include "listaSimple.h"
using namespace std;

void cargaLista(Lista &L){
    insertarComienzo(L, 21);
    insertarComienzo(L, 43);
    insertarComienzo(L, 41);
    insertarComienzo(L, 21);
    insertarComienzo(L, 12);
    insertarComienzo(L, 11);
    insertarComienzo(L, 12);
}

void eliminaRepetidos(Lista &L){
    Nodo *p, *q, *aux, *qAnt=NULL;
    p=L.cabeza;
    for(int i=0;i<L.longitud-1;i++){
        q=p->sig;
        for(int j=i;j<L.longitud;j++){
            if(p->elem==q->elem){
                qAnt->sig=q->sig;
                delete q;
                q=qAnt;
                L.longitud--;
            }
            qAnt=q;
            q=q->sig;
            if(q==NULL) break;
        }
        p=p->sig;
    }
}

int main(int argc, char** argv) {
    
    Lista L;
    construir(L);
    
    cargaLista(L);
    mostrar(L);
    eliminaRepetidos(L);
    mostrar(L);
    return 0;
}

