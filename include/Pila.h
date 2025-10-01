#ifndef PILA_H
#define PILA_H

#include "Pasajero.h"
#include "NodoPila.h"

class Pila
{
    public:
        Pila();
        virtual ~Pila();

        pnodoPila Getcima(){return cima;}
        void Setcima(pnodoPila c) {cima = c;}

        bool esVacia();
        void apilar(Pasajero pas);
        void desapilar();
        void mostrarPila();

        Pasajero* obtenerPasajeroCima();

    private:
        pnodoPila cima;


};

#endif // PILA_H

