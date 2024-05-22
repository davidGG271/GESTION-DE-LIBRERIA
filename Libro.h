#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <vector>

using namespace std;

struct Libro {
    vector<string> autor;             // Autor(es)
    int ano_publicacion;              // A�o de publicaci�n
    vector<string> genero;            // G�nero
    string tipo;              // Tipo (por ejemplo, tapa dura, tapa blanda, ebook, etc.)
    string titulo;            // T�tulo
    string isbn;              // ISBN
    string editorial;         // Editorial
    int num_paginas;                  // N�mero de p�ginas
    string descripcion;       // Descripci�n
    string fecha_adquisicion; // Fecha de adquisici�n
    vector<string> lenguaje;          // Lenguaje
    bool estado;
};


#endif
