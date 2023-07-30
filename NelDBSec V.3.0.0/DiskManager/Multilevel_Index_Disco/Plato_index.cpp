#include "Plato_index.h"

Plato_Index::Plato_Index(){
    this->id_plato=0;
    this->ruta_next_plato="";
    this->cantidades_next_plato=0;
    this->direccion_plato=0;
    this->capacidad_plato=0;
}
Plato_Index::~Plato_Index(){}

//-------------get---------------------
int Plato_Index::get_id_plato(){
    return this->id_plato;
}

string Plato_Index::get_ruta_next_plato(){
    return this->ruta_next_plato;
}
int Plato_Index::get_cantidades_next_plato(){
    return this->cantidades_next_plato;
}

int Plato_Index::get_direccion_plato(){
    return this->direccion_plato;
}

int Plato_Index::get_capacidad_plato(){
    return this->capacidad_plato;
}

//---------------set-------------------
void Plato_Index::set_id_plato(int input){
    this->id_plato=input;
}

void Plato_Index::set_ruta_next_plato(string input){
    this->ruta_next_plato=input;
}

void Plato_Index::set_cantidades_next_plato(int input){
    this->cantidades_next_plato=input;
}

void Plato_Index::set_direccion_plato(int input){
    this->direccion_plato=input;
}

void Plato_Index::set_capacidad_plato(int input){
    this->capacidad_plato=input;
}

//------------------others-------------
void Plato_Index::print_data_Plato(){
    cout<<"Plato: "<<this->id_plato;
    // cout<<" - "<<this->ruta_next_plato;
    // cout<<" - "<<this->cantidades_next_plato;
    cout<<" - "<<this->direccion_plato;
    cout<<" - "<<this->capacidad_plato<<endl;
}

std::ostream& operator<<(std::ostream& os, Plato_Index& plato_index){
    os << plato_index.get_id_plato();
    os << "-" << plato_index.get_ruta_next_plato();
    os << "-" << plato_index.get_cantidades_next_plato();
    os << "-" << plato_index.get_direccion_plato();
    os << "-" << plato_index.get_capacidad_plato();
    return os;
}

std::istream& operator>>(std::istream& is, Plato_Index& plato_index) {
    is>>plato_index.id_plato;
    is>>plato_index.ruta_next_plato;
    is>>plato_index.cantidades_next_plato;
    is>>plato_index.direccion_plato;
    is>>plato_index.capacidad_plato;

    return is;
}
