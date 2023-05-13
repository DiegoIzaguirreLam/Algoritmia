/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 12 de mayo de 2023, 08:19 PM
 */

#include <cstdlib>
#include <iostream>
#include "cola.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cola C;
    construir(&C);
    Elemento e;
    e.tipo='N'; e.nOrd=1; encolar(&C, e); mostrar(C);
    e.tipo='C'; e.nOrd=1; encolar(&C, e); mostrar(C);
    e.tipo='V'; e.nOrd=1; encolar(&C, e); mostrar(C);
    e.tipo='N'; e.nOrd=2; encolar(&C, e); mostrar(C);
    e.tipo='N'; e.nOrd=3; encolar(&C, e); mostrar(C);
    e.tipo='C'; e.nOrd=2; encolar(&C, e); mostrar(C);
    e.tipo='V'; e.nOrd=2; encolar(&C, e); mostrar(C);
    e.tipo='V'; e.nOrd=3; encolar(&C, e); mostrar(C);
    e.tipo='C'; e.nOrd=3; encolar(&C, e); mostrar(C);
    e.tipo='C'; e.nOrd=4; encolar(&C, e); mostrar(C);
    e.tipo='V'; e.nOrd=4; encolar(&C, e); mostrar(C);
    
    cout<<endl;
    while(!esColaVacia(C)){
        e=desencolar(&C);
        cout<<e.tipo<<" "<<e.nOrd<<endl;
    }
    
    
    
    return 0;
}

