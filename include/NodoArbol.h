#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <string>
#include "ListaPasajeros.h"

class NodoArbol
{
    friend class Arbol;
    public:
        NodoArbol(string p);
        virtual ~NodoArbol();

        ListaPasajeros Getpasajeros() { return pasajeros; }
        string GetpaisArbol() {return pais;}
        void Setpais(string val) {pais = val;}
        NodoArbol* Getderecha() { return derecha; }
        void Setderecha(NodoArbol* val) { derecha = val; }
        NodoArbol* Getizquierda() { return izquierda; }
        void Setizquierda(NodoArbol* val) { izquierda = val; }


    protected:

    private:
        string pais;
        ListaPasajeros pasajeros;
        NodoArbol* derecha;
        NodoArbol* izquierda;
};typedef NodoArbol* pnodoArbol;

#endif // NODOARBOL_H
