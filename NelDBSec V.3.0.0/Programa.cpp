#include "Programa.h"

Programa::Programa()
{
    int num_frames;
    cout<<"ingrese el numero de frames con el que se pueda trabajar: "<<endl;
    cin>>num_frames;
    this->ptr_buffManager=new BufferManager(num_frames);
    //Guardamos
    this->ptr_pagina_recibir=nullptr;
}

Programa::~Programa(){}

void Programa::setPtrPaginaRecibir(Pagina &pagina){
    (*this->ptr_pagina_recibir)=pagina;
}

Pagina& Programa::obtenerPagina(int id_pagina){
    /*
    Primero busca en el B+ tree y este le permite sacar del disco el bloque o sector necesitado
    - Quién busca: Disk Manager
    - Una vez encontrado, retorna la página al Buffer Manager
    - Buffer manager: Agrega dato a TablaMetadta y agrega la página a Buffer Pool
    - Retorna la página al Programa
    */
    (*this->ptr_buffManager).agregarPagina_BuffPool_tablaMetadata(1);
    cout<<"..-..rr"<<endl;
    // (*this->ptr_pagina_recibir)=(*this->ptr_buffManager).get_pagina_retornar();
    cout<<"Pagina recibida, mostrando estado de la tabla de metadata"<<endl;
    (*this->ptr_buffManager).mostrar_tabla_metadata();
    // cout<<"Mostrando pagina recibida..."<<endl;
    // (*this->ptr_pagina_recibir).print_info_pagina();
    cout<<".........."<<endl;
    Pagina *ptr_paginaAux;
    Pagina pagina;
    pagina.insert_aux_dataPagina();
    *ptr_paginaAux=pagina;
    // (*ptr_paginaAux).insert_aux_dataPagina();
    cout<<".........."<<endl;
    return (*ptr_paginaAux);
}
