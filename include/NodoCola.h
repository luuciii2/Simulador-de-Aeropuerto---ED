#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "Pasajero.h"


class NodoCola
{
    friend class Cola;
    public:
        NodoCola();
        virtual ~NodoCola();
        NodoCola(ppasajero pas_, NodoCola *sig_);

        NodoCola* Getsiguiente()  { return siguiente; }
        void Setsiguiente(NodoCola* nuevoSiguiente) { siguiente = nuevoSiguiente; }
        ppasajero Getpasajero() { return pasajero; }
        void Setpasajero(ppasajero nuevoPasajero) { pasajero = nuevoPasajero; }

    private:
        NodoCola *siguiente;
        ppasajero pasajero;

};typedef NodoCola *pnodoCola;

#endif // NODOCOLA_H
