#ifndef SLOT_H
#define SLOT_H

#include <iostream>
using namespace std;

class Slot
{
private:
    int offset;     //direc_memoria
    int size_length;    //la longitud o tamaño del registro
    int direc_sig_slot;     //dirección del siguiente slot
public:
    Slot();
    Slot(int _offset,int _size_length,int _direc_sig_slot);
    ~Slot();

    //---------- GET --------------
    int get_offset();
    int get_size_length();
    int get_direc_sig_slot();

    //---------- SET --------------
    void set_offset(int _offset);
    void set_size_length(int _size_length);
    void set_direc_sig_slot(int _direc_sig_slot);

    //------------- OTHERS --------------
    void print_data_slot();
};

#endif