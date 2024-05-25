#ifndef LISTALIBRO_H
#define LISTALIBRO_H

#include "Libro.h"
#include "NodoLibro.h"
#include <iostream>

using namespace std;

class ListaLibro {
private:
    NodoL* inicio;
    NodoL* final;

public:
    ListaLibro() {
        inicio = nullptr;
        final = nullptr;
    }

    void agregar(NodoL* nodoNuevo) {
        if (inicio == nullptr) {
            inicio = nodoNuevo;
            final = nodoNuevo;
            nodoNuevo->anterior = nullptr;
            nodoNuevo->siguiente = nullptr;
        } else {
            nodoNuevo->anterior = final;
            final->siguiente = nodoNuevo;
            final = nodoNuevo;
            final->siguiente = nullptr;
        }
    }

    void eliminar(string isbn) {
        if (inicio == nullptr) {
            cout << "No hay libros registrados" << std::endl;
        }

        if (!LibroExiste(isbn)) {
            cout << "El libro no existe" << std::endl;
        }

        if (inicio->libro.isbn == isbn) {
            NodoL* auxI = inicio;
            inicio = inicio->siguiente;

            if (inicio != nullptr)
                inicio->anterior = nullptr;

            delete auxI;
        } else if (final->libro.isbn == isbn) {
            NodoL* auxF = final;
            final = final->anterior;

            if (final != nullptr)
                final->siguiente = nullptr;

            delete auxF;
        } else {
            NodoL* aux = inicio;

            while (aux != nullptr && aux->libro.isbn != isbn) {
                aux = aux->siguiente;
            }

            if (aux != nullptr) {
                NodoL* auxA = aux->anterior;
                NodoL* auxS = aux->siguiente;

                auxA->siguiente = auxS;

                if (auxS != nullptr) {
                    auxS->anterior = auxA;
                }
                delete aux;
                cout << "Libro eliminado exitosamente!" << std::endl;
            }
        }
    }

    bool LibroExiste(string isbn) {
        bool existe = false;

        if (inicio == nullptr) {
            return existe;
        } else {
            NodoL* aux = inicio;

            while (aux != nullptr) {
                if (aux->libro.isbn == isbn) {
                    existe = true;
                    return existe;
                }
                aux = aux->siguiente;
            }
        }
        return existe;
    }

    NodoL* encontrarLibro(string isbn) {
        if (inicio == nullptr) {
            return nullptr;
        } else {
            NodoL* aux = inicio;
            while (aux != nullptr) {
                if (aux->libro.isbn == isbn) {
                    return aux;
                }
                aux = aux->siguiente;
            }
        }
        return nullptr;
    }
    
    void ordenarPorTitulo() {
	    if (inicio == nullptr) {
	        std::cout << "No hay libros para ordenar" << std::endl;
	        return;
	    }

	    bool intercambio;
	    NodoL* actual;
	    NodoL* siguiente = nullptr;
	
	    do {
	        intercambio = false;
	        actual = inicio;
	
	        while (actual->siguiente != siguiente) {
	            if (actual->libro.titulo > actual->siguiente->libro.titulo) {
	                swap(actual->libro, actual->siguiente->libro);
	                intercambio = true;
	            }
	            actual = actual->siguiente;
	        }
	        siguiente = actual;
	    } while (intercambio);
	}
	
	NodoL* busquedaBinariaPorTitulo(string titulo) {
	    ordenarPorTitulo(); // Ordenamos primero por título
	    NodoL* izquierda = inicio;
	    NodoL* derecha = final;
	
	    while (izquierda <= derecha) {
	        NodoL* medio = izquierda + (derecha - izquierda) / 2;
	
	        // Check if title is present at mid
	        if (medio->libro.titulo == titulo) {
	            return medio;
	        }
	
	        // If title greater, ignore left half
	        if (medio->libro.titulo < titulo) {
	            izquierda = medio + 1;
	        } else { // If title is smaller, ignore right half
	            derecha = medio - 1;
	        }
	    }
	
	    // if we reach here, then element was not present
	    return nullptr;
	}
};

#endif
