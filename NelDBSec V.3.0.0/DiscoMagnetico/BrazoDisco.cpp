#include "BrazoDisco.h"

BrazoDisco::BrazoDisco(){}

BrazoDisco::~BrazoDisco(){}

/*
-------------------- COMPROBAMOS EXISTENCIA DEL DISCO ----------------
*/

string BrazoDisco::conseguir_disco(const string &disco_name){
    bool disco_existe=Crear_leer_file_discos("DiskManager/Discos_almacenados.txt",disco_name);
    if (disco_existe==false)
    {
        cout<<"Su disco no existe - Data Index - no procede"<<endl;
    }
    else
    {
        cout<<"El disco "<<disco_name<<" si existe - Data Index - procede"<<endl;
        string ruta_disco_index="DiskManager/Data_Index/"+disco_name;
        return ruta_disco_index;
    }
}

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

void BrazoDisco::crearDiscoCuestionario(){
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

    crear_disco(*ptr_disco_magnetico);
    
    // Creamos archivo que contenga la información general del DISCO
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

        std::cout<<"Archivo Disco Info creado y escrito exitosamente: "<<name_disco<<std::endl;
    } else {
        std::cout<<"Error al crear el archivo Disco Info: "<<name_disco<<std::endl;
    }

}


void BrazoDisco::crear_multilevel_index_disco(){
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
        
        // SistemaOperativo SisOpera_aux;
        // SisOpera_aux.agregar_disco_index(*ptr_disk_header);
        // Cerrar el archivo
        archivo.close();
    } 
    else 
    {
        std::cout << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    }
}

