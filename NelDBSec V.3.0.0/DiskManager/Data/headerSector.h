#ifndef HEADERSECTOR_H
#define HEADERSECTOR_H

#include <iostream>
using namespace std;

class headerSector
{
private:
    //general
    unsigned int cant_bytes_bloque;
    unsigned int cant_bytes_usados_bloque;
    unsigned int cant_bytes_restantes_bloque;
    unsigned int num_general_records_bloque;
    
    //fixed length
    unsigned int direc_space_delete_fixed_bloque;
    unsigned int direc_end_fixed_bloque;
    unsigned int num_records_fixed_bloque;
    unsigned int direc_primer_record_fixed_length;

    //variable length
    unsigned int direc_space_delete_variable_bloque;
    unsigned int num_records_variable_bloque;
    unsigned int direc_free_space_variable_bloque; //apunta a donde inicias las tuplas de variable length
    unsigned int direc_primer_record_variable_length;
public:
    headerSector(/* args */);
    ~headerSector();

    //--------------------GET-------------------
    //general
    int get_cant_bytes_bloque();
    int get_cant_bytes_usados_bloque();
    int get_cant_bytes_restantes_bloque();
    int get_num_general_records_bloque();
    
    //fixed length
    int get_direc_space_delete_fixed_bloque();
    int get_direc_end_fixed_bloque();
    int get_num_records_fixed_bloque();
    int get_direc_primer_record_fixed_length();

    //variable length
    int get_direc_space_delete_variable_bloque();
    int get_num_records_variable_bloque();
    int get_direc_free_space_variable_bloque();
    int get_direc_primer_record_variable_length();

    //--------------------SET-------------------
    //general
    void set_cant_bytes_bloque(int _input);
    void set_cant_bytes_usados_bloque(int _input);
    void set_cant_bytes_restantes_bloque(int _input);
    void set_num_general_records_bloque(int _input);
    
    //fixed length
    void set_direc_space_delete_fixed_bloque(int _input);
    void set_direc_end_fixed_bloque(int _input);
    void set_num_records_fixed_bloque(int _input);
    void set_direc_primer_record_fixed_length(int _input);

    //variable length
    void set_direc_space_delete_variable_bloque(int _input);
    void set_num_records_variable_bloque(int _input);
    void set_direc_free_space_variable_bloque(int _input);
    void set_direc_primer_record_variable_length(int _input);

    //--------------------Others-------------------
    void print_info_header_bloque();
};

#endif