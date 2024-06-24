#ifndef FUNCIONINICIO_H
#define FUNCIONINICIO_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include <limits>
#include "ArbolUsuario.h"
#include "Cifrado.h"

#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

void registrarse(ArbolUsuario& lista);
int asingnarIdUsuario(ArbolUsuario lista);
string generateID();
#endif


void registrarse(ArbolUsuario& listaUsuarios){
    Usuario nuevoUsuario;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nombre del usuario: ";
    getline(cin, nuevoUsuario.nombres);

    cout << "Ingrese correo del usuario: ";
    getline(cin, nuevoUsuario.correo);

    cout << "Ingrese contrasenia del usuario: ";
    string contrasenia;
    getline(cin, contrasenia);

    nuevoUsuario.contrasenia = cifrarContrasena(contrasenia); // Cifrar la contrase�a antes de guardarla

    nuevoUsuario.id = generateID();

    listaUsuarios.agregar(nuevoUsuario);
    cout << "Usuario agregado" << endl;
    system("pause");
    system("cls");
}

string generateID() {
 auto now = std::chrono::system_clock::now();
    auto milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    // Convertir el tiempo en milisegundos a un string
    std::stringstream ss;
    ss << milliseconds_since_epoch;

    return ss.str();
}