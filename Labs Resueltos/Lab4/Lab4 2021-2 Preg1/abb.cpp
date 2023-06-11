#include "abb.h"

void construir( ABB &pA )
{
    pA = NULL;  // todo arbol empieza vacio
}

NodoABB* crearNodo( Elemento e )
{
    // todo nodo que sea crea es siempre una hoja
    NodoABB *p;
    p = new NodoABB;  // se crea el nodo en memoria
    p->hizq = NULL;
    p->elem = e;
    p->hder = NULL;
    return p; // se retorna la direccion del nodo creado
}

void insertar( ABB &pA, Elemento e )
{
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
            if ( e.codigo < q->elem.codigo )
                q = q->hizq;
            else
                q = q->hder;
        }
        if ( e.codigo < pq->elem.codigo )
            pq->hizq = p;
        else
            pq->hder = p;
    }
}

// devuelve la dirección del nodo raiz del árbol
NodoABB* obtenerRaiz( ABB A )
{
    return A;
}

// muestra el contenido del árbol en orden
void mostrarEnOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnOrden( pAI);  // se recorre en orden el subarbol izquierdo
        cout << pR->elem.codigo << " " << pR->elem.calidad<<"  ";  // se visita la raiz
        mostrarEnOrden( pAD);  // se recorre en orden el subarbol derecho
    }
}

// muestra el contenido del árbol en preorden
void mostrarEnPreOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        cout << pR->elem.codigo << " " << pR->elem.calidad<<"  ";  // se visita la raiz
        mostrarEnPreOrden( pAI);  // se recorre en preorden el subarbol izquierdo
        mostrarEnPreOrden( pAD);  // se recorre en preorden el subarbol derecho
    }
}

// muestra el contenido del árbol en postorden
void mostrarEnPostOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnPostOrden( pAI);  // se recorre en postorden el subarbol izquierdo
        mostrarEnPostOrden( pAD);  // se recorre en postorden el subarbol derecho
        cout << pR->elem.codigo << " " << pR->elem.calidad<<"  ";  // se visita la raiz
    }
}

// retorna true si el elemento e se encuentra en el árbol
// retorne false en caso contrario
bool buscar( NodoABB *pR, Elemento e )
{
    NodoABB *p;
    p = pR;
    while ( p != NULL )
    {
        if ( e.codigo == p->elem.codigo )  // si lo encuentra retorna true
            return true;
        else
            if ( e.codigo < p->elem.codigo )
                p = p->hizq;   // continua la búsqueda en el subárbol izquierdo
            else
                p = p->hder;   // continua la búsqueda en el subárbol derecho
    }
    return false;  // si no lo encuentra retorna false
}

// retorna el valor del elemento menor del árbol
// el menor siempre se encuentra en el extremo izquierdo del árbol
Elemento menor( NodoABB *pR )
{
    NodoABB *p;
    p = pR;
    while ( p->hizq != NULL )
        p = p->hizq;
    return p->elem;
}

// retorna el valor del elemento mayor del árbol
// el mayor siempre se encuentra en el extremo derecho del árbol
Elemento mayor( NodoABB *pR )
{
    NodoABB *p;
    p = pR;
    while ( p->hder != NULL )
        p = p->hder;
    return p->elem;
}

// devuleve la cantidad de nodos que contiene el árbol
int contarNodos( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int nodosAI, nodosAD;
    if ( pR == NULL )  // caso base: arbol vacio: no tiene nodos
        return 0;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        nodosAI = contarNodos( pAI); // cuenta los nodos del subárbol izquierdo
        nodosAD = contarNodos( pAD); // cuenta los nodos del subárbol derecho
        return nodosAI + nodosAD + 1;  // le suma 1 ( el nodo raiz )
    }
}
/*
// retorna la suma de los datos contenidos en el árbol
int sumarNodos( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int sumaAI, sumaAD;
    if ( pR == NULL )  // caso base: arbol vacio
        return 0;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        sumaAI = sumarNodos( pAI); // suma los datos del subárbol izquierdo
        sumaAD = sumarNodos( pAD); // suma los datos del subárbol derecho
        return sumaAI + sumaAD + pR->elem;  // le suma el dato contenido en la raiz
    }
}

*/
int es_arbol_vacio(ABB tad){
    return tad==NULL;
}