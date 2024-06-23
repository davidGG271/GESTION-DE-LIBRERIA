#ifndef FUNCIONESADMIN_H
#define FUNCIONESADMIN_H

#include "Usuario.h"
#include "ListaUsuario.h"
#include "Administrador.h"

#include <iostream>

using namespace std;

void paginaPrincipalAdmin(ListaUsuario &listaUsuarios, Administrador &admin);
void tabla(ListaUsuario &lista);
string espaciar(int tamanio, int valor);

void paginaPrincipalAdmin(ListaUsuario &listaUsuarios, Administrador &admin, ArbolUsuario &arbolUsuario)
{
	int opcion;
	int opcion2;
	Usuario nuevoUsuario;
	do
	{
		cout << "listo\n";
		cout << "Bienvenido " << admin.nombre << endl;

		cout << "1. Gestionar libros\n";
		cout << "2. Gestionar Usuarios\n";
		cout << "3. Historial de prestamos\n";
		cout << "4. Cerrar sesion\n";

		cout << "Ingrese la funcion a realizar: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:

			break;
		case 2:
			system("cls");
			tabla(listaUsuarios);

			do
			{
				cout << "1. Agregar Usuario\n";
				cout << "2. Editar Usuario\n";
				cout << "3. Atras\n";
				cout << "Selecciona una opcion: ";
				cin >> opcion2;

				switch (opcion2)
				{
				case 1:
					
					cout << endl;
					cout << "Ingrese ID del usuario: ";
					cin >> nuevoUsuario.id;
					cout << "Ingrese nombre del usuario: ";
					cin >> nuevoUsuario.nombres;
					cout << "Ingrese correo del usuario: ";
					cin >> nuevoUsuario.correo;
					cout << "Ingrese contrasenia del usuario: ";
					cin >> nuevoUsuario.contrasenia;

					arbolUsuario.agregar(nuevoUsuario);
					cout << "Usuario agregado " << endl;
					cout << endl;
					break;
				case 2:
					// en proceso
					break;
				case 3:
					break;
					/*default:
						system("cls");
						break;*/
				}
			} while (opcion2 != 3);

			break;
		case 3:
			break;
		case 4:
			cout << "Saliendo...\n";
			system("cls");
			break;
		default:
			cout << "Opci�n no v�lida, intente nuevamente.\n";
			break;
		}

	} while (opcion != 4);
}

string espaciar(int tamanio, int valor)
{
	int espacio = 0;
	string texto = "";

	espacio = valor - tamanio;

	for (int i = 0; i < espacio; i++)
	{
		texto = texto + " ";
	}
	return texto;
}

void tabla(ListaUsuario &lista)
{
	system("color f9");
	NodoU *u;
	string preferencias = "";

	cout << "_________________________________________________________________________________________________________\n";
	cout << "ID                          NOMBRES                   CORREO                       PREFERENCIAS            ";
	cout << "_________________________________________________________________________________________________________\n";

	for (int i = 0; i < lista.getLongitud(); i++)
	{
		u = lista.encontrarUsuario(to_string(i + 1));
		preferencias = "[ ";
		if (u != nullptr)
		{
			for (const auto p : u->usuario.preferencias)
			{
				preferencias = preferencias + p.tipo + ", ";
			}
			preferencias = preferencias + "]";
			cout << u->usuario.id << espaciar(2, 26) << u->usuario.nombres << espaciar(u->usuario.nombres.size(), 30) << u->usuario.correo << espaciar(u->usuario.correo.size(), 40) << preferencias << "\n";
		}
		else
		{
			cout << "no hay mas usuario";
		}
	}
	cout << endl;
}

#endif