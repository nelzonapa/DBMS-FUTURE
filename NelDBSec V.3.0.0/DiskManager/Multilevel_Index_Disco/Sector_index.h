#ifndef SECTOR_INDEX_H
#define SECTOR_INDEX_H

#include <iostream>
using namespace std;

class Sector_Index
{
protected:
    int id_sector;
    string ruta_next_sector;
    int cantidades_next_sector;
    int direccion_sector;
    int capacidad_sector;
public:
    Sector_Index();
    ~Sector_Index();

    //-------------get---------------------
    int get_id_sector();
    string get_ruta_next_sector();
    int get_cantidades_next_sector();
    int get_direccion_sector();
    int get_capacidad_sector();

    //---------------set-------------------
    void set_id_sector(int input);
    void set_ruta_next_sector(string input);
    void set_cantidades_next_sector(int input);
    void set_direccion_sector(int input);
    void set_capacidad_sector(int input);

    //------------------others-------------
    void print_data_sector();
    friend std::ostream& operator<<(std::ostream& os, Sector_Index& sector_index);
    friend std::istream& operator>>(std::istream& is, Sector_Index& sector_index);
};

#endif