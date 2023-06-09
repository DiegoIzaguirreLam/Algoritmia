/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 24 de mayo de 2023, 06:34 PM
 */

#include <cstdlib>

#include "cola.h"

using namespace std;

void cargaCola(Cola &C){
    encolar(C, 5);
    encolar(C, 1);
    encolar(C, 8);
    encolar(C, 4);
    encolar(C, 3);
    encolar(C, 6);
    encolar(C, 2);
    encolar(C, 9);
}

void ordenaCola(Cola &C, int n){
    if(n==0) return;
    int max=desencolar(C), e;
    for(int i=1;i<n;i++){
        e=desencolar(C);
        if(e>max){
            encolar(C, max);
            max=e;
        }
        else
            encolar(C, e);
    }
    ordenaCola(C, n-1);
    encolar(C,max);
}

int main(int argc, char** argv) {
    
    Cola C;
    construir(C);
    cargaCola(C);
    mostrar(C);
    ordenaCola(C, C.longitud);
    mostrar(C);
    
    
    return 0;
}