void BrazoDisco::crear_disco(DiscoMagnetico &disco_magnetic){
    BrazoDisco brazo_crea_disco;
    int id_disco=disco_magnetic.get_id_disk_magnetic();
    string disco_name="Disco_"+to_string(id_disco);
    //Comprobamos la existencia del disco en el registro de discos
    bool disco_existe=Crear_leer_file_discos("DiskManager/Discos_almacenados.txt",disco_name);
    if (disco_existe==false)
    {
        string final_route_disco="DiscoMagnetico/"+disco_name;
        LPCSTR folderPath=final_route_disco.c_str();
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) 
        {
            cout<<"Carpeta Disco creada exitosamente."<<endl;
            
            string route_disco_index="DiskManager/Data_Index/"+disco_name+"_index";
            LPCSTR folderPath=route_disco_index.c_str();
            BOOL success = CreateDirectoryA(folderPath, NULL);
            if (success)
            {
                cout<<"Carpeta para data - index"<<disco_name<<" creada"<<endl;
            }
            else
            {
                cout<<"Error al crear carpeta disco - data index"<<endl;
            }          

            //Ahora procedemos con los platos
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

void BrazoDisco::crear_platos(DiscoMagnetico &disco_magnetic,const string &final_route_disco){
    int _num_platos=disco_magnetic.get_num_platos();
    for (int i = 0; i < _num_platos; i++)
    {
        string num=to_string(i+1);
        string route_plato=final_route_disco+"/Plato_";
        string final_route_plato=route_plato+num;
        cout<<"Route platos: "<<final_route_plato<<endl;//Route platos: DiskManager/Disco/Platos/plato_1.bin
        LPCSTR folderPath =final_route_plato.c_str();
        // cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) 
        {
            std::cout << "Carpeta plato creada exitosamente." << std::endl;
            //pasamos con las superficies
            crear_superficies(disco_magnetic,final_route_plato);//crear superficies, para el plato i
        } 
        else 
        {
            std::cout << "Error al crear la carpeta plato." << std::endl;
        }
    }
    
}

void BrazoDisco::crear_superficies(DiscoMagnetico &disco_magnetic, const string &final_route_plato){

    int _num_superficies=disco_magnetic.get_num_superficies_por_plato();
    
    for (int i=1; i<=_num_superficies; i++)
    {
        string num=to_string(i);
        string route_superficie=final_route_plato+"/Superficie_";
        string final_route_superficie=route_superficie+num;
        cout<<"Route platos: "<<final_route_superficie<<endl;//Route platos: DiskManager/Disco/Platos/plato_1.bin
        LPCSTR folderPath =final_route_superficie.c_str();
        // cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        BOOL success = CreateDirectoryA(folderPath, NULL);
        if (success) {
            std::cout << "Carpeta superficie creada exitosamente." << std::endl;

            //pasamos con las pistas
            crear_pistas(disco_magnetic,final_route_superficie);

        } else {
            std::cout << "Error al crear la carpeta superficie." << std::endl;
        }
    }
}

void BrazoDisco::crear_pistas(DiscoMagnetico &disco_magnetic, const string &final_route_superficie){
    int _num_pistas=disco_magnetic.get_num_pistas_por_superficie();
    //------------------------------------
    for (int i=1; i<=_num_pistas; i++)
    {
        string num=to_string(i);
        string route_pistas=final_route_superficie+"/Pista_";
        string final_route_pistas=route_pistas+num;
        cout<<"Route platos: "<<final_route_pistas<<endl;//Route platos: DiskManager/Disco/Platos/plato_1.bin
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

void BrazoDisco::crear_sectores(DiscoMagnetico& disco_magnetic, const std::string& final_route_pistas) {
    int _capacidad_sector = disco_magnetic.get_capacidad_sector();
    int _num_sectores = disco_magnetic.get_num_sectores_por_pista();

    for (int i = 1; i <= _num_sectores; i++) {
        std::string num = std::to_string(i) + ".txt";
        std::string route_sector = final_route_pistas + "/Sector_";
        std::string final_route_sector = route_sector + num;
        std::cout << "Ruta sectores: " << final_route_sector << std::endl;

        std::ofstream archivo(final_route_sector);
        if (archivo.is_open()) {
            std::cout << "Archivo de texto creado: " << final_route_sector << std::endl;

            // Escribir el número 1 al final del archivo
            archivo.seekp(_capacidad_sector - 1);
            archivo << "1";
        }
        else {
            std::cout << "Error al crear el archivo de texto: " << final_route_sector << std::endl;
        }
        archivo.close();
    }
}


void BrazoDisco::insertarRegistrosCSV(string &nameArchivo) {
    vector<string> valoresIngresar;
    string archivo=nameArchivo+".csv";
    string linea;
    ifstream archivoCSV(archivo);
    
    if (!archivoCSV.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivo << endl;
    }
    else
    {
        bool existeDisco=comprobar_existencia_file("Disco_1");
        if (existeDisco==true)
        {
            cout<<endl<<"Disco Enocntrado... "<<endl;
            getline(archivoCSV,linea);//Saltamos atributos
            while (getline(archivoCSV,linea))
            {
                istringstream ss(linea);
                string dato;
                while (getline(ss, dato, ',')) {
                    valoresIngresar.push_back(dato);
                    cout<<dato<<endl;
                }
                int numBloqueLibre=get_num_bloque_espacio_libre(sizeof(valoresIngresar));
                string archivoSector="Sector_"+to_string(numBloqueLibre)+".txt";
                headerSector headerSectorAux=getHeaderSector(numBloqueLibre);
                int posicionEscribir=headerSectorAux.getDirecEndFixedData();
                escribirVectorRegistroEnSector(valoresIngresar,archivoSector,posicionEscribir);
            }
        }
        else{
            cout<<"No existe un DISCO que usar"<<endl;
            crearDiscoCuestionario();
        }
        archivoCSV.close();
    }
}


void BrazoDisco::escribirVectorRegistroEnSector( vector<string> &valores,  string &archivo, int posicionWrite) {
    ofstream archivoSalida(archivo, ios::out | ios::app);

    if (!archivoSalida.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivo << endl;
        bool discoCreado;
        crearDiscoCuestionario();
        return;
    }
    else
    {
        archivoSalida.seekp(posicionWrite); // Mover el puntero de escritura a la posición dada
        archivoSalida<<"$";
        for ( string &valor : valores) {
            archivoSalida << valor << ",";
        }
        archivoSalida<<"$";
    }
    archivoSalida.close();
}



//-----------------------Read Others-------------------------
void BrazoDisco::read_header_bloque(int _num_bloque){
    int ubication_read_bin=0;
    string route_sector="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    headerSector header_bloque;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&header_bloque), sizeof(headerSector));
        cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    }
    header_bloque.printInfoSectorHeader();
    archivo.close();
    header_bloque.~headerSector();
}


//-----------------------GET---------------------------

Disco_Header& BrazoDisco::get_disco_magnetic_info(){
    const char* route_disc="DiskManager/Disco/magnetic_disk_info.bin";
    ifstream archivo(route_disc, ios::binary);
    Disco_Header *ptr_disco_magnetico=new Disco_Header();
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_disco_magnetico)), sizeof(Disco_Header));
        cout<<"Datos leidos del archivo: "<<route_disc<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<endl;
    }
    // disco_magnetico.print_info_magnetic_disk();
    archivo.close();
    return (*ptr_disco_magnetico);
}

