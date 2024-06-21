#include "Libro.h"
#include "Usuario.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "NodoLibro.h"
#include "ArbolUsuario.h"

#include "Administrador.h"
//#include "Li"


#include <iostream>

using namespace std;




void mostrarInicio();
void inicioSesion();
void registrarse();
int adminIniciarSesion();
int paginaPrincipalAdmin(Administrador admin);
int usuarioIniciarSesion();

Administrador admin;
ListaUsuario listaUsuario;

ArbolUsuario arbol;


int main(){

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
	admin.correo = "henryhuaman@hotmail.com";
	admin.contrasenia = "abc";
	
	mostrarInicio();
	
}

void mostrarInicio(){
	cout << "\nBienvenido a la Biblioteca\n";
    cout << "1. Iniciar Sesión\n";
    cout << "2. Registrarse\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
    int opcion;
    cin >> opcion;
    do{
    	switch (opcion) {
            case 1:
            	system("cls");
                inicioSesion();
                break;
            case 2:
                registrarse();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion != 3);
    	
}

void inicioSesion(){
	cout << "\nElegir tipo de usuario\n";
    cout << "1. Administrador\n";
    cout << "2. Usuario\n";
    cout << "3. Atras\n";
    cout << "Seleccione una opción: "	;
    bool b = true;
    int opcion;
    cin >> opcion;
    do{
    	switch (opcion) {
            case 1:
            	system("cls");
                opcion = adminIniciarSesion();
				
                break;
            case 2:
                usuarioIniciarSesion();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
                break;
        }
    } while (opcion != 3);
    
}

void registrarse(){

}


int adminIniciarSesion(){
	string correo = "";
	
	string contrasenia = "";
	cout<<"Ingese su correo: ";
	cin>>correo;
	if(correo=="-1"){
		return 3;
	}
	cout<<"Ingrese su contraseña: ";
	cin>>contrasenia;
	
	if(admin.correo == correo && admin.contrasenia == contrasenia){
		system("cls");
		paginaPrincipalAdmin(admin);
		return 1;
	}else{
		return 1;
	}
}

int paginaPrincipalAdmin(Administrador admin){
	cout<<"listo\n";
	cout<<"Bienvenido "<<admin.nombre<<endl;
	
	cout<<"1. Gestionar libros\n";
	cout<<"2. Gestionar Usuarios\n";
	cout<<"3. Historial de prestamos\n";
	
	int opcion;
	int opcion2;
	cout<<"Ingrese la funcion a realizar: ";
	cin>>opcion;
	
	do{
		switch(opcion){
			case 1:
				
				
				break;
			case 2:
				system("cls");
				
				cout<<"1. Ordenar alfabeticamente\n";
				cout<<"2. Ordenar por fecha de registro\n";
				cout<<"3. Atras\n";
				cout<<"Selecciona una opcion: ";
				cin>>opcion2;
				do{
					switch(opcion2){
						case 1:
							//en proceso
							break;
						case 2:
							//en proceso
							break;	
						case 3:
							break;
						default:
							system("cls");
							break;
					}
				}while(opcion2!=3);
				
				break;
			case 3:
				break;
			case 4:
				cout << "Saliendo...\n";
				break;
			default:
				cout<<"Opción no válida, intente nuevamente.\n";
				break;
		}
		
	}while(opcion!=4);
	
}

int usuarioIniciarSesion(){
	string correo = "";
	string contrasenia = "";
	
	cout<<"Ingese su correo: ";
	cin>>correo;
	if(correo=="-1"){
		return 3;
	}
	cout<<"Ingrese su contraseña: ";
	cin>>contrasenia;
	
	//falta
	
}


