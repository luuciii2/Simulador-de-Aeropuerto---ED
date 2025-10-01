#include "CeldaLista.h"

CeldaLista::CeldaLista()
{
    box = NULL;
    siguiente = NULL;
}

CeldaLista::CeldaLista(pbox box_, CeldaLista *sig_)
{
    box = box_;
    siguiente = sig_;
}

CeldaLista::~CeldaLista()
{
    //dtor
}