headerSector& BrazoDisco::getHeaderSector(int _num_bloque){
    int ubication_read=0;
    string route_sector="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    ifstream archivo(route_sector);
    archivo.seekg(ubication_read);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    headerSector headerAux;
    if (archivo.is_open()) 
    {
        archivo>>headerAux;//aprovechamos sobrecarga
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para get header bloque."<<route_sector<<endl;
        
    }
    archivo.close();
    return headerAux;
}

int BrazoDisco::get_num_bloque_espacio_libre(int _space_necesitado){
    //Para leer el header de los bloques
    headerSector *ptr_header_bloque=new headerSector();

    //Primero quiero saber cuántos bloques hay
    
    Disco_Header *ptr_disco_magnetico=new Disco_Header();
    (*ptr_disco_magnetico)=get_disco_magnetic_info();
    int num_bloques=(*ptr_disco_magnetico).get_num_bloques_total();
    for (size_t i = 1; i <=num_bloques; i++)
    {
        (*ptr_header_bloque)=getHeaderSector(i);
        int space_libre=(*ptr_header_bloque).getCantBytesRestantesSector();
        if (_space_necesitado<space_libre)
        {
            return i;
        }
        
    }
}

int BrazoDisco::calcular_espacio_necesario(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    
    int espacio_ocuparemos=0;
    string atributo_key;
    string valor_atributo;
    for (int i = 0; i < _vec_atributos.size(); i++)
    {
        atributo_key=_vec_atributos[i];
        valor_atributo=_vec_valores_ingresar[i];
        //Cuenta el tamaño de todos los atributos
        // cout<<valor_atributo<<" ";
        if (valor_atributo=="NULL")
        {
            continue;//no suma ese espacio, son los 1's del NULLBITMAP
        }
        else
        {
            espacio_ocuparemos=espacio_ocuparemos+(_map_atributos[atributo_key].second);
        }
        
    }
    // cout<<"espacio gaaaaaaa: "<<espacio_ocuparemos<<endl;

    int tam_vec_valores_ingresar=_vec_valores_ingresar.size();
    int tam_vec_atributos=_vec_atributos.size();
    // cout<<tam_vec_valores_ingresar<<endl;

    for (int i=tam_vec_atributos; i<tam_vec_valores_ingresar; i++)
    {
        string valor_aux=_vec_valores_ingresar[i];
        //CODE TABLA
        // cout<<valor_aux<<" ";
        if (i==tam_vec_atributos)
        {
            espacio_ocuparemos=espacio_ocuparemos+4;
        }
        //BOOL TIPO DE VARIABLE
        else if (i==tam_vec_atributos+1)
        {
            espacio_ocuparemos=espacio_ocuparemos+1;
        }
        //EL NULLBITMAP
        else if (i==tam_vec_atributos+2)
        {
            const char* nullbitmap=valor_aux.c_str();
            espacio_ocuparemos=espacio_ocuparemos+strlen(nullbitmap);
        }
        //FINALMENTE EL ID EXTRA
        else if(i==tam_vec_atributos+3)
        {
            espacio_ocuparemos=espacio_ocuparemos+4;
        }
    }
    return espacio_ocuparemos;
}

