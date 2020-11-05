#include <iostream>
#include "laboratorio.h"
#include "computadora.h"

using namespace std;

/* Opciones Menu */
enum {
    AGREGAR = 1,
    MOSTRAR,
    RESPALDAR,
    RECUPERAR,
    INSERTAR,
    INICIALIZAR,
    ELIMINAR,
    ORDENAR,
    BUSCAR,
    SALIR
};

int main() {

    Laboratorio lab;
    
    int opc; // creamos una opcion para el menu
    Computadora c; // creamos una variable computadora temporal
    size_t p; // declaramos una variable de tipo posición
    bool continueProgram = true; // comenzamos el menu ciclico

    do {

        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                     " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Agregar Computadora" << endl;
        cout << "\t2-. Mostrar" << endl;
        cout << "\t3-. Respaldar" << endl;
        cout << "\t4-. Recuperar" << endl;
        cout << "\t5-. Insertar" << endl;
        cout << "\t6-. Inicializar" << endl;
        cout << "\t7-. Eliminar" << endl;
        cout << "\t8-. Ordenar" << endl;
        cout << "\t9-. Buscar" << endl;
        cout << "\t10-. Salir" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();
        cout << endl;
        
        /* Evaluamos */
        switch(opc) {

        case AGREGAR:
            cin >> c; // pedimos datos y guardamos

            lab.agregarComputadora(c); // agregamos al arreglo
            cin.ignore();
            break;
        
        case MOSTRAR:
            lab.mostrar(); // mostramos
            break;

        case RESPALDAR:
            lab.respaldar(); // respaldamos
            break;

        case RECUPERAR:
            lab.recuperar(); // recuperamos
            break;

        case INSERTAR:
            size_t p; // creamos una variable posición

            cout << "\tPosicion a insertar : ";
            cin >> p; cin.ignore();
            cin >> c; // pedimos datos y guardamos
            cout << endl;

            if (p >= lab.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else { 
                lab.insertar(c,p); // insertamos en p
            }
            break;

        case INICIALIZAR:
            size_t n; // creamos una variable de tamaño

            cout << "\tDimension de vector : ";
            cin >> n; cin.ignore(); // guardamos el nuevo tamaño
            cout << "  Inicializar con : " << endl;
            cin >> c; // guardamos la cadena a inicializar
            cout << endl;

            lab.inicializar(c,n); // declaramos el cambio en el vector
            break;
      
        case ELIMINAR:
            cout << "\tPosicion para eliminar : ";
            cin >> p; cin.ignore();

            if (p >= lab.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else {
                lab.eliminar(p); // eliminamos en p
            }
            break;
        
        case ORDENAR:
            lab.ordernar(); // ordenación: simple
            break;

        case BUSCAR: {
                cin >> c; // pedimos el personaje
                cout << endl;

                Computadora *ptr = lab.buscar(c); // buscamos

                if(ptr==nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *ptr << endl;
                }
            }
            break;

        case SALIR: 
            continueProgram = false; // cerramos ciclo
            break;

        default: 
            cout << "\tOpcion Invalida" << endl;
            break;
        }

    } while (continueProgram);

    return 0;
}