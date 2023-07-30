#ifndef PISTA_H
#define PISTA_H

#include <iostream>
using namespace std;

class Pista_Index
{
protected:
    int id_pista;
    string ruta_next_pista;
    int cantidades_next_pista;
    int direccion_pista;
    int capacidad_pista;
public:
    Pista_Index();
    ~Pista_Index();

    //-------------get---------------------
    int get_id_pista();
    string get_ruta_next_pista();
    int get_cantidades_next_pista();
    int get_direccion_pista();
    int get_capacidad_pista();

    //---------------set-------------------
    void set_id_pista(int input);
    void set_ruta_next_pista(string input);
    void set_cantidades_next_pista(int input);
    void set_direccion_pista(int input);
    void set_capacidad_pista(int input);

    //------------------others-------------
    void print_data_pista();
    friend std::ostream& operator<<(std::ostream& os, Pista_Index& pista_index);
    friend std::istream& operator>>(std::istream& is, Pista_Index& pista_index);

};


#endif