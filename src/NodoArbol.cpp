#include "NodoArbol.h"
#include "ListaPasajeros.h"
#include<iostream>

NodoArbol::NodoArbol(string p)
{
    pais = p;
    pasajeros = ListaPasajeros();
    derecha = NULL;
    izquierda = NULL;
}

NodoArbol::~NodoArbol()
{
    //dtor
}

