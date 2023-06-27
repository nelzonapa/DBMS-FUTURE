#include "Header.h"

Header::Header(){
    this->num_records_general=0;
    this->cant_bytes_usados=0;

    this->ptr_delete_fixed_space=0;
    this->ptr_direc_end_fixed=0;
    this->num_records_fixed=0;

    this->num_records_variable=0;
    this->direc_free_space_variable=0;
}

Header::Header(int _num_records_general,int _cant_bytes_usados,int _ptr_delete_fixed_space,int _ptr_direc_end_fixed,int _num_records_fixed, int _num_records_variable, int _direc_free_space_variable){
    this->num_records_general=_num_records_general;
    this->cant_bytes_usados=_cant_bytes_usados;

    this->ptr_delete_fixed_space=_ptr_delete_fixed_space;
    this->ptr_direc_end_fixed=_ptr_direc_end_fixed;
    this->num_records_fixed=_num_records_fixed;

    this->num_records_variable=_num_records_variable;
    this->direc_free_space_variable=_direc_free_space_variable;
}

Header::~Header(){}

//GET
int Header::get_num_records_general(){
    return this->num_records_general;
}

int Header::get_cant_bytes_usados(){
    return this->cant_bytes_usados;
}

int Header::get_ptr_delete_fixed_space(){
    return this->ptr_delete_fixed_space;
}

int Header::get_ptr_direc_end_fixed(){
    return this->ptr_direc_end_fixed;
}

int Header::get_num_records_fixed(){
    return this->num_records_fixed;
}

int Header::get_num_records_variable(){
    return this->num_records_variable;
}

int Header::get_direc_free_space_variable(){
    return this->direc_free_space_variable;
}

//SET
void Header::set_num_records_general(int _input){
    this->num_records_general=_input;
}

void Header::set_cant_bytes_usados(int _input){
    this->cant_bytes_usados=_input;
}

void Header::set_ptr_delete_fixed_space(int _new_direc){
    this->ptr_delete_fixed_space=_new_direc;
}

void Header::set_ptr_direc_end_fixed(int _input){
    this->ptr_direc_end_fixed=_input;
}

void Header::set_num_records_fixed(int _input){
    this->num_records_fixed=_input;
}

void Header::set_num_records_variable(int _input){
    this->num_records_variable=_input;
}

void Header::set_direc_free_space_variable(int _input){
    this->direc_free_space_variable=_input;
}
//Print info

void Header::print_info_header(){
    std::cout<<"Header con tamanio: "<<sizeof(Header)<<endl;
    std::cout<<"Numero de records en toda la base de datos: "<<this->num_records_general<<std::endl;
    std::cout<<"Numero bytes usados en toda la base de datos: "<<this->cant_bytes_usados<<std::endl;
    
    std::cout<<"Numero de records fixed-length en toda la base de datos: "<<this->num_records_fixed<<std::endl;
    std::cout<<"Direccion delete_space_fixed_length: "<<this->ptr_delete_fixed_space<<std::endl;
    std::cout<<"Direccion end_fixed_records: "<<this->ptr_direc_end_fixed<<std::endl;    
    
    std::cout<<"Numero de records variable-length toda la base de datos: "<<this->num_records_variable<<std::endl;
    std::cout<<"Direccion direc_free_space_variable_length: "<<this->direc_free_space_variable<<std::endl;
}   