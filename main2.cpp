#include "Libro.h"
#include "Usuario.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "NodoLibro.h"
#include "ArbolUsuario.h"
#include "ISBNArbolDeLibros.h"

#include "FuncionesAdmin.h"
#include "FuncionInicio.h"
#include "FuncionesUsuario.h"
#include "Administrador.h"


#include <string>

#include <iostream>

using namespace std;




void mostrarInicio();
void inicioSesion();
void adminIniciarSesion();
void usuarioIniciarSesion();

Administrador admin;
ListaUsuario listaUsuario;
ListaLibro listaLibro;

ArbolUsuario arbolUsuario;
ISBNArbolLibro arbolLibrosIsbn;


int main(){


	arbolUsuario.cargarUsuarios();
	//arbolUsuario.imprimir();
	cout<<"\n";
	cout<<"altura: "<<arbolUsuario.getAltura();
	arbolUsuario.reinsertarBalanceado();
	cout<<"\naltura: "<<arbolUsuario.getAltura();

	cout<<"\nantes de la carga";
	arbolLibrosIsbn.cargarLibros();
	//cout<<"-----------------a";
	arbolLibrosIsbn.imprimir();
	arbolLibrosIsbn.reinsertarBalanceado();


	admin.id = 1;
	admin.nombre = "henry";
	admin.correo = "henry";
	admin.contrasenia = "abc";

	mostrarInicio();

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
    cout << "Seleccione una opci n: ";

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
                cout << "Opci n no v lida, intente nuevamente.\n";
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
	cout<<"Ingrese su contrase a: ";
	cin>>contrasenia;

	if(admin.correo == correo && admin.contrasenia == contrasenia){
		system("cls");
		paginaPrincipalAdmin(arbolUsuario, arbolLibrosIsbn, admin);
		return;
	}
	system("cls");
	adminIniciarSesion();
}


void usuarioIniciarSesion(){
	string correo = "";
	string contrasenia = "";
	NodoArbolUsuario* encontrado = nullptr;

	cout<<"Ingese su correo: ";
	cin>>correo;
	if(correo=="-1"){
		return;
	}
	cout<<"Ingrese su contrase a: ";
	cin>>contrasenia;

	encontrado = arbolUsuario.verificarInicioSesion(correo, contrasenia);
	if(encontrado!=nullptr){
		system("cls");
		paginaPrincipalUsu(encontrado->usuario, arbolLibrosIsbn);
		return;
	}
	system("cls");

}
