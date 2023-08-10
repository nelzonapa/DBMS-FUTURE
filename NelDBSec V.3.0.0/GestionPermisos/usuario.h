#ifndef USUARIO_H
#define USUARIO_H

#include "../ProgramaPrincipal/Programa.cpp"
#include "permisoRol.cpp"
#include "string"
using namespace std;

class Usuario
{
private:
    int id;
    string nombre;
    string contrasenia;
    PermisoRol permisoRol;
    Programa programa;
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

    //others
    void ejecutarPrograma();
    void menu_program(Programa &programa);
    void mostrarTablaMetadata();
    void mostrarBufferPool();
    void ingresarTablaDesdeArchivo(string nombreArchivoCSV);
};


#endif