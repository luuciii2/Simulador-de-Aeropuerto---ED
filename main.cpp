#include <iostream>
#include <vector>
#include <string>
#include <cctype> // Para isalpha y isupper
#include <algorithm> // Para std::all_of
#include <limits> // Para numeric_limits

#include "Pasajero.h"
#include "Pila.h"
#include "Aeropuerto.h"

using namespace std;

int main()
{
    int opcion;
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                        |   PRACTICA DE ESTRUCTURAS DE DATOS     |"<<endl;
    cout<<"                                        |    ft. Lucia Cantero & Rodrigo Rey     |"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n";
    cout<<"         [1] Crear la pila de pasajeros" <<endl;
    cout<<"\n";
    cout<<"         [2] Mostrar la pila de pasajeros." <<endl;
    cout<<"\n";
    cout<<"         [3] Borrar la pila de pasajeros." <<endl;
    cout<<"\n";
    cout<<"         [4] Simulacion de N minutos en el aeropuerto." <<endl;
    cout<<"\n";
    cout<<"         [5] Mostrar los datos de la lista de boxes." <<endl;
    cout<<"\n";
    cout<<"         [6] Mostrar el box mas y el menos lleno." <<endl;
    cout<<"\n";
    cout<<"         [7] Mostrar el numero de boxes operativos." <<endl;
    cout<<"\n";
    cout<<"         [8] Funcionamiento completo del control de aduanas." <<endl;
    cout<<"\n";
    cout<<"         [9] Insertar pasajero al arbol (leyendo datos del teclado)." <<endl;
    cout<<"\n";
    cout<<"         [10] Mostrar arbol de pasajeros." <<endl;
    cout<<"\n";
    cout<<"         [11] Mostrar los pasajeros con destino a un pais dado" <<endl;
    cout<<"\n";
    cout<<"         [12] Mostrar los paises que han sido destino de algun pasajero." <<endl;
    cout<<"\n";
    cout<<"         [13] Calcular y mostrar el pais destino de mayor numero de pasajeros y el de menor numero." <<endl;
    cout<<"\n";
    cout<<"         [14] Mostrar el tiempo medio de estancia en el aeropuerto de los pasajeros con destino a un pais dado." <<endl;
    cout<<"\n";
    cout<<"         [15] Mostrar el tiempo medio de estancia en el aeropuerto de los pasajeros con destino a cada uno de los paises." <<endl;
    cout<<"\n";
    cout<<"         [0] Salir del programa." <<endl;
    cout<<"\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n";
    cout<<" -> Seleccione la parte de la practica a la que le gustaria acceder: ";
    cin >> opcion;

    Pasajero pas1 = Pasajero(1, 0, 20, "Indonesia",6);
    Pasajero pas2 = Pasajero(2, 0, 15, "Portugal", 1);
    Pasajero pas3 = Pasajero(3, 5, 39, "Australia",7 );
    Pasajero pas4 = Pasajero(4, 7, 23, "Sudafrica",5);
    Pasajero pas5 = Pasajero(5, 9, 16, "Indonesia",6);
    Pasajero pas6 = Pasajero(6, 11, 23, "Noruega",4);
    Pasajero pas7 = Pasajero(7, 14, 31, "Australia",7);
    Pasajero pas8 = Pasajero(8, 18, 14, "Italia", 2);
    Pasajero pas9 = Pasajero(9, 21, 20, "Alemania",3);



    vector <Pasajero> pasajeros = {pas1,pas2,pas3,pas4,pas5,pas6,pas7,pas8,pas9};

    Aeropuerto aeropuerto1 = Aeropuerto();

    int minutosAnteriores = 0;

    while(opcion != 0){
            switch (opcion){
                case 1:{
                    aeropuerto1.empezar(pasajeros);

                    cout << "La pila de pasajeros ha sido creada correctamente."<<endl;

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 2:{
                    cout<<"MOSTRANDO PILA "<<endl;
                    aeropuerto1.mostrarPila();

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 3:{
                    aeropuerto1.borrarPila();

                    cout << "La pila de pasajeros ha sido borrada correctamente."<<endl;

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 4:{
                    if (minutosAnteriores==0){aeropuerto1.empezar(pasajeros);}

                    int minutos = 0;
                    cout<<"Introduzca el numero de minutos que desea simular: ";
                    cin>>minutos;

                    minutosAnteriores = aeropuerto1.pasoTiempoListas(minutos,true,minutosAnteriores);

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 5:{
                    aeropuerto1.mostrarBoxesListas();

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 6:{
                    aeropuerto1.consultarBoxes();

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 7:{
                    cout<<"Numero de boxes operativos: "<<aeropuerto1.mostrarBoxesOperativos()<<endl;


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 8:{
                    cout<<"Ejecutando funcionamiento completo de control de aduanas."<<endl;

                    aeropuerto1.empezar(pasajeros);

                    aeropuerto1.pasoTiempoListas(0,false,0);

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 9:{
                    cout<<"Introduzca los datos del pasajero: "<<endl;

                    int id, horal, adu, pri;
                    string p;

                    // Validación para `id`
                    cout << "ID: ";
                    cin >> id;
                    while (cin.fail()) {
                        cin.clear(); // Limpia el estado de error
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada inválida
                        cout << "Error: Por favor, introduce un numero entero para el ID: ";
                        cin >> id;
                    }

                    // Validación para `horal`
                    cout << "Hora de llegada: ";
                    cin >> horal;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: Por favor, introduce un numero entero para la hora de llegada: ";
                        cin >> horal;
                    }

                    // Validación para `adu`
                    cout << "Tiempo en aduanas: ";
                    cin >> adu;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: Por favor, introduce un numero entero para el tiempo en aduanas: ";
                        cin >> adu;
                    }

                    // Validación para `pri`
                    cout << "Prioridad: ";
                    cin >> pri;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: Por favor, introduce un numero entero para la prioridad: ";
                        cin >> pri;
                    }

                    // Validación para `p` (país)
                    cout << "Pais: ";
                    cin >> p;
                    while (true) {
                        // Verificar que todos los caracteres sean letras
                        if (!std::all_of(p.begin(), p.end(), [](char c) { return isalpha(c); })) {
                            cout << "Error: El nombre del pais solo debe contener letras. Intentalo de nuevo: ";
                            cin >> p;
                            continue;
                        }
                        // Verificar si la primera letra es mayúscula
                        if (!isupper(p[0])) {
                            cout << "Error: La primera letra debe ser una mayuscula. Intentalo de nuevo: ";
                            cin >> p;
                            continue;
                        }
                        // Verificar que todas las letras restantes sean minúsculas
                        if (!std::all_of(p.begin() + 1, p.end(), [](char c) { return islower(c); })) {
                            cout << "Error: Todas las letras, excepto la primera, deben ser minusculas. Intentalo de nuevo: ";
                            cin >> p;
                            continue;
                        }

                        // Si ambas condiciones son correctas, salir del bucle
                        break;
                    }

                    Pasajero pas = Pasajero(id,horal,adu,p,pri);
                    aeropuerto1.insertarEnArbol(pas);
                    cout<<"\nPasajero insertado al arbol"<<endl;

                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 10:{
                    cout<<"MOSTRANDO ARBOL"<<endl;

                    aeropuerto1.mostrarABBPasajeros();


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 11:{
                    string p;
                    cout<<"Introduzca el pais del que quiere consultar la lista de pasajeros: "<<endl;
                    cin>>p;

                    aeropuerto1.mostrarPasajeros(p);


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 12:{
                    cout<<"MOSTRANDO PAISES"<<endl;

                    aeropuerto1.mostrarPaises();


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 13:{

                    aeropuerto1.masYmenos();


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 14:{
                    string pais;
                    cout<<"Introduzca el pais del que quiere calcular el tiempo medio "<<endl;
                    cin>>pais;

                    aeropuerto1.tiempoMedioPais(pais);


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                case 15:{
                    cout<<"CALCULANDO TIEMPO MEDIO DE LOS PASAJEROS DE TODO EL ARBOL"<<endl;

                    aeropuerto1.tiempoMedioPaises();


                    cout <<"\n -> Acceda a una funcionalidad del menu: ";
                    cin >> opcion;
                    break;
                }
                default:{
                    cout<<"\n";
                    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"\n";
                    cout<<"Funcionalidad no disponible. Por favor, acceda a una de las opciones mostradas."<<endl;
                    cout<<" -> Acceda a una funcionalidad disponible del menu: ";
                    cin >> opcion;
                }
            }

    }
    cout<<"\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n";
    cout<<"FIN DEL PROGRAMA";
    return 0;
}
