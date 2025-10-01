#include <iostream>
#include "Pasajero.h"

using namespace std;

Pasajero::Pasajero()
{
    //ctor
}

Pasajero::Pasajero(int idPasajero_, int horaLlegada_, int aduanas_, string pais_, int prioridad_){
    idPasajero = idPasajero_;
    horaLlegada = horaLlegada_;
    aduanas = aduanas_;
    pais = pais_;
    prioridad = prioridad_;
    idBoxPas = 0;
    tiempoTotal = 0;
}

Pasajero::~Pasajero()
{
    //dtor
}

void Pasajero::verPasajero(){
    cout<<"Id pasajero "<<idPasajero<<endl;
}
