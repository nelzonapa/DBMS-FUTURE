#ifndef BLOQUE_H
#define BLOQUE_H

#include <iostream>

using namespace std;

class Bloque
{
protected:
    int id_bloque;
    string route_fin_bloque;
    string route_inicio_bloque;
    int capacidad_bloque;
public:
    Bloque();
    ~Bloque();

    //-------------get---------------------
    int get_id_bloque();
    string get_route_fin_bloque();
    string get_route_inicio_bloque();
    int get_capacidad_bloque();

    //---------------set-------------------
    void set_id_bloque(int input);
    void set_route_fin_bloque(string);
    void set_route_inicio_bloque(string);
    void set_capacidad_bloque(int input);

    //------------------others-------------
    void print_data_bloque();
};

#endif