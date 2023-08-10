#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H

#include "Multilevel_Index_Disco/Disco_index.h"
#include "Multilevel_Index_Disco/Disco_index.cpp"

#include "Multilevel_Index_Disco/Plato_index.h"
#include "Multilevel_Index_Disco/Plato_index.cpp"

#include "Multilevel_Index_Disco/Superficie_index.h"
#include "Multilevel_Index_Disco/Superficie_index.cpp"

#include "Multilevel_Index_Disco/Pista_index.h"
#include "Multilevel_Index_Disco/Pista_index.cpp"

#include "Multilevel_Index_Disco/Sector_index.h"
#include "Multilevel_Index_Disco/Sector_index.cpp"

#include "Multilevel_Index_Disco/Bloque.h"
#include "Multilevel_Index_Disco/Bloque.cpp"

#include "Multilevel_Index_Disco/Disco_Header.h"
#include "Multilevel_Index_Disco/Disco_Header.cpp"


// #include "Data/headerSector.h"
#include "Data/headerSector.cpp"

// #include "Data/Variable_length/Slot.h"
#include "Data/Variable_length/Slot.cpp"

// #include "../DiscoMagnetico/DiscoMagnetico.h"
#include "../DiscoMagnetico/DiscoMagnetico.cpp"

#include "../DiscoMagnetico/BrazoDisco.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>

typedef unordered_map<string, pair<string,int>> MapaPares;

class SistemaOperativo
{
private:
    BrazoDisco brazoDiscoMagnetico;

public:
    SistemaOperativo();
    ~SistemaOperativo();

    //-------------------------CREATE--------------------------
    void agregar_disco_index(Disco_Header & disco_header);
    void agregar_platos_index(Disco_Header & disco_header,const string &route_disco_index);
    void agregar_superficies_index(Disco_Header & disco_header,const string &route_disco_index);
    void agregar_pistas_index(Disco_Header & disco_header,const string &route_disco_index);
    void agregar_sectores_index(Disco_Header & disco_header,const string &route_disco_index);
    void agregar_bloques_index(Disco_Header & disco_header,const string &route_disco_index);
   

    //-------------------------WRITE_INFO--------------------------
    void write_disco_general_info(Disco_Header &disco_header);
    void write_disco_info(Disco_index &disco_index,const string &ruta_disco, int ubication_write);
    void write_platos_info(Plato_Index &plato_index,const string &ruta_disco, int ubication_write);
    void write_superficies_info(Superficie_Index &superficie_index,const string &ruta_disco, int ubication_write);
    void write_pistas_info(Pista_Index &pista_index,const string &ruta_disco, int ubication_write);
    void write_sectores_info(Sector_Index &sector_index,const string &ruta_disco, int ubication_write);
    void write_bloques_info(Bloque &bloque,const string &ruta_disco, int ubication_write);

    //-------------------------GET PARTS-------------------------
    Disco_Header& get_disco_header(int num_id_disco);
    Disco_index& get_disco_index(int num_id_disco);
    Plato_Index& get_plato_index(int num_id_disco,int id_plato);
    Superficie_Index& get_superficie_index(int num_id_disco, int id_superficie);
    Pista_Index& get_pista_index(int num_id_disco, int id_pista);
    Sector_Index& get_sector_index(int num_id_disco, int id_sector);
    Bloque& get_bloque_index(int num_id_disco, int id_bloque);


    //-------------------------PRINT PARTS INDEX--------------------------
    void print_disco_header(int num_id_disco);
    void print_disco_index(int num_id_disco);
    void print_plato_index(int num_id_disco);
    void print_superficie_index(int num_id_disco);
    void print_pista_index(int num_id_disco);
    void print_sector_index(int num_id_disco);
    void print_bloque_index(int num_id_disco);

    //----------------- ESQUEMA DATA ------------------
    void crear_esquema_tabla(string _name_archivo);//solo el nombre del archivo
    void leer_esquema_tabla(string _name_tabla);
    void mostrar_esquema_map(MapaPares& map_atributos,vector<string> &vector_ordenado_atributos);
    MapaPares& get_esquema_tabla(string _name_tabla);
    vector<string>& get_vector_atributos(string _name_tabla);
    string decidir_tipo_dato(string &value);


    /*-------------- WriteData ---------------*/
    void ingresarTablaDesdeArchivoCSV(string nombreArchivo);

};

#endif