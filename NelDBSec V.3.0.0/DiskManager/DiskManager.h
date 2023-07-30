#ifndef DISKMANAGER_H
#define DISKMANAGER_H

#include "SistemaOperativo.h"
#include "SistemaOperativo.cpp"

// #include "Disco_Header.h"
// #include "Disco_Header.cpp"

// #include "../DiscoMagnetico/DiscoMagnetico.h"
// #include "../DiscoMagnetico/DiscoMagnetico.cpp"

#include "../DiscoMagnetico/BrazoDisco.h"
#include "../DiscoMagnetico/BrazoDisco.cpp"

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

typedef unordered_map<string, pair<string,int>> MapaPares;
//Para solo detectar nuestro esquema

class DiskManager
{
private:
    /* data */
public:
    DiskManager();
    ~DiskManager();

    /*Funciones*/
    void menu();//solo para probar
    //------------DISK---------
    void crear_disco();
    void crear_multilevel_index_disco();
    

    //----------------READ INFO----------------
    void print_multilevel_index_disco();
    void mostrar_informacion_disco(int id_disco);
    void mostrar_info_de_bloque(int num_bloque);
    void mostrar_contenido_variable_length_bloque(int num_bloque);

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