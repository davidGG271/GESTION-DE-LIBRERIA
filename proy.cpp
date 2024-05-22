#include<iostream>

using namespace std;


struct Libro {
    char autor[MAX_CHAR];             // Autor(es)
    int ano_publicacion;              // Año de publicación
    string genero;            // Género
    string tipo;              // Tipo (por ejemplo, tapa dura, tapa blanda, ebook, etc.)
    string titulo;            // Título
    string isbn;              // ISBN
    string editorial;         // Editorial
    int num_paginas;                  // Número de páginas
    double precio;                    // Precio
    string descripcion;       // Descripción
    string fecha_adquisicion; // Fecha de adquisición
    string lenguaje;          // Lenguaje
};

struct Usuario {
    string nombres;                     // Nombres
    string apellidos;                   // Apellidos
    int id;                                     // ID
    string contrasena[MAX_CHAR];                  // Contraseña
    string preferencias[MAX_CHAR];                // Preferencias
    string correo[MAX_CHAR];                      // Correo
    string libros_virtuales_comprados[MAX_LIBROS][MAX_CHAR]; // Libros virtuales comprados
    int num_libros_comprados;                   // Número de libros comprados
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
