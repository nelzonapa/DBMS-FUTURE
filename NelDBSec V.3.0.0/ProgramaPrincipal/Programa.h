#ifndef PROGRAMA_H
#define PROGRAMA_H

// #include "Main_Memory/BufferManager/BufferManager.h"
#include "../Main_Memory/BufferManager/BufferManager.cpp"


class Programa
{
private:
    BufferManager buffManagerPrograma;
    Pagina paginaRecibir;
public:
    Programa();
    ~Programa();

    void setPtrPaginaRecibir(Pagina &pagina);
    
    Pagina& obtenerPagina(int id_pagina);

    void ingresarTablaDesdeArchivoCSV(string nombreArchivo);

    void mostrarTablaMetadata();
    void mostrarBufferPool();
    
};


#endif