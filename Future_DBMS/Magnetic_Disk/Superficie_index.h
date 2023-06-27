#ifndef SUPERFICIE_INDEX_H
#define SUPERFICIE_INDEX_H

class Superficie_index
{
protected:
    int id_superficie;
    int direc_superficie;
    int capacidad_superficie;
public:
    Superficie_index(int _id_superficie, int _direc_superficie, int _capacidad_superficie);
    Superficie_index();
    ~Superficie_index();
    void print_data_sup_index();
    friend class R_W_Head;
};


#endif