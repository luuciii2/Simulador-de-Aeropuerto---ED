#include "CeldaListaPas.h"


CeldaListaPas::~CeldaListaPas()
{
    //dtor
}

CeldaListaPas::CeldaListaPas(Pasajero pas, CeldaListaPas *sig_)
{
    pasajero = pas;
    siguiente = sig_;
}
