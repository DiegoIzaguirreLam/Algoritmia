/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 9 de mayo de 2023, 09:31 AM
 */

#include <cstdlib>
#include <iostream>

#include "listaSimple.h"
#include "pila.h"
#include "cola.h"
#define MAXCOL 7
using namespace std;

//flag indica si el elemento en la posicion 0 es 0 o 1, de modo que asi podemos saber si tenemos que buscar los 0's hacia el inicio o hacia el final
int cuentaMalos(int band[], int ini, int fin, int cont, int flag){
    if(ini>fin){
        return cont;
    }
    if(ini==fin)
        return cont+!band[ini];
    int med=(ini+fin)/2;
    
    if(!flag){//en este caso, los malos estan en la primera mitad
        if(band[med]==0){
            return cuentaMalos(band, med+1, fin, cont+med-ini+1, flag);
        }
        else
            return cuentaMalos(band, ini, med-1, cont, flag);
    }
    else{
        if(band[med]==0){
            return cuentaMalos(band, ini, med-1, cont+fin-med+1, flag);
        }
        else
            return cuentaMalos(band, med+1, fin, cont, flag);
    }
}

void insertarFaja(Lista &faja, int band[][MAXCOL], int M){
    for(int i=0;i<M;i++){
        if(band[0][i]==1){
            insertarFinal(faja, band[1][i]);
        }
    }
}

void vaciaFaja(Lista &fajaCont){
    fajaCont.cabeza = NULL;
    fajaCont.ultimo = NULL;
    fajaCont.longitud = 0;
}

void concatenaLista(Lista &faja1, Lista &fajaCont){
    if(!esListaVacia(fajaCont)){
        faja1.ultimo->sig=fajaCont.cabeza;
        faja1.ultimo=fajaCont.ultimo;
        vaciaFaja(fajaCont);
    }
}

Nodo* sacaElemento( Lista &L, Elemento e)
{
    Nodo *p, *pRet=NULL, *pAnt;
    if ( esListaVacia(L) )
        return NULL;
    else
    {
        p = L.cabeza;
        while ( p != NULL )
        {
            if ( p->elem == e ){
                pRet=p;
                break;
            }
            p = p->sig;    
        }
        if(pRet!=NULL){
            pAnt=ubicarAnterior(L, e);
            if(pAnt==NULL){
                L.cabeza=pRet->sig;
            }
            else{
                pAnt->sig=pRet->sig;
            }
            L.longitud--;
        }
        return pRet;
    }
}

void generaCombos(Cola &cEmpaq, Pila &pAmer, Pila &pPep, Pila &pHaw, Lista &faja1){
    Nodo *temp1, *temp2, *temp3;
    while(!esListaVacia(faja1)){
        temp1=sacaElemento(faja1, 1);
        temp2=sacaElemento(faja1, 2);
        temp3=sacaElemento(faja1, 3);
        if(temp1!=NULL && temp2!=NULL && temp3!=NULL){
            encolar(&cEmpaq, temp1->elem);
            encolar(&cEmpaq, temp2->elem);
            encolar(&cEmpaq, temp3->elem);
        }
        else{//se usan los depositos
            if(temp1!=NULL)
                apilar(&pAmer, temp1->elem);
            if(temp2!=NULL)
                apilar(&pPep, temp2->elem);
            if(temp3!=NULL)
                apilar(&pHaw, temp3->elem);
        }
        delete temp1;
        delete temp2;
        delete temp3;
    }
}

int main(int argc, char** argv) {
    //ingresando los datos en una matriz, donde la primera fila indica si es esta quemada o no y la segunda fila indica la seccion de cada pizza.
    int M=7;
    int band1[][MAXCOL]={{1,1,1,0,0,0,0},
                         {2,1,3,2,3,1,1}};
    int band2[][MAXCOL]={{1,1,1,1,1,1,0},
                         {1,2,3,3,3,2,1}};
    int band3[][MAXCOL]={{1,1,1,1,1,0,0},
                         {1,2,1,1,3,1,2}};
    int band4[][MAXCOL]={{0,0,1,1,1,1,1},
                         {3,1,3,2,3,3,1}};
    
    int cont=0;
    cout<<M-cuentaMalos(band1[0], 0, M-1, cont, band1[0][0])<<endl;
    cont=0;
    cout<<M-cuentaMalos(band2[0], 0, M-1, cont, band2[0][0])<<endl;
    cont=0;
    cout<<M-cuentaMalos(band3[0], 0, M-1, cont, band3[0][0])<<endl;
    cont=0;
    cout<<M-cuentaMalos(band4[0], 0, M-1, cont, band4[0][0])<<endl;
    //en este caso es mas conveniente buscar los malos, puesto que estos siempre estaran a un solo lado de la bandeja, y restamos estos al total de elementos
    
    Lista faja1, faja2, faja3, faja4;
    construir(faja1);
    construir(faja2);
    construir(faja3);
    construir(faja4);
    
    insertarFaja(faja1, band1, M);
    insertarFaja(faja2, band2, M);
    insertarFaja(faja3, band3, M);
    insertarFaja(faja4, band4, M);
    cout<<endl;
    mostrar(faja1);
    mostrar(faja2);
    mostrar(faja3);
    mostrar(faja4);
    
    cout<<endl;
    cout<<endl;
    concatenaLista(faja1, faja2);
    mostrar(faja1);
    concatenaLista(faja1, faja3);
    mostrar(faja1);
    concatenaLista(faja1, faja4);
    mostrar(faja1);
    cout<<endl;
    mostrar(faja1);
    mostrar(faja2);
    mostrar(faja3);
    mostrar(faja4);
    
    Pila pAmer, pPep, pHaw;
    construir(&pAmer);
    construir(&pPep);
    construir(&pHaw);
    
    Cola cEmpaq;
    construir(&cEmpaq);
    
    generaCombos(cEmpaq, pAmer, pPep, pHaw, faja1);
    mostrar(cEmpaq);
    cout<<"Apilamiento provisional:"<<endl;
    cout<<"Pizzas Americana: "<<endl;
    mostrar(pAmer);
    cout<<"Pizzas Pepperoni: "<<endl;
    mostrar(pPep);
    cout<<"Pizzas Hawaiana: "<<endl;
    mostrar(pHaw);
    mostrar(faja1);
    
    return 0;
}

