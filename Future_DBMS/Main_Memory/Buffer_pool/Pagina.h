#ifndef PAGINA_H
#define PAGINA_H
#include <iostream>
#include <vector>
#include <list>

class Pagina
{
private:
    int size;
    Pagina *ptr_sig_pag;
    std::vector<char*> vector_registros;
public:
    Pagina(int _size);
    Pagina();
    ~Pagina();

    int get_size();
    Pagina& get_next_pagina();

    void set_size(int _size);
    void insert_back_vector(char* _registro);
    void insert_postion_vector(char* _registro, int posicion);
    void delete_register_vector(int posicion);
    void update_register_vector(char* _registro,int posicion);

};


#endif