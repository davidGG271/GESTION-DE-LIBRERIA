    #ifndef FUNCIONESUSUARIO_H
#define FUNCIONESUSUARIO_H

#include "Usuario.h"
#include "Prestamo.h"
#include "ISBNArbolDeLibros.h"
#include "PrestamoArbol.h"

#include <iostream>
using namespace std;

void paginaPrincipalUsu(Usuario& usuario);
void seleccionarLibro(Usuario& usuario, ISBNArbolLibro arbolLibrosIsbn);
void verLibrosSeleccionados(Usuario& usuario, PrestamoArbol& arbolPrestamo, ISBNArbolLibro& arbolLibro);
void verHistorialPrestamos(Usuario& usuario, PrestamoArbol& arbolPrestamo);
void gestionarCuenta(Usuario& Usuario);
string sumarSemana(const string& fecha);

#endif

string sumarSemana(const string& fecha) {
    // Extraer día, mes y año de la cadena
    int dia, mes, anio;
    sscanf(fecha.c_str(), "%d-%d-%d", &dia, &mes, &anio);
    
    // Ajustar para struct tm
    mes -= 1; // Mes en struct tm es 0-11
    anio -= 1900; // Año en struct tm comienza desde 1900

    // Crear struct tm
    tm fechaTm = {};
    fechaTm.tm_mday = dia;
    fechaTm.tm_mon = mes;
    fechaTm.tm_year = anio;

    // Sumar 7 días
    time_t fechaTimeT = mktime(&fechaTm); // Convertir tm a time_t
    fechaTimeT += 7 * 24 * 60 * 60; // Sumar una semana en segundos

    // Convertir de vuelta a struct tm
    tm* nuevaFechaTm = localtime(&fechaTimeT);

    // Convertir struct tm de vuelta a string
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", nuevaFechaTm);

    return string(buffer);
}

void paginaPrincipalUsu(Usuario& usuario, ISBNArbolLibro arbolLibros, PrestamoArbol& arbolPrestamo){
	int opcion;
	cout<<"hola "<<usuario.nombres<<"\n";
	do{

		cout<<"1. Ver libros\n";
		cout<<"2. Gestionar Cuenta\n";
		cout<<"3. Tu Historial de prestamos\n";
		cout<<"4. Ver libros seleccionados\n";
		cout<<"5. Cerrar sesion\n";

		cout<<"Ingrese la funcion a realizar: ";
		cin>>opcion;
		switch(opcion){
			case 1:
				seleccionarLibro(usuario, arbolLibros);
				break;
			case 2:
				gestionarCuenta(usuario);
				break;
			case 3:
            verHistorialPrestamos(usuario, arbolPrestamo);
				break;
			case 4:
				verLibrosSeleccionados(usuario, arbolPrestamo, arbolLibros);
				break;
			case 5:
				cout << "Saliendo...\n";
				system("cls");
				break;
			default:
				system("cls");
				cout<<"Opci�n no v�lida, intente nuevamente.\n";
				break;
		}
	}while(opcion!=6);
}

void seleccionarLibro(Usuario& usuario, ISBNArbolLibro arbolLibrosIsbn){
	system("color f9");
	vector<Libro> libros = arbolLibrosIsbn.getListaOrdenada();

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
	string isbn;
	int opcion;
    cout<<"Tipee el ISBN de un libro: ";
    cin>>isbn;
	NodoArbol* encontrado = arbolLibrosIsbn.buscar(isbn);
    if(encontrado!=nullptr){
        system("cls");
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
                cout << "11. Stock:             " << encontrado->libro.stock << endl;
                cout << "-------------------\n" << endl;
                cout<<"Desea seleccionar el Libro ? - Ingrese Si(1) - No(0): "<<endl;
                cin>>opcion;
                system("cls");
                switch(opcion){
                    case 1:
						usuario.librosSeleccionados.push_back(encontrado->libro);
                        cout<<"Asignado correctamente!\n";
                        system("pause");
                        system("cls");
                        break;
                    case 0:
                        system("cls");
                        break;
                    default:
                        system("cls");
                        cout << "Opción inválida." << endl;
                        break;
				}

    }else{
        cout<<"ISBN no valido";
        system("cls");
    }
}

