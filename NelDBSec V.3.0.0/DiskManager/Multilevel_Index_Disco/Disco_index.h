#ifndef DISCO_INDEX_H
#define DISCO_INDEX_H

#include <iostream>
#include <string>

using namespace std;

class Disco_index
{
private:
    int id_disco;
    string ruta_next_disco;
    int cantidades_next_disco;
    int direccion_disco;
    int capacidad_disco;
public:
    Disco_index();
    ~Disco_index();

    //-------------get---------------------
    int get_id_disco();
    string get_ruta_next_disco();
    int get_cantidades_next_disco();
    int get_direccion_disco();
    int get_capacidad_disco();

    //---------------set-------------------
    void set_id_disco(int input);
    void set_ruta_next_disco(string input);
    void set_cantidades_next_disco(int input);
    void set_direccion_disco(int input);
    void set_capacidad_disco(int input);

    //------------------others-------------
    void print_data_disco();
    friend std::ostream& operator<<(std::ostream& os, Disco_index& disco_index);
    friend std::istream& operator>>(std::istream& is, Disco_index& disco_index);

};

#endif
