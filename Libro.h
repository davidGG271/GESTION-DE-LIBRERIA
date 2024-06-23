#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <vector>

using namespace std;

struct Libro {
	string isbn;              // ISBN
    string titulo;            // Título
    string autor;             // Autor(es)
    int ano_publicacion;      // Año de publicación
    string genero;            // Género
    int num_paginas;          // Número de páginas
    string editorial;         // Editorial
    string lenguaje;          // Lenguaje
    string descripcion;       // Descripción
    string fecha_adquisicion; // Fecha de adquisición
    int stock;

    friend ostream& operator<<(ostream& os, const Libro& libro) {
        os << libro.autor << '\n'
           << libro.ano_publicacion << '\n'
           << libro.genero << '\n'
           << libro.titulo << '\n'
           << libro.isbn << '\n'
           << libro.editorial << '\n'
           << libro.num_paginas << '\n'
           << libro.descripcion << '\n'
           << libro.fecha_adquisicion << '\n'
           << libro.lenguaje << '\n'
           << libro.stock << '\n';
        return os;
    }

    friend istream& operator>>(istream& is, Libro& libro) {
        getline(is, libro.autor);
        is >> libro.ano_publicacion;
        is.ignore();
        getline(is, libro.genero);
        getline(is, libro.titulo);
        getline(is, libro.isbn);
        getline(is, libro.editorial);
        is >> libro.num_paginas;
        is.ignore();
        getline(is, libro.descripcion);
        getline(is, libro.fecha_adquisicion);
        getline(is, libro.lenguaje);
        is >> libro.stock;
        is.ignore();
        return is;
    }
};

#endif
