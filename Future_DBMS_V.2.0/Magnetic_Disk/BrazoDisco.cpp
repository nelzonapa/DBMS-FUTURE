#include "BrazoDisco.h"

BrazoDisco::BrazoDisco(){}

BrazoDisco::~BrazoDisco(){}


//-------------------------PARTE_CREATE--------------------------
void BrazoDisco::crear_disco(MagneticDisk &disco_magnetic){
    BrazoDisco brazo_crea_disco;
    brazo_crea_disco.write_disco_info(disco_magnetic);

    brazo_crea_disco.crear_platos(disco_magnetic);
    // brazo_crea_disco.write_platos_info();//Header de platos en mantenimiento

    brazo_crea_disco.crear_superficies(disco_magnetic);
    // brazo_crea_disco.write_superficies_info();//Header de superficies en mantenimiento

    brazo_crea_disco.crear_pistas(disco_magnetic);
    // brazo_crea_disco.write_pistas_info();//Header de pistas en mantenimiento

    brazo_crea_disco.crear_sectores(disco_magnetic);
    // brazo_crea_disco.write_sectores_info();//Header de sectores en mantenimiento

    brazo_crea_disco.crear_bloques(disco_magnetic);
    // brazo_crea_disco.write_bloques_info();//Header de platos en mantenimiento

    std::cout<<"disc-created"<<endl;
}

void BrazoDisco::crear_platos(MagneticDisk &disco_magnetic){
    int _num_platos=disco_magnetic.get_num_platos();
    int _num_superficies=disco_magnetic.get_num_superficies();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();
    for (int i = 0; i < _num_platos; i++)
    {
        Plato platito;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_plato="Magnetic_Disk/Disco/Platos/plato";
        string final_route_plato=route_plato+num;
        cout<<"Route platos: "<<final_route_plato<<endl;//Route platos: Magnetic_Disk/Disco/Platos/plato_1.bin

        //Ingresaremos datos del plato
        platito.set_id_plato(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de superficie
        //id final de superficie
        int n=(_num_superficies/_num_platos);
        int id_fin_superficie=(i+1)*n;
        int id_inicio_superficie=((i+1)*n)-(n-1);
        string route_reference_superficie="Magnetic_Disk/Disco/Platos/Superficies/superficie_";
        string route_fin_superficie=route_reference_superficie+to_string(id_fin_superficie)+".bin";
        string route_inicio_superficie=route_reference_superficie+to_string(id_inicio_superficie)+".bin";
        
        //los demás set del PLATO;
        platito.set_route_fin_plato(route_fin_superficie);
        platito.set_route_inicio_plato(route_inicio_superficie);
        platito.set_capacidad_plato(_capacidad_disco_total/_num_platos);

        cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        ofstream archivo(final_route_plato,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&platito), sizeof(Plato));
            cout<<"Archivo binario creado: "<<final_route_plato<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_plato<<endl;
        }
        archivo.close();
        platito.~Plato();
    }
    
}

void BrazoDisco::crear_superficies(MagneticDisk &disco_magnetic){
    int _num_superficies=disco_magnetic.get_num_superficies();      //
    int _num_pistas=disco_magnetic.get_num_pistas();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();

    for (int i = 0; i < _num_superficies; i++)      //
    {
        Superficie superficie;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_superficie="Magnetic_Disk/Disco/Platos/Superficies/superficie";
        string final_route_superficie=route_superficie+num;
        cout<<"Route superficie: "<<final_route_superficie<<endl;

        //Ingresaremos datos del superficie
        superficie.set_id_superficie(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de pista
        //id final de pista
        int n=(_num_pistas/_num_superficies);      //
        int id_fin_pista=(i+1)*n;
        int id_inicio_pista=(i+1)*n-(n-1);
        string route_reference_pista="Magnetic_Disk/Disco/Platos/Superficies/Pistas/pista_";
        string route_fin_pista=route_reference_pista+to_string(id_fin_pista)+".bin";
        string route_inicio_pista=route_reference_pista+to_string(id_inicio_pista)+".bin";
        //los demás set de la superficie;
        superficie.set_route_fin_superficie(route_fin_pista);
        superficie.set_route_inicio_superficie(route_inicio_pista);
        superficie.set_capacidad_superficie(_capacidad_disco_total/_num_superficies);      //

        //Abrimos, creamos y escribimos
        ofstream archivo(final_route_superficie,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&superficie), sizeof(Superficie));
            cout<<"Archivo binario creado: "<<final_route_superficie<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_superficie<<endl;
        }
        archivo.close();
        superficie.~Superficie();
    }
}

