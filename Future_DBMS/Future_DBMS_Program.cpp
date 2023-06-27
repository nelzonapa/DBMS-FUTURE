#include <iostream>
#include "Main_Memory/Buffer_manager.h"
#include "Main_Memory/Buffer_manager.cpp"
#include "Main_Memory/Disk_Manager.h"
#include "Main_Memory/Disk_Manager.cpp"

using namespace std;

void menu(Buffer_manager *ptr_buf_manager);

int main(){
    cout<<"Bienvenido al programa principal - Future DBMS -"<<endl;
    cout<<"Creando el buffer pool para el uso del programa..."<<endl;
    Buffer_manager *ptr_buf_manager=new Buffer_manager();//Buffer manager creado
    Disk_Manager *ptr_disco_manager=new Disk_Manager();
    cout<<"Buffer_manager creado...\nBuffer Pool creado...\nDisk_manager creado"<<endl;
    menu(ptr_buf_manager);

}

void menu(Buffer_manager *ptr_buf_manager){
    std::cout<<"Bienvenido al DBMS Future!!"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    while (x==false)
    {
        std::cout<<"\t----- MENU -----\n";
        std::cout<<"1. Mostrar registro"<<endl;
        std::cout<<"2. Salir"<<endl;
        std::cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                int num_registro; 
                cout<<"Indique el numero del registro:"<<endl;
                cin>>num_registro;
                (*ptr_buf_manager).show_page(num_registro);
                break;

            case 2:
                x=true;
                break;

            default:
                std::cout<<"Error, escoja entre las opciones dadas"<<endl;
                break;
        }

    }
    std::cout<<"Usted ha sido expulsado del programa..."<<endl;
    return;
}