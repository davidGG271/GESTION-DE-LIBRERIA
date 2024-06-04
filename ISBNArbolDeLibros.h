
#include <iostream>
using namespace std;

struct NodoArbol {
    string isbn;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};

class ISBNArbolLibro {
	private:
	    NodoArbol* raiz;
	
	public:
	    ISBNArbolLibro() {
	        raiz = nullptr;
	    }
	
	    void insertar(string isbn) {
	        raiz = insertarRec(raiz, isbn);
	    }
	
	    bool buscar(string isbn) {
	        return buscarRec(raiz, isbn);
	    }
	
	private:
	    NodoArbol* insertarRec(NodoArbol* nodo, string isbn) {
	        if (nodo == nullptr) {
	            NodoArbol* nuevoNodo = new NodoArbol();
	            nuevoNodo->isbn = isbn;
	            nuevoNodo->izquierda = nullptr;
	            nuevoNodo->derecha = nullptr;
	            return nuevoNodo;
	        }
	
	        if (isbn < nodo->isbn) {
	            nodo->izquierda = insertarRec(nodo->izquierda, isbn);
	        } else if (isbn > nodo->isbn) {
	            nodo->derecha = insertarRec(nodo->derecha, isbn);
	        }
	
	        return nodo;
	    }
	
	    bool buscarRec(NodoArbol* nodo, string isbn) {
	        if (nodo == nullptr) {
	            return false;
	        }
	
	        if (nodo->isbn == isbn) {
	            return true;
	        }
	
	        if (isbn < nodo->isbn) {
	            return buscarRec(nodo->izquierda, isbn);
	        } else {
	            return buscarRec(nodo->derecha, isbn);
	        }
	    }
};
