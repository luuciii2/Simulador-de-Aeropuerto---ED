#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H

#include "CeldaListaPas.h"
class ListaPasajeros
{
    public:
        ListaPasajeros();
        virtual ~ListaPasajeros();

        CeldaListaPas* Getprimero() { return primero; }
        void Setprimero(CeldaListaPas* val) { primero = val; }
        CeldaListaPas* Getultimo() { return ultimo; }
        void Setultimo(CeldaListaPas* val) { ultimo = val; }
        int Getlongitud(){return longitud;}

        bool esVacia();
        void enlistar(Pasajero pas);
        void desenlistar();
        bool estaEnLista (Pasajero pas);
        void mostrarListaPas();
        float sumaTiempos();

    protected:

    private:
        CeldaListaPas* primero;
        CeldaListaPas* ultimo;
        int longitud;
};

#endif // LISTAPASAJEROS_H
