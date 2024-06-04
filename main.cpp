#include "Libro.h"
#include "Usuario.h"
#include "ListaUsuario.h"
#include "NodoUsuario.h"
#include "ListaLibro.h"
#include "NodoLibro.h"
#include "ISBNArbolDeLibros.h"

#include <iostream>
#include <string>

using namespace std;

void mostrarMenuPrincipal() {
    cout << "Menu Principal:" << endl;
    cout << "1. Trabajar con Usuarios" << endl;
    cout << "2. Trabajar con Libros" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuUsuario() {
    cout << "Menu Usuarios:" << endl;
    cout << "1. Agregar Usuario" << endl;
    cout << "2. Eliminar Usuario" << endl;
    cout << "3. Buscar Usuario" << endl;
    cout << "4. Volver al Menu Principal" << endl;
    cout << "Seleccione una opción: ";
}

void mostrarMenuLibro() {
    cout << "Menu Libros:" << endl;
    cout << "1. Agregar Libro" << endl;
    cout << "2. Eliminar Libro" << endl;
    cout << "3. Buscar Libro" << endl;
    cout << "4. Volver al Menu Principal" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    ListaUsuario listaUsuarios;
    ListaLibro listaLibros;
    ISBNArbolLibro isbnArbol;
    int opcion;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 1: { // Trabajar con Usuarios
                int opcionUsuario;
                do {
                    mostrarMenuUsuario();
                    cin >> opcionUsuario;

                    switch (opcionUsuario) {
                        case 1: { // Agregar Usuario
                            Usuario nuevoUsuario;
                            cout << endl;
                            cout << "Ingrese ID del usuario: ";
                            cin >> nuevoUsuario.id;
                            cout << "Ingrese nombre del usuario: ";
                            cin >> nuevoUsuario.nombres;
                            cout << "Ingrese correo del usuario: ";
                            cin >> nuevoUsuario.correo;
                            cout << "Ingrese contrasenia del usuario: ";
                            cin >> nuevoUsuario.contrasenia;

                            NodoU* nodoNuevo = agregarNodoUsuario(nuevoUsuario);
                            listaUsuarios.agregar(nodoNuevo);
                            cout << "Usuario agregado " << endl;
                            cout << endl;
                            break;
                        }
                        case 2: { // Eliminar Usuario
                            string id;
                            cout << endl;
                            cout << "Ingrese ID del usuario : ";
                            cin >> id;
                            listaUsuarios.eliminar(id);
                            cout << "USUARIO ELIMINADO CORRECTAMENTE " << endl;
                            cout << endl;
                            break;
                        }
                        case 3: { // Buscar Usuario
                            string id;
                            cout << endl;
                            cout << "Ingrese ID del usuario a buscar: ";
                            cin >> id;
                            NodoU* usuario = listaUsuarios.encontrarUsuario(id);
                            if (usuario != nullptr) {
                                cout << "Usuario encontrado:" << endl;
                                cout << "ID: " << usuario->usuario.id << endl;
                                cout << "Nombre: " << usuario->usuario.nombres << endl;
                                cout << "Correo: " << usuario->usuario.correo << endl;
                            } else {
                                cout << "Usuario no encontrado." << endl;
                            }
                            cout << endl;
                            break;
                        }
                        case 4: // Volver al Menu Principal
                            break;
                        default:
                            cout << "Opcion invalida" << endl;
                    }
                } while (opcionUsuario != 4);
                break;
            }
            case 2: { // Trabajar con Libros
			    int opcionLibro;
			    do {
			        mostrarMenuLibro();
			        cin >> opcionLibro;
			
			        switch (opcionLibro) {
			            case 1: { // Agregar Libro
			                Libro nuevoLibro;
			                cout << endl;
			                cout << "Ingrese ISBN del libro: ";
			                cin >> nuevoLibro.isbn;
			                if (isbnArbol.buscar(nuevoLibro.isbn)) {
                                cout << "Error: El ISBN ya existe en la lista." << endl;
                            } else {
                                cout << "Ingrese título del libro: ";
                                cin >> nuevoLibro.titulo;
                                // Aquí continuarías solicitando la información restante del libro
                                NodoL* nodoNuevoLibro = agregarNodoLibro(nuevoLibro);
                                listaLibros.agregar(nodoNuevoLibro);
                                isbnArbol.insertar(nuevoLibro.isbn);
                                cout << "Libro agregado " << endl;
                                cout << endl;
                            }
			                break;
			            }
			            case 2: { // Eliminar Libro
			                string isbn;
			                cout << endl;
			                cout << "Ingrese ISBN del libro: ";
			                cin >> isbn;
			                listaLibros.eliminar(isbn);
			                cout << "LIBRO ELIMINADO CORRECTAMENTE " << endl;
			                cout << endl;
			                break;
			            }
			            case 3: { // Buscar Libro
			                string isbn;
			                cout << endl;
			                cout << "Ingrese ISBN del libro a buscar: ";
			                cin >> isbn;
			                NodoL* libro = listaLibros.encontrarLibro(isbn);
			                if (libro != nullptr) {
			                    cout << "Libro encontrado:" << endl;
			                    cout << "ISBN: " << libro->libro.isbn << endl;
			                    cout << "Título: " << libro->libro.titulo << endl;
			                    // Aquí imprimirías el resto de la información del libro
			                } else {
			                    cout << "Libro no encontrado." << endl;
			                }
			                cout << endl;
			                break;
			            }
			            case 4: // Volver al Menu Principal
			                break;
			            default:
			                cout << "Opcion invalida" << endl;
			        }
			    } while (opcionLibro != 4);
			    break;
        	}
        }
    } while (opcion != 3);

    return 0;
}
