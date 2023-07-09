#ifndef PLATO_H
#define PLATO_H

#include <iostream>
using namespace std;

class Plato_Index
{
protected:
    int id_plato;
    string route_fin_plato;
    string route_inicio_plato;
    int capacidad_plato;
public:
    Plato_Index();
    ~Plato_Index();

    //-------------get---------------------
    int get_id_plato();
    string get_route_fin_plato();
    string get_route_inicio_plato();
    int get_capacidad_plato();

    //---------------set-------------------
    void set_id_plato(int input);
    void set_route_fin_plato(string);
    void set_route_inicio_plato(string);
    void set_capacidad_plato(int input);

    //------------------others-------------
    void print_data_Plato();

};


#endif