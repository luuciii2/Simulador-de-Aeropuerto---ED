#include <iostream>
#include <iomanip>
#include "Cola.h"

#include "NodoCola.h"

using namespace std;

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola()
{
    while (primero){desencolar();}
}

bool Cola::esVacia(){
    return primero == NULL;
}

void Cola::encolar(Pasajero pas){
    Pasajero* ppas = new Pasajero(pas);
    pnodoCola nuevo = new NodoCola(ppas, NULL);

    if (esVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        pnodoCola aux1 = primero;
        pnodoCola aux2 = NULL;
        int prioridadNuevo = pas.Getprioridad();

        while (aux1 != NULL && prioridadNuevo <= aux1->pasajero->Getprioridad()) {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }

        if (aux2 == NULL) {
            nuevo->siguiente = primero;
            primero = nuevo;
        } else {
            nuevo->siguiente = aux1;
            aux2->siguiente = nuevo;
        }

        if (aux1 == NULL) {
            ultimo = nuevo;
        }
    }
    longitud++;
}



void Cola::desencolar(){
    if (!esVacia()){
            if (primero == ultimo){
                primero = NULL;
                ultimo = NULL;
            }
            else{
                pnodoCola aux = primero;
                primero = aux->siguiente;
                delete aux;
            }
            longitud--;

    }

}




void Cola::mostrarCola(){

    if(esVacia()){
        cout<<"La cola es vacia."<<endl;
        return;
    }
    pnodoCola aux = primero;
    while (aux != NULL) {

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
