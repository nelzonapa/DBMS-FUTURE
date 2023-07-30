#ifndef DISCOMAGNETICO_H
#define DISCOMAGNETICO_H

#include <iostream>
using namespace std;

class DiscoMagnetico
{
protected:
    int id_disk_magnetic;
    int num_platos;
    int num_superficies_por_plato;
    int num_pistas_por_superficie;
    int num_sectores_por_pista;
    int num_sectores_en_bloque;

    int capacidad_sector;

public:
    DiscoMagnetico();
    ~DiscoMagnetico();
    //Funciones:

    //----------------set()-----------------------
    void set_id_disk_magnetic(int _input);

    void set_num_platos(int _input);
    void set_num_superficies_por_plato(int _input);
    void set_num_pistas_por_superficie(int _input);
    void set_num_sectores_por_pista(int _input);
    void set_num_sectores_en_bloque(int _input);

    void set_capacidad_sector(int _input);

    //--------------------get()---------------------
    int get_id_disk_magnetic();

    int get_num_platos();
    int get_num_superficies_por_plato();
    int get_num_pistas_por_superficie();
    int get_num_sectores_por_pista();
    int get_num_sectores_en_bloque();

    int get_capacidad_sector();

    //-----------------Others---------------
    void print_info_disco_magnetico();
};

#endif