#include <iostream>
#include "Prestamo.h"
#include "ListaUsuario.h"
#include "ListaLibro.h"
#include "ListaPrestamo.h"
#include <ctime>
#include <sstream>

using namespace std;

string obtenerFechaActual() {
    // Obtener el tiempo actual
    time_t tiempoActual = time(nullptr);
    // Convertirlo a una estructura tm local
    tm* tiempoLocal = localtime(&tiempoActual);
    
    // Crear un stringstream para formatear la fecha
    ostringstream oss;
    oss << (tiempoLocal->tm_year + 1900) << "-" 
        << (tiempoLocal->tm_mon + 1) << "-"
        << tiempoLocal->tm_mday;
    
    // Retornar la fecha como string
    return oss.str();
}

void imprimirPrestamo(Prestamo prestamo){
    cout << "ID Prestamo: " << prestamo.id << endl;
    cout << "Cliente: " << prestamo.usuario.nombres << endl;
    cout << "Libros prestados: " << endl;
    for(int i = 0; i < prestamo.libros.size(); i++){
        cout <<"[" << i+1 <<"] " << prestamo.libros.at(i).titulo << endl; 
    }
    cout << "Fecha de salida: " << prestamo.fechaSalida << endl;
    cout << "Fecha de entrega: " << prestamo.fechaDevolucion << endl;

}

void agregarNuevoPrestamo(ListaUsuario listaUsuario, ListaLibro listaLibro, ListaPrestamo& listaPrestamo){
    Prestamo prestamo;
    string idUsuario;
    string isbn;

    cout<<"Ingrese el id del nuevo prestamo: ";
    cin >> prestamo.id;
    cout<<"Ingrese el id del usuario: ";
    cin >> idUsuario;
    NodoU* usuarioAux = listaUsuario.encontrarUsuario(idUsuario);
    Usuario usuario;
    if(usuarioAux != nullptr){
        usuario = usuarioAux->usuario;
    }
    else{
        cout << "Usuario no encontrado.";
        return;
    }
    
    do{
        cout<<"Ingrese el id del libro, o 0 para finalizar: ";
        cin >> isbn;
        if(isbn != "0"){
            NodoL* nodo = listaLibro.encontrarLibro(isbn);
            prestamo.libros.push_back(nodo->libro);
        }
        else if(isbn == "0" && prestamo.libros.size() == 0){
            cout << "Ingrese al menos un libro\n.";
            isbn = "";
        }
        system("pause");
        system("cls");
    } while(isbn != "0");
    prestamo.usuario = usuario;
    prestamo.fechaSalida = obtenerFechaActual();
    listaPrestamo.agregar(prestamo);

}

void eliminarPrestamo(ListaPrestamo &listaPrestamo){
    string idPrestamo;
    cout << "Ingrese el id del prestamo a eliminar: ";
    cin >> idPrestamo;
    NodoP* prestamoAux = listaPrestamo.encontrarPrestamo(idPrestamo);
    Prestamo prestamo;
    if(prestamoAux != nullptr){
        prestamo = prestamoAux->prestamo;
    }
    else{
        cout << "Prestamo no encontrado.";
        return;
    }

    cout << "Informacion del prestamo: " << endl;
    imprimirPrestamo(prestamo);
    cout << "Eliminar prestamo?";
    cout << "[1] Si" <<endl;
    cout << "[2] Volver"<<endl;
    int opcion;
    cin >> opcion;
    if(opcion == 1){
        listaPrestamo.eliminar(idPrestamo);
    }
}

void buscarPrestamo(ListaPrestamo listaPrestamo){
    string idPrestamo;
    cout << "Ingrese el id del prestamo: ";
    cin >> idPrestamo;
    NodoP* prestamoAux = listaPrestamo.encontrarPrestamo(idPrestamo);
    if(prestamoAux != nullptr){
        imprimirPrestamo(prestamoAux->prestamo);
        system("pause");
        system("cls");
    }
    else{
        cout << "Prestamo no encontrado";
    }
}

void establecerFechaEntrega(ListaPrestamo& listaPrestamo){
    string idPrestamo;
    cout << "Ingrese el id del prestamo: ";
    cin >> idPrestamo;

    if(listaPrestamo.encontrarPrestamo(idPrestamo) == nullptr){
        cout << "Prestamo no encontrado.";
        return;
    }

    imprimirPrestamo(listaPrestamo.encontrarPrestamo(idPrestamo)->prestamo);

    int opcion = 0;
    cout << "Establecer como prestamo finalizado?"<<endl;
    cout << "[1] Sí"<<endl;
    cout << "[2] Volver"<<endl;
    cin >> opcion;
    if(opcion == 1){
        listaPrestamo.encontrarPrestamo(idPrestamo)->prestamo.fechaDevolucion = obtenerFechaActual();
        cout << "Prestamo actualizdo."<<endl;
    }
}
