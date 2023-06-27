#ifndef BLOCK_INDEX_H
#define BLOCK_INDEX_H

#include <iostream>

using namespace std;

class Block_index
{
protected:
    int id_Block;
    int direc_Block;
    int peso_Block;

public:
    Block_index();
    Block_index(int _id_Block,int _direcBlock, int peso_Block);
    ~Block_index();
    void print_data_Block_index();
    friend class R_W_Head;
};

#endif