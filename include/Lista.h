#ifndef LISTA_H
#define LISTA_H

#include "CeldaLista.h"


class Lista
{
    public:
        Lista();
        virtual ~Lista();

        pcelda Getprimero() { return primero; }
        void Setprimero(pcelda val) { primero = val; }
        pcelda Getultimo() { return ultimo; }
        void Setultimo(pcelda val) { ultimo = val; }
        int Getlongitud(){return longitud;}

        bool esVacia();
        void enlistar(Box box);
        void desenlistar();
        pbox boxMenosPas();
        pbox boxMasPas();
        bool boxsMas2Pas();
        int numBoxsVacios();
        void eliminarBoxsVacios();
        bool algunBoxLleno();

    private:
        int longitud;
        pcelda primero;
        pcelda ultimo;
};

#endif // LISTA_H
