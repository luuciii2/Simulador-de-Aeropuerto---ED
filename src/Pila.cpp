#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "Pasajero.h"

using namespace std;

Pila::Pila()
{
    cima = NULL;
}

Pila::~Pila()
{
    while(cima) {desapilar();}
}

bool Pila::esVacia(){
    return cima == NULL;
}

void Pila::apilar(Pasajero pas){
    Pasajero* ppas = new Pasajero(pas);
    if (esVacia()){
        pnodoPila nuevo = new NodoPila(ppas,NULL);
        cima = nuevo;
    }
    else{
        pnodoPila aux = cima;
        pnodoPila anterior = NULL;
        int tiempoNuevo = pas.GethoraLlegada();

        while (aux != NULL && tiempoNuevo >= aux->pasajero->GethoraLlegada()){
            anterior = aux;
            aux = aux->siguiente;
        }
        pnodoPila nuevo = new NodoPila(ppas, aux);

        if (anterior == NULL){
            cima = nuevo;
        } else{
            anterior->siguiente = nuevo;
        }

    }
}


void Pila::desapilar(){
     if (cima){
        pnodoPila aux = cima;
        cima = aux->siguiente;
        delete aux->pasajero;
        delete aux;
    }
}



void Pila::mostrarPila(){


    if(esVacia()){
        cout<<"La pila esta vacia."<<endl;
        return;
    }


    pnodoPila aux = cima;
    while(aux != NULL){


            int anchoCampo = 20;

            cout << setw(anchoCampo) << left << "\033[1m ID del pasajero:\033[0m " << setw(5) << aux->pasajero->GetidPasajero();
            cout << setw(anchoCampo) << left << "\033[1m Hora de llegada:\033[0m " << setw(5) << aux->pasajero->GethoraLlegada();
            cout << setw(15) << left << "\033[1m Aduanas:\033[0m " << setw(5) << aux->pasajero->Getaduanas();
            cout << setw(10) << left << "\033[1m Pais:\033[0m " << setw(15) << aux->pasajero->Getpais();
            cout << setw(anchoCampo) << left << "\033[1m Prioridad:\033[0m " << setw(5) << aux->pasajero->Getprioridad();
            cout << "\n";

        aux = aux->siguiente;
    }
}

