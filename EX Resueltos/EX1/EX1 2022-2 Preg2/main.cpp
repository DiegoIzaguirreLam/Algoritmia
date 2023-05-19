/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 10 de mayo de 2023, 02:00 PM
 */

#include <cstdlib>
#include <iostream>
#include "pila.h"

using namespace std;

Elemento cima(Pila P){//solo podra ser llamada si se sabe que la pila no es vacia
    return P.cima->elem;
}

void detecta(int frec[], int n){
    Pila p;
    construir(&p);
    int i=0;
    int duracion, pfrec, pArea, maxDur, maxArea=0, maxFrec;
    int j;
    
    while(i<n){
        if(esPilaVacia(p) || frec[i]>=frec[cima(p)]){
            apilar(&p, i);
            i++;
        }
        else{
            j=desapilar(&p);
            if(!esPilaVacia(p))
                duracion = i-cima(p)-1;
            else
                duracion = j;
            pfrec = frec[j];
            pArea=duracion*pfrec;
            if(pArea>maxArea){
                maxArea=pArea;
                maxDur=duracion;
                maxFrec=frec[j];
            }
        }
    }
    while(!esPilaVacia(p)){
            j=desapilar(&p);
            if(!esPilaVacia(p))
                duracion = i-cima(p)-1;
            else
                duracion = j;
            pfrec = frec[j];
            pArea=duracion*pfrec;
            if(pArea>maxArea){
                maxArea=pArea;
                maxDur=duracion;
                maxFrec=frec[j];
            }
    }
    cout<<"Frecuencia maxima: "<<maxFrec<<" Duracion: "<<maxDur<<endl;
}

int main(int argc, char** argv) {
    int frec[]={1,2,1,4,5,6,4,5,2,2,1};
    int n=11;
    detecta(frec, n);
    return 0;
}
