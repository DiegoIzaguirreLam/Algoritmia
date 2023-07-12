
#include <iostream>
#define MAX 10
using namespace std;
int solu[MAX];
int y=0;
int x=0;
int nSol=0;

void imprimeSolu(int pallet[][MAX],int M,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) cout<<pallet[i][j]<<" ";
        cout<<endl;
    }
}

int hallarpeso(int ind, int n, int peso, int paq[], int tomados[], int pallets[][MAX], int indPallet, int indPeso, int M, int N, int pesoObj){
    if(indPallet==N){
        imprimeSolu(pallets, M, N);
        return 1;
    }
    if(ind==n || peso<0 || indPeso==M)
        return 0;

    if(paq[ind]==peso && !tomados[ind]){//se termina de llenar el pallet y se pasa al siguiente pallet
        pallets[indPallet][indPeso]=paq[ind];
        tomados[ind]=1;
        if(hallarpeso(0, n, pesoObj, paq, tomados, pallets, indPallet+1, 0, M, N, pesoObj)){
            return 1;
        }
        else{
            pallets[indPallet][indPeso]=0;
            tomados[ind]=0;
            return 0;
        }
    }
    if(!tomados[ind]){
        pallets[indPallet][indPeso]=paq[ind];
        tomados[ind]=1;
        if(hallarpeso(ind+1, n, peso-paq[ind], paq, tomados, pallets, indPallet, indPeso+1, M, N, pesoObj)){
            return 1;
        }
        else{
            pallets[indPallet][indPeso]=0;
            tomados[ind]=0;
            return hallarpeso(ind+1, n, peso, paq, tomados, pallets, indPallet, indPeso, M, N, pesoObj);
        }
    }
    else{
        return hallarpeso(ind+1, n, peso, paq, tomados, pallets, indPallet, indPeso, M, N, pesoObj);
    }
}

int calculaSuma(int arr[], int n){
    int suma=0;
    for(int i=0;i<n;i++) suma += arr[i];
    return suma;
}

int main(){
    int M = 2, N = 3;
    int arr[]={4, 5, 3, 1, 3, 2};
    int n=6;
    int pallets[N][MAX]={};
    int tomados[n]={};
    int suma = calculaSuma(arr, n);
    if(n == M*N){
        if(!hallarpeso(0, n, suma/N, arr, tomados, pallets, 0, 0, M, N, suma/N))
            cout<<"No hay soluciones"<<endl;
    }
    else{
        cout<<"La cantidad de pallets debe ser igual a N*M"<<endl;
    }
    return 0;
}






