/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 19 de mayo de 2023, 11:18 AM
 */

#include <cstdlib>
#include "cola.h"
#include "pila.h"

using namespace std;

void cargaCola(Cola &C){
    Elemento e;
    e.tipo='A';e.nOrd=1;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    e.tipo='B';e.nOrd=1;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    e.tipo='C';e.nOrd=1;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
    encolar(C, e); e.nOrd++;
}

Elemento verFrente(Cola C){
    return C.frente->elem;
}

void reordena(Cola &C){
    Pila aux;
    construir(aux);
    Elemento e, eAux;
    int numRot=0;
    //se eliminan los C
    while(C.cantC>0){
        e=desencolar(C);
        if(e.tipo!='C') 
            encolar(C, e);
    }
    //los A en la pila
    if(C.cantB>0){
    while(C.cantA>0){
        e=desencolar(C);
        apilar(aux, e);
    }
        while(!esPilaVacia(aux)){
            e=desencolar(C);
            if(e.nOrd==top(aux).nOrd){
                eAux=desapilar(aux);
                encolar(C, eAux);
                encolar(C, e);
                numRot=0;
            }
            else if(numRot==C.cantB){//si ya se revisaron todos los B y ninguno es igual al mayor A en la pila, entonces hay mas A que B, por lo tanto hay que encolar el B y luego el A en la cima
                encolar(C, e);
                eAux=desapilar(aux);
                encolar(C, eAux);
                numRot=0;
            }
            else{
                encolar(C, e);
                numRot++;//cuenta cuantos B ya se van revisando
            }
        }

        while(verFrente(C).tipo!='A' || verFrente(C).nOrd!=1){
            e=desencolar(C);
            encolar(C, e);
        }
    }
}

int main(int argc, char** argv) {
    Cola C;
    construir(C);
    Elemento e;
    cargaCola(C);
    mostrar(C);
    reordena(C);
    mostrar(C);
    return 0;
}

