#include "DiskManager.h"

DiskManager::DiskManager(){}
DiskManager::~DiskManager(){}

void DiskManager::menu(){
    cout<<"Usted se encuentra en el Disk Manager del DBMS Future (ADMIN)"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    // Disco_Header *ptr;//puntero a un disco
    string name_file_csv;//para cuando ingresemos archivo
    // unordered_map<string,pair<string,int>> *map_esquema;//para el esquema
    int id_disco;
    while (x==false)
    {
        cout<<"\t----- MENU -----\n";
        cout<<"1. Crear disco"<<endl;
        cout<<"2. Crear multilevel index disco"<<endl;
        cout<<"3. Mostrar informacion disco"<<endl;
        cout<<"4. Mostrar informacion del multilevel index"<<endl;
        cout<<"------------"<<endl;
        cout<<"5. Guardar esquema nueva tabla"<<endl;
        cout<<"6. Escribir nuevo registro: "<<endl;
        cout<<"------------"<<endl;
        cout<<"7. Mostrar informacion de un bloque"<<endl;
        cout<<"8. Mostrar registros variables de un bloque"<<endl;
        cout<<"------------"<<endl;
        cout<<"9. Salir"<<endl;
        cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Creando disco..."<<endl;
                crear_disco();
                break;
            case 2:
                // cout<<"Recuperando disco..."<<endl;
                crear_multilevel_index_disco();
                break;
            case 3:
                cout<<"Mostrando información del disco..."<<endl;
                cout<<"Ingrese el id del disco a leer: "<<endl;
                cin>>id_disco;
                mostrar_informacion_disco(id_disco);
                break;
            case 4:
                cout<<"Multilevel Index Disco..."<<endl;
                print_multilevel_index_disco();
                break;
            case 5:
                cout<<"Ingrese el nombre del archivo csv a analizar - En proceso -"<<endl;
                // cin>>name_file_csv;
                // crear_esquema_tabla(name_file_csv);
                break;
            case 6:
                escribir_registro();
                break;
            case 7:
                cout<<"Ingrese el numero del bloque para mostrar su informacion.."<<endl;
                int num2;
                cin>>num2;
                mostrar_info_de_bloque(num2);
                break;
            case 8:
                cout<<"Ingrese el numero del bloque para mostrar los registros variables.."<<endl;
                int num;
                cin>>num;
                mostrar_contenido_variable_length_bloque(num);
                break;
            case 9:
                x=true;
                break;

            default:
                cout<<"Error, escoja entre las opciones dadas"<<endl;
                break;
        }

    }
    cout<<"Usted ha sido expulsado/expulsada del programa"<<endl;
    
    return;
}

//------------DISK---------

void DiskManager::crear_disco(){
    cout<<"Creando disco..."<<endl;
    DiscoMagnetico *ptr_disco_magnetico=new DiscoMagnetico();
    //recolectaremos_información:
    cout<<"Para proceder complete lo siguiente: "<<endl;
    int id_disco,cantidad_platos,capacidad_sector, cant_sectores, cant_pistas,sectores_por_bloque;
    
    std::cout<<"Ingrese el ID de su disco: "<<endl;
    cin>>id_disco;    //recibe el id del disco
    ptr_disco_magnetico->set_id_disk_magnetic(id_disco);

    std::cout<<"Ingrese la cantidad de PLATOS a tener: "<<endl;
    cin>>cantidad_platos;    //recibe cantidad de platos, recordemos que cada plato tiene sus 2 superficies
    ptr_disco_magnetico->set_num_platos(cantidad_platos);

    ptr_disco_magnetico->set_num_superficies_por_plato(2);

    std::cout<<"Ingrese la cantidad de PISTAS por Superficie a tener: "<<endl;
    cin>>cant_pistas;       //recibe la cantidad de pistas a tener
    ptr_disco_magnetico->set_num_pistas_por_superficie(cant_pistas);
    
    std::cout<<"Ingrese la cantidad de SECTORES por Pista a tener: "<<endl;
    cin>>cant_sectores;     //recibe la cantidad de sectores a tener
    ptr_disco_magnetico->set_num_sectores_por_pista(cant_sectores);

    std::cout<<"Ingrese la cantidad de Sectores en un Bloque a tener: "<<endl;
    cin>>sectores_por_bloque;     //recibe la cantidad de sectores a tener
    ptr_disco_magnetico->set_num_sectores_en_bloque(sectores_por_bloque);

    std::cout<<"Ingrese la capacidad del sector: "<<endl;
    cin>>capacidad_sector;    //1024 -> 1 KB
    ptr_disco_magnetico->set_capacidad_sector(capacidad_sector);

    cout<<"Informacion del disco llenada correctamente"<<endl;
    cout<<"Creando su disco"<<endl;

    //Ahora llamamos a brazo
    BrazoDisco brazo_disk;
    brazo_disk.crear_disco(*ptr_disco_magnetico);
    
    // Abrir el archivo en modo de escritura
    string name_disco="DiskManager/disco_"+to_string(ptr_disco_magnetico->get_id_disk_magnetic())+"_info.txt";
    std::ofstream archivo(name_disco);

    if (archivo.is_open()) {
        string disco_name="Disco_"+to_string(ptr_disco_magnetico->get_id_disk_magnetic());
        string final_route_disco="DiscoMagnetico/"+disco_name;
        archivo<<final_route_disco<<endl;
        archivo<<ptr_disco_magnetico->get_id_disk_magnetic()<<endl;
        archivo<<ptr_disco_magnetico->get_num_platos()<<endl;
        archivo<<ptr_disco_magnetico->get_num_superficies_por_plato()<<endl;
        archivo<<ptr_disco_magnetico->get_num_pistas_por_superficie()<<endl;
        archivo<<ptr_disco_magnetico->get_num_sectores_por_pista()<<endl;
        archivo<<ptr_disco_magnetico->get_num_sectores_en_bloque()<<endl;
        archivo<<ptr_disco_magnetico->get_capacidad_sector()<<endl;

        // Cerrar el archivo
        archivo.close();

        std::cout<<"Archivo creado y escrito exitosamente: "<<name_disco<<std::endl;
    } else {
        std::cout<<"Error al crear el archivo: "<<name_disco<<std::endl;
    }

}


