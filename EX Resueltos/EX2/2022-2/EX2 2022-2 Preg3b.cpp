
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 10
using namespace std;

int pallets[MAX][MAX]={0};

int asignaPallets(int arr[],int tomados[], int N,int M,int n,int pesoObj, int indPeso, int iPallet,int iPeso, int peso){
    if(iPallet==N){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                cout<<pallets[i][j]<<" ";
            cout<<endl;
        }
        return 1;
    }
    if(peso<0 || indPeso==n) return 0;
    if(!tomados[indPeso]){
        if(peso==arr[indPeso]){//se completa y se pasa al siguiente pallet
            tomados[indPeso]=1;
            pallets[iPallet][iPeso]=arr[indPeso];
            if(asignaPallets(arr, tomados, N, M, n, pesoObj, 0, iPallet+1, 0, pesoObj)){
                return 1;
            }
            else{//back (de pallet)
                tomados[indPeso]=0;
                pallets[iPallet][iPeso]=0;
                return asignaPallets(arr, tomados, N, M, n, pesoObj, indPeso+1, iPallet, iPeso, peso);
            }
        }
        else{//se agrega el peso al pallet
            tomados[indPeso]=1;
            pallets[iPallet][iPeso]=arr[indPeso];
            if(asignaPallets(arr, tomados, N, M, n, pesoObj, indPeso+1, iPallet, iPeso+1, peso-arr[indPeso])){
                return 1;
            }
            else{//back (de peso colocado en pallet)
                tomados[indPeso]=0;
                pallets[iPallet][iPeso]=0;
                return asignaPallets(arr, tomados, N, M, n, pesoObj,indPeso+1, iPallet, iPeso, peso);
            }
        }
    }
    else{//no se puede volver a tomar el peso, se pasa al siguiente
        return asignaPallets(arr, tomados, N, M, n, pesoObj,indPeso+1, iPallet, iPeso, peso);
    }
}

int main(){
    int M=2, N=3;
    int arr[]={4, 5, 3, 1, 3, 2};
    int n=6;
    int tomados[n]={};
    int suma=0;
    for(int i=0;i<n;i++) suma+=arr[i];
    
    if(!asignaPallets(arr, tomados, N, M, n, suma/N, 0, 0, 0, suma/N)){
        cout<<"No se pudieron asignar los pesos equitativamente a los pallets"<<endl;
    }
    return 0;
}

