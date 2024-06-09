#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <iostream>

using namespace std;

struct Preferencia {
    string tipo;
    int contador;
};

struct Usuario{
	string usuario;
	string nombres;
	string id;
	string correo;
	string contrasenia;
	vector<Preferencia> preferencias;
};

#endif
