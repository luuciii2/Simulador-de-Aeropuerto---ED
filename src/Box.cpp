#include "Box.h"

#include <iostream>

#include "Pasajero.h"

Box::Box()
{
    pasajero_box = NULL;
}

Box::~Box()
{
    //dtor
}
Box::Box(int id){
    pasajero_box = NULL;
    idBox = id;
    colaBox = Cola();
}

bool Box::boxVacio() {
    return pasajero_box == NULL;
}


void Box::meterPas(ppasajero pas_box){
    pasajero_box = pas_box;
}

void Box::quitarPas(){
    pasajero_box = NULL;
}

void Box::mostrarBox(){

    if (boxVacio()){
        cout<<"\033[1mBOX CON ID \033[0m  "<<idBox<<"\n"<< "Vacio"<<endl;
    }else{
        cout<<"\033[1mBOX CON ID \033[0m "<<idBox<<"\n"<<"Ocupado por el pasajero con ID: "<<pasajero_box->GetidPasajero()<<endl;
        if (!colaBox.esVacia()){
            cout<<"Cola del box: "<<endl;
            colaBox.mostrarCola();
        }
        else{cout<<"Cola del box vacia"<<endl;}
    }
}



void Box::meterACola(Pasajero pas){
    colaBox.encolar(pas);
}
bool Box::colaBoxVacia(){
    return colaBox.esVacia();
}
pnodoCola Box::primeroBox(){
    colaBox.Getprimero();
}
void Box::quitarDeCola(){
    colaBox.desencolar();
}
void Box::verCola(){
    colaBox.mostrarCola();
}
int Box::longitud(){
    colaBox.Getlongitud();
}


