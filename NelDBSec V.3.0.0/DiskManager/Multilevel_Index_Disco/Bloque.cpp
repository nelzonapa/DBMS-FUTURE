#include "Bloque.h"

Bloque::Bloque(){
    this->id_bloque=0;
    this->direccion_inicio_bloque=0;
    this->capacidad_bloque=0;
    /*------*/
    this->num_records_general=0;
    this->cant_bytes_usados=0;

    this->ptr_delete_fixed_space=0;
    this->ptr_direc_end_fixed=0;
    this->num_records_fixed=0;

    this->num_records_variable=0;
    this->direc_free_space_variable=0;
}
Bloque::~Bloque(){}

//-------------get---------------------
int Bloque::get_id_bloque(){
    return this->id_bloque;
}
int Bloque::get_direccion_inicio_bloque(){
    return this->direccion_inicio_bloque;
}
int Bloque::get_capacidad_bloque(){
    return this->capacidad_bloque;
}


int Bloque::get_num_records_general(){
    return this->num_records_general;
}

int Bloque::get_cant_bytes_usados(){
    return this->cant_bytes_usados;
}

int Bloque::get_ptr_delete_fixed_space(){
    return this->ptr_delete_fixed_space;
}

int Bloque::get_ptr_direc_end_fixed(){
    return this->ptr_direc_end_fixed;
}

int Bloque::get_num_records_fixed(){
    return this->num_records_fixed;
}

int Bloque::get_num_records_variable(){
    return this->num_records_variable;
}

int Bloque::get_direc_free_space_variable(){
    return this->direc_free_space_variable;
}


//---------------set-------------------
void Bloque::set_id_bloque(int input){
    this->id_bloque=input;
}
void Bloque::set_direccion_inicio_bloque(int input){
    this->direccion_inicio_bloque=input;
}
void Bloque::set_capacidad_bloque(int input){
    this->capacidad_bloque=input;
}


void Bloque::set_num_records_general(int _input){
    this->num_records_general=_input;
}

void Bloque::set_cant_bytes_usados(int _input){
    this->cant_bytes_usados=_input;
}

void Bloque::set_ptr_delete_fixed_space(int _new_direc){
    this->ptr_delete_fixed_space=_new_direc;
}

void Bloque::set_ptr_direc_end_fixed(int _input){
    this->ptr_direc_end_fixed=_input;
}

void Bloque::set_num_records_fixed(int _input){
    this->num_records_fixed=_input;
}

void Bloque::set_num_records_variable(int _input){
    this->num_records_variable=_input;
}

void Bloque::set_direc_free_space_variable(int _input){
    this->direc_free_space_variable=_input;
}

//------------------others-------------
void Bloque::print_data_bloque(){
    cout<<"Bloque: "<<this->id_bloque;
    // cout<<" - "<<this->direccion_inicio_bloque;
    cout<<" - "<<this->capacidad_bloque<<endl;
    std::cout<<"Numero de records en el bloque: "<<this->num_records_general<<std::endl;
    std::cout<<"Numero bytes usados en el bloque: "<<this->cant_bytes_usados<<std::endl;
    
    std::cout<<"Numero de records fixed-length en el bloque: "<<this->num_records_fixed<<std::endl;
    std::cout<<"Direccion delete_space_fixed_length: "<<this->ptr_delete_fixed_space<<std::endl;
    std::cout<<"Direccion end_fixed_records: "<<this->ptr_direc_end_fixed<<std::endl;    
    
    std::cout<<"Numero de records variable-length en el bloque: "<<this->num_records_variable<<std::endl;
    std::cout<<"Direccion direc_free_space_variable_length: "<<this->direc_free_space_variable<<std::endl;
}

std::ostream& operator<<(std::ostream& os, Bloque& bloque){
    os <<bloque.get_id_bloque();
    os << "-" << bloque.get_direccion_inicio_bloque();
    os << "-" << bloque.get_capacidad_bloque();
    os << "-" << bloque.get_num_records_general();
    os << "-" << bloque.get_cant_bytes_usados();

    os << "-" << bloque.get_num_records_fixed();
    os << "-" << bloque.get_ptr_delete_fixed_space();
    os << "-" << bloque.get_ptr_direc_end_fixed();

    os << "-" << bloque.get_num_records_variable();
    os << "-" << bloque.get_direc_free_space_variable();
    return os;
}

std::istream& operator>>(std::istream& is, Bloque& bloque) {
    // Leer los datos de is y asignarlos a los atributos de disco_header
    is>>bloque.id_bloque;
    is>>bloque.direccion_inicio_bloque;
    is>>bloque.capacidad_bloque;
    is>>bloque.num_records_general;
    is>>bloque.cant_bytes_usados;

    is>>bloque.num_records_fixed;
    is>>bloque.ptr_delete_fixed_space;
    is>>bloque.ptr_direc_end_fixed;

    is>>bloque.num_records_variable;
    is>>bloque.direc_free_space_variable;

    return is;
}