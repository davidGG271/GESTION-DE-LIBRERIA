#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <iostream>
#include <string>
#include "Libro.h"

using namespace std;

struct Preferencia {
    string tipo;
    int contador;
};

struct Usuario{
    string id;
	string nombres;
	string correo;
	string contrasenia;
	vector<Preferencia> preferencias;
    vector<Libro> librosSeleccionados;

	 friend ostream& operator<<(ostream& os, const Usuario& usuario) {
        os << usuario.id << '\n'
           << usuario.nombres << '\n'
           << usuario.correo << '\n'
           << usuario.contrasenia << '\n';
        os << usuario.librosSeleccionados.size() << '\n'; // Guardar el tamaño del vector de libros
        for (const auto& libro : usuario.librosSeleccionados) {
            os << libro; // Suponiendo que Libro tiene sobrecargado el operador <<
        }
        return os;
    }

    friend istream& operator>>(istream& is, Usuario& usuario) {
        getline(is, usuario.id);
        getline(is, usuario.nombres);
        getline(is, usuario.correo);
        getline(is, usuario.contrasenia);
        size_t librosSize;
        is >> librosSize;
        is.ignore(); // Para ignorar el salto de línea después del tamaño
        usuario.librosSeleccionados.resize(librosSize);
        for (auto& libro : usuario.librosSeleccionados) {
            is >> libro; // Suponiendo que Libro tiene sobrecargado el operador >>
        }
        return is;
    }
};

#endif
