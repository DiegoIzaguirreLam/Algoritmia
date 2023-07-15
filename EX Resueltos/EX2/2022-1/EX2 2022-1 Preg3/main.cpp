
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 27 de junio de 2023, 02:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "abb.h"

using namespace std;

void leeLetra(ifstream &archPalabra, ABB &parbol, int nLetras, int i){
    if(i<nLetras){
        Elemento e;
        archPalabra>>e.pos>>e.letra;
        insertar(parbol, e);
        leeLetra(archPalabra, parbol, nLetras, i+1);
    }
}

void leePalabra(ABB &parbol, int &nLetras){
    ifstream archPalabra;
    archPalabra.open("Palabra.txt", ios::in);
    if(archPalabra){
        archPalabra>>nLetras;
        leeLetra(archPalabra, parbol, nLetras, 0);
    }
    else{
        exit(1);
    }
    archPalabra.close();
}

int buscaLetra(char intento[],ABB A1, int i){
    if(A1){
        if(A1->elem.letra == intento[i-1]){
            if(A1->elem.pos == i){
                cout<<intento[i-1]<<" ";
                return 1;
            }
            else{
                cout<<intento[i-1]<<"(x) ";
                return 2;
            }
        }
        return buscaLetra(intento, A1->hizq, i) || buscaLetra(intento, A1->hder, i);
    }
    else
        return 0;
}

int coincide(char intento[], ABB A1,int n, int i){
    if(i==n){
        return 1;
    }
    else{
        int flag = buscaLetra(intento, A1, i+1);
        if(flag==1)
            return coincide(intento, A1, n, i+1);
        else{
            if (flag==0) cout<<"_ ";
            return coincide(intento, A1, n, i+1) && 0;
        }
    }
}

void leeIntento(char intento[], int &nLetrasIntento){
    char temp;
    temp = getchar();
    if(temp=='\n') return;
    else{
        intento[nLetrasIntento++]=temp;
        leeIntento(intento, nLetrasIntento);
    }
}

int procesaIntento(ABB A1, char intento[], int nLetras, int iIntento, int nIntentos){
    if(iIntento>nIntentos){
        return 0;
    }
    int nLetrasIntento=0;
    cout<<"Intento "<<iIntento<<": ";
    leeIntento(intento, nLetrasIntento);
    if(nLetrasIntento!=nLetras){
        cout<<"La longitud de la palabra ingresada no es la correcta. Vuelva a intentarlo."<<endl;
        return procesaIntento(A1, intento, nLetras, iIntento, nIntentos);
    }
    else if(coincide(intento, A1, nLetras, 0)){
        return 1;
    }
    else{
        cout<<endl;
        return procesaIntento(A1, intento, nLetras, iIntento+1, nIntentos);
    }
}

void imprimeEspacios(int nLetras, int i){
    if(i<nLetras){
        cout<<"_ ";
        imprimeEspacios(nLetras, i+1);
    }
}

void procesaJuego(ABB A1,char intento[],int nLetras){
    int nIntentos=5;
    cout<<"BIENVENIDO AL JUEGO DE BALWORD"<<endl;
    cout<<"Descubre la palabra de "<<nLetras<<" letras. Tiene como máximo "<<nIntentos<<" intentos."<<endl;
    //cout<<"_ _ _ _ _"<<endl;
    imprimeEspacios(nLetras, 0);
    cout<<endl;
    int i=1;
    if(procesaIntento(A1, intento, nLetras, i, nIntentos)){
        cout<<endl<<"Felicitaciones por haber resuelto el reto."<<endl;
    }
    else
        cout<<endl<<"Lo siento, se agotaron los intentos"<<endl;
}

int main(int argc, char** argv) {
    ABB A1;
    int nLetras;
    construir(A1);
    leePalabra(A1, nLetras);
    mostrarEnOrden(A1);
    cout<<endl;
    char intento[5]={'H','E','L','I','O'};
    procesaJuego(A1, intento, nLetras);
    return 0;
}

