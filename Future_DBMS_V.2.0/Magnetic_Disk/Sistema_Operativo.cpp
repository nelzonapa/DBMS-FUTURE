#include "Sistema_Operativo.h"

Sistema_Operativo::Sistema_Operativo(){}
Sistema_Operativo::~Sistema_Operativo(){}

void Sistema_Operativo::menu(){
    cout<<"Usted se encuentra en el Sistema Operativo del DBMS Future (ADMIN)"<<endl;
    bool x=false;//para detectar si sale del programa
    int op;//detectar la opcion
    MagneticDisk *ptr;//puntero a un disco
    string name_file_csv;//para cuando ingresemos archivo
    // unordered_map<string,pair<string,int>> *map_esquema;//para el esquema
    while (x==false)
    {
        std::cout<<"\t----- MENU -----\n";
        std::cout<<"1. Crear disco"<<endl;
        std::cout<<"2. Recuperar disco"<<endl;
        std::cout<<"------------"<<endl;
        std::cout<<"3. Guardar esquema nueva tabla"<<endl;
        std::cout<<"4. Escribir nuevo registro: "<<endl;
        std::cout<<"------------"<<endl;
        std::cout<<"5. Mostrar informacion de un bloque"<<endl;
        std::cout<<"------------"<<endl;
        std::cout<<"6. Salir"<<endl;
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
                // leer_esquema_tabla(name_file_csv);
                // mostrar_esquema_map(name_file_csv);
                // escribir_registro_fixed_length();
                break;
            case 4:
                escribir_registro();
                break;
            case 5:
                std::cout<<"Ingrese el numero del bloque para mostrar su informacion.."<<endl;
                int num;
                cin>>num;
                mostrar_info_de_bloque(num);
                break;
            case 6:
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

//----------------- ESQUEMA DATA ------------------
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
        MapaPares map_atributos;//unordered_map<string, pair<string, int>>
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
                file_write<<vector_ordenado_atributos[i]+",";//saca el atributo
            }
            file_write<<endl;

            //Ingresar los tipos
            file_write<<"TiposData"<<endl;
            for (int i = 0; i < vector_ordenado_atributos.size(); i++)
            {
                file_write<<map_atributos[vector_ordenado_atributos[i]].first + ",";
            }
            file_write<<endl;

            file_write<<"SizeData"<<endl;
            //Finalmente el tamaño MAX de cada uno
            //en caso de strings le aumentamos 10 más
            for (int i = 0; i < vector_ordenado_atributos.size(); i++)
            {
                file_write<<to_string(map_atributos[vector_ordenado_atributos[i]].second) + ",";
            }
            file_write<<endl;

            file_write.close();

            cout << "El archivo ESQUEMA se ha creado exitosamente." << endl;
        }
        else 
        {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
}

void Sistema_Operativo::leer_esquema_tabla(string _name_tabla){
    string route_archivo_leer="Magnetic_Disk/Data/esquema_"+_name_tabla+".txt";
    ifstream file_open(route_archivo_leer);
    if (!file_open)
    {
        cout << "No se pudo abrir el archivo csv leer esquema" << endl;
    }
    else
    {
        
        //cout<<"Para almacenar por mientras"<<endl;
        string linea;
        string name_tabla;
        MapaPares map_atributos;
        vector<string> vector_ordenado_atributos;


        // cout<<"Leer la primera línea con los nombres de atributos
        while (getline(file_open,linea))
        {
            // cout<<"linea: "<<linea<<endl;
            if (linea=="NombreTabla")
            {
                getline(file_open, linea);//leemos el nombre de la tabla
                name_tabla=linea;
            }
            else if(linea=="Atributos")
            {
                getline(file_open, linea);
                istringstream iss(linea);
                string _atributo;
                while (getline(iss,_atributo,',')) // después de cada espacio ' '
                {
                    map_atributos[_atributo] = make_pair("", 0); // Inicializar con valores vacíos
                    vector_ordenado_atributos.push_back(_atributo); // Agregar el atributo al vector de orden
                }  
            }
            else if(linea=="TiposData")
            {
                getline(file_open, linea);
                istringstream iss(linea);
                string _tipo_data;
                
                int i=0;
                while (getline(iss,_tipo_data,','))
                {
                    string atributo_name=vector_ordenado_atributos[i];
                    if (i<vector_ordenado_atributos.size())
                    {
                        map_atributos[atributo_name].first=_tipo_data;
                    }
                    i++;
                }
                
            }
            else if (linea=="SizeData")
            {
                getline(file_open, linea);
                istringstream iss(linea);
                string _size_data;
                
                int i=0;
                while (getline(iss,_size_data,','))
                {
                    string atributo_name=vector_ordenado_atributos[i];
                    if (i<vector_ordenado_atributos.size())
                    {
                        map_atributos[atributo_name].second=stoi(_size_data);
                    }
                    i++;
                }
            }
            
        }
        mostrar_esquema_map(map_atributos,vector_ordenado_atributos);
        // cout<<"Esquema leido correctamente"<<endl;
        // if (map_atributos.empty())
        // {
        //     cout<<"Mapa vacio"<<endl;
        // }
        
    }
    
    
}

