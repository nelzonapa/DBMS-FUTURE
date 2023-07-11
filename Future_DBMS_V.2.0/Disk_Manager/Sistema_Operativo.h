#ifndef SISTEMA_OPERATIVO_H
#define SISTEMA_OPERATIVO_H

#include "Disco_index.h"
#include "Disco_index.cpp"

#include "Plato_index.h"
#include "Plato_index.cpp"

#include "Superficie_index.h"
#include "Superficie_index.cpp"

#include "Pista_index.h"
#include "Pista_index.cpp"

#include "Sector_index.h"
#include "Sector_index.cpp"

#include "Bloque.h"
#include "Bloque.cpp"

#include "Disco_Header.h"
#include "Disco_Header.cpp"


#include "Data/Header_Bloque.h"
#include "Data/Header_Bloque.cpp"

#include "Data/Variable_length/Slot.h"
#include "Data/Variable_length/Slot.cpp"

#include "../Disco_Magnetico/Disco_Magnetico.h"
#include "../Disco_Magnetico/Disco_Magnetico.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>
typedef unordered_map<string, pair<string,int>> MapaPares;

class Sistema_Operativo
{
public:
    Sistema_Operativo();
    ~Sistema_Operativo();

    //-------------------------cCREATE--------------------------
    void crear_ubicacion_disco_header(Disco_Magnetico &disco_magnetic,const string &direccion_ruta);
    void crear_disco_index(Disco_Magnetico &disco_magnetic,const string &direccion_ruta, bool final_inicio);
    void crear_platos_index(Disco_Magnetico &disco_magnetic,const string &direccion_ruta, bool final_inicio);
    void crear_superficies_index(Disco_Magnetico &disco_magnetic,const string &direccion_ruta, bool final_inicio);
    void crear_pistas_index(Disco_Magnetico &disco_magnetic,const string &direccion_ruta, bool final_inicio);
    void crear_sectores_index(Disco_Magnetico &disco_magnetic,const string &direccion_ruta, bool final_inicio);
    void crear_bloques_index(Disco_Magnetico &disco_magnetic,const string &direccion_ruta, bool final_inicio);
   

    //-------------------------WRITE_INFO--------------------------
    void write_disco_info(Disco_Header &disco_magnetic);
    void write_platos_info();
    void write_superficies_info();
    void write_pistas_info();
    void write_sectores_info();
    void write_bloques_info();

    //-------------------------GET--------------------------
    Disco_index& get_disco_header(int num_id_disco);
    Disco_index& get_disco_index(int num_id_disco);
    Plato_Index& get_plato_index(int _num_plato);
    Superficie_Index& get_superficie_index(int _num_superficie);
    Pista_Index& get_pista_index(int _num_pista);
    Sector_Index& get_sector_index(int _num_sector);
    Bloque& get_bloque_index(int _num_bloque);

    //-------------------------Read Otros-------------------------
    void read_header_bloque(int _num_bloque);

    //-----------------------GET---------------------------
    Disco_Header& get_disco_magnetic_info();
    Header_Bloque& get_header_bloque(int num_bloque);
    int get_num_bloque_espacio_libre(int _space_necesitado);
    int calcular_espacio_necesario(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar);

    //--------------WRITE VARIABLE DATA-----------
    void caminar_por_slots_tupla_variable_data_insertar_slot(Slot &slot_tupla_enviado, int num_bloque, int direc_slot_escrito);
    void insert_variable_length_data(MapaPares &ptr_map_atributos,vector<string> &ptr_vec_atributos,vector<string> &ptr_vec_valores_ingresar);
    
    //----------------------READ VARIABLE DATA-----------------
    void leer_slot_tupla_atributos(Slot &slot,int num_bloque);
    void caminar_por_slots_tupla_variable_data_imprimir(int num_bloque,int direc_slot_escrito);
    void read_variable_length_data_per_block(int num_block);
    void read_variable_length_data(int _id_record);

    //--------------WRITE FIXED LENGTH DATA-----------
    void insert_fixed_length_data(MapaPares &ptr_map_atributos,vector<string> &ptr_vec_atributos,vector<string> &ptr_vec_valores_ingresar);
    
    //----------------------READ FIXED DATA-----------------
    // void read_fixed_length_data();
};

#endif