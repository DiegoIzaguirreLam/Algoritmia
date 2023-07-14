

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 13 de julio de 2023, 05:43 PM
 */

#include <cstdlib>
#include "abb.h"
#include "cola.h"

using namespace std;

double calculaDensidad(ABB A1){
    Cola C;
    construir(C);
    ElementoC e;
    ABB temp;
    int contNodos=0;
    int alturaRaiz=0;
    e.nodo=A1;
    e.nivel=0;
    encolar(C, e);
    while(!esColaVacia(C)){
        e = desencolar(C);
        contNodos++;
        temp = e.nodo;
        alturaRaiz=e.nivel; // siempre va a ser >=
        e.nivel = e.nivel+1;
        if(temp->hizq){
            e.nodo = temp->hizq;
            encolar(C, e);
        }
        if(temp->hder){
            e.nodo = temp->hder;
            encolar(C, e);            
        }
    }
    return (double)contNodos/alturaRaiz;
}

int main(int argc, char** argv) {
    ABB A1;
    construir(A1);
    insertar(A1,15);
    insertar(A1,20);
    insertar(A1,11);
    insertar(A1,5);
    insertar(A1,14);
    insertar(A1,4);
    insertar(A1,8);
    insertar(A1,7);
    insertar(A1,13);
    mostrarEnOrden(A1);
    cout<<endl;
    cout<<calculaDensidad(A1);
    
    return 0;
}

