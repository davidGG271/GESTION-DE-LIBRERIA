#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "Usuario.h"
#include "Libro.h"
#include "ListaLibro.h"
#include<list>
#include<vector>
#include <iostream>

struct Hash{
	vector<list<Libro>> librosPreferencia;
};


int asignarHash(Usuario usuario, string tipo){
	
	for(const auto& pref : usuario.preferencias){
			if(pref.tipo==tipo){
				return pref.contador;
			}
	}
	return -1;
}


void agregarLibro(Hash& hashing, Libro libro, Usuario usuario){
	
	for(const auto& libroGenero : libro.genero){
		int contador = asignarHash(usuario, libroGenero);
	    // Aseguramos que la lista de libros en la preferencia especificada esté inicializada
	    if (contador >= hashing.librosPreferencia.size()) {
	        hashing.librosPreferencia.resize(contador + 1);
	    }
	    // Agregamos el libro a la lista de libros en la preferencia
	    hashing.librosPreferencia[contador].push_back(libro);
	}
	
}


#endif
