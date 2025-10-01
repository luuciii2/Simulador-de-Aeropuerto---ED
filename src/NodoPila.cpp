#include <iostream>
#include "NodoPila.h"

using namespace std;

NodoPila::NodoPila()
{
    pasajero = NULL;
    siguiente= NULL;
}

NodoPila::~NodoPila()
{
    //dtor
}

NodoPila::NodoPila(ppasajero pasajero_, NodoPila *siguiente_){
    pasajero = pasajero_;
    siguiente = siguiente_;
}
