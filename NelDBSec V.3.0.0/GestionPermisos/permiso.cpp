#include "permiso.h"

Permiso::Permiso(){
    this->idPermiso=1;
    this->nombrePermiso="Administrador";
}

Permiso::Permiso(int _idPermiso,  string& _nombrePermiso)
    : idPermiso(_idPermiso), nombrePermiso(_nombrePermiso) {}

// Funciones get
int Permiso::getIdPermiso()  {
    return idPermiso;
}

string Permiso::getNombrePermiso()  {
    return nombrePermiso;
}

// Funciones set
void Permiso::setIdPermiso(int _idPermiso) {
    idPermiso = _idPermiso;
}

void Permiso::setNombrePermiso( string& _nombrePermiso) {
    nombrePermiso = _nombrePermiso;
}
