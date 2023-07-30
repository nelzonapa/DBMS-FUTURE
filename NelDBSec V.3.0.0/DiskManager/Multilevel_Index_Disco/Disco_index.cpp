#include "Disco_index.h"

Disco_index::Disco_index(){
    this->id_disco=0;
    this->ruta_next_disco="";
    this->cantidades_next_disco=0;
    this->direccion_disco=0;
    this->capacidad_disco=0;
}
Disco_index::~Disco_index(){}

//-------------get---------------------
int Disco_index::get_id_disco(){
    return this->id_disco;
}

string Disco_index::get_ruta_next_disco(){
    return this->ruta_next_disco;
}

int Disco_index::get_cantidades_next_disco(){
    return this->cantidades_next_disco;
}

int Disco_index::get_direccion_disco(){
    return this->direccion_disco;
}

int Disco_index::get_capacidad_disco(){
    return this->capacidad_disco;
}

//---------------set-------------------
void Disco_index::set_id_disco(int input){
    this->id_disco=input;
}
void Disco_index::set_ruta_next_disco(string input){
    this->ruta_next_disco=input;
}

void Disco_index::set_cantidades_next_disco(int input){
    this->cantidades_next_disco=input;
}

void Disco_index::set_direccion_disco(int input){
    this->direccion_disco=input;
}

void Disco_index::set_capacidad_disco(int input){
    this->capacidad_disco=input;
}

//------------------others-------------
void Disco_index::print_data_disco(){
    cout<<"Disco: "<<this->id_disco;
    // cout<<" - "<<this->ruta_next_disco;
    // cout<<" - "<<this->cantidades_next_disco;
    cout<<" - "<<this->direccion_disco;
    cout<<" - "<<this->capacidad_disco<<endl;
}

std::ostream& operator<<(std::ostream& os, Disco_index& disco_index){
    os << disco_index.get_id_disco();
    os << "-" << disco_index.get_ruta_next_disco();
    os << "-" << disco_index.get_cantidades_next_disco();
    os << "-" << disco_index.get_direccion_disco();
    os << "-" << disco_index.get_capacidad_disco();
    return os;
}

std::istream& operator>>(std::istream& is, Disco_index& disco_index) {
    is>>disco_index.id_disco;
    is>>disco_index.ruta_next_disco;
    is>>disco_index.cantidades_next_disco;
    is>>disco_index.direccion_disco;
    is>>disco_index.capacidad_disco;

    return is;
}