void verLibrosSeleccionados(Usuario& usuario, PrestamoArbol& arbolPrestamo, ISBNArbolLibro& arbolLibro){
    int opc;
    system("cls");
	cout << "Libros seleccionados:\n";
    cout<<"____________________________________________________________________________________________________________\n";
	cout<<"ISBN               TITULO                 AÑO DE PUBLICACION                  FECHA DE ADQUISION            ";
	cout<<"_____________________________________________________________________________________________________________\n";

	if (usuario.librosSeleccionados.empty()) {
        cout << "\nNo tiene libros seleccionados.\n";
        system("pause");
        system("cls");
        return;
    } else {
        Prestamo prestamo;
        // Iterar sobre cada usuario en el vector
        for (const auto& libro : usuario.librosSeleccionados) {
            // Imprimir cada usuario con sus detalles
            cout << libro.isbn << espaciar(2, 16)
                 << libro.titulo << espaciar(libro.titulo.size(), 26)
                 << libro.ano_publicacion << espaciar(to_string(libro.ano_publicacion).size(), 28)
                 << libro.fecha_adquisicion << "\n";
        }
        cout << "Generar Prestamo?\n";
        cout << "[1] Si\n";
        cout << "[2] No\n";
        cin >> opc;
        if(opc == 1){
            prestamo.id = generateID();
            prestamo.idUsuario = usuario.id;
            prestamo.fechaSalida = obtenerFechaActual();
            prestamo.fechaDevolucion = sumarSemana(obtenerFechaActual());
            
            for (const auto& libro : usuario.librosSeleccionados) {
                arbolLibro.buscar(libro.isbn)->libro.stock --;
                prestamo.isbnLibros.push_back(libro.isbn);
            }
            arbolPrestamo.insertar(prestamo);
            usuario.librosSeleccionados.clear();
            cout << "Prestamo generado exitosamente.\n";
            system("pause");
            system("cls");
        }
        else{
            prestamo.isbnLibros.clear();
            system("cls");
        }
    }
}

void verHistorialPrestamos(Usuario& usuario, PrestamoArbol& arbolPrestamo) {
    vector<Prestamo> prestamos = arbolPrestamo.obtenerPrestamosPorUsuario(usuario.id);
    system("cls");
    if (prestamos.empty()) {
        cout << "No tiene historial de prestamos.\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "Historial de prestamos:\n";
    cout << "______________________________________________________________________________________\n";
    cout << "ID       FECHA SALIDA     FECHA DEVOLUCIÓN      ISBN(s)\n";
    cout << "______________________________________________________________________________________\n";

    for (const auto& prestamo : prestamos) {
        cout << prestamo.id << "    "
             << prestamo.fechaSalida << "      "
             << prestamo.fechaDevolucion << "      ";

        for (const auto& isbn : prestamo.isbnLibros) {
            cout << isbn << " ";
        }

        cout << "\n\n";
    }
    system("pause");
    system("cls");
}

void gestionarCuenta(Usuario& usuario) {
    int opcion;
    cout << "1. Modificar correo\n";
    cout << "2. Modificar nombre\n";
    cout << "3. Modificar contraseña\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();  // Limpiar el buffer de entrada

    switch (opcion) {
    case 1:
        cout << "Ingrese el nuevo correo: ";
        getline(cin, usuario.correo);
        break;
    case 2:
        cout << "Ingrese el nuevo nombre: ";
        getline(cin, usuario.nombres);
        break;
    case 3:
        cout << "Ingrese la nueva contraseña: ";
        getline(cin, usuario.contrasenia);
        break;
    default:
        system("cls");
        cout << "Opción no válida.\n";
        break;
    }
}
