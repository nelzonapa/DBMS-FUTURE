#include "Pista.h"

Pista::Pista(){
    this->id_pista=0;
    this->route_fin_pista=" ";
    this->route_inicio_pista=" ";
    this->capacidad_pista=0;
}
Pista::~Pista(){}

//-------------get---------------------
int Pista::get_id_pista(){
    return this->id_pista;
}
string Pista::get_route_inicio_pista(){
    return this->route_inicio_pista;
}
string Pista::get_route_fin_pista(){
    return this->route_fin_pista;
}
int Pista::get_capacidad_pista(){
    return this->capacidad_pista;
}

//---------------set-------------------
void Pista::set_id_pista(int input){
    this->id_pista=input;
}
void Pista::set_route_inicio_pista(string _route){
    this->route_inicio_pista=_route;
}
void Pista::set_route_fin_pista(string _route){
    this->route_fin_pista=_route;
}
void Pista::set_capacidad_pista(int input){
    this->capacidad_pista=input;
}

//------------------others-------------
void Pista::print_data_pista(){
    cout<<"Información del pista: "<<this->id_pista<<endl;
    cout<<"id_pista: "<<this->id_pista<<endl;
    cout<<"route_inicio_pista: "<<this->route_inicio_pista<<endl;
    cout<<"route_fin_pista: "<<this->route_fin_pista<<endl;
    cout<<"capacidad_pista: "<<this->capacidad_pista<<endl;
}