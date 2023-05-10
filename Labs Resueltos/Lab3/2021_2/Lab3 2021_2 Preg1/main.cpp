/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 8 de mayo de 2023, 04:45 PM
 */

#include <cstdlib>
#include <iostream>
#include "cola.h"

using namespace std;

void ordenaC(Cola *ptrC, int n, int piso, int flag){
    Elemento min, aux;
    int mindif, i=1, auxdif;
    if(n==0) return;
    min=desencolar(ptrC);
    mindif=abs(piso-min.piso);
    while(i<n){
        aux=desencolar(ptrC);
        auxdif=abs(piso-aux.piso);//    (((auxdif>mindif && flag && aux.piso>piso) || (aux.piso<piso && flag && min.piso>piso)) || ((auxdif>mindif && !flag && aux.piso<piso) || (aux.piso>piso && !flag && min.piso<piso)))
        if(((auxdif>mindif && flag && aux.piso>piso) || (aux.piso<piso && flag && min.piso>piso)) || ((auxdif>mindif && !flag && aux.piso<piso) || (aux.piso>piso && !flag && min.piso<piso))){
            encolar(ptrC, min);
            min=aux;
            mindif=auxdif;
        }
        else{
            encolar(ptrC, aux);
        }
        i++;
    }
    ordenaC(ptrC, n-1, piso, flag);
    encolar(ptrC, min);
}
/*
void ordenaReq(Cola *ptrC, int n, int piso, int flag){
    Elemento min, aux;
    int i=1;
    if(n==0) return;
    min=desencolar(ptrC);
    while(i<n){
        aux=desencolar(ptrC);
        if((aux.piso>piso && flag) || (aux.piso<piso && !flag)){
            encolar(ptrC, min);
            min=aux;
        }
        else{
            encolar(ptrC, aux);
        }
        i++;
    }
    ordenaReq(ptrC, n-1, piso, flag);
    encolar(ptrC, min);
}
*/
void muestraRecur(Cola *ptrC, int n){
    Elemento elem;
    if(n==0) return;
    elem=desencolar(ptrC);
    encolar(ptrC, elem);
    muestraRecur(ptrC, n-1);
    cout << elem.piso << "-" << elem.flagDir<<" -> ";
}

int main(int argc, char** argv) {
    
    Cola cGeneral, cS, cB;
    construir(&cGeneral);
    construir(&cS);
    construir(&cB);
    
    int npisos=7, pisoS=1, pisoB=1, nSoli, inicio=1;
    Solicitud s;
    s.piso=1; s.flagDir=1;
    encolar(&cGeneral, s);
    encolar(&cS, s);
    encolar(&cB, s);

    while(!esColaVacia(cS) || !esColaVacia(cB)){
        cout<<"La cola general de solicitudes tiene: "<<endl;
        muestraRecur(&cGeneral, cGeneral.longitud);
        cout<<endl;
        if(inicio==1){
            cout<<"Luego de asignar las solicitudes a cada ascensor se tiene: "<<endl;
            cout<<"Cola 1: ";
            muestraRecur(&cS, cS.longitud);
            cout<<endl;
            cout<<"Cola 2: ";
            muestraRecur(&cB, cB.longitud);
            cout<<endl;
            inicio=2;
            desencolar(&cGeneral);
            cout<<"El ascensor 1 esta en el piso "<<pisoS<<endl;
            cout<<"El ascensor 2 esta en el piso "<<pisoB<<endl;
        }
        else{
            if(inicio==2){
                desencolar(&cS);
                desencolar(&cB);
                inicio=0;
            }
            cout<<"Ingresar la cantidad de solicitudes"<<endl;
            cin>>nSoli;
            for(int i=0;i<nSoli;i++){
                cin>>s.piso>>s.flagDir;
                encolar(&cGeneral, s);
            }
            cout<<"La cola general de solicitudes tiene: "<<endl;
            muestraRecur(&cGeneral, cGeneral.longitud);
            cout<<endl;
            while(!esColaVacia(cGeneral)){
                s=desencolar(&cGeneral);
                if(s.flagDir)
                    encolar(&cS, s);
                else
                    encolar(&cB, s);
            }
            ordenaC(&cS, cS.longitud, pisoS, 1);
            ordenaC(&cB, cB.longitud, pisoB, 0);
            //ordenaReq(&cS, cS.longitud, pisoS, 1);
            //ordenaReq(&cB, cB.longitud, pisoB, 0);
            cout<<"Luego de asignar las solicitudes a cada ascensor se tiene: "<<endl;
            cout<<"Cola 1: ";
            muestraRecur(&cS, cS.longitud);
            cout<<endl;
            cout<<"Cola 2: ";
            muestraRecur(&cB, cB.longitud);
            if(!esColaVacia(cS)){
                s=cS.frente->elem;
                pisoS=s.piso;
            }
            if(!esColaVacia(cB)){
                s=cB.frente->elem;
                pisoB=s.piso;
            }
            cout<<endl;
            cout<<"El ascensor 1 esta en el piso "<<pisoS<<endl;
            cout<<"El ascensor 2 esta en el piso "<<pisoB<<endl;
            if(!esColaVacia(cS))
                desencolar(&cS);
            if(!esColaVacia(cB))
                desencolar(&cB);
        }

    }
    return 0;
}

