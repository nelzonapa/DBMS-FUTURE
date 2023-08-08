#include "inicioSesion.h"

// Constructor
inicioSesion::inicioSesion() {}

// Destructor
inicioSesion::~inicioSesion() {}

// Función get para el atributo usuario
Usuario inicioSesion::getUsuario()
{
    return usuario;
}

// Función set para el atributo usuario
void inicioSesion::setUsuario(Usuario& _usuario) 
{
    usuario = _usuario;
}

// Función para autenticar al usuario
bool inicioSesion::autenticar(string nombreUsuario, string contrasenia) 
{
    // Verificamos si el nombre de usuario y la contraseña coinciden con los almacenados
    if (nombreUsuario == usuario.getNombre() && contrasenia == usuario.getContrasenia()) {
        return true; // Autenticación exitosa
    } else {
        return false; // Autenticación fallida
    }
}
