#include "Page_table.h"

Page_Table::Page_Table(){
    this->cant_pages_general=0;
    this->cant_pages_pinned=0;
    this->cant_pages_unpinned=0;
    this->ptr_unpinned=0;
    //el list se queda como esta
}

Page_Table::~Page_Table(){}

//GET
int Page_Table::get_cant_pages_general(){
    return this->cant_pages_general;
}
int Page_Table::get_cant_pages_pinned(){
    return this->cant_pages_pinned;
}
int Page_Table::get_cant_pages_unpinned(){
    return this->cant_pages_unpinned;
}
Page_T& Page_Table::get_ptr_unpinned(){
    return (*this->ptr_unpinned);
}

//SET
void Page_Table::set_cant_pages_general(int _input){
    this->cant_pages_general=_input;
}
void Page_Table::set_cant_pages_pinned(int _input){
    this->cant_pages_pinned=_input;
}
void Page_Table::set_cant_pages_unpinned(int _input){
    this->cant_pages_unpinned=_input;
}
void Page_Table::set_ptr_unpinned(Page_T &ptr_unpinned){
    (*this->ptr_unpinned)=ptr_unpinned;
}