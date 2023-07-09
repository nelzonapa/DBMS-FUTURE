#include "BrazoDisco.h"

BrazoDisco::BrazoDisco(){}

BrazoDisco::~BrazoDisco(){}

/*
-------------------- COMPROBAMOS EXISTENCIA DEL DISCO ----------------
*/

bool BrazoDisco::comprobar_existencia_file(const string& filePath) {
    ifstream file(filePath);
    return file.good();
}

bool BrazoDisco::Crear_leer_file_discos(const string& filePath, const string& word_buscar) {
    if (comprobar_existencia_file(filePath)) 
    {
        ifstream inputFile(filePath);
        string content((istreambuf_iterator<char>(inputFile)),istreambuf_iterator<char>());

        if (content.find(word_buscar) != string::npos) {
            cout<<word_buscar<<"' fue encontrada en "<<filePath<<endl;
            return true;
        } else {
            cout<<word_buscar<<"' no fue encontrada en "<<filePath<<endl;
            ofstream outputFile(filePath, ios::app);//para no sobreescribir
            if (outputFile.is_open()) {
                outputFile<<word_buscar<<endl;
                return false;
            }
            outputFile.close();
        }

        inputFile.close();
    } 
    else 
    {
        ofstream outputFile(filePath);
        if (outputFile.is_open()) {
            cout<<"Archivo creado: "<<filePath<<endl;
            outputFile<<word_buscar<<endl;
            return false;
        } else {
            cout<<"No se pudo crear el archivo: "<<filePath<<endl;
            // return false;
        }

        outputFile.close();
    }
}

//-------------------------PARTE_CREATE--------------------------
void BrazoDisco::crear_disco(Disco_Magnetico &disco_magnetic){
    BrazoDisco brazo_crea_disco;
    int id_disco=disco_magnetic.get_id_disk_magnetic();
    string disco_name="Disco_"+to_string(id_disco);
    //Comprobamos la existencia del disco en el registro de discos
    bool disco_existe=Crear_leer_file_discos("Disk_Manager/Discos_almacenados.txt",disco_name);
    if (disco_existe==false)
    {
        string final_route_disco="Disco_Magnetico/"+disco_name;
        LPCSTR folderPath=final_route_disco.c_str();
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) 
        {
            cout<<"Carpeta Disco creada exitosamente."<<endl;
            brazo_crea_disco.crear_platos(disco_magnetic,final_route_disco);

            std::cout<<"disc-created"<<endl;
        } 
        else 
        {
            cout<<"Error al crear la Carpeta Disco."<<endl;
        }
    }
    else
    {
        cout<<"El disco "<<disco_name<<" ya existe"<<endl;
    }
}

void BrazoDisco::crear_platos(Disco_Magnetico &disco_magnetic,const string &final_route_disco){
    int _num_platos=disco_magnetic.get_num_platos();
    for (int i = 0; i < _num_platos; i++)
    {
        string num=to_string(i+1);
        string route_plato=final_route_disco+"/Plato_";
        string final_route_plato=route_plato+num;
        cout<<"Route platos: "<<final_route_plato<<endl;//Route platos: Disk_Manager/Disco/Platos/plato_1.bin
        LPCSTR folderPath =final_route_plato.c_str();
        // cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) 
        {
            std::cout << "Carpeta plato creada exitosamente." << std::endl;
            crear_superficies(disco_magnetic,final_route_plato);//crear superficies, para el plato i
        } 
        else 
        {
            std::cout << "Error al crear la carpeta plato." << std::endl;
        }
    }
    
}

void BrazoDisco::crear_superficies(Disco_Magnetico &disco_magnetic, const string &final_route_plato){

    int _num_superficies=disco_magnetic.get_num_superficies();
    
    for (int i=1; i<=_num_superficies; i++)
    {
        string num=to_string(i);
        string route_superficie=final_route_plato+"/Superficie_";
        string final_route_superficie=route_superficie+num;
        cout<<"Route platos: "<<final_route_superficie<<endl;//Route platos: Disk_Manager/Disco/Platos/plato_1.bin
        LPCSTR folderPath =final_route_superficie.c_str();
        // cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) {
            std::cout << "Carpeta superficie creada exitosamente." << std::endl;
            crear_pistas(disco_magnetic,final_route_superficie);

        } else {
            std::cout << "Error al crear la carpeta superficie." << std::endl;
        }
    }
}

void BrazoDisco::crear_pistas(Disco_Magnetico &disco_magnetic, const string &final_route_superficie){
    int _num_pistas=disco_magnetic.get_num_pistas();
    //------------------------------------
    for (int i=1; i<=_num_pistas; i++)
    {
        string num=to_string(i);
        string route_pistas=final_route_superficie+"/Pista_";
        string final_route_pistas=route_pistas+num;
        cout<<"Route platos: "<<final_route_pistas<<endl;//Route platos: Disk_Manager/Disco/Platos/plato_1.bin
        LPCSTR folderPath =final_route_pistas.c_str();
        // cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) 
        {
            std::cout << "Carpeta Pista creada exitosamente." << std::endl;
            crear_sectores(disco_magnetic,final_route_pistas);

        } else {
            std::cout << "Error al crear la carpeta Pista." << std::endl;
        }
    }
}

void BrazoDisco::crear_sectores(Disco_Magnetico &disco_magnetic,const string &final_route_pistas){
    int _capacidad_sector=disco_magnetic.get_capacidad_sector();
    int _num_sectores=disco_magnetic.get_num_sectores();
    //------------------------------------
    for (int i=1; i<=_num_sectores; i++)
    {
        string num=to_string(i)+".bin";
        string route_sector=final_route_pistas+"/Sector_";
        string final_route_sector=route_sector+num;
        cout<<"Route platos: "<<final_route_sector<<endl;//Route platos: Disk_Manager/Disco/Platos/plato_1.bin
        
        ofstream archivo(final_route_sector,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<final_route_sector<<endl;
            archivo.seekp(_capacidad_sector-1);
            archivo.write("", 1);
            //Para que se cree con la capacidad correcta
            //Agregamos el HEADER DEL SECTOR
            // Header_Bloque header_bloque;
            // header_bloque.set_cant_bytes_bloque(_capacidad_sector);
            // header_bloque.set_cant_bytes_restantes_bloque(_capacidad_sector-sizeof(Header_Bloque));
            // header_bloque.set_cant_bytes_usados_bloque(sizeof(Header_Bloque));
            // header_bloque.set_direc_end_fixed_bloque(sizeof(Header_Bloque));
            // header_bloque.set_direc_free_space_variable_bloque(_capacidad_sector);
            // archivo.seekp(0);
            // archivo.write(reinterpret_cast<const char*>(&header_bloque), sizeof(Header_Bloque));
            // cout<<"Header del Bloque "<<i+1<<" insertado"<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_sector<<endl;
        }
        archivo.close();
    }
}

