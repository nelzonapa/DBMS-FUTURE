#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include "BPlusNodo.h"
#include "BPlusNodo.cpp"

#include <iostream>
#include <string>
#include <fstream>
#include <string>


using namespace std;

class BPlusTree
{
private:
    string nameTabla;  //tabla a la que pertenece el B+
    int grado; // Rango del árbol
    string direccionRaiz; // dirección de la raíz del árbol
    string direcfinalBPlusTree;

public:
    BPlusTree();
    BPlusTree(int n);
    ~BPlusTree();

    //SETTERS
    void set_nameTabla(string input); 
    void set_grado(int input);
    void set_direccionRaiz(string input); 
    void set_direcfinalBPlusTree(string input);
    
    //GETTERS
    string get_nameTabla(); 
    int get_grado();
    string get_direccionRaiz(); 
    string get_direcfinalBPlusTree();

    //Otros
    bool verificarExistenciaRaiz(int direccionRaiz);
    void agregarNewKey(int idRegistro,int direccionRaiz);
    void eliminarNodo();
    void reemplazarNodo();
    void imprimirInfoBPlusTree();
    void escribirNodo(int position, BPlusNodo &bPlusNodo);
    
    //Sobrecarga
    friend std::ostream& operator<<(std::ostream& os, const BPlusTree& bplusTree);
    friend std::istream& operator>>(std::istream& is, BPlusTree& bplusTree);


};

#endif