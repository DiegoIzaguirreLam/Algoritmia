#include "listaSimple.h"

void construir( Lista &pL )
{
    // se crea la lista vacia
    pL.cabeza = NULL;
    //pL.cola = NULL;
    pL.longitud = 0;
}

bool esListaVacia( Lista L )
{
    return L.cabeza == NULL;
    // return L.longitud == 0;
}

NodoL* crearNodo( Elemento e, NodoL *s )
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

void insertarComienzo( Lista &pL, Elemento e )
{
    NodoL *p;
    p = crearNodo( e, pL.cabeza );
    pL.cabeza = p;
    pL.longitud++;
}

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
            cout << p->elem.semana << "-" << p->elem.cantidad <<"-"<<p->elem.idProd<<" ";
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

void insertarFinal( Lista &pL, Elemento e )
{
    NodoL *p, *pU;
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

void destruir( Lista *pL )
{
    NodoL *p, *pAux;
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