//--------------WRITE VARIABLE DATA-----------
void BrazoDisco::caminar_por_slots_tupla_variable_data_insertar_slot(Slot &slot_tupla_enviado, int num_bloque, int direc_slot_escrito){
    // 
    // headerSector *ptr_header_bloque=new headerSector();
    // (*ptr_header_bloque)=getHeaderSector(num_bloque);//obtenemos info del header del bloque

    Slot slot_ya_escrito;//slot auxiliar
    string route_bloque="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque)+".bin";
    ifstream archivo(route_bloque, ios::binary);
    archivo.seekg(direc_slot_escrito);
    archivo.read(reinterpret_cast<char*>(&slot_ya_escrito), sizeof(Slot));
    if (slot_ya_escrito.get_direc_sig_slot()!=0)
    {
        caminar_por_slots_tupla_variable_data_insertar_slot(slot_tupla_enviado,num_bloque,slot_ya_escrito.get_direc_sig_slot());
    }
    else{
        
        headerSector *ptr_header_bloque=new headerSector();
        (*ptr_header_bloque)=getHeaderSector(num_bloque);//obtenemos el header del bloque

        int direccion_slot_nuevo=(*ptr_header_bloque).getDirecEndFixedData();
        slot_ya_escrito.set_direc_sig_slot(direccion_slot_nuevo);
        slot_tupla_enviado.set_direc_sig_slot(0);
        //ahora si escribimos el slot
        archivo.close();
        ofstream archivo_new_write(route_bloque, ios::binary | ios::app);//ios app para no eliminar contenido anterior
        archivo_new_write.seekp(direccion_slot_nuevo);
        archivo_new_write.write(reinterpret_cast<const char *>(&slot_tupla_enviado), sizeof(Slot));

        int longitud_tupla_total=slot_tupla_enviado.get_size_length();
        //-------------ACTUALIZAMOS HEADER_BLOQUE -----------
        (*ptr_header_bloque).setCantBytesRestantesSector((*ptr_header_bloque).getCantBytesRestantesSector()-(longitud_tupla_total+sizeof(Slot)));
        (*ptr_header_bloque).setCantBytesUsadosSector((*ptr_header_bloque).getCantBytesUsadosSector()+(longitud_tupla_total+sizeof(Slot)));
        (*ptr_header_bloque).setDirecEndFixedData((*ptr_header_bloque).getDirecEndFixedData()+(sizeof(Slot)));
        (*ptr_header_bloque).setDirecFreeSpaceVariableSector((*ptr_header_bloque).getDirecFreeSpaceVariableSector()-longitud_tupla_total);
        (*ptr_header_bloque).setNumGeneralRecordsSector((*ptr_header_bloque).getNumGeneralRecordsSector()+1);
        (*ptr_header_bloque).setNumRecordsVariableSector((*ptr_header_bloque).getNumRecordsVariableSector()+1);
        
        archivo_new_write.close();
    }

    
}

