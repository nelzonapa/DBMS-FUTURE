#include "Bloque.h"

Bloque::Bloque(){
    this->id_bloque=0;
    this->route_fin_bloque=" ";
    this->route_inicio_bloque=" ";
    this->capacidad_bloque=0;
}
Bloque::~Bloque(){}

//-------------get---------------------
int Bloque::get_id_bloque(){
    return this->id_bloque;
}
string Bloque::get_route_inicio_bloque(){
    return this->route_inicio_bloque;
}
string Bloque::get_route_fin_bloque(){
    return this->route_fin_bloque;
}
int Bloque::get_capacidad_bloque(){
    return this->capacidad_bloque;
}

//---------------set-------------------
void Bloque::set_id_bloque(int input){
    this->id_bloque=input;
}
void Bloque::set_route_inicio_bloque(string _route){
    this->route_inicio_bloque=_route;
}
void Bloque::set_route_fin_bloque(string _route){
    this->route_fin_bloque=_route;
}
void Bloque::set_capacidad_bloque(int input){
    this->capacidad_bloque=input;
}

//------------------others-------------
void Bloque::print_data_bloque(){
    cout<<"Información del bloque: "<<this->id_bloque<<endl;
    cout<<"id_bloque: "<<this->id_bloque<<endl;
    cout<<"route_inicio_bloque: "<<this->route_inicio_bloque<<endl;
    cout<<"route_fin_bloque: "<<this->route_fin_bloque<<endl;
    cout<<"capacidad_bloque: "<<this->capacidad_bloque<<endl;
}