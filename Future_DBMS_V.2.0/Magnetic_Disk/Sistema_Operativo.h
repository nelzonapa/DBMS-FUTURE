#ifndef SISTEMA_OPERATIVO_H
#define SISTEMA_OPERATIVO_H

#include "BrazoDisco.h"
#include "BrazoDisco.cpp"

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
//Para solo detectar nuestro esquema

class Sistema_Operativo
{
private:
    /* data */
public:
    Sistema_Operativo();
    ~Sistema_Operativo();

    /*Funciones*/
    void menu();//solo para probar
    //------------DISK---------
    void crear_disco();
    void recuperar_disco();

    //----------------READ INFO----------------

    void mostrar_info_de_bloque(int num_bloque);

    //----------------- WRITE FIXED LENGTH ------------------
    void escribir_disk_from_archivo(string _name_tabla);
    string decidir_tipo_dato(string &value);
};

#endif 