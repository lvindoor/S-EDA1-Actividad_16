#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Laboratorio {
    vector<Computadora> computadoras; // creamos un vector de computadoras
public:
    Laboratorio();
    void agregarComputadora(const Computadora &c);
    void insertar(const Computadora &c, size_t pos);
    void mostrar();
    void respaldar();
    void respaldarTabla();
    void recuperar();
    void inicializar(const Computadora &c, size_t n);
    void eliminar(size_t pos);
    void ordernar();

    /* Metodos de busqueda */
    Computadora* buscar(const Computadora &c);

    /* Tamaño */
    size_t size();

    /* Entrada | Asignación */
    friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c) {
        l.agregarComputadora(c);
        return l;
    }
};

#endif