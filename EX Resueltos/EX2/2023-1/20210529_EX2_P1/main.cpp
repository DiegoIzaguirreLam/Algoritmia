//Diego Izaguirre Lam. Codigo 20210529
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on 15 de julio de 2023, 09:42 AM
 */

#include <cstdlib>
#include <valarray>

#include "abb.h"

using namespace std;
//basado en buscam() que busca el menorm colocado en paideia
ABB buscaMayor(ABB parbol){
    if (parbol==NULL) return parbol;
    else{
        if(parbol->hder==NULL)
            return parbol;
        else
            return buscaMayor(parbol->hder);
    }
}

ABB inserta_nodo(ABB &A1, int dato){
    if(A1){
        if(dato<A1->elem){//insertamos donde corresponda
            A1->hizq = inserta_nodo(A1->hizq, dato);
        }
        else if(dato>A1->elem){
            A1->hder = inserta_nodo(A1->hder, dato);
        }
        else{//si se repite el valor, realizamos la insercion del dato segun lo mencionado en el enunciado
            ABB aux;
            aux = buscaMayor(A1);
            A1->hder = inserta_nodo(A1->hder, dato + aux->elem);
        }
    }
    else{//arbol vacio, se crea el primer nodo
        A1 = crearNodo(dato);
    }
    return A1;
}

int altura(ABB parbol){//halla la altura para el balanceo
    if(parbol) return max(altura(parbol->hizq), altura(parbol->hder))+1;
    return 0;
}

void rotacion_derecha(ABB &abb){//realiza una rotacion a la derecha del abb
    ABB t=abb;
    abb = abb->hizq;
    t->hizq = abb->hder;
    abb->hder = t;
}

void rotacion_izquierda(ABB &abb){//realiza una rotacion a la izquierda del abb
    ABB t=abb;
    abb = abb->hder;
    t->hder = abb->hizq;
    abb->hizq = t;
}


ABB balancea_arbol(ABB &abb){//funcion recursiva para balancear el arbol
    if(abb){
        abb->hizq = balancea_arbol(abb->hizq);//se balancean en postorden los subarboles
        abb->hder = balancea_arbol(abb->hder);
        int altIzq=altura(abb->hizq), altDer=altura(abb->hder), dif;
        dif = abs(altIzq-altDer);
        if(dif>1){
            if(altIzq>altDer){
                if(altura(abb->hizq->hizq)>=altura(abb->hizq->hder)){
                    rotacion_derecha(abb);
                }
                else{
                    rotacion_izquierda(abb->hizq);
                    rotacion_derecha(abb);
                }
            }
            else{
                if(altura(abb->hder->hder)>=altura(abb->hder->hizq)){
                    rotacion_izquierda(abb);
                }
                else{
                    rotacion_derecha(abb->hder);
                    rotacion_izquierda(abb);
                }
            }
        }
    }
    return abb;
}

void generaArbolVerif(ABB &A2){//generamos el arbol por el sistema
    construir(A2);
    //Datos de prueba
    /*int datos[]={3,1,5,2,4,6,7};
    int n=7;*/
    int datos[]={4,1,6,2,5,7,3};
    int n=7;
    for(int i=0;i<n;i++){
        inserta_nodo(A2, datos[i]);
    }
}

void generaASuma(ABB A1, ABB A2,ABB &ASuma){//funcion para generar el arbol abb de la suma
    if(A1 && A2){
        ASuma = crearNodo(A1->elem + A2->elem);
        generaASuma(A1->hizq, A2->hizq, ASuma->hizq);
        generaASuma(A1->hder, A2->hder, ASuma->hder);
    }
    else if(A1){
        ASuma = crearNodo(A1->elem);
        generaASuma(A1->hizq, A2, ASuma->hizq);
        generaASuma(A1->hder, A2, ASuma->hder);
    }
    else if(A2){
        ASuma = crearNodo(A2->elem);
        generaASuma(A1, A2->hizq, ASuma->hizq);
        generaASuma(A1, A2->hder, ASuma->hder);
    }
    else{
        return;
    }
}

int verificaABB(ABB ASuma){//verifica si el arbol sumado es abb
    if(ASuma){
        if((ASuma->hizq && ASuma->elem <= ASuma->hizq->elem) || (ASuma->hder && ASuma->elem >=ASuma->hder->elem)){//verificamos si se incumple la propiedad de ABB
            return 0;
        }
        else{
            return verificaABB(ASuma->hizq) && verificaABB(ASuma->hder);//se comprueba recursivamente para los hizq y hder de cada nodo
        }
    }
    else{
        return 1;//llego al fin del arbol y es abb
    }
}


int suma_arboles(ABB A1, ABB A2){//usamos un arbol para generar la suma
    ABB ASuma;
    construir(ASuma);
    generaASuma(A1, A2, ASuma);//generamos el arbol suma
    cout<<"Arbol suma generado (preorden): ";
    mostrarEnPreOrden(ASuma);
    cout<<endl;
    return verificaABB(ASuma);//funcion recursiva que verifica si cumple con la propiedad de abb
}

int main(int argc, char** argv) {//funcion principal
    int n=8;
    int arr[]={2,5,2,1,5,6,3,4};
    ABB A1;
    construir(A1);
    for(int i=0;i<n;i++){
        A1=inserta_nodo(A1, arr[i]);
    }
    //mostrarEnOrden(A1);cout<<endl;
    cout<<"Arbol construido (preorden): ";
    mostrarEnPreOrden(A1);
    cout<<endl;
    A1 = balancea_arbol(A1);
    cout<<"Arbol balanceado (preorden): ";
    mostrarEnPreOrden(A1);
    cout<<endl;
    ABB A2;//generado por sistema
    generaArbolVerif(A2);
    cout<<"Arbol generado por el sistema para la verificacion: ";
    mostrarEnPreOrden(A2);
    cout<<endl;
    if(suma_arboles(A1, A2)){
        cout<<"Acceso otorgado"<<endl;
    }
    else
        cout<<"Acceso denegado"<<endl;
    
    return 0;
}

