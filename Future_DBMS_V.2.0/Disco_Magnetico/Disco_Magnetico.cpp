#include "Disco_Magnetico.h"

Disco_Magnetico::Disco_Magnetico()
{
    this->id_disk_magnetic=0;

    this->num_platos=0;
    this->num_superficies=0;
    this->num_pistas=0;
    this->num_sectores=0;
    this->num_bloques=0;

    this->capacidad_sector=0;
}

Disco_Magnetico::~Disco_Magnetico(){}

// set()

void Disco_Magnetico::set_id_disk_magnetic(int _input){
    this->id_disk_magnetic=_input;
}

void Disco_Magnetico::set_num_platos(int _input){
    this->num_platos=_input;
}
void Disco_Magnetico::set_num_superficies(int _input){
    this->num_superficies=_input;
}
void Disco_Magnetico::set_num_pistas(int _input){
    this->num_pistas=_input;
}
void Disco_Magnetico::set_num_sectores(int _input){
    this->num_sectores=_input;
}
void Disco_Magnetico::set_num_bloques(int _input){
    this->num_bloques=_input;
}

void Disco_Magnetico::set_capacidad_sector(int _input){
    this->capacidad_sector=_input;
}

// get()
int Disco_Magnetico::get_id_disk_magnetic(){
    return this->id_disk_magnetic;
}

int Disco_Magnetico::get_num_platos(){
    return this->num_platos;
}
int Disco_Magnetico::get_num_superficies(){
    return this->num_superficies;
}
int Disco_Magnetico::get_num_pistas(){
    return this->num_pistas;
}
int Disco_Magnetico::get_num_sectores(){
    return this->num_sectores;
}
int Disco_Magnetico::get_num_bloques(){
    return this->num_bloques;
}

int Disco_Magnetico::get_capacidad_sector(){
    return this->capacidad_sector;
}

//-----------------Others---------------
void Disco_Magnetico::print_info_disco_magnetico(){
    cout<<"Imprimiendo informacion del Disco Magnetico:"<<endl;

    cout<<"Numero de platos: "<<this->num_platos<<endl;
    cout<<"Numero de superficies: "<<this->num_superficies<<endl;
    cout<<"Numero de pistas: "<<this->num_pistas<<endl;
    cout<<"Numero de sectores: "<<this->num_sectores<<endl;
    cout<<"Numero de bloques: "<<this->num_bloques<<endl;

    cout<<"Capacidad Total del Disco: "<<this->capacidad_sector<<endl;
}