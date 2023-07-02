#include "Sistema_Operativo.h"

Sistema_Operativo::Sistema_Operativo(){}
Sistema_Operativo::~Sistema_Operativo(){}

void Sistema_Operativo::menu(){
    std::cout<<"Usted se encuentra en el Sistema Operativo del DBMS Future (ADMIN)"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    MagneticDisk *ptr;//puntero a un disco
    string name_file_csv;//para cuando ingresemos archivo
    while (x==false)
    {
        std::cout<<"\t----- MENU -----\n";
        std::cout<<"1. Crear disco"<<endl;
        std::cout<<"2. Recuperar disco"<<endl;
        std::cout<<"3. Guardar esquema nueva tabla"<<endl;
        std::cout<<"------------"<<endl;
        std::cout<<"4. Mostrar informacion de un bloque"<<endl;
        std::cout<<"------------"<<endl;
        std::cout<<"5. Salir"<<endl;
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
                std::cout<<"Ingrese el nombre del archivo csv a analizar"<<endl;
                cin>>name_file_csv;
                crear_esquema_tabla(name_file_csv);
                break;
            case 4:
                std::cout<<"Ingrese el numero del bloque para mostrar su informacion.."<<endl;
                int num;
                cin>>num;
                mostrar_info_de_bloque(num);
                break;
            case 5:
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

//------------DISK---------

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
    cout<<"Mostrando informacion del disco guardado..."<<endl;
    brazo_disk.read_disco_info();
}

void Sistema_Operativo::recuperar_disco(){
    cout<<"recuperando disco..."<<endl;
    
}

//----------------READ INFO----------------

void Sistema_Operativo::mostrar_info_de_bloque(int num_bloque){
    BrazoDisco brazo_disk;
    brazo_disk.read_header_bloque(num_bloque);
}

//----------------- WRITE DATA ------------------
void Sistema_Operativo::crear_esquema_tabla(string _name_archivo){
    /*Quiero obtener el número o tamaño de cada
    atributo*/
    
    //ABRIR EL ARCHIVO CSV
    string route_archivo_leer=_name_archivo+".csv";
    ifstream file_open(route_archivo_leer);
    if (!file_open)
    {
        cout << "No se pudo abrir el archivo csv." << endl;
    }
    else{

        string linea;
        unordered_map<string, pair<string, int>> map_atributos;
        vector<string> vector_ordenado_atributos;
        // Leer la primera línea con los nombres de atributos
        if (getline(file_open, linea))
        {
            istringstream iss(linea);
            string _atributo;
            while (getline(iss, _atributo, ',')) // después de cada coma ','
            {
                map_atributos[_atributo] = make_pair("", 0); // Inicializar con valores vacíos
                vector_ordenado_atributos.push_back(_atributo); // Agregar el atributo al vector de orden
            }
        }

        //PASAMOS A LEER LOS REGISTROS Teniendo en cuenta los ATRIBUTOS
        int cont_size_max_strings;
        
        while (getline(file_open, linea))//mientras se tenga lineas para leer
        {
            istringstream iss(linea);//para leer parte por parte
            string valor_atributo;
            // string atributo_aux;

            int i = 0;//contador
            //leeremos toda la linea
            while (getline(iss, valor_atributo, ','))
            {
                if (i < vector_ordenado_atributos.size())// 13 VECES
                {
                    //recogemos el atributo en el puesto i de las columnas de ATRIBUTOS
                    string atributo_name = vector_ordenado_atributos[i];
                    //first guarda el tipo del dato
                    map_atributos[atributo_name].first=decidir_tipo_dato(valor_atributo);
                    //Second guardará el tamaño o size
                    //primero decidimos si el valor atributo es de tipo int, string, bool y ello
                    if (map_atributos[atributo_name].first=="int")
                    {
                        map_atributos[atributo_name].second=4;
                    }
                    else if(map_atributos[atributo_name].first=="float"){
                        map_atributos[atributo_name].second=8;
                    }
                    else if (map_atributos[atributo_name].first=="bool")
                    {
                        map_atributos[atributo_name].second=1;
                    }
                    else{
                        // cout<<"s: "<<map_atributos[atributo_name].first;
                        // const char* atributo=(map_atributos[atributo_name].first).c_str();
                        // int size_atributo=std::strlen(atributo);
                        map_atributos[atributo_name].second=strlen(valor_atributo.c_str());
                        // cout<<"s: "<<size_atributo;
                    }
                                        
                }
                i++;
            }
        }
        file_open.close();


        //CREAR EL ESQUEMA DE LA TABLA TXT
        string route_archivo_crear="Magnetic_Disk/Data/esquema_"+_name_archivo+".txt";
        ofstream file_write(route_archivo_crear);
        if (file_write.is_open()) 
        {
            file_write<<"NombreTabla"<<endl;
            file_write<<_name_archivo<<endl;
            file_write<<"Atributos"<<endl;

            //Atributos puestos
            for (int i = 0; i < vector_ordenado_atributos.size(); i++)
            {
                file_write<<vector_ordenado_atributos[i]+" ";//saca el atributo
            }
            file_write<<endl;

            //Ingresar los tipos
            file_write<<"TiposData"<<endl;
            for (int i = 0; i < vector_ordenado_atributos.size(); i++)
            {
                file_write<<map_atributos[vector_ordenado_atributos[i]].first + " ";
            }
            file_write<<endl;

            file_write<<"SizeData"<<endl;
            //Finalmente el tamaño MAX de cada uno
            //en caso de strings le aumentamos 10 más
            for (int i = 0; i < vector_ordenado_atributos.size(); i++)
            {
                file_write<<to_string(map_atributos[vector_ordenado_atributos[i]].second) + " ";
            }
            file_write<<endl;

            file_write.close();

            cout << "El archivo se ha creado exitosamente." << endl;
        }
        else 
        {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
}


//-------------------- WRITE FIXED LENGTH ----------------------
void Sistema_Operativo::escribir_disk_from_archivo(string _name_file_tabla)
{
    ifstream file(_name_file_tabla);
    if (!file)
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    else
    {
        string linea;
        unordered_map<string, pair<string, string>> map_atributos;
        vector<string> vector_orden_atributos;
        // Leer la primera línea con los nombres de atributos
        if (getline(file, linea))
        {
            istringstream iss(linea);
            string _atributo;
            while (getline(iss, _atributo, ',')) // después de cada coma ','
            {
                map_atributos[_atributo] = make_pair("", ""); // Inicializar con valores vacíos
                vector_orden_atributos.push_back(_atributo); // Agregar el atributo al vector de orden
            }
        }

        //PASAMOS A LEER LOS REGISTROS Teniendo en cuenta los ATRIBUTOS
        while (getline(file, linea))//mientras se tenga lineas para leer
        {
            istringstream iss(linea);//para leer parte por parte
            string valor_atributo;
            // string atributo_aux;

            int i = 0;//contador
            //leeremos toda la linea
            while (getline(iss, valor_atributo, ','))
            {
                if (i < vector_orden_atributos.size())
                {
                    //recogemos el atributo en el puesto i
                    string atributo_aux = vector_orden_atributos[i];
                    map_atributos[atributo_aux].first=valor_atributo;
                    map_atributos[atributo_aux].second=decidir_tipo_dato(valor_atributo);
                    
                    if (map_atributos[atributo_aux].second=="string")
                    {
                        const char* atributo=(map_atributos[atributo_aux].first).c_str();
                        int size_atributo=std::strlen(atributo);
                        BrazoDisco brazo_disk;
                        //ME QUEDE EN QUE FALTA QUE LO ESCRIBA EN LOS BLOQUES
                        // brazo_disk
                    }
                                        
                }
                i++;
            }
        }

        string guarda_atributo;
        // Imprimir los atributos y sus valores en el orden correspondiente
        for (size_t i = 0; i < vector_orden_atributos.size(); i++)
        {
            guarda_atributo = vector_orden_atributos[i];
            std::cout<<"Atributo: "<<guarda_atributo<<std::endl;
            std::cout<<"Valor 1: "<<map_atributos[guarda_atributo].first<<std::endl;
            std::cout<<"Valor 2: "<<map_atributos[guarda_atributo].second<<std::endl;
            std::cout<<std::endl;
        }

        file.close();
    }
}

string Sistema_Operativo::decidir_tipo_dato(string &value)
{
    // Ver si es de tipo Int
    bool isInteger = true;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (!isdigit(value[i]))
        {
            isInteger = false;
            break;
        }
    }
    if (isInteger)
    {
        return "int";
    }

    // Revisamos si es float
    istringstream iss(value);
    float num;
    if (iss>>num>>ws && iss.eof())
    {
        return "float";
    }

    // En caso de tener un booleano
    if (value == "true" || value == "false")
    {
        return "bool";
    }

    // Otros lo ponemos como string
    return "string";
}