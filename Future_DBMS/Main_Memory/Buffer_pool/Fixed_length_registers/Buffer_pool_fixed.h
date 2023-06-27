#ifndef BUFFER_POOL_FIXED_H
#define BUFFER_POOL_FIXED_H

#include "../Pagina.h"
#include "../Pagina.cpp"

using namespace std;
class Buffer_pool_fixed
{
private:
    int limit_num_pages;
    int count_pages;
    std::list<Pagina> frames_pages_list;
public:
    Buffer_pool_fixed();
    ~Buffer_pool_fixed();
};

#endif