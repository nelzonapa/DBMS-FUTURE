#ifndef ROL_H
#define ROL_H

#include <string>
using namespace std;

class Rol {
private:
    int idRol;
    string nombreRol;

public:
    Rol();
    Rol(int _idRol,  string& _nombreRol);

    // Funciones get
    int getIdRol() ;
    string getNombreRol() ;

    // Funciones set
    void setIdRol(int _idRol);
    void setNombreRol( string& _nombreRol);
};

#endif
