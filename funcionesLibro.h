#ifndef FUNCIONESLIBRO_H
#define FUNCIONESLIBRO_H

#include <iostream>

using namespace std;

#include "Libro.h"
#include "ListaLibro.h"
#include "ISBNArbolDeLibros.h"

void agregarNuevoLibro(ListaLibro& listaLibros, ISBNArbolLibro& isbnArbol);
void eliminarLibro(ListaLibro& listaLibros);
void buscarLibro(ListaLibro& listaLibros);
void mostrarCategorias(ListaLibro& listaLibros);

#endif // FUNCIONESLIBRO_H

void agregarNuevoLibro(ListaLibro& listaLibros, ISBNArbolLibro& isbnArbol) {
    Libro nuevoLibro;
    cout << endl;
    cout << "Ingrese ISBN del libro: ";
    cin >> nuevoLibro.isbn;
    if (isbnArbol.buscar(nuevoLibro.isbn)) {
        cout << "Error: El ISBN ya existe en la lista." << endl;
    } else {
        cout << "Ingrese t�tulo del libro: ";
        cin >> nuevoLibro.titulo;
        cout << "Ingrese el autor: ";
        cin >> nuevoLibro.autor;
        cout << "Ingrese a�o de publicaci�n: ";
        cin >> nuevoLibro.ano_publicacion;
        cout << "Ingrese g�nero: ";
        cin >> nuevoLibro.genero;
        cout << "Ingrese editorial: ";
        cin >> nuevoLibro.editorial;
        cout << "Ingrese n�mero de p�ginas: ";
        cin >> nuevoLibro.num_paginas;
        cout << "Ingrese la descripcion: ";
        cin >> nuevoLibro.descripcion;
        cout << "Ingrese fecha de adquisicion: ";
        cin >> nuevoLibro.fecha_adquisicion;
        cout << "Ingrese el lenguaje: ";
        cin >> nuevoLibro.lenguaje;
        nuevoLibro.estado = "true";
        listaLibros.agregar(nuevoLibro);
        isbnArbol.insertar(nuevoLibro.isbn);
        cout << "Libro agregado " << endl;
        cout << endl;
    }
}

void eliminarLibro(ListaLibro& listaLibros) {
    string isbn;
    cout << endl;
    cout << "Ingrese ISBN del libro: ";
    cin >> isbn;
    listaLibros.eliminar(isbn);
    cout << "LIBRO ELIMINADO CORRECTAMENTE " << endl;
    cout << endl;
}

void buscarLibro(ListaLibro& listaLibros) {
    string isbn;
    cout << endl;
    cout << "Ingrese ISBN del libro a buscar: ";
    cin >> isbn;
    NodoL* libro = listaLibros.encontrarLibro(isbn);
    if (libro != nullptr) {
        cout << "Libro encontrado: " << endl;
        cout << "T�tulo: " << libro->libro.titulo << endl;
        cout << "Autor: " << libro->libro.autor << endl;
        cout << "A�o de publicaci�n: " << libro->libro.ano_publicacion << endl;
        cout << "G�nero: " << libro->libro.genero << endl;
        cout << "Tipo: " << libro->libro.tipo << endl;
        cout << "ISBN: " << libro->libro.isbn << endl;
        cout << "Editorial: " << libro->libro.editorial << endl;
        cout << "N�mero de p�ginas: " << libro->libro.num_paginas << endl;
        cout << "Descripci�n: " << libro->libro.descripcion << endl;
        cout << "Fecha de adquisici�n: " << libro->libro.fecha_adquisicion << endl;
        cout << "Lenguaje: " << libro->libro.lenguaje << endl;
        cout << "Estado: " << (libro->libro.estado ? "Disponible" : "No disponible") << endl;
    } else {
        cout << "Libro no encontrado." << endl;
    }
    cout << endl;
}

void mostrarCategorias(ListaLibro& listaLibros) {
    vector<string> categorias = listaLibros.obtenerCategorias();
    cout << "Categor�as disponibles:" << endl;
    for (size_t i = 0; i < categorias.size(); ++i) {
        cout << i + 1 << ". " << categorias[i] << endl;
    }
    cout << "Seleccione una categor�a: ";
    int opcionCategoria;
    cin >> opcionCategoria;
    if (opcionCategoria > 0 && opcionCategoria <= categorias.size()) {
        string categoriaSeleccionada = categorias[opcionCategoria - 1];
        vector<Libro> librosCategoria = listaLibros.filtrarPorCategoria(categoriaSeleccionada);
        cout << "Libros en la categor�a " << categoriaSeleccionada << ":" << endl;
        for (const auto& libro : librosCategoria) {
            cout << "T�tulo: " << libro.titulo << ", ISBN: " << libro.isbn << endl;
        }
    } else {
        cout << "Opci�n inv�lida." << endl;
    }
}
