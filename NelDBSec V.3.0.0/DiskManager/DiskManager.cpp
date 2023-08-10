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
    this->sistemaOperativo.crear_disco();
}
void DiskManager::crear_multilevel_index_disco(){
    this->sistemaOperativo.crear_multilevel_index_disco();
}

//----------------READ INFO----------------

void DiskManager::print_multilevel_index_disco(){
    cout<<"Ingrese el id del disco para mostrar su respectivo multilevel index: "<<endl;
    int id_disco;
    cin>>id_disco;
    this->sistemaOperativo.print_disco_index(id_disco);
    this->sistemaOperativo.print_plato_index(id_disco);
    this->sistemaOperativo.print_superficie_index(id_disco);
    this->sistemaOperativo.print_pista_index(id_disco);
    this->sistemaOperativo.print_sector_index(id_disco);
    this->sistemaOperativo.print_bloque_index(id_disco);
}

void DiskManager::mostrar_informacion_disco(int id_disco){
    
    Disco_Header *ptr_disc_header=new Disco_Header();
    (*ptr_disc_header)=this->sistemaOperativo.get_disco_header(id_disco);
    ptr_disc_header->print_info_magnetic_disk();
}

//IN PROCESS
void DiskManager::mostrar_info_de_bloque(int num_bloque){
    
    // this->sistemaOperativo.read_header_bloque(num_bloque);
}

//IN PROCESS
void DiskManager::mostrar_contenido_variable_length_bloque(int num_bloque){
    
    // this->sistemaOperativo.read_variable_length_data_per_block(num_bloque);
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
    
    if (bool_fixed_length_data==false && bool_variable_length_data==false)
    {
        cout<<"Tipo de dato detectado: VARIABLE_LENGTH_DATA"<<endl;

        //agregamos la clave de la tabla
        (*ptr_vec_valores_ingresar).push_back(to_string(sacar_codigo_tabla(name_table)));

        //agregamos el FALSE de VARIABLE LENGTH
        (*ptr_vec_valores_ingresar).push_back("false");

        //ahora el nullbitmap solo porque es de VARIABLE LENGTH
        (*ptr_vec_valores_ingresar).push_back(nullbitmap);

        // this->sistemaOperativo.insert_variable_length_data((*ptr_map_atributos),(*ptr_vec_atributos),(*ptr_vec_valores_ingresar));
    }
    else if(bool_fixed_length_data==true && bool_variable_length_data==true){
        cout<<"Tipo de dato detectado: FIXED_LENGTH_DATA"<<endl;

        //agregamos la clave de la tabla
        (*ptr_vec_valores_ingresar).push_back(to_string(sacar_codigo_tabla(name_table)));
        //ahora el nullbitmap no es necesario
        //agregamos el TRUE de FIXED LENGTH
        (*ptr_vec_valores_ingresar).push_back("true");

        // this->sistemaOperativo.insertFixedLengthData((*ptr_map_atributos),(*ptr_vec_atributos),(*ptr_vec_valores_ingresar));
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
// Pagina DiskManager::obtenerBloquePagina(int idPagina){

// }

// NUEVOS REGISTROS DESDE CSV
void DiskManager::agregarRegistrosNuevaTabla(string nombreArchivo){
    this->sistemaOperativo.ingresarTablaDesdeArchivoCSV(nombreArchivo);
}