#include "BrazoDisco.h"

BrazoDisco::BrazoDisco(){}

BrazoDisco::~BrazoDisco(){}


//-------------------------PARTE_CREATE--------------------------
void BrazoDisco::crear_disco(MagneticDisk &disco_magnetic){
    // cout<<"Entre a crear_disco"<<endl;
    // disco_magnetic.print_info_magnetic_disk();
    BrazoDisco brazo_crea_disco;
    brazo_crea_disco.write_disco_info(disco_magnetic);

    // brazo_crea_disco.crear_platos(disco_magnetic.get_num_platos());
    // brazo_crea_disco.write_platos_info();//Header de platos en mantenimiento

    // brazo_crea_disco.crear_superficies(disco_magnetic.get_num_superficies());
    // brazo_crea_disco.write_superficies_info();//Header de superficies en mantenimiento

    // brazo_crea_disco.crear_pistas(disco_magnetic.get_num_pistas());
    // brazo_crea_disco.write_pistas_info();//Header de pistas en mantenimiento

    // brazo_crea_disco.crear_sectores(disco_magnetic.get_num_sectores());
    // brazo_crea_disco.write_sectores_info();//Header de sectores en mantenimiento

    // brazo_crea_disco.crear_bloques(disco_magnetic.get_num_bloques());
    // brazo_crea_disco.write_bloques_info();//Header de platos en mantenimiento

    std::cout<<"disc-created"<<endl;
}

void BrazoDisco::crear_platos(int _num_platos){
    for (int i = 0; i < _num_platos; i++)
    {
        const char* route_platos="Disco/Platos/platos_info.bin";
        cout<<"Route platos: "<<route_platos<<endl;
        ofstream archivo(route_platos,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<route_platos<<endl;
        } 
        else{
            cout<<"Error al crear el archivo binario: "<<route_platos<<endl;
        }
        archivo.close();
    }
    
}

void BrazoDisco::crear_superficies(int _num_superficies){
    for (int i = 0; i < _num_superficies; i++)
    {
        const char* route_superficies="Disco/Platos/Superficies/superficies_info.bin";
        ofstream archivo(route_superficies,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<route_superficies<<endl;
        } 
        else{
            cout<<"Error al crear el archivo binario: "<<route_superficies<<endl;
        }
        archivo.close();
    }
}

void BrazoDisco::crear_pistas(int _num_pistas){
    for (int i = 0; i < _num_pistas; i++)
    {
        const char* route_pistas="Disco/Platos/Superficies/Pistas/pistas_info.bin";
        ofstream archivo(route_pistas,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<route_pistas<<endl;
        } 
        else{
            cout<<"Error al crear el archivo binario: "<<route_pistas<<endl;
        }
        archivo.close();
    }
}

void BrazoDisco::crear_sectores(int _num_sectores){
    for (int i = 0; i < _num_sectores; i++)
    {
        const char* route_sectores="Disco/Platos/Superficies/Pistas/Sectores/sectores_info.bin";
        ofstream archivo(route_sectores,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<route_sectores<<endl;
        } 
        else{
            cout<<"Error al crear el archivo binario: "<<route_sectores<<endl;
        }
        archivo.close();
    }
}

void BrazoDisco::crear_bloques(int _num_bloques){
    for (int i = 0; i < _num_bloques; i++)
    {
        string num="_"+to_string(i+1)+".bin";
        string route_bloque="Disco/Platos/Superficies/Pistas/Sectores/bloque";
        string final_route_bloque=route_bloque+num;
        ofstream archivo(final_route_bloque,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<final_route_bloque<<endl;
        } 
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_bloque<<endl;
        }
        archivo.close();
    }
}



//-------------------------WRITE_INFO--------------------------
void BrazoDisco::write_disco_info(MagneticDisk &disco_magnetic){
    const char* route_disc="Disco/magnetic_disk_info.bin";

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
    const char* route_disc="Disco/magnetic_disk_info.bin";
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
}

void BrazoDisco::read_platos_info(){

}

void BrazoDisco::read_superficies_info(){

}

void BrazoDisco::read_pistas_info(){

}

void BrazoDisco::read_sectores_info(){

}

void BrazoDisco::read_bloques_info(){

}

