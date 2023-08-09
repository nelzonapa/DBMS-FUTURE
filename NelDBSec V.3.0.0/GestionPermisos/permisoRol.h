#ifndef PERMISOROL_H
#define PERMISOROL_H

#include "permiso.cpp"
#include "rol.cpp"
// #include "../Main_Memory/BufferManager/BufferManager.cpp"

class PermisoRol {
private:
    int id;
    Permiso permiso;
    Rol rol;
public:

    PermisoRol();
    ~PermisoRol();

    // Funciones get
    int getId() ;
    Permiso getPermiso();
    Rol getRol();

    // Funciones set
    void setId(int _id);
    void setPermiso( Permiso& _permiso);
    void setRol( Rol& _rol);

    //others:
    string getNamePermiso();
    string getNameRol();

};

#endif
