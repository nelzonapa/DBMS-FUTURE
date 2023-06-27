#ifndef PAGE_T_H
#define PAGE_T_H

class Page_T
{
private:
    //inside the page, the block
    int direc_pagina;
    bool dirty_flag;
    int pin_count;  
    Pagina *ptr_pag;
    
public:
    Page_T();
    Page_T(int _direc_pagina,bool _dirty_flag,int _pin_count,Pagina *_ptr_pag);
    ~Page_T();

    //GET
    int get_direc_pagina();
    bool get_dirty_flag();
    int get_pin_count();  
    Pagina* get_ptr_pag();

    //SET
    void set_direc_pagina(int _direc_pagina);
    void set_dirty_flag(bool _dirty_flag);
    void set_pin_count(int _pin_count);  
    void set_ptr_pag(Pagina *_ptr_pag);

};

#endif