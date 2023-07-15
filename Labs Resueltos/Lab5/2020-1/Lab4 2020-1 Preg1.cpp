
#include <iostream>
#include <fstream>
#include <cstdlib>

#define MAX 100

using namespace std;

int solu[MAX]={};
int y=0;

void leeProyectos(ifstream &archProyectos, int N, int costo[],int predecesores[][MAX]){
    for(int i=0;i<N;i++){//ingrese el costo de los proyectos (0...N-1)
        archProyectos>>costo[i];
    }
    int predec;
    for(int i=0;i<N;i++){//ingrese los predecesores para el proyecto i. Ingresar -1 cuando no hay más predecesores.
        predec=0;
        while(predec!=-1){
            archProyectos>>predec;
            if(predec!=-1) predecesores[i][predec]=1;
        }
    }
}

int valido(int predecesores[][MAX],int N,int indProyecto,int solu[]){
    int flagPred;
    for(int i=0;i<N;i++)
        if(predecesores[indProyecto][i]){
            flagPred=0;
            for(int j=0;j<y;j++){
                if(solu[j]==i){
                    flagPred=1;
                    break;
                }
            }
            if(!flagPred) return 0;
        }
    return 1;
}

int seleccionauna(int costo[],int predecesores[][MAX],int N,int P,int indProyecto){
    if(P==0){
        for(int i=0;i<y;i++){
            cout<<"P"<<solu[i]<<" ";
        }
        cout<<endl;
        return 1;
    }
    if(P<0 || indProyecto==N) return 0;
    if(valido(predecesores, N, indProyecto, solu)){
        solu[y] = indProyecto;
        y++;
        if(seleccionauna(costo, predecesores, N, P-costo[indProyecto], indProyecto+1)){
            return 1;
        }
        else{
            y--;
        }
    }
    return seleccionauna(costo, predecesores, N, P, indProyecto+1);
}

int seleccionamultiples(int costo[],int predecesores[][MAX],int N,int P,int indProyecto){
    if(P==0){
        for(int i=0;i<y;i++){
            cout<<"P"<<solu[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    if(P<0 || indProyecto==N) return 0;
    if(valido(predecesores, N, indProyecto, solu)){
        solu[y] = indProyecto;
        y++;
        if(seleccionamultiples(costo, predecesores, N, P-costo[indProyecto], indProyecto+1)){
            return 1;
        }
        else{
            y--;
        }
    }
    return seleccionamultiples(costo, predecesores, N, P, indProyecto+1);
}

int main(){
    int N, P;
    ifstream archProyectos;
    archProyectos.open("Proyectos.txt", ios::in);
    if(!archProyectos){
        cout<<"Error al abrir archProyectos"<<endl;
        exit(1);
    }
    archProyectos>>N>>P;
    
    int costo[N], predecesores[N][MAX]={};
    leeProyectos(archProyectos, N, costo, predecesores);
    archProyectos.close();
    /*for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(predecesores[i][j]){
                cout<<"P"<<i<<" depende de P"<<j<<endl;
            }
        }
    }*/
    if(!seleccionauna(costo, predecesores, N, P, 0)){
        cout<<"No hay soluciones"<<endl;
    }
    y=0;
    cout<<endl;
    seleccionamultiples(costo, predecesores, N, P, 0);
    
}

