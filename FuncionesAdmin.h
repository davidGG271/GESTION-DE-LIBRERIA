#ifndef FUNCIONESADMIN_H
#define FUNCIONESADMIN_H

#include "Usuario.h"
#include "Administrador.h"
#include "ISBNArbolDeLibros.h"
#include "ArbolUsuario.h"
#include "PrestamoArbol.h"

#include <ctime>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

void paginaPrincipalAdmin(ArbolUsuario &arbolUsuarios, ISBNArbolLibro &arbolLibros, PrestamoArbol &arbolPrestamos, Administrador &admin);
void agregarLibro(ISBNArbolLibro &arbolLibros);
void eliminarLibro(ISBNArbolLibro &arbolLibros);
void mostrarDetalles(ISBNArbolLibro &arbolLibros);
void eliminarUsuario(ArbolUsuario &arbolUsuarios);
void verDetallesPrestamos(PrestamoArbol &arbolPrestamos, ArbolUsuario &arbolUsuarios, ISBNArbolLibro &arbolLibros);
void tablaUsuarios(ArbolUsuario &arbol);
string espaciar(int tamanio, int valor);
void tablaLibros(ISBNArbolLibro &lista);
string obtenerFechaActual();
void tablaPrestamos(PrestamoArbol &arbol);



void paginaPrincipalAdmin(ArbolUsuario &arbolUsuarios, ISBNArbolLibro &arbolLibros, PrestamoArbol &arbolPrestamos, Administrador &admin)
{
    int opcion;
    int opcion2;
    int opcion3;

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

            do
            {
                system("cls");
                tablaLibros(arbolLibros);
                cout << "1. Agregar Libro\n";
                cout << "2. Seleccionar libro\n";
                cout << "3. Eliminar libro\n";
                cout << "4. Atras\n";
                cout << "Selecciona una opcion: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                    system("cls");
                    agregarLibro(arbolLibros);

                    break;
                case 2:
                    system("cls");
                    tablaLibros(arbolLibros);
                    mostrarDetalles(arbolLibros);

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
            } while (opcion2 != 4);

            break;
        case 2:

            do
            {
                system("cls");
                tablaUsuarios(arbolUsuarios);
                cout << "1. Eliminar Usuario\n";
                cout << "2. Atras\n";
                cout << "Selecciona una opcion: ";
                cin >> opcion3;

                switch (opcion3)
                {
                case 1:
                    system("cls");
                    tablaUsuarios(arbolUsuarios);
                    eliminarUsuario(arbolUsuarios);
                    system("cls");
                    break;
                case 2:
                    break;
                default:
                    system("cls");
                    break;
                }
            } while (opcion3 != 2);

            break;
        case 3:

            system("cls");
            tablaPrestamos(arbolPrestamos);
            verDetallesPrestamos(arbolPrestamos, arbolUsuarios, arbolLibros);
            system("cls");
            break;
        case 4:
            cout << "Saliendo...\n";
            cout << "1. Eliminar Usuario\n";
            cout << "2. Atras\n";
            cout << "Selecciona una opcion: ";
            system("cls");
            break;
        default:
            cout << "Opción no válida, intente nuevamente.\n";
            break;
        }

    } while (opcion != 4);
}

void agregarLibro(ISBNArbolLibro &arbolLibros)
{
    Libro libro;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Ingrese isbn: ";
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

void eliminarLibro(ISBNArbolLibro &arbolLibros)
{
    string isbn;
    cout << "Seleccionar libro a eliminar por isbn(-1 si quiere salir): ";
    cin >> isbn;
    if (isbn == "-1")
    {
        return;
    }
    arbolLibros.eliminar(isbn);
}

void mostrarDetalles(ISBNArbolLibro &arbolLibros)
{
    string isbn;
    int opcion;
    cout << "Tipee el ISBN de un libro: ";
    cin >> isbn;

    NodoArbol *encontrado = arbolLibros.buscar(isbn);
    if (encontrado != nullptr)
    {
        system("cls");
        do
        {
            cout << "Detalles del libro:" << endl;
            cout << "-------------------" << endl;
            cout << "1. ISBN:                  " << encontrado->libro.isbn << endl;
            cout << "2. Título:                " << encontrado->libro.titulo << endl;
            cout << "3. Autor(es):             " << encontrado->libro.autor << endl;
            cout << "4. Año de publicación:    " << encontrado->libro.ano_publicacion << endl;
            cout << "5. Género:                " << encontrado->libro.genero << endl;
            cout << "6. Número de páginas:     " << encontrado->libro.num_paginas << endl;
            cout << "7. Editorial:             " << encontrado->libro.editorial << endl;
            cout << "8. Lenguaje:              " << encontrado->libro.lenguaje << endl;
            cout << "9. Descripción:           " << encontrado->libro.descripcion << endl;
            cout << "10. Fecha de adquisición: " << encontrado->libro.fecha_adquisicion << endl;
            cout << "11. Stock:             " << encontrado->libro.stock << endl
                 << endl;
            cout << "12. salir";
            cout << "-------------------\n"
                 << endl;
            cout << "Elige atributo modificar: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
            case 1:
                cout << "Ingrese el nuevo ISBN: ";
                cin >> encontrado->libro.isbn;
                break;
            case 2:
                cout << "Ingrese el nuevo título: ";
                cin.ignore();
                getline(cin, encontrado->libro.titulo);
                break;
            case 3:
                cout << "Ingrese el nuevo autor(es): ";
                cin.ignore();
                getline(cin, encontrado->libro.autor);
                break;
            case 4:
                cout << "Ingrese el nuevo año de publicación: ";
                cin >> encontrado->libro.ano_publicacion;
                break;
            case 5:
                cout << "Ingrese el nuevo género: ";
                cin.ignore();
                getline(cin, encontrado->libro.genero);
                break;
            case 6:
                cout << "Ingrese el nuevo número de páginas: ";
                cin >> encontrado->libro.num_paginas;
                break;
            case 7:
                cout << "Ingrese la nueva editorial: ";
                cin.ignore();
                getline(cin, encontrado->libro.editorial);
                break;
            case 8:
                cout << "Ingrese el nuevo lenguaje: ";
                cin.ignore();
                getline(cin, encontrado->libro.lenguaje);
                break;
            case 9:
                cout << "Ingrese la nueva descripción: ";
                cin.ignore();
                getline(cin, encontrado->libro.descripcion);
                break;
            case 10:
                cout << "Ingrese la nueva fecha de adquisición: ";
                cin.ignore();
                getline(cin, encontrado->libro.fecha_adquisicion);
                break;
            case 11:
                cout << "Ingrese el nuevo stock: ";
                cin >> encontrado->libro.stock;
                break;
            case 12:
                system("cls");
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
            }
        } while (opcion != 12);
    }
    else
    {
        cout << "isbn no valido";
    }
}

