#ifndef ARBOLPRESTAMO_H_INCLUDED
#define ARBOLPRESTAMO_H_INCLUDED

#include "Prestamo.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct NodoArbolPrestamo {
    Prestamo prestamo;
    NodoArbolPrestamo* izquierda;
    NodoArbolPrestamo* derecha;

    friend ostream& operator<<(ostream& os, const NodoArbolPrestamo& nodo) {
        os << nodo.prestamo;
        return os;
    }

    friend istream& operator>>(istream& is, NodoArbolPrestamo& nodo) {
        is >> nodo.prestamo;
        return is;
    }
};

class PrestamoArbol {
private:
    NodoArbolPrestamo* raiz;

public:
    PrestamoArbol() {
        raiz = nullptr;
    }

    void insertar(Prestamo prestamo) {
        raiz = insertarRec(raiz, prestamo);
    }

    NodoArbolPrestamo* buscar(string id) {
        return buscarRec(raiz, id);
    }

    void imprimir() {
        NodoArbolPrestamo* nodo = raiz;
        print(nodo);
    }

    vector<Prestamo> getListaOrdenada() {
        vector<Prestamo> lista;
        obtenerListaOrdenada(raiz, lista);
        return lista;
    }

    void eliminar(string id) {
        raiz = eliminarNodo(raiz, id);
    }

    void editar(Prestamo prestamo) {
        raiz = editarNodo(raiz, prestamo);
    }

    void reinsertarBalanceado() {
        vector<Prestamo> lista = getListaOrdenada();
        raiz = construirArbolBalanceado(lista, 0, lista.size() - 1);
    }

    int altura() {
        return calcularAltura(raiz);
    }

    void guardarPrestamos() {
        ofstream archivo("prestamos.txt");
        if (archivo.fail()) {
            cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo << *this;
    }

    void cargarPrestamos() {
        ifstream archivo("prestamos.txt");
        if (archivo.fail()) {
            cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo >> *this;
    }

    friend ostream& operator<<(ostream& os, const PrestamoArbol& arbol) {
        serializar(os, arbol.raiz);
        return os;
    }

    friend istream& operator>>(istream& is, PrestamoArbol& arbol) {
        arbol.raiz = deserializar(is);
        return is;
    }

private:
    NodoArbolPrestamo* insertarRec(NodoArbolPrestamo* nodo, Prestamo prestamo) {
        if (nodo == nullptr) {
            return new NodoArbolPrestamo{prestamo, nullptr, nullptr};
        }

        if (prestamo.id < nodo->prestamo.id) {
            nodo->izquierda = insertarRec(nodo->izquierda, prestamo);
        } else if (prestamo.id > nodo->prestamo.id) {
            nodo->derecha = insertarRec(nodo->derecha, prestamo);
        }

        return nodo;
    }

    NodoArbolPrestamo* buscarRec(NodoArbolPrestamo* nodo, string id) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (nodo->prestamo.id == id) {
            return nodo;
        }

        if (id < nodo->prestamo.id) {
            return buscarRec(nodo->izquierda, id);
        } else {
            return buscarRec(nodo->derecha, id);
        }
    }

    NodoArbolPrestamo* eliminarNodo(NodoArbolPrestamo* nodo, const string& id) {
        if (nodo == nullptr) {
            return nodo;
        }

        if (id < nodo->prestamo.id) {
            nodo->izquierda = eliminarNodo(nodo->izquierda, id);
        } else if (id > nodo->prestamo.id) {
            nodo->derecha = eliminarNodo(nodo->derecha, id);
        } else {
            if (nodo->izquierda == nullptr) {
                NodoArbolPrestamo* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == nullptr) {
                NodoArbolPrestamo* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }

            NodoArbolPrestamo* temp = encontrarMinimo(nodo->derecha);
            nodo->prestamo = temp->prestamo;
            nodo->derecha = eliminarNodo(nodo->derecha, temp->prestamo.id);
        }

        return nodo;
    }

    NodoArbolPrestamo* encontrarMinimo(NodoArbolPrestamo* nodo) {
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    NodoArbolPrestamo* editarNodo(NodoArbolPrestamo* nodo, const Prestamo& prestamo) {
        if (nodo == nullptr) {
            return nodo;
        }

        if (prestamo.id < nodo->prestamo.id) {
            nodo->izquierda = editarNodo(nodo->izquierda, prestamo);
        } else if (prestamo.id > nodo->prestamo.id) {
            nodo->derecha = editarNodo(nodo->derecha, prestamo);
        } else {
            nodo->prestamo = prestamo;
        }

        return nodo;
    }

    NodoArbolPrestamo* construirArbolBalanceado(vector<Prestamo>& lista, int inicio, int fin) {
        if (inicio > fin) {
            return nullptr;
        }
        int medio = inicio + (fin - inicio) / 2;
        NodoArbolPrestamo* nodo = new NodoArbolPrestamo{lista[medio], nullptr, nullptr};
        nodo->izquierda = construirArbolBalanceado(lista, inicio, medio - 1);
        nodo->derecha = construirArbolBalanceado(lista, medio + 1, fin);
        return nodo;
    }

    void obtenerListaOrdenada(NodoArbolPrestamo* nodo, vector<Prestamo>& lista) {
        if (nodo != nullptr) {
            obtenerListaOrdenada(nodo->izquierda, lista);
            lista.push_back(nodo->prestamo);
            obtenerListaOrdenada(nodo->derecha, lista);
        }
    }

    int calcularAltura(NodoArbolPrestamo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzquierda = calcularAltura(nodo->izquierda);
        int alturaDerecha = calcularAltura(nodo->derecha);
        return max(alturaIzquierda, alturaDerecha) + 1;
    }

    void print(NodoArbolPrestamo* nodo) {
        if (nodo != nullptr) {
            print(nodo->izquierda);
            cout << nodo->prestamo.id << "\t" << nodo->prestamo.fechaSalida << "\n";
            print(nodo->derecha);
        }
    }

    static void serializar(ostream& os, NodoArbolPrestamo* nodo) {
        if (nodo == nullptr) {
            os << "#\n";
        } else {
            os << nodo->prestamo << '\n';
            serializar(os, nodo->izquierda);
            serializar(os, nodo->derecha);
        }
    }

    static NodoArbolPrestamo* deserializar(istream& is) {
        string id;
        getline(is, id);

        if (id == "#") {
            return nullptr;
        }

        Prestamo prestamo;
        prestamo.id = id;
        getline(is, prestamo.fechaDevolucion);
        getline(is, prestamo.fechaSalida);
        size_t librosSize;
        is >> librosSize;
        is.ignore();
        prestamo.isbnLibros.resize(librosSize);
        for (auto& isbnLibro : prestamo.isbnLibros) {
            getline(is, isbnLibro);
        }
        getline(is, prestamo.idUsuario);

        NodoArbolPrestamo* nodo = new NodoArbolPrestamo{prestamo, nullptr, nullptr};
        nodo->izquierda = deserializar(is);
        nodo->derecha = deserializar(is);

        return nodo;
    }
};


#endif // ARBOLPRESTAMO_H_INCLUDED
