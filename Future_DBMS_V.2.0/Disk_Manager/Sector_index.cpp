#include "Sector_index.h"

Sector_Index::Sector_Index(){
    this->id_sector=0;
    this->route_fin_sector=" ";
    this->route_inicio_sector=" ";
    this->capacidad_sector=0;
}
Sector_Index::~Sector_Index(){}

//-------------get---------------------
int Sector_Index::get_id_sector(){
    return this->id_sector;
}
string Sector_Index::get_route_inicio_sector(){
    return this->route_inicio_sector;
}
string Sector_Index::get_route_fin_sector(){
    return this->route_fin_sector;
}
int Sector_Index::get_capacidad_sector(){
    return this->capacidad_sector;
}

//---------------set-------------------
void Sector_Index::set_id_sector(int input){
    this->id_sector=input;
}
void Sector_Index::set_route_inicio_sector(string _route){
    this->route_inicio_sector=_route;
}
void Sector_Index::set_route_fin_sector(string _route){
    this->route_fin_sector=_route;
}
void Sector_Index::set_capacidad_sector(int input){
    this->capacidad_sector=input;
}

//------------------others-------------
void Sector_Index::print_data_sector(){
    cout<<"Información del sector: "<<this->id_sector<<endl;
    cout<<"id_sector: "<<this->id_sector<<endl;
    cout<<"route_inicio_sector: "<<this->route_inicio_sector<<endl;
    cout<<"route_fin_sector: "<<this->route_fin_sector<<endl;
    cout<<"capacidad_sector: "<<this->capacidad_sector<<endl;
}