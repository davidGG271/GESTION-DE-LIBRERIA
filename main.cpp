#include "Libro.h"
#include "Usuario.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "NodoLibro.h"
#include "ArbolUsuario.h"
#include "ISBNArbolDeLibros.h"
#include "PrestamoArbol.h"

#include "FuncionesAdmin.h"
#include "FuncionInicio.h"
#include "FuncionesUsuario.h"
#include "Administrador.h"
#include "Cifrado.h"

#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

void mostrarInicio();
void inicioSesion();
void adminIniciarSesion();
void usuarioIniciarSesion();
string inputPassword(const string& prompt);
void registrarse(ArbolUsuario& arbolUsuario);

Administrador admin;
ListaUsuario listaUsuario;
ListaLibro listaLibro;

ArbolUsuario arbolUsuario;
ISBNArbolLibro arbolLibrosIsbn;
PrestamoArbol arbolPrestamo;

int main(){


	arbolUsuario.cargarUsuarios();
	arbolUsuario.reinsertarBalanceado();

	arbolPrestamo.cargarPrestamos();
	arbolPrestamo.reinsertarBalanceado();

	arbolLibrosIsbn.cargarLibros();
	arbolLibrosIsbn.reinsertarBalanceado();

	//Datos administrador
	admin.id = 1;
	admin.nombre = "henry";
	admin.correo = "henry";
	admin.contrasenia = "abc";

	mostrarInicio();

}

string inputPassword(const string& prompt) {
    cout << prompt;
    string contra;
    char caracter;
    caracter = _getch();
    while(caracter != 13) { // 13 es el c�digo ASCII de Enter
        if (caracter != 8) { // 8 es el c�digo ASCII de Backspace
            contra.push_back(caracter);
            cout << "*";
        } else {
            if (!contra.empty()) {
                cout << "\b \b"; // Borra el �ltimo asterisco
                contra.pop_back();
            }
        }
        caracter = _getch();
    }
    cout << endl;
    return contra;
}


void mostrarInicio(){
	int opcion;
	do{
	cout << "\nBienvenido a la Biblioteca\n";
    cout << "1. Iniciar Sesion\n";
    cout << "2. Registrarse\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opci n: ";

    cin >> opcion;

    	switch (opcion) {
            case 1:
            	system("cls");
                inicioSesion();
                break;
            case 2:
                registrarse(arbolUsuario);
                break;
            case 3:
                cout << "Saliendo...\n";
                arbolUsuario.guardarUsuarios();
                arbolLibrosIsbn.guardarLibros();
				arbolPrestamo.guardarPrestamos();
                break;
            default:
                cout << "Opcion no valida, intente nuevamente.\n";
                break;
        }
    } while (opcion != 3);

}

void inicioSesion(){
    int opcion;
	do{
	cout << "\nElegir tipo de usuario\n";
    cout << "1. Administrador\n";
    cout << "2. Usuario\n";
    cout << "3. Atras\n";
    cout << "Seleccione una opcion: ";

    cin >> opcion;

    	switch (opcion) {
            case 1:
            	system("cls");
                adminIniciarSesion();
                break;
            case 2:
                usuarioIniciarSesion();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida, intente nuevamente.\n";
                break;
        }
    } while (opcion != 3);

}


void adminIniciarSesion(){
	string correo = "";

	string contrasenia = "";
	cout<<"Ingese su correo: ";
	cin>>correo;
	if(correo=="-1"){
		return;
	}
	cout<<"Ingrese su contrasena: ";
	cin>>contrasenia;

	if(admin.correo == correo && admin.contrasenia == contrasenia){
		system("cls");
		paginaPrincipalAdmin(arbolUsuario, arbolLibrosIsbn, arbolPrestamo, admin);
		return;
	}
	system("cls");
	adminIniciarSesion();
}


void usuarioIniciarSesion(){
	string correo = "";
    string contrasenia = "";
    NodoArbolUsuario* encontrado = nullptr;

    cout << "Ingrese su correo: ";
    cin >> correo;
    if (correo == "-1") {
        return;
    }
    contrasenia = inputPassword("Ingrese su contrase�a: ");

    string contraseniaCifrada = cifrarContrasena(contrasenia); // Cifrar la contrase�a ingresada una sola vez
    cout << "Contrase�a ingresada cifrada: " << contraseniaCifrada << endl; // Mensaje de depuraci�n

    encontrado = arbolUsuario.verificarInicioSesion(correo, contraseniaCifrada);
    if (encontrado != nullptr) {
        system("cls");
        paginaPrincipalUsu(encontrado->usuario, arbolLibrosIsbn, arbolPrestamo);
        return;
    } else {
        cout << "Inicio de sesi�n fallido. Correo o contrase�a incorrectos." << endl;
    }
    system("pause");

}
