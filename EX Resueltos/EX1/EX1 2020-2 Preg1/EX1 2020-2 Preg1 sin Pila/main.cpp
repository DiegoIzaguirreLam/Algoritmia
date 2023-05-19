/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 14 de mayo de 2023, 12:33 PM
 */

#include <cstdlib>
#include <iostream>
#include "cola.h"
using namespace std;

void encolarEspecial(Cola &C, char cat){
    NodoC *p;
    Elemento e;
    e.cat=cat;
    if(cat=='A'){
        e.cod=C.cantA+1;
        p=crearNodo(e, C.frente);
        if(C.cantA==0){
            C.frente=p;
        }
        else{
            p->sig=C.ultA->sig;
            C.ultA->sig=p;
            if(C.final==C.ultA){
                C.final=p;
            }
        }
        if(C.final==NULL) C.final=p;
        C.cantA++;
        C.ultA=p;
    }
    else if(cat=='B'){
        e.cod=C.cantB+1;
        p=crearNodo(e,NULL);
        if(C.cantA==0 && C.cantB==0){
            p->sig=C.frente;
            C.frente=p;
        }
        else if(C.cantA!=0 && C.cantB==0){
            p->sig=C.ultA->sig;
            C.ultA->sig=p;
        }
        else{
            p->sig=C.ultB->sig;
            C.ultB->sig=p;
        }
        if(p->sig==NULL)
            C.final=p;
        C.cantB++;
        C.ultB=p;
    }
    else if(cat=='C'){
        e.cod=C.longitud-C.cantA-C.cantB+1;
        p=crearNodo(e, NULL);
        if(esColaVacia(C)){
            C.frente=p;
        }
        else{
            C.final->sig=p;
        }
        C.final=p;
    }
    else{
        cout<<"Categoria no permitida"<<endl;
        return;
    }
    C.longitud++;
}
//no usa pila..
void generaNueva(Cola &C){
    NodoC *p,*aux, *q, *aux2, *pA;
    p=C.ultB;
    while(p->sig!=NULL){
        aux=p->sig;
        delete p->sig;
        p=aux;
        C.longitud--;
    }
    C.ultB->sig=NULL;
    p=C.frente;
    q=C.ultA->sig;
    for(int i=0; i<C.cantA;i++){
        aux=p->sig;
        if(q!=NULL){
            aux2=q->sig;
            p->sig=q;
            q->sig=aux;
        }
        else break;
        p=aux;
        q=aux2;
    }
    
    
}


int main(int argc, char** argv) {
    
    Cola C;
    construir(&C);
    
    encolarEspecial(C, 'A');
    encolarEspecial(C, 'A');
    encolarEspecial(C, 'B');
    encolarEspecial(C, 'A');
    encolarEspecial(C, 'C');
    encolarEspecial(C, 'A');
    encolarEspecial(C, 'B');
    encolarEspecial(C, 'A');
    encolarEspecial(C, 'C');
    encolarEspecial(C, 'A');    
    encolarEspecial(C, 'B');  
    encolarEspecial(C, 'B');  
    mostrar(C);
    
    generaNueva(C);
    
    mostrar(C);
    cout<<"Longitud: "<<C.longitud<<endl<<"A: "<<C.cantA<<"   B: "<<C.cantB<<endl;
    
    return 0;
}

