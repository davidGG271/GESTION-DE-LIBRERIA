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
			return buscarNodo(raiz, titulo);
		}
		
		vector<Libro> getListaOrdenada() {
		    vector<Libro> lista;
		    obtenerListaOrdenada(raiz, lista);
		    return lista;
		}
		
		void eliminar(string titulo) {
		    raiz = eliminarNodo(raiz, titulo);
		}
		
		void editar(Libro libro) {
		    raiz = editarNodo(raiz, libro);
		}
		
	private:
		
		NodoArbolAlfa* insertarNodo(NodoArbolAlfa* nodo, Libro libro){
			if(nodo == nullptr){//si el puntero es nulo, se procedera a crear el nodo
				NodoArbolAlfa* actual = new NodoArbolAlfa{libro,nullptr,nullptr};
				return actual;
			}
			
			NodoArbolAlfa* actual = raiz; //se crear un nuevo puntero con la ubicacion de la raiz
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
		
		bool buscarNodo(NodoArbolAlfa* nodo, string titulo){
				
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
		
		NodoArbolAlfa* eliminarNodo(NodoArbolAlfa* nodo, const string& titulo) {
		    if (nodo == nullptr) {
		        return nodo; // Caso base: árbol vacío o nodo no encontrado
		    }
		
		    string tituloMinusc = convertirMinuscula(titulo);
		    string nodoTituloMinusc = convertirMinuscula(nodo->libro.titulo);
		
		    if (tituloMinusc < nodoTituloMinusc) {
		        nodo->izquierda = eliminarNodo(nodo->izquierda, titulo);
		    } else if (tituloMinusc > nodoTituloMinusc) {
		        nodo->derecha = eliminarNodo(nodo->derecha, titulo);
		    } else {
		        // Nodo encontrado
		        if (nodo->izquierda == nullptr) {
		            NodoArbolAlfa* temp = nodo->derecha;
		            delete nodo;
		            return temp;
		        } else if (nodo->derecha == nullptr) {
		            NodoArbolAlfa* temp = nodo->izquierda;
		            delete nodo;
		            return temp;
		        }
		
		        NodoArbolAlfa* temp = encontrarMinimo(nodo->derecha);
		        nodo->libro = temp->libro;
		        nodo->derecha = eliminarNodo(nodo->derecha, temp->libro.titulo);
		    }
		
		    return nodo;
		}
		
		NodoArbolAlfa* encontrarMinimo(NodoArbolAlfa* nodo) {
		    while (nodo->izquierda != nullptr) {
		        nodo = nodo->izquierda;
		    }
		    return nodo;
		}
		
		string convertirMinuscula(string cadena){
			string aux= "";
			for(const char c : cadena){
				aux += tolower(static_cast<unsigned char>(c));
			}
			return aux;
		}
		
		NodoArbolAlfa* editarNodo(NodoArbolAlfa* nodo, const Libro& libro) {
		    if (nodo == nullptr) {
		        return nodo; // Caso base: nodo no encontrado
		    }
		
		    string libroTituloMinusc = convertirMinuscula(libro.titulo);
		    string nodoTituloMinusc = convertirMinuscula(nodo->libro.titulo);
		
		    if (libroTituloMinusc < nodoTituloMinusc) {
		        nodo->izquierda = editarNodo(nodo->izquierda, libro);
		    } else if (libroTituloMinusc > nodoTituloMinusc) {
		        nodo->derecha = editarNodo(nodo->derecha, libro);
		    } else {
		        // Nodo encontrado, actualizar el libro
		        nodo->libro = libro;
		    }
		
		    return nodo;
		}
		
		void obtenerListaOrdenada(NodoArbolAlfa* nodo, vector<Libro>& lista) {
		    if (nodo != nullptr) {
		        obtenerListaOrdenada(nodo->izquierda, lista);
		        lista.push_back(nodo->libro);
		        obtenerListaOrdenada(nodo->derecha, lista);
		    }
		}
		
};

#endif
