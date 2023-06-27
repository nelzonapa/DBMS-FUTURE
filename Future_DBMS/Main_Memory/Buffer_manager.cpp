#include "Buffer_manager.h"

Buffer_manager::Buffer_manager(){
}
Buffer_manager::~Buffer_manager(){}

void Buffer_manager::show_page(int num_page){
    //debe comprobar si esta vacío el buffer o tiene algun elemento
    if((this->tabla_metadata).get_cant_pages_general()==0){
        cout<<"El buffer pool esta vacio"<<endl;
        cout<<"Solicitando registro al disco..."<<endl;
        
    }
    else{
        cout<<"El buffer pool no esta vacio"<<endl;
    }
}