MapaPares& Sistema_Operativo::get_esquema_tabla(string _name_tabla){
    string route_archivo_leer="Magnetic_Disk/Data/esquema_"+_name_tabla+".txt";
    ifstream file_open(route_archivo_leer);
    if (!file_open)
    {
        cout << "No se pudo abrir el archivo csv leer esquema" << endl;
    }
    else
    {
        
        //cout<<"Para almacenar por mientras"<<endl;
        string linea;
        string name_tabla;
        MapaPares *ptr_map_atributos=new MapaPares();
        // MapaPares map_atributos;
        vector<string> vector_ordenado_atributos;
        // (*ptr_mapa)=map_atributos;


        // cout<<"Leer la primera línea con los nombres de atributos
        while (getline(file_open,linea))
        {
            // cout<<"linea: "<<linea<<endl;
            if (linea=="NombreTabla")
            {
                getline(file_open, linea);//leemos el nombre de la tabla
                name_tabla=linea;
            }
            else if(linea=="Atributos")
            {
                getline(file_open, linea);
                istringstream iss(linea);
                string _atributo;
                while (getline(iss,_atributo,',')) // después de cada espacio ' '
                {
                    (*ptr_map_atributos)[_atributo] = make_pair("", 0); // Inicializar con valores vacíos
                    vector_ordenado_atributos.push_back(_atributo); // Agregar el atributo al vector de orden
                }  
            }
            else if(linea=="TiposData")
            {
                getline(file_open, linea);
                istringstream iss(linea);
                string _tipo_data;
                
                int i=0;
                while (getline(iss,_tipo_data,','))
                {
                    string atributo_name=vector_ordenado_atributos[i];
                    if (i<vector_ordenado_atributos.size())
                    {
                        (*ptr_map_atributos)[atributo_name].first=_tipo_data;
                    }
                    i++;
                }
                
            }
            else if (linea=="SizeData")
            {
                getline(file_open, linea);
                istringstream iss(linea);
                string _size_data;
                
                int i=0;
                while (getline(iss,_size_data,','))
                {
                    string atributo_name=vector_ordenado_atributos[i];
                    if (i<vector_ordenado_atributos.size())
                    {
                        (*ptr_map_atributos)[atributo_name].second=stoi(_size_data);
                    }
                    i++;
                }
            }
            
        }
        return (*ptr_map_atributos);
        
    }
    
    
}

