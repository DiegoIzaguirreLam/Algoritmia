/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 13 de mayo de 2023, 10:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "pila.h"
#define MAXCOL 10
using namespace std;



int buscaPila(Pila pila[][MAXCOL], int maxPila[][MAXCOL], int maxNiveles, Elemento k, int &iPila, int &jPila, int x, int y, int m){//busca la mejor pila posible
    if(x<0 || y<0 || x>=m || y>=m){
        iPila=-1;
        jPila=-1;
        return 0;
    }
    int encontroPila1=0, encontroPila2=0;
    for(int j=y;j<m-1;j++){
        if(pila[x][j].longitud < maxNiveles && maxPila[x][j] >= pila[x][j].pesoAct + k){
            iPila=x;
            jPila=j;
            encontroPila1=1;
        }
    }
    for(int i=x;i<m;i++){
        if(pila[i][m-1].longitud < maxNiveles && maxPila[i][m-1] >= pila[i][m-1].pesoAct + k){
            iPila=i;
            jPila=m-1;
            encontroPila2=1;
        }
    }
    if(!encontroPila2){
        for(int j=m-2;j>=0;j--){
            if(pila[m-1][j].longitud < maxNiveles && maxPila[m-1][j] >= pila[m-1][j].pesoAct + k){
                iPila=m-1;
                jPila=j;
                encontroPila2=1;
                break;
            }
        }
    }

    if(encontroPila1 || encontroPila2) return 1;
    else{
        buscaPila(pila, maxPila, maxNiveles, k, iPila, jPila, x+1, y, m-1);
    }
}

Elemento cima(Pila P){
    return P.cima->elem;
}

void apilaEnLote(Pila &P, int peso){
    if(esPilaVacia(P)){
        apilar(&P, peso);
        P.pesoAct+=peso;
        return;
    }
    if(peso>cima(P)){
        int aux;
        aux=desapilar(&P);
        apilaEnLote(P, peso);
        apilar(&P, aux);
    }
    else{
        apilar(&P, peso);
        P.pesoAct+=peso;
    }
}

void imprimePosPila(Pila &P, int n){
    if(esPilaVacia(P)){
        cout<<setw(3)<<"0";
        return;
    }
    if(n==0){
        cout<<setw(3)<<cima(P);
        return;
    }
    Elemento e;
    e=desapilar(&P);
    imprimePosPila(P, n-1);
    apilar(&P, e);
}

int main(int argc, char** argv) {
    int m=5;
    int maxPila[][MAXCOL]={ {19,21,22,20,18},
                            {10,20,18,16,15},
                            {30,25,20,12,12},
                            {20,22,15,14,15},
                            {16,17,10,12,20}};
    int maxNiveles=4;
    Pila pila[5][MAXCOL];
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            construir(&pila[i][j]);
    }
    int pesos[]={5,3,5,5,3,5,3,3,4,5,2,2,2,5,5,6,7,4,3,5,4,8,2,1,5,3,7,1,5,3,6,3,7,1,3,6,14,10,7,10,11,14,9,4};
    int n=43, i;
    int fsinApilar=0;
    //para este problema digamos que se quiere poner cada peso en la pila mas al fondo al recorrer el almacen en forma de C invertida
    //los elementos de mayor peso deben estar abajo.
    int iPila, jPila;
    for(i=0; i<n;i++){
        buscaPila(pila, maxPila, maxNiveles, pesos[i], iPila, jPila, 0, 0, m);
        if(iPila!=-1 && jPila!=-1){
            apilaEnLote(pila[iPila][jPila], pesos[i]);
            pesos[i]=0;
        }
        else{
            fsinApilar=1;
            break;
        }
    }
    if(fsinApilar){
        cout<<"Pesos no apilados: ";
        for(i;i<n;i++) cout<<pesos[i]<<" ";
    }
    cout<<endl<<"Almacen: "<<endl;
    for(int k=0;k<maxNiveles;k++){
        cout<<"Nivel "<<k+1<<endl;
        for(i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(pila[i][j].longitud>=k+1){//5
                    imprimePosPila(pila[i][j], pila[i][j].longitud-k-1);
                }
                else cout<<setw(3)<<"0";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<endl<<endl;
    cout<<"Espacio libre de cada pila: "<<endl;
    for(i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<setw(3)<<maxPila[i][j]-pila[i][j].pesoAct<<" ";
        }
        cout<<endl;
    }
    return 0;
}

