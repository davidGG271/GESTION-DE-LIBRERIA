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

struct ArbolUsuario{
		
	public:
		NodoArbolUsuario* raiz;
		
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
		
		void eliminar(string id){
			raiz = eliminarNodo(raiz, id);
		}
		
		void editar(Usuario usuario){
			raiz = editarNodo(raiz, usuario);
		}
		
		void reinsertarBalanceado() {
            vector<Usuario> lista = getListaOrdenada();
            raiz = construirArbolBalanceado(lista, 0, lista.size() - 1);
        }
        
        int getAltura(){
        	return alturaRec(raiz);
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
	    
	    NodoArbolUsuario* eliminarNodo(NodoArbolUsuario* nodo, string& id){
	    	if(nodo!=nullptr){
	    		// si el puntero es nulo, lo retornara
	    		return nodo;
			}
			
			if(id<nodo->usuario.id){
				//si el id a encontrar es menor al id del nodo, pasara al nodo
				//izquierdo
				nodo->izquierda = eliminarNodo(nodo->izquierda, id);
			}else if(id>nodo->usuario.id){
				//si el id a encontrar es mayor al id del nodo, pasara al nodo
				//derecho
				nodo->derecha = eliminarNodo(nodo->derecha, id);
			}else{
				//Si lo encuetra, pasara varificar si tiene 1 o 0 hijos...
				if (nodo->izquierda == nullptr) {
					// guarda el valor del nodo hijo derecho, borra el nodo padre, y 
					//toma su lugar
		            NodoArbolUsuario* temp = nodo->derecha;
		            delete nodo;
		            return temp;
		        } else if (nodo->derecha == nullptr) {
		        	// guarda el valor del nodo hijo izquierdo, borra el nodo padre, y 
					//toma su lugar
		            NodoArbolUsuario* temp = nodo->izquierda;
		            delete nodo;
		            return temp;
					}
				
				//Si tiene 2 hijos, guardamos el menor nodo del subarbol derecho	
				NodoArbolUsuario* temp = encontrarMinimo(nodo->derecha);
				
				//Al nodo a eliminar le asignamos el valor de nodo temp...
				temp->usuario = nodo->usuario;
				
				//pasamos a buscar al antiguo nodo que tenia almacenado el menor valor del subarbol
				nodo->derecha = eliminarNodo(nodo->derecha, temp->usuario.id);
				
			}
			return nodo;
		}
		
		NodoArbolUsuario* encontrarMinimo(NodoArbolUsuario* nodo) {
		    while (nodo->izquierda != nullptr) {
		        nodo = nodo->izquierda;
		    }
		    return nodo;
		}
		
		NodoArbolUsuario* editarNodo(NodoArbolUsuario* nodo, Usuario usuario){
			if (nodo == nullptr) {
	            return nodo;
	        }
			
	        if (nodo->usuario.id == usuario.id) {
	        	nodo->usuario = usuario;
	            return nodo;
	        }
	
	        if (comparar(nodo->usuario.id,usuario.id)) {
	            nodo->izquierda = editarNodo(nodo->izquierda, usuario);
	        } else {
	            nodo->derecha = editarNodo(nodo->derecha, usuario);
	        }
		}
		
	    void getLista(NodoArbolUsuario* nodo, vector<Usuario>& lista){
	    	if(nodo!=nullptr){
				getLista(nodo->izquierda,lista);
				lista.push_back(nodo->usuario);
				getLista(nodo->derecha,lista);
			}
		}
		
		NodoArbolUsuario* construirArbolBalanceado(vector<Usuario>& lista, int inicio, int fin) {
            if (inicio > fin) {
                return nullptr;
            }
            int medio = inicio + (fin - inicio) / 2;
            NodoArbolUsuario* nodo = new NodoArbolUsuario{lista[medio], nullptr, nullptr};
            nodo->izquierda = construirArbolBalanceado(lista, inicio, medio - 1);
            nodo->derecha = construirArbolBalanceado(lista, medio + 1, fin);
            return nodo;
        }
	    
	    int alturaRec(NodoArbolUsuario* nodo) {
            if (nodo == nullptr) {
                return 0; // Un nodo nulo tiene altura 0
            }
            int alturaIzquierda = alturaRec(nodo->izquierda);
            int alturaDerecha = alturaRec(nodo->derecha);
            return 1 + max(alturaIzquierda, alturaDerecha);
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

