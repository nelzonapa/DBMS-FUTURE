#include "Superficie.h"

Superficie::Superficie(){
    this->id_superficie=0;
    this->route_fin_superficie=" ";
    this->route_inicio_superficie=" ";
    this->capacidad_superficie=0;
}
Superficie::~Superficie(){}

//-------------get---------------------
int Superficie::get_id_superficie(){
    return this->id_superficie;
}
string Superficie::get_route_inicio_superficie(){
    return this->route_inicio_superficie;
}
string Superficie::get_route_fin_superficie(){
    return this->route_fin_superficie;
}
int Superficie::get_capacidad_superficie(){
    return this->capacidad_superficie;
}

//---------------set-------------------
void Superficie::set_id_superficie(int input){
    this->id_superficie=input;
}
void Superficie::set_route_inicio_superficie(string _route){
    this->route_inicio_superficie=_route;
}
void Superficie::set_route_fin_superficie(string _route){
    this->route_fin_superficie=_route;
}
void Superficie::set_capacidad_superficie(int input){
    this->capacidad_superficie=input;
}

//------------------others-------------
void Superficie::print_data_superficie(){
    cout<<"Información del superficie: "<<this->id_superficie<<endl;
    cout<<"id_superficie: "<<this->id_superficie<<endl;
    cout<<"route_inicio_superficie: "<<this->route_inicio_superficie<<endl;
    cout<<"route_fin_superficie: "<<this->route_fin_superficie<<endl;
    cout<<"capacidad_superficie: "<<this->capacidad_superficie<<endl;
}