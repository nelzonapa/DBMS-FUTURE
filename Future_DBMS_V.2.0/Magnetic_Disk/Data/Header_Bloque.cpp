#include "Header_Bloque.h"

Header_Bloque::Header_Bloque(){
    //general
    this->cant_bytes_bloque=0;
    this->cant_bytes_usados_bloque=0;
    this->cant_bytes_restantes_bloque=0;
    this->num_general_records_bloque=0;
    
    //fixed length
    this->direc_space_delete_fixed_bloque=0;
    this->direc_end_fixed_bloque=0;
    this->num_records_fixed_bloque=0;

    //variable length
    this->num_records_variable_bloque=0;
    this->direc_free_space_variable_bloque=0;
}

Header_Bloque::~Header_Bloque(){}

//--------------------GET-------------------
//general
int Header_Bloque::get_cant_bytes_bloque(){
    return this->cant_bytes_bloque;
}
int Header_Bloque::get_cant_bytes_usados_bloque(){
    return this->cant_bytes_usados_bloque;
}
int Header_Bloque::get_cant_bytes_restantes_bloque(){
    return this->cant_bytes_restantes_bloque;
}
int Header_Bloque::get_num_general_records_bloque(){
    return this->num_general_records_bloque;
}

//fixed length
int Header_Bloque::get_direc_space_delete_fixed_bloque(){
    return this->direc_space_delete_fixed_bloque;
}
int Header_Bloque::get_direc_end_fixed_bloque(){
    return this->direc_end_fixed_bloque;
}
int Header_Bloque::get_num_records_fixed_bloque(){
    return this->num_records_fixed_bloque;
}

//variable length
int Header_Bloque::get_num_records_variable_bloque(){
    return this->num_records_variable_bloque;
}
int Header_Bloque::get_direc_free_space_variable_bloque(){
    return this->direc_free_space_variable_bloque;
}



//--------------------SET-------------------
//general
void Header_Bloque::set_cant_bytes_bloque(int _input){
    this->cant_bytes_bloque=_input;
}
void Header_Bloque::set_cant_bytes_usados_bloque(int _input){
    this->cant_bytes_usados_bloque=_input;
}
void Header_Bloque::set_cant_bytes_restantes_bloque(int _input){
    this->cant_bytes_restantes_bloque=_input;
}
void Header_Bloque::set_num_general_records_bloque(int _input){
    this->num_general_records_bloque=_input;
}

//fixed length
void Header_Bloque::set_direc_space_delete_fixed_bloque(int _input){
    this->direc_space_delete_fixed_bloque=_input;
}
void Header_Bloque::set_direc_end_fixed_bloque(int _input){
    this->direc_end_fixed_bloque=_input;
}
void Header_Bloque::set_num_records_fixed_bloque(int _input){
    this->num_records_fixed_bloque=_input;
}

//variable length
void Header_Bloque::set_num_records_variable_bloque(int _input){
    this->num_records_variable_bloque=_input;
}
void Header_Bloque::set_direc_free_space_variable_bloque(int _input){
    this->direc_free_space_variable_bloque=_input;
}

//--------------------Others-------------------

void Header_Bloque::print_info_header_bloque(){
    //general
    cout<<"Mostrando informacion que almacena el Header_Bloque"<<endl;
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