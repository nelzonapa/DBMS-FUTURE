#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include "Page_T.h"
#include "Page_T.cpp"

#include <list>

using namespace std;

class Page_Table
{
private:
    //info of the buffer_pool:
    int cant_pages_general;
    int cant_pages_pinned;
    int cant_pages_unpinned;
    Page_T *ptr_unpinned;

    //list of special pages of the TABLE
    list<Page_T> page_table_index;
public:
    Page_Table();
    ~Page_Table();

    //GET
    int get_cant_pages_general();
    int get_cant_pages_pinned();
    int get_cant_pages_unpinned();
    Page_T& get_ptr_unpinned();

    //SET
    void set_cant_pages_general(int _input);
    void set_cant_pages_pinned(int _input);
    void set_cant_pages_unpinned(int _input);
    void set_ptr_unpinned(Page_T &ptr_unpinned);
};



#endif