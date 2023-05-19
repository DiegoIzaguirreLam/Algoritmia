/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 18 de mayo de 2023, 06:43 PM
 */

#include <cstdlib>
#include "pila.h"
using namespace std;


void robot(int alma[][10], int x, int y, int n, int t, int &npasos, int cont, int &tamPila){
    if(x<0 || y<0 || x>=n || y>=n) return;
    if(alma[x][y]>=t && cont>npasos){
        npasos=cont;
        tamPila=alma[x][y];
    }
    robot(alma, x+1, y, n, t, npasos, cont+1, tamPila);
    robot(alma, x, y+1, n, t, npasos, cont+1, tamPila);
}

Elemento cima(Pila p){
    return p.cima->elem;
}

void apilaLugar(Pila &u, Elemento elem){
    Elemento temp;
    if(elem<cima(u)){
        apilar(u, elem);
        return;
    }
    else{
        temp=desapilar(u);
        apilaLugar(u, elem);
        apilar(u, temp);
    }
}

int main(int argc, char** argv) {
    int alma[][10]={{5,6,3,2,1},{2,1,2,3,6},{3,0,1,4,5},{4,5,1,2,2},{3,7,2,3,1}};
    
    int n=5, t=4;
    int npasos=0, parcialPasos=0;
    int tamPila=0;
    
    robot(alma, 0,0, n, t, npasos, parcialPasos, tamPila);
    cout<<"El mejor espacio esta a "<<npasos<<" de distancia y acepta pilas de tamaño "<<tamPila<<endl;
    Pila u, p;
    construir(u);
    construir(p);
    
    apilar(u,6);
    apilar(u,5);
    apilar(u,2);
    
    apilar(p,5);
    apilar(p,4);
    apilar(p,3);
    apilar(p,1);
    
    while(!esPilaVacia(p)){
        apilaLugar(u, desapilar(p));
    }
    
    mostrar(u);
    
    
    return 0;
}

