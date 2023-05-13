/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 12 de mayo de 2023, 11:34 AM
 */
#define MAXCOL 12
#include <cstdlib>
#include <iostream>
#include "cola.h"
using namespace std;

int mov[8][2];

void vecinos(){
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=-1; mov[1][1]=1;
    mov[2][0]=0; mov[2][1]=1;
    mov[3][0]=1; mov[3][1]=1;
    mov[4][0]=1; mov[4][1]=0;
    mov[5][0]=1; mov[5][1]=-1;
    mov[6][0]=0; mov[6][1]=-1;
    mov[7][0]=-1; mov[7][1]=-1;
}


void encolarAdy(Cola &C, int mat[][MAXCOL], int nReg, int n){
    if(esColaVacia(C)) return;
    Elemento e, eAux;
    e=desencolar(&C);
    mat[e.i][e.j]=nReg;//cada elemento desencolado lo marca como region n
    for(int k=0;k<8;k++){//revisa si los vecinos son tierra
        eAux.i=e.i+mov[k][0];
        eAux.j=e.j+mov[k][1];
        if(eAux.i<n && eAux.j<n && eAux.i>=0 && eAux.j>=0){
            if(mat[eAux.i][eAux.j]==1){
                encolar(&C, eAux);
            }
        }
    }
    encolarAdy(C, mat, nReg, n);
}


int main(int argc, char** argv) {
    
    int mat[][MAXCOL]={ {1,0,1,0,0,0,1,1,1,1},
                        {0,0,1,0,1,0,1,0,0,0},
                        {1,1,1,1,0,0,1,0,0,0},
                        {1,0,0,1,0,1,0,0,0,0},
                        {1,1,1,1,0,0,0,1,1,1},
                        {0,1,0,1,0,0,1,1,1,1},
                        {0,0,0,0,0,1,1,1,0,0},
                        {0,0,0,1,0,0,1,1,1,0},
                        {1,0,1,0,1,0,0,1,0,0},
                        {1,1,1,1,0,0,0,1,1,1}};
    int n=10;
    Cola C;
    construir(&C);
    Elemento e;
    int nReg=2;//empezamos en 2 porque si empieza en 1 puede haber un error para distinguir entre "tierra de ningun terreno" y "tierra libre"
    vecinos();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                e.i=i;
                e.j=j;
                encolar(&C, e);
                encolarAdy(C, mat, nReg, n);
                nReg++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]>1) mat[i][j]--;//reducir en 1 ya que empezamos a contar en 2
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Se cuenta con "<<nReg-2<<" regiones"<<endl;
    return 0;
}

