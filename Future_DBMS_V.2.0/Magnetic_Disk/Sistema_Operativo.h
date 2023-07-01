#ifndef SISTEMA_OPERATIVO_H
#define SISTEMA_OPERATIVO_H

#include "BrazoDisco.h"
#include "BrazoDisco.cpp"

class Sistema_Operativo
{
private:
    /* data */
public:
    Sistema_Operativo();
    ~Sistema_Operativo();

    /*Funciones*/
    void menu();//solo para probar
    void crear_disco();
    void recuperar_disco();

};

#endif 