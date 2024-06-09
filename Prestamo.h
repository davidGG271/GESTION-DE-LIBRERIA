#ifndef Prestamo_h
#define Prestamo_h

#include <Libro_h>
#include <vector>
#include <iostream>

using namespace std;

Struct Prestamo {
	string id;
	string fechaDevolucion;
	string fechaSalida;
	vector<Libro> libros;
	string IdUsuario; //cambiar struct persona
}

#endif
