#ifndef NODOLIBRO_H
#define NODOLIBRO_H

#include "Libro.h"

struct NodoL {
    Libro libro;
    NodoL* anterior;
    NodoL* siguiente;

    friend ostream& operator<<(ostream& os, const NodoL& nodo) {
        os << nodo.libro;
        return os;
    }

    friend istream& operator>>(istream& is, NodoL& nodo) {
        is >> nodo.libro;
        return is;
    }
};


#endif
