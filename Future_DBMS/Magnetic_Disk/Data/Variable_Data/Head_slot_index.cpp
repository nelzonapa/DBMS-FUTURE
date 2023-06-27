#include "Head_slot_index.h"

Head_slot_index::Head_slot_index()
{
    this->num_slots_index=0;
    this->direc_final_index=0;  
    this->direc_vacio_delete=0;
}

Head_slot_index::Head_slot_index(int _num_slots_index, int _direc_final_index, int _direc_vacio_delete)
{
    this->num_slots_index=_num_slots_index;
    this->direc_final_index=_direc_final_index;
    this->direc_vacio_delete=_direc_vacio_delete;
}

Head_slot_index::~Head_slot_index(){}


//SET
void Head_slot_index::set_num_slots_index(int _num_slots_index){
    this->num_slots_index=_num_slots_index;
}
void Head_slot_index::set_direc_final_index(int _direc_final_index){
    this->direc_final_index=_direc_final_index;
}
void Head_slot_index::set_direc_vacio_delete(int _direc_vacio_delete){
    this->direc_vacio_delete=_direc_vacio_delete;
}

//GET
int Head_slot_index::get_num_slots_index(){
    return this->num_slots_index;
}
int Head_slot_index::get_direc_final_index(){
    return this->direc_final_index;
}
int Head_slot_index::get_direc_vacio_delete(){
    return this->direc_vacio_delete;
}

void Head_slot_index::print_info_Head_slots_index(){
    std::cout<<"numero de slots: "<<this->num_slots_index<<"\nDireccion final slots: "<<this->direc_final_index<<"\nDireccion space vacio: "<<this->direc_vacio_delete<<endl;
}
