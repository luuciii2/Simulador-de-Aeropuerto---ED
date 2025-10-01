#ifndef ARBOL_H
#define ARBOL_H
#include <string>

#include "NodoArbol.h"


class Arbol
{
    friend class Aeropuerto;
    public:
        Arbol();
        virtual ~Arbol();

        NodoArbol* Getraiz() { return raiz; }
        void Setraiz(NodoArbol* val) { raiz = val; }

        void pasajeroEnArbol (Pasajero pas, pnodoArbol arbol, bool &estaEnArbol);
        void insertar (Pasajero pas, pnodoArbol arbol);
        void mostrarDatos(pnodoArbol arbol); //inorden para mostrarlos por orden alfabetico!!
        void mostrarPaises(pnodoArbol arbol);
        bool mostrarPasajeros (string p, pnodoArbol arbol); //dado un pais, mostrar los pasajeros que han ido a él
        void paisConMasYMenosPas(pnodoArbol arbol, std::string& paisMas, int& masPas,std::string& paisMenos, int& menosPas);
        float tiempoMedioNodo(pnodoArbol arbol, string p);
        float tiempoMedioTodos(); //calcula el tiempo medio de todos los pasajeros
    protected:

    private:
        NodoArbol* raiz;
        void tiempoPreorden (pnodoArbol arbol, float &sumaTiempos, int &sumaPas); //funcion utilizada para calcular el tiempo medio de todos los pasajeros, recorriendo el arbol en preorden

};

#endif // ARBOL_H
