#ifndef ABB_H
#define ABB_H

#include <iostream>

using namespace std;

typedef struct{
    int codigo;
    int calidad;
} Elemento;

typedef struct nodo
{   Elemento elem;      // dato
    struct nodo *hizq;  // puntero al hijo izquierdo
    struct nodo *hder;  // puntero al hijo derecho
} NodoABB;

typedef NodoABB * ABB;

void construir( ABB &pA );
NodoABB* crearNodo( Elemento e );
void insertar( ABB &pA, Elemento e );
NodoABB* obtenerRaiz( ABB A );
int es_arbol_vacio(ABB );
void mostrarEnOrden( ABB );
void mostrarEnPreOrden( ABB );
void mostrarEnPostOrden( ABB );
bool buscar( ABB, Elemento e );
Elemento menor( NodoABB *pR );
Elemento mayor( NodoABB *pR );
int contarNodos( NodoABB *pR );
int sumarNodos( NodoABB *pR );

#endif /* ABB_H */
