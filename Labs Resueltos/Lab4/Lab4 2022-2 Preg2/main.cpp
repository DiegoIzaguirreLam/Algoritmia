/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 1 de junio de 2023, 12:54 PM
 */

#include <cstdlib>

#include "abb.h"

using namespace std;

ABB busca(ABB parbol,int valor){
    if(parbol==NULL) return parbol;
    else{
        if(parbol->elem.lote == valor) return parbol;
        else{
            if(parbol->elem.lote < valor ) parbol=parbol->hder;
            else
                parbol=parbol->hizq;
            return busca(parbol,valor);
        }
    }
}


void fusionaAlmacen(ABB &A1, ABB &A2){
    if(A2==NULL) return;
    ABB p;
    p = busca(A1, A2->elem.lote);
    
    if(p==NULL){
        insertar(A1, A2->elem);
    }
    else{
        p->elem.cantidad += A2->elem.cantidad;
    }
    if(A2->hizq!=NULL) fusionaAlmacen(A1, A2->hizq);
    if(A2->hder!=NULL) fusionaAlmacen(A1, A2->hder);
    A2=NULL;
    delete A2;
}

int main(int argc, char** argv) {
    ABB A1;
    construir(A1);
    Elemento e;
    e.lote=20170620; e.cantidad=20;
    insertar(A1, e);
    e.lote=20170810; e.cantidad=20;
    insertar(A1, e);
    e.lote=20180211; e.cantidad=20;
    insertar(A1, e);
    e.lote=20180409; e.cantidad=10;
    insertar(A1, e);
    
    ABB A2;
    construir(A2);
    e.lote=20170811; e.cantidad=5;
    insertar(A2, e);
    e.lote=20180211; e.cantidad=10;
    insertar(A2, e);
    e.lote=20180410; e.cantidad=15;
    insertar(A2, e);
    
    mostrarEnOrden(A1);
    cout<<endl;
    mostrarEnOrden(A2);
    cout<<endl;
    fusionaAlmacen(A1, A2);
    cout<<endl;
    mostrarEnOrden(A1);
    cout<<endl;
    mostrarEnOrden(A2);
    
    return 0;
}

