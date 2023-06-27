#include "Sector_index.h"

#include <iostream>

using namespace std;

Sector_index::Sector_index(){//constructor 1
    this->id_sector_index=0;
    this->direc_sector_index=0;
    this->peso_sector=0;
}
Sector_index::Sector_index(int _id,int _direc, int _peso_sector){//constructor 2
    this->id_sector_index=_id;
    this->direc_sector_index=_direc;
    this->peso_sector=_peso_sector;
}
Sector_index::~Sector_index(){}

void Sector_index::print_data_sector_index()
{
    cout<<id_sector_index<<"\t\t"<<direc_sector_index<<"\t\t"<<peso_sector<<endl;
}