#include "usuario.h"
Usuario::Usuario(/* args */)
{
    this->id=1; 
    this->nombre="Nelzon"; 
    this->contrasenia="12345";
}

Usuario::Usuario(int _id,  string& _nombre,  string& _contrasenia)
{
    this->id=_id; 
    this->nombre=_nombre; 
    this->contrasenia=_contrasenia;
}

Usuario::~Usuario()
{
}

// Funciones get
int Usuario::getId()  {
    return id;
}

string Usuario::getNombre()  {
    return nombre;
}

string Usuario::getContrasenia()  {
    return contrasenia;
}

// Funciones set
void Usuario::setId(int _id) {
    this->id = _id;
}

void Usuario::setNombre( string& _nombre) {
    this->nombre = _nombre;
}

void Usuario::setContrasenia( string& _contrasenia) {
    this->contrasenia = _contrasenia;
}


void Usuario::ejecutarPrograma(){
    if (this->permisoRol.getNamePermiso()=="Administrador" && this->permisoRol.getNameRol()=="Administrador")
    {
        this->permisoRol.ejecutarBufferManager();
    }
    else
    {
        cout<<"Usted no tiene permiso para ingresar al sistema"<<endl;
    }
    
}