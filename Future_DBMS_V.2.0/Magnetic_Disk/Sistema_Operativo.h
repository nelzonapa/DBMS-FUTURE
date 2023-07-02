#ifndef SISTEMA_OPERATIVO_H
#define SISTEMA_OPERATIVO_H

#include "BrazoDisco.h"
#include "BrazoDisco.cpp"

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>
typedef unordered_map<string, pair<string,int>> MapaPares;
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

    //----------------- ESQUEMA DATA ------------------
    void crear_esquema_tabla(string _name_archivo);//solo el nombre del archivo
    void leer_esquema_tabla(string _name_tabla);
    void mostrar_esquema_map(MapaPares& map_atributos,vector<string> &vector_ordenado_atributos);
    MapaPares& get_esquema_tabla(string _name_tabla);
    vector<string>& get_vector_atributos(string _name_tabla);
    string decidir_tipo_dato(string &value);

    //----------------- WRITE FIXED OR VARIABLE LENGTH ------------------
    void escribir_registro();
    
    int sacar_codigo_tabla(string _name_tabla);
    
};

#endif 