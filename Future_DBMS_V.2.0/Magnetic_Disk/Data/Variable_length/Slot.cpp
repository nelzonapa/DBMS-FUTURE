#include "Slot.h"

Slot::Slot(){
    this->offset=0;
    this->size_length=0;
    this->direc_sig_slot=0;
}

Slot::Slot(int _offset,int _size_length, int _direc_sig_slot){
    this->offset=_offset;
    this->size_length=_size_length;
    this->direc_sig_slot=_direc_sig_slot;
}

Slot::~Slot(){}

//-------------- GET ---------------
int Slot::get_offset(){
    return this->offset;
}

int Slot::get_size_length(){
    return this->size_length;
}

int Slot::get_direc_sig_slot(){
    return this->direc_sig_slot;
}

//---------- SET --------------

void Slot::set_offset(int _offset){
    this->offset=_offset;
}

void Slot::set_size_length(int _size){
    this->size_length=_size;
}

void Slot::get_direc_sig_slot(int _direc_sig_slot){
    this->direc_sig_slot=_direc_sig_slot;
}

//------------- OTHERS --------------
void Slot::print_data_slot(){
    cout<<"Slot:\n Offset: "<<this->offset<<" \nLength: "<<this->size_length<<endl;
}