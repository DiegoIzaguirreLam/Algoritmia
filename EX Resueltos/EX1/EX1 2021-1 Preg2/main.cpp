/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 18 de mayo de 2023, 08:00 PM
 */

#include <cstdlib>
#include <string.h>
#include "listaSimple.h"
#include <iostream>
using namespace std;

int cuentaCompraVenta(Nodo *p, char tipoOP, int cont){
    if(p==NULL) return cont;
    if(p->elem.tipoOp==tipoOP) return cuentaCompraVenta(p->sig, tipoOP, cont+1);
    else return cuentaCompraVenta(p->sig, tipoOP, cont);
}

void muestraCompraVenta(Nodo *p, char tipoOP){
    if(p==NULL) return;
    if(p->elem.tipoOp==tipoOP){
        cout<<p->elem.numOp<<endl<<p->elem.fechHora<<endl<<p->elem.tipoId<<endl<<p->elem.id<<endl;
        cout<<p->elem.tipoOp<<endl<<p->elem.precio<<endl<<p->elem.numAcciones<<endl;
    }
    muestraCompraVenta(p->sig, tipoOP);
}

Nodo *reversa(Lista &L, Nodo *p, int flagPrimerUniverso){
    if(p->sig==NULL) return p;
    Nodo *nuevaCabeza;
    nuevaCabeza=reversa(L, p->sig, 0);
    p->sig->sig=p;
    p->sig=NULL;
    if(flagPrimerUniverso) L.cabeza=nuevaCabeza;
    return nuevaCabeza;
}


int main(int argc, char** argv) {
    Lista L;
    construir(L);
    int sigue=1;
    char fechaHoraAnt[16]="0";
    char flagCV;
    while(sigue){
        Elemento e;
        int tamId;
        cin>>e.numOp>>e.fechHora>>e.tipoId;
        if(strcmp(e.tipoId, "01")) tamId=8;
        else if(strcmp(e.tipoId, "04")) tamId=12;
        else if(strcmp(e.tipoId, "06")) tamId=11;
        else if(strcmp(e.tipoId, "07")) tamId=12;
        else tamId=15;
        e.id = new char [tamId];
        cin>>e.id>>e.tipoOp>>e.precio>>e.numAcciones;
        if(strcmp(e.fechHora, fechaHoraAnt)<0){
            cout<<"La fecha y la hora deben ser posteriores a la operacion anterior, intente ingresar nuevamente "<<endl;
            continue;
        }
        insertarFinal(L, e);
        cout<<"Desea ingresar otra operacion? (0/1): ";
        cin>>sigue;
        strcpy(fechaHoraAnt, e.fechHora);
    }
    cout<<"Desea mostrar las operacion de compra o venta? (C/V): ";
    cin>>flagCV;
    muestraCompraVenta(L.cabeza, flagCV);
    cout<<"Se realizaron "<< cuentaCompraVenta(L.cabeza, flagCV, 0)<<" operaciones de ";
    if(flagCV=='C') cout<<"compra";
    else cout<<"venta";
    cout<<endl;
    reversa(L, L.cabeza, 1);
    
    cout<<"Desea mostrar las operacion de compra o venta? (C/V): ";
    cin>>flagCV;
    muestraCompraVenta(L.cabeza, flagCV);
    return 0;
}

