#ifndef DISCO_HEADER_H
#define DISCO_HEADER_H

#include <iostream>
#include <string>

using namespace std;

class Disco_Header
{
private:
    string route_disk_magnetic;
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
    void set_route_disk_magnetic(string route);
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
    string get_route_disk_magnetic();
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
    void print_2_info();
    void print_info_magnetic_disk();
    friend std::ostream& operator<<(std::ostream& os, Disco_Header& disco_header);
    friend std::istream& operator>>(std::istream& is, Disco_Header& disco_header);

};

#endif