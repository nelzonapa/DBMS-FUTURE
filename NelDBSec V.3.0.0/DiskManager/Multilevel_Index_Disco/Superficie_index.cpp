#include "Superficie_index.h"

Superficie_Index::Superficie_Index(){
    this->id_superficie=0;
    this->ruta_next_superficie="";
    this->cantidades_next_superficie=0;
    this->direccion_superficie=0;
    this->capacidad_superficie=0;
}
Superficie_Index::~Superficie_Index(){}

//-------------get---------------------
int Superficie_Index::get_id_superficie(){
    return this->id_superficie;
}

string Superficie_Index::get_ruta_next_superficie(){
    return this->ruta_next_superficie;
}
int Superficie_Index::get_cantidades_next_superficie(){
    return this->cantidades_next_superficie;
}

int Superficie_Index::get_direccion_superficie(){
    return this->direccion_superficie;
}

int Superficie_Index::get_capacidad_superficie(){
    return this->capacidad_superficie;
}

//---------------set-------------------
void Superficie_Index::set_id_superficie(int input){
    this->id_superficie=input;
}

void Superficie_Index::set_ruta_next_superficie(string input){
    this->ruta_next_superficie=input;
}

void Superficie_Index::set_cantidades_next_superficie(int input){
    this->cantidades_next_superficie=input;
}

void Superficie_Index::set_direccion_superficie(int input){
    this->direccion_superficie=input;
}
void Superficie_Index::set_capacidad_superficie(int input){
    this->capacidad_superficie=input;
}

//------------------others-------------
void Superficie_Index::print_data_superficie(){
    cout<<"Superficie: "<<this->id_superficie;
    // cout<<" - "<<this->ruta_next_superficie;
    // cout<<" - "<<this->cantidades_next_superficie;
    cout<<" - "<<this->direccion_superficie;
    cout<<" - "<<this->capacidad_superficie<<endl;
}

std::ostream& operator<<(std::ostream& os, Superficie_Index& superficie_index){
    os << superficie_index.get_id_superficie();
    os << "-" << superficie_index.get_ruta_next_superficie();
    os << "-" << superficie_index.get_cantidades_next_superficie();
    os << "-" << superficie_index.get_direccion_superficie();
    os << "-" << superficie_index.get_capacidad_superficie();
    return os;
}

std::istream& operator>>(std::istream& is, Superficie_Index& superficie_index) {
    is>>superficie_index.id_superficie;
    is>>superficie_index.ruta_next_superficie;
    is>>superficie_index.cantidades_next_superficie;
    is>>superficie_index.direccion_superficie;
    is>>superficie_index.capacidad_superficie;

    return is;
}