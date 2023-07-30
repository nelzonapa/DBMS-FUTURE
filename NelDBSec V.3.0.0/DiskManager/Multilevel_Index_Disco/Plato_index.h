#ifndef PLATO_H
#define PLATO_H

#include <iostream>
using namespace std;

class Plato_Index
{
protected:
    int id_plato;
    string ruta_next_plato;
    int cantidades_next_plato;
    int direccion_plato;
    int capacidad_plato;
public:
    Plato_Index();
    ~Plato_Index();

    //-------------get---------------------
    int get_id_plato();
    string get_ruta_next_plato();
    int get_cantidades_next_plato();
    int get_direccion_plato();
    int get_capacidad_plato();

    //---------------set-------------------
    void set_id_plato(int input);
    void set_ruta_next_plato(string input);
    void set_cantidades_next_plato(int input);
    void set_direccion_plato(int input);
    void set_capacidad_plato(int input);

    //------------------others-------------
    void print_data_Plato();
    friend std::ostream& operator<<(std::ostream& os, Plato_Index& plato_index);
    friend std::istream& operator>>(std::istream& is, Plato_Index& plato_index);

};


#endif