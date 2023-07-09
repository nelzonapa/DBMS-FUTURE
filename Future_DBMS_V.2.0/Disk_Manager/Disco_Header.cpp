#include "Disco_Header.h"

Disco_Header::Disco_Header()
{
    this->id_disk_magnetic=0;

    this->num_platos=0;
    this->num_superficies=0;
    this->num_pistas=0;
    this->num_sectores=0;
    this->num_bloques=0;

    this->capacidad_total_magneticDisk=0;
    this->capacidad_usada_magneticDisk=0;
    this->capacidad_restante_magneticDisk=0;
}

Disco_Header::~Disco_Header(){}

// set()
void Disco_Header::set_route_disk_magnetic(const char* route){
    this->route_disk_magnetic=route;
}

void Disco_Header::set_id_disk_magnetic(int _input){
    this->id_disk_magnetic=_input;
}

void Disco_Header::set_num_platos(int _input){
    this->num_platos=_input;
}
void Disco_Header::set_num_superficies(int _input){
    this->num_superficies=_input;
}
void Disco_Header::set_num_pistas(int _input){
    this->num_pistas=_input;
}
void Disco_Header::set_num_sectores(int _input){
    this->num_sectores=_input;
}
void Disco_Header::set_num_bloques(int _input){
    this->num_bloques=_input;
}

void Disco_Header::set_capacidad_total_magneticDisk(int _input){
    this->capacidad_total_magneticDisk=_input;
}
void Disco_Header::set_capacidad_usada_magneticDisk(int _input){
    this->capacidad_usada_magneticDisk=_input;
}
void Disco_Header::set_capacidad_restante_magneticDisk(int _input){
    this->capacidad_restante_magneticDisk=_input;
}

// get()
const char* Disco_Header::get_route_disk_magnetic(){
    return this->route_disk_magnetic;
}

int Disco_Header::get_id_disk_magnetic(){
    return this->id_disk_magnetic;
}

int Disco_Header::get_num_platos(){
    return this->num_platos;
}
int Disco_Header::get_num_superficies(){
    return this->num_superficies;
}
int Disco_Header::get_num_pistas(){
    return this->num_pistas;
}
int Disco_Header::get_num_sectores(){
    return this->num_sectores;
}
int Disco_Header::get_num_bloques(){
    return this->num_bloques;
}

int Disco_Header::get_capacidad_total_magneticDisk(){
    return this->capacidad_total_magneticDisk;
}
int Disco_Header::get_capacidad_usada_magneticDisk(){
    return this->capacidad_usada_magneticDisk;
}
int Disco_Header::get_capacidad_restante_magneticDisk(){
    return this->capacidad_restante_magneticDisk;
}

//-----------------Others---------------
void Disco_Header::print_info_magnetic_disk(){
    cout<<"Imprimiendo informacion del Disco Magnetico:"<<endl;
    cout<<"Direccion/ruta: "<<this->route_disk_magnetic<<endl;
    // cout<<"id disco"<<this->id_disk_magnetic<<endl;

    cout<<"Numero de platos: "<<this->num_platos<<endl;
    cout<<"Numero de superficies: "<<this->num_superficies<<endl;
    cout<<"Numero de pistas: "<<this->num_pistas<<endl;
    cout<<"Numero de sectores: "<<this->num_sectores<<endl;
    cout<<"Numero de bloques: "<<this->num_bloques<<endl;

    cout<<"Capacidad Total del Disco: "<<this->capacidad_total_magneticDisk<<endl;
    cout<<"Capacidad Usada del Disco: "<<this->capacidad_usada_magneticDisk<<endl;
    cout<<"Capacidad Restante del Disco: "<<this->capacidad_restante_magneticDisk<<endl;
}