#include<iostream>

using namespace std;


struct Libro {
    char autor[MAX_CHAR];             // Autor(es)
    int ano_publicacion;              // A�o de publicaci�n
    string genero;            // G�nero
    string tipo;              // Tipo (por ejemplo, tapa dura, tapa blanda, ebook, etc.)
    string titulo;            // T�tulo
    string isbn;              // ISBN
    string editorial;         // Editorial
    int num_paginas;                  // N�mero de p�ginas
    double precio;                    // Precio
    string descripcion;       // Descripci�n
    string fecha_adquisicion; // Fecha de adquisici�n
    string lenguaje;          // Lenguaje
};

struct Usuario {
    string nombres;                     // Nombres
    string apellidos;                   // Apellidos
    int id;                                     // ID
    string contrasena[MAX_CHAR];                  // Contrase�a
    string preferencias[MAX_CHAR];                // Preferencias
    string correo[MAX_CHAR];                      // Correo
    string libros_virtuales_comprados[MAX_LIBROS][MAX_CHAR]; // Libros virtuales comprados
    int num_libros_comprados;                   // N�mero de libros comprados
};

struct Gerente{
	string nombres;
	string apellidos;
	string contrasenia;
	string correo;
};

struct 

int main(){
	
}
