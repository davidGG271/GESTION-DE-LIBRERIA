#ifndef FUNCIONINICIO_H
#define FUNCIONINICIO_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include "ListaUsuario.h"
#include <limits>
#include "ArbolUsuario.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

void registrarse(ArbolUsuario& lista);
int asingnarIdUsuario(ArbolUsuario lista);
string generateID();
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

	nuevoUsuario.id = generateID();

	listaUsuarios.agregar(nuevoUsuario);
    cout << "Usuario agregado " << endl;
    //listaUsuarios.guardarUsuarios();
    cout << endl;
}

int asingnarIdUsuario(ArbolUsuario lista){
	return lista.getLongitud() + 1;
}


string generateID() {
    // Obtener la fecha y hora actual hasta milisegundos
    auto now = chrono::system_clock::now();
    auto millis = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
    time_t now_time = chrono::system_clock::to_time_t(now);

    // Obtener la estructura tm local usando localtime_r o localtime según el entorno
    tm buf;
#ifdef _WIN32
    localtime_s(&buf, &now_time);  // En Windows
#else
    localtime_r(&now_time, &buf);  // En sistemas POSIX-compatibles
#endif

    // Convertir a una cadena en el formato YYYYMMDDHHMMSSmmm
    stringstream ss;
    ss << put_time(&buf, "%Y%m%d%H%M%S") << setw(3) << setfill('0') << millis.count();

    return ss.str();
}


