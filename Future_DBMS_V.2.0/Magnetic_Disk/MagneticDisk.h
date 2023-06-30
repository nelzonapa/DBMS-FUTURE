#ifndef MAGNETICDISK_H
#define MAGNETICDISK_H

#include <iostream>
using namespace std;

class MagneticDisk
{
protected:
    int id_disk_magnetic;
    int num_platos;
    int num_sectores;
    int num_pistas;
    int capacidad_total_magneticDisk;
    int capacidad_usada;

public:
    MagneticDisk();
    MagneticDisk(int _num_platos,int _capacidad, int _num_sectors,int _num_pistas);
    ~MagneticDisk();
};

#endif