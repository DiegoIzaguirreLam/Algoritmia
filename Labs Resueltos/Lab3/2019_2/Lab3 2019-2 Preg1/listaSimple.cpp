#include "listaSimple.h"

void construir( Lista &pL )
{
    // se crea la lista vacia
    pL.cabeza = NULL;
    pL.longitud = 0;
}

bool esListaVacia( Lista L )
{
    return L.cabeza == NULL;
    // return L.longitud == 0;
}

NodoL* crearNodoL( Elemento e, NodoL *s )
{
    NodoL *p;
    p = new NodoL; // se crea un nodo y su direccion se almacena en p
    p->elem = e;
    p->sig = s;
    return p;
}

int obtenerLongitud( Lista L )
{
    return L.longitud;
}
/*
void insertarComienzo( Lista &pL, Elemento e )
{
    Nodo *p;
    p = crearNodo( e, pL.cabeza );
    pL.cabeza = p;
    pL.longitud++;
}
*/
void mostrar( Lista L )
{
    NodoL *p;
    if ( esListaVacia(L) )
        cout << "La lista esta vacia" << endl;
    else
    {
        p = L.cabeza;
        while ( p!= NULL )
        {
            cout << p->elem.numPed << "     " << p->elem.estado<<endl;
            p = p->sig;
        }
        cout << endl;
    }
}

NodoL* ubicarUltimo( Lista L )
{
    NodoL *pU;
    int i;
    if ( esListaVacia(L) )
        return NULL;
    else
    {
        pU = L.cabeza;
        for(i=1; i<=L.longitud-1; i++ )
            pU = pU->sig;
        return pU;
    }
}
/*
void insertarFinal( Lista &pL, Elemento e )
{
    Nodo *p, *pU;
    p = crearNodo( e, NULL);
    if ( esListaVacia(pL) )
        pL.cabeza = p;
    else
    {
        pU = ubicarUltimo( pL );
        pU->sig = p;
    }
    pL.longitud++;
}
*/
NodoL* ubicarElemento( Lista L, Elemento e)
{
    NodoL *p;
    if ( esListaVacia(L) )
        return NULL;
    else
    {
        p = L.cabeza;
        while ( p != NULL )
        {
            if ( p->elem.numPed == e.numPed && p->elem.estado==e.estado )
                return p;
            p = p->sig;    
        }
        return NULL;
    }
}

NodoL* ubicarAnterior( Lista L, Elemento e)
{
    NodoL *p, *pA;
    pA = NULL;
    p = L.cabeza;
    while ( p!=NULL )
    {
        if ( p->elem.numPed == e.numPed && p->elem.estado==e.estado )
            return pA;
        pA = p;
        p = p->sig;
    }
}

void eliminar( Lista *pL, Elemento e )
{
    NodoL *p, *pA;
    p = ubicarElemento( *pL, e);
    if ( p == NULL )
        cout << "No es posible eliminar un dato inexistente" << endl;
    else
    {
        pA = ubicarAnterior( *pL, e);
        if ( pA == NULL )
            pL->cabeza = p->sig;
        else
            pA->sig = p->sig;
        pL->longitud--;
        delete p;
    }
}
/*
void destruir( Lista *pL )
{
    Nodo *p, *pAux;
    if ( ! esListaVacia( *pL) )
    {
        p = pL->cabeza;
        while ( p != NULL )
        {
            pAux = p->sig;
            delete p;
            p = pAux;
        }
        pL->cabeza = NULL;
        pL->longitud = 0;
    }
}
 * */