void eliminarUsuario(ArbolUsuario &arbolUsuarios)
{
    string id;
    cout << "Seleccionar libro a eliminar por id(-1 si quiere salir): ";
    cin >> id;
    if (id == "-1")
    {
        return;
    }
    arbolUsuarios.eliminar(id);
}

void verDetallesPrestamos(PrestamoArbol &arbolPrestamos, ArbolUsuario &arbolUsuarios, ISBNArbolLibro &arbolLibros)
{
    string id;
    NodoArbolPrestamo *encontrado;
    NodoArbol *nodoLibro;
    system("cls");
    tablaPrestamos(arbolPrestamos);
    cout << "Escribe un ID(-1 para salir) ";
    cin >> id;
    if (id == "-1")
    {
        return;
    }
    encontrado = arbolPrestamos.buscar(id);
    if (encontrado != nullptr)
    {
        cout << "Id: " << encontrado->prestamo.id << endl;
        cout << "Usuario: " << arbolUsuarios.buscar(encontrado->prestamo.idUsuario)->usuario.nombres << " - " << encontrado->prestamo.idUsuario << endl;
        cout << "Fecha de salida: " << encontrado->prestamo.fechaSalida << endl;
        cout << "Fecha de Devolucion: " << encontrado->prestamo.fechaDevolucion << endl;
        cout << "Libros prestados:" << endl;

        for (const auto &isbn : encontrado->prestamo.isbnLibros)
        {
            nodoLibro = arbolLibros.buscar(isbn);
            cout << nodoLibro->libro.titulo << " - " << nodoLibro->libro.isbn;
        }
        cout << endl;
        system("pause");
    }
}

string obtenerFechaActual()
{
    time_t tiempoActual = time(nullptr);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", localtime(&tiempoActual));
    return string(buffer);
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

void tablaUsuarios(ArbolUsuario &arbol)
{
    system("color f9");
    vector<Usuario> usuarios = arbol.getListaOrdenada();

    cout << "_______________________________________________________________________________________________________________\n";
    cout << "ID              NOMBRES                  CORREO                        PREFERENCIAS\n";
    cout << "_______________________________________________________________________________________________________________\n";

    // Verificar si hay usuarios para mostrar
    if (usuarios.empty())
    {
        cout << "No hay usuarios registrados.\n";
    }
    else
    {
        // Iterar sobre cada usuario en el vector
        for (const auto &usuario : usuarios)
        {
            string preferencias = "[ ";

            // Construir la lista de preferencias
            for (size_t i = 0; i < usuario.preferencias.size(); ++i)
            {
                preferencias += usuario.preferencias[i].tipo;
                if (i != usuario.preferencias.size() - 1)
                {
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

void tablaLibros(ISBNArbolLibro &arbol)
{
    system("color f9");
    vector<Libro> libros = arbol.getListaOrdenada();

    cout << "____________________________________________________________________________________________________________\n";
    cout << "ISBN               TITULO                 ANIO DE PUBLICACION                  FECHA DE ADQUISION            " << endl;
    cout << "_____________________________________________________________________________________________________________\n";

    if (libros.empty())
    {
        cout << "No hay libros registrados.\n";
    }
    else
    {
        // Iterar sobre cada usuario en el vector
        for (const auto &libro : libros)
        {

            // Imprimir cada usuario con sus detalles
            cout << libro.isbn << espaciar(2, 16)
                 << libro.titulo << espaciar(libro.titulo.size(), 26)
                 << libro.ano_publicacion << espaciar(to_string(libro.ano_publicacion).size(), 28)
                 << libro.fecha_adquisicion << "\n";
        }
    }

    cout << endl;
}

void tablaPrestamos(PrestamoArbol &arbol)
{
    system("color f9");
    vector<Prestamo> prestamos = arbol.getListaOrdenada();

    cout << "____________________________________________________________________________________________________________\n";
    cout << "ID                ID DE USUARIO                 FECHA DE DEVOLUCION                  FECHA DE SALIDA         " << endl;
    cout << "_____________________________________________________________________________________________________________\n";

    if (prestamos.empty())
    {
        cout << "No hay librod registrados. \n";
    }
    else
    {
        for (const auto &prestamo : prestamos)
        {

            cout << prestamo.id << espaciar(2, 16)
                 << prestamo.idUsuario << espaciar(prestamo.idUsuario.size(), 26)
                 << prestamo.fechaDevolucion << espaciar(prestamo.fechaDevolucion.size(), 26)
                 << prestamo.fechaSalida << espaciar(prestamo.fechaSalida.size(), 28);
        }
    }
    cout << endl;
}
#endif