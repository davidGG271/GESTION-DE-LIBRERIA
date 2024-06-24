#ifndef ARBOLUSUARIO_H
#define ARBOLUSUARIO_H

#include "Usuario.h"
#include <functional>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> // Necesario para std::istringstream y std::ostringstream

template <typename T>
bool comparar(const T& a, const T& b) {
    return a > b; // Cambia aqu� seg�n el tipo de comparaci�n que necesites
}

struct NodoArbolUsuario {
    Usuario usuario;
    NodoArbolUsuario* izquierda;
    NodoArbolUsuario* derecha;

    friend std::ostream& operator<<(std::ostream& os, const NodoArbolUsuario& nodo) {
        os << nodo.usuario;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, NodoArbolUsuario& nodo) {
        is >> nodo.usuario;
        return is;
    }
};

struct ArbolUsuario {
    NodoArbolUsuario* raiz;

    ArbolUsuario() : raiz(nullptr) {}

    void agregar(Usuario usuario) {
        raiz = agregarNodo(raiz, usuario);
    }

    NodoArbolUsuario* buscar(string id) {
        return buscarRec(raiz, id);
    }

    std::vector<Usuario> getListaOrdenada() {
        NodoArbolUsuario* nodo = raiz;
        std::vector<Usuario> lista;
        getLista(nodo, lista);
        return lista;
    }

    void imprimir() {
        NodoArbolUsuario* nodo = raiz;
        print(nodo);
    }

    void eliminar(std::string id) {
        raiz = eliminarNodo(raiz, id);
    }

    void editar(Usuario usuario) {
        raiz = editarNodo(raiz, usuario);
    }

    void reinsertarBalanceado() {
        std::vector<Usuario> lista = getListaOrdenada();
        raiz = construirArbolBalanceado(lista, 0, lista.size() - 1);
    }

    int getAltura() {
        return alturaRec(raiz);
    }

    int getLongitud(){
        return contarNodosRec(raiz);
    }

    void guardarUsuarios() {
        std::ofstream archivo("usuarios.txt");
        if (archivo.fail()) {
            std::cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo << *this;
    }

    void cargarUsuarios() {
        std::ifstream archivo("usuarios.txt");
        if (archivo.fail()) {
            std::cout << "No se puede abrir el archivo.\n";
            return;
        }
        archivo >> *this;
    }

    NodoArbolUsuario* verificarInicioSesion(const std::string& correo, const std::string& contrasenia) {
        return verificarRec(raiz, correo, contrasenia);
    }

    friend std::ostream& operator<<(std::ostream& os, const ArbolUsuario& arbol) {
        serializar(os, arbol.raiz);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ArbolUsuario& arbol) {
        arbol.raiz = deserializar(is);
        return is;
    }

private:
    NodoArbolUsuario* agregarNodo(NodoArbolUsuario* nodo, Usuario usuario) {
        if (nodo == nullptr) {
            NodoArbolUsuario* actual = new NodoArbolUsuario{usuario, nullptr, nullptr};
            return actual;
        }
        if (comparar(nodo->usuario.id, usuario.id)) {
            nodo->izquierda = agregarNodo(nodo->izquierda, usuario);
        } else if (comparar(usuario.id, nodo->usuario.id)) {
            nodo->derecha = agregarNodo(nodo->derecha, usuario);
        }
        return nodo;
    }

    NodoArbolUsuario* verificarRec(NodoArbolUsuario* nodo, const string& correo, const string& contrasenia) {
        if (nodo == nullptr) {
            return nullptr;
        }
        if (nodo->usuario.correo == correo && nodo->usuario.contrasenia == contrasenia) {
            return nodo;
        }
        NodoArbolUsuario* izquierda = verificarRec(nodo->izquierda, correo, contrasenia);
        if (izquierda != nullptr) {
            return izquierda;
        }
        return verificarRec(nodo->derecha, correo, contrasenia);
    }


    NodoArbolUsuario* buscarRec(NodoArbolUsuario* nodo, string id) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (nodo->usuario.id == id) {
            return nodo;
        }

        if (id < nodo->usuario.id) {
            return buscarRec(nodo->izquierda, id);
        } else {
            return buscarRec(nodo->derecha, id);
        }
    }

