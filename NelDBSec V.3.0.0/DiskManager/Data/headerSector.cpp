#include "headerSector.h"

headerSector::headerSector(){
    //general
    this->cant_bytes_bloque=0;
    this->cant_bytes_usados_bloque=0;
    this->cant_bytes_restantes_bloque=0;
    this->num_general_records_bloque=0;
    
    //fixed length
    this->direc_space_delete_fixed_bloque=0;
    this->direc_end_fixed_bloque=0;
    this->num_records_fixed_bloque=0;
    this->direc_primer_record_fixed_length=0;

    //variable length
    this->direc_space_delete_variable_bloque=0;
    this->num_records_variable_bloque=0;
    this->direc_free_space_variable_bloque=0;
    this->direc_primer_record_variable_length=0;
}

headerSector::~headerSector(){}

//--------------------GET-------------------
//general
int headerSector::get_cant_bytes_bloque(){
    return this->cant_bytes_bloque;
}
int headerSector::get_cant_bytes_usados_bloque(){
    return this->cant_bytes_usados_bloque;
}
int headerSector::get_cant_bytes_restantes_bloque(){
    return this->cant_bytes_restantes_bloque;
}
int headerSector::get_num_general_records_bloque(){
    return this->num_general_records_bloque;
}

//-------------------------fixed length
int headerSector::get_direc_space_delete_fixed_bloque(){
    return this->direc_space_delete_fixed_bloque;
}
int headerSector::get_direc_end_fixed_bloque(){
    return this->direc_end_fixed_bloque;
}
int headerSector::get_num_records_fixed_bloque(){
    return this->num_records_fixed_bloque;
}

int headerSector::get_direc_primer_record_fixed_length(){
    return this->direc_primer_record_fixed_length;
}

//--------------------------variable length

int headerSector::get_direc_space_delete_variable_bloque(){
    return this->direc_space_delete_variable_bloque;
}

int headerSector::get_num_records_variable_bloque(){
    return this->num_records_variable_bloque;
}
int headerSector::get_direc_free_space_variable_bloque(){
    return this->direc_free_space_variable_bloque;
}

int headerSector::get_direc_primer_record_variable_length(){
    return this->direc_primer_record_variable_length;
}



//--------------------SET-------------------
//general
void headerSector::set_cant_bytes_bloque(int _input){
    this->cant_bytes_bloque=_input;
}
void headerSector::set_cant_bytes_usados_bloque(int _input){
    this->cant_bytes_usados_bloque=_input;
}
void headerSector::set_cant_bytes_restantes_bloque(int _input){
    this->cant_bytes_restantes_bloque=_input;
}
void headerSector::set_num_general_records_bloque(int _input){
    this->num_general_records_bloque=_input;
}

//fixed length
void headerSector::set_direc_space_delete_fixed_bloque(int _input){
    this->direc_space_delete_fixed_bloque=_input;
}
void headerSector::set_direc_end_fixed_bloque(int _input){
    this->direc_end_fixed_bloque=_input;
}
void headerSector::set_num_records_fixed_bloque(int _input){
    this->num_records_fixed_bloque=_input;
}

void headerSector::set_direc_primer_record_fixed_length(int _input){
    this->direc_primer_record_fixed_length=_input;
}

//variable length

void headerSector::set_direc_space_delete_variable_bloque(int _input){
    this->direc_space_delete_variable_bloque=_input;
}

void headerSector::set_num_records_variable_bloque(int _input){
    this->num_records_variable_bloque=_input;
}
void headerSector::set_direc_free_space_variable_bloque(int _input){
    this->direc_free_space_variable_bloque=_input;
}

void headerSector::set_direc_primer_record_variable_length(int _input){
    this->direc_primer_record_variable_length=_input;
}

//--------------------Others-------------------

void headerSector::print_info_header_bloque(){
    //general
    cout<<"Mostrando informacion que almacena el headerSector"<<endl;
    cout<<"- cant_bytes_bloque: "<<this->cant_bytes_bloque<<endl;
    cout<<"- cant_bytes_usados_bloque: "<<this->cant_bytes_usados_bloque<<endl;
    cout<<"- cant_bytes_restantes_bloque: "<<this->cant_bytes_restantes_bloque<<endl;
    cout<<"- num_general_records_bloque: "<<this->num_general_records_bloque<<endl;
    
    //fixed length
    cout<<"- direc_space_delete_fixed_bloque: "<<this->direc_space_delete_fixed_bloque<<endl;
    cout<<"- direc_end_fixed_bloque: "<<this->direc_end_fixed_bloque<<endl;
    cout<<"- num_records_fixed_bloque: "<<this->num_records_fixed_bloque<<endl;

    //variable length
    cout<<"- num_records_variable_bloque: "<<this->num_records_variable_bloque<<endl;
    cout<<"- direc_free_space_variable_bloque: "<<this->direc_free_space_variable_bloque<<endl;
}   