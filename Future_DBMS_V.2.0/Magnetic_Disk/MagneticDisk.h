#ifndef MAGNETICDISK_H
#define MAGNETICDISK_H

#include <iostream>
using namespace std;

class MagneticDisk
{
protected:
    const char* route_disk_magnetic;
    int id_disk_magnetic;

    int num_platos;
    int num_superficies;
    int num_pistas;
    int num_sectores;
    int num_bloques;

    int capacidad_total_magneticDisk;
    int capacidad_usada_magneticDisk;
    int capacidad_restante_magneticDisk;

public:
    MagneticDisk();
    ~MagneticDisk();
    //Funciones:

    //----------------set()-----------------------
    void set_route_disk_magnetic(const char* route);
    void set_id_disk_magnetic(int _input);

    void set_num_platos(int _input);
    void set_num_superficies(int _input);
    void set_num_pistas(int _input);
    void set_num_sectores(int _input);
    void set_num_bloques(int _input);

    void set_capacidad_total_magneticDisk(int _input);
    void set_capacidad_usada_magneticDisk(int _input);
    void set_capacidad_restante_magneticDisk(int _input);

    //--------------------get()---------------------
    const char* get_route_disk_magnetic();
    int get_id_disk_magnetic();

    int get_num_platos();
    int get_num_superficies();
    int get_num_pistas();
    int get_num_sectores();
    int get_num_bloques();

    int get_capacidad_total_magneticDisk();
    int get_capacidad_usada_magneticDisk();
    int get_capacidad_restante_magneticDisk();

    //-----------------Others---------------
    void print_info_magnetic_disk();
};

#endif