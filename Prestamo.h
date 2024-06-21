#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Libro.h"
#include "Usuario.h"
#include <vector>
#include <iostream>

using namespace std;

struct Prestamo {
    string id;
    string fechaDevolucion;
    string fechaSalida;
    vector<Libro> libros;
    Usuario usuario;

    friend ostream& operator<<(ostream& os, const Prestamo& prestamo) {
        os << prestamo.id << '\n'
           << prestamo.fechaDevolucion << '\n'
           << prestamo.fechaSalida << '\n'
           << prestamo.libros.size() << '\n';
        for (const auto& libro : prestamo.libros) {
            os << libro << '\n';
        }
        os << prestamo.usuario;
        return os;
    }

    friend istream& operator>>(istream& is, Prestamo& prestamo) {
        size_t librosSize;
        is >> prestamo.id;
        is.ignore(); // To consume the newline character after id
        is >> prestamo.fechaDevolucion;
        is.ignore();
        is >> prestamo.fechaSalida;
        is.ignore();
        is >> librosSize;
        is.ignore();
        prestamo.libros.resize(librosSize);
        for (auto& libro : prestamo.libros) {
            is >> libro;
            is.ignore();
        }
        is >> prestamo.usuario;
        return is;
    }
};

#endif
