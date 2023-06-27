#include "Pagina.h"

Pagina::Pagina(int _size){
    this->size=_size;
    this->ptr_sig_pag=nullptr;
    //el vector estará vacío
}

Pagina::Pagina(){
    this->size=0;
    this->ptr_sig_pag=nullptr;
    //el vector estará vacío
}

Pagina::~Pagina(){}

int Pagina::get_size(){
    return this->size;
}

Pagina& Pagina::get_next_pagina(){
    return (*this->ptr_sig_pag);
}


void Pagina::set_size(int _size){
    this->size=size;
}

void Pagina::insert_back_vector(char* _registro){
    this->vector_registros.push_back(_registro);
}

void Pagina::insert_postion_vector(char* _registro, int posicion){
    (this->vector_registros).insert((this->vector_registros).begin() + posicion, _registro); // Insertar en la posición
}

void Pagina::delete_register_vector(int posicion){
    this->vector_registros.erase(this->vector_registros.begin() + posicion); // Eliminar el elemento en la posición
}

void Pagina::update_register_vector(char* _registro, int posicion){
    delete_register_vector(posicion);
    insert_postion_vector(_registro,posicion);
}