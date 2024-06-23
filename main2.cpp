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

	listaUsuario.cargarUsuarios();
	listaUsuario.imprimir();
	cout<<"\n";
	NodoU* actual = listaUsuario.inicio;
	while(actual!=nullptr){
		arbolUsuario.agregar(actual->usuario);
		actual= actual->siguiente;
	}*/
	arbolUsuario.cargarUsuarios();
	arbolUsuario.imprimir();
	cout<<"\n";
	cout<<"altura: "<<arbolUsuario.getAltura();
	arbolUsuario.reinsertarBalanceado();
	cout<<"\naltura: "<<arbolUsuario.getAltura();
	listaUsuario.sobreescribir(arbolUsuario.getListaOrdenada());


	//vector<>

	/*
	Usuario u1;
	Usuario u2;
	Usuario u3;

	NodoU n1;
	NodoU n2;
	NodoU n3;

	u1.id= "1";
	u1.nombres = "henry huaman";
	u1.correo = "henry@hotmail.com";
	u1.contrasenia = "123";

	u2.id = "5";
	u2.nombres = "felipe lopez";
	u2.correo = "felipe@hotmail.com";
	u2.contrasenia = "124";

	u3.id = "3";
	u3.nombres = "miguel perez";
	u3.correo = "miguel@hotmail.com";
	u3.contrasenia = "125";

	n1.usuario =u1;
	n2.usuario =u2;
	n3.usuario =u3;

	arbol.agregar(u1);
	arbol.agregar(u3);
	arbol.agregar(u2);



	arbol.imprimir();
	*/

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
    cout << "1. Iniciar Sesi n\n";
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
                break;
            default:
                cout << "Opci n no v lida, intente nuevamente.\n";
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
		paginaPrincipalAdmin(listaUsuario, listaLibro, admin, arbolUsuario);
		return;
	}
	system("cls");
	adminIniciarSesion();
}


void usuarioIniciarSesion(){
	string correo = "";
	string contrasenia = "";
	NodoU* encontrado = nullptr;

	cout<<"Ingese su correo: ";
	cin>>correo;
	if(correo=="-1"){
		return;
	}
	cout<<"Ingrese su contrase a: ";
	cin>>contrasenia;

	encontrado = listaUsuario.buscarPorInicio(correo, contrasenia);
	if(encontrado!=nullptr){
		system("cls");
		paginaPrincipalUsu(encontrado->usuario);
		return;
	}
	system("cls");

}
