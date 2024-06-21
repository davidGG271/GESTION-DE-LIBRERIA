#ifndef LISTAUSU_H
#define LISTAUSU_H

#include "Usuario.h"
#include <iostream>
#include <fstream>

struct NodoU {
	Usuario usuario;
	NodoU* anterior;
	NodoU* siguiente;

	NodoU(const Usuario& usuario) : usuario(usuario), anterior(nullptr), siguiente(nullptr) {}

	friend std::ostream& operator<<(std::ostream& os, const NodoU& nodo) {
        os << nodo.usuario;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, NodoU& nodo) {
        is >> nodo.usuario;
        return is;
    }
};

class ListaUsuario
{

private:
	NodoU *inicio;
	NodoU *final;

public:
	ListaUsuario()
	{
		inicio = nullptr;
		final = nullptr;
	}

	void agregar(Usuario usuario)
	{
		NodoU *nodoNuevo = new NodoU{usuario};
		if (inicio == nullptr)
		{

			inicio = nodoNuevo;
			final = nodoNuevo;
		}
		else
		{
			nodoNuevo->anterior = final;
			final->siguiente = nodoNuevo;
			final = nodoNuevo;
			final->siguiente = nullptr;
		}
	}

	void eliminar(string id)
	{
		if (inicio == nullptr)
		{
			cout << "No hay usuarios registrados" << endl;
		}

		if (!UsuarioExiste(id))
		{
			cout << "El usuario no existe" << endl;
		}

		if (inicio->usuario.id == id)
		{
			NodoU *auxI = inicio;
			inicio = inicio->siguiente;

			if (inicio != NULL)
				inicio->anterior = NULL;

			delete auxI;
		}
		else if (final->usuario.id == id)
		{
			NodoU *auxF = final;
			final = final->anterior;

			if (final != nullptr)
			{
				final->siguiente = nullptr;
			}
			delete auxF;
		}
		else
		{
			NodoU *aux = inicio;

			while (aux != nullptr && aux->usuario.id != id)
			{
				aux = aux->siguiente;
			}

			if (aux != nullptr)
			{
				NodoU *auxA = aux->anterior;
				NodoU *auxS = aux->siguiente;

				auxA->siguiente = auxS;

				if (auxS != nullptr)
				{
					auxS->anterior = auxA;
				}
				delete aux;
				cout << "\033[2J\033[1;1H";
				cout << "Medico eliminado exitosamente!" << endl;
			}
		}
	}

	bool UsuarioExiste(string id)
	{
		bool existe = false;

		if (inicio == nullptr)
		{
			return existe;
		}
		else
		{
			NodoU *aux = inicio;

			while (aux != nullptr)
			{
				cout << "bbaaa" << endl;
				if (aux->usuario.id == id)
				{
					existe = true;
					return existe;
				}
				aux = aux->siguiente;
			}
		}
		return existe;
	}

	NodoU *encontrarUsuario(string id)
	{
		if (inicio == nullptr)
		{
			return nullptr;
		}
		else
		{
			NodoU *aux = inicio;
			while (aux != nullptr)
			{
				if (aux->usuario.id == id)
				{
					return aux;
				}
				aux = aux->siguiente;
			}
		}

		return nullptr;
	}

	friend std::ostream &operator<<(std::ostream &os, const ListaUsuario &lista)
	{
		NodoU *aux = lista.inicio;
		while (aux != nullptr)
		{
			os << aux->usuario << '\n';
			aux = aux->siguiente;
		}
		return os;
	}

	friend std::istream &operator>>(std::istream &is, ListaUsuario &lista)
	{
		Usuario usuario;
		while (is >> usuario)
		{
			lista.agregar(usuario);
		}
		return is;
	}

	void guardarUsuarios()
	{
		std::ofstream archivo("usuarios.txt");
		if (archivo.fail())
		{
			std::cout << "No se puede abrir el archivo.\n";
			return;
		}
		archivo << *this; // Usar la sobrecarga del operador <<
	}

	void cargarUsuarios()
	{
		std::ifstream archivo("usuarios.txt");
		if (archivo.fail())
		{
			std::cout << "No se puede abrir el archivo.\n";
			return;
		}
		archivo >> *this; // Usar la sobrecarga del operador >>
	}
};

#endif
