#include <iostream>
#include "Prestamo.h"

struct NodoP{
    Prestamo prestamo;
    NodoP* anterior;
    NodoP* siguiente;
};

NodoP* agregarNodoPrestamo(Prestamo p){
    NodoP* nuevo = new NodoP();
    nuevo->prestamo = p;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;

    return nuevo;
}