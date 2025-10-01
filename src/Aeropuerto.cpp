#include <iostream>
#include <string>
#include <vector>

#include "Aeropuerto.h"
#include "Pasajero.h"
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"
#include "Box.h"
#include "Arbol.h"



using namespace std;

Aeropuerto::Aeropuerto()
{
    pila = Pila();
    lista = Lista();
    boxl = Box(1);
    lista.enlistar(boxl);
    numPas = 0;

}

Aeropuerto::~Aeropuerto()
{
    //dtor
}

void Aeropuerto :: crearPila (vector <Pasajero> &pasajeros){
    numPas = pasajeros.size();
    for (Pasajero pasajero : pasajeros) {
        pila.apilar(pasajero);
    }

}

void Aeropuerto :: empezar (vector <Pasajero> &pasajeros){
    pila.~Pila();
    crearPila(pasajeros);
    lista = Lista();
    boxl = Box(1);
    lista.enlistar(boxl);
}

void Aeropuerto::mostrarPila(){

    pila.mostrarPila();

}

void Aeropuerto::borrarPila(){
    pila.~Pila();
}



void Aeropuerto::mostrarBoxesListas() {
    if (lista.esVacia()) {
        cout << "No existe ningun Box creado." << endl;
        return;
    }

    pcelda actual = lista.Getprimero();
    while (actual != NULL) {

        Box* box = actual->Getbox();
        cout<<"\n";
        box->mostrarBox();

        actual = actual->Getsiguiente();
    }
}

int Aeropuerto::mostrarBoxesOperativos(){
    return lista.Getlongitud();
}

void Aeropuerto::consultarBoxes(){//sirve para consultar cual es el box con menos pasajeros y el box m�s ocupado
    if (lista.Getprimero()==lista.Getultimo()){
        cout<<"Solo esta operativo el Box 1: "<<endl;
        lista.Getprimero()->Getbox()->mostrarBox();
    }else{
    cout<<"\n\033[1mBOX CON MENOS PASAJEROS \033[0m \n";
    lista.boxMenosPas()->mostrarBox();
    cout<<"\n\033[1mBOX CON MAS PASAJEROS \033[0m \n";
    lista.boxMasPas()->mostrarBox();
    }

}

void Aeropuerto :: sacarDePila(int tiempoActual){ //esta funcion saca el pasajero de la cima de la pila y lo coloca en el box con menos pasajeros
        Box* boxMenorCola = lista.boxMenosPas(); //crear variable que es un puntero al box con la menor cola
        ppasajero nuevoPasajero = pila.Getcima()->Getpasajero(); //puntero al pasajero de la cima
        boxMenorCola->meterACola(*(nuevoPasajero)); //meter al nuevo pasajero
        cout<<" Pasajero con ID "<<nuevoPasajero->GetidPasajero()<<" Se ha puesto a la cola del BOX "<<boxMenorCola->GetidBox()<<endl;
        cout<<" La cola es la siguiente: "<<endl;
        boxMenorCola->verCola();
        pila.desapilar();

}

void Aeropuerto :: meterABox(int tiempoActual, Box* box){ //esta funcion saca al pasajero de la cola del Box y lo mete al mismo
        ppasajero pas = box->primeroBox()->Getpasajero();
        box->meterPas(pas);
        box->quitarDeCola();
        pas->SetidBoxPas(box->GetidBox());
        cout<<" Pasajero con ID "<<pas->GetidPasajero()<<" Ha entrado al BOX "<<box->GetidBox()<<endl;

}



int Aeropuerto :: tiempoPas(int tiempoActual, ppasajero pas){ //devuelve el tiempo que ha estado un pasajero en el aeropuerto
        int tiempoPasajero = ((tiempoActual - pas->GethoraLlegada())+pas->Getaduanas());
        pas->SettiempoTotal(tiempoPasajero);
        return tiempoPasajero;
}

void Aeropuerto :: insertarEnArbol(Pasajero pas){ //inserta un pasajero en el arbol (se comprueba si el pais está en el arbol para meterlo a la lista, o por el contrario crear nueva hoja)

        bool estaEnArbol = false;
        arbol.pasajeroEnArbol(pas, arbol.raiz, estaEnArbol);
        if (!estaEnArbol){arbol.insertar(pas,arbol.raiz);}

}
void Aeropuerto :: mostrarABBPasajeros(){//muestra el arbol de pasajeros

    arbol.mostrarDatos(arbol.Getraiz());

}
void Aeropuerto :: mostrarPasajeros (string p){//muestra los pasajeros que han viajado al pais introducido

    if(arbol.mostrarPasajeros(p, arbol.raiz) == false){cout<<"Pais no encontrado"<<endl;};
}
void Aeropuerto :: mostrarPaises(){//muestra los paises segun como estan ordenados en el arbol

    arbol.mostrarPaises(arbol.raiz);
}