void DiskManager::crear_multilevel_index_disco(){
    int id_disco;
    cout<<"Creando multilevel...\nIngrese el id del disco: "<<endl;
    cin>>id_disco;
    
    Disco_Header *ptr_disk_header=new Disco_Header();

    string nombreArchivo="DiskManager/disco_"+to_string(id_disco)+"_info.txt";
    // Abrir el archivo en modo de lectura
    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) 
    {
        std::string linea;

        getline(archivo, linea);
        ptr_disk_header->set_route_disk_magnetic(linea);

        getline(archivo, linea);
        ptr_disk_header->set_id_disk_magnetic(stoi(linea));

        getline(archivo, linea);
        ptr_disk_header->set_num_platos_total(stoi(linea));

        getline(archivo, linea);
        ptr_disk_header->set_num_superficies_total(stoi(linea)*2);
        int cantidad_platos=stoi(linea);

        getline(archivo, linea);
        ptr_disk_header->set_num_pistas_total(cantidad_platos*2*stoi(linea));
        int cant_pistas=stoi(linea);

        getline(archivo, linea);
        ptr_disk_header->set_num_sectores_total(cantidad_platos*2*cant_pistas*stoi(linea));
        int cant_sectores=stoi(linea);

        getline(archivo, linea);
        ptr_disk_header->set_num_bloques_total(cantidad_platos*2*cant_pistas*cant_sectores*stoi(linea));
        int cant_bloques=stoi(linea);

        getline(archivo, linea);
        ptr_disk_header->set_capacidad_total_magneticDisk(stoi(linea)*(ptr_disk_header->get_num_sectores_total()));
        
        SistemaOperativo SisOpera_aux;
        SisOpera_aux.agregar_disco_index(*ptr_disk_header);
        // Cerrar el archivo
        archivo.close();
    } 
    else 
    {
        std::cout << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    }
}


//----------------READ INFO----------------

void DiskManager::print_multilevel_index_disco(){
    SistemaOperativo sis_operativo;
    cout<<"Ingrese el id del disco para mostrar su respectivo multilevel index: "<<endl;
    int id_disco;
    cin>>id_disco;
    sis_operativo.print_disco_index(id_disco);
    sis_operativo.print_plato_index(id_disco);
    sis_operativo.print_superficie_index(id_disco);
    sis_operativo.print_pista_index(id_disco);
    sis_operativo.print_sector_index(id_disco);
    sis_operativo.print_bloque_index(id_disco);
}

void DiskManager::mostrar_informacion_disco(int id_disco){
    SistemaOperativo sis_operativo;
    Disco_Header *ptr_disc_header=new Disco_Header();
    (*ptr_disc_header)=sis_operativo.get_disco_header(id_disco);
    ptr_disc_header->print_info_magnetic_disk();
}

//IN PROCESS
void DiskManager::mostrar_info_de_bloque(int num_bloque){
    SistemaOperativo sis_operat;
    sis_operat.read_header_bloque(num_bloque);
}

