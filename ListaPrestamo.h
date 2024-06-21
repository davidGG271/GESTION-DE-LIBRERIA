#ifndef LISTAPRESTAMO_H
#define LISTAPRESTAMO_H

#include "Prestamo.h"
#include <iostream>

struct NodoP{
    Prestamo prestamo;
    NodoP* anterior;
    NodoP* siguiente;
};

class ListaPrestamo{
    
    private:
        NodoP* inicio;
        NodoP* final;
    
    public:
        
        ListaPrestamo(){
            inicio=nullptr;
            final=nullptr;
        }
        
        void agregar(Prestamo prestamo){
            NodoP* nodoNuevo = new NodoP{prestamo,nullptr,nullptr};
            if(inicio==nullptr){
                inicio = nodoNuevo;
                final = nodoNuevo;
            }else{
                nodoNuevo->anterior = final;
                final->siguiente = nodoNuevo;
                final = nodoNuevo;
                final->siguiente=nullptr;
            }
        }
        
        void eliminar(string id){
            if(inicio==nullptr){
                cout<<"No hay préstamos registrados"<<endl;
            }
            
            if(!PrestamoExiste(id)){
                cout<<"El préstamo no existe"<<endl;
            }
            
            if(inicio->prestamo.id == id) {
                NodoP* auxI = inicio;
                inicio = inicio->siguiente;
            
                if (inicio != NULL)
                    inicio->anterior = NULL;
            
                delete auxI;
            }else if(final->prestamo.id==id){
                NodoP* auxF = final;
                final = final->anterior;
                
                if(final!=nullptr){
                    final->siguiente = nullptr;    
                }
                delete auxF;
            }else{
                NodoP* aux = inicio;
                
                while(aux != nullptr && aux->prestamo.id!=id){
                    aux=aux->siguiente;
                }
                
                if(aux!=nullptr){
                    NodoP* auxA = aux->anterior;
                    NodoP* auxS = aux->siguiente;
                    
                    auxA->siguiente = auxS;
                    
                    if(auxS!=nullptr){
                        auxS->anterior = auxA;
                    }
                    delete aux;
                    cout << "\033[2J\033[1;1H";
                    cout << "Préstamo eliminado exitosamente!" << endl;
                }
            }
        }
        
        
        bool PrestamoExiste(string id){
            bool existe = false;
            
            if(inicio==nullptr){
                return existe;
            }else{
                NodoP* aux = inicio;
                
                while(aux!=nullptr){
                    cout<<"bbaaa"<<endl;
                    if(aux->prestamo.id==id){
                        existe = true;
                        return existe;
                    }
                    aux = aux->siguiente;
                }
            }
            return existe;
        }
        
        NodoP* encontrarPrestamo(string id){
            if(inicio == nullptr){
                return nullptr;
            }else{
                NodoP *aux = inicio;
                while(aux != nullptr){
                    if(aux->prestamo.id == id){
                        return aux;
                    }
                    aux = aux->siguiente;
                }
            }
            
            return nullptr;
        }
        
    
};

#endif
