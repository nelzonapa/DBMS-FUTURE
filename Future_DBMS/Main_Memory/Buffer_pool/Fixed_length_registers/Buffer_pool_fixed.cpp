#include "Buffer_pool_fixed.h"

Buffer_pool_fixed::Buffer_pool_fixed(){
    std::cout<<"Ingrese la cantidad de paginas que desea en el Buf_pool: "<<endl;
    std::cin>>this->limit_num_pages;
    this->count_pages=0;
}

Buffer_pool_fixed::~Buffer_pool_fixed(){}