#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include "Buffer_pool/Fixed_length_registers/Buffer_pool_fixed.h"
#include "Buffer_pool/Fixed_length_registers/Buffer_pool_fixed.cpp"

#include "Buffer_pool/Table_metadata/Page_table.h"
#include "Buffer_pool/Table_metadata/Page_table.cpp"

using namespace std;

class Buffer_manager
{
private:
    Buffer_pool_fixed Buf_Pool_Fix;//todo buffer manager controla un buffer pool
    Page_Table tabla_metadata;//tabla metadatos
public:
    Buffer_manager();
    ~Buffer_manager();

    void show_page(int num);
};

#endif