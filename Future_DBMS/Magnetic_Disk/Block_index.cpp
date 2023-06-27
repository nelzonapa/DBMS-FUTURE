#include "Block_index.h"

Block_index::Block_index(){
    this->id_Block=0;
    this->direc_Block=0;
    this->peso_Block=0;
}
Block_index::Block_index(int _idBlock_index, int direcBlock, int _peso_bloque){
    this->id_Block=_idBlock_index;
    this->direc_Block=direcBlock;
    this->peso_Block=_peso_bloque;
}
Block_index::~Block_index(){}

void Block_index::print_data_Block_index()
{
    std::cout<<id_Block<<"\t\t"<<direc_Block<<"\t\t"<<peso_Block<<std::endl;
}