#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Lista::~Lista(){

    while(primero){desenlistar();}
}

bool Lista::esVacia(){
    return primero == NULL;
}

void Lista::enlistar(Box box){

    Box* pbox = new Box(box);
    pcelda nuevo = new CeldaLista(pbox, NULL);

    if (esVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}

void Lista::desenlistar(){
    if (!esVacia()){
            if (primero == ultimo){
                primero = NULL;
                ultimo = NULL;
            }
            else{
                pcelda aux = primero;
                primero = aux->siguiente;
                delete aux;
            }
            longitud --;
    }
}




pbox Lista::boxMenosPas() {
    if (esVacia()){return NULL;}


    pcelda actual = primero;

    Box* boxMenorCola = actual->Getbox();

    int menorTamano = boxMenorCola->longitud();

    while (actual != NULL) {
        Box* box = actual->Getbox();
        int tamanoCola = box->longitud();
        if (tamanoCola < menorTamano) {
            menorTamano = tamanoCola;
            boxMenorCola = box;
        }
        actual = actual->Getsiguiente();
    }

    return boxMenorCola ;
}

pbox Lista::boxMasPas() {
    if (esVacia()){return NULL;}

    pcelda actual = primero;

    Box* boxMayorCola = actual->Getbox();

    int mayorTamano = boxMayorCola->longitud();

    while (actual != NULL) {
        Box* box = actual->Getbox();
        int tamanoCola = box->longitud();

        if (tamanoCola > mayorTamano){
            mayorTamano = tamanoCola;
            boxMayorCola = box;
        }
        actual = actual->Getsiguiente();
    }

    return boxMayorCola ;
}



bool Lista::boxsMas2Pas() {
    bool masDeDos = true;
    if (esVacia()) {return masDeDos = false;}

    pcelda actual = primero;
    while (actual != NULL) {
        Box* box = actual->Getbox();
        if ((box->longitud()) <= 2) {
            masDeDos = false;
        }
        actual = actual->Getsiguiente();
    }
    return masDeDos;
}

int Lista::numBoxsVacios() {
    int count = 0;
    pcelda actual = primero;

    while (actual != NULL) {
        Box* box = actual->Getbox();
        if (box->boxVacio() && box->colaBoxVacia()) {
            count++;
        }
        actual = actual->Getsiguiente();
    }

    return count;
}
bool Lista::algunBoxLleno(){
    pcelda actual = primero;
    bool algunoLleno = false;

    while (actual != NULL && !algunoLleno){
        if (!(actual->Getbox()->boxVacio())){algunoLleno = true;}
        actual = actual->Getsiguiente();
    }
    return algunoLleno;
}
void Lista::eliminarBoxsVacios() {

    pcelda actual = primero;
    pcelda anterior = NULL;

    while (actual != NULL) {
        Box* box = actual->Getbox();
        if (box->boxVacio() && box->colaBoxVacia()) {
            if (anterior == NULL) {
                primero = actual->Getsiguiente();
            } else {
                anterior->Setsiguiente(actual->Getsiguiente());
            }

            longitud --;
            delete actual;
            actual = (anterior == NULL) ? primero : anterior->Getsiguiente();
        } else {
            anterior = actual;
            actual = actual->Getsiguiente();
        }
    }
}
