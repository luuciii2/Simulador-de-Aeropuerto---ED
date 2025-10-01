#ifndef BOX_H
#define BOX_H

#include <iostream>

#include "Pasajero.h"
#include "Cola.h"


class Box
{
    public:
        Box();
        Box(int id);
        virtual ~Box();

        ppasajero GetpasajeroBox() { return pasajero_box; }
        void SetpasajeroBox(ppasajero val) { pasajero_box = val; }

        int GetidBox() { return idBox; }
        void SetidBox(int val) { idBox = val; }

        void meterPas(ppasajero pas_box);
        void quitarPas ();
        bool boxVacio();
        void mostrarBox();

        Cola Getcola() {return colaBox; }
        void Setcola(Cola val) { colaBox = val; }


        void meterACola(Pasajero pas);
        void quitarDeCola();
        bool colaBoxVacia();
        pnodoCola primeroBox();
        void verCola();
        int longitud();

    protected:
        int idBox;
        ppasajero pasajero_box;
        Cola colaBox;

    private:

};typedef Box* pbox;

#endif // BOX_H
