#ifndef PLATO_INDEX_H
#define PLATO_INDEX_H

class Plato_index
{
protected:
    int id_plato;
    int direc_plato;
    int capacidad_plato;
public:
    Plato_index();
    Plato_index(int _id_plato, int _direc_plato, int _capacidad_plato);
    ~Plato_index();
    void print_data_plato_index();
    friend class R_W_Head;
};


#endif