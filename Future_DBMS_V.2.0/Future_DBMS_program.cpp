#include <iostream>
#include "Disk_Manager/Disk_Manager.h"
#include "Disk_Manager/Disk_Manager.cpp"
// #include "Disco_Magnetico/Sistema_Operativo.h"
// #include "Disco_Magnetico/Sistema_Operativo.cpp"

using namespace std;

void insertar_registros_desde_file(const string &nombre_tabla,const string &doc_csv);
void insertar_registro(const string &nombre_tabla,const string &registro);
void menu_program();

void leer_registro(int num_registro);
void leer_bloque(int num_bloque);
void leer_sector(int num_sector);
void leer_pista(int num_pista);
void leer_superficie(int num_superficie);
void leer_plato(int num_plato);
void leer_disco(int id_disco);


void insertar_registros_desde_file(const string &nombre_tabla,const string &doc_csv){
    ifstream archivo(doc_csv);
    if (!archivo) {
        cout<<"Error al abrir el archivo CSV."<<endl;
    }
    else
    {
        // Descartar la primera línea (encabezados)
        string linea;
        getline(archivo, linea);
        // cout<<linea<<endl;
        while (getline(archivo,linea))
        {
            // Leer las líneas
            cout<<linea<<endl;
            insertar_registro(nombre_tabla,linea);
        }
        archivo.close();
    }
}

void insertar_registro(const string &nombre_tabla,const string &registro){
    vector<string> datos;
    istringstream iss(registro);
    string campo;

    while (getline(iss, campo, ',')) 
    {
        datos.push_back(campo);
    }
    //enviamos el registro a ser evaluado en Buffer manager que se guia del esquema
    // Buffer_Manager
    //en este caso nos saltaremos el buffer manager, e interactuaremos directamente con 
    //el esquema - data dictionary del disco
}

void leer_registro(int num_registro){

}

void leer_bloque(int num_bloque){

}

void leer_sector(int num_sector){

}

void leer_pista(int num_pista){

}

void leer_superficie(int num_superficie){

}

void leer_plato(int num_plato){

}

void leer_disco(int id_disco){

}

void menu_program(){
    cout<<"Bienvenido al nuevo DBMS Future"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    string nombre_tabla;//para cuando ingresemos archivo
    string registro;
    string doc_csv;

    while (x==false)
    {
        std::cout<<"\t----- MENU -----\n";
        std::cout<<"1. Ingresar registro"<<endl;
        std::cout<<"2. Ingresar registros de archivo"<<endl;
        std::cout<<"3. Salir"<<endl;
        std::cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"INSERT INTO: (nombre de tabla)"<<endl;
                cin>>nombre_tabla;
                cout<<"VALUES (registro a ingresar)..."<<endl;
                cin>>registro;
                insertar_registro(nombre_tabla,registro);
                break;
            case 2:
                cout<<"INSERT INTO: (nombre de tabla)"<<endl;
                cin>>nombre_tabla;
                cout<<"VALUES (nombre archivo con registros)..."<<endl;
                cin>>doc_csv;
                insertar_registros_desde_file(nombre_tabla,doc_csv);
                break;
            case 3:
                x=true;
                break;

            default:
                std::cout<<"Error, escoja entre las opciones dadas"<<endl;
                break;
        }

    }
    std::cout<<"Usted ha sido expulsado/expulsada del programa"<<endl;
    
    return;
}

int main(){
    Disk_Manager disk_aux;
    disk_aux.menu();
    // menu_program();
    return 0;
}
//solo para probar