#ifndef PERMISO_H
#define PERMISO_H

#include <string>
using namespace std;

class Permiso {
private:
    int idPermiso;
    string nombrePermiso;

public:
    Permiso();
    Permiso(int _idPermiso,  string& _nombrePermiso);

    // Funciones get
    int getIdPermiso() ;
    string getNombrePermiso() ;

    // Funciones set
    void setIdPermiso(int _idPermiso);
    void setNombrePermiso( string& _nombrePermiso);
};

#endif
