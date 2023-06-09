/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 3 de junio de 2023, 08:32 PM
 */

#include <cstdlib>
#include "abb.h"
#include "cola.h"
using namespace std;

int altura(ABB parbol){
    if(parbol==NULL) return 0;
    return max(altura(parbol->hizq), altura(parbol->hder))+1;
}

void rota_der(ABB &A1){
    ABB t=A1->hizq;
    A1->hizq = t->hder;
    t->hder = A1;
    A1 = t;
}

void rota_izq(ABB &A1){
    ABB t=A1->hder;
    A1->hder = t->hizq;
    t->hizq = A1;
    A1 = t;
}

void balancea(ABB &A1){
    if(A1==NULL) return;
    balancea(A1->hizq);
    balancea(A1->hder);
    int altIzq, altDer;
    altIzq=altura(A1->hizq);
    altDer=altura(A1->hder);
    if(abs(altIzq-altDer)>1){
        if (altIzq > altDer){//desbalanceo a la izquierda
            if(altura(A1->hizq->hizq)>=altura(A1->hizq->hder)){
                rota_der(A1);
            }
            else{
                rota_izq(A1->hizq);
                rota_der(A1);
            }
        }
        else{//desbalanceo a la derecha
            if(altura(A1->hder->hder)>=altura(A1->hder->hizq)){
                rota_izq(A1);
            }
            else{
                rota_der(A1->hder);
                rota_izq(A1);
            }
        }
    }
}

ABB busca(ABB parbol, Elemento e){
    if(parbol==NULL) return NULL;
    if(parbol->elem == e) return parbol;
    else
        if(parbol->elem > e)
            return busca(parbol->hizq, e);
        else
            return busca(parbol->hder, e);
}
int hallaNivel(ABB parbol, Elemento e){
    ABB paux=parbol;
    int cont=0;
    while(paux!=NULL){
        if(paux->elem > e ){
            paux = paux->hizq;
        }
        else if(paux->elem < e){
            paux = paux->hder;
        }
        else
            return cont;
        cont++;
    }
    return cont;
}
void mostrarAmplitud(ABB parbol){
    if(parbol==NULL) return;
    Cola C;
    construir(C);
    Elemento e=parbol->elem;
    encolar(C, parbol->elem);
    ABB temp;
    int eAlt, antAltura;
    antAltura = hallaNivel(parbol, e);
    while(!esColaVacia(C)){
        e=desencolar(C);
        temp = busca(parbol, e);
        eAlt = hallaNivel(parbol, e);
        if(eAlt!=antAltura){
            antAltura = eAlt;
            cout<<endl;
        }
        cout<<e<<" ";
        if(temp->hizq!=NULL) encolar(C, temp->hizq->elem);
        if(temp->hder!=NULL) encolar(C, temp->hder->elem);
    }
}

int main(int argc, char** argv) {
    ABB A1;
    construir(A1);
    int arr[]={3, 2, 1, 72, 14, 36, 81, 9, 65, 43, 27, 50, 68, 30, 79, 5, 93, 61, 17, 48, 88, 38, 23};
    int n=sizeof(arr)/sizeof (arr[0]);
    for(int i=0;i<n;i++) 
        insertar(A1, arr[i]);
    mostrarEnPreOrden(A1);
    //mostrarEnPreOrden(A1);
    cout<<endl;
    //mostrarAmplitud(A1);
    cout<<endl;
    
    balancea(A1);
    mostrarEnPreOrden(A1);
    cout<<endl;
    mostrarAmplitud(A1);
    return 0;
}

