#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <iostream
#include <string>

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

	 friend ostream& operator<<(ostream& os, const Usuario& usuario) {
        os << usuario.id << '\n'
           << usuario.nombres << '\n'
           << usuario.correo << '\n'
           << usuario.contrasenia << '\n';
        return os;
    }

    friend istream& operator>>(istream& is, Usuario& usuario) {
        getline(is, usuario.id);
        getline(is, usuario.nombres);
        getline(is, usuario.correo);
        getline(is, usuario.contrasenia);
        return is;
    }
};

#endif
