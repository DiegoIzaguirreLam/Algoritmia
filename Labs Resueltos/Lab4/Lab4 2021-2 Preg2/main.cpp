
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


void crearArbol(ABB &A1){
    construir(A1);
    Elemento e;
    e.nombre='A'; e.precio=190;
    insertar(A1, e);
    e.nombre='C'; e.precio=180;
    insertar(A1, e);
    e.nombre='G'; e.precio=150;
    insertar(A1, e);
    e.nombre='B'; e.precio=100;
    insertar(A1, e);
    e.nombre='M'; e.precio=20;
    insertar(A1, e);
    e.nombre='P'; e.precio=140;
    insertar(A1, e);
    e.nombre='Q'; e.precio=210;
    insertar(A1, e);
    
    
}

int alturaNodo(ABB A1){
    if(!A1) return 0;
    return max(alturaNodo(A1->hizq), alturaNodo(A1->hder))+1;
}

void rotacionDerecha(ABB &A1){
    ABB t = A1;
    A1 = A1->hizq;
    t->hizq = A1->hder;
    A1->hder = t;
}

void rotacionIzquierda(ABB &A1){
    ABB t = A1;
    A1 = A1->hder;
    t->hder = A1->hizq;
    A1->hizq = t;
}


void balancea(ABB &A1){
   if(A1){
       balancea(A1->hizq);
       balancea(A1->hder);
       int altIzq, altDer, dif;
       altIzq=alturaNodo(A1->hizq);
       altDer=alturaNodo(A1->hder);
       dif=abs(altIzq-altDer);
       if(dif>1){
           if(altIzq>altDer){
               if(alturaNodo(A1->hizq->hizq) >= alturaNodo(A1->hizq->hder)){//balanceo normal, rot der
                   rotacionDerecha(A1);
               }
               else{//doble rotder
                   rotacionIzquierda(A1->hizq);
                   rotacionDerecha(A1);
               }
           }
           else{
               if(alturaNodo(A1->hder->hder) >= alturaNodo(A1->hder->hizq)){//balanceo normal, rot izq
                   rotacionIzquierda(A1);
               }
               else{//doble rot izq
                   rotacionDerecha(A1->hder);
                   rotacionIzquierda(A1);
               }
           }
       }
   } 
}

ABB busca(ABB parbol, int precio){
    if(parbol==NULL) return NULL;
    if(parbol->elem.precio == precio) return parbol;
    else
        if(parbol->elem.precio > precio)
            return busca(parbol->hizq, precio);
        else
            return busca(parbol->hder, precio);
}

void mostrarAmplitud(ABB parbol){
    if(parbol==NULL) return;
    Cola C;
    construir(C);
    ElementoC e;
    e.nodo=parbol;
    e.nivel=1;
    encolar(C, e);
    ABB temp;
    int nivel=1;
    while(!esColaVacia(C)){
        e=desencolar(C);
        temp = e.nodo;
        if(e.nivel>nivel){
            nivel = e.nivel;
            cout<<endl;
        }
        cout<<temp->elem.nombre<<"-"<<temp->elem.precio<<" ";
        e.nivel = e.nivel+1;
        if(temp->hizq!=NULL){
            e.nodo = temp->hizq;
            encolar(C, e);
        }
        if(temp->hder!=NULL){
            e.nodo = temp->hder;
            encolar(C, e);
        }
    }
}

int main(int argc, char** argv) {
    ABB A1;
    crearArbol(A1);
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

