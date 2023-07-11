/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 22 de junio de 2023, 10:25 AM
 */

#include <cstdlib>
#include <iostream>
#define MAX 4
#define MAXCAR 27


using namespace std;

void imprimeSolu(char carUnic[], int charANum[], int nCarUnic){
    for(int i=0;i<nCarUnic;i++){
        cout<<carUnic[i]<<"="<<charANum[i]<<", ";
    }
    cout<<endl;
}

void hallaCarUnic(char cript[][MAX], int n,int m, char carUnic[], int &nCarUnic){
    nCarUnic = 0;
    int flagCarUnic;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            flagCarUnic=1;
            if(!('A'<=cript[i][j] && cript[i][j]<='Z')) continue;//asumiendo que todas las letras estan en mayusculas
            for(int k=0;k<nCarUnic;k++){
                if(carUnic[k]==cript[i][j]){
                    flagCarUnic=0;
                    break;
                } 
            }
            if(flagCarUnic){
                carUnic[nCarUnic++]=cript[i][j];
            }
        }
}

int validaValor(char cript[][MAX], int n,char carUnic[],int charANum[],int valor,int nCarUnic,int indC){//evalua que no se repita el valor del caracter
    if(valor==0){
        for(int i=0;i<n;i++){
            if(cript[i][0]==carUnic[indC]) return 0; //si el valor es 0 y toca asignar un valor a algun digito mas a la izquierda, no se puede.
        }
    }
    for(int i=0;i<nCarUnic;i++){
        if(charANum[i]==valor) return 0;
    }
    return 1;
}

int hallaPosCarUnic(char carUnic[], int nCarUnic, char car){
    for(int i=0;i<nCarUnic;i++){
        if(carUnic[i]==car)
            return i;
    }
    return -1;
}

int validaOperacion(char cript[][MAX], int n, int m, char operacion, char carUnic[], int charANum[], int nCarUnic){
    int result=0, resultOp=0, numFormado;
    int ind;
    if(operacion=='+'){
        for(int j=0;j<m;j++){
            ind=hallaPosCarUnic(carUnic, nCarUnic, cript[4][j]);
            if(ind!=-1) result = result*10 + charANum[ind];
        }
        for(int i=0;i<n-1;i++){//todas las filas menos la ultima (resultado)
            numFormado=0;
            for(int j=0;j<m;j++){
                ind=hallaPosCarUnic(carUnic, nCarUnic, cript[i][j]);
                if(ind!=-1) numFormado = numFormado*10 + charANum[ind];// hallo el numero en la fila
            }
            resultOp = resultOp + numFormado;
        }
        return result == resultOp;
    }
    else
        return 0;
}

int resuelveCript(char cript[][MAX],char operacion, int n,int m, char carUnic[], int nCarUnic, int charANum[], int indC){//asigno a la letra en la posicion indC un valor
    if(indC==nCarUnic){
        if(validaOperacion(cript, n, m, operacion, carUnic, charANum, nCarUnic)){
            imprimeSolu(carUnic, charANum, nCarUnic);
            return 0; 
        }
        return 0;
    }
    for(int i=0;i<10;i++){
        if(validaValor(cript, n, carUnic, charANum, i, nCarUnic, indC)){
            charANum[indC] = i;
            if(resuelveCript(cript, operacion, n, m, carUnic, nCarUnic, charANum, indC+1)){
                return 1;
            }
        }
    }
    charANum[indC] = -1;
    return 0;
}

int main(int argc, char** argv) {
    
    char cript[5][MAX]={{'D','O','S'},{'D','O','S'},{'D','O','S'},{'D','O','S'},{'O','C','H','O'}};
    int n=5, m=MAX;
    char operacion='+';
    char carUnic[MAXCAR];
    int nCarUnic;
    
    hallaCarUnic(cript, n, m, carUnic, nCarUnic);
    for(int i=0;i<nCarUnic;i++) cout<<carUnic[i]<<" ";
    cout<<endl;
    int charANum[nCarUnic]={0};
    resuelveCript(cript, operacion, n, m, carUnic, nCarUnic, charANum, 0);
    
    return 0;
}

