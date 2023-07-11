#ifndef DISCO_INDEX_H
#define DISCO_INDEX_H

#include <iostream>
#include <string>

using namespace std;

class Disco_index
{
private:
    int id_disco;
    string route_fin_disco;
    string route_inicio_disco;
    int capacidad_disco;
public:
    Disco_index();
    ~Disco_index();

    //-------------get---------------------
    int get_id_disco();
    string get_route_fin_disco();
    string get_route_inicio_disco();
    int get_capacidad_disco();

    //---------------set-------------------
    void set_id_disco(int input);
    void set_route_fin_disco(string input);
    void set_route_inicio_disco(string input);
    void set_capacidad_disco(int input);

    //------------------others-------------
    void print_data_disco();

};

#endif
