#include "Disco_Header.h"

Disco_Header::Disco_Header()
{
    this->route_disk_magnetic="none";
    this->id_disk_magnetic=0;

    this->num_platos_total=0;
    this->num_superficies_total=0;
    this->num_pistas_total=0;
    this->num_sectores_total=0;
    this->num_bloques_total=0;

    this->capacidad_total_magneticDisk=0;
    this->capacidad_usada_magneticDisk=0;
    this->capacidad_restante_magneticDisk=0;
}

Disco_Header::~Disco_Header(){}

// set()
void Disco_Header::set_route_disk_magnetic(string route){
    this->route_disk_magnetic=route;
}

void Disco_Header::set_id_disk_magnetic(int _input){
    this->id_disk_magnetic=_input;
}

void Disco_Header::set_num_platos_total(int _input){
    this->num_platos_total=_input;
}
void Disco_Header::set_num_superficies_total(int _input){
    this->num_superficies_total=_input;
}
void Disco_Header::set_num_pistas_total(int _input){
    this->num_pistas_total=_input;
}
void Disco_Header::set_num_sectores_total(int _input){
    this->num_sectores_total=_input;
}
void Disco_Header::set_num_bloques_total(int _input){
    this->num_bloques_total=_input;
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
string Disco_Header::get_route_disk_magnetic(){
    return this->route_disk_magnetic;
}

int Disco_Header::get_id_disk_magnetic(){
    return this->id_disk_magnetic;
}

int Disco_Header::get_num_platos_total(){
    return this->num_platos_total;
}
int Disco_Header::get_num_superficies_total(){
    return this->num_superficies_total;
}
int Disco_Header::get_num_pistas_total(){
    return this->num_pistas_total;
}
int Disco_Header::get_num_sectores_total(){
    return this->num_sectores_total;
}
int Disco_Header::get_num_bloques_total(){
    return this->num_bloques_total;
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

void Disco_Header::print_2_info(){
    std::cout<<"Imprimiendo informacion del Disco Magnetico:"<<endl;
    std::cout<<"Direccion/ruta: "<<this->route_disk_magnetic<<endl;
    std::cout<<"id disco: "<<this->id_disk_magnetic<<endl;
}

//-----------------Others---------------
void Disco_Header::print_info_magnetic_disk(){
    print_2_info();

    cout<<"Numero de platos: "<<this->num_platos_total<<endl;
    cout<<"Numero de superficies: "<<this->num_superficies_total<<endl;
    cout<<"Numero de pistas: "<<this->num_pistas_total<<endl;
    cout<<"Numero de sectores: "<<this->num_sectores_total<<endl;
    cout<<"Numero de bloques: "<<this->num_bloques_total<<endl;

    cout<<"Capacidad Total del Disco: "<<this->capacidad_total_magneticDisk<<endl;
    cout<<"Capacidad Usada del Disco: "<<this->capacidad_usada_magneticDisk<<endl;
    cout<<"Capacidad Restante del Disco: "<<this->capacidad_restante_magneticDisk<<endl;
    return;
}

std::ostream& operator<<(std::ostream& os, Disco_Header& disco_header) {
    os << disco_header.get_route_disk_magnetic();
    os << "-" << disco_header.get_id_disk_magnetic();
    os << "-" << disco_header.get_num_platos_total();
    os << "-" << disco_header.get_num_superficies_total();
    os << "-" << disco_header.get_num_pistas_total();
    os << "-" << disco_header.get_num_sectores_total();
    os << "-" << disco_header.get_num_bloques_total();

    os << "-" << disco_header.get_capacidad_total_magneticDisk();
    os << "-" << disco_header.get_capacidad_usada_magneticDisk();
    os << "-" << disco_header.get_capacidad_restante_magneticDisk();
    return os;
}


std::istream& operator>>(std::istream& is, Disco_Header& disco_header) {
    is>>disco_header.route_disk_magnetic;
    is>>disco_header.id_disk_magnetic;
    is>>disco_header.num_platos_total;
    is>>disco_header.num_superficies_total;
    is>>disco_header.num_pistas_total;
    is>>disco_header.num_sectores_total;
    is>>disco_header.num_bloques_total;

    is>>disco_header.capacidad_total_magneticDisk;
    is>>disco_header.capacidad_usada_magneticDisk;
    is>>disco_header.capacidad_restante_magneticDisk;
    return is;
}