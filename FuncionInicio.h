#ifndef FUNCIONINICIO_H
#define FUNCIONINICIO_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include "ListaUsuario.h"
#include <limits>
#include "ArbolUsuario.h"

using namespace std;

void registrarse(ArbolUsuario& lista);
int asingnarIdUsuario(ArbolUsuario lista);

#endif


void registrarse(ArbolUsuario& listaUsuarios){
	Usuario nuevoUsuario;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Ingrese nombre del usuario: ";
    getline(cin, nuevoUsuario.nombres);

    cout << "Ingrese correo del usuario: ";
    getline(cin, nuevoUsuario.correo);

    cout << "Ingrese contrasenia del usuario: ";
    getline(cin, nuevoUsuario.contrasenia);

	nuevoUsuario.id = to_string(asingnarIdUsuario(listaUsuarios));

	listaUsuarios.agregar(nuevoUsuario);
    cout << "Usuario agregado " << endl;
    //listaUsuarios.guardarUsuarios();
    cout << endl;
}

int asingnarIdUsuario(ArbolUsuario lista){
	return lista.getLongitud() + 1;
}



