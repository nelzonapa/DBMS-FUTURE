#ifndef SISTEMA_OPERATIVO_H
#define SISTEMA_OPERATIVO_H

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
    void crear_disco(Disco_Header &disco_magnetic); 
    void crear_platos(Disco_Header &disco_magnetic);
    void crear_superficies(Disco_Header &disco_magnetic);
    void crear_pistas(Disco_Header &disco_magnetic);
    void crear_sectores(Disco_Header &disco_magnetic);
    void crear_bloques(Disco_Header &disco_magnetic);
   

    //-------------------------WRITE_INFO--------------------------
    void write_disco_info(Disco_Header &disco_magnetic);
    void write_platos_info();
    void write_superficies_info();
    void write_pistas_info();
    void write_sectores_info();
    void write_bloques_info();

    //-------------------------READ_INFO--------------------------
    void read_disco_info();
    void read_plato_info(int _num_plato);
    void read_superficie_info(int _num_superficie);
    void read_pista_info(int _num_pista);
    void read_sector_info(int _num_sector);
    void read_bloque_info(int _num_bloque);

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