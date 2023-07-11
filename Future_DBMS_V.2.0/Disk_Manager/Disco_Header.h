#ifndef DISCO_HEADER_H
#define DISCO_HEADER_H

#include <iostream>
using namespace std;

class Disco_Header
{
protected:
    const char* route_disk_magnetic;
    int id_disk_magnetic;

    int num_platos_total;
    int num_superficies_total;
    int num_pistas_total;
    int num_sectores_total;
    int num_bloques_total;

    int capacidad_total_magneticDisk;
    int capacidad_usada_magneticDisk;
    int capacidad_restante_magneticDisk;

public:
    Disco_Header();
    ~Disco_Header();
    //Funciones:

    //----------------set()-----------------------
    void set_route_disk_magnetic(const char* route);
    void set_id_disk_magnetic(int _input);

    void set_num_platos_total(int _input);
    void set_num_superficies_total(int _input);
    void set_num_pistas_total(int _input);
    void set_num_sectores_total(int _input);
    void set_num_bloques_total(int _input);

    void set_capacidad_total_magneticDisk(int _input);
    void set_capacidad_usada_magneticDisk(int _input);
    void set_capacidad_restante_magneticDisk(int _input);

    //--------------------get()---------------------
    const char* get_route_disk_magnetic();
    int get_id_disk_magnetic();

    int get_num_platos_total();
    int get_num_superficies_total();
    int get_num_pistas_total();
    int get_num_sectores_total();
    int get_num_bloques_total();

    int get_capacidad_total_magneticDisk();
    int get_capacidad_usada_magneticDisk();
    int get_capacidad_restante_magneticDisk();

    //-----------------Others---------------
    void print_info_magnetic_disk();
};

#endif