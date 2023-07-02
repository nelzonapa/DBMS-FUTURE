#ifndef BRAZODISCO_H
#define BRAZODISCO_H

#include "MagneticDisk.h"
#include "MagneticDisk.cpp"

#include "Plato.h"
#include "Plato.cpp"

#include "Superficie.h"
#include "Superficie.cpp"

#include "Pista.h"
#include "Pista.cpp"

#include "Sector.h"
#include "Sector.cpp"

#include "Bloque.h"
#include "Bloque.cpp"

#include "Data/Header_Bloque.h"
#include "Data/Header_Bloque.cpp"

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
    void crear_platos(MagneticDisk &disco_magnetic);
    void crear_superficies(MagneticDisk &disco_magnetic);
    void crear_pistas(MagneticDisk &disco_magnetic);
    void crear_sectores(MagneticDisk &disco_magnetic);
    void crear_bloques(MagneticDisk &disco_magnetic);
   

    //-------------------------WRITE_INFO--------------------------
    void write_disco_info(MagneticDisk &disco_magnetic);
    void write_platos_info();
    void write_superficies_info();
    void write_pistas_info();
    void write_sectores_info();
    void write_bloques_info();

    //-------------------------READ_INFO--------------------------
    void read_disco_info();
    void read_plato_info(int _num_plato);
    void read_superficie_info(int _num_superficie);
    void read_pista_info(int _num_pista);
    void read_sector_info(int _num_sector);
    void read_bloque_info(int _num_bloque);

    //-------------------------Read Otros-------------------------
    void read_header_bloque(int _num_bloque);

};

#endif