#ifndef FUNCIONESADMIN_H
#define FUNCIONESADMIN_H

#include "Usuario.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "Administrador.h"


#include "ISBNArbolDeLibros.h"
#include "ArbolUsuario.h"

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

void paginaPrincipalAdmin(ArbolUsuario& arbolUsuarios, ISBNArbolLibro& arbolLibros, Administrador& admin);
void agregarLibro(ISBNArbolLibro& arbolLibros);
void eliminarLibro(ISBNArbolLibro& arbolLibros);
void tablaUsuarios(ArbolUsuario& arbol);
string espaciar(int tamanio, int valor);
void tablaLibros(ISBNArbolLibro& lista);
string obtenerFechaActual();

#endif

void paginaPrincipalAdmin(ArbolUsuario& arbolUsuarios, ISBNArbolLibro& arbolLibros, Administrador& admin){
        int opcion;
        int opcion2;
        int opcion3;

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
				do{
                    tablaLibros(arbolLibros);
					cout<<"1. Agregar Libro\n";
					cout<<"2. Seleccionar libro\n";
					cout<<"3. Eliminar libro\n";
					cout<<"4. Atras\n";
					cout<<"Selecciona una opcion: ";
					cin>>opcion2;

					switch(opcion2){
						case 1:
						    system("cls");
						    agregarLibro(arbolLibros);

							//en proceso
							break;
						case 2:
							system("cls");
							tablaLibros(arbolLibros);
							//cin>>isbn;
							//en espera

							break;
						case 3:
						    system("cls");
						    tablaLibros(arbolLibros);
						    eliminarLibro(arbolLibros);
						    system("cls");
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
				tablaUsuarios(arbolUsuarios);

				do{
				cout<<"1. Eliminar Usuario\n";
				cout<<"2. Editar Usuario\n";
				cout<<"3. Atras\n";
				cout<<"Selecciona una opcion: ";
				cin>>opcion3;

					switch(opcion3){
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
				}while(opcion3!=3);

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

void agregarLibro(ISBNArbolLibro& arbolLibros){
    Libro libro;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Ingrese isbn";
    getline(cin, libro.isbn);
    cout << "Ingrese Título: ";
    getline(cin, libro.titulo);
    cout << "Ingrese Autor: ";
    getline(cin, libro.autor);
    cout << "Ingrese Año de Publicación: ";
    cin >> libro.ano_publicacion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Ingrese Género: ";
    getline(cin, libro.genero);
    cout << "Ingrese Número de Páginas: ";
    cin >> libro.num_paginas;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Ingrese Editorial: ";
    getline(cin, libro.editorial);
    cout << "Ingrese Lenguaje: ";
    getline(cin, libro.lenguaje);
    cout << "Ingrese Descripción: ";
    getline(cin, libro.descripcion);
    cout << "Ingrese el stock de copias: ";
    cin >> libro.stock;
    libro.fecha_adquisicion = obtenerFechaActual();
    arbolLibros.insertar(libro);
}

void eliminarLibro(ISBNArbolLibro& arbolLibros){
    string isbn;
    cout<<"2. Seleccionar libro a eliminar por isbn\n";
    cin>>isbn;
    arbolLibros.eliminar(isbn);
}

string obtenerFechaActual() {
    time_t tiempoActual = time(nullptr);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&tiempoActual));
    return string(buffer);
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

void tablaUsuarios(ArbolUsuario& arbol) {
    system("color f9");
    vector<Usuario> usuarios = arbol.getListaOrdenada();

    cout << "_______________________________________________________________________________________________________________\n";
    cout << "ID              NOMBRES                  CORREO                        PREFERENCIAS\n";
    cout << "_______________________________________________________________________________________________________________\n";

    // Verificar si hay usuarios para mostrar
    if (usuarios.empty()) {
        cout << "No hay usuarios registrados.\n";
    } else {
        // Iterar sobre cada usuario en el vector
        for (const auto& usuario : usuarios) {
            string preferencias = "[ ";

            // Construir la lista de preferencias
            for (size_t i = 0; i < usuario.preferencias.size(); ++i) {
                preferencias += usuario.preferencias[i].tipo;
                if (i != usuario.preferencias.size() - 1) {
                    preferencias += ", ";
                }
            }
            preferencias += " ]";

            // Imprimir cada usuario con sus detalles
            cout << usuario.id << espaciar(2, 16)
                 << usuario.nombres << espaciar(usuario.nombres.size(), 26)
                 << usuario.correo << espaciar(usuario.correo.size(), 28)
                 << preferencias << "\n";
        }
    }

    cout << endl;
}

void tablaLibros(ISBNArbolLibro& arbol){
	system("color f9");
	vector<Libro> libros = arbol.getListaOrdenada();

	cout<<"____________________________________________________________________________________________________________\n";
	cout<<"ISBN               TITULO                 AÑO DE PUBLICACION                  FECHA DE ADQUISION            ";
	cout<<"_____________________________________________________________________________________________________________\n";

     if (libros.empty()) {
        cout << "No hay libros registrados.\n";
    } else {
        // Iterar sobre cada usuario en el vector
        for (const auto& libro : libros) {

            // Imprimir cada usuario con sus detalles
            cout << libro.isbn << espaciar(2, 16)
                 << libro.titulo << espaciar(libro.titulo.size(), 26)
                 << libro.ano_publicacion << espaciar(to_string(libro.ano_publicacion).size(), 28)
                 << libro.fecha_adquisicion << "\n";
        }
    }

	cout<<endl;

}
