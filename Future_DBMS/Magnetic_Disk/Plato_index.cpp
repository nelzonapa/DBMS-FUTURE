#include "Plato_index.h"

Plato_index::Plato_index(){
    this->id_plato=0;
    this->direc_plato=0;
    this->capacidad_plato=0;
}
Plato_index::Plato_index(int _id_plato, int _direc_plato, int _capacidad_plato){
    this->id_plato=_id_plato;
    this->direc_plato=_direc_plato;
    this->capacidad_plato=_capacidad_plato;
}

Plato_index::~Plato_index(){}

void Plato_index::print_data_plato_index(){
    std::cout<<id_plato<<"\t\t"<<this->direc_plato<<"\t\t"<<this->capacidad_plato<<endl;
}