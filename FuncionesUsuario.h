#ifndef FUNCIONESUSUARIO_H
#define FUNCIONESUSUARIO_H

#include "Usuario.h"

#include <iostream>
using namespace std;

void paginaPrincipalUsu(Usuario& usuario);

#endif

void paginaPrincipalUsu(Usuario& usuario){
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
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				cout << "Saliendo...\n";
				system("cls");
				break;
			default:
				system("cls");
				cout<<"Opción no válida, intente nuevamente.\n";
				break;
		}	
	}while(opcion!=6);
}
