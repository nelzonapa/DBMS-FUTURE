#ifndef BLOQUE_H
#define BLOQUE_H

#include <iostream>

using namespace std;

class Bloque
{
protected:
    int id_bloque;
    int direccion_inicio_bloque;
    int capacidad_bloque;
    //general
    unsigned int num_records_general;
    unsigned int cant_bytes_usados;
    
    //fixed length
    unsigned int ptr_delete_fixed_space;
    unsigned int ptr_direc_end_fixed;
    unsigned int num_records_fixed;

    //variable length
    unsigned int num_records_variable;
    unsigned int direc_free_space_variable; //apunta a donde inicias las tuplas de variable length

public:
    Bloque();
    ~Bloque();

    //-------------get---------------------
    int get_id_bloque();
    int get_direccion_inicio_bloque();
    int get_capacidad_bloque();

    int get_num_records_general();
    int get_cant_bytes_usados();
    int get_ptr_delete_fixed_space();
    int get_ptr_direc_end_fixed();
    int get_num_records_fixed();
    int get_num_records_variable();
    int get_direc_free_space_variable();

    //---------------set-------------------
    void set_id_bloque(int input);
    void set_direccion_inicio_bloque(int input);
    void set_capacidad_bloque(int input);

    void set_num_records_general(int _input);
    void set_cant_bytes_usados(int _input);
    void set_ptr_delete_fixed_space(int _new_direc);
    void set_ptr_direc_end_fixed(int _input);
    void set_num_records_fixed(int _input);
    void set_num_records_variable(int _input);
    void set_direc_free_space_variable(int _input);
    
    //------------------others-------------
    void print_data_bloque();
    friend std::ostream& operator<<(std::ostream& os, Bloque& bloque);
    friend std::istream& operator>>(std::istream& is, Bloque& Bloque);

};

#endif