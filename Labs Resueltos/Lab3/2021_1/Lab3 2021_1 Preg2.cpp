
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 30 de abril de 2023, 09:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <iomanip>
#define MAX 8
using namespace std;

/*
 * 
 */

void merge(char arr[], int ini,int med,int fin){
    int i,j,k;
    
    int elemIzq=med-ini+1, elemDer=fin-med;
    char izq[elemIzq], der[elemDer];
    
    for(int i=0;i<elemIzq;i++)
        izq[i]=arr[ini+i];
    for(int j=0;j<elemDer;j++)
        der[j]=arr[med+1+j];
    
    i=0;
    j=0;
    k=ini;
    
    while(i<elemIzq && j<elemDer){
        if(izq[i]>der[j]){
            arr[k]=izq[i];
            i++;
            k++;
        }
        else{
            arr[k]=der[j];
            j++;
            k++;
        }
    }
    while(i<elemIzq){
        arr[k]=izq[i];
        i++;
        k++;
    }
    while(j<elemDer){
        arr[k]=der[j];
        j++;
        k++;
    }
    
}

void mergeSort(char arr[], int ini, int fin){
    if(ini>=fin){
        return;
    }
    int med=(ini+fin)/2;
    mergeSort(arr, ini, med);
    mergeSort(arr, med+1, fin);
    merge(arr, ini, med, fin);
}

void cuentaF(char lote[], int ini, int fin, int *nF){
    if(ini>fin){
        return;
    }
    if(ini==fin){
        (*nF)+=(lote[ini]=='F');
        return;
    }
    int med=(ini+fin)/2;
    if(lote[med]=='F'){
        (*nF)+=med-ini+1;
        cuentaF(lote, med+1, fin, nF);
    }
    else if(lote[med]==' '){
        cuentaF(lote, ini, med-1, nF);
    }
    else{
        cuentaF(lote, ini, med, nF);
    }
}

void cuentaEsp(char lote[], int ini, int fin, int *nE){
    if(ini>=fin){
        return;
    }
    int med=(ini+fin)/2;
    if(lote[med]==0){
        (*nE)+=fin-med+1;
        cuentaEsp(lote, ini, med-1, nE);
    }
    else{
        cuentaEsp(lote, med+1, fin, nE);
    }
}


void procesaLote(int M,int N,double P,char lote[][MAX], int nlote){
    if(nlote==M){
        return;
    }
    double Pi;
    int nF=0, nC=0, nE=0;
    mergeSort(lote[nlote], 0, N-1);
    
    cuentaF(lote[nlote], 0, N-1, &nF);//las F estaran al inicio
    cuentaEsp(lote[nlote], 0, N-1, &nE);//los espacios estaran al final
    int nProd=N-nE;
    nC=nProd-nF;
    Pi=(double) nC/nProd;
    cout<<nlote+1<<"    ";
    if(Pi>=P)
        cout<<"Aprobado"<<endl;
    else
        cout<<"Rechazado"<<endl;
    
    procesaLote(M,N,P,lote,nlote+1);
}

int main(int argc, char** argv) {
    int M=6, N=8;
    double P=0.7;
    char lote[][MAX]={  {'F','F','F','C','C','F'},
                        {'C','F','C','C','C','F','C','F'},
                        {'F','C','C','C','C','C','C','C'},
                        {'C','C','C','C','C','F','C'},
                        {'C','F','F','F','F','C'},
                        {'C','C','F','C','F','C','C'}};
    
    procesaLote(M,N,P,lote,0);
    return 0;
}

