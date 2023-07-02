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
        std::cout<<"------------"<<endl;
        std::cout<<"3. Mostrar informacion de un bloque"<<endl;
        std::cout<<"------------"<<endl;
        std::cout<<"4. Salir"<<endl;
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
                std::cout<<"Ingrese el numero del bloque para mostrar su informacion.."<<endl;
                int num;
                cin>>num;
                mostrar_info_de_bloque(num);
                break;
            case 4:
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
    cout<<"Mostrando informacion del disco guardado..."<<endl;
    brazo_disk.read_disco_info();
}

void Sistema_Operativo::recuperar_disco(){
    cout<<"recuperando disco..."<<endl;
    
}


void Sistema_Operativo::mostrar_info_de_bloque(int num_bloque){
    BrazoDisco brazo_disk;
    brazo_disk.read_header_bloque(num_bloque);
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
        int cont_bytes;
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
            string atributo_aux;

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