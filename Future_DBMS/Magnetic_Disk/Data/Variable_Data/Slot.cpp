#include "Slot.h"

Slot::Slot(){
    this->offset=0;
    this->size_length=0;
}

Slot::Slot(int _offset,int _size){
    this->offset=_offset;
    this->size_length=_size;
}

Slot::~Slot(){}

int Slot::get_offset(){
    return this->offset;
}

int Slot::get_length(){
    return this->size_length;
}

void Slot::set_offset(int _offset){
    this->offset=_offset;
}

void Slot::set_length(int _size){
    this->size_length=_size;
}


void Slot::print_data_slot(){
    std::cout<<"Slot:\n Offset: "<<this->offset<<" \nLength: "<<this->size_length<<endl;
}