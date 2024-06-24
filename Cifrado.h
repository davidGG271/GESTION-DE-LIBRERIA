#ifndef CIFRADO_H
#define CIFRADO_H

#include <string>

using namespace std;

string cifrarContrasena(const string& contrasena) {
    string cifrada = contrasena;
    for (char& c : cifrada) {
        c = c + 3; // Simplemente desplazar cada car�cter por 3 posiciones en ASCII
    }
    return cifrada;
}

string descifrarContrasena(const string& contrasena) {
    string descifrada = contrasena;
    for (char& c : descifrada) {
        c = c - 3; // Revertir el desplazamiento de 3 posiciones en ASCII
    }
    return descifrada;
}

#endif // CIFRADO_H

