#ifndef NODOPRESTAMO_H
#define NODOPRESTAMO_H

#include "Prestamo.h"

struct NodoP {
    Prestamo prestamo;
    NodoP* anterior;
    NodoP* siguiente;

    friend ostream& operator<<(ostream& os, const NodoP& nodo) {
        os << nodo.prestamo;
        return os;
    }

    friend istream& operator>>(istream& is, NodoP& nodo) {
        is >> nodo.prestamo;
        return is;
    }
};

NodoP* agregarNodoPrestamo(Prestamo p) {
    NodoP* nuevo = new NodoP();
    nuevo->prestamo = p;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;
    return nuevo;
}

#endif
