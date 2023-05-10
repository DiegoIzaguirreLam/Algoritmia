/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cola.h
 * Author: Diego
 *
 * Created on 8 de mayo de 2023, 10:43 AM
 */

#ifndef COLA_H
#define COLA_H

typedef int Elemento;

typedef struct nodoC
{
    Elemento elem;
    struct nodoC *sig;
} NodoC;

typedef struct
{
    NodoC* frente;
    NodoC* final;
    int longitud;
} Cola;

void construir( Cola *pC );
bool esColaVacia( Cola C );
int obtenerLongitud( Cola C );
NodoC* crearNodo( Elemento e, NodoC *s );
void mostrar( Cola C );
void encolar( Cola *pC, Elemento e );
Elemento desencolar( Cola *pC );
void destruir( Cola *pC );

#endif /* COLA_H */

