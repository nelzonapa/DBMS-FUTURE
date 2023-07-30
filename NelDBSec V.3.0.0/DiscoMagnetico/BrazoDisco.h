#ifndef BRAZODISCO_H
#define BRAZODISCO_H

// #include "DiscoMagnetico.h"
// #include "DiscoMagnetico.cpp"

// #include "../DiskManager/SistemaOperativo.h"
// #include "../DiskManager/SistemaOperativo.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>
#include <windows.h>

typedef unordered_map<string, pair<string,int>> MapaPares;

class BrazoDisco
{
public:
    BrazoDisco();
    ~BrazoDisco();
    /*
    -------------------- COMPROBAMOS EXISTENCIA DEL DISCO ----------------
    */
    string conseguir_disco(const string &disco_name);
    bool comprobar_existencia_file(const string& filePath);
    bool Crear_leer_file_discos(const string& filePath, const string& word_buscar);

    //-------------------------cCREATE--------------------------
    void crear_disco(DiscoMagnetico &disco_magnetic); 
    void crear_platos(DiscoMagnetico &disco_magnetic,const string &route_disco);
    void crear_superficies(DiscoMagnetico &disco_magnetic, const string &final_route_plato);
    void crear_pistas(DiscoMagnetico &disco_magnetic, const string &final_route_plato);
    void crear_sectores(DiscoMagnetico &disco_magnetic, const string &final_route_plato);

    /*escribir data*/
    

};

#endif