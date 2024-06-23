#ifndef FUNCIONESADMIN_H
#define FUNCIONESADMIN_H

#include "Usuario.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "Administrador.h"


#include "ISBNArbolDeLibros.h"
#include "ArbolUsuario.h"

#include <iostream>

using namespace std;

void paginaPrincipalAdmin(ArbolUsuario& arbolUsuarios, ISBNArbolLibro& arbolLibros, Administrador& admin);
void tablaUsuarios(ArbolUsuario& arbol);
string espaciar(int tamanio, int valor);
void tablaLibros(ListaLibro& lista);

#endif

void paginaPrincipalAdmin(ArbolUsuario& arbolUsuarios, ISBNArbolLibro& arbolLibros, Administrador& admin){
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
							tablaLibros(arbolLibros);
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
				tablaUsuarios(arbolUsuarios);

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
                 << libro.ano_publicacion << espaciar(libro.ano_publicacion.size(), 28)
                 << libro.fecha_adquisicion << "\n";
        }
    }

    cout << endl;
	actual = lista.inicio;
	while(actual!=nullptr){

		cout<<actual->libro.isbn<<espaciar(2,26)<<actual->libro.titulo<<espaciar(actual->libro.titulo.size(),30)<<actual->libro.ano_publicacion<<espaciar(to_string(actual->libro.ano_publicacion).size(),40)<< actual->libro.fecha_adquisicion<<"\n";
	}

	cout<<endl;

}
