#include "Superficie_index.h"

Superficie_index::Superficie_index(){
    id_superficie=0;
    direc_superficie=0;
    capacidad_superficie=0;
}
Superficie_index::Superficie_index(int _id_superficie, int _direc_superficie, int _capacidad_superficie){
    id_superficie=_id_superficie;
    direc_superficie=_direc_superficie;
    capacidad_superficie=_capacidad_superficie;
}

Superficie_index::~Superficie_index(){}

void Superficie_index::print_data_sup_index(){
    std::cout<<this->id_superficie<<"\t\t"<<this->direc_superficie<<"\t\t"<<this->capacidad_superficie<<endl;
}