#ifndef BPLUSNODO_H
#define BPLUSNODO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class BPlusNodo {
private:
    // Vector de vecDirecciones a nodos internos
    //string: direccion_nodo_interno
    // direc siguiente hoja
    int gradoBplusNodo;
    std::vector<string> vecDirecciones;
    // TRUE CUANDO ES HOJA, FALSE CUANDO ES NODO INTERNO

    // Vector de claves
    //string: keys
    std::vector<string> keys;
    // Booleano que indica si el nodo es hoja
    bool esHoja;

public:
    BPlusNodo(int _grado);
    BPlusNodo();
    ~BPlusNodo();

    //set-metodos
    void setEspacioVectorDirecciones(int tamanio);
    void setEspacioVectorKeys(int tamanio);
    void setEsHoja(bool input);
    void setgrado(int input);
    //get-metodos
    int getGradoBplusNodo();
    vector<string> getVecDirecciones();
    vector<string> getKeys();
    vector<string> Ordenar(vector<string> keys);
    bool getEsHoja();

    //Ingresar Datos a vectores:
    bool ingresarElementVectorDirecciones(string elemento);
    bool ingresarElementVectorKeys(string key);


    //Sobrecargas
    friend std::ostream& operator<<(std::ostream& os, const BPlusNodo& bPlusNodo);
    friend std::istream& operator>>(std::istream& is, BPlusNodo& bPlusNodo);

    //Otros
    void printInfoBPlusNode();

};


#endif