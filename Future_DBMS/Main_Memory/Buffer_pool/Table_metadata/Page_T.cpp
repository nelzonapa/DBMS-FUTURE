#include "Page_T.h"

Page_T::Page_T(){
    this->direc_pagina=0;
    this->dirty_flag=false;
    this->pin_count=0;
    this->ptr_pag=nullptr;
}

Page_T::Page_T(int _direc_pagina,bool _dirty_flag,int _pin_count,Pagina *_ptr_pag){
    this->direc_pagina=_direc_pagina;
    this->dirty_flag=_dirty_flag;
    this->pin_count=_pin_count;
    this->ptr_pag=_ptr_pag;
}

Page_T::~Page_T(){}

//GET
int Page_T::get_direc_pagina(){
    this->direc_pagina;
}
bool Page_T::get_dirty_flag(){
    this->dirty_flag;
}
int Page_T::get_pin_count(){
    this->pin_count;
}  
Pagina* Page_T::get_ptr_pag(){
    this->ptr_pag;
}

//SET
void Page_T::set_direc_pagina(int _direc_pagina){
    this->direc_pagina=_direc_pagina;
}
void Page_T::set_dirty_flag(bool _dirty_flag){
    this->dirty_flag=_dirty_flag;
}
void Page_T::set_pin_count(int _pin_count){
    this->pin_count=_pin_count;
}  
void Page_T::set_ptr_pag(Pagina *_ptr_pag){
    this->ptr_pag=_ptr_pag;
}