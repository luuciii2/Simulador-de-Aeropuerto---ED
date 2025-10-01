#include "Arbol.h"

#include "NodoArbol.h"
#include <string>
#include <iostream>

Arbol::Arbol()
{
    raiz = new NodoArbol("Mm");
}

Arbol::~Arbol()
{
    //dtor
}

void Arbol :: pasajeroEnArbol (Pasajero pas, pnodoArbol arbol, bool &estaEnArbol){

    if (arbol->pasajeros.estaEnLista(pas)){estaEnArbol = true;}


    if (arbol->izquierda != NULL){pasajeroEnArbol(pas, arbol->izquierda, estaEnArbol);}
    if (arbol->derecha != NULL){pasajeroEnArbol(pas, arbol->derecha,estaEnArbol);}

}
void Arbol :: insertar (Pasajero pas, pnodoArbol arbol){

    string p = pas.Getpais();

    if (p == arbol->pais){
            pas.Setprioridad(arbol->pasajeros.Getprimero()->Getpasajero().Getprioridad());
            arbol->pasajeros.enlistar(pas);}
    else{
    if (p < arbol->pais){
        if (arbol->izquierda == NULL){
            pnodoArbol n = (new NodoArbol(p));
            n->pasajeros.enlistar(pas);
            arbol->izquierda = n;

        }
        else {
            insertar (pas, arbol->izquierda);
        }
    }
    else { //p > arbol->pais
        if (arbol->derecha == NULL){
            pnodoArbol n  = (new NodoArbol(p));
            n->pasajeros.enlistar(pas);
            arbol->derecha = n;
        }
        else {
            insertar (pas, arbol->derecha);
        }
    }}

}

bool Arbol::mostrarPasajeros(string p, pnodoArbol arbol){

    if (p == arbol->pais){
        cout<<"Los pasajeros con destino a "<<p<<" son los siguientes: "<<endl;
        arbol->pasajeros.mostrarListaPas();
        return true;

    }

    else if (p < arbol->pais){
            if (arbol->izquierda != NULL){return mostrarPasajeros(p, arbol->izquierda);}
            else{return false;}
    }
    else{//p > arbol->pais
            if (arbol->derecha != NULL){return mostrarPasajeros(p, arbol->derecha);}
            else{return false;}
    }


}

void Arbol :: mostrarDatos(pnodoArbol arbol){

    if (arbol->izquierda != NULL){mostrarDatos(arbol->izquierda);}

    cout<<"\n\033[1mPais: "<<arbol->pais<<"\033[0m"<<endl;
    cout<<" Lista de pasajeros que han viajado al pais: "<<endl;
    arbol->pasajeros.mostrarListaPas();

    if (arbol->derecha != NULL){mostrarDatos(arbol->derecha);}

}

void Arbol :: mostrarPaises (pnodoArbol arbol){

    if (arbol->izquierda != NULL){mostrarPaises(arbol->izquierda);}

    cout<<arbol->pais<<endl;

    if (arbol->derecha != NULL){mostrarPaises(arbol->derecha);}
}


void Arbol::paisConMasYMenosPas(pnodoArbol arbol, string &paisMas, int &masPas, string &paisMenos, int &menosPas){

    int numPas = arbol->pasajeros.Getlongitud();

    // Si estamos procesando el primer nodo (menosPas == -1), inicializamos los valores
    if (menosPas == -1) {

        menosPas = numPas;
        paisMenos = arbol->pais;
        masPas = numPas;
        paisMas = arbol->pais;

    } else {

        if (numPas > masPas) {
            masPas = numPas;
            paisMas = arbol->pais;
        }
        if (numPas < menosPas) {
            menosPas = numPas;
            paisMenos = arbol->pais;
        }
    }


    if (arbol->izquierda != NULL){paisConMasYMenosPas(arbol->izquierda, paisMas, masPas, paisMenos, menosPas);}


    if (arbol->derecha != NULL){paisConMasYMenosPas(arbol->derecha, paisMas, masPas, paisMenos, menosPas);}
}

float Arbol :: tiempoMedioNodo(pnodoArbol arbol, string p){

    if (p == arbol->pais){
            float sumaTiempos = arbol->pasajeros.sumaTiempos();
            int numPas = arbol->pasajeros.Getlongitud();

            return sumaTiempos/numPas;

    }

    else if (p < arbol->pais){
            if (arbol->izquierda != NULL){return tiempoMedioNodo(arbol->izquierda, p);}
            else{return -1;}

    }
    else{//p > arbol->pais
            if (arbol->derecha != NULL){return tiempoMedioNodo(arbol->derecha, p);}
            else{return -1;}

    }

}

void Arbol :: tiempoPreorden (pnodoArbol arbol, float &sumaTiempos, int &numPas){

    if (arbol->pais != "Mm"){
        sumaTiempos += arbol->pasajeros.sumaTiempos();
        numPas += arbol->pasajeros.Getlongitud();
    }

    if (arbol->izquierda != NULL){tiempoPreorden(arbol->izquierda, sumaTiempos, numPas);}
    if(arbol->derecha != NULL){tiempoPreorden(arbol->derecha, sumaTiempos, numPas);}


}

float Arbol :: tiempoMedioTodos(){

    float sumaTiempos = 0.0;
    int numPas = 0;

    tiempoPreorden(raiz, sumaTiempos, numPas);

    if (numPas != 0){return sumaTiempos / numPas;}
    else{return 0;}
}

