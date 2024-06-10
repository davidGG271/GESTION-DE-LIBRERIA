#include "Libro.h"
#include "Usuario.h"
#include "ListaUsuario.h"
#include "NodoUsuario.h"
#include "ListaLibro.h"
#include "NodoLibro.h"
#include "ISBNArbolDeLibros.h"
#include "funcionesPrestamo.h"

#include <iostream>
#include <string>

using namespace std;

void mostrarMenuPrincipal() {
    cout << "Menu Principal:" << endl;
    cout << "1. Trabajar con Usuarios" << endl;
    cout << "2. Trabajar con Libros" << endl;
    cout << "3. Prestamos" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opci�n: ";
}

void mostrarMenuUsuario() {
    cout << "Menu Usuarios:" << endl;
    cout << "1. Agregar Usuario" << endl;
    cout << "2. Eliminar Usuario" << endl;
    cout << "3. Buscar Usuario" << endl;
    cout << "4. Volver al Menu Principal" << endl;
    cout << "Seleccione una opci�n: ";
}

void mostrarMenuLibro() {
    cout << "Menu Libros:" << endl;
    cout << "1. Agregar Libro" << endl;
    cout << "2. Eliminar Libro" << endl;
    cout << "3. Buscar Libro" << endl;
    cout << "4. Volver al Menu Principal" << endl;
    cout << "Seleccione una opci�n: ";
}

void mostrarMenuPrestamo() {
    cout << "Menu Prestamos:" << endl;
    cout << "1. Agregar Prestamo" << endl;
    cout << "2. Eliminar Prestamo" << endl;
    cout << "3. Buscar Prestamo" << endl;
    cout << "4. Establecer fecha de entrega prestamo"<<endl;
    cout << "5. Volver al Menu Principal" << endl;
    cout << "Seleccione una opci�n: ";
}

int main() {
    ListaUsuario listaUsuarios;
    ListaLibro listaLibros;
    ListaPrestamo listaPrestamo;
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
                                cout << "Ingrese t�tulo del libro: ";
                                cin >> nuevoLibro.titulo;
                                // Aqu� continuar�as solicitando la informaci�n restante del libro
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
			                    cout << "T�tulo: " << libro->libro.titulo << endl;
			                    // Aqu� imprimir�as el resto de la informaci�n del libro
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
			case 3:
				int opcionPrestamo;
				do{
                    system("cls");
                    mostrarMenuPrestamo();
                    cin >> opcionPrestamo;
					switch(opcionPrestamo){
                        case 1:
                            agregarNuevoPrestamo(listaUsuarios, listaLibros, listaPrestamo);
                            break;
                        case 2:
                            eliminarPrestamo(listaPrestamo);
                            break;
                        case 3:
                            buscarPrestamo(listaPrestamo);
                            break;
                        case 4:
                            establecerFechaEntrega(listaPrestamo);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Opcion invalida.";
                    }

				} while (opcionPrestamo != 5);
				break;
			
			
        	}
        }
        
    } while (opcion != 4);

    return 0;
}
