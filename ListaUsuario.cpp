#ifndef LISTAUSU_H
#define LISTAUSU_H

#include "Usuario_h"
#include "NodoUsu_h"
#include <iostream>


class ListaUsuario{
	
	private:
		NodoU* inicio;
		NodoU* final;
	
	public:
		ListaUsuario();
		
		ListaUsuario(){
			inicio=nullptr;
			final=nullptr;
		}
		
		void agregar(NodoU* nodoNuevo){
			
			if(inicio==nullptr){
				inicio = nodoNuevo;
				final = nodoNuevo;
				nodoNuevo->anterior=nullptr;
				nodoNuevo->siguente=nullptr;
				
			}else{
				nodoNuevo->anterior = final;
				final->siguente = nodoNuevo;
				fin = nodoNuevo;
				final->siguente=nullptr;
			}
		}
		
		void eliminar(int id){
			if(inicio==nullptr){
				cout<<"No hay usuarios registrados"<<endl;
			}
			
			if(!UsuarioExiste(id)){
				cout<<"El usuario no existe"<<endl;
			}
			
			if(inicio->usuario.id == id) {
				NodoM* auxI = inicio;
				inicio = inicio->der;
			
				if (inicio != NULL)
			        inicio->anterior = NULL;
			
			    delete auxI;
			}else if(final->usuario.id==dni){
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
		
		
		
		bool UsuarioExiste(int id){
			bool existe = false;
			
			if(inicio==nullptr){
				return existe;
			}else{
				NodoU* aux = inicio;
				
				while(aux!=nullptr){
					if(aux->usuario.id==id){
						existe = true;
						return existe;
					}
					aux = aux->siguente;
				}
			}
			return existe;
		}
		
		
		
		
	
};

#endif

