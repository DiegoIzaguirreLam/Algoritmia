/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AB.h
 * Author: Diego
 *
 * Created on 13 de julio de 2023, 11:38 PM
 */

#ifndef AB_H
#define AB_H

typedef struct{
    int cromo;
    int peso;
} Elemento;

typedef struct nodoab{
    Elemento e;
    struct nodoab* hizq;
    struct nodoab* hder;
} NodoAB;

typedef NodoAB* AB;

void construir(AB &pA);
NodoAB* crearNodo(Elemento elem);
void creaPivot(AB &pA, Elemento e);
void insertaHizq(AB &pA, Elemento e);
void insertaHder(AB &pA, Elemento e);
void mostrarEnOrden( NodoAB *pR );


#endif /* AB_H */

