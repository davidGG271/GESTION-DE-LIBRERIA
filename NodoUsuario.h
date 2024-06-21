#ifndef NODOUSU_H
#define NODOUSU_H

#include <iostream>
#include "Usuario.h"

struct NodoU {
	Usuario usuario;
	NodoU* anterior;
	NodoU* siguente;

	NodoU(const Usuario& usuario) : usuario(usuario), anterior(nullptr), siguente(nullptr) {}


	friend ostream& operator<<(ostream& os, const NodoU& nodo) {
        os << nodo.usuario;
        return os;
    }

    friend istream& operator>>(istream& is, NodoU& nodo) {
        is >> nodo.usuario;
        return is;
    }
};

#endif
