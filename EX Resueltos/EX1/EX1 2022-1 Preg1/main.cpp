/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 12 de mayo de 2023, 06:24 PM
 */

#include <cstdlib>
#include <iostream>

#include "pila.h"
using namespace std;

Elemento cima(Pila P){
    return P.cima->elem;
}

void cargarContenedor(Pila &contenedor){
    Elemento e;
    e.codigo=10;e.fechaCad=20221224; apilar(&contenedor, e);
    e.codigo=9;e.fechaCad=20221130; apilar(&contenedor, e);
    e.codigo=8;e.fechaCad=20221212; apilar(&contenedor, e);
    e.codigo=7;e.fechaCad=20220814; apilar(&contenedor, e);
    e.codigo=6;e.fechaCad=20221106; apilar(&contenedor, e);
    e.codigo=5;e.fechaCad=20221003; apilar(&contenedor, e);
    e.codigo=4;e.fechaCad=20220918; apilar(&contenedor, e);
    e.codigo=3;e.fechaCad=20220630; apilar(&contenedor, e);
    e.codigo=2;e.fechaCad=20221006; apilar(&contenedor, e);
    e.codigo=1;e.fechaCad=20110603; apilar(&contenedor, e);
}

void apila_enCaja(Pila &cajai, Elemento e, int c){
    Elemento temp;
    temp=desapilar(&cajai);
    if(esPilaVacia(cajai) || e.fechaCad<cima(cajai).fechaCad){
        apilar(&cajai, e);
        apilar(&cajai, temp);
        return;
    }
    apila_enCaja(cajai, e, c);   
    apilar(&cajai, temp);
}

void asignaCaja(Pila caja[], int ncajas, int c, Elemento e){
    Elemento eReg;
    for(int i=0;i<ncajas;i++){//para cada una de las cajas
        if(esPilaVacia(caja[i]) || (e.fechaCad < cima(caja[i]).fechaCad && obtenerLongitud(caja[i])<c)){// ya lo apile
            apilar(&caja[i], e);
            break;
        }
        else if(e.fechaCad > cima(caja[i]).fechaCad && obtenerLongitud(caja[i])==c){//tengo que sacar elementos, apilar el que tengo y volverlos a apilar. en caso se exceda la capacidad, tengo que volver a apilar el ultimo elemento que saque
            eReg=desapilar(&caja[i]);//voy a tener que volver a poner la cima en otro lado, entonces lo guardo
            apila_enCaja(caja[i], e, c);//se coloca el producto en la caja
            asignaCaja(caja, ncajas, c, eReg);
            break;
        }
        else if(e.fechaCad > cima(caja[i]).fechaCad && obtenerLongitud(caja[i])<c){//buscamos la posicion que debe ir en la caja.
            apila_enCaja(caja[i], e, c);
            break;
        }
    }//si la caja esta llena y la fecha de caducidad del producto a agregar es menor que la cima, no debemos revisar la caja y pasamos a la siguiente
}

void distribuyeCajas(Pila &contenedor, Pila caja[], int ncajas, int c){
    while(!esPilaVacia(contenedor))
        asignaCaja(caja, ncajas, c, desapilar(&contenedor));
}


int main(int argc, char** argv) {
    int n=10, c=3;
    int ncajas=n/c+1;
    Pila contenedor, caja[ncajas];
    construir(&contenedor);
    for(int i=0;i<ncajas; i++)
        construir(&caja[i]);
    cargarContenedor(contenedor);
    
    distribuyeCajas(contenedor, caja, ncajas, c);
    
    for(int i=0;i<ncajas; i++){
        cout<<"Caja "<<i+1<<": ";
        mostrar(caja[i]);
    }
    return 0;
}

