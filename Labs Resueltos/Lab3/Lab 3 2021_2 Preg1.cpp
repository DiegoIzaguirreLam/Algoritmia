
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
#define MAXEMP 7
#define MAXDIAS 6
using namespace std;

/*
 * 
 */

void merge(int arr[], int ini,int med,int fin, char emp[]){
    int i, j, k;
    int elementosIzq=med-ini+1;
    int elementosDer=fin-med;
    
    int izq[elementosIzq];
    int der[elementosDer];
    char izqE[elementosIzq], derE[elementosDer];
    
    
    for(int i=0;i<elementosIzq;i++){
        izq[i]=arr[ini+i];
        izqE[i]=emp[ini+i];
    }
    for(int j=0;j<elementosDer;j++){
        der[j]=arr[med+1+j];
        derE[j]=emp[med+1+j];
    }
    
    i=0;
    j=0;
    k=ini;
    
    while(i<elementosIzq && j<elementosDer){
        if(izq[i]>der[j]){
            arr[k]=der[j];
            emp[k]=derE[j];
            j++;
        }
        else{
            arr[k]=izq[i];
            emp[k]=izqE[i];
            i++;
        }
        k++;
    }
    
    while(i<elementosIzq){
        arr[k]=izq[i];
        emp[k]=izqE[i];
        k++;
        i++;
    }
    while(j<elementosDer){
        arr[k]=der[j];
        emp[k]=derE[j];
        k++;
        j++;
    }
}

void mergeSort(int valdia[], int ini, int fin, char emp[]){//se ordena el arreglo con divide y venceras
    if(ini>=fin){
        return;
    }
    int med=(ini+fin)/2;
    mergeSort(valdia, ini, med, emp);
    mergeSort(valdia, med+1, fin, emp);
    merge(valdia, ini, med, fin, emp);
    
}

int busquedaBin(int valdia[], int ini, int fin, double IBd){//se realiza la busqueda con divide y venceras
    if(ini==fin){
        return ini;
    }
    int med=(ini+fin)/2;
    
    if(valdia[med]>IBd){ //se busca el primero que sea mayor a IBd, para a partir de ahi imprimir
        return busquedaBin(valdia, ini, med, IBd);
    }
    else{
        return busquedaBin(valdia, med+1, fin, IBd);
    }
}

void evalDia(int C,int T,int IBm, char emp[][MAXEMP], int val[][MAXEMP], int ndia){
    if(ndia==T) return;
    
    mergeSort(val[ndia], 0, C-1, emp[ndia]);
    double IBd=0;
    int sumaAcciones=0;
    for(int i=0;i<C;i++)
        IBd+=val[ndia][i];
    IBd/=C;
    cout<<ndia+1<<"     "<<setw(10)<<IBd<<"   ";
    if(IBd<=IBm){
        cout<<"Compra"<<"   ";
        int imayorIBd=busquedaBin(val[ndia], 0, C-1, IBd);
        for(int i=0;i<imayorIBd;i++){
            cout<<emp[ndia][i]<<" ";
            sumaAcciones+=val[ndia][i];
        }
    }
    else{
        cout<<"Vende" <<"    ";
        int imayorIBd=busquedaBin(val[ndia], 0, C-1, IBd);
        for(int i=imayorIBd;i<C;i++){
            cout<<emp[ndia][i]<<" ";
            sumaAcciones+=val[ndia][i];
        }
    }
    cout<<"     "<<sumaAcciones<<endl;
    evalDia(C, T, IBm, emp, val, ndia+1);
}

int main(int argc, char** argv) {
    int C=7, T=6;
    double IBm=4.2;
    
    int val[][MAXEMP]={ {8,4,5,6,7,1,2},
                        {3,4,5,7,1,2,6},
                        {5,6,5,2,1,6,8},
                        {3,4,5,6,2,1,9},
                        {3,4,5,4,5,3,2},
                        {3,4,4,8,9,7,6}};
    char emp[MAXDIAS][MAXEMP];
    for(int j=0;j<T;j++)
        for(int i=0;i<C;i++)
            emp[j][i]='A'+i;
    evalDia(C, T, IBm, emp, val, 0);
    
    return 0;
}

