#include "Plato_index.h"

Plato_Index::Plato_Index(){
    this->id_plato=0;
    this->route_fin_plato=" ";
    this->route_inicio_plato=" ";
    this->capacidad_plato=0;
}
Plato_Index::~Plato_Index(){}

//-------------get---------------------
int Plato_Index::get_id_plato(){
    return this->id_plato;
}
string Plato_Index::get_route_inicio_plato(){
    return this->route_inicio_plato;
}
string Plato_Index::get_route_fin_plato(){
    return this->route_fin_plato;
}
int Plato_Index::get_capacidad_plato(){
    return this->capacidad_plato;
}

//---------------set-------------------
void Plato_Index::set_id_plato(int input){
    this->id_plato=input;
}
void Plato_Index::set_route_inicio_plato(string _route){
    this->route_inicio_plato=_route;
}
void Plato_Index::set_route_fin_plato(string _route){
    this->route_fin_plato=_route;
}
void Plato_Index::set_capacidad_plato(int input){
    this->capacidad_plato=input;
}

//------------------others-------------
void Plato_Index::print_data_Plato(){
    cout<<"Información del plato: "<<this->id_plato<<endl;
    cout<<"id_plato: "<<this->id_plato<<endl;
    cout<<"route_inicio_plato: "<<this->route_inicio_plato<<endl;
    cout<<"route_fin_plato: "<<this->route_fin_plato<<endl;
    cout<<"capacidad_plato: "<<this->capacidad_plato<<endl;
}