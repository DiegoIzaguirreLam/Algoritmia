/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 18 de mayo de 2023, 07:17 PM
 */

#include <cstdlib>
#include <iostream>
#include "cola.h"
#include "pila.h"

using namespace std;

void cargaColaPilaRetencion(Cola &C, Pila &robot1, Pila &robot2){
    Elemento e;
    e.nOrd=5;e.tipo='P';encolar(C, e);
    e.nOrd=6;e.tipo='P';encolar(C, e);
    e.nOrd=7;e.tipo='A';encolar(C, e);
    e.nOrd=8;e.tipo='A';encolar(C, e);
    e.nOrd=9;e.tipo='P';encolar(C, e);
    e.nOrd=10;e.tipo='A';encolar(C, e);
    e.nOrd=11;e.tipo='P';encolar(C, e);
    
    e.nOrd=0;e.tipo='A';apilar(robot1, e);
    e.nOrd=1;e.tipo='A';apilar(robot1, e);
    e.nOrd=4;e.tipo='A';apilar(robot1, e);
    e.nOrd=2;e.tipo='P';apilar(robot2, e);
    e.nOrd=3;e.tipo='P';apilar(robot2, e);
}

Elemento cima(Pila p){
    return p.cima->elem;
}

void reordena(Cola &C, Pila &robot1, Pila &robot2, int numCola, int numRobot1, int numRobot2){
    Pila aux;
    construir(aux);
    Elemento e;
    int agreg=numCola-numRobot1-numRobot2;
    while(!esPilaVacia(robot1) || !esPilaVacia(robot2)){
        if(esPilaVacia(robot2) || cima(robot1).nOrd > cima(robot2).nOrd)
            e=desapilar(robot1);
        else e=desapilar(robot2);
        apilar(aux, e);
    }
    while(!esPilaVacia(aux)){
        e=desapilar(aux);
        encolar(C, e);
        numCola--;
    }
    while(agreg>0){
        e=desencolar(C);
        encolar(C, e);
        agreg--;
    }
    while(robot1.longitud + robot2.longitud < numRobot1+numRobot2){
        e=desencolar(C);
        if(e.tipo=='A') apilar(robot1,e);
        else apilar(robot2, e);
    }
}

void reclasifica(Pila &robot1, Pila &robot2){
    Cola aux;
    construir(aux);
    Elemento e;
    while(!esPilaVacia(robot1) || !esPilaVacia(robot2)){
        if(esPilaVacia(robot2) || cima(robot1).nOrd > cima(robot2).nOrd)
            e=desapilar(robot1);
        else e=desapilar(robot2);
        encolar(aux, e);
    }
    while(!esColaVacia(aux)){
        e=desencolar(aux);
        if(e.tipo=='A') apilar(robot1, e);
        else apilar(robot2, e);
    }
}


int main(int argc, char** argv) {
    
    Cola C;
    construir(C);
    Pila robot1, robot2;
    construir(robot1);
    construir(robot2);
    int numCola=7, numRobot1=3, numRobot2=2;
    cargaColaPilaRetencion(C, robot1, robot2);
    
    reordena(C, robot1, robot2, numCola, numRobot1, numRobot2);
    cout<<"Despues de reordenar: "<<endl;
    mostrar(C);
    mostrar(robot1);
    cout<<endl;
    mostrar(robot2);
    cout<<endl<<endl;
    reclasifica(robot1, robot2);
    cout<<"Despues de reclasificacion: "<<endl;
    mostrar(robot1);
    cout<<endl;
    mostrar(robot2);
    return 0;
}

