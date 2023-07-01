#ifndef PISTA_H
#define PISTA_H

#include <iostream>
using namespace std;

class Pista
{
protected:
    int id_pista;
    string route_fin_pista;
    string route_inicio_pista;
    int capacidad_pista;
public:
    Pista();
    ~Pista();

    //-------------get---------------------
    int get_id_pista();
    string get_route_fin_pista();
    string get_route_inicio_pista();
    int get_capacidad_pista();

    //---------------set-------------------
    void set_id_pista(int input);
    void set_route_fin_pista(string);
    void set_route_inicio_pista(string);
    void set_capacidad_pista(int input);

    //------------------others-------------
    void print_data_pista();
};


#endif