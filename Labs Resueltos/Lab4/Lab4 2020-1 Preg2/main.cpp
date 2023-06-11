/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 9 de junio de 2023, 07:01 PM
 */

#include <cstdlib>
#include "abb.h"
using namespace std;

void generaAlmacenes(ABB &alm1, ABB &alm2){
    Elemento e;
    e.lote=20180211; e.cantidad=20; insertar(alm1, e);
    e.lote=20170620; e.cantidad=20; insertar(alm1, e);
    e.lote=20170810; e.cantidad=20; insertar(alm1, e);
    e.lote=20180409; e.cantidad=10; insertar(alm1, e);
    
    e.lote=20180211; e.cantidad=10; insertar(alm2, e);
    e.lote=20170811; e.cantidad=5; insertar(alm2, e);
    e.lote=20180410; e.cantidad=15; insertar(alm2, e);
}

ABB buscaHoja(ABB alm){
    if(alm->hizq==NULL && alm->hder==NULL) return alm;
    if(alm->hizq!=NULL) return buscaHoja(alm->hizq);//primero busca mayor antiguedad (menor anio)
    else return buscaHoja(alm->hder);
}

ABB buscaAnterior(ABB parbol, ABB q){
    if(parbol == q || parbol==NULL) return NULL; //caso base, q es raiz y hoja
    if((parbol->hizq!=NULL && parbol->hizq == q) || (parbol->hder!=NULL && parbol->hder == q)) return parbol;//caso base, es padre de q
    if(parbol->elem.lote < q->elem.lote) return buscaAnterior(parbol->hder, q);
    else return buscaAnterior(parbol->hizq, q);
}

void insertarModif(ABB &pA, Elemento e){//copiamos el insertar y hacemos las modificaciones necesarias
    NodoABB *p, *q, *pq;
    p = crearNodo( e );     // se crea el nodo como hoja
    if ( pA == NULL ) // arbol vacio
        pA = p;  // el nodo insertado se convierte en la raiz del árbol
    else  // el árbol no está vacío
    {
        // hay que encontrar la ubicación que le corresponde al nuevo nodo
        q = pA;
        pq = NULL;
        while ( q != NULL )
        {
            pq = q;
            if ( e.lote < q->elem.lote )
                q = q->hizq;
            else if (e.lote > pq->elem.lote)
                q = q->hder;
            else
                break;
        }
        if ( e.lote < pq->elem.lote )
            pq->hizq = p;
        else if (e.lote > pq->elem.lote)
            pq->hder = p;
        else
            pq->elem.cantidad += e.cantidad;
    }
}

void fusionaAlmacenes(ABB &alm1, ABB &alm2){
    int nodosAlm1, nodosAlm2;
    nodosAlm1=contarNodos(alm1);
    nodosAlm2=contarNodos(alm2);
    ABB q, padreq;
    if(nodosAlm1 > nodosAlm2){//mover de 2 a 1
        while(!es_arbol_vacio(alm2)){
            q=buscaHoja(alm2);
            padreq=buscaAnterior(alm2, q);
            if(padreq==NULL){
                insertarModif(alm1, alm2->elem);
                alm2 = NULL;
                delete alm2;
                break;
            }
            else{
                if(padreq->elem.lote > q->elem.lote){
                    padreq->hizq = NULL;
                }
                else{
                    padreq->hder = NULL;
                }
                insertarModif(alm1, q->elem);
                delete q;
            }
        }
    }
    else{
        while(!es_arbol_vacio(alm1)){
            q=buscaHoja(alm1);
            padreq=buscaAnterior(alm2, q);
            if(padreq==NULL){
                insertarModif(alm2, alm1->elem);
                alm1 = NULL;
                delete alm1;
                break;
            }
            else{
                if(padreq->elem.lote > q->elem.lote){
                    padreq->hizq = NULL;
                }
                else{
                    padreq->hder = NULL;
                }
                insertarModif(alm2, q->elem);
                delete q;
            }
        }
    }
}

ABB buscaNodo(ABB alm1, int lote){
    if(alm1==NULL || alm1->elem.lote == lote) return alm1;
    if(alm1->elem.lote > lote) return buscaNodo(alm1->hizq, lote);
    else return buscaNodo(alm1->hder, lote);
}

ABB fusionar_2(ABB &alm1, ABB &alm2){//deja alm2 vacio y alm1 con la fusion
    Elemento e;
    if(alm2){
        fusionar_2(alm1, alm2->hizq);
        fusionar_2(alm1, alm2->hder);
        e=alm2->elem;
        delete alm2;
        ABB existeNodo = buscaNodo(alm1, e.lote);
        if(existeNodo){
            existeNodo->elem.cantidad += e.cantidad;
        }
        else{
            insertar(alm1, e);
        }
        alm2 = NULL;
    }
}



int main(int argc, char** argv) {
    ABB alm1, alm2;
    construir(alm1);
    construir(alm2);
    
    generaAlmacenes(alm1, alm2);
    mostrarEnOrden(alm1);
    cout<<endl;
    mostrarEnOrden(alm2);
    cout<<endl;
    //fusionaAlmacenes(alm1, alm2);
    fusionar_2(alm1, alm2);//hacer validacion de cual es mayor y luego llamar la funcion
    mostrarEnOrden(alm1);
    cout<<endl;
    mostrarEnOrden(alm2);
    cout<<endl;
    return 0;
}

