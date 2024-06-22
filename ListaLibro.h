#ifndef LISTALIBRO_H
#define LISTALIBRO_H

#include "Libro.h"
#include "NodoLibro.h"
#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class ListaLibro {
private:
    NodoL* inicio;
    NodoL* final;

public:
    ListaLibro() : inicio(nullptr), final(nullptr) {}

    void agregar(Libro libro) {
    	NodoL* nodoNuevo = new NodoL{libro, nullptr, nullptr}; 
        if (inicio == nullptr) {
            inicio = nodoNuevo;
            final = nodoNuevo;
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
            return;
        }

        if (!LibroExiste(isbn)) {
            cout << "El libro no existe" << std::endl;
            return;
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
        if (inicio == nullptr) {
            return false;
        } else {
            NodoL* aux = inicio;
            while (aux != nullptr) {
                if (aux->libro.isbn == isbn) {
                    return true;
                }
                aux = aux->siguiente;
            }
        }
        return false;
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
            NodoL* medio = izquierda;
            for (int i = 0; i < (derecha - izquierda) / 2; ++i) {
                medio = medio->siguiente;
            }

            // Check if title is present at mid
            if (medio->libro.titulo == titulo) {
                return medio;
            }

            // If title greater, ignore left half
            if (medio->libro.titulo < titulo) {
                izquierda = medio->siguiente;
            } else { // If title is smaller, ignore right half
                derecha = medio->anterior;
            }
        }

        // if we reach here, then element was not present
        return nullptr;
    }

    vector<Libro> filtrarPorCategoria(const string& categoria) {
        vector<Libro> librosCategoria;
        NodoL* aux = inicio;
        while (aux != nullptr) {
            if (aux->libro.genero == categoria) {
                librosCategoria.push_back(aux->libro);
            }
            aux = aux->siguiente;
        }
        sort(librosCategoria.begin(), librosCategoria.end(), [](const Libro& a, const Libro& b) {
            return a.titulo < b.titulo;
        });
        return librosCategoria;
    }

    vector<string> obtenerCategorias() {
        map<string, bool> categorias;
        NodoL* aux = inicio;
        while (aux != nullptr) {
            categorias[aux->libro.genero] = true;
            aux = aux->siguiente;
        }
        vector<string> listaCategorias;
        for (const auto& categoria : categorias) {
            listaCategorias.push_back(categoria.first);
        }
        return listaCategorias;
    }

    friend ostream& operator<<(ostream& os, const ListaLibro& lista) {
        NodoL* aux = lista.inicio;
        while (aux != nullptr) {
            os << aux->libro << '\n';
            aux = aux->siguiente;
        }
        return os;
    }

    friend istream& operator>>(istream& is, ListaLibro& lista) {
        Libro libro;
        while (is >> libro) {
            lista.agregar(libro);
        }
        return is;
    }

    void guardarLibros() {
        ofstream archivo("libros.txt");
        if (archivo.fail()) {
            cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo << *this; // Usar la sobrecarga del operador <<
    }

    void cargarLibros() {
        ifstream archivo("libros.txt");
        if (archivo.fail()) {
            cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo >> *this; // Usar la sobrecarga del operador >>
    }
};

#endif
