#ifndef ISBNARBOLDELIBROS_H
#define ISBNARBOLDELIBROS_H

#include "Libro.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct NodoArbol {
    Libro libro;
    NodoArbol* izquierda;
    NodoArbol* derecha;
    
    friend std::ostream& operator<<(std::ostream& os, const NodoArbol& nodo) {
        os << nodo.libro;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, NodoArbol& nodo) {
        is >> nodo.libro;
        return is;
    }
};

class ISBNArbolLibro {
	private:
	    NodoArbol* raiz;

	public:
	    ISBNArbolLibro() {
	        raiz = nullptr;
	    }

	    void insertar(Libro libro) {
	        raiz = insertarRec(raiz, libro);
	    }

	    NodoArbol* buscar(string isbn) {
	        return buscarRec(raiz, isbn);
	    }

	    void imprimir(){
	    	NodoArbol* nodo=raiz;
	    	print(nodo);
		}

	    vector<Libro> getListaOrdenada() {
		    vector<Libro> lista;
		    obtenerListaOrdenada(raiz, lista);
		    return lista;
		}

		void eliminar(string isbn) {
		    raiz = eliminarNodo(raiz, isbn);
		}

		void editar(Libro libro) {
		    raiz = editarNodo(raiz, libro);
		}

		void reinsertarBalanceado() {
            vector<Libro> lista = getListaOrdenada();
            raiz = construirArbolBalanceado(lista, 0, lista.size() - 1);
        }

        int altura() {
            return calcularAltura(raiz);
        }
        
        void guardarLibros() {
            std::ofstream archivo("libros.txt");
            if (archivo.fail()) {
                std::cout << "No se puede abrir el archivo.\n";
                return;
            }
            archivo << *this;
		}

        void cargarLibros() {
            std::ifstream archivo("libros.txt");
            if (archivo.fail()) {
                std::cout << "No se puede abrir el archivo.\n";
                return;
            }
            archivo >> *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const ISBNArbolLibro& arbol) {
            serializar(os, arbol.raiz);
            return os;
        }

        friend std::istream& operator>>(std::istream& is, ISBNArbolLibro& arbol) {
            arbol.raiz = deserializar(is);
            return is;
		}

	private:
	    NodoArbol* insertarRec(NodoArbol* nodo, Libro libro) {
	        if (nodo == nullptr) {
	            NodoArbol* nuevoNodo = new NodoArbol{libro,nullptr,nullptr};
	            return nuevoNodo;
	        }

	        if (libro.isbn < nodo->libro.isbn) {
	            nodo->izquierda = insertarRec(nodo->izquierda, libro);
	        } else if (libro.isbn > nodo->libro.isbn) {
	            nodo->derecha = insertarRec(nodo->derecha, libro);
	        }

	        return nodo;
	    }

	    NodoArbol* buscarRec(NodoArbol* nodo, string isbn) {
	        if (nodo == nullptr) {
	            return nullptr;
	        }

	        if (nodo->libro.isbn == isbn) {
	            return nodo;
	        }

	        if (isbn < nodo->libro.isbn) {
	            return buscarRec(nodo->izquierda, isbn);
	        } else {
	            return buscarRec(nodo->derecha, isbn);
	        }
	    }

	    NodoArbol* eliminarNodo(NodoArbol* nodo, const string& isbn) {
		    if (nodo == nullptr) {
		        return nodo; // Caso base: �rbol vac�o o nodo no encontrado
		    }

		    if (isbn < nodo->libro.isbn) {
		        nodo->izquierda = eliminarNodo(nodo->izquierda, isbn);
		    } else if (isbn > nodo->libro.isbn) {
		        nodo->derecha = eliminarNodo(nodo->derecha, isbn);
		    } else {
		        // Nodo encontrado
		        if (nodo->izquierda == nullptr) {
		            NodoArbol* temp = nodo->derecha;
		            delete nodo;
		            return temp;
		        } else if (nodo->derecha == nullptr) {
		            NodoArbol* temp = nodo->izquierda;
		            delete nodo;
		            return temp;
		        }

		        NodoArbol* temp = encontrarMinimo(nodo->derecha);
		        nodo->libro = temp->libro;
		        nodo->derecha = eliminarNodo(nodo->derecha, temp->libro.isbn);
		    }

			return nodo;

		}

		NodoArbol* encontrarMinimo(NodoArbol* nodo) {
		    while (nodo->izquierda != nullptr) {
		        nodo = nodo->izquierda;
		    }
		    return nodo;
		}

		NodoArbol* editarNodo(NodoArbol* nodo, const Libro& libro) {
		    if (nodo == nullptr) {
		        return nodo; // Caso base: nodo no encontrado
		    }

		    if (libro.titulo < nodo->libro.titulo) {
		        nodo->izquierda = editarNodo(nodo->izquierda, libro);
		    } else if (libro.titulo> nodo->libro.titulo) {
		        nodo->derecha = editarNodo(nodo->derecha, libro);
		    } else {
		        // Nodo encontrado, actualizar el libro
		        nodo->libro = libro;
		    }

		    return nodo;
		}

		NodoArbol* construirArbolBalanceado(vector<Libro>& lista, int inicio, int fin) {
            if (inicio > fin) {
                return nullptr;
            }
            int medio = inicio + (fin - inicio) / 2;
            NodoArbol* nodo = new NodoArbol{lista[medio], nullptr, nullptr};
            nodo->izquierda = construirArbolBalanceado(lista, inicio, medio - 1);
            nodo->derecha = construirArbolBalanceado(lista, medio + 1, fin);
            return nodo;
        }

        void obtenerListaOrdenada(NodoArbol* nodo, vector<Libro>& lista) {
		    if (nodo != nullptr) {
		        obtenerListaOrdenada(nodo->izquierda, lista);
		        lista.push_back(nodo->libro);
		        obtenerListaOrdenada(nodo->derecha, lista);
		    }
		}

		int calcularAltura(NodoArbol* nodo) {
	            if (nodo == nullptr) {
	                return 0;
	            }
	            int alturaIzquierda = calcularAltura(nodo->izquierda);
	            int alturaDerecha = calcularAltura(nodo->derecha);
	            return max(alturaIzquierda, alturaDerecha) + 1;
        }

        void print(NodoArbol* nodo){
			if(nodo!=nullptr){
				print(nodo->izquierda);
				cout<<nodo->libro.isbn<<"\t";
				print(nodo->derecha);
			}
		}
		
		static void serializar(std::ostream& os, NodoArbol* nodo) {
            if (nodo == nullptr) {
                os << "#\n";
            } else {
                os << nodo->libro; // Utiliza el operador << de Libro para serializar el libro
                serializar(os, nodo->izquierda);
                serializar(os, nodo->derecha);
            }
        }

        static NodoArbol* deserializar(std::istream& is) {
            std::string isbn;
            std::getline(is, isbn);

            if (isbn == "#") {
                return nullptr;
            }

            Libro libro;
            libro.isbn = isbn;

            getline(is, libro.autor);
            is >> libro.ano_publicacion;
            is.ignore();
            getline(is, libro.genero);
            getline(is, libro.titulo);
            getline(is, libro.editorial);
            is >> libro.num_paginas;
            is.ignore();
            getline(is, libro.descripcion);
            getline(is, libro.fecha_adquisicion);
            getline(is, libro.lenguaje);
            is >> libro.stock;
            is.ignore();

            NodoArbol* nodo = new NodoArbol{libro, nullptr, nullptr};

            nodo->izquierda = deserializar(is);
            nodo->derecha = deserializar(is);

            return nodo;
		}
};

#endif // ISBNARBOLDELIBROS_H
