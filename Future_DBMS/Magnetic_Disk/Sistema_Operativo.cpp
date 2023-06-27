#include "Sistema_Operativo.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

Sistema_operativo::Sistema_operativo(){

}
Sistema_operativo::~Sistema_operativo(){}

void Sistema_operativo::menu(){
    std::cout<<"Bienvenido al nuevo DBMS Future!!"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    MagneticDisk *ptr;//puntero a un disco
    while (x==false)
    {
        std::cout<<"\t----- MENÚ -----\n";
        std::cout<<"1. Config DISCO"<<endl;
        std::cout<<"2. Mostrar info de disco"<<endl;
        std::cout<<"3. Mostrar METADATA de un objeto"<<endl;
        std::cout<<"4. Mostrar datos de un bloque"<<endl;
        std::cout<<"5. Insertar comando"<<endl;
        std::cout<<"6. Eliminar un registro"<<endl;
        std::cout<<"7. Insertar registros/objetos de longitud variable"<<endl;
        std::cout<<"8. Mostrar tabla slot index"<<endl;
        std::cout<<"9. Insertar registros/objetos de longitud fija"<<endl;
        std::cout<<"10. Insertar registros desde un archivo"<<endl;
        std::cout<<"11. Mostrar info de DataBase"<<endl;
        std::cout<<"12. Mostrar slot"<<endl;
        std::cout<<"13. Salir"<<endl;
        std::cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
            
                cout<<"Configurando su DISCO"<<endl;
                ptr=config_disco_magnetic();
                break;
            
            case 2:
                std::cout<<"Mostrar información del DISCO"<<endl;
                (*ptr).print_info_magentic_disk();//muestra la información del disco
                break;
            case 3:
                int id_object;
                cout<<"Ingrese el numero_id del objeto a mostrar su METADATA: "<<endl;
                cin>>id_object;
                read_metadata_object(id_object,(*ptr));
                break;
            case 4:
                // cout<<"Comando en mantenimiento..."<<endl;
                int id_bloque;
                cout<<"Ingrese el numero_id del Bloque a mostrar: "<<endl;
                cin>>id_bloque;
                read_data_bloque(id_bloque,(*ptr));
                break;
            case 5:
                std::cout<<"En mantenimiento ..."<<endl;
                // analizar_comando_ingresado((*ptr));
                break;

            case 6:
                int id_object_delete;
                cout<<"Ingrese el id del registro a eliminar: "<<endl;
                cin>>id_object_delete;
                eliminar_registro(id_object_delete,(*ptr));
                break;
            case 7:
                ingresar_registro_variable(*ptr);
                break;
            case 8:
                mostrar_slots_index();
                break;
            case 9:
                ingresar_registro_fijo();
                break;
            case 10:
                ingresar_registros_archivo(*ptr);
                //puede que haya uno para registrso fijos y otro para variables desde un csv
                break;
            case 11:
                mostrar_info_DataBase();
                break;
            case 12:
                int num; 
                cout<<"Ingrese el numero del slot a mostrar"<<endl;
                cin>>num;
                mostrar_slot(num);
                break;
            case 13:
                x=true;
                break;

            default:
                std::cout<<"Error, escoja entre las opciones dadas"<<endl;
                break;
        }

    }
    std::cout<<"Usted ha sido expulsado del programa"<<endl;
    
    return;
}

void Sistema_operativo::read_data_bloque(int id_bloque,MagneticDisk &ptr){
    int cantidad_platos=ptr.return_n_platos();
    int cant_sectores=ptr.return_n_sectores();
    int cant_pistas=ptr.return_n_pistas();
    int cant_objects=ptr.return_n_objetos();
    int cant_objects_por_bloq=ptr.return_cant_objects_block();
    R_W_Head head;
    // head.reading_metadata_bloque(id_bloque,cantidad_platos,cant_sectores,cant_pistas,cant_objects);
    head.print_data_passengers_bloque(id_bloque,cant_objects_por_bloq);
}

