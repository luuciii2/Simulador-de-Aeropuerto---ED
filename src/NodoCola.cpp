#include <iostream>
#include "NodoCola.h"

using namespace std;

NodoCola::NodoCola()
{
    pasajero = NULL;
    siguiente = NULL;
}

NodoCola::~NodoCola()
{
    //dtor
}

NodoCola::NodoCola(ppasajero pas_, NodoCola *sig_)
{
    pasajero = pas_;
    siguiente = sig_;
}
