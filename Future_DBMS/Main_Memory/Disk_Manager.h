#ifndef DISK_MANAGER_H
#define DISK_MANAGER_H

#include "../Magnetic_Disk/Sistema_Operativo.h"
#include "../Magnetic_Disk/Sistema_Operativo.cpp"

class Disk_Manager
{
private:
    Sistema_operativo Sis_Operativo;
public:
    Disk_Manager(/* args */);
    ~Disk_Manager();
};


#endif