void Sistema_operativo::read_metadata_object(int id_object,MagneticDisk &ptr){
    int cantidad_platos=(ptr).return_n_platos();
    int cant_sectores=ptr.return_n_sectores();
    int cant_pistas=ptr.return_n_pistas();
    int cant_objects=ptr.return_n_objetos();
    R_W_Head head;
    head.reading_metadata_object(id_object,cantidad_platos,cant_sectores,cant_pistas,cant_objects);
}

void Sistema_operativo::analizar_comando(const string &comando_ingresado,MagneticDisk &disco){
    //SELECT * FROM #passenger_titanic#
    stringstream ss(comando_ingresado);
    string element;
    getline(ss,element,'#');//leemos la primera parte
    getline(ss,element,'#');
    element.erase(std::remove(element.begin(), element.end(), ' '), element.end());//borramos espacios en blanco
    if (element=="titanic")
    {
        string tabla=element+".bin";
        disco.print_data_passengers();
    }
    else if (element=="WHERE")
    {
        int id;
        string signo;
        getline(ss,element,'#');
        getline(ss,element,'#');
        signo=element;
        getline(ss,element,'#');
        element.erase(std::remove(element.begin(), element.end(), ' '), element.end());//borramos espacios en blanco
        id = std::stoi(element);
        disco.print_data_passengers_filtro(signo,id);
    }
    

    //SELECT * FROM passenger_titanic #WHERE #passenger_id#<#20#
    //SELECT * FROM passenger_titanic #WHERE #passenger_id#=#20#
}

MagneticDisk* Sistema_operativo::config_disco_magnetic(){
    int cantidad_platos,capacidad_bytes, cant_sectores, cant_pistas;
    std::cout<<"Ingrese la cantidad de platos a tener: "<<endl;
    cin>>cantidad_platos;    //recibe cantidad de platos, recordemos que cada plato tiene sus 2 superficies
    std::cout<<"Ingrese la cantidad de sectores por superficie a tener: "<<endl;
    cin>>cant_sectores; //recibe la cantidad de sectores a tener
    std::cout<<"Ingrese la cantidad de pistas por superficie a tener: "<<endl;
    cin>>cant_pistas; //recibe la cantidad de pistas a tener
    /*
    OJO: al tener la cantidad de sectores y la cantidad de pistas, 
    se obtendrá a partir de ello el número de bloques a crear.
    */
    std::cout<<"Ingrese la capacidad total que desea tener en su disco magnetico en bytes: "<<endl;
    cin>>capacidad_bytes;    //1024 -> 1 KB
    MagneticDisk *ptr=new MagneticDisk(cantidad_platos,capacidad_bytes,cant_sectores,cant_pistas);//se crea el disco con las características dadas
    cout<<"Disco CONFIGURADO correctamente"<<endl;
    return ptr;
}

void Sistema_operativo::analizar_comando_ingresado(MagneticDisk &disco){
    string consulta;
    std::cout<<"Ingrese su consulta: "<<endl;
    cin.ignore();
    getline(cin,consulta);//obtenemos la consulta
    //SELECT * FROM #passenger_titanic#
    analizar_comando(consulta,disco);
}

void Sistema_operativo::eliminar_registro(int id_object, MagneticDisk &disco){
    R_W_Head head;
    head.print_header_fixed_data();
    head.delete_data_fixed_block(id_object);
    head.print_header_fixed_data();
    // read_metadata_object(id_object,disco);
}

//Fijo
void Sistema_operativo::ingresar_registro_fijo(){
    std::cout<<"Comando en mantenimiento..."<<endl;
    // std::cout<<"Ahora ingrese un archivo para leer la data en el DISCO:"<<endl;
    // cin>>name_archivo;
    // cout<<"leyendo archivo..."<<endl;
    // int _capacity_disk=(*ptr).return_capacity_disco_mag();
    // R_W_Head head;
    // int _new_cantida=head.leer_registros_from_csv(name_archivo,"DataBase.bin",_capacity_disk);
    // // cout<<"Size: "<<sizeof(Passenger_titanic)<<endl;
    // (*ptr).modificar_cantidad_usada(_new_cantida*sizeof(Passenger_titanic));
    // // cout<<"Cantidad leida del archivo: "<<_new_cantida<<endl;
    // cout<<"Archivo leido y cargado con exito"<<endl;
    // cout<<"Nombre de su tabla: titanic"<<endl;
}

void Sistema_operativo::ingresar_registros_archivo(MagneticDisk &ptr){
    // std::cout<<"Comando en mantenimiento..."<<endl;
    int _capacity_disk=(ptr).return_capacity_disco_mag();
    string name_archivo, consulta;
    std::cout<<"Ingrese el nombre del archivo:"<<endl;
    cin>>name_archivo;
    cout<<"leyendo archivo: "<<name_archivo<<" ..."<<endl;
    R_W_Head head;
    head.leer_registros_from_csv(name_archivo,"DataBase.bin",_capacity_disk);
    // cout<<"Size: "<<sizeof(Passenger_titanic)<<endl;
    Header *ptr_header=new Header();
    ptr_header=head.get_header_file();
    int cant_usada=(*ptr_header).get_cant_bytes_usados();
    ptr.modificar_cantidad_usada(cant_usada);
    // // cout<<"Cantidad leida del archivo: "<<_new_cantida<<endl;
    cout<<"Archivo leido y cargado con exito"<<endl;
    // cout<<"Nombre de su tabla:"<<endl;
}


//Variable

void Sistema_operativo::ingresar_registro_variable(MagneticDisk &disco){
    int capacidad_disco=disco.return_capacity_disco_mag();
    // cout<<"capacidad_disco: "<<capacidad_disco<<endl;
    std::cout<<"Ingresando registro de ejemplo"<<endl;
    R_W_Head head;
    Estudiante est1(1,0,"Nelzon",20190652,"");
    head.write_variable_data_block(est1,capacidad_disco);
    // mostrar_slots_index();
}

void Sistema_operativo::mostrar_slots_index(){
    std::cout<<"Mostrando la tabla slots_index..."<<endl;
    R_W_Head head;
    Head_slot_index *ptr=new Head_slot_index();
    ptr=head.get_head_slots_index();
    int num_slots=(*ptr).get_num_slots_index();
    cout<<"Num slots: "<<num_slots<<endl;
    int ubication=0;
    for (int i=1; i<=num_slots; i++)
    {
        // int direc_read=i*sizeof(Slot)-sizeof(Slot);//sizeof(Head_slot_index) ya esta dentro de get_Slot_index()
        Slot *ptr_slot_index=new Slot();
        ptr_slot_index=head.get_slot_index(ubication);
        (*ptr_slot_index).print_data_slot();
        ubication+=sizeof(Slot);
    }
    
}

//In process
void Sistema_operativo::mostrar_slot(int num_slot){
    std::cout<<"Mostrando contenido del slot #"<<num_slot<<endl;
    
    R_W_Head head;
    Head_slot_index *ptr_head_slot=new Head_slot_index();
    ptr_head_slot=head.get_head_slots_index();
    if ((*ptr_head_slot).get_num_slots_index()<=num_slot)//mientras si exista
    {
        Slot *ptr_slot=head.get_slot_index(num_slot*sizeof(Slot)-sizeof(Slot));
        (*ptr_slot).print_data_slot();
        Estudiante *ptr_student=new Estudiante();
        ptr_student=head.read_variable_data_block((*ptr_slot));
        (*ptr_student).print_info_student();
    }
    else{
        std::cout<<"No se tiene ese slot"<<endl;
    }
    
}

void Sistema_operativo::mostrar_info_DataBase(){
    Header *ptr_header=new Header();
    R_W_Head head;
    ptr_header=head.get_header_file();
    std::cout<<"Mostrando informacion de la DataBase de Header Principal..."<<endl;
    (*ptr_header).print_info_header();
}

