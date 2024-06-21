#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <vector>

using namespace std;

struct Libro {
    string autor;             // Autor(es)
    int ano_publicacion;      // Año de publicación
    string genero;            // Género
    string tipo;              // Tipo (por ejemplo, tapa dura, tapa blanda, ebook, etc.)
    string titulo;            // Título
    string isbn;              // ISBN
    string editorial;         // Editorial
    int num_paginas;          // Número de páginas
    string descripcion;       // Descripción
    string fecha_adquisicion; // Fecha de adquisición
    string lenguaje;          // Lenguaje
    bool estado;

    friend ostream& operator<<(ostream& os, const Libro& libro) {
        os << libro.autor << '\n'
           << libro.ano_publicacion << '\n'
           << libro.genero << '\n'
           << libro.tipo << '\n'
           << libro.titulo << '\n'
           << libro.isbn << '\n'
           << libro.editorial << '\n'
           << libro.num_paginas << '\n'
           << libro.descripcion << '\n'
           << libro.fecha_adquisicion << '\n'
           << libro.lenguaje << '\n'
           << libro.estado << '\n';
        return os;
    }

    friend istream& operator>>(istream& is, Libro& libro) {
        getline(is, libro.autor);
        is >> libro.ano_publicacion;
        is.ignore();
        getline(is, libro.genero);
        getline(is, libro.tipo);
        getline(is, libro.titulo);
        getline(is, libro.isbn);
        getline(is, libro.editorial);
        is >> libro.num_paginas;
        is.ignore();
        getline(is, libro.descripcion);
        getline(is, libro.fecha_adquisicion);
        getline(is, libro.lenguaje);
        is >> libro.estado;
        is.ignore();
        return is;
    }
};

#endif
