#include "rol.h"

Rol::Rol(){
    this->idRol=1;
    this->nombreRol="Administrador";
}

Rol::Rol(int _idRol,  string& _nombreRol)
    : idRol(_idRol), nombreRol(_nombreRol) {}

// Funciones get
int Rol::getIdRol()  {
    return idRol;
}

string Rol::getNombreRol()  {
    return nombreRol;
}

// Funciones set
void Rol::setIdRol(int _idRol) {
    idRol = _idRol;
}

void Rol::setNombreRol( string& _nombreRol) {
    nombreRol = _nombreRol;
}
