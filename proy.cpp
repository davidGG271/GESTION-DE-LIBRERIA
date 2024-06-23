#include "Libro.h"
#include "Usuario.h"
#include "InterfazUsuario.h"
#include "ListaUsuario.h"
#include "NodoUsuario.h"
#include "ListaLibro.h"
#include "NodoLibro.h"
#include "ISBNArbolDeLibros.h"
#include<iostream>

using namespace std;


struct Gerente{
	string nombres;
	string apellidos;
	string contrasenia;
	string correo;
};

int main(){
	Hash hashTable;
	
	vector<Preferencia> preferencias;
	Preferencia p1;
	p1.contador = 4;
	p1.tipo = "Drama";
	Preferencia p2;
	p2.contador = 1;
	p2.tipo = "Terror";
	Preferencia p3;
	p3.contador = 5;
	p3.tipo = "Filosofia";
	
	preferencias.push_back(p1);
	preferencias.push_back(p2);
	preferencias.push_back(p3);
	Usuario usuario;
	usuario.preferencias = preferencias;

    // Creamos algunos libros
    Libro libro1;
    libro1.titulo = "The Great Gatsby";
    libro1.genero.push_back("Terror");
    libro1.genero.push_back("Drama");
	
	Libro libro2;
    libro2.titulo = "1984";
    libro2.genero.push_back("Drama");
    
    Libro libro3;
    libro3.titulo = "Pride and Prejudice";
    libro3.genero.push_back("Filosofia");
    
    
    agregarLibro(hashTable, libro1, usuario);
    agregarLibro(hashTable, libro2, usuario);
    agregarLibro(hashTable, libro3, usuario);
    
    // Imprimimos los libros almacenados por preferencia
    size_t preferencia = 1;
    for (const auto& listaLibros : hashTable.librosPreferencia) {
        cout << "Preferencia " << preferencia << ":\n";
        for (const auto& libro : listaLibros) {
            cout << "- " << libro.titulo << endl;
        }
        ++preferencia;
    }

    return 0;
    
}
