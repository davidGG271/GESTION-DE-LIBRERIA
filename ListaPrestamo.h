#ifndef LISTAPRESTAMO_H
#define LISTAPRESTAMO_H

#include "Prestamo.h"
#include <iostream>

struct NodoP {
    Prestamo prestamo;
    NodoP* anterior;
    NodoP* siguiente;

    NodoP(const Prestamo& prestamo) : prestamo(prestamo), anterior(nullptr), siguiente(nullptr) {}

    friend std::ostream& operator<<(std::ostream& os, const NodoP& nodo) {
        os << nodo.prestamo;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, NodoP& nodo) {
        is >> nodo.prestamo;
        return is;
    }
};

class ListaPrestamo {
private:
    NodoP* inicio;
    NodoP* final;

public:
    ListaPrestamo() : inicio(nullptr), final(nullptr) {}

    void agregar(Prestamo prestamo) {
        NodoP* nodoNuevo = new NodoP(prestamo);
        if (inicio == nullptr) {
            inicio = nodoNuevo;
            final = nodoNuevo;
        } else {
            nodoNuevo->anterior = final;
            final->siguiente = nodoNuevo;
            final = nodoNuevo;
        }
    }

    void eliminar(std::string id) {
        if (inicio == nullptr) {
            std::cout << "No hay préstamos registrados" << std::endl;
            return;
        }

        if (!PrestamoExiste(id)) {
            std::cout << "El préstamo no existe" << std::endl;
            return;
        }

        if (inicio->prestamo.id == id) {
            NodoP* auxI = inicio;
            inicio = inicio->siguiente;
            if (inicio != nullptr) {
                inicio->anterior = nullptr;
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
                std::cout << "Préstamo eliminado exitosamente!" << std::endl;
            }
        }
    }

    bool PrestamoExiste(std::string id) {
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

    NodoP* encontrarPrestamo(std::string id) {
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

    friend std::ostream& operator<<(std::ostream& os, const ListaPrestamo& lista) {
        NodoP* aux = lista.inicio;
        while (aux != nullptr) {
            os << aux->prestamo << '\n';
            aux = aux->siguiente;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ListaPrestamo& lista) {
        Prestamo prestamo;
        while (is >> prestamo) {
            lista.agregar(prestamo);
        }
        return is;
    }

    void guardarPrestamos() {
        std::ofstream archivo("prestamos.txt");
        if (archivo.fail()) {
            std::cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo << *this;
    }

    void cargarPrestamos() {
        std::ifstream archivo("prestamos.txt");
        if (archivo.fail()) {
            std::cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo >> *this;
    }
    
};

#endif
