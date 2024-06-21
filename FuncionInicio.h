#ifndef FUNCIONINICIO_H
#define FUNCIONINICIO_H

#include <iostream>
#include "Usuario.h"
#include "ListaUsuario.h"

using namespace std;

void registrarse(ListaUsuario lista);
int asingnarIdUsuario(ListaUsuario lista);

#endif


void registrarse(ListaUsuario& listaUsuarios){
	Usuario nuevoUsuario;
    cout << endl;
    cout << "Ingrese ID del usuario: ";
    cin >> nuevoUsuario.id;
    cout << "Ingrese nombre del usuario: ";
    cin >> nuevoUsuario.nombres;
   	cout << "Ingrese correo del usuario: ";
    cin >> nuevoUsuario.correo;
    cout << "Ingrese contrasenia del usuario: ";
	cin >> nuevoUsuario.contrasenia;
	
    NodoU* nodoNuevo = agregarNodoUsuario(nuevoUsuario);
	listaUsuarios.agregar(nodoNuevo);
    cout << "Usuario agregado " << endl;
    cout << endl;
}

int asingnarIdUsuario(ListaUsuario lista){
	return lista.getLongitud()+1;
}

