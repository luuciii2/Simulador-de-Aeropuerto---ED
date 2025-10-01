#ifndef PASAJERO_H
#define PASAJERO_H

#include <string>

using namespace std;

class Pasajero
{
    public:
        Pasajero();
        Pasajero(int idPasajero, int horaLlegada, int aduanas, string pais, int prioridad);
        virtual ~Pasajero();

        int GetidPasajero() {return idPasajero; }
        void SetidPasajero(int val) { idPasajero = val; }
        int GethoraLlegada() { return horaLlegada; }
        void SethoraLlegada(int val) { horaLlegada = val; }
        int GettiempoTotal() { return tiempoTotal; }
        void SettiempoTotal(int val) { tiempoTotal = val; }
        int Getaduanas() { return aduanas; }
        void Setaduanas(int val) { aduanas = val; }
        string Getpais() { return pais; }
        void Setpais(string val) { pais = val; }
        int Getprioridad() { return prioridad; }
        void Setprioridad(int val) { prioridad = val; }
        int GetidBoxPas() {return idBoxPas;}
        void SetidBoxPas(int val) {idBoxPas = val;}
        void verPasajero();


    protected:

    private:
        int idPasajero;
        int horaLlegada;
        int aduanas;
        string pais;
        int prioridad;
        int tiempoTotal;
        int idBoxPas;
};typedef Pasajero *ppasajero;

#endif // PASAJERO_H
