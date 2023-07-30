#include "Pista_index.h"

Pista_Index::Pista_Index(){
    this->id_pista=0;
    this->ruta_next_pista="";
    this->cantidades_next_pista=0;
    this->direccion_pista=0;
    this->capacidad_pista=0;
}
Pista_Index::~Pista_Index(){}

//-------------get---------------------
int Pista_Index::get_id_pista(){
    return this->id_pista;
}

string Pista_Index::get_ruta_next_pista(){
    return this->ruta_next_pista;
}
int Pista_Index::get_cantidades_next_pista(){
    return this->cantidades_next_pista;
}

int Pista_Index::get_direccion_pista(){
    return this->direccion_pista;
}

int Pista_Index::get_capacidad_pista(){
    return this->capacidad_pista;
}

//---------------set-------------------
void Pista_Index::set_id_pista(int input){
    this->id_pista=input;
}

void Pista_Index::set_ruta_next_pista(string input){
    this->ruta_next_pista=input;
}

void Pista_Index::set_cantidades_next_pista(int input){
    this->cantidades_next_pista=input;
}


void Pista_Index::set_direccion_pista(int _route){
    this->direccion_pista=_route;
}

void Pista_Index::set_capacidad_pista(int input){
    this->capacidad_pista=input;
}

//------------------others-------------
void Pista_Index::print_data_pista(){
    cout<<"Pista: "<<this->id_pista;
    // cout<<" - "<<this->ruta_next_pista;
    // cout<<" - "<<this->cantidades_next_pista;
    cout<<" - "<<this->direccion_pista;
    cout<<" - "<<this->capacidad_pista<<endl;
}

std::ostream& operator<<(std::ostream& os, Pista_Index& pista_index){
    os << pista_index.get_id_pista();
    os << "-" << pista_index.get_ruta_next_pista();
    os << "-" << pista_index.get_cantidades_next_pista();
    os << "-" << pista_index.get_direccion_pista();
    os << "-" << pista_index.get_capacidad_pista();
    return os;
}

std::istream& operator>>(std::istream& is, Pista_Index& pista_index) {
    is>>pista_index.id_pista;
    is>>pista_index.ruta_next_pista;
    is>>pista_index.cantidades_next_pista;
    is>>pista_index.direccion_pista;
    is>>pista_index.capacidad_pista;

    return is;
}