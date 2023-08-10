#ifndef HEADERSECTOR_H
#define HEADERSECTOR_H

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

class headerSector
{
private:
    //general info del sector
    int pesoBytesSector;
    int cantBytesUsadosSector;
    int cantBytesRestantesBloque;
    int numGeneralRecordsBloque;
    
    //fixed length info
    int direcDeleteSpacesFixedData;
    int direcEndFixedData;
    int numRecordsFixedSector;
    int direcFirstFixedRecord;

    //variable length info
    int direcDeleteSpacesVariableData;
    int numRecordsVariableSector;
    int direcFreeSpaceVariableSector; //apunta a donde inicias las tuplas de variable length
    int direcFirstVariableRecord;

    //Data B+Tree
    int numberBPlusTrees;
    int directFirstBPlusTree;
    int directEndBPlusTrees;

    //Metadata
    int metadataSector;
    
public:
    headerSector(/* args */);
    ~headerSector();

    //--------------------GET-------------------
    
    int getPesoBytesSector();
    int getCantBytesUsadosSector();
    int getCantBytesRestantesSector();
    int getNumGeneralRecordsSector();

    int getDirecDeleteSpacesFixedData();
    int getDirecEndFixedData();
    int getNumRecordsFixedSector();
    int getDirecFirstFixedRecord();
    
    int getDirecDeleteSpacesVariableData();
    int getNumRecordsVariableSector();
    int getDirecFreeSpaceVariableSector();
    int getDirecFirstVariableRecord();
    
    int getNumberBPlusTrees();
    int getDirectFirstBPlusTree();
    int getDirectEndBPlusTrees();

    int getMetadataSector();
    
    //--------------------SET-------------------

    void setPesoBytesSector(int peso);
    void setCantBytesUsadosSector(int cant);
    void setCantBytesRestantesSector(int cant);
    void setNumGeneralRecordsSector(int num);
    
    void setDirecDeleteSpacesFixedData(int direc);
    void setDirecEndFixedData(int direc);
    void setNumRecordsFixedSector(int num);
    void setDirecFirstFixedRecord(int direc);
    
    void setDirecDeleteSpacesVariableData(int direc);
    void setNumRecordsVariableSector(int num);
    void setDirecFreeSpaceVariableSector(int direc);
    void setDirecFirstVariableRecord(int direc);
    
    void setNumberBPlusTrees(int num);
    void setDirectFirstBPlusTree(int direc);
    void setDirectEndBPlusTrees(int direc);

    void setMetadataSector(int metadata);


    //--------------------Others-------------------
    friend std::istream &operator>>(std::istream &is, headerSector &header);
    friend std::ostream &operator<<(std::ostream &os, const headerSector &header);
    void printInfoSectorHeader();
};

#endif