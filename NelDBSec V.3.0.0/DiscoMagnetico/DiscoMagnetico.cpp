#include "DiscoMagnetico.h"

DiscoMagnetico::DiscoMagnetico()
{
    this->id_disk_magnetic=0;

    this->num_platos=0;
    this->num_superficies_por_plato=0;
    this->num_pistas_por_superficie=0;
    this->num_sectores_por_pista=0;
    this->num_sectores_en_bloque=0;

    this->capacidad_sector=0;
}

DiscoMagnetico::~DiscoMagnetico(){}

// set()

void DiscoMagnetico::set_id_disk_magnetic(int _input){
    this->id_disk_magnetic=_input;
}

void DiscoMagnetico::set_num_platos(int _input){
    this->num_platos=_input;
}
void DiscoMagnetico::set_num_superficies_por_plato(int _input){
    this->num_superficies_por_plato=_input;
}
void DiscoMagnetico::set_num_pistas_por_superficie(int _input){
    this->num_pistas_por_superficie=_input;
}
void DiscoMagnetico::set_num_sectores_por_pista(int _input){
    this->num_sectores_por_pista=_input;
}
void DiscoMagnetico::set_num_sectores_en_bloque(int _input){
    this->num_sectores_en_bloque=_input;
}

void DiscoMagnetico::set_capacidad_sector(int _input){
    this->capacidad_sector=_input;
}

// get()
int DiscoMagnetico::get_id_disk_magnetic(){
    return this->id_disk_magnetic;
}

int DiscoMagnetico::get_num_platos(){
    return this->num_platos;
}
int DiscoMagnetico::get_num_superficies_por_plato(){
    return this->num_superficies_por_plato;
}
int DiscoMagnetico::get_num_pistas_por_superficie(){
    return this->num_pistas_por_superficie;
}
int DiscoMagnetico::get_num_sectores_por_pista(){
    return this->num_sectores_por_pista;
}
int DiscoMagnetico::get_num_sectores_en_bloque(){
    return this->num_sectores_en_bloque;
}

int DiscoMagnetico::get_capacidad_sector(){
    return this->capacidad_sector;
}

//-----------------Others---------------
void DiscoMagnetico::print_info_disco_magnetico(){
    cout<<"Imprimiendo informacion del Disco Magnetico:"<<endl;
    cout<<"Id del disco: "<<this->id_disk_magnetic<<endl;
    cout<<"Numero de platos: "<<this->num_platos<<endl;
    cout<<"Numero de superficies por plato: "<<this->num_superficies_por_plato<<endl;
    cout<<"Numero de pistas por superficie: "<<this->num_pistas_por_superficie<<endl;
    cout<<"Numero de sectores por pista: "<<this->num_sectores_por_pista<<endl;
    cout<<"Numero de sectores en un bloque: "<<this->num_sectores_en_bloque<<endl;
    cout<<"Capacidad de un sector: "<<this->capacidad_sector<<endl;
}