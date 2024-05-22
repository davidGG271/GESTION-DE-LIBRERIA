#include <Libro_h>
#include <Usuario_h>

#include<iostream>

using namespace std;

struct NodoU {
	Usuario usuario;
	NodoU* siguente;
};

int main() {
	NodoU* inicio;

	Usuario u;
	Usuario u1;

	u.contrasena = "123";
	u.correo = "henry@usil.pe";

	u1.correo = "javier@usil.pe";
	u1.contrasena = "1234";



}
