
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 10

using namespace std;

int solu[]={0,0,0,0,0,0};

int valida(int ciudades[][MAX],int refri[],int n,int indCiudad, int vac){
    if(vac==0 && refri[indCiudad]==0) return 0;
    for(int i=0;i<n;i++)
        if(ciudades[indCiudad][i] && solu[i]==vac) return 0;
    for(int i=0;i<n;i++)
        if(ciudades[i][indCiudad] && solu[i]==vac) return 0;
    return 1;
}


int hallasoluciones(int ciudades[][MAX],int refri[],int costo[], int n, int indCiudad, int parcial){
    if(indCiudad==n){
        for(int i=0;i<n;i++){
            cout<<solu[i]+1<<" ";
        }
        cout<<" Costo: $ "<<parcial<<"K"<<endl;
        return 0;
    }
    
    for(int i=0;i<4;i++){
        if(valida(ciudades, refri, n, indCiudad, i)){
            solu[indCiudad]=i;
            parcial+=costo[i];
            if(hallasoluciones(ciudades,refri,costo,n,indCiudad+1,parcial)){
                return 1;
            }
            else{
                solu[indCiudad]=-1;
                parcial-=costo[i];
            }
        }
    }
    return 0;
}

int main(){
    int ciudades[][MAX]={  {0,1,1,0,0,1},
                        {1,0,1,1,0,0},
                        {1,1,0,1,0,1},
                        {0,1,1,0,1,1},
                        {0,0,0,1,0,1},
                        {1,0,1,1,1,0}};
    int n=6;
    int refri[]={0,0,1,0,1,0};
    int costo[]={10, 5, 12, 8};
    
    hallasoluciones(ciudades, refri, costo, n, 0, 0);
    
    return 0;
}



