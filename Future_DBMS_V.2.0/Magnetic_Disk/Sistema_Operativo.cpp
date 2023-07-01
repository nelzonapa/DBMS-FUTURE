#include "Sistema_Operativo.h"

Sistema_Operativo::Sistema_Operativo(){}
Sistema_Operativo::~Sistema_Operativo(){}

void Sistema_Operativo::menu(){
    std::cout<<"Usted se encuentra en el Sistema Operativo del DBMS Future (ADMIN)"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    MagneticDisk *ptr;//puntero a un disco
    while (x==false)
    {
        std::cout<<"\t----- MENU -----\n";
        std::cout<<"1. Crear disco"<<endl;
        std::cout<<"2. Recuperar disco"<<endl;
        std::cout<<"3. Salir"<<endl;
        std::cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Creando disco..."<<endl;
                crear_disco();
                break;
            
            case 2:
                std::cout<<"Recuperando disco..."<<endl;
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

void Sistema_Operativo::crear_disco(){
    cout<<"Creando disco..."<<endl;
    MagneticDisk* ptr_MagneticDisk=new MagneticDisk();
    //recolectaremos_información:
    cout<<"Para proceder complete lo siguiente: "<<endl;
    int cantidad_platos,capacidad_bytes, cant_sectores, cant_pistas,cant_bloques;
    
    std::cout<<"Ingrese la cantidad de PLATOS a tener: "<<endl;
    cin>>cantidad_platos;    //recibe cantidad de platos, recordemos que cada plato tiene sus 2 superficies
    ptr_MagneticDisk->set_num_platos(cantidad_platos);
    ptr_MagneticDisk->set_num_superficies(cantidad_platos*2);

    std::cout<<"Ingrese la cantidad de PISTAS por Superficie a tener: "<<endl;
    cin>>cant_pistas;       //recibe la cantidad de pistas a tener
    ptr_MagneticDisk->set_num_pistas(cant_pistas*(ptr_MagneticDisk->get_num_superficies()));
    
    std::cout<<"Ingrese la cantidad de SECTORES por Pista a tener: "<<endl;
    cin>>cant_sectores;     //recibe la cantidad de sectores a tener
    ptr_MagneticDisk->set_num_sectores(cant_sectores*(ptr_MagneticDisk->get_num_pistas()));

    std::cout<<"Ingrese la cantidad de BLOQUES por Sector a tener: "<<endl;
    cin>>cant_bloques;     //recibe la cantidad de sectores a tener
    ptr_MagneticDisk->set_num_bloques(cant_bloques*(ptr_MagneticDisk->get_num_sectores()));

    std::cout<<"Ingrese la capacidad total que desea tener en su disco magnetico en bytes: "<<endl;
    cin>>capacidad_bytes;    //1024 -> 1 KB
    ptr_MagneticDisk->set_capacidad_total_magneticDisk(capacidad_bytes);

    cout<<"Informacion del disco llenada correctamente"<<endl;
    cout<<"Creando su disco"<<endl;
    // ptr_MagneticDisk->print_info_magnetic_disk();

    //Ahora llamamos a brazo
    BrazoDisco brazo_disk;
    brazo_disk.crear_disco(*ptr_MagneticDisk);
    cout<<"Disco creado correctamente..."<<endl;
    cout<<"Mostrando info de disco guardado..."<<endl;
    brazo_disk.read_disco_info();
    cout<<"-------------------------"<<endl;
    brazo_disk.read_plato_info(1);
    brazo_disk.read_plato_info(2);
    cout<<"-------------------------"<<endl;
    brazo_disk.read_superficie_info(1);
    brazo_disk.read_superficie_info(2);
    brazo_disk.read_superficie_info(3);
    brazo_disk.read_superficie_info(4);
    cout<<"-------------------------"<<endl;
    brazo_disk.read_pista_info(1);
    brazo_disk.read_pista_info(2);
    brazo_disk.read_pista_info(3);
    brazo_disk.read_pista_info(6);
    brazo_disk.read_pista_info(7);
    brazo_disk.read_pista_info(8);
    cout<<"-------------------------"<<endl;
    brazo_disk.read_sector_info(1);
    brazo_disk.read_sector_info(2);
    brazo_disk.read_sector_info(3);
    brazo_disk.read_sector_info(14);
    brazo_disk.read_sector_info(15);
    brazo_disk.read_sector_info(16);

}

void Sistema_Operativo::recuperar_disco(){
    cout<<"recuperando disco..."<<endl;
    
}