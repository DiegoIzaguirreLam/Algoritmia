/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pila.h
 * Author: Diego
 *
 * Created on 8 de mayo de 2023, 12:14 PM
 */

#ifndef PILA_H
#define PILA_H

typedef int Elemento;

typedef struct nodoP
{
    Elemento elem;
    struct nodoP *sig;
} NodoP;

typedef struct
{
    NodoP* cima;
    int pesoAct;
    int longitud;
} Pila;

void construir( Pila *pP );
bool esPilaVacia( Pila P );
int obtenerLongitud( Pila P );
NodoP* crearNodo( Elemento e, NodoP *s );
void apilar( Pila *pP, Elemento e );
void mostrar( Pila P );
Elemento desapilar( Pila *pP );



#endif /* PILA_H */