void Aeropuerto :: masYmenos(){ //muestra el pais con mas pasajeros y el pais con menos pasajeros
    string paisMas = "";
    int masPas = 0;
    string paisMenos = "";
    int menosPas = -1; // Se inicializa a -1 para identificar que no hemos procesado el arbol

    //se llama a la funcion paisConMasYMenosPas directamente con arbol.izquierda y arbol.derecha porque si no sale la raiz, Mm, como pais con menos pasajeros
    if (arbol.raiz->Getizquierda() != NULL){arbol.paisConMasYMenosPas(arbol.raiz->Getizquierda(), paisMas, masPas, paisMenos, menosPas);}


    if (arbol.raiz->Getderecha() != NULL){arbol.paisConMasYMenosPas(arbol.raiz->Getderecha(), paisMas, masPas, paisMenos, menosPas);}

    if (masPas == 0 && menosPas == -1){cout<<"Arbol vacio"<<endl;}
    else{

        cout<<"PAIS CON MAS PASAJEROS: "<<paisMas<<" -> "<<masPas<<" pasajeros"<<endl;
        cout<<"PAIS CON MENOS PASAJEROS: "<<paisMenos<<" -> "<<menosPas<<" pasajeros"<<endl;
    }
}

void Aeropuerto::tiempoMedioPais(string p){ //muestra el tiempo medio de los pasajeros que han viajado al pais introducido
    float t = arbol.tiempoMedioNodo(arbol.raiz, p);

    if (t != -1){cout<<"El tiempo medio de estancia de los pasajeros que han viajado a "<<p<<" es de "<<t<<" minutos"<<endl;}
    else{cout<<"Pais no encontrado"<<endl;}
}

void Aeropuerto::tiempoMedioPaises(){

    float t = arbol.tiempoMedioTodos();
    cout<<"El tiempo medio de estancia de los pasajeros con destino a cada uno de los paises es de "<<t<<" minutos"<<endl;
}

int Aeropuerto :: pasoTiempoListas (int tiempoElegido, bool tiempo, int minutosAnte){
    int tiempoActualP = 0;
    if (minutosAnte != 0){
        tiempoActualP += minutosAnte+1;
    }
    float tiempoEnAeropuerto = 0.0;
    float tiempoMedio;
    int tiempoActual = tiempoActualP;
    tiempoElegido += minutosAnte;


    while ((((tiempoActual<=tiempoElegido && tiempo) || !(tiempoActual<tiempoElegido) && !tiempo ) && (!pila.esVacia() || lista.algunBoxLleno()))){
        cout << "\n\033[1mHORA ACTUAL:\033[0m  "<<tiempoActual<<"\n";

        while (!pila.esVacia() && pila.Getcima()->Getpasajero()->GethoraLlegada()==tiempoActual){ //este while cotrola si hay que sacar a alguien de la pila
            sacarDePila(tiempoActual);
        }

        pcelda boxActual = lista.Getprimero();

        while (boxActual != NULL){
            pbox box = boxActual->Getbox();
            if (box->boxVacio()&&(!box->colaBoxVacia())){
                 meterABox(tiempoActual, box);
                 tiempoEnAeropuerto += tiempoPas(tiempoActual, box->GetpasajeroBox());
            }
            else if (!box->boxVacio()){
                int aduanasActuales = box->GetpasajeroBox()->Getaduanas();
                aduanasActuales--;
                box->GetpasajeroBox()->Setaduanas(aduanasActuales);

                if (aduanasActuales == 0){
                    cout<<" Pasajero con ID "<<box->GetpasajeroBox()->GetidPasajero()<<" Ha salido del BOX "<<box->GetidBox()<<endl;
                    Pasajero pas = *(box->GetpasajeroBox());
                    insertarEnArbol(pas);
                    box->quitarPas();

                    if (!box->colaBoxVacia()){
                            meterABox(tiempoActual, box);
                            tiempoEnAeropuerto += tiempoPas(tiempoActual, box->GetpasajeroBox());
                    }
                }
            }
            boxActual = boxActual->Getsiguiente();
        }

        //Si todos los boxs tienen mas de 2 pasajeros en espera se crea otro box.
        if (lista.boxsMas2Pas()){
            int id = (lista.Getlongitud()) + 1;
            pbox nuevo = new Box (id);
            lista.enlistar(*(nuevo));
            cout<<" Un nuevo BOX ha sido annadido. El numero total de Boxs es: "<<lista.Getlongitud()<<endl;
        }

        //Si hay 2 boxs o mas libres los eliminamos.
        if(lista.numBoxsVacios()>=2 && lista.Getlongitud()>1){
            lista.eliminarBoxsVacios();
            cout<<" Boxs vacios eliminados. El numero total de Boxs es: "<<lista.Getlongitud()<<endl;
        }

        tiempoActual++;

    }
    if (tiempoActual == tiempoActualP){
            cout<<"La simulacion ha terminado, vuelva a empezar"<<endl;
            return 0;
    }
    else{

            if (tiempo == false){
                tiempoMedio = tiempoEnAeropuerto/numPas;
                cout<<"\nEl tiempo medio de estancia en el aeropuerto ha sido de "<<tiempoMedio<<"minutos"<<endl;
            }
            return tiempoElegido;
    }

}
