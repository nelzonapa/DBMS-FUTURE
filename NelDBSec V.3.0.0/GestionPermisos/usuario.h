#ifndef USUARIO_H
#define USUARIO_H

#include "string"
using namespace std;

class Usuario
{
private:
    int id;
    string nombre;
    string contrasenia;
public:
    Usuario(/* args */);
    Usuario(int _id,  string& _nombre,  string& _contrasenia);
    ~Usuario();

    // Funciones get
    int getId() ;
    string getNombre() ;
    string getContrasenia() ;

    // Funciones set
    void setId(int _id);
    void setNombre( string& _nombre);
    void setContrasenia( string& _contrasenia);

};


#endif