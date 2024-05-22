#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <vector>

using namespace std;

struct Libro {
    vector<string> autor;             // Autor(es)
    int ano_publicacion;              // Año de publicación
    vector<string> genero;            // Género
    string tipo;              // Tipo (por ejemplo, tapa dura, tapa blanda, ebook, etc.)
    string titulo;            // Título
    string isbn;              // ISBN
    string editorial;         // Editorial
    int num_paginas;                  // Número de páginas
    string descripcion;       // Descripción
    string fecha_adquisicion; // Fecha de adquisición
    vector<string> lenguaje;          // Lenguaje
    bool estado;
};


#endif
