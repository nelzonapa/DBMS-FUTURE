#ifndef READWRITEHEAD_H
#define READWRITEHEAD_H


#include <fstream>//para la parte cpp
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;


#include "Sector_index.h"
#include "Sector_index.cpp"

#include "Block_index.h"
#include "Block_index.cpp"

#include "Plato_index.h"
#include "Plato_index.cpp"

#include "Superficie_index.h"
#include "Superficie_index.cpp"


#include "Data/Fixed_data/Passenger_titanic.h"
#include "Data/Fixed_data/Passenger_titanic.cpp"

#include "Data/Header.h"
#include "Data/Header.cpp"

#include "Data/Variable_Data/Estudiante.cpp"

#include "Data/Variable_Data/Slot.h"
#include "Data/Variable_Data/Slot.cpp"

#include "Data/Variable_Data/Head_slot_index.h"
#include "Data/Variable_Data/Head_slot_index.cpp"

class R_W_Head
{
public:
    R_W_Head();
    ~R_W_Head();


    //variable length
    char* get_nullbitmap_record(Estudiante &student);
    void write_variable_data_block(Estudiante &student, int capacidad_disco);
    Estudiante* read_variable_data_block(Slot &_slot);
    void write_head_slots_index(Head_slot_index &H_slots_index);
    Head_slot_index* get_head_slots_index();
    void write_data_slot_index(Slot &slot, int ubication_read);
    Slot* get_slot_index(int ubication);
    void read_data_slot_index(int ubication);

    //fixed - length
    void set_direc_fixed_delete_space(int _direc_object,Header &H);
    int get_direc_fixed_delete_space(int _direc_object);
    void caminar_modificar_header(Header &header1,Header &header2,int _direc,int _direc2);
    void delete_data_fixed_block(int ubication_delete);
    void write_header_file_general(Header &head_delete);

    //métodos de lectura y de escritura CON ARCHIVO BINARIO
    void write_data_fixed_block(Passenger_titanic &passenger);
    Header* get_header_file(); 
    
    void read_data_fixed_block(int ubication_read);
    int verify_existence_fixed_record();
    //
    void write_data_sector_index(Sector_index &sector,int ubication_read);
    void read_data_sector_index(int ubication_read);
    void write_data_Block_index(Block_index &bloque,int ubication_read);
    void read_data_Block_index(int ubication_read);
    void read_data_platos_index(int ubication_read);
    void write_data_platos_index(Plato_index &plato1,int ubication_read);
    void write_superficie_index(Superficie_index &superficie,int ubication_read);
    void read_data_superficie_index(int ubication_read);
    int verify_existence_superficie_index(Superficie_index &sup_index);

    // void read_tokens_sql(int ubication_read);
    void leer_registros_from_csv(const string _archivo_csv,const string archivo_bin,int capacity_disc_mag);

    // Otras funciones
    Plato_index* search_data_platos_index_walking(int ubication_read);
    Superficie_index* search_data_superficie_index_walking(int direccion);
    Sector_index* search_data_sector_index_walking(int direccion);
    Block_index* search_data_block_index_walking(int direccion);

    void reading_metadata_object(int id_objeto, int num_platos,int num_sectors,int num_pistas,int cant_objetos);
    Block_index* return_data_block(int ubication_read);
    void reading_metadata_bloque(int id_objeto, int num_platos,int num_sectors,int num_pistas,int cant_objetos);
    void print_data_passengers_bloque(int direc_bloque,int num_objetos_per_block);

    void print_header_fixed_data();
    

    friend class Estudiante;
    friend class Slot;
    friend class Plato;
    friend class Superficie;
    friend class MagneticDisk;
    friend class Header;
    friend class Head_slot_index;
};

#endif