#include "ListaPasajeros.h"
#include <iostream>
#include <iomanip>

ListaPasajeros::ListaPasajeros()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

ListaPasajeros::~ListaPasajeros()
{
    while(primero){desenlistar();}
}

bool ListaPasajeros::esVacia(){
    bool a= primero==NULL;
    return primero == NULL;
}

void ListaPasajeros::enlistar(Pasajero pas){

    pceldaPas nuevo = new CeldaListaPas(pas, NULL);
    if (esVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;

}

void ListaPasajeros::desenlistar(){
    if (!esVacia()){
            if (primero == ultimo){
                primero = NULL;
                ultimo = NULL;
            }
            else{
                pceldaPas aux = primero;
                primero = aux->siguiente;
                delete aux;
            }
            longitud--;
    }
}

bool ListaPasajeros :: estaEnLista (Pasajero pas){
    bool estaEnLista = false;

    if(!esVacia()){
        pceldaPas aux = primero;
        while (aux != NULL) {

                if (aux->pasajero.GetidPasajero() == pas.GetidPasajero()){estaEnLista = true;}

            aux = aux->siguiente;
        }
    }
    return estaEnLista;


}
void ListaPasajeros::mostrarListaPas(){

    if(esVacia()){
        cout<<"La lista es vacia."<<endl;
        return;
    }
    pceldaPas aux = primero;
    while (aux != NULL) {

            int anchoCampo = 20;

            cout << setw(anchoCampo) << left << "\033[1m ID del pasajero:\033[0m " << setw(5) << aux->pasajero.GetidPasajero();
            cout << setw(anchoCampo) << left << "\033[1m Hora de llegada:\033[0m " << setw(5) << aux->pasajero.GethoraLlegada();
            cout << setw(15) << left << "\033[1m Aduanas:\033[0m " << setw(5) << aux->pasajero.Getaduanas();
            cout << setw(10) << left << "\033[1m Pais:\033[0m " << setw(15) << aux->pasajero.Getpais();
            cout << setw(anchoCampo) << left << "\033[1m Prioridad:\033[0m " << setw(5) << aux->pasajero.Getprioridad();
            cout <<setw(anchoCampo) << left << "\033[1m  ID del Box:\033[0m" << setw(5) << aux->pasajero.GetidBoxPas();
            cout << setw(anchoCampo) << left << "\033[1m Tiempo de estancia:\033[0m " << setw(5) << aux->pasajero.GettiempoTotal();
            cout << "\n";

        aux = aux->siguiente;
    }
}

float ListaPasajeros :: sumaTiempos (){
    float suma = 0;
    if(!esVacia()){
        pceldaPas aux = primero;
        while (aux != NULL) {

            suma += aux->pasajero.GettiempoTotal();


            aux = aux->siguiente;
        }
    }

    return suma;

}
