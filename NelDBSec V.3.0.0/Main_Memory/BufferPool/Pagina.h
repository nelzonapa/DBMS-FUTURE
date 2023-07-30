#ifndef PAGINA_H
#define PAGINA_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string.h>


using namespace std;

class Pagina
{
protected:
    map<int,vector<string>> *ptrMapRegistrosPagina;
    int id_pagina;
public:
    Pagina();
    ~Pagina();

    //otras funciones
    bool vacioPtrMapRegistros();
    int get_id_pagina();
    void print_info_pagina();
    void insert_aux_dataPagina(){
        (*this->ptrMapRegistrosPagina)[1].push_back("nelzon, Elemento 1");
        (*this->ptrMapRegistrosPagina)[2].push_back("jorge, Elemento 2");
        (*this->ptrMapRegistrosPagina)[3].push_back("apaza, Elemento 3");
        this->id_pagina=1;
    }

    friend class BufferPool;
    friend class TablaMetadata;
};

#endif