/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 10 de junio de 2023, 12:49 PM
 */

#include <cstdlib>
#include "abb.h"
#include "cola.h"
using namespace std;

void generaArbol(ABB &A1){
    Elemento e;
    e.codigo=10; e.calidad=1; insertar(A1, e);
    e.codigo=5; e.calidad=2; insertar(A1, e);
    e.codigo=20; e.calidad=2; insertar(A1, e);
    e.codigo=2; e.calidad=3; insertar(A1, e);
    e.codigo=6; e.calidad=3; insertar(A1, e);
    e.codigo=21; e.calidad=3; insertar(A1, e);
}

void imprime_amplitud(ABB parbol){
    ABB paux=parbol;
    Cola C;
    construir(C);
    encolar(C, paux);
    while(!esColaVacia(C)){
        paux = desencolar(C);
        cout<<paux->elem.codigo<<" "<<paux->elem.calidad<<"  ";
        if(paux->hizq) encolar(C, paux->hizq);
        if(paux->hder) encolar(C, paux->hder);
    }
}

int validaCalidad(ABB A1, int calidadInsert, int nivel){
    if(A1==NULL) return 0;
    if(nivel==calidadInsert-1){
        return (A1->hizq==NULL || A1->hder==NULL);
    }
    else{
        return validaCalidad(A1->hizq, calidadInsert, nivel+1) || validaCalidad(A1->hder, calidadInsert, nivel+1);
    }
}

int validaModif(ABB A1, int codActualizar, int codNuevo){
    ABB prec=A1, pAnt=NULL;
    int valido=0;
    while(prec){
        if(prec->elem.codigo == codActualizar){
            if(pAnt){//hay que verificar el padre
                if(codActualizar < pAnt->elem.codigo)
                    valido = codNuevo<pAnt->elem.codigo;
                else
                    valido = codNuevo>pAnt->elem.codigo;
            }
            else valido=1;
            if(prec->hizq) valido = valido && prec->hizq->elem.codigo<codNuevo;
            if(prec->hder) valido = valido && prec->hder->elem.codigo>codNuevo;
            break;
        }
        else{
            if(prec->elem.codigo > codActualizar)
                prec=prec->hizq;
            else
                prec=prec->hder;
        }
        pAnt=prec;
    }
    return valido;
}

int busca_amplitud(ABB parbol, int nivel, int codigo){
    ABB paux=parbol;
    Cola C;
    construir(C);
    encolar(C, paux);
    int nivelcont=0, antCalidad=0;
    while(!esColaVacia(C)){
        paux = desencolar(C);
        if(paux->elem.calidad!=antCalidad){
            nivelcont++;
            antCalidad=paux->elem.calidad;
        }
        if(nivelcont==nivel){
            if(codigo==paux->elem.codigo) return 1;
        }
        if(nivelcont<nivel){
            if(paux->hizq) encolar(C, paux->hizq);
            if(paux->hder) encolar(C, paux->hder);
        }
    }
    return 0;
}


int main(int argc, char** argv) {
    ABB A1;
    construir(A1);
    generaArbol(A1);
    
    imprime_amplitud(A1);
    cout<<endl;
    cout<<validaCalidad(A1, 2, 1)<<endl;
    cout<<validaModif(A1, 5, 7)<<endl;
    
    cout<<busca_amplitud(A1, 2, 6);
    return 0;
}

