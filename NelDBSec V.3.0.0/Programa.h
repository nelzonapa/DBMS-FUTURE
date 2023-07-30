#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "Main_Memory/BufferManager/BufferManager.h"
#include "Main_Memory/BufferManager/BufferManager.cpp"


class Programa
{
private:
    BufferManager *ptr_buffManager;
    Pagina *ptr_pagina_recibir;
public:
    Programa();
    ~Programa();

    void setPtrPaginaRecibir(Pagina &pagina);
    
    Pagina& obtenerPagina(int id_pagina);
};


#endif