void BrazoDisco::crear_pistas(MagneticDisk &disco_magnetic){
    int _num_pistas=disco_magnetic.get_num_pistas();      //
    int _num_sectores=disco_magnetic.get_num_sectores();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();
    
    for (int i = 0; i < _num_pistas; i++)      //
    {
        Pista pista;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_superficie="Magnetic_Disk/Disco/Platos/Superficies/Pistas/pista";
        string final_route_pista=route_superficie+num;
        cout<<"Route platos: "<<final_route_pista<<endl;

        //Ingresaremos datos del pista
        pista.set_id_pista(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de sector
        //id final de sector
        int n=(_num_sectores/_num_pistas);      //
        int id_fin_sector=(i+1)*n;
        int id_inicio_sector=(i+1)*n-(n-1);
        string route_reference_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/sector_";
        string route_fin_sector=route_reference_sector+to_string(id_fin_sector)+".bin";
        string route_inicio_sector=route_reference_sector+to_string(id_inicio_sector)+".bin";
        //los demás set de la pista;
        pista.set_route_fin_pista(route_fin_sector);
        pista.set_route_inicio_pista(route_inicio_sector);
        pista.set_capacidad_pista(_capacidad_disco_total/_num_pistas);      //

        //Abrimos, creamos y escribimos
        ofstream archivo(final_route_pista,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&pista), sizeof(Pista));
            cout<<"Archivo binario creado: "<<final_route_pista<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_pista<<endl;
        }
        archivo.close();
        pista.~Pista();
    }
}

void BrazoDisco::crear_sectores(MagneticDisk &disco_magnetic){
    int _num_sectores=disco_magnetic.get_num_sectores();      //
    int _num_bloques=disco_magnetic.get_num_bloques();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();
    
    for (int i = 0; i < _num_sectores; i++)      //
    {
        Sector sector;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_superficie="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/sector";
        string final_route_sector=route_superficie+num;
        cout<<"Route platos: "<<final_route_sector<<endl;

        //Ingresaremos datos de sector
        sector.set_id_sector(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de bloque
        //id final de bloque
        int n=(_num_bloques/_num_sectores);      //
        int id_fin_bloque=(i+1)*n;
        int id_inicio_bloque=(i+1)*n-(n-1);
        string route_reference_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_";
        string route_fin_bloque=route_reference_bloque+to_string(id_fin_bloque)+".bin";
        string route_inicio_bloque=route_reference_bloque+to_string(id_inicio_bloque)+".bin";
        //los demás set de la sector;
        sector.set_route_fin_sector(route_fin_bloque);
        sector.set_route_inicio_sector(route_inicio_bloque);
        sector.set_capacidad_sector(_capacidad_disco_total/_num_sectores);      //

        //Abrimos, creamos y escribimos
        ofstream archivo(final_route_sector,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&sector), sizeof(Sector));
            cout<<"Archivo binario creado: "<<final_route_sector<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_sector<<endl;
        }
        archivo.close();
        sector.~Sector();
    }
}

void BrazoDisco::crear_bloques(MagneticDisk &disco_magnetic){
    int _num_bloques=disco_magnetic.get_num_bloques();
    int _capacidad_total_disco=disco_magnetic.get_capacidad_total_magneticDisk();
    int _capacidad_por_bloque=_capacidad_total_disco/_num_bloques;
    for (int i = 0; i < _num_bloques; i++)
    {
        //Nos ubicamos:
        string num="_"+to_string(i+1)+".bin";
        string route_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque";
        string final_route_bloque=route_bloque+num;
        //Abrimos,creamos
        ofstream archivo(final_route_bloque,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<final_route_bloque<<endl;
            archivo.seekp(_capacidad_por_bloque-1);
            archivo.write("", 1);
            //Para que se cree con la capacidad correcta
            //Agregamos el HEADER DEL BLOQUE
            Header_Bloque header_bloque;
            header_bloque.set_cant_bytes_bloque(_capacidad_por_bloque);
            header_bloque.set_cant_bytes_restantes_bloque(_capacidad_por_bloque-sizeof(Header_Bloque));
            header_bloque.set_cant_bytes_usados_bloque(sizeof(Header_Bloque));
            header_bloque.set_direc_end_fixed_bloque(sizeof(Header_Bloque));
            header_bloque.set_direc_free_space_variable_bloque(_capacidad_por_bloque);
            archivo.seekp(0);
            archivo.write(reinterpret_cast<const char*>(&header_bloque), sizeof(Header_Bloque));
            cout<<"Header del Bloque "<<i+1<<" insertado"<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_bloque<<endl;
        }
        archivo.close();
    }
}



