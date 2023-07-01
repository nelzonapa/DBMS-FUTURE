#ifndef SECTOR_H
#define SECTOR_H

#include <iostream>
using namespace std;

class Sector
{
protected:
    int id_sector;
    string route_fin_sector;
    string route_inicio_sector;
    int capacidad_sector;
public:
    Sector();
    ~Sector();

    //-------------get---------------------
    int get_id_sector();
    string get_route_fin_sector();
    string get_route_inicio_sector();
    int get_capacidad_sector();

    //---------------set-------------------
    void set_id_sector(int input);
    void set_route_fin_sector(string);
    void set_route_inicio_sector(string);
    void set_capacidad_sector(int input);

    //------------------others-------------
    void print_data_sector();
};

#endif