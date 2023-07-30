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

Pagina& Programa::obtenerPagina(int id_pagina){
    (*this->ptr_buffManager).agregarPagina_BuffPool_tablaMetadata(1);
    cout<<"..-..rr"<<endl;
    (*this->ptr_pagina_recibir)=(*this->ptr_buffManager).get_pagina_retornar();
    cout<<"Pagina recibida, mostrando estado de la tabla de metadata"<<endl;
    (*this->ptr_buffManager).mostrar_tabla_metadata();
    cout<<"Mostrando pagina recibida..."<<endl;
    (*this->ptr_pagina_recibir).print_info_pagina();
}
