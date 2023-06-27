#ifndef SECTOR_INDEX_H
#define SECTOR_INDEX_H


class Sector_index
{
protected:
    int id_sector_index;
    int direc_sector_index;
    int peso_sector;

public:
    Sector_index();
    Sector_index(int _id_sector_index,int _direc_sector_index, int _peso_sector);
    ~Sector_index();
    void print_data_sector_index();
    friend class R_W_Head;
};

#endif