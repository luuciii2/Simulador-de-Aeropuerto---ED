#ifndef CELDALISTA_H
#define CELDALISTA_H

#include "Box.h"


class CeldaLista;

typedef CeldaLista *pcelda;

class CeldaLista
{
    friend class Lista;
    public:
        CeldaLista();
        CeldaLista(pbox box_, CeldaLista *sig_);
        virtual ~CeldaLista();


        pbox Getbox() { return box; }
        void Setbox(pbox val) { box = val; }
        pcelda Getsiguiente() { return siguiente; }
        void Setsiguiente(pcelda val) { siguiente = val; }

    protected:

    private:
        pbox box;
        pcelda siguiente;
};

#endif // CELDALISTA_H
