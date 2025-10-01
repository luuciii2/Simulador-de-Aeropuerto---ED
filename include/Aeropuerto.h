#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <vector>

#include "Pila.h"
#include "Cola.h"
#include "Box.h"
#include "Lista.h"
#include "Arbol.h"



class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();

        Pila Getpila() { return pila; }
        void Setpila(Pila val) { pila = val; }
        Cola Getcola() { return cola; }
        void Setcola(Cola val) { cola = val; }
        Lista Getlista() { return lista; }
        void Setlista (Lista val) { lista = val; }
        Box Getboxl() { return boxl; }
        void Setboxl (Box val) { boxl = val; }

        void empezar(vector <Pasajero> &listaPasajeros);
        void crearPila(vector <Pasajero> &listaPasajeros);
        void mostrarPila();
        void borrarPila();
        void mostrarBoxesListas();
        int mostrarBoxesOperativos();
        void consultarBoxes(); //sirve para consultar cual es el box con menos pasajeros y el box más ocupado
        int pasoTiempoListas(int tiempoElegido, bool tiempo, int minutosAnte);
        void sacarDePila(int tiempoActual);
        void meterABox(int tiempoActual, Box* box);
        int tiempoPas(int tiempoActual, ppasajero pas);
        void insertarEnArbol (Pasajero pas);
        void mostrarABBPasajeros(); //muestra el arbol de pasajeros
        void mostrarPasajeros (string p); //muestra los pasajeros que han viajado al pais introducido
        void mostrarPaises(); //muestra los paises segun como estan ordenados en el arbol
        void masYmenos(); //muestra el pais con mas pasajeros y el pais con menos pasajeros
        void tiempoMedioPais(string p); //muestra el tiempo medio de los pasajeros que han viajado al pais introducido
        void tiempoMedioPaises(); //muestra el tiempo medio de todos los pasajeros

    protected:

    private:
        Pila pila;
        Cola cola;
        Lista lista;
        Box boxl;
        Arbol arbol;
        int numPas;

};

#endif // AEROPUERTO_H