//IN PROCESS
void DiskManager::mostrar_contenido_variable_length_bloque(int num_bloque){
    SistemaOperativo sis_operat;
    sis_operat.read_variable_length_data_per_block(num_bloque);
}


// --------------------------------------------------------------------- IN PROCESS ------------------------------------------------------


//-------------------- WRITE FIXED OR VARIABLE LENGTH ----------------------
void DiskManager::escribir_registro()
{
    cout<<"Ingrese el nombre de la tabla a la que pertenecera su registro: "<<endl;
    string name_table;
    cin>>name_table;
    MapaPares *ptr_map_atributos=new MapaPares();
    vector<string> *ptr_vec_atributos=new vector<string>();
    vector<string> *ptr_vec_valores_ingresar=new vector<string>();;//para pasar en orden

    // (*ptr_map_atributos)=get_esquema_tabla(name_table);
    // (*ptr_vec_atributos)=get_vector_atributos(name_table);
    // mostrar_esquema_map((*ptr_map_atributos),(*ptr_vec_atributos));

    //dependiendo del nombre de la tabla:
    // Al leer archivos CON RESGITROS: IFSTREAM Y CON EL FOR QUE VAYA
    // AVANZANDO CON EL GETLINE ISS PARA LEER CADA ATRIBUTO
    string nullbitmap;
    for (size_t i = 0; i < (*ptr_vec_atributos).size(); i++)
    {
        string leida;
        string atributo_a_leer=(*ptr_vec_atributos)[i];
        cout<<"Ingrese el atributo: "<<atributo_a_leer<<endl;
        cin>>leida;
        (*ptr_vec_valores_ingresar).push_back(leida);
        //Para decidir si es variable o  fixed
        if (leida=="NULL")
        {
            nullbitmap=nullbitmap+"1";
        }
        else
        {
            nullbitmap=nullbitmap+"0";
        }
    }
    //Ya tenemos los atributos y también el nullbitmap
    bool bool_fixed_length_data=true; //es fijo
    bool bool_variable_length_data=true; // es fijo, no variable
    //SI AMBOS SON TRUE, SE INCLINA A FIXED
    //SI AMBOS SON FALSE, SE INCLINA A VARIABLE
    cout<<"Nullbitmap: "<<nullbitmap<<endl;
    for (int i = 0; i < nullbitmap.size(); i++)
    {
        if (nullbitmap[i]=='1')
        {
            bool_variable_length_data=false;//variable length detectado
            bool_fixed_length_data=false;
            break;//se detiene todo
        }
    }
    SistemaOperativo sis_operativo;
    if (bool_fixed_length_data==false && bool_variable_length_data==false)
    {
        cout<<"Tipo de dato detectado: VARIABLE_LENGTH_DATA"<<endl;

        //agregamos la clave de la tabla
        (*ptr_vec_valores_ingresar).push_back(to_string(sacar_codigo_tabla(name_table)));

        //agregamos el FALSE de VARIABLE LENGTH
        (*ptr_vec_valores_ingresar).push_back("false");

        //ahora el nullbitmap solo porque es de VARIABLE LENGTH
        (*ptr_vec_valores_ingresar).push_back(nullbitmap);

        sis_operativo.insert_variable_length_data((*ptr_map_atributos),(*ptr_vec_atributos),(*ptr_vec_valores_ingresar));
    }
    else if(bool_fixed_length_data==true && bool_variable_length_data==true){
        cout<<"Tipo de dato detectado: FIXED_LENGTH_DATA"<<endl;

        //agregamos la clave de la tabla
        (*ptr_vec_valores_ingresar).push_back(to_string(sacar_codigo_tabla(name_table)));
        //ahora el nullbitmap no es necesario
        //agregamos el TRUE de FIXED LENGTH
        (*ptr_vec_valores_ingresar).push_back("true");

        // sis_operativo.insertFixedLengthData((*ptr_map_atributos),(*ptr_vec_atributos),(*ptr_vec_valores_ingresar));
    }

    
    
    
    
    
    
}

int DiskManager::sacar_codigo_tabla(string _name_tabla){
    int suma = 0;
    for (size_t i = 0; i < _name_tabla.length(); ++i) {
        char c = _name_tabla[i];
        suma += static_cast<int>(c);
    }
    return suma/103;
}

// OBTENER BLOQUE PARA BUFFER MANAGER
Pagina DiskManager::obtenerBloquePagina(int idPagina){

}

// NUEVOS REGISTROS DESDE CSV
void DiskManager::agregarRegistrosNuevaTabla(string nombreArchivo){
    this->sistemaOperativo.ingresarTablaDesdeArchivoCSV(nombreArchivo);
}