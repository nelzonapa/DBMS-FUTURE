#ifndef SUPERFICIE_INDEX_H
#define SUPERFICIE_INDEX_H

#include <iostream>
using namespace std;

class Superficie_Index
{
protected:
    int id_superficie;
    string ruta_next_superficie;
    int cantidades_next_superficie;
    int direccion_superficie;
    int capacidad_superficie;
public:
    Superficie_Index();
    ~Superficie_Index();

    //-------------get---------------------
    int get_id_superficie();
    string get_ruta_next_superficie();
    int get_cantidades_next_superficie();
    int get_direccion_superficie();
    int get_capacidad_superficie();

    //---------------set-------------------
    void set_id_superficie(int input);
    void set_ruta_next_superficie(string input);
    void set_cantidades_next_superficie(int input);
    void set_direccion_superficie(int input);
    void set_capacidad_superficie(int input);

    //------------------others-------------
    void print_data_superficie();

    friend std::ostream& operator<<(std::ostream& os, Superficie_Index& superficie_index);
    friend std::istream& operator>>(std::istream& is, Superficie_Index& superficie_index);

};


#endif