void BrazoDisco::insert_variable_length_data(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    
    headerSector *ptr_header_bloque=new headerSector();
    int espacio_ocuparemos=calcular_espacio_necesario(_map_atributos,_vec_atributos,_vec_valores_ingresar);
    //AHORA
    // cout<<"obtenemos el bloque con espacio libre"<<endl;
    cout<<"espacio a ocupar: "<<espacio_ocuparemos<<endl;
    int num_bloque_space=get_num_bloque_espacio_libre(espacio_ocuparemos);
    cout<<"bloque donde se escribira: "<<num_bloque_space<<endl;

    //YA TENEMOS EL HEADER DEL BLOQUE
    (*ptr_header_bloque)=getHeaderSector(num_bloque_space);

    /*
    Cómo ya sabemos a qué bloque ingresar, procedemos a ingresar el dato en ese bloque:
    */
    string route_bloque="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque_space)+".bin";

    //Abriremos el archivo:
    ofstream archivo(route_bloque, ios::binary | ios::app);//ios app para no eliminar contenido anterior
    //ahora verificamos si se abrió:
    if (archivo.is_open()) 
    {   
        /*----------- Comenzamos ESCRITURA -----------*/
        //
        int tam_vec_valores_ingresar=_vec_valores_ingresar.size();
        int tam_vec_atributos=_vec_atributos.size();
        int cant_slots_atributo=tam_vec_atributos;
        vector<Slot> vec_slots_para_ingresar;
        //escribiremos los datos y su slot:
        Slot slot_atributo;
        Slot slot_tupla;

        string atributo_key;
        string valor_atributo;

        //Ahora debemos ubicarnos donde nos indique el HEADER_DEL_BLOQUE:
        int ubication_write_bin=(*ptr_header_bloque).getDirecFreeSpaceVariableSector();
        int longitud_tupla_total=0;

        //-------------LOS ATRIBUTOS -----------
        for (int i=(tam_vec_atributos-1); i>=0; i--)
        {
            atributo_key=_vec_atributos[i];
            valor_atributo=_vec_valores_ingresar[i];
            int size_atributo=(_map_atributos[atributo_key].second);
            string tipo_data_atributo=(_map_atributos[atributo_key].first);

            // retrocede la cantidad que debe para escribir data
            ubication_write_bin = ubication_write_bin - size_atributo;
            archivo.seekp(ubication_write_bin);


            // Para escribir debemos detectar el tipo de dato
            if (valor_atributo=="NULL")
            {
                continue;   //no ingresa el que no tiene dato
                //pero se tiene que ingresar el slot? NO, porque no tiene nada
                // slot_atributo.set_offset(ubication_write_bin);
                // slot_atributo.set_size_length();
                // vec_slots_para_ingresar.push_back();
            }
            else if (tipo_data_atributo == "int")
            {
                int number = stoi(valor_atributo);
                archivo.write(reinterpret_cast<const char *>(&number), size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);


            }
            else if (tipo_data_atributo == "float")
            {
                float decimal = stof(valor_atributo);
                archivo.write(reinterpret_cast<const char *>(&decimal), size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);
            }
            else if (tipo_data_atributo == "bool")
            {
                bool booleano = (valor_atributo == "true");
                archivo.write(reinterpret_cast<const char *>(&booleano), size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);
            }
            else if (tipo_data_atributo == "string")
            {
                const char *atributo_string = valor_atributo.c_str();
                archivo.write(atributo_string, size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);
            }
        }

        int num_slots=vec_slots_para_ingresar.size();

        //-------------AHORA ingresamos los SLOTS_ATRIBUTO -----------
        for (int i=(num_slots-1); i>=0; i--)
        {
            ubication_write_bin=ubication_write_bin-sizeof(Slot);
            archivo.seekp(ubication_write_bin);
            Slot *ptr_slot_vec=&vec_slots_para_ingresar[i];

            //escribe el slot
            archivo.write(reinterpret_cast<const char *>(&(*ptr_slot_vec)), sizeof(Slot));
            longitud_tupla_total=longitud_tupla_total+sizeof(Slot);

        }

        //-------------AHORA el NULLBITMAP -----------
        //el nullbitmap esta guardado al final del vector de valores:
        const char* nullbitmap=_vec_valores_ingresar[tam_vec_valores_ingresar-1].c_str();
        //ahora ingresamos el nullbitmap
        ubication_write_bin=ubication_write_bin-strlen(nullbitmap);
        archivo.seekp(ubication_write_bin);
        archivo.write(nullbitmap, strlen(nullbitmap));

        longitud_tupla_total=longitud_tupla_total+strlen(nullbitmap);

        //-------------AHORA EL SLOT_TUPLA -----------
        //dirección de donde comienza
        slot_tupla.set_offset(ubication_write_bin);
        //Damos la longitud total de la tupla
        slot_tupla.set_size_length(longitud_tupla_total);
        //Ahora vemos la dirección que guarda del siguiente SLOT_TUPLA:
        //Caso en el que puede llegar a ser el primer registro de tipo variable:
        if ((*ptr_header_bloque).getNumRecordsVariableSector()==0)
        {
            //ESCRIBIMOS EL SLOT_TUPLA
            ubication_write_bin= (*ptr_header_bloque).getDirecEndFixedData();
            (*ptr_header_bloque).setDirecFirstVariableRecord(ubication_write_bin);//en si el primer slot
            slot_atributo.set_direc_sig_slot(0);

            //escribimos el primer slot
            archivo.seekp(ubication_write_bin);
            archivo.write(reinterpret_cast<const char *>(&slot_tupla), sizeof(Slot));
            
            //-------------ACTUALIZAR HEADER_BLOQUE -----------
            (*ptr_header_bloque).setCantBytesRestantesSector((*ptr_header_bloque).getCantBytesRestantesSector()-(longitud_tupla_total+sizeof(Slot)));
            (*ptr_header_bloque).setCantBytesUsadosSector((*ptr_header_bloque).getCantBytesUsadosSector()+(longitud_tupla_total+sizeof(Slot)));
            (*ptr_header_bloque).setDirecEndFixedData((*ptr_header_bloque).getDirecEndFixedData()+(sizeof(Slot)));
            (*ptr_header_bloque).setDirecFreeSpaceVariableSector((*ptr_header_bloque).getDirecFreeSpaceVariableSector()-longitud_tupla_total);
            (*ptr_header_bloque).setNumGeneralRecordsSector((*ptr_header_bloque).getNumGeneralRecordsSector()+1);
            (*ptr_header_bloque).setNumRecordsVariableSector((*ptr_header_bloque).getNumRecordsVariableSector()+1);
        }
        else    //caso de no ser el primer variable data
        {
            //En este caso el slot tupla que queremos ingresar es el H2
            
            headerSector *ptr_header_bloque=new headerSector();
            (*ptr_header_bloque)=getHeaderSector(num_bloque_space);//obtenemos el header del bloque
            int direcFirstVariableRecord=ptr_header_bloque->getDirecFirstVariableRecord();

            caminar_por_slots_tupla_variable_data_insertar_slot(slot_tupla,num_bloque_space,direcFirstVariableRecord);
        }
        
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para get header bloque en insert variable length: "<<route_bloque<<endl;
    }
    archivo.close();
    
}

