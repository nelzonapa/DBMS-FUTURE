#include "Plato.h"

Plato::Plato(){
    this->id_plato=0;
    this->route_fin_plato=" ";
    this->route_inicio_plato=" ";
    this->capacidad_plato=0;
}
Plato::~Plato(){}

//-------------get---------------------
int Plato::get_id_plato(){
    return this->id_plato;
}
string Plato::get_route_inicio_plato(){
    return this->route_inicio_plato;
}
string Plato::get_route_fin_plato(){
    return this->route_fin_plato;
}
int Plato::get_capacidad_plato(){
    return this->capacidad_plato;
}

//---------------set-------------------
void Plato::set_id_plato(int input){
    this->id_plato=input;
}
void Plato::set_route_inicio_plato(string _route){
    this->route_inicio_plato=_route;
}
void Plato::set_route_fin_plato(string _route){
    this->route_fin_plato=_route;
}
void Plato::set_capacidad_plato(int input){
    this->capacidad_plato=input;
}

//------------------others-------------
void Plato::print_data_Plato(){
    cout<<"Información del plato: "<<this->id_plato<<endl;
    cout<<"id_plato: "<<this->id_plato<<endl;
    cout<<"route_inicio_plato: "<<this->route_inicio_plato<<endl;
    cout<<"route_fin_plato: "<<this->route_fin_plato<<endl;
    cout<<"capacidad_plato: "<<this->capacidad_plato<<endl;
}