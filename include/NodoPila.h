#ifndef NODOPILA_H
#define NODOPILA_H

#include "Pasajero.h"

class NodoPila
{
    friend class Pila;
    public:
        NodoPila();
        virtual ~NodoPila();
        NodoPila(ppasajero pasajero_, NodoPila * siguiente_);

        NodoPila* Getsiguiente()  { return siguiente; }
        void Setsiguiente(NodoPila* nuevoSiguiente) { siguiente = nuevoSiguiente; }
        ppasajero Getpasajero() { return pasajero; }
        Pasajero GetObjetoPasajero() {return (*pasajero);}
        void Setpasajero(ppasajero nuevoPasajero) { pasajero = nuevoPasajero; }


    private:
        ppasajero pasajero;
        NodoPila *siguiente;
};typedef NodoPila *pnodoPila;

#endif // NODOPILA_H