vector<string>& Sistema_Operativo::get_vector_atributos(string _name_tabla){
    
    string route_archivo_leer="Magnetic_Disk/Data/esquema_"+_name_tabla+".txt";
    ifstream file_open(route_archivo_leer);
    if (!file_open)
    {
        cout << "No se pudo abrir el archivo csv leer esquema" << endl;
    }
    else
    {
        
        //cout<<"Para almacenar por mientras"<<endl;
        string linea;
        string name_tabla;
        vector<string> *ptr_vector_ordenado_atributos=new vector<string>();
        MapaPares map_atributos;
        // vector<string> vector_ordenado_atributos;
        // (*ptr_vector)=vector_ordenado_atributos;


        // cout<<"Leer la primera línea con los nombres de atributos
        getline(file_open,linea);
        getline(file_open,linea);
        //pasamos a atributos
        getline(file_open,linea);
        if(linea=="Atributos")
        {
            getline(file_open, linea);
            istringstream iss(linea);
            string _atributo;
            while (getline(iss,_atributo,',')) // después de cada espacio ' '
            {
                map_atributos[_atributo] = make_pair("", 0); // Inicializar con valores vacíos
                (*ptr_vector_ordenado_atributos).push_back(_atributo); // Agregar el atributo al vector de orden
            } 
        }
        file_open.close();
        return (*ptr_vector_ordenado_atributos);
    }
}

void Sistema_Operativo::mostrar_esquema_map(MapaPares& map_atributos,vector<string> &vector_ordenado_atributos){
    string guarda_atributo;
    // Imprimir los atributos y sus valores en el orden correspondiente
    for (size_t i = 0; i < vector_ordenado_atributos.size(); i++)
    {
        guarda_atributo = vector_ordenado_atributos[i];
        std::cout<<"Atributo: "<<guarda_atributo<<std::endl;
        std::cout<<"Valor 1: "<<map_atributos[guarda_atributo].first<<std::endl;
        std::cout<<"Valor 2: "<<map_atributos[guarda_atributo].second<<std::endl;
        std::cout<<std::endl;
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


//-------------------- WRITE FIXED OR VARIABLE LENGTH ----------------------
void Sistema_Operativo::escribir_registro()
{
    cout<<"Ingrese el nombre de la tabla a la que pertenecera su registro: "<<endl;
    string name_table;
    cin>>name_table;
    MapaPares *ptr_map_atributos=new MapaPares();
    vector<string> *ptr_vec_atributos=new vector<string>();
    vector<string> *ptr_vec_valores_ingresar=new vector<string>();;//para pasar en orden

    (*ptr_map_atributos)=get_esquema_tabla(name_table);
    (*ptr_vec_atributos)=get_vector_atributos(name_table);
    mostrar_esquema_map((*ptr_map_atributos),(*ptr_vec_atributos));

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
    BrazoDisco brazo_escritor;
    if (bool_fixed_length_data==false && bool_variable_length_data==false)
    {
        cout<<"Tipo de dato detectado: VARIABLE_LENGTH_DATA"<<endl;

        //agregamos la clave de la tabla
        (*ptr_vec_valores_ingresar).push_back(to_string(sacar_codigo_tabla(name_table)));
        //ahora el nullbitmap solo porque es de VARIABLE LENGTH
        (*ptr_vec_valores_ingresar).push_back(nullbitmap);
        //agregamos el FALSE de VARIABLE LENGTH
        (*ptr_vec_valores_ingresar).push_back("false");

        brazo_escritor.insert_variable_length_data((*ptr_map_atributos),(*ptr_vec_atributos),(*ptr_vec_valores_ingresar));
    }
    else if(bool_fixed_length_data==true && bool_variable_length_data==true){
        cout<<"Tipo de dato detectado: FIXED_LENGTH_DATA"<<endl;

        //agregamos la clave de la tabla
        (*ptr_vec_valores_ingresar).push_back(to_string(sacar_codigo_tabla(name_table)));
        //ahora el nullbitmap no es necesario
        //agregamos el TRUE de FIXED LENGTH
        (*ptr_vec_valores_ingresar).push_back("true");

        brazo_escritor.insert_fixed_length_data((*ptr_map_atributos),(*ptr_vec_atributos),(*ptr_vec_valores_ingresar));
    }

    
    
    
    
    
    
}

int Sistema_Operativo::sacar_codigo_tabla(string _name_tabla){
    int suma = 0;
    for (size_t i = 0; i < _name_tabla.length(); ++i) {
        char c = _name_tabla[i];
        suma += static_cast<int>(c);
    }
    return suma/103;
}

