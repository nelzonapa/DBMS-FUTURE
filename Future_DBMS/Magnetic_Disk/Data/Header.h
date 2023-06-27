#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class Header
{
private:
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
    Header();
    Header(int _num_records_general,int cant_bytes_usados,int _ptr_delete_fixed_space,int _ptr_direc_end_fixed,int _num_records_fixed, int _num_records_variable, int _direc_free_space_variable);
    ~Header();

    //GET
    int get_num_records_general();

    int get_cant_bytes_usados();

    int get_ptr_delete_fixed_space();

    int get_ptr_direc_end_fixed();

    int get_num_records_fixed();

    int get_num_records_variable();

    int get_direc_free_space_variable();

    //SET
    void set_num_records_general(int _input);

    void set_cant_bytes_usados(int _input);

    void set_ptr_delete_fixed_space(int _new_direc);

    void set_ptr_direc_end_fixed(int _input);

    void set_num_records_fixed(int _input);

    void set_num_records_variable(int _input);

    void set_direc_free_space_variable(int _input);

    void print_info_header();
};

#endif