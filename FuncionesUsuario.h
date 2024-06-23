#ifndef FUNCIONESUSUARIO_H
#define FUNCIONESUSUARIO_H

#include "Usuario.h"
#include "ISBNArbolDeLibros.h"

#include <iostream>
using namespace std;

void paginaPrincipalUsu(Usuario& usuario);
void seleccionarLibro(Usuario& usuario, ISBNArbolLibro arbolLibrosIsbn);
void verLibrosSeleccionados(Usuario& usuario);
void gestionarCuenta(Usuario& Usuario);

#endif

void paginaPrincipalUsu(Usuario& usuario, ISBNArbolLibro arbolLibros){
	int opcion;
	cout<<"hola "<<usuario.nombres<<"\n";
	do{
		
		cout<<"1. Ver libros\n";
		cout<<"2. Gestionar Cuenta\n";
		cout<<"3. Tu Historial de prestamos\n";
		cout<<"4. Ver libros seleccionados\n";
		cout<<"5. Ver recomendados\n";
		cout<<"6. Cerrar sesion\n";
		
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
				break;
			case 4:
				verLibrosSeleccionados(usuario);
				break;
			case 5:
				break;
			case 6:
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
						encontrado->libro.stock = encontrado->libro.stock-1;
						usuario.librosSeleccionados.push_back(encontrado->libro);
                        cout<<"Asignado correctamente!";
                        break;
                    case 0:
                        system("cls");
                        break;
                    default:
                        cout << "Opción inválida." << endl;
                        break;
				}

    }else{
        cout<<"ISBN no valido";
    }
}

void verLibrosSeleccionados(Usuario& usuario){
	cout << "Libros seleccionados:\n";
    cout<<"____________________________________________________________________________________________________________\n";
	cout<<"ISBN               TITULO                 AÑO DE PUBLICACION                  FECHA DE ADQUISION            ";
	cout<<"_____________________________________________________________________________________________________________\n";

	if (usuario.librosSeleccionados.empty()) {
        cout << "No tiene libros seleccionados.\n";
        return;
    } else {
        // Iterar sobre cada usuario en el vector
        for (const auto& libro : usuario.librosSeleccionados) {

            // Imprimir cada usuario con sus detalles
            cout << libro.isbn << espaciar(2, 16)
                 << libro.titulo << espaciar(libro.titulo.size(), 26)
                 << libro.ano_publicacion << espaciar(to_string(libro.ano_publicacion).size(), 28)
                 << libro.fecha_adquisicion << "\n";
        }
    }
}

void gestionarCuenta(Usuario& usuario){
	int opcion;
    cout << "1. Modificar correo\n";
    cout << "2. Modificar nombre\n";
    cout << "3. Modificar contraseña\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
    case 1:
        cout << "Ingrese el nuevo correo: ";
        cin>>usuario.correo;
        break;
    case 2:
        cout << "Ingrese el nuevo nombre: ";
        usuario.nombres;
        break;
    case 3:
        cout << "Ingrese la nueva contraseña: ";
        usuario.contrasenia;
        break;
    default:
        cout << "Opción no válida.\n";
    }
}