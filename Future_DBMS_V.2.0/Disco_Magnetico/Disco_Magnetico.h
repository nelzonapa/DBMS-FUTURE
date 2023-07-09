#ifndef DISCO_MAGNETICO_H
#define DISCO_MAGNETICO_H

#include <iostream>
using namespace std;

class Disco_Magnetico
{
protected:
    int id_disk_magnetic;

    int num_platos;
    int num_superficies;
    int num_pistas;
    int num_sectores;
    int num_bloques;

    int capacidad_sector;

public:
    Disco_Magnetico();
    ~Disco_Magnetico();
    //Funciones:

    //----------------set()-----------------------
    void set_id_disk_magnetic(int _input);

    void set_num_platos(int _input);
    void set_num_superficies(int _input);
    void set_num_pistas(int _input);
    void set_num_sectores(int _input);
    void set_num_bloques(int _input);

    void set_capacidad_sector(int _input);

    //--------------------get()---------------------
    int get_id_disk_magnetic();

    int get_num_platos();
    int get_num_superficies();
    int get_num_pistas();
    int get_num_sectores();
    int get_num_bloques();

    int get_capacidad_sector();

    //-----------------Others---------------
    void print_info_disco_magnetico();
};

#endif