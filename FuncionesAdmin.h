#ifndef FUNCIONESADMIN_H
#define FUNCIONESADMIN_H

#include "Usuario.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "Administrador.h"

#include <iostream>

using namespace std;

void paginaPrincipalAdmin(ListaUsuario& listaUsuarios, ListaLibro& listaLibros, Administrador& admin);
void tablaUsuarios(ListaUsuario& lista);
string espaciar(int tamanio, int valor);
void tablaLibros(ListaLibro& lista);

#endif

void paginaPrincipalAdmin(ListaUsuario& listaUsuarios, ListaLibro& listaLibros, Administrador& admin){
	int opcion;
	int opcion2;
	int opcion3;
	string isbn;
	do{
	cout<<"listo\n";
	cout<<"Bienvenido "<<admin.nombre<<endl;

	cout<<"1. Gestionar libros\n";
	cout<<"2. Gestionar Usuarios\n";
	cout<<"3. Historial de prestamos\n";
	cout<<"4. Cerrar sesion\n";


	cout<<"Ingrese la funcion a realizar: ";
	cin>>opcion;


		switch(opcion){
			case 1:
				system("cls");
				tablaLibros(listaLibros);
				do{
				cout<<"1. Agregar Libro\n";
				cout<<"2. Seleccionar libro\n";
				cout<<"3. Elimminar libro\n";
				cout<<"4. Atras\n";
				cout<<"Selecciona una opcion: ";
				cin>>opcion3;

					switch(opcion2){
						case 1:

							//en proceso
							break;
						case 2:
							system("cls");
							tablaLibros(listaLibros);
							cin>>isbn;

							break;
						case 3:
							break;
                        case 4:
							break;
						default:
							system("cls");
							break;
					}
				}while(opcion2!=4);

				break;
			case 2:
				system("cls");
				tablaUsuarios(listaUsuarios);

				do{
				cout<<"1. Eliminar Usuario\n";
				cout<<"2. Editar Usuario\n";
				cout<<"3. Atras\n";
				cout<<"Selecciona una opcion: ";
				cin>>opcion2;

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


string espaciar(int tamanio, int valor){
	int espacio = 0;
	string texto ="";

	espacio = valor - tamanio;

	for(int i = 0;i<espacio;i++){
		texto =texto + " ";
	}
	return texto;
}

void tablaUsuarios(ListaUsuario& lista){
	system("color f9");
	NodoU* u;
	string preferencias="";

	cout<<"_________________________________________________________________________________________________________\n";
	cout<<"ID                          NOMBRES                   CORREO                       PREFERENCIAS            ";
	cout<<"_________________________________________________________________________________________________________\n";

	for(int i = 0; i<lista.getLongitud();i++){
		u =lista.encontrarUsuario(to_string(i+1));
		preferencias = "[ ";
		if(u!=nullptr){
			for(const auto p : u->usuario.preferencias){
				preferencias = preferencias + p.tipo+", ";
			}
		preferencias = preferencias + "]";
			cout<<u->usuario.id<<espaciar(2,26)<<u->usuario.nombres<<espaciar(u->usuario.nombres.size(),30)<<u->usuario.correo<<espaciar(u->usuario.correo.size(),40)<< preferencias<<"\n";
		}else{
			cout<<"no hay mas usuario";
		}

	}
	cout<<endl;

}

void tablaLibros(ListaLibro& lista){
	system("color f9");
	NodoL* actual = nullptr;
	string preferencias="";

	cout<<"_________________________________________________________________________________________________________\n";
	cout<<"ISBN               TITULO                 AÑO DE PUBLICACION                  FECHA DE ADQUISION            ";
	cout<<"_________________________________________________________________________________________________________\n";

	actual = lista.inicio;
	while(actual!=nullptr){

		cout<<actual->libro.isbn<<espaciar(2,26)<<actual->libro.titulo<<espaciar(actual->libro.titulo.size(),30)<<actual->libro.ano_publicacion<<espaciar(to_string(actual->libro.ano_publicacion).size(),40)<< actual->libro.fecha_adquisicion<<"\n";
	}

	cout<<endl;

}


