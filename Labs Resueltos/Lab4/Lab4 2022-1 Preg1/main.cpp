/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 1 de junio de 2023, 01:25 PM
 */

#include <cstdlib>

#include "abb.h"
#include "listaSimple.h"

using namespace std;

ABB busca(ABB parbol,Elemento valor){
    if(parbol==NULL) return parbol;
    else{
        if((parbol->elem.camp1 == valor.camp1) && (parbol->elem.camp2 == valor.camp2)) return parbol;
        else{
            if(parbol->elem.camp1 < valor.camp1 || (parbol->elem.camp1==valor.camp1 && parbol->elem.camp2 < valor.camp2)) parbol=parbol->hder;
            else
                parbol=parbol->hizq;
            return busca(parbol,valor);
        }
    }
}

void verificarInsertar(ABB A1, Elemento e){
    if(buscar(A1, e)){
        cout<<"Cannot insert duplicate key"<<endl;
    }
    else
        cout<<"Ok"<<endl;
}

bool verificarModificacion(ABB A1, Elemento PK, Elemento PK_new){
    ABB q = busca(A1, PK_new), p = busca(A1, PK);
    if(p==NULL){
        cout<<"El elemento con PK ("<<PK.camp1<<" "<<PK.camp2<<") no se encuentra en la tabla, no se puede modificar"<<endl;
        return false;
    }
    else{
        if(q==NULL){
            cout<<"Ok"<<endl;
            return true;
        }
        else{
            cout<<"Violation of Primary Key constraint on update"<<endl;
            return false;
        }     
    }
}

void actualizaDatos(ABB &A1, Elemento e, Elemento e_new){
    if(verificarModificacion(A1, e, e_new)){
        ABB p = busca(A1, e);
        p->elem = e_new;
    }
}

void verificaCambio(ABB &A1, Lista &L, int &flag, int primerUniv){//flag indica si se viola la PK
    if(A1==NULL) return;
    verificaCambio(A1->hizq, L, flag, 0);
    if(!flag){
        if(primerUniv==1) cout<<"Violation of Primary Key constraint"<<endl;
        return;
    }
    verificaCambio(A1->hder, L, flag, 0);
    if(!flag){//si ya se violo la PK, retorna inmediatamente
        if(primerUniv==1) cout<<"Violation of Primary Key constraint"<<endl;
        return;
    }
    Nodo *p=L.cabeza;
    while(p!=NULL){
        if(p->elem.camp3 == A1->elem.camp3 && p->elem.camp2==A1->elem.camp2){
            flag = 0;//se viola la PK
            return;
        }
        p=p->sig;
    }
    insertarFinal(L, A1->elem);
    if(primerUniv==1){
        cout<<"Ok."<<endl;
    }
}

int main(int argc, char** argv) {
    ABB A1;
    construir(A1);
    Elemento e;
    /*
    e.camp1=10; e.camp2=8; e.camp3=5;
    insertar(A1, e);
    e.camp1=8; e.camp2=20; e.camp3=6;
    insertar(A1, e);
    e.camp1=5; e.camp2=10; e.camp3=3;
    insertar(A1, e);
    e.camp1=10; e.camp2=1; e.camp3=7;
    insertar(A1, e);
    e.camp1=15; e.camp2=10; e.camp3=3;
    insertar(A1, e);
    e.camp1=16; e.camp2=8; e.camp3=7;
    insertar(A1, e);
    */
    e.camp1=10; e.camp2=8; e.camp3=5;
    insertar(A1, e);
    e.camp1=8; e.camp2=20; e.camp3=6;
    insertar(A1, e);
    e.camp1=5; e.camp2=10; e.camp3=3;
    insertar(A1, e);
    e.camp1=10; e.camp2=1; e.camp3=7;
    insertar(A1, e);
    e.camp1=15; e.camp2=11; e.camp3=3;
    insertar(A1, e);
    e.camp1=16; e.camp2=8; e.camp3=7;
    insertar(A1, e);
    mostrarEnOrden(A1);
    cout<<endl;
    mostrarEnPreOrden(A1);
    cout<<endl;
    
    verificarInsertar(A1, e);
    Elemento PK, PK_new;
    PK.camp1 = 16; PK.camp2 = 8;
    PK_new.camp1 = 15; PK_new.camp2 = 10;
    verificarModificacion(A1, PK, PK_new); 
    //actualizaDatos(A1, PK, PK_new);
    cout<<endl;
    Lista LAux;
    construir(LAux);
    int flag=1;
    verificaCambio(A1, LAux, flag, 1);
    
    return 0;
}

