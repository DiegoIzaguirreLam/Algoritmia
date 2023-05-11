/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 9 de mayo de 2023, 08:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include "listaSimple.h"

using namespace std;


void ordena(Lista &L, int n){//ordena la lista, intercambiando valores (no hay restricciones)
    Nodo *p, *q;
    Elemento temp;
    p=L.cabeza;
    if(p==NULL)
        return;
    else{
        while(p!=NULL){
            q=p->sig;
            while(q!=NULL){
                if(p->elem.hora > q->elem.hora){
                    temp=q->elem;
                    q->elem=p->elem;
                    p->elem=temp;
                }
                q=q->sig;
            }
            p=p->sig;
        }
    }
}

void fusiona(Lista &L1, Lista &L2){
    if(esListaVacia(L2))
        return;
    //verificar si son disjuntos, solo se concatena L2 al final de L1. esto se puede ya que todas las listas estan previamente ordenadas de menor a mayor
    if(L1.ultimo->elem.hora<L2.cabeza->elem.hora){
        L1.ultimo->sig=L2.cabeza;
        L1.ultimo=L2.ultimo;
        L1.longitud+=L2.longitud;
    }
    else if(L1.cabeza->elem.hora > L2.ultimo->elem.hora){//L2 debe ir antes de L1
        L2.ultimo->sig=L1.cabeza;
        L1.cabeza=L2.cabeza;
        L1.longitud+=L2.longitud;
    }
    else{
        Nodo *p=L1.cabeza, *q=L2.cabeza, *aux, *aux2;
        int i=0;
        
        while(p!=NULL && q!=NULL){//se recorre solo la lista L1, por lo que la complejidad es O(n) como maximo
            if(p==L1.cabeza && p->elem.hora>q->elem.hora){//en caso el elemento deba ir al comienzo
                aux2=q->sig;
                L1.cabeza=q;
                q->sig=p;
                q=aux2;
                L1.longitud++;
            }
            else if(p!=L1.ultimo && p->elem.hora <= q->elem.hora && q->elem.hora<p->sig->elem.hora){//se compara cada valor de L2 con el de q1.
                aux=p->sig;
                aux2=q->sig;//aux para no perder cual es el siguiente valor que debe ser insertado
                p->sig=q;
                q->sig=aux;
                q=aux2;
                i++;
                L1.longitud++;
            }
            p=p->sig;
        }
        if(q!=NULL){//en caso termine de recorrer la Lista L1 y aun hay elementos sin colocar, estos deben ir al final de la lista L1:
            L1.ultimo->sig=q;
            L1.ultimo=L2.ultimo;
            L1.longitud=L1.longitud+L2.longitud-i;
        }
    }
}

void mostrarSalida(Lista L){
    Nodo *p;
    if ( esListaVacia(L) )
        cout << "La lista esta vacia" << endl;
    else
    {
        p = L.cabeza;
        while ( p!= NULL )
        {
            cout << p->elem.hora << "("<<p->elem.sucursal<<")("<<p->elem.dia<<")"<<" -> ";
            p = p->sig;
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {
    Lista Lun, Mar, Mier, Jue, Vie;
    construir(Lun);
    construir(Mar);
    construir(Mier);
    construir(Jue);
    construir(Vie);
    Elemento e;//entrada de datos
    
    e.hora=7;e.sucursal=15;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    e.hora=8;e.sucursal=6;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    e.hora=10;e.sucursal=14;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    e.hora=12;e.sucursal=1;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    e.hora=13;e.sucursal=7;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    
    e.hora=4;e.sucursal=19;strcpy(e.dia,"Martes");
    insertarFinal(Mar, e);
    e.hora=5;e.sucursal=3;strcpy(e.dia,"Martes");
    insertarFinal(Mar, e);
    
    e.hora=8;e.sucursal=2;strcpy(e.dia,"Miercoles");
    insertarFinal(Mier, e);
    e.hora=9;e.sucursal=5;strcpy(e.dia,"Miercoles");
    insertarFinal(Mier, e);
    e.hora=10;e.sucursal=10;strcpy(e.dia,"Miercoles");
    insertarFinal(Mier, e);
    
    
    e.hora=4;e.sucursal=2;strcpy(e.dia,"Jueves");
    insertarFinal(Jue, e);
    e.hora=5;e.sucursal=11;strcpy(e.dia,"Jueves");
    insertarFinal(Jue, e);

    e.hora=3;e.sucursal=12;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    e.hora=14;e.sucursal=13;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    e.hora=15;e.sucursal=9;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    e.hora=16;e.sucursal=14;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    
    //ordenar cada una de las listas
    ordena(Lun, Lun.longitud);
    ordena(Mar, Mar.longitud);
    ordena(Mier, Mier.longitud);
    ordena(Jue, Jue.longitud);
    ordena(Vie, Vie.longitud);
    
    mostrar(Lun);  
    mostrar(Mar);
    mostrar(Mier);
    mostrar(Jue);
    mostrar(Vie);
    cout<<endl<<endl;
    //por cada fusiona, el resultado va quedando guardado en la lista Lun
    fusiona(Lun, Mar);    
    mostrar(Lun);//revisamos los resultados parciales de las funciones de fusion
    fusiona(Lun, Mier);  
    mostrar(Lun);
    fusiona(Lun, Jue); 
    mostrar(Lun);
    fusiona(Lun, Vie); 
    mostrarSalida(Lun);//finalmente tenemos el resultado final en Lun
    
    return 0;
}


    /*
    e.hora=8;e.sucursal=6;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    e.hora=10;e.sucursal=14;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    e.hora=12;e.sucursal=1;strcpy(e.dia,"Lunes");
    insertarFinal(Lun, e);
    
    e.hora=7;e.sucursal=3;strcpy(e.dia,"Martes");
    insertarFinal(Mar, e);
    e.hora=9;e.sucursal=8;strcpy(e.dia,"Martes");
    insertarFinal(Mar, e);
    
    e.hora=8;e.sucursal=2;strcpy(e.dia,"Miercoles");
    insertarFinal(Mier, e);
    e.hora=9;e.sucursal=5;strcpy(e.dia,"Miercoles");
    insertarFinal(Mier, e);
    e.hora=10;e.sucursal=10;strcpy(e.dia,"Miercoles");
    insertarFinal(Mier, e);
    
    
    e.hora=15;e.sucursal=9;strcpy(e.dia,"Jueves");
    insertarFinal(Jue, e);
    e.hora=14;e.sucursal=13;strcpy(e.dia,"Jueves");
    insertarFinal(Jue, e);
    e.hora=16;e.sucursal=11;strcpy(e.dia,"Jueves");
    insertarFinal(Jue, e);
    
    e.hora=18;e.sucursal=12;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    e.hora=17;e.sucursal=4;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    e.hora=19;e.sucursal=7;strcpy(e.dia,"Viernes");
    insertarFinal(Vie, e);
    */