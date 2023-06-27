#ifndef SLOT_H
#define SLOT_H

class Slot
{
private:
    int offset;     //direc_memoria
    int size_length;    //la longitud o tamaño del registro
public:
    Slot();
    Slot(int _offset,int _size);
    ~Slot();

    int get_offset();
    int get_length();
    void set_offset(int _offset);
    void set_length(int _size);

    void print_data_slot();
};

#endif