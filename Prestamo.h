#ifndef Prestamo_h
#define Prestamo_h

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
};

#endif