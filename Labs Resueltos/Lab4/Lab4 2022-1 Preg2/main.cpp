/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 3 de junio de 2023, 07:26 PM
 */

#include <cstdlib>
#include "abb.h"

using namespace std;

ABB buscam(ABB parbol){
    if (parbol==NULL) return parbol;
    else{
        if(parbol->hizq==NULL)
            return parbol;
        else
            return buscam(parbol->hizq);
    }
}

ABB borranodo(ABB parbol,int valor){
    
    if(parbol==NULL) return parbol;
    
    if(valor<parbol->elem.lote)
        parbol->hizq = borranodo(parbol->hizq,valor);
    else
        if(valor>parbol->elem.lote)
            parbol->hder = borranodo(parbol->hder,valor);
        else{
            if(parbol->hizq==NULL){
                ABB temp = parbol->hder;              
                delete parbol;
                return temp;
            }
            else
                if(parbol->hder==NULL){
                    ABB temp = parbol->hizq;
                    delete parbol;
                    return temp;
                }
            ABB temp = buscam(parbol->hder);    
            parbol->elem = temp->elem;    
            parbol->hder=borranodo(parbol->hder,temp->elem.lote);
            return parbol;
        }    
}

void despachaLote(ABB &parbol, int n){
    if(n==0 || parbol==NULL) return;
    ABB temp = buscam(parbol);
    
    if(temp->elem.cantidad<=n){
        n-=temp->elem.cantidad;
        borranodo(parbol, temp->elem.lote);
        despachaLote(parbol, n);
    }
    else if(temp->elem.cantidad>n){
        temp->elem.cantidad -= n;
    }
}

int main(int argc, char** argv) {
    ABB A1;
    construir(A1);
    Elemento e;
    e.lote=20220815; e.cantidad=40;
    insertar(A1, e);
    e.lote=20220710; e.cantidad=50;
    insertar(A1, e);
    e.lote=20220720; e.cantidad=50;
    insertar(A1, e);
    e.lote=20220630; e.cantidad=50;
    insertar(A1, e);
    e.lote=20220624; e.cantidad=40;
    insertar(A1, e);
    e.lote=20220615; e.cantidad=40;
    insertar(A1, e);
    e.lote=20220618; e.cantidad=40;
    insertar(A1, e);
    e.lote=20220930; e.cantidad=30;
    insertar(A1, e);
    cout<<"La representación, en preorden, del árbol de lotes de productos es: "<<endl;
    mostrarEnPreOrden(A1);
    cout<<endl;
    int n, cantidad;
    cout<<"Ingrese la cantidad de solicitudes de despacho: ";
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cout<<"Ingrese la cantidad de unidades para el despacho: ";
        cin>>cantidad;   
        despachaLote(A1, cantidad);
        cout<<"La representación, en preorden, del árbol de lotes de productos luego del despacho "<<i<<" es: "<<endl;
        mostrarEnPreOrden(A1);
        cout<<endl;
    }
    
    
    
    
    return 0;
}

