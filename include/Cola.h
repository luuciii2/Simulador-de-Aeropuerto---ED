#ifndef COLA_H
#define COLA_H

#include "NodoCola.h"


class Cola
{
    public:
        Cola();
        virtual ~Cola();

        pnodoCola Getprimero()  { return primero; }
        void Setprimero(pnodoCola nuevoPrimero) { primero = nuevoPrimero; }
        pnodoCola Getultimo()  { return ultimo; }
        void Setultimo(pnodoCola nuevoUltimo) { ultimo = nuevoUltimo; }
        int Getlongitud()  { return longitud; }
        void Setlongitud(int nuevaLongitud) { longitud = nuevaLongitud; }


        void encolar(Pasajero pas);
        void desencolar();
        bool esVacia();
        void mostrarCola();

    private:
        pnodoCola primero;
        pnodoCola ultimo;
        int longitud;

};

#endif // COLA_H
