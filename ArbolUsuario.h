#ifndef ARBOLUSUARIO_H
#define ARBOLUSUARIO_H

#include "Usuario.h"
#include <functional>
#include <iostream>
#include <vector>


template <typename T>
bool comparar(const T& a, const T& b) {
    return a > b; // Cambia aquí según el tipo de comparación que necesites
}

struct NodoArbolUsuario {
    Usuario usuario;
    NodoArbolUsuario* izquierda;
    NodoArbolUsuario* derecha;
};

class ArbolUsuario{
	private:
		NodoArbolUsuario* raiz;
	
	public:
		ArbolUsuario() {
	        raiz = nullptr;
	    }
	    
	    void agregar(Usuario usuario) {
	    	raiz = agregarNodo(raiz, usuario);
		}
	
	    bool buscar(string id) {
	        return buscarRec(raiz, id);
	    }
	    
	    vector<Usuario> getListaOrdenada(){
	    	NodoArbolUsuario* nodo=raiz;
	    	vector<Usuario> lista;
	    	getLista(nodo, lista);
	    	return lista;
		}
	    
	    void imprimir(){
	    	NodoArbolUsuario* nodo=raiz;
	    	print(nodo);
		}
	    
	private:
		NodoArbolUsuario* agregarNodo(NodoArbolUsuario* nodo, Usuario usuario){
			if(nodo == nullptr){//si el puntero es nulo, se procedera a crear el nodo
				NodoArbolUsuario* actual = new NodoArbolUsuario{usuario,nullptr,nullptr};
				return actual;
			}
			if(comparar(nodo->usuario.id,usuario.id)){
				// si el nodo padre tiene un libro con un titulo de mayor valor en base al codigo ASCII, este pasara a por la misma funcion
				//con el nodo hijo izquierdo
				nodo->izquierda = agregarNodo(nodo->izquierda,usuario);
			}else if(comparar(usuario.id,nodo->usuario.id)){
				// si el nodo padre tiene un libro con un titulo de menor valor en base al codigo ASCII, este pasara a por la misma funcion
				//con el nodo hijo derecho
				nodo->derecha = agregarNodo(nodo->derecha,usuario);
			}
			return nodo;
		}
		
		bool buscarRec(NodoArbolUsuario* nodo, string& id) {
	        if (nodo == nullptr) {
	            return false;
	        }
			
	        if (nodo->usuario.id == id) {
	            return true;
	        }
	
	        if (comparar(nodo->usuario.id,id)) {
	            return buscarRec(nodo->izquierda, id);
	        } else {
	            return buscarRec(nodo->derecha, id);
	        }
	    }
	    
	    void getLista(NodoArbolUsuario* nodo, vector<Usuario>& lista){
	    	if(nodo!=nullptr){
				getLista(nodo->izquierda,lista);
				lista.push_back(nodo->usuario);
				getLista(nodo->derecha,lista);
			}
		}
	    
	    void print(NodoArbolUsuario* nodo){
			if(nodo!=nullptr){
				print(nodo->izquierda);
				cout<<nodo->usuario.id<<"\t";
				print(nodo->derecha);
			}
		}
	
};

#endif

