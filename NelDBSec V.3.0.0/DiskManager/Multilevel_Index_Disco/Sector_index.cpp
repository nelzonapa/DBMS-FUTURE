#include "Sector_index.h"

Sector_Index::Sector_Index(){
    this->id_sector=0;
    this->ruta_next_sector="";
    this->cantidades_next_sector=0;
    this->direccion_sector=0;
    this->capacidad_sector=0;
}
Sector_Index::~Sector_Index(){}

//-------------get---------------------
int Sector_Index::get_id_sector(){
    return this->id_sector;
}
string Sector_Index::get_ruta_next_sector(){
    return this->ruta_next_sector;
}
int Sector_Index::get_cantidades_next_sector(){
    return this->cantidades_next_sector;
}
int Sector_Index::get_direccion_sector(){
    return this->direccion_sector;
}
int Sector_Index::get_capacidad_sector(){
    return this->capacidad_sector;
}

//---------------set-------------------
void Sector_Index::set_id_sector(int input){
    this->id_sector=input;
}

void Sector_Index::set_ruta_next_sector(string input){
    this->ruta_next_sector=input;
}

void Sector_Index::set_cantidades_next_sector(int input){
    this->cantidades_next_sector=input;
}

void Sector_Index::set_direccion_sector(int input){
    this->direccion_sector=input;
}
void Sector_Index::set_capacidad_sector(int input){
    this->capacidad_sector=input;
}

//------------------others-------------
void Sector_Index::print_data_sector(){
    cout<<"Sector: "<<this->id_sector;
    // cout<<" - "<<this->ruta_next_sector;
    // cout<<" - "<<this->cantidades_next_sector;
    cout<<" - "<<this->direccion_sector;
    cout<<" - "<<this->capacidad_sector<<endl;
}

std::ostream& operator<<(std::ostream& os, Sector_Index& sector_index){
    os << sector_index.get_id_sector();
    os << "-" << sector_index.get_ruta_next_sector();
    os << "-" << sector_index.get_cantidades_next_sector();
    os << "-" << sector_index.get_direccion_sector();
    os << "-" << sector_index.get_capacidad_sector();
    return os;
}

std::istream& operator>>(std::istream& is, Sector_Index& sector_index) {
    is>>sector_index.id_sector;
    is>>sector_index.ruta_next_sector;
    is>>sector_index.cantidades_next_sector;
    is>>sector_index.direccion_sector;
    is>>sector_index.capacidad_sector;

    return is;
}