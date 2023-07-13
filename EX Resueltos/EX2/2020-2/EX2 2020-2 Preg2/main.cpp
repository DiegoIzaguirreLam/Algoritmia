/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 12 de julio de 2023, 08:26 PM
 */

#include <cstdlib>
#include "listaSimple.h"
#include "abb.h"

using namespace std;


ABB buscam(ABB parbol){
    if (parbol==NULL) return parbol;
    else{
        ABB pA=parbol;
        while(pA->hizq){
            pA=pA->hizq;
        }
        return pA;
    }
}

ABB borranodo(ABB parbol,Elemento e){
    if(parbol==NULL) return parbol;
    
    if( e.semana < parbol->elem.semana || (e.semana==parbol->elem.semana && e.cantidad<parbol->elem.cantidad) 
                    || (e.semana==parbol->elem.semana && e.cantidad==parbol->elem.cantidad && e.idProd<parbol->elem.idProd))
        parbol->hizq = borranodo(parbol->hizq,e);
    else
        if( e.semana > parbol->elem.semana || (e.semana==parbol->elem.semana && e.cantidad>parbol->elem.cantidad) 
                    || (e.semana==parbol->elem.semana && e.cantidad==parbol->elem.cantidad && e.idProd>parbol->elem.idProd))
            parbol->hder = borranodo(parbol->hder,e);
        else{
            if(parbol->hizq==NULL){
                ABB temp = parbol->hder;              
                delete parbol;
                return temp;
            }
            else
                if(parbol->hder==NULL){
                    ABB temp = parbol->hizq;
                    delete parbol;
                    return temp;
                }
            ABB temp = buscam(parbol->hder);    
            parbol->elem = temp->elem;    
            parbol->hder=borranodo(parbol->hder,e);
            return parbol;
        }    
}



void crearArbol(ABB &A1, int &P, int &N){
    construir(A1);
    Elemento e;
    cout<<"Ingrese los valores de P y N: ";
    cin>>P>>N;
    cout<<"Siguiendo el orden de registro de semanas mencionado (3, 4, 1, 2): "<<endl;
    for(int i=1;i<=4;i++){
        cout<<"Ingrese los datos de cada producto para la semana "<<i<<": "<<endl;
        if(i==1) e.semana=3;
        else if(i==2) e.semana=4;
        else if(i==3) e.semana=1;
        else if(i==4) e.semana=2;
        for(int j=1;j<=N;j++){
            cin>>e.cantidad;
            e.idProd=j;
            if(e.cantidad!=0) insertar(A1, e);
        }
    }
}


void atiendeSemana(ABB &A1, int nSemana,int capSemanal){
    ABB prec, pA, parbol=A1;
    if(A1==NULL) return;
    //primero se busca la semana
    while(parbol && parbol->elem.semana!=nSemana){
        if(nSemana<parbol->elem.semana) parbol=parbol->hizq;
        else parbol=parbol->hder;
    }
    //si es nulo, no hay nada que atender
    if(parbol){
        cout<<"Semana "<<nSemana<<": ";
        while(capSemanal>0){
            if(!parbol || parbol->elem.semana!=nSemana) break;
            prec=parbol;
            pA=NULL;
            while(prec && prec->elem.semana==nSemana){
                pA=prec;
                prec=prec->hder; //buscamos la mayor cantidad de productos en la semana
            }//pA es el puntero a la orden que debemos atender
            //se debe restar la capacidad atendida
            int atendido;
            if(capSemanal>pA->elem.cantidad){
                atendido=pA->elem.cantidad;
                capSemanal-=pA->elem.cantidad;
            }
            else{
                atendido=capSemanal;
                capSemanal=-1;
                pA->elem.cantidad-=atendido;
            }
            cout<<"Producto "<<pA->elem.idProd<<": "<<atendido<<" ";
            if(capSemanal!=-1){
                if(pA->elem.cantidad==parbol->elem.cantidad && pA->elem.idProd==parbol->elem.idProd) parbol=parbol->hizq;
                A1=borranodo(A1, pA->elem);
            }
        }
        cout<<endl;
    }
}

void noAtendidos(ABB &A1, Lista &L){
    if(A1){
        noAtendidos(A1->hizq, L);
        noAtendidos(A1->hder, L);
        Elemento e=A1->elem;
        insertarFinal(L, e);
        A1=NULL;
        delete A1;
    }
}

int main(int argc, char** argv) {
    ABB A1;
    Lista L;
    construir(L);
    int P, N;
    crearArbol(A1, P, N);
    
    mostrarEnPreOrden(A1);
    cout<<endl;
    mostrarEnOrden(A1);
    cout<<endl;
    int capSemanal;
    capSemanal=P/4;
    for(int i=1;i<=4;i++){
        atiendeSemana(A1, i, capSemanal);//falta completar para las ordenes no atendidas
    }
    noAtendidos(A1,L);
    cout<<"Ordenes sin atender o atendidas parcialmente: ";
    mostrar(L);
    return 0;
}



/*

40
5
2 3 4 0 0
0 3 2 0 0
4 2 8 0 2
0 0 0 3 2
 */