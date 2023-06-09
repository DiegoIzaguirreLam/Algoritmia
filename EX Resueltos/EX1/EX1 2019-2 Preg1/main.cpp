/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 24 de mayo de 2023, 05:13 PM
 */

#include <cstdlib>
#include <iostream>
#include "pila.h"

using namespace std;

void hallaintervalo(int arr[], int n, int intervalo[]){
    Pila aux;
    construir(aux);
    int i=0;
    
    while(i<n){
        if(!esPilaVacia(aux) && arr[i]>arr[top(aux)]){
            desapilar(aux);
        }
        else{
            if(esPilaVacia(aux)){
                intervalo[i]=i+1;
            }
            else{
                intervalo[i]=i-top(aux);
            }
            apilar(aux,i);
            i++;
        }
    }
}

int main(int argc, char** argv) {
    int arr[]={100, 80, 60, 70, 60, 75, 85};
    int n=7;
    int intervalo[n]={};
    hallaintervalo(arr, n, intervalo);
    for(int i=0;i<n;i++) cout<<intervalo[i]<<" ";
    
    return 0;
}