//-------------------------WRITE_INFO--------------------------
void BrazoDisco::write_disco_info(MagneticDisk &disco_magnetic){
    const char* route_disc="Magnetic_Disk/Disco/magnetic_disk_info.bin";

    disco_magnetic.set_route_disk_magnetic(route_disc);
    ofstream archivo(route_disc,ios::binary);
    // ofstream archivo;
    // archivo.exceptions(ofstream::failbit | ofstream::badbit);
    // archivo.open(route_disc,ios::binary| ios::in);
    //Me quede en llenar el archivo de info del disco que será de ejemplo para lo demás 
    
    if (archivo.is_open()){
        cout<<"Archivo binario creado: "<<route_disc<<endl;
        archivo.write(reinterpret_cast<const char*>(&disco_magnetic), sizeof(MagneticDisk));
    } 
    else{
        cout<<"Error al crear el archivo binario: "<<route_disc<<endl;
    }
    archivo.close();
}

void BrazoDisco::write_platos_info(){
}

void BrazoDisco::write_superficies_info(){

}

void BrazoDisco::write_pistas_info(){

}

void BrazoDisco::write_sectores_info(){
    
}

void BrazoDisco::write_bloques_info(){

}

//-------------------------READ_INFO--------------------------
void BrazoDisco::read_disco_info(){
    const char* route_disc="Magnetic_Disk/Disco/magnetic_disk_info.bin";
    ifstream archivo(route_disc, ios::binary);
    MagneticDisk disco_magnetico;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&disco_magnetico), sizeof(MagneticDisk));
        cout<<"Datos leidos del archivo: "<<route_disc<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<endl;
    }
    disco_magnetico.print_info_magnetic_disk();
    archivo.close();
    disco_magnetico.~MagneticDisk();
}

void BrazoDisco::read_plato_info(int _num_plato){
    int ubication_read_bin=0;
    string route_plato="Magnetic_Disk/Disco/Platos/plato_"+to_string(_num_plato)+".bin";

    ifstream archivo(route_plato, ios::binary);
    archivo.seekg(ubication_read_bin);

    Plato platito;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&platito), sizeof(Plato));
        cout<<"Datos leidos del archivo: "<<route_plato<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_plato<<endl;
    }
    platito.print_data_Plato();
    archivo.close();
    platito.~Plato();
}

void BrazoDisco::read_superficie_info(int _num_superficie){
    int ubication_read_bin=0;
    string route_superficie="Magnetic_Disk/Disco/Platos/Superficies/superficie_"+to_string(_num_superficie)+".bin";

    ifstream archivo(route_superficie, ios::binary);
    archivo.seekg(ubication_read_bin);

    Superficie superficie;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&superficie), sizeof(Superficie));
        cout<<"Datos leidos del archivo: "<<route_superficie<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_superficie<<endl;
    }
    superficie.print_data_superficie();
    archivo.close();
    superficie.~Superficie();
}

void BrazoDisco::read_pista_info(int _num_pista){
    int ubication_read_bin=0;
    string route_pista="Magnetic_Disk/Disco/Platos/Superficies/Pistas/pista_"+to_string(_num_pista)+".bin";

    ifstream archivo(route_pista, ios::binary);
    archivo.seekg(ubication_read_bin);

    Pista pista;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&pista), sizeof(Pista));
        cout<<"Datos leidos del archivo: "<<route_pista<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_pista<<endl;
    }
    pista.print_data_pista();
    archivo.close();
    pista.~Pista();
}

void BrazoDisco::read_sector_info(int _num_sector){
    int ubication_read_bin=0;
    string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/sector_"+to_string(_num_sector)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    Sector sector;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&sector), sizeof(Sector));
        cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    }
    sector.print_data_sector();
    archivo.close();
    sector.~Sector();
}

void BrazoDisco::read_bloque_info(int _num_bloque){
    // int ubication_read_bin=0;
    // string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    // ifstream archivo(route_sector, ios::binary);
    // archivo.seekg(ubication_read_bin);

    // //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    // Sector sector;
    // if (archivo.is_open()) {
    //     archivo.read(reinterpret_cast<char*>(&sector), sizeof(Sector));
    //     cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    // } else {
    //     cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    // }
    // sector.print_data_sector();
    // archivo.close();
    // sector.~Sector();
    cout<<"read_bloque_info() En proceso..."<<endl;
}


//-----------------------Read Others-------------------------
void BrazoDisco::read_header_bloque(int _num_bloque){
    int ubication_read_bin=0;
    string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Header_Bloque header_bloque;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&header_bloque), sizeof(Header_Bloque));
        cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    }
    header_bloque.print_info_header_bloque();
    archivo.close();
    header_bloque.~Header_Bloque();
}

