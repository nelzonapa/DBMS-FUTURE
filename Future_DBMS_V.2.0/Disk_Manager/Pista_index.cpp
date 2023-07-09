#include "Pista_index.h"

Pista_Index::Pista_Index(){
    this->id_pista=0;
    this->route_fin_pista=" ";
    this->route_inicio_pista=" ";
    this->capacidad_pista=0;
}
Pista_Index::~Pista_Index(){}

//-------------get---------------------
int Pista_Index::get_id_pista(){
    return this->id_pista;
}
string Pista_Index::get_route_inicio_pista(){
    return this->route_inicio_pista;
}
string Pista_Index::get_route_fin_pista(){
    return this->route_fin_pista;
}
int Pista_Index::get_capacidad_pista(){
    return this->capacidad_pista;
}

//---------------set-------------------
void Pista_Index::set_id_pista(int input){
    this->id_pista=input;
}
void Pista_Index::set_route_inicio_pista(string _route){
    this->route_inicio_pista=_route;
}
void Pista_Index::set_route_fin_pista(string _route){
    this->route_fin_pista=_route;
}
void Pista_Index::set_capacidad_pista(int input){
    this->capacidad_pista=input;
}

//------------------others-------------
void Pista_Index::print_data_pista(){
    cout<<"Información del pista: "<<this->id_pista<<endl;
    cout<<"id_pista: "<<this->id_pista<<endl;
    cout<<"route_inicio_pista: "<<this->route_inicio_pista<<endl;
    cout<<"route_fin_pista: "<<this->route_fin_pista<<endl;
    cout<<"capacidad_pista: "<<this->capacidad_pista<<endl;
}