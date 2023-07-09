#ifndef BRAZODISCO_H
#define BRAZODISCO_H

// #include "Disco_Magnetico.h"
// #include "Disco_Magnetico.cpp"

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
    bool comprobar_existencia_file(const string& filePath);
    bool Crear_leer_file_discos(const string& filePath, const string& word_buscar);

    //-------------------------cCREATE--------------------------
    void crear_disco(Disco_Magnetico &disco_magnetic); 
    void crear_platos(Disco_Magnetico &disco_magnetic,const string &route_disco);
    void crear_superficies(Disco_Magnetico &disco_magnetic, const string &final_route_plato);
    void crear_pistas(Disco_Magnetico &disco_magnetic, const string &final_route_plato);
    void crear_sectores(Disco_Magnetico &disco_magnetic, const string &final_route_plato);
};

#endif