//----------------------READ VARIABLE DATA-----------------

void BrazoDisco::leer_slot_tupla_atributos(Slot &slot,int num_bloque){
    int direccion_para_empezar_leer=slot.get_offset();
    int longitud_tupla=slot.get_size_length();

    string route_bloque="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque)+".bin";

    //primero abrimos el file del bloque a leer:
    ifstream archivo(route_bloque, ios::binary);
    if (archivo.is_open())
    {
        //primero leemos el nullbitmap:

    }
    else{
        cout<<"No se pudo abrir el archivo para lectura de slot"<<endl;
    }
    

}

void BrazoDisco::caminar_por_slots_tupla_variable_data_imprimir(int num_bloque,int direc_slot_escrito){
    Slot slot_ya_escrito;//slot auxiliar
    string route_bloque="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque)+".bin";
    ifstream archivo(route_bloque, ios::binary);
    archivo.seekg(direc_slot_escrito);
    archivo.read(reinterpret_cast<char*>(&slot_ya_escrito), sizeof(Slot));
    if (slot_ya_escrito.get_direc_sig_slot()!=0)
    {
        slot_ya_escrito.print_data_slot();
        leer_slot_tupla_atributos(slot_ya_escrito,num_bloque);
        cout<<endl;
        caminar_por_slots_tupla_variable_data_imprimir(num_bloque,slot_ya_escrito.get_direc_sig_slot());
    }
    else{
        cout<<"Ya no se tienen mas registros"<<endl;
    }
}

void BrazoDisco::read_variable_length_data_per_block(int num_block){
    
    headerSector *ptr_header_bloque=new headerSector();
    (*ptr_header_bloque)=getHeaderSector(num_block);

    int direccion_primer_slot=(*ptr_header_bloque).getDirecFirstVariableRecord();
    caminar_por_slots_tupla_variable_data_imprimir(num_block,direccion_primer_slot);
}

void BrazoDisco::read_variable_length_data(int _id_record){
    // int ubication_read;
    // 
    // headerSector *ptr_header_bloque=new headerSector();

}

//----------------------WRITE FIXED DATA---------------------

void BrazoDisco::insertFixedLengthData(vector<string> &_vec_valores_ingresar){
    headerSector *ptr_header_bloque=new headerSector();
    //primero necesitamos saber cuánto espacio ocuparemos
    int espacio_ocuparemos;
    //obtenemos el bloque con espacio libre
    int num_bloque_space=get_num_bloque_espacio_libre(espacio_ocuparemos);
    (*ptr_header_bloque)=getHeaderSector(num_bloque_space); //necesitamos algun bloque
}

//----------------------READ FIXED DATA-----------------

