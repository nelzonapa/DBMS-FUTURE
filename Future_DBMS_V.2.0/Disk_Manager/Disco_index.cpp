#include "Disco_index.h"

Disco_index::Disco_index(){
    this->id_disco=0;
    this->route_fin_disco=" ";
    this->route_inicio_disco=" ";
    this->capacidad_disco=0;
}
Disco_index::~Disco_index(){}

//-------------get---------------------
int Disco_index::get_id_disco(){
    return this->id_disco;
}
string Disco_index::get_route_fin_disco(){
    return this->route_fin_disco;
}
string Disco_index::get_route_inicio_disco(){
    return this->route_inicio_disco;
}
int Disco_index::get_capacidad_disco(){
    return this->capacidad_disco;
}

//---------------set-------------------
void Disco_index::set_id_disco(int input){
    this->id_disco=input;
}
void Disco_index::set_route_fin_disco(string input){
    this->route_fin_disco=input;
}
void Disco_index::set_route_inicio_disco(string input){
    this->route_inicio_disco=input;
}
void Disco_index::set_capacidad_disco(int input){
    this->capacidad_disco=input;
}

//------------------others-------------
void Disco_index::print_data_disco(){
    cout<<"Data Disco_index: "<<endl;
    cout<<"id_disco: "<<this->id_disco<<endl;
    cout<<"route_fin_disco: "<<this->route_fin_disco<<endl;
    cout<<"route_inicio_disco: "<<this->route_inicio_disco<<endl;
    cout<<"capacidad_disco: "<<this->capacidad_disco<<endl;
}