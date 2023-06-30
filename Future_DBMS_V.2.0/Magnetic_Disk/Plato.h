#ifndef PLATO_H
#define PLATO_H

class Plato
{
protected:
    int id_plato;
    int route_plato;
    int capacidad_plato;
public:
    Plato();
    Plato(int _id_plato, int _route_plato, int _capacidad_plato);
    ~Plato();
    void print_data_Plato();
    friend class R_W_Head;
};


#endif