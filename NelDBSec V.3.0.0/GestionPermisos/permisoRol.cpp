#include "permisoRol.h"

PermisoRol::PermisoRol(){
    this->id=1;
}

PermisoRol::~PermisoRol(){}

// Funciones PermisoRol
int PermisoRol::getId()  {
    return id;
}

Permiso PermisoRol::getPermiso()  {
    return permiso;
}

Rol PermisoRol::getRol()  {
    return rol;
}

// Funciones set
void PermisoRol::setId(int _id) {
    id = _id;
}

void PermisoRol::setPermiso( Permiso& _permiso) {
    permiso = _permiso;
}

void PermisoRol::setRol( Rol& _rol) {
    rol = _rol;
}


string PermisoRol::getNamePermiso(){
    return this->permiso.getNombrePermiso();
}

string PermisoRol::getNameRol(){
    return this->rol.getNombreRol();
}
