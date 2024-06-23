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
    vector<string> isbnLibros;
    string idUsuario;

    friend ostream& operator<<(ostream& os, const Prestamo& prestamo) {
        os << prestamo.id << '\n'
           << prestamo.fechaDevolucion << '\n'
           << prestamo.fechaSalida << '\n'
           << prestamo.isbnLibros.size() << '\n';
        for (const auto& isbnLibro : prestamo.isbnLibros) {
            os << isbnLibro << '\n';
        }
        os << prestamo.idUsuario;
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
        prestamo.isbnLibros.resize(librosSize);
        for (auto& isbnLibro : prestamo.isbnLibros) {
            is >> isbnLibro;
            is.ignore();
        }
        is >> prestamo.idUsuario;
        return is;
    }
};

#endif
