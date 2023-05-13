/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 12 de mayo de 2023, 09:24 PM
 */

#include <cstdlib>
#include <iostream>

#include "listaSimple.h"
using namespace std;

void insertarSigCabeza(Lista &L, Elemento e){
    Nodo *p;
    p=crearNodo(e, L.cabeza->sig);
    L.cabeza->sig=p;
    L.longitud++;
}

void siguienteProceso(Lista &L){
    Nodo *aux, *pU;
    if(L.longitud>1){
        pU=ubicarUltimo(L);
        pU->sig=L.cabeza;
        aux=L.cabeza->sig;
        L.cabeza->sig=NULL;
        L.cabeza=aux;
    }
    
}

int main(int argc, char** argv) {
    Lista L;
    construir(L);
    int nIni=3, T=1;
    struct proceso p;
    int i, opcion;
    int flagelim;
    cout<<"Duraciones iniciales de procesos = ";
    for(i=1;i<=nIni;i++){
        p.num=i;
        cin>>p.duracion;
        insertarFinal(L, p);
    }
    
    while(1){
        L.cabeza->elem.duracion--;
        cout<<"Se ejecuto el proceso #"<<L.cabeza->elem.num<<endl;
        flagelim=0;
        if(L.cabeza->elem.duracion == 0){
            cout<<"Se completo proceso #"<<L.cabeza->elem.num<<endl;
            eliminar(&L, L.cabeza->elem);
            flagelim=1;
        }
        cout<<"Desea insertar un nuevo proceso? ";
        cin>>opcion;
        if(opcion){
            cout<<"Indicar duracion de proceso #"<<i<<": ";
            cin>>p.duracion;
            p.num=i;
            i++;
            insertarSigCabeza(L, p);
        }
        if(!flagelim) siguienteProceso(L);
        if(esListaVacia(L)) break;
    }
    
    
    return 0;
}

