#ifndef BRAZODISCO_H
#define BRAZODISCO_H

// #include "DiscoMagnetico.h"
// #include "DiscoMagnetico.cpp"

// #include "../DiskManager/SistemaOperativo.h"
// #include "../DiskManager/SistemaOperativo.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>
#include <windows.h>

typedef unordered_map<string, pair<string,int>> MapaPares;

class BrazoDisco
{
public:
    BrazoDisco();
    ~BrazoDisco();
    /*
    -------------------- COMPROBAMOS EXISTENCIA DEL DISCO ----------------
    */
    string conseguir_disco(const string &disco_name);
    bool comprobar_existencia_file(const string& filePath);
    bool Crear_leer_file_discos(const string& filePath, const string& word_buscar);

    //-------------------------cCREATE--------------------------
    void crear_disco(DiscoMagnetico &disco_magnetic); 
    void crear_platos(DiscoMagnetico &disco_magnetic,const string &route_disco);
    void crear_superficies(DiscoMagnetico &disco_magnetic, const string &final_route_plato);
    void crear_pistas(DiscoMagnetico &disco_magnetic, const string &final_route_plato);
    void crear_sectores(DiscoMagnetico &disco_magnetic, const string &final_route_plato);

    /*------ data---------*/
    void escribirFixedLengthData(string registro, string metadata);
    void escribirVariableLengthData(string registro, string metadata);

    string leerFixedLengthData(string metadata);
    string leerVariableLengthData(string metadata);

    void eliminarRegistro(string idRegistro,string metadata);
    void actualizarRegistro(string idRegistro,string metadata);

    void insertarRegistrosCSV(string &nameArchivo);
    void escribirVectorRegistroEnSector( vector<string> &valores, string &archivo);

    void read_header_bloque(int _num_bloque);
    Disco_Header& get_disco_magnetic_info();
    headerSector& get_header_bloque(int _num_bloque);
    int get_num_bloque_espacio_libre(int _space_necesitado);

    int calcular_espacio_necesario(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar);
    void caminar_por_slots_tupla_variable_data_insertar_slot(Slot &slot_tupla_enviado, int num_bloque, int direc_slot_escrito);
    void insert_variable_length_data(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar);

    //----------------------READ VARIABLE DATA-----------------
    void leer_slot_tupla_atributos(Slot &slot,int num_bloque);
    void caminar_por_slots_tupla_variable_data_imprimir(int num_bloque,int direc_slot_escrito);
    void read_variable_length_data_per_block(int num_block);
    void read_variable_length_data(int _id_record);
    void insertFixedLengthData(vector<string> &_vec_valores_ingresar);


};

#endif