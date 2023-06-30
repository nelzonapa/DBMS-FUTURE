#ifndef SECTOR_H
#define SECTOR_H


class Sector
{
protected:
    int id_sector;
    int direc_sector;
    int peso_sector;

public:
    Sector();
    Sector(int _id_Sector,int _direc_Sector, int _peso_sector);
    ~Sector();
    void print_data_Sector();
    friend class R_W_Head;
};

#endif