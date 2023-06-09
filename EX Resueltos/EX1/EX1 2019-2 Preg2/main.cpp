/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 24 de mayo de 2023, 05:24 PM
 */

#include <cstdlib>
#include <cmath>
#include "listaSimple.h"
#include "pila.h"

using namespace std;

void cargabin(int num,int n,int cromo[]){
	int i,res;
	for(i=0;i<n;i++)cromo[i]=0; 
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}

void cargaLista(Lista &L){
    insertarComienzo(L, 200);
    insertarComienzo(L, 300);
    insertarComienzo(L, 160);
    insertarComienzo(L, 250);
    insertarComienzo(L, 400);
    insertarComienzo(L, 340);
    insertarComienzo(L, 320);
    insertarComienzo(L, 410);
    insertarComienzo(L, 250);
    insertarComienzo(L, 290);
    insertarComienzo(L, 330);
    insertarComienzo(L, 120);
    insertarComienzo(L, 450);
    insertarComienzo(L, 420);
    insertarComienzo(L, 340);
    insertarComienzo(L, 160);
    insertarComienzo(L, 180);
    insertarComienzo(L, 215);
    insertarComienzo(L, 390);
    insertarComienzo(L, 220);
    insertarComienzo(L, 260);
}

Elemento ubicaPosicion(Lista &L, int pos){
    Nodo *p=L.cabeza;
    for(int i=0;i<pos;i++){
        p=p->sig;
    }
    return p->elem;
}

void eligeCajas(Lista L, int selecc[], int &nselecc){
    int peso=2000,n=L.longitud,parcial,mpeso=0,mcomb,maxCaj=12,contCaj;
    int cromo[n];
    int opcion=(int)pow(2,n);
    int i, j, producto;
    for(i=0;i<opcion;i++){
        cargabin(i, n, cromo);
        parcial=0;
        contCaj=0;
        for(j=0;j<n;j++){
            if(cromo[j]){
                parcial+=ubicaPosicion(L, j);
                contCaj++;
            }
        }
        if(parcial<=peso && contCaj<=maxCaj && parcial>mpeso){
            mpeso=parcial;
            mcomb=i;
        }
    }
    cargabin(mcomb, n, cromo);
    cout<<"Peso maximo: "<<mpeso<<" Cajas seleccionadas: ";
    nselecc=0;
    for(j=0;j<n;j++){
        if(cromo[j]){
            producto=ubicaPosicion(L, j);
            cout<<producto<<" ";
            selecc[nselecc]=producto;
            nselecc++;
        }
    }
    cout<<endl;
}
void insertaEnOrden(Pila &P, int peso){
    int eAux;
    if(esPilaVacia(P) || peso<=top(P)){
        apilar(P, peso);
        return;
    }
    else{
        eAux=desapilar(P);
        insertaEnOrden(P, peso);
        apilar(P, eAux);
    }
}

void cargaCamion(Pila &P, int selecc[], int nselecc){
    for(int j=0;j<nselecc;j++){
        insertaEnOrden(P,selecc[j]);
    }
}

int main(int argc, char** argv) {
    Lista L;
    construir(L);
    cargaLista(L);
    int selecc[L.longitud], nselecc;
    eligeCajas(L, selecc, nselecc);
    Pila P;
    construir(P);
    cargaCamion(P, selecc, nselecc);
    mostrar(P);
    
    return 0;
}

