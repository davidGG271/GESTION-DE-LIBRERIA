#ifndef FUNCIONESADMIN_H
#define FUNCIONESADMIN_H

#include "Usuario.h"
#include "ListaUsuario.h"
#include "Administrador.h"

#include <iostream>

using namespace std;

void paginaPrincipalAdmin(ListaUsuario& listaUsuarios, Administrador& admin);

#endif

void paginaPrincipalAdmin(ListaUsuario& listaUsuarios, Administrador& admin){
	cout<<"listo\n";
	cout<<"Bienvenido "<<admin.nombre<<endl;
	
	cout<<"1. Gestionar libros\n";
	cout<<"2. Gestionar Usuarios\n";
	cout<<"3. Historial de prestamos\n";
	cout<<"4. Cerrar sesion\n";
	
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
				system("cls");
				break;
			default:
				cout<<"Opción no válida, intente nuevamente.\n";
				break;
		}
		
	}while(opcion!=4);
	
}