    NodoArbolUsuario* eliminarNodo(NodoArbolUsuario* nodo, std::string& id) {
        if (nodo == nullptr) {
            return nodo;
        }
        if (id < nodo->usuario.id) {
            nodo->izquierda = eliminarNodo(nodo->izquierda, id);
        } else if (id > nodo->usuario.id) {
            nodo->derecha = eliminarNodo(nodo->derecha, id);
        } else {
            if (nodo->izquierda == nullptr) {
                NodoArbolUsuario* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == nullptr) {
                NodoArbolUsuario* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }
            NodoArbolUsuario* temp = encontrarMinimo(nodo->derecha);
            nodo->usuario = temp->usuario;
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

    NodoArbolUsuario* editarNodo(NodoArbolUsuario* nodo, Usuario usuario) {
        if (nodo == nullptr) {
            return nodo;
        }
        if (nodo->usuario.id == usuario.id) {
            nodo->usuario = usuario;
            return nodo;
        }
        if (comparar(nodo->usuario.id, usuario.id)) {
            nodo->izquierda = editarNodo(nodo->izquierda, usuario);
        } else {
            nodo->derecha = editarNodo(nodo->derecha, usuario);
        }
        return nodo;
    }

    void getLista(NodoArbolUsuario* nodo, std::vector<Usuario>& lista) {
        if (nodo != nullptr) {
            getLista(nodo->izquierda, lista);
            lista.push_back(nodo->usuario);
            getLista(nodo->derecha, lista);
        }
    }

    NodoArbolUsuario* construirArbolBalanceado(std::vector<Usuario>& lista, int inicio, int fin) {
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
            return 0;
        }
        int alturaIzquierda = alturaRec(nodo->izquierda);
        int alturaDerecha = alturaRec(nodo->derecha);
        return 1 + std::max(alturaIzquierda, alturaDerecha);
    }

    int contarNodosRec(NodoArbolUsuario* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return 1 + contarNodosRec(nodo->izquierda) + contarNodosRec(nodo->derecha);
    }

    void print(NodoArbolUsuario* nodo) {
        if (nodo != nullptr) {
            print(nodo->izquierda);
            std::cout << nodo->usuario.id << "\t";
            print(nodo->derecha);
        }
    }

    static void serializar(std::ostream& os, NodoArbolUsuario* nodo) {
    if (nodo == nullptr) {
        os << "#\n";
    } else {
        os << nodo->usuario.id << '\n'
           << nodo->usuario.nombres << '\n'
           << nodo->usuario.correo << '\n'
           << nodo->usuario.contrasenia << '\n'
           << nodo->usuario.librosSeleccionados.size() << '\n';
        for (const auto& libro : nodo->usuario.librosSeleccionados) {
            os << libro;
        }
        serializar(os, nodo->izquierda);
        serializar(os, nodo->derecha);
    }
}


    static NodoArbolUsuario* deserializar(std::istream& is) {
    std::string id;
    std::getline(is, id);

    if (id == "#") {
        return nullptr;
    }

    std::string nombres, correo, contrasenia;
    std::getline(is, nombres);
    std::getline(is, correo);
    std::getline(is, contrasenia);

    Usuario usuario{id, nombres, correo, contrasenia, {}, {}};

    size_t numLibros;
    is >> numLibros;
    is.ignore();  // Ignorar el salto de línea después del número

    for (size_t i = 0; i < numLibros; ++i) {
        Libro libro;
        is >> libro;
        usuario.librosSeleccionados.push_back(libro);
    }
    NodoArbolUsuario* nodo = new NodoArbolUsuario{usuario, nullptr, nullptr};

    nodo->izquierda = deserializar(is);
    nodo->derecha = deserializar(is);

    return nodo;
}

};

#endif
