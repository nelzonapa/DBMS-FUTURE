#include <iostream>
#include "Programa.h"
#include "Programa.cpp"

void mostrarTablaMetadata();
void menu_program(Programa &programa);

int main(){
    Programa *ptr_programa=new Programa();
    Pagina *ptr_pagina;
    menu_program(*ptr_programa);
}

void menu_program(Programa &programa){
    cout<<"Bienvenido al nuevo DBMS Future"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;
    int num_pagina;

    while (x==false)
    {
        std::cout<<"\t----- MENU -----\n";
        std::cout<<"1. Obtener Pagina"<<endl;
        std::cout<<"2. Mostrar la tabla metadata"<<endl;
        std::cout<<"3. Salir"<<endl;
        std::cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Ingrese el numero de la pagina a obtener"<<endl;
                cin>>num_pagina;
                programa.setPtrPaginaRecibir(programa.obtenerPagina(num_pagina));
                break;
            case 2:
                cout<<"Estado de la tabla metadata: ...."<<endl;
                mostrarTablaMetadata();
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

void mostrarTablaMetadata(){
    
}
