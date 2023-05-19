/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 18 de mayo de 2023, 06:01 PM
 */

#include <cstdlib>

#include "listaSimple.h"

using namespace std;

void cargaListas(Lista &L1,Lista &L2,Lista &L3,Lista &L4,Lista &L5){
    insertarFinal(L1, 8, "Lunes");
    insertarFinal(L1, 10, "Lunes");
    insertarFinal(L1, 20, "Lunes");
    insertarFinal(L2, 5, "Martes");
    insertarFinal(L2, 6, "Martes");
    insertarFinal(L3, 4, "Miercoles");
    insertarFinal(L3, 9, "Miercoles");
    insertarFinal(L3, 10, "Miercoles");
    insertarFinal(L4, 14, "Jueves");
    insertarFinal(L4, 15, "Jueves");
    insertarFinal(L4, 16, "Jueves");
    insertarFinal(L5, 17, "Viernes");
    insertarFinal(L5, 18, "Viernes");
    insertarFinal(L5, 19, "Viernes");
}

void fusiona(Lista &L1, Lista &L2){
    if(L1.cola->elem<=L2.cabeza->elem){
        L1.cola->sig=L2.cabeza;
        L1.cola=L2.cola;
    }
    else if(L1.cabeza->elem>L2.cola->elem){
        L2.cola->sig=L1.cabeza;
        L1.cabeza=L2.cabeza;
    }
    else{
        Nodo *p=L1.cabeza, *q=L2.cabeza, *aux, *sigP;
        while(p->sig!=NULL && q!=NULL){
            sigP=p->sig;
            if(p->elem > q->elem && p==L1.cabeza){
                aux=q->sig;
                q->sig=L1.cabeza;
                L1.cabeza=q;
                q=aux;
                sigP=p;
            }
            else if(p->elem<=q->elem && q->elem<p->sig->elem){
                aux=q->sig;
                q->sig=p->sig;
                p->sig=q;
                q=aux;
                sigP=p->sig;
            }
            p=sigP;
        }
        if(q!=NULL){
            L1.cola->sig=q;
            L1.cola=q;
        }
    }
    L1.longitud+=L2.longitud;
}

int main(int argc, char** argv) {
    Lista L1, L2, L3, L4, L5;
    construir(L1);
    construir(L2);
    construir(L3);
    construir(L4);
    construir(L5);
    
    cargaListas(L1, L2, L3, L4, L5);
    mostrar(L1);
    fusiona(L1, L2);
    mostrar(L1);
    fusiona(L1, L3);
    mostrar(L1);
    fusiona(L1, L4);
    mostrar(L1);
    fusiona(L1, L5);
    mostrar(L1);
    return 0;
}

