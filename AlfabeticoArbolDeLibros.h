#ifndef ALFABETICOARBOLDELIBROS_H
#define ALFABETICOARBOLDELIBROS_H

#include <iostream>
#include "Libro.h"
using namespace std;

struct NodoArbolAlfa {
    Libro libro;
    NodoArbolAlfa* izquierda;
    NodoArbolAlfa* derecha;
};

class AlfabeticoArbolDeLibros{
	private:
		NodoArbolAlfa* raiz;
	
	public:
		AlfabeticoArbolDeLibros() {//constructor
	        raiz = nullptr;
	    }
	    
	    void agregar(Libro libro){
	    	raiz = insertarNodo(raiz, libro);
		}
		
		bool buscar(string titulo){
			return buscarNodo(titulo);
		}
		
	private:
		
		NodoArbolAlfa* insertarNodo(NodoArbolAlfa nodo, Libro libro){
			if(nodo == nullptr){//si el puntero es nulo, se procedera a crear el nodo
				NodoArbolAlfa* actual = new NodoArbolAlfa{libro,nullptr,nullptr};
				return actual;
			}
			
			NodoArbolAlfa* actual = raiz //se crear un nuevo puntero con la ubicacion de la raiz
			if(convertirMinuscula(libro.titulo)<convertirMinuscula(actual->libro.titulo)){
				// si el nodo padre tiene un libro con un titulo de mayor valor en base al codigo ASCII, este pasara a por la misma funcion
				//con el nodo hijo izquierdo
				insertarNodo(actual->izquierda,libro);
			}else if(convertirMinuscula(libro.titulo)>actual->libro.titulo){
				// si el nodo padre tiene un libro con un titulo de menor valor en base al codigo ASCII, este pasara a por la misma funcion
				//con el nodo hijo derecho
				insertarNodo(actual->derecha,libro);
			}
			return actual;
		}
		
		bool buscarNodo(NodoArbolAlfa nodo, string titulo){
				
			if (nodo == nullptr) {// return falso si el nodo actual es nullptr
	            return false;
	        }
			
			if(convertirMinuscula(titulo)==convertirMinuscula(nodo->libro.titulo)){
			// si el nodo actual contiene el libro con el titulo a encontrar, retorna verdadero
				return true;
			}
			
			if(convertirMinuscula(titulo)<convertirMinuscula(nodo->libro.titulo)){
				// si el nodo actual tiene un libro con un titulo de mayor valor en base al codigo ASCII, 
				//este pasara a por la misma funcion con el nodo hijo izquierdo
				return buscarNodo(nodo->izquierda,titulo);
			}else{
				// si el nodo actual tiene un libro con un titulo de menor valor en base al codigo ASCII, 
				//este pasara a por la misma funcion con el nodo hijo derecho
				return buscarNodo(nodo->derecha,titulo);
			}
		}
		
		
		string convertirMinuscula(string cadena){
			string aux= "";
			for(const char c : cadena){
				aux += tolower(static_cast<unsigned char>(c));
			}
			return aux;
		}
		
};

#endif
