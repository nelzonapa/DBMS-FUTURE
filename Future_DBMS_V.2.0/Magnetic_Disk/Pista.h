#ifndef PISTA_H
#define PISTA_H

class Pista
{
protected:
    int id_pista;
    int direc_pista;
    int capacidad_pista;
public:
    Pista(int _id_pista, int _direc_pista, int _capacidad_pista);
    Pista();
    ~Pista();
};


#endif