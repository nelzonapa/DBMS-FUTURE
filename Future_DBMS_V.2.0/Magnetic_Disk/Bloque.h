#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

using namespace std;

class Block
{
protected:
    int id_Block;
    int direc_Block;
    int peso_Block;

public:
    Block();
    Block(int _id_Block,int _direcBlock, int peso_Block);
    ~Block();
    void print_data_Block();
};

#endif