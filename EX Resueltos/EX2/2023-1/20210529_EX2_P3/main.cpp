//Diego Izaguirre Lam. Codigo 20210529

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 15 de julio de 2023, 08:10 AM
 */

#include <cstdlib>
#include <iostream>
#define MAX 50
#define MAXEJ 10
using namespace std;

int marcaRuta[MAX]={};
int nSol=0;

int validaVictoria(int bowser, int guerrEj){//si bowser tiene mas poder equivalente (medido en guerreros de agua), ganara la batalla
    if(bowser>guerrEj) return 1;
    else return 0;
}

void guardaGuerreros(int distr[],int guerrAntes[]){//guardamos los guerreros antes de la batalla
    for(int i=0;i<3;i++)
        guerrAntes[i]=distr[i];
}

void restaGuerreros(int distr[],int guerrEj){
    for(int i=1;i<=3;i++){//resta los guerreros y guarda los que resta en restaGuerr
        if(i*distr[i-1]>guerrEj){//guerrEj medido en guerreros de agua
            distr[i-1] -= guerrEj/i;//restamos el equivalente a distr
            break;
        }
        else{
            guerrEj -= distr[i-1]*i;
            distr[i-1]=0;
        }
    }
}

int hallaRuta(int bowser,int distr[], int frentes[][MAXEJ],int n,int nejer,int indFrente){
    if(indFrente==n){
        nSol++;
        cout<<"Solucion "<<nSol<<": ";
        cout<<"El reino champiñón ha caido, el ejército de Bowser venció ";
        for(int i=0;i<nejer;i++){
            cout<<"al ejercito "<<marcaRuta[i]<<" del frente "<<i+1<<", ";
        }
        cout<<"Le quedaron ";
        for(int i=0;i<3;i++){
            cout<<distr[i]<<" guerreros de tipo ";
            if(i==0) cout<<"Agua, ";
            if(i==1) cout<<"Tierra, ";
            if(i==2) cout<<"Aire. ";
        }
        cout<<endl<<endl;
        return 0;//para encontrar todas, return 0
    }
    int guerrAntes[3];
    for(int i=0;i<nejer;i++){//ejercitos del frente i, intenta para cada ejercito.
        if(validaVictoria(bowser, frentes[indFrente][i])){
            guardaGuerreros(distr, guerrAntes);//guardamos los guerreros antes de la batalla
            restaGuerreros(distr, frentes[indFrente][i]);
            marcaRuta[indFrente]=i+1;//marca el ejercito que ataco en la ruta
            if(hallaRuta(bowser-frentes[indFrente][i],distr, frentes, n, nejer, indFrente+1)){
                return 1;
            }
            else{//le tengo que "devolver" los guerreros a bowser y desmarcar el ejercito de la ruta
                marcaRuta[indFrente]=0;
                for(int k=0;k<3;k++)
                    distr[k] = guerrAntes[k];
            }
        }
    }
    return 0;//si no lo puede vencer, se debe hacer back para hallar otra solu
}


int main(int argc, char** argv) {
    int numEj;
    int bowser=0;//guerreros de bowser equivalentes en agua
    int distr[3]={};//guarda la distribucion de guerreros de bowser
    for(int i=1;i<=3;i++){
        cout<<"Ingrese la cantidad de guerreros del tipo ";
        if(i==1) cout<<"Agua ";
        if(i==2) cout<<"Tierra ";
        if(i==3) cout<<"Aire ";
        cout<<"del ejercito de Bowser: ";
        cin>>numEj;
        distr[i-1]=numEj;
        bowser += numEj*i;
    }
    int n, nejer;
    cout<<"Ingrese el número de frentes del reino champiñón: ";
    cin>>n;
    cout<<"Ingrese el número de ejércitos del reino champiñón por cada frente: ";
    cin>>nejer;
    int frentes[n][MAXEJ]={};//cada frente tomara una fila, con cada uno de sus ejercitos (agua, tierra, aire, respectivamente) en las columnas de dicha fila
    int totalAgua=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<nejer;k++){
            totalAgua=0;
            for(int j=1;j<=3;j++){
                cout<<"Ingrese la cantidad de guerreros del tipo ";
                if(j==1) cout<<"Agua ";
                if(j==2) cout<<"Tierra ";
                if(j==3) cout<<"Aire ";
                cout<<"del ejercito "<<k+1<<" del Frente "<<i+1<<" del reino champiñón: ";
                cin>>numEj;
                totalAgua = totalAgua + numEj*j;//relaciones de equivalencia a agua
            }
            frentes[i][k]= totalAgua;//total equivalente a agua del ejercito k del frente i
        }
    }
    hallaRuta(bowser, distr, frentes, n, nejer, 0);
    if(!nSol){//si no hay soluciones
        cout<<"El reino champiñon ha resultado victorioso"<<endl;
    }
    return 0;
}

/*
 150
80
40
2
2
30
20
10
35
25
15
18
15
12
22
13
10

 */

