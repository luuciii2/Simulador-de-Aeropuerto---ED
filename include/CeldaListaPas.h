#ifndef CELDALISTAPAS_H
#define CELDALISTAPAS_H
#include "Pasajero.h"


class CeldaListaPas
{
    friend class ListaPasajeros;
    public:
        virtual ~CeldaListaPas();
        CeldaListaPas(Pasajero pas, CeldaListaPas *sig_);

        Pasajero Getpasajero() { return pasajero; }
        void Setpasajero(Pasajero val) { pasajero = val; }
        CeldaListaPas* Getsiguiente() { return siguiente; }
        void Setsiguiente(CeldaListaPas* val) { siguiente = val; }

    protected:

    private:
        Pasajero pasajero;
        CeldaListaPas* siguiente;
};typedef CeldaListaPas* pceldaPas;

#endif // CELDALISTAPAS_H
