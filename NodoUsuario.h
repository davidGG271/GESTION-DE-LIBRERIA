#ifndef NODOUSU_H
#define NODOUSU_H

#include <iostream>
#include "Usuario.h"

struct NodoU {
	Usuario usuario;
	NodoU* anterior;
	NodoU* siguente;
};

NodoU* agregarNodoUsuario(Usuario u){
	NodoU* nuevo = new NodoU();
	nuevo->usuario = u;
	nuevo->siguente = nullptr;
	nuevo->anterior = nullptr;
	
	return nuevo;
}

#endif
