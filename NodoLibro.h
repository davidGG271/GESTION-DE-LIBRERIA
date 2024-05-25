#ifndef NODOLIBRO_H
#define NODOLIBRO_H

#include "Libro.h"

struct NodoL {
    Libro libro;
    NodoL* anterior;
    NodoL* siguiente;
};

NodoL* agregarNodoLibro(Libro l) {
    NodoL* nuevo = new NodoL();
    nuevo->libro = l;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;
    return nuevo;
}

#endif
