#ifndef BRAZODISCO_H
#define BRAZODISCO_H

#include "MagneticDisk.h"
#include "MagneticDisk.cpp"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//include varios

class BrazoDisco
{
public:
    BrazoDisco();
    ~BrazoDisco();

    //-------------------------cCREATE--------------------------
    void crear_disco(MagneticDisk &disco_magnetic); 
    void crear_platos(int _num_platos);
    void crear_superficies(int _num_superficies);
    void crear_pistas(int _num_pistas);
    void crear_sectores(int _num_sectores);
    void crear_bloques(int _num_bloques);
   

    //-------------------------WRITE_INFO--------------------------
    void write_disco_info(MagneticDisk &disco_magnetic);
    void write_platos_info();
    void write_superficies_info();
    void write_pistas_info();
    void write_sectores_info();
    void write_bloques_info();

    //-------------------------READ_INFO--------------------------
    void read_disco_info();
    void read_platos_info();
    void read_superficies_info();
    void read_pistas_info();
    void read_sectores_info();
    void read_bloques_info();

};

#endif