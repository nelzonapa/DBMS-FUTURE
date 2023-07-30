#include "BufferPool.h"

BufferPool::BufferPool(int _num_frames){
    this->num_frames=_num_frames;
    this->ptrMapFramesBufPool=new map<int,Pagina>();
}
BufferPool::BufferPool(){
    this->ptrMapFramesBufPool=new map<int,Pagina>();
}

BufferPool::~BufferPool(){}

Pagina& BufferPool::get_pagina(int id_pag){
    Pagina *ptr_pagina;
    if ((*this->ptrMapFramesBufPool).find(id_pag) != ((*this->ptrMapFramesBufPool).end())) 
    {
        (*ptr_pagina)=(*this->ptrMapFramesBufPool)[id_pag];
        cout<<"El segundo valor para "<<id_pag<<" es: "<<endl;
        (*ptr_pagina).print_info_pagina();
    } 
    else 
    {
        cout<<"La clave o pagina"<<id_pag<<" no se encontro en el mapa."<<endl;
    }
}

void BufferPool::agregar_pagina(Pagina &pagina,int id_pag){
    pagina.print_info_pagina();
    cout<<id_pag<<endl;
    cout<<"buyaa"<<endl;
    map<int,Pagina> mapAux;
    mapAux.insert(make_pair(id_pag,pagina));
    
    for (auto elemento : mapAux) {
        int clave = elemento.first;
        Pagina pagina = elemento.second;
        std::cout << "Clave: " << clave << ", ";
        pagina.print_info_pagina();
        std::cout << std::endl;
    }
    
    std::map<int,Pagina> *ptrMapAux=new std::map<int,Pagina>();
    cout<<"buyaa"<<endl;
    (*ptrMapAux)[id_pag]=pagina;
    cout<<"buyaa"<<endl;
    mostrarBufferPool();

    (this->ptrMapFramesBufPool)=(ptrMapAux);

    cout<<"Pagina agregada en el Buffer Pool..."<<id_pag<<endl;
}

void BufferPool::eliminar_pagina(int id_pag){
    auto iter = (*this->ptrMapFramesBufPool).find(id_pag);
    if (iter != ((*this->ptrMapFramesBufPool).end())) 
    {
        (*this->ptrMapFramesBufPool).erase(iter);
        cout<<"Se elimino la pagina con clave "<<id_pag<<endl;
    } 
    else
    {
        cout<<"La pagina con clave "<<id_pag<<" no se encontro en el mapa."<<endl;
    }
}

void BufferPool::replace_pagina(Pagina &pagina,int id_pag){
    eliminar_pagina(id_pag);
    agregar_pagina(pagina,id_pag);
    cout<<"Pagina "<<id_pag<<" reemplazada"<<endl;
}

void BufferPool::mostrarBufferPool(){
    for (auto elemento : (*this->ptrMapFramesBufPool)) {
        int clave = elemento.first;
        Pagina pagina = elemento.second;
        std::cout << "Clave: " << clave << ", ";
        pagina.print_info_pagina();
        std::cout << std::endl;
    }
}