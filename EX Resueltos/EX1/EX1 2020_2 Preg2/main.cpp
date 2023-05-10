/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 9 de mayo de 2023, 11:36 AM
 */

#include <cstdlib>
#include <iostream>
#include "pila.h"

#define MAXCOL 5
#define NOENC -100
using namespace std;

int robot(int alma[][MAXCOL], int n, int t, int x, int y, int cont, int &xb, int &yb, int flag, int &mpasos){
    if(x==n-1 && y==n-1)
        return NOENC;
    if(x<0 || x>=n || y<0 || y>=n) return NOENC;
    int derecha, abajo, retorna;
    derecha=robot(alma, n, t, x, y+1, cont+1, xb, yb, 0, mpasos);
    abajo=robot(alma, n, t, x+1, y, cont+1, xb, yb, 0, mpasos);
    
    if(alma[x][y]>=t && derecha<0 && abajo<0 && mpasos<cont){ //los pasos de abajo y derecha siempre seran al menos 1 mas, por lo que estas soluciones siempre van a tener prioridad
        xb=x;
        yb=y;
        mpasos=cont;
        retorna= cont;
    }
    else if(derecha>abajo && derecha>0) retorna=derecha;
    else if(abajo>derecha && abajo>0) retorna=abajo;
    else
        retorna= NOENC;
    if(flag) cout<<"El mejor espacio está a "<< mpasos<<" pasos de distancia y acepta pilas de tamaño "<<alma[xb][yb]<<endl;
    return retorna;
}

int verCima(Pila &p){
    return p.cima->elem;
}

void pilaAlm(Pila &u, Pila &p){
    Pila aux;
    Elemento e;
    construir(&aux);
    while(!esPilaVacia(p)){
        e=desapilar(&p);
        if(e>verCima(u)){
            while(e>verCima(u)){
                apilar(&aux, desapilar(&u));
            }
            apilar(&u, e);
            while(!esPilaVacia(aux)){
                apilar(&u, desapilar(&aux));
            }
        }
        else{
            apilar(&u, e);
        }
    }
    
}
int main(int argc, char** argv) {
    
    int alma[][MAXCOL]={{5,6,3,2,1},{2,1,2,3,6},{3,0,1,4,5},{4,5,1,2,2},{3,7,2,3,1}};
    int n=5;
    int t=4;
    int xb, yb, mpasos=-1;
    robot(alma, n, t, 0, 0, 0, xb, yb, 1, mpasos);
    
    Pila u, p;
    construir(&u);
    construir(&p);
    
    apilar(&u, 6);
    apilar(&u, 5);
    apilar(&u, 2);
    
    apilar(&p, 5);
    apilar(&p, 4);
    apilar(&p, 3);
    apilar(&p, 1);
    
    pilaAlm(u, p);
    cout<<"Pila u:"<<endl;
    mostrar(u);
    return 0;
}

