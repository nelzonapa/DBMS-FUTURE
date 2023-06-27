#include "MagneticDisk.h"
#include "MagneticDisk.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Sistema_operativo
{
private:
    /* data */
public:
    Sistema_operativo();
    ~Sistema_operativo();


    /*Funciones*/
    void menu();
    MagneticDisk* config_disco_magnetic();

    void analizar_comando(const string &comando_ingresado,MagneticDisk &disco);
    void analizar_comando_ingresado(MagneticDisk &disco);
    void read_metadata_object(int id_object,MagneticDisk &ptr);
    void read_data_bloque(int id_bloque,MagneticDisk &ptr);
    void eliminar_registro(int id_object, MagneticDisk &disco);

    //Fijo
    void ingresar_registro_fijo();
    void ingresar_registros_archivo(MagneticDisk &ptr);
    //Variable
    void ingresar_registro_variable(MagneticDisk &disco);
    void mostrar_slots_index();
    void mostrar_info_DataBase();
    void mostrar_slot(int num_slot);

};