#ifndef LISTAPRESTAMO_H
#define LISTAPRESTAMO_H

#include "NodoPrestamo.h"
#include <iostream>
#include <fstream>

class ListaPrestamo {
    
private:
    NodoP* inicio;
    NodoP* final;
    
public:
    ListaPrestamo() : inicio(nullptr), final(nullptr) {}

    void agregar(NodoP* nodoNuevo) {
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

    void eliminar(string id) {
        if (inicio == nullptr) {
            cout << "No hay préstamos registrados" << endl;
            return;
        }

        if (!PrestamoExiste(id)) {
            cout << "El préstamo no existe" << endl;
            return;
        }

        if (inicio->prestamo.id == id) {
            NodoP* auxI = inicio;
            inicio = inicio->siguiente;
            if (inicio != NULL) {
                inicio->anterior = NULL;
            }
            delete auxI;
        } else if (final->prestamo.id == id) {
            NodoP* auxF = final;
            final = final->anterior;
            if (final != nullptr) {
                final->siguiente = nullptr;
            }
            delete auxF;
        } else {
            NodoP* aux = inicio;
            while (aux != nullptr && aux->prestamo.id != id) {
                aux = aux->siguiente;
            }
            if (aux != nullptr) {
                NodoP* auxA = aux->anterior;
                NodoP* auxS = aux->siguiente;
                auxA->siguiente = auxS;
                if (auxS != nullptr) {
                    auxS->anterior = auxA;
                }
                delete aux;
                cout << "Préstamo eliminado exitosamente!" << endl;
            }
        }
    }

    bool PrestamoExiste(string id) {
        if (inicio == nullptr) {
            return false;
        } else {
            NodoP* aux = inicio;
            while (aux != nullptr) {
                if (aux->prestamo.id == id) {
                    return true;
                }
                aux = aux->siguiente;
            }
        }
        return false;
    }

    NodoP* encontrarPrestamo(string id) {
        if (inicio == nullptr) {
            return nullptr;
        } else {
            NodoP* aux = inicio;
            while (aux != nullptr) {
                if (aux->prestamo.id == id) {
                    return aux;
                }
                aux = aux->siguiente;
            }
        }
        return nullptr;
    }

    friend ostream& operator<<(ostream& os, const ListaPrestamo& lista) {
        NodoP* aux = lista.inicio;
        while (aux != nullptr) {
            os << aux->prestamo << '\n';
            aux = aux->siguiente;
        }
        return os;
    }

    friend istream& operator>>(istream& is, ListaPrestamo& lista) {
        Prestamo prestamo;
        while (is >> prestamo) {
            NodoP* nodo = new NodoP();
            nodo->prestamo = prestamo;
            lista.agregar(nodo);
        }
        return is;
    }

    void guardarPrestamos() {
        ofstream archivo("prestamos.txt");
        if (archivo.fail()) {
            cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo << *this; // Usar la sobrecarga del operador <<
    }

    void cargarPrestamos() {
        ifstream archivo("prestamos.txt");
        if (archivo.fail()) {
            cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo >> *this; // Usar la sobrecarga del operador >>
    }
};

#endif
