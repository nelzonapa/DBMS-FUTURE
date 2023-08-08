#ifndef INICIOSESION_H
#define INICIOSESION_H

#include "usuario.cpp"

#include "string"
using namespace std;

class inicioSesion
{
private:
    Usuario usuario;
public:
    inicioSesion();
    ~inicioSesion();
    // Funciones get
    Usuario getUsuario();

    // Funciones set
    void setUsuario(Usuario& _usuario);

    //Others:
    bool autenticar(string nombreUsuario, string contrasenia);
};


#endif