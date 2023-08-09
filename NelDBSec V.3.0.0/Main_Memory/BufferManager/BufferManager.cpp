#include "BufferManager.h"

BufferManager::BufferManager(int input){
    this->num_frames=input;

}

BufferManager::~BufferManager(){}

BufferManager::BufferManager(){
    this->num_frames=0;

}


void BufferManager::set_num_frames(int input){
    this->num_frames=input;
}

Pagina& BufferManager::get_pagina_retornar(){
    return (this->paginaRetornar);
}


// ------------------ BufferPool -----------------
void BufferManager::agregarPaginaBufferPool(int idPag){}
void BufferManager::mostrarBufferPool(){}


//------------- Tabla Metadata ----------------
void BufferManager::agregarPaginaTablaMetadata(int id_pag){
    // (this->tablaMetadata).
    bool tabla_vacia=(this->tablaMetadata).tabla_vacia();
    if (tabla_vacia==true)//en caso de estar vacía
    {
        
        (paginaRetornar).insert_aux_dataPagina();
        // (*ptr_pagina_aux).print_info_pagina();

        //digamos que ya se recibió esta pagina del DISK MANAGER
        (this->tablaMetadata).agregar_pagina_tabla_metadata(id_pag);
        cout<<"____________-"<<endl;
        // (this->tablaMetadata).imprimir_toda_tabla_metadata();
        //Ahora agregamos al buffer pool:
        // (this->bufferPool).agregar_pagina((*ptr_pagina_aux),(this->paginaRetornar).get_id_pagina());
    }
    else
    {
        bool existe_pagina=(this->tablaMetadata).comprobar_existe_pagina(id_pag);
        if (existe_pagina == false)
        {
            cout<<"BuffManager: Su pagina ya existe en memoria"<<endl;
        }
        else
        {
            cout<<"BuffManager: Su pagina NO existe en memoria, solicitando al Disk Manager..."<<endl;
            // this->diskManager.
            Pagina pagina_aux;
            pagina_aux.insert_aux_dataPagina();
            (this->paginaRetornar)=pagina_aux;
            //digamos que ya se recibió esta pagina del DISK MANAGER
            // (this->tablaMetadata)->agregar_pagina_tabla_metadata((this->paginaRetornar).get_id_pagina());

            //Ahora agregamos al buffer pool:
            // (this->bufferPool)->agregar_pagina((this->paginaRetornar),(this->paginaRetornar).get_id_pagina());
        }
    }
    
}

void BufferManager::mostrarTablaMetadata(){
    this->tablaMetadata.imprimir_toda_tabla_metadata();
}


//Obtener del Disk Manager
    void obtenerPaginaDiskManager();