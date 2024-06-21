#ifndef FUNCIONINICIO_H
#define FUNCIONINICIO_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include "ListaUsuario.h"


using namespace std;

void registrarse(ListaUsuario& lista);
int asingnarIdUsuario(ListaUsuario lista);

#endif


void registrarse(ListaUsuario& listaUsuarios){
	Usuario nuevoUsuario;
    cout << endl;
    cout << "Ingrese nombre del usuario: ";
    cin >> nuevoUsuario.nombres;
   	cout << "Ingrese correo del usuario: ";
    cin >> nuevoUsuario.correo;
    cout << "Ingrese contrasenia del usuario: ";
	cin >> nuevoUsuario.contrasenia;
	
	nuevoUsuario.id = to_string(asingnarIdUsuario(listaUsuarios));
	
	listaUsuarios.agregar(nuevoUsuario);
    cout << "Usuario agregado " << endl;
    cout << endl;
}

int asingnarIdUsuario(ListaUsuario lista){
	return lista.getLongitud()+1;
}

