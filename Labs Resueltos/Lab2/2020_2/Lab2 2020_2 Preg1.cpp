
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 30 de abril de 2023, 09:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#define MAX 3
using namespace std;

/*
 * 
 */
void cargabin(int num,int n,int cromo[],int uni){
	int i,res;
	for(i=0;i<n;i++)cromo[i]=0; 
	i=0;
	while(num>0){
		res = num%uni;
		num = num/uni;
		cromo[i]=res;
		i++;
	}
}

int hallaMax(int maq[][MAX],int N, int i, int opcion){
    if(i==opcion){
        return 0;
    }
    int cromo[N], suma=0, ocupado[N]={}, invalido=0;
    cargabin(i, N, cromo, N);
    
    for(int j=0;j<N;j++){
        if(ocupado[j]==0) ocupado[j]=1;
        else{
            invalido=1;
            break;
        }
        suma+=maq[j][cromo[j]];
    }
    if(invalido==1) suma=0;
    
    return max(suma, hallaMax(maq, N, i+1, opcion));
}

int main(int argc, char** argv) {
    int N=3;
    int maq[][3]={{100,150,200},{100,100,100},{100,200,150}};
    int opcion=(int)(pow(N,N));
    cout<<hallaMax(maq, N, 0, opcion);
    return 0;
}


