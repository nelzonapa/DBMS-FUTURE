#ifndef MAGNETICDISK_H
#define MAGNETICDISK_H

#include "ReadWriteHead.h"
#include "ReadWriteHead.cpp"

#include <iostream>
using namespace std;

class MagneticDisk
{
protected:
    int id_disk_magnetic;
    int num_platos;
    int num_sectores;
    int num_pistas;
    int capacidad_total_magneticDisk;
    int capacidad_usada;

public:
    MagneticDisk();
    MagneticDisk(int _num_platos,int _capacidad, int _num_sectors,int _num_pistas);
    ~MagneticDisk();
    void modificar_cap_total(int _capacidad);
    void modificar_num_platos(int _num_platos);
    void agregar_platos_index_data();
    void agregar_superficies_index_data();
    void print_info_magentic_disk();
    void print_info_platos_index();
    void print_data_superficie_index();
    void agregar_sector_index_data();
    void print_data_sector_index();
    void agregar_bloques_index_data();
    void print_data_block_index();
    void print_data_passengers();
    void print_blocks_info();

    void print_data_passengers_filtro(string signo,int id);
    void modificar_cantidad_usada(int _new_cant);

    int return_n_platos();
    int return_n_sectores();
    int return_n_pistas();
    int return_n_objetos();
    int return_capacity_disco_mag();
    int return_cant_objects_block();

    friend class R_W_Head;
};

#endif