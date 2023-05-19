#ifndef PILA_H
#define PILA_H

# include <iostream>
#include "cola.h"
using namespace std;


typedef struct nodoP
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodoP *sig;  // sig es la dirección del siguiente nodo
} NodoP;

typedef struct
{
    NodoP *cima; // cima almacena la direccion del primer nodo de la pila
    int longitud; // cantidad de nodos de la pila
} Pila;

void construir( Pila &pP );
bool esPilaVacia( Pila P );
NodoP* crearNodo( Elemento e, NodoP *s );
void apilar( Pila &pP, Elemento e );
void mostrar( Pila P );
Elemento desapilar( Pila &pP );
void destruir( Pila *pP );
int top(Pila );
#endif /* PILA_H */

