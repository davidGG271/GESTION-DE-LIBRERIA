#ifndef LISTAUSU_H
#define LISTAUSU_H

#include "Usuario.h"
#include <iostream>
#include <fstream>

struct NodoU {
	Usuario usuario;
	NodoU* anterior;
	NodoU* siguente;
};

class ListaUsuario{
	
	private:
		NodoU* inicio;
		NodoU* final;
	
	public:
		
		ListaUsuario(){
			inicio=nullptr;
			final=nullptr;
		}
		
		void agregar(Usuario usuario){
			NodoU* nodoNuevo = new NodoU{usuario,nullptr,nullptr};
			if(inicio==nullptr){
				
				inicio = nodoNuevo;
				final = nodoNuevo;
				
			}else{
				nodoNuevo->anterior = final;
				final->siguente = nodoNuevo;
				final = nodoNuevo;
				final->siguente=nullptr;
			}
		}
		
		void eliminar(string id){
			if(inicio==nullptr){
				cout<<"No hay usuarios registrados"<<endl;
			}
			
			if(!UsuarioExiste(id)){
				cout<<"El usuario no existe"<<endl;
			}
			
			if(inicio->usuario.id == id) {
				NodoU* auxI = inicio;
				inicio = inicio->siguente;
			
				if (inicio != NULL)
			        inicio->anterior = NULL;
			
			    delete auxI;
			}else if(final->usuario.id==id){
			  	NodoU* auxF = final;
			  	final = final->anterior;
			  	
			  	if(final!=nullptr){
			  		final->siguente = nullptr;	
				}
				delete auxF;
			}else{
				NodoU* aux = inicio;
				
				while(aux != nullptr && aux->usuario.id!=id){
					aux=aux->siguente;
				}
				
				if(aux!=nullptr){
					NodoU* auxA = aux->anterior;
					NodoU* auxS = aux->siguente;
					
					auxA->siguente = auxS;
					
					if(auxS!=nullptr){
						auxS->anterior = auxA;
					}
					delete aux;
					cout << "\033[2J\033[1;1H";
      				cout << "Medico eliminado exitosamente!" << endl;
				}
			}
		}
		
		
		bool UsuarioExiste(string id){
			bool existe = false;
			
			if(inicio==nullptr){
				return existe;
			}else{
				NodoU* aux = inicio;
				
				while(aux!=nullptr){
					cout<<"bbaaa"<<endl;
					if(aux->usuario.id==id){
						existe = true;
						return existe;
					}
					aux = aux->siguente;
				}
			}
			return existe;
		}
		
		NodoU* encontrarUsuario(string id){
			if(inicio == nullptr){
			    return nullptr;
			}else{
				NodoU *aux = inicio;
			    while(aux != nullptr){
					if(aux->usuario.id == id){
				        return aux;
			      	}
			      aux = aux->siguente;
			    }
			  }
			
			  return nullptr;
		}
		
	
};

#endif
