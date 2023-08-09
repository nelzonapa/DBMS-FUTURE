#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

// #include "../BufferPool/Pagina.h"
// #include "../BufferPool/Pagina.cpp"

#include "../BufferPool/BufferPool.h"
#include "../BufferPool/BufferPool.cpp"

#include "TablaMetadata.h"
#include "TablaMetadata.cpp"

// #include "../../DiskManager/DiskManager.h"
#include "../../DiskManager/DiskManager.cpp"


#include <list>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

class BufferManager
{
private:
    BufferPool bufferPool;
    TablaMetadata tablaMetadata;
    Pagina paginaRetornar;
    int num_frames; // Tamaño máximo del Buffer Pool
    DiskManager diskManager;
public:
    BufferManager(int input);
    BufferManager();
    ~BufferManager();

    //SETTERS
    void set_num_frames(int input);

    Pagina& get_pagina_retornar();
    
    //BufferPool
    void agregarPaginaBufferPool(int idPag);
    void mostrarBufferPool();

    //Metadata
    void agregarPaginaTablaMetadata(int idPag);
    void mostrarTablaMetadata();

    //----Disk Manager----
    void obtenerPaginaDiskManager();
    void ingresarDatosDesdeArchivoCSV(string nombreArchivo);
};

#endif