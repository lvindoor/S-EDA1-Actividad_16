#include "laboratorio.h"

Laboratorio::Laboratorio() { }

void Laboratorio::agregarComputadora(const Computadora &c) {
    computadoras.push_back(c); // insertar en posicion c
}

void Laboratorio::insertar(const Computadora &c, size_t pos) {
    computadoras.insert(computadoras.begin()+pos,c); // insertamos en la posicion
}

void Laboratorio::mostrar() {

    cout << left;
    cout << setw(20) << "Sistema Operativo";
    cout << setw(10) << "RAM (GB)";
    cout << setw(20) << "Nombre del Equipo";
    cout << setw(16) << "Procesador";
    cout << endl;
        
    for(size_t i=0;i<computadoras.size();i++) {
        Computadora &c = computadoras[i];
        cout << c;

        //cout << "Sistema Operativo  : " << c.getSistemaOperativo() << endl;
        //cout << "RAM (GB)           : " << c.getRam() << endl;
        //cout << "Nombre del Equipo  : " << c.getNombreEquipo() << endl;
        //cout << "Procesador         : " << c.getProcesador() << endl << endl;
    }
}

void Laboratorio::respaldarTabla() {
    ofstream archivo("computadoras_tabla.txt");
    if(archivo.is_open()) {
        archivo << left;
        archivo << setw(20) << "Sistema Operativo";
        archivo << setw(10) << "RAM (GB)";
        archivo << setw(20) << "Nombre del Equipo";
        archivo << setw(16) << "Procesador";
        archivo << endl;
        for(size_t i=0;i<computadoras.size();i++) {
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar() {
    ofstream archivo("computadoras.txt");
    if(archivo.is_open()) {
        for(size_t i=0;i<computadoras.size();i++) {
            Computadora &c = computadoras[i];
            archivo << c.getSistemaOperativo() << endl;
            archivo << c.getRam() << endl;
            archivo << c.getNombreEquipo() << endl;
            archivo << c.getProcesador() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar() {
    ifstream archivo("computadoras.txt");
    if(archivo.is_open()) {
        string tempString;
        int tempInt;
        Computadora c;

        while(true) {
            getline(archivo, tempString); // Sistema Operativo
            
            if(archivo.eof()) { // ¿Termino de leer?
                break; // cierra ciclo
            }

            c.setSistemaOperativo(tempString);

            getline(archivo, tempString); // Ram (GB)
            tempInt = stoi(tempString); // string to int -> stoi
            c.setRam(tempInt);

            getline(archivo,tempString); // Nombre del Equipo
            c.setNombreEquipo(tempString);

            getline(archivo,tempString); // Procesador
            c.setProcesador(tempString);

            agregarComputadora(c);
        }        
    }

    archivo.close();

}

void Laboratorio::inicializar(const Computadora &c, size_t n) {
    computadoras = vector<Computadora>(n,c);
}

void Laboratorio::eliminar(size_t pos) {
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordernar() {
    sort(computadoras.begin(),computadoras.end()); // ordenación: simple
}

Computadora* Laboratorio::buscar(const Computadora &c) {
    // vector<Computadora>::iterator
    auto i = find(computadoras.begin(), computadoras.end(), c); // busca posición y retorna posición
    
    if(i==computadoras.end()) { // ¿Apunta al final?
        return nullptr; // retorna posicion 0
    } else {
        return &(*i); // retornamos la direccion de memoria
    }
}

size_t Laboratorio::size() {
    return computadoras.size();
}