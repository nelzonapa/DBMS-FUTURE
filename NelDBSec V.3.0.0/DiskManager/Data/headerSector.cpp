#include "headerSector.h"

headerSector::headerSector(){
    //general
    this->pesoBytesSector=0;
    this->cantBytesUsadosSector=0;
    this->cantBytesRestantesBloque=0;
    this->numGeneralRecordsBloque=0;
    
    //fixed length
    this->direcDeleteSpacesFixedData=0;
    this->direcEndFixedData=0;
    this->numRecordsFixedSector=0;
    this->direcFirstFixedRecord=0;

    //variable length
    this->direcDeleteSpacesVariableData=0;
    this->numRecordsVariableSector=0;
    this->direcFreeSpaceVariableSector=0;
    this->direcFirstVariableRecord=0;

    //B+Tree
    this->numberBPlusTrees=0;
    this->directFirstBPlusTree=0;
    this->directEndBPlusTrees=0;
}

headerSector::~headerSector(){}

//--------------------GET-------------------
//general
// Métodos de acceso (getters)
int headerSector::getPesoBytesSector()
{
    return pesoBytesSector;
}

int headerSector::getCantBytesUsadosSector()
{
    return cantBytesUsadosSector;
}

int headerSector::getCantBytesRestantesBloque()
{
    return cantBytesRestantesBloque;
}

int headerSector::getNumGeneralRecordsBloque()
{
    return numGeneralRecordsBloque;
}

int headerSector::getDirecDeleteSpacesFixedData()
{
    return direcDeleteSpacesFixedData;
}

int headerSector::getDirecEndFixedData()
{
    return direcEndFixedData;
}

int headerSector::getNumRecordsFixedSector()
{
    return numRecordsFixedSector;
}

int headerSector::getDirecFirstFixedRecord()
{
    return direcFirstFixedRecord;
}

int headerSector::getDirecDeleteSpacesVariableData()
{
    return direcDeleteSpacesVariableData;
}

int headerSector::getNumRecordsVariableSector()
{
    return numRecordsVariableSector;
}

int headerSector::getDirecFreeSpaceVariableSector()
{
    return direcFreeSpaceVariableSector;
}

int headerSector::getDirecFirstVariableRecord()
{
    return direcFirstVariableRecord;
}

int headerSector::getNumberBPlusTrees()
{
    return numberBPlusTrees;
}

int headerSector::getDirectFirstBPlusTree()
{
    return directFirstBPlusTree;
}

int headerSector::getDirectEndBPlusTrees()
{
    return directEndBPlusTrees;
}

// Métodos de modificación (setters)
void headerSector::setPesoBytesSector(int peso)
{
    pesoBytesSector = peso;
}

void headerSector::setCantBytesUsadosSector(int cant)
{
    cantBytesUsadosSector = cant;
}

void headerSector::setCantBytesRestantesBloque(int cant)
{
    cantBytesRestantesBloque = cant;
}

void headerSector::setNumGeneralRecordsBloque(int num)
{
    numGeneralRecordsBloque = num;
}

void headerSector::setDirecDeleteSpacesFixedData(int direc)
{
    direcDeleteSpacesFixedData = direc;
}

void headerSector::setDirecEndFixedData(int direc)
{
    direcEndFixedData = direc;
}

void headerSector::setNumRecordsFixedSector(int num)
{
    numRecordsFixedSector = num;
}

void headerSector::setDirecFirstFixedRecord(int direc)
{
    direcFirstFixedRecord = direc;
}

void headerSector::setDirecDeleteSpacesVariableData(int direc)
{
    direcDeleteSpacesVariableData = direc;
}

void headerSector::setNumRecordsVariableSector(int num)
{
    numRecordsVariableSector = num;
}

void headerSector::setDirecFreeSpaceVariableSector(int direc)
{
    direcFreeSpaceVariableSector = direc;
}

void headerSector::setDirecFirstVariableRecord(int direc)
{
    direcFirstVariableRecord = direc;
}

void headerSector::setNumberBPlusTrees(int num)
{
    numberBPlusTrees = num;
}

void headerSector::setDirectFirstBPlusTree(int direc)
{
    directFirstBPlusTree = direc;
}

void headerSector::setDirectEndBPlusTrees(int direc)
{
    directEndBPlusTrees = direc;
}

//--------------------Others-------------------

void headerSector::printInfoSectorHeader(){
    std::cout << "General info del sector: "<<endl;
    std::cout << "Peso Bytes Sector: " << pesoBytesSector << ""<<endl;
    std::cout << "Cant Bytes Usados Sector: " << cantBytesUsadosSector << ""<<endl;
    std::cout << "Cant Bytes Restantes Bloque: " << cantBytesRestantesBloque << ""<<endl;
    std::cout << "Num General Records Bloque: " << numGeneralRecordsBloque << ""<<endl;

    std::cout << "Fixed length info: "<<endl;
    std::cout << "Direc Delete Spaces Fixed Data: " << direcDeleteSpacesFixedData << ""<<endl;
    std::cout << "Direc End Fixed Data: " << direcEndFixedData << ""<<endl;
    std::cout << "Num Records Fixed Sector: " << numRecordsFixedSector << ""<<endl;
    std::cout << "Direc First Fixed Record: " << direcFirstFixedRecord << ""<<endl;

    std::cout << "Variable length info: "<<endl;
    std::cout << "Direc Delete Spaces Variable Data: " << direcDeleteSpacesVariableData << ""<<endl;
    std::cout << "Num Records Variable Sector: " << numRecordsVariableSector << ""<<endl;
    std::cout << "Direc Free Space Variable Sector: " << direcFreeSpaceVariableSector << ""<<endl;
    std::cout << "Direc First Variable Record: " << direcFirstVariableRecord << ""<<endl;

    std::cout << "Data B+Tree: "<<endl;
    std::cout << "Number B+ Trees: " << numberBPlusTrees << ""<<endl;
    std::cout << "Direct First B+ Tree: " << directFirstBPlusTree << ""<<endl;
    std::cout << "Direct End B+ Trees: " << directEndBPlusTrees << ""<<endl;
}   