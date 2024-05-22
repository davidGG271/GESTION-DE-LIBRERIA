#include "Libro.h"
#include "Usuario.h"
#include "ListaUsuario.h"
#include "NodoUsuario.h"

#include <iostream>
#include <string>

using namespace std;

void mostrarMenu() {
    cout << "Menu Biblioteca Daniel Diaz:" << endl;
    cout << "1. Agregar Usuario" << endl;
    cout << "2. Eliminar Usuario" << endl;
    cout << "3. Buscar Usuario" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    ListaUsuario listaUsuarios;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Usuario nuevoUsuario;
                cout<<endl;
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
                 cout<<endl;
                break;
            }
            case 2: {
                string id;
                 cout<<endl;
                cout << "Ingrese ID del usuario : ";
                cin >> id;
                listaUsuarios.eliminar(id);
                cout<<"USARIO ELIMINADO CORRECTAMENTE "<<endl;
             cout<<endl;
                break;
            }
            case 3: {
                string id;
                 cout<<endl;
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
                 cout<<endl;
                break;
            }
            case 4:
            	 cout<<endl;
                cout << "Saliendo " << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);

    return 0;
}
