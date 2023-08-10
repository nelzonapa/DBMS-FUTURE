#include "SistemaOperativo.h"

SistemaOperativo::SistemaOperativo(){}

SistemaOperativo::~SistemaOperativo(){}


//-------------------------PARTE_CREATE--------------------------


void SistemaOperativo::agregar_disco_index(Disco_Header &disco_header){
    //Escribe el header principal
    SistemaOperativo sis_operativo_aux;
    sis_operativo_aux.write_disco_general_info(disco_header);

    //Ahora pasamos a escribir todo lo demás:
    string disco_name="Disco_"+to_string(disco_header.get_id_disk_magnetic());
    string route_disco_index="DiskManager/Data_Index/"+disco_name+"_index";

    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_disco=disco_header.get_capacidad_total_magneticDisk();
    Disco_index disco_index;
    disco_index.set_id_disco(disco_header.get_id_disk_magnetic());
    //POSIBLE PROBLEM ROUTE
    string next_route=disco_header.get_route_disk_magnetic()+"/Plato_1";
    disco_index.set_ruta_next_disco(disco_header.get_route_disk_magnetic());
    disco_index.set_cantidades_next_disco(disco_header.get_num_platos_total());
    disco_index.set_direccion_disco(0);
    disco_index.set_capacidad_disco(peso_disco);
    //dirección desde 0
    //Enviamos a escribir la parte para Disk Manager: 
    sis_operativo_aux.write_disco_info(disco_index,route_disco_index,0);
    sis_operativo_aux.agregar_platos_index(disco_header,route_disco_index);
    sis_operativo_aux.agregar_superficies_index(disco_header,route_disco_index);
    sis_operativo_aux.agregar_pistas_index(disco_header,route_disco_index);
    sis_operativo_aux.agregar_sectores_index(disco_header,route_disco_index);
    sis_operativo_aux.agregar_bloques_index(disco_header,route_disco_index);
}

void SistemaOperativo::agregar_platos_index(Disco_Header & disco_header,const string &route_disco_index){
    SistemaOperativo sis_operativo_aux;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_plato=(disco_header.get_capacidad_total_magneticDisk()/disco_header.get_num_platos_total());
    int num_platos=disco_header.get_num_platos_total();
    for (int i = 1; i <=num_platos; i++)
    {
        Plato_Index plato_index;
        plato_index.set_ruta_next_plato("/Superficie_");
        plato_index.set_cantidades_next_plato(disco_header.get_num_superficies_total());
        plato_index.set_capacidad_plato(peso_plato);
        plato_index.set_direccion_plato(direccion_bytes);
        plato_index.set_id_plato(i);

        sis_operativo_aux.write_platos_info(plato_index,route_disco_index,acumulador_bytes); //Importante para caminar en el archivo binario

        direccion_bytes+=peso_plato;  
        acumulador_bytes+=sizeof(Plato_Index);
    }
}

void SistemaOperativo::agregar_superficies_index(Disco_Header & disco_header,const string &route_disco_index){
    SistemaOperativo sis_operativo_aux;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_superficie=disco_header.get_capacidad_total_magneticDisk()/disco_header.get_num_superficies_total();
    int num_superficie=disco_header.get_num_superficies_total();
    for (int i = 1; i <=num_superficie; i++)
    {
        Superficie_Index superficie_index;
        superficie_index.set_ruta_next_superficie("/Pista_");
        superficie_index.set_cantidades_next_superficie(disco_header.get_num_pistas_total());
        superficie_index.set_capacidad_superficie(peso_superficie);
        superficie_index.set_direccion_superficie(direccion_bytes);
        superficie_index.set_id_superficie(i);

        sis_operativo_aux.write_superficies_info(superficie_index,route_disco_index,acumulador_bytes); //Importante para caminar en el archivo binario

        direccion_bytes+=peso_superficie;  
        acumulador_bytes+=sizeof(Superficie_Index);
    }
}

void SistemaOperativo::agregar_pistas_index(Disco_Header & disco_header,const string &route_disco_index){
    SistemaOperativo sis_operativo_aux;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_pista=disco_header.get_capacidad_total_magneticDisk()/disco_header.get_num_pistas_total();
    int num_pistas=disco_header.get_num_pistas_total();
    for (int i = 1; i <=num_pistas; i++)
    {
        Pista_Index pista_index;
        pista_index.set_ruta_next_pista("/Sector_");
        pista_index.set_cantidades_next_pista(disco_header.get_num_sectores_total());
        pista_index.set_capacidad_pista(peso_pista);
        pista_index.set_direccion_pista(direccion_bytes);
        pista_index.set_id_pista(i);

        sis_operativo_aux.write_pistas_info(pista_index,route_disco_index,acumulador_bytes); //Importante para caminar en el archivo binario

        direccion_bytes+=peso_pista;  
        acumulador_bytes+=sizeof(Pista_Index);
    }
}

void SistemaOperativo::agregar_sectores_index(Disco_Header & disco_header,const string &route_disco_index){
    SistemaOperativo sis_operativo_aux;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_sector=disco_header.get_capacidad_total_magneticDisk()/disco_header.get_num_sectores_total();
    int num_sectores=disco_header.get_num_sectores_total();
    for (int i = 1; i <=num_sectores; i++)
    {
        Sector_Index sector_index;
        sector_index.set_ruta_next_sector("/Bloque_");
        sector_index.set_cantidades_next_sector(disco_header.get_num_bloques_total());
        sector_index.set_capacidad_sector(peso_sector);
        sector_index.set_direccion_sector(direccion_bytes);
        sector_index.set_id_sector(i);

        sis_operativo_aux.write_sectores_info(sector_index,route_disco_index,acumulador_bytes); //Importante para caminar en el archivo binario

        direccion_bytes+=peso_sector;  
        acumulador_bytes+=sizeof(Sector_Index);
    }
}

void SistemaOperativo::agregar_bloques_index(Disco_Header & disco_header,const string &route_disco_index){
    SistemaOperativo sis_operativo_aux;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_bloque=disco_header.get_capacidad_total_magneticDisk()/disco_header.get_num_bloques_total();
    int num_bloques=disco_header.get_num_bloques_total();
    for (int i = 1; i <=num_bloques; i++)
    {
        Bloque bloque;
        bloque.set_capacidad_bloque(peso_bloque);
        bloque.set_direccion_inicio_bloque(direccion_bytes);
        bloque.set_id_bloque(i);

        sis_operativo_aux.write_bloques_info(bloque,route_disco_index,acumulador_bytes); //Importante para caminar en el archivo binario

        direccion_bytes+=peso_bloque;  
        acumulador_bytes+=sizeof(Bloque);
    }
}

//-------------------------WRITE_INFO--------------------------
void SistemaOperativo::write_disco_general_info(Disco_Header &disco_header){
    string disco_name = "Disco_" + to_string(disco_header.get_id_disk_magnetic());
    string route_disco_header = "DiskManager/Data_Index/" + disco_name + "_index/Disco_header.bin";

    int ubication_write=0;
    fstream file(route_disco_header,ios::binary| ios::in| ios::out);
    if (!file.is_open()) {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntentandode de nuevo..."<<endl;
        fstream file(route_disco_header,ios::binary| ios::in| ios::out | ios::trunc);
        // int id_aux=verify_existence_fixed_record();
        file.seekp(ubication_write);
        //escribimos al pasajero en la base de datos bin
        file.write((char *)&disco_header,sizeof(Disco_Header));
        file.close();
    }
    else
    {
        // int id_aux=verify_existence_fixed_record();
        file.seekp(ubication_write);
        //we want to write the object of these class Passenger_titanic into our binary file
        file.write((char *)&disco_header,sizeof(Disco_Header));
        file.close();
    }

}

void SistemaOperativo::write_disco_info(Disco_index &disco_index,const string &ruta_disco, int ubication_write){
    string route_disc=ruta_disco+"/disco_index.bin";

    ofstream archivo(route_disc,ios::binary);
    archivo.seekp(ubication_write);
    if (archivo.is_open())
    {
        cout<<"Archivo binario creado: "<<route_disc<<endl;
        archivo.seekp(0);
        archivo.write(reinterpret_cast<const char*>(&disco_index), sizeof(Disco_index));
    } 
    else
    {
        cout<<"Error al crear el archivo binario: "<<route_disc<<endl;
    }
    archivo.close();
}

void SistemaOperativo::write_platos_info(Plato_Index &plato_index,const string &ruta_disco, int ubication_write){
    string ubication_file_bin=ruta_disco+"/platos_index.bin";
    fstream file(ubication_file_bin,ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones

    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file(ubication_file_bin,ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&plato_index,sizeof(Plato_Index));
        cout<<"platos_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&plato_index,sizeof(Plato_Index));
        file.close();
        cout<<"platos_index.bin..."<<endl;

    }
}

void SistemaOperativo::write_superficies_info(Superficie_Index &superficie_index,const string &ruta_disco, int ubication_write){
    string ubication_file_bin=ruta_disco+"/superficies_index.bin";
    fstream file(ubication_file_bin,ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones

    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file(ubication_file_bin,ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&superficie_index,sizeof(Superficie_Index));
        cout<<"superficies_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&superficie_index,sizeof(Superficie_Index));
        file.close();
        cout<<"superficies_index.bin..."<<endl;

    }
}

void SistemaOperativo::write_pistas_info(Pista_Index &pista_index,const string &ruta_disco, int ubication_write){
    string ubication_file_bin=ruta_disco+"/pistas_index.bin";
    fstream file(ubication_file_bin,ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones

    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file(ubication_file_bin,ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&pista_index,sizeof(Pista_Index));
        cout<<"pistas_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&pista_index,sizeof(Pista_Index));
        file.close();
        cout<<"pistas_index.bin..."<<endl;

    }
}

void SistemaOperativo::write_sectores_info(Sector_Index &sector_index,const string &ruta_disco, int ubication_write){
    string ubication_file_bin=ruta_disco+"/sectores_index.bin";
    fstream file(ubication_file_bin,ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones

    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file(ubication_file_bin,ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&sector_index,sizeof(Sector_Index));
        cout<<"sectores_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&sector_index,sizeof(Sector_Index));
        file.close();
        cout<<"sectores_index.bin..."<<endl;

    }
}

void SistemaOperativo::write_bloques_info(Bloque &bloque,const string &ruta_disco, int ubication_write){
    string ubication_file_bin=ruta_disco+"/bloques_index.bin";
    fstream file(ubication_file_bin,ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones

    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file(ubication_file_bin,ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&bloque,sizeof(Bloque));
        cout<<"bloques_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&bloque,sizeof(Bloque));
        file.close();
        cout<<"bloques_index.bin..."<<endl;

    }
}

//-------------------------GET PARTS--------------------------

Disco_Header& SistemaOperativo::get_disco_header(int num_id_disco){
    string disco_name="Disco_"+to_string(num_id_disco);
    string final_route_disco_header="DiskManager/Data_Index/"+disco_name+"_index/Disco_header.bin";
    
    fstream file(final_route_disco_header,ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else
    {
        file.seekg(0);//read from the beginning, tomando header

        Disco_Header *ptr_disco_header=new Disco_Header();
        file.read((char *)&(*ptr_disco_header),sizeof(Disco_Header));

        return (*ptr_disco_header);
        file.close();

    }

    // ifstream archivo(final_route_disco_header, ios::binary);
    // if (archivo.is_open()) {
    //     archivo.seekg(0);
    //     Disco_Header *ptr_disco_h=new Disco_Header();
    //     archivo.read((char*)&(*ptr_disco_h), sizeof(Disco_Header));
    //     // cout<<":::"<<disco_h.get_num_bloques_total()<<endl;
    //     // disco_h.print_info_magnetic_disk();

    //     if (!archivo.fail()) {
    //         cout << "Datos leidos del archivo: " << final_route_disco_header << endl;
    //         return (*ptr_disco_h);
    //     } 
    //     else 
    //     {
    //         cout << "Error al leer el archivo binario: " << final_route_disco_header << endl;
    //     }
    // } 
    // else 
    // {
    //     cout << "Error al abrir el archivo binario para lectura: " << final_route_disco_header << endl;
    // }
    // archivo.close();
}

Disco_index& SistemaOperativo::get_disco_index(int num_id_disco){
    Disco_index *disco_index=new Disco_index();
    string disco_name="Disco_"+to_string(num_id_disco);
    string final_route_disco="DiskManager/Data_Index/"+disco_name+"_index/disco_index.bin";
    ifstream archivo(final_route_disco, ios::binary);
    archivo.seekg(0);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*disco_index)), sizeof(Disco_index));
        cout<<"Datos leidos del archivo: "<<final_route_disco<<endl;
        return (*disco_index);
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para lectura."<<final_route_disco<<endl;
    }
}

Plato_Index& SistemaOperativo::get_plato_index(int num_id_disco,int id_plato){
    int ubication_read_bin=id_plato*sizeof(Plato_Index);
    string route_plato_index="DiskManager/Data_Index/Disco_"+to_string(num_id_disco)+"_index/platos_index";

    ifstream archivo(route_plato_index, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Plato_Index *ptr_plato_index;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_plato_index)), sizeof(Plato_Index));
        cout<<"Datos leidos del archivo: "<<route_plato_index<<endl;
        return (*ptr_plato_index);
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_plato_index<<endl;
    }
    archivo.close();
}

Superficie_Index& SistemaOperativo::get_superficie_index(int num_id_disco, int id_superficie){
    int ubication_read_bin=id_superficie*sizeof(Superficie_Index);
    string route_superficie_index="DiskManager/Data_Index/Disco_"+to_string(num_id_disco)+"_index/superficies_index";

    ifstream archivo(route_superficie_index, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Superficie_Index *ptr_superficie_index;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_superficie_index)), sizeof(Superficie_Index));
        cout<<"Datos leidos del archivo: "<<route_superficie_index<<endl;
        return (*ptr_superficie_index);
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_superficie_index<<endl;
    }
    archivo.close();
}

Pista_Index& SistemaOperativo::get_pista_index(int num_id_disco, int id_pista){
    int ubication_read_bin=id_pista*sizeof(Pista_Index);
    string route_pista_index="DiskManager/Data_Index/Disco_"+to_string(num_id_disco)+"_index/pistas_index";

    ifstream archivo(route_pista_index, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Pista_Index *ptr_pista_index;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_pista_index)), sizeof(Pista_Index));
        cout<<"Datos leidos del archivo: "<<route_pista_index<<endl;
        return (*ptr_pista_index);
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_pista_index<<endl;
    }
    archivo.close();
}

Sector_Index& SistemaOperativo::get_sector_index(int num_id_disco, int id_sector){
    int ubication_read_bin=id_sector*sizeof(Sector_Index);
    string route_sector_index="DiskManager/Data_Index/Disco_"+to_string(num_id_disco)+"_index/sectores_index";

    ifstream archivo(route_sector_index, ios::binary);
    archivo.seekg(ubication_read_bin);

    Sector_Index *ptr_sector_index;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_sector_index)), sizeof(Sector_Index));
        cout<<"Datos leidos del archivo: "<<route_sector_index<<endl;
        return (*ptr_sector_index);
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_sector_index<<endl;
    }
    archivo.close();
}

Bloque& SistemaOperativo::get_bloque_index(int num_id_disco, int id_bloque){
    int ubication_read_bin=id_bloque*sizeof(Bloque);
    string route_bloque_index="DiskManager/Data_Index/Disco_"+to_string(num_id_disco)+"_index/bloques_index";

    ifstream archivo(route_bloque_index, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Bloque *ptr_bloque=new Bloque();
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_bloque)), sizeof(Bloque));
        cout<<"Datos leidos del archivo: "<<route_bloque_index<<endl;
        return (*ptr_bloque);
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_bloque_index<<endl;
    }
    archivo.close();
}


//-------------------------PRINT PARTS INDEX--------------------------
void SistemaOperativo::print_disco_header(int num_id_disco){
    Disco_Header disco_h;
    string disco_name="Disco_"+to_string(num_id_disco);
    string final_route_disco_header="DiskManager/Data_Index/"+disco_name+"_index/Disco_header.bin";
    ifstream archivo(final_route_disco_header, ios::binary);
    if (archivo.is_open()) {
        archivo.seekg(0);
        archivo.read((char*)&(disco_h), sizeof(Disco_Header));

        if (!archivo.fail()) {
            disco_h.print_info_magnetic_disk();
        } 
        else 
        {
            cout << "Error al leer el archivo binario: " << final_route_disco_header << endl;
        }
    } 
    else 
    {
        cout << "Error al abrir el archivo binario para lectura: " << final_route_disco_header << endl;
    }
    archivo.close();
}

void SistemaOperativo::print_disco_index(int num_id_disco){
    Disco_index disco_index;
    string disco_name="Disco_"+to_string(num_id_disco);
    string final_route_disco="DiskManager/Data_Index/"+disco_name+"_index/disco_index.bin";
    ifstream archivo(final_route_disco, ios::binary);
    archivo.seekg(0);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(disco_index)), sizeof(Disco_index));
        disco_index.print_data_disco();
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para lectura."<<final_route_disco<<endl;
    }
}

void SistemaOperativo::print_plato_index(int num_id_disco){

    Disco_Header *disk_header=new Disco_Header();
    (*disk_header)=get_disco_header(num_id_disco);
    int num_platos=(*disk_header).get_num_platos_total();

    string disco_name="Disco_"+to_string(num_id_disco);
    string final_route_plato="DiskManager/Data_Index/"+disco_name+"_index/platos_index.bin";
    ifstream archivo(final_route_plato, ios::binary);

    int ubication_read=0;
    for (int i = 0; i < num_platos; i++)
    {
        archivo.seekg(ubication_read);
        Plato_Index plato_index;
        if (archivo.is_open()) 
        {
            archivo.read(reinterpret_cast<char*>(&plato_index), sizeof(Plato_Index));
            plato_index.print_data_Plato();
            ubication_read=ubication_read+sizeof(Plato_Index);
        } 
        else 
        {
            cout<<"Error al abrir el archivo binario para lectura."<<final_route_plato<<endl;
        }
    }
    
}

void SistemaOperativo::print_superficie_index(int num_id_disco){

    Disco_Header *disk_header=new Disco_Header();
    (*disk_header)=get_disco_header(num_id_disco);
    int num_superficies=(*disk_header).get_num_superficies_total();

    string disco_name="Disco_"+to_string(num_id_disco);
    string route_superficie="DiskManager/Data_Index/"+disco_name+"_index/superficies_index.bin";

    ifstream archivo(route_superficie, ios::binary);

    int ubication_read_bin=0;

    for (int i = 0; i < num_superficies; i++)
    {
        archivo.seekg(ubication_read_bin);
        Superficie_Index superficie;
        if (archivo.is_open()) {
            archivo.read(reinterpret_cast<char*>(&superficie), sizeof(Superficie_Index));
            superficie.print_data_superficie();
            ubication_read_bin=ubication_read_bin+sizeof(Superficie_Index);
        } 
        else 
        {
            cout<<"Error al abrir el archivo binario para lectura."<<route_superficie<<endl;
        }
    }
    archivo.close();
}

void SistemaOperativo::print_pista_index(int num_id_disco){

    Disco_Header *disk_header=new Disco_Header();
    (*disk_header)=get_disco_header(num_id_disco);
    int num_pistas=(*disk_header).get_num_pistas_total();

    string disco_name="Disco_"+to_string(num_id_disco);
    string route_pista="DiskManager/Data_Index/"+disco_name+"_index/pistas_index.bin";

    ifstream archivo(route_pista, ios::binary);
    int ubication_read_bin=0;

    for (int i = 0; i < num_pistas; i++)
    {
        archivo.seekg(ubication_read_bin);

        Pista_Index pista;
        if (archivo.is_open()) {
            archivo.read(reinterpret_cast<char*>(&pista), sizeof(Pista_Index));
            pista.print_data_pista();
            ubication_read_bin=ubication_read_bin+sizeof(Pista_Index);
        } 
        else 
        {
            cout<<"Error al abrir el archivo binario para lectura."<<route_pista<<endl;
        }
    }
    
    archivo.close();
}

void SistemaOperativo::print_sector_index(int num_id_disco){

    Disco_Header *disk_header=new Disco_Header();
    (*disk_header)=get_disco_header(num_id_disco);
    int num_sectores=(*disk_header).get_num_sectores_total();

    string disco_name="Disco_"+to_string(num_id_disco);
    string route_sector="DiskManager/Data_Index/"+disco_name+"_index/sectores_index.bin";

    ifstream archivo(route_sector, ios::binary);
    int ubication_read_bin=0;

    for (int i = 0; i < num_sectores; i++)
    {
        archivo.seekg(ubication_read_bin);

        Sector_Index sector;
        if (archivo.is_open()) {
            archivo.read(reinterpret_cast<char*>(&sector), sizeof(Sector_Index));
            sector.print_data_sector();
            ubication_read_bin=ubication_read_bin+sizeof(Sector_Index);
        } 
        else 
        {
            cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
        }
    }
    archivo.close();
}

void SistemaOperativo::print_bloque_index(int num_id_disco){

    Disco_Header *disk_header=new Disco_Header();
    (*disk_header)=get_disco_header(num_id_disco);
    int num_bloques=(*disk_header).get_num_bloques_total();

    string disco_name="Disco_"+to_string(num_id_disco);
    string route_sector="DiskManager/Data_Index/"+disco_name+"_index/bloques_index.bin";

    ifstream archivo(route_sector, ios::binary);
    int ubication_read_bin=0;

    for (int i = 0; i < num_bloques; i++)
    {
        archivo.seekg(ubication_read_bin);
        Bloque bloque;
        if (archivo.is_open()) {
            archivo.read(reinterpret_cast<char*>(&bloque), sizeof(Bloque));
            bloque.print_data_bloque();
            ubication_read_bin=ubication_read_bin+sizeof(Bloque);
        } 
        else 
        {
            cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
        }
    }
    
    archivo.close();
}



//-----------------------Read Others-------------------------
void SistemaOperativo::read_header_bloque(int _num_bloque){
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

Disco_Header& SistemaOperativo::get_disco_magnetic_info(){
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

headerSector& SistemaOperativo::get_header_bloque(int _num_bloque){
    int ubication_read_bin=0;
    string route_sector="DiskManager/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    headerSector *ptr_header_bloque=new headerSector();
    if (archivo.is_open()) 
    {
        archivo.read(reinterpret_cast<char*>(&(*ptr_header_bloque)), sizeof(headerSector));
        // cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para get header bloque."<<route_sector<<endl;
    }
    archivo.close();
    return (*ptr_header_bloque);
}

int SistemaOperativo::get_num_bloque_espacio_libre(int _space_necesitado){
    //Para leer el header de los bloques
    headerSector *ptr_header_bloque=new headerSector();

    //Primero quiero saber cuántos bloques hay
    SistemaOperativo brazo;
    Disco_Header *ptr_disco_magnetico=new Disco_Header();
    (*ptr_disco_magnetico)=brazo.get_disco_magnetic_info();
    int num_bloques=(*ptr_disco_magnetico).get_num_bloques_total();
    for (size_t i = 1; i <=num_bloques; i++)
    {
        (*ptr_header_bloque)=brazo.get_header_bloque(i);
        int space_libre=(*ptr_header_bloque).getCantBytesRestantesSector();
        if (_space_necesitado<space_libre)
        {
            return i;
        }
        
    }
    
    
}

int SistemaOperativo::calcular_espacio_necesario(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    
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
void SistemaOperativo::caminar_por_slots_tupla_variable_data_insertar_slot(Slot &slot_tupla_enviado, int num_bloque, int direc_slot_escrito){
    // SistemaOperativo brazo;
    // headerSector *ptr_header_bloque=new headerSector();
    // (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque);//obtenemos info del header del bloque

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
        SistemaOperativo brazo;
        headerSector *ptr_header_bloque=new headerSector();
        (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque);//obtenemos el header del bloque

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

void SistemaOperativo::insert_variable_length_data(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    SistemaOperativo brazo;
    headerSector *ptr_header_bloque=new headerSector();
    int espacio_ocuparemos=brazo.calcular_espacio_necesario(_map_atributos,_vec_atributos,_vec_valores_ingresar);
    //AHORA
    // cout<<"obtenemos el bloque con espacio libre"<<endl;
    cout<<"espacio a ocupar: "<<espacio_ocuparemos<<endl;
    int num_bloque_space=brazo.get_num_bloque_espacio_libre(espacio_ocuparemos);
    cout<<"bloque donde se escribira: "<<num_bloque_space<<endl;

    //YA TENEMOS EL HEADER DEL BLOQUE
    (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque_space);

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
            SistemaOperativo brazo;
            headerSector *ptr_header_bloque=new headerSector();
            (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque_space);//obtenemos el header del bloque
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

void SistemaOperativo::leer_slot_tupla_atributos(Slot &slot,int num_bloque){
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

void SistemaOperativo::caminar_por_slots_tupla_variable_data_imprimir(int num_bloque,int direc_slot_escrito){
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

void SistemaOperativo::read_variable_length_data_per_block(int num_block){
    SistemaOperativo brazo;
    headerSector *ptr_header_bloque=new headerSector();
    (*ptr_header_bloque)=brazo.get_header_bloque(num_block);

    int direccion_primer_slot=(*ptr_header_bloque).getDirecFirstVariableRecord();
    caminar_por_slots_tupla_variable_data_imprimir(num_block,direccion_primer_slot);
}

void SistemaOperativo::read_variable_length_data(int _id_record){
    // int ubication_read;
    // SistemaOperativo brazo;
    // headerSector *ptr_header_bloque=new headerSector();

}

//----------------------WRITE FIXED DATA---------------------

void SistemaOperativo::insertFixedLengthData(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    SistemaOperativo brazo;
    headerSector *ptr_header_bloque=new headerSector();
    //primero necesitamos saber cuánto espacio ocuparemos
    int espacio_ocuparemos;
    //obtenemos el bloque con espacio libre
    int num_bloque_space=brazo.get_num_bloque_espacio_libre(espacio_ocuparemos);
    (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque_space);//necesitamos algun bloque
}

//----------------------READ FIXED DATA-----------------


//----------------- ESQUEMA DATA ------------------
void SistemaOperativo::crear_esquema_tabla(string _name_archivo){
    /*Quiero obtener el número o tamaño de cada
    atributo*/
    
    //ABRIR EL ARCHIVO CSV
    cout<<"name_archivo"<<_name_archivo<<endl;
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
        int contRegistrosPrueba=0;
        
        while (contRegistrosPrueba!=10 && getline(file_open,linea))//leeremos los primeros 10
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
            contRegistrosPrueba++;
        }
        file_open.close();


        //CREAR EL ESQUEMA DE LA TABLA TXT
        string route_archivo_crear="DiskManager/Data/esquema_"+_name_archivo+".txt";
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

void SistemaOperativo::leer_esquema_tabla(string _name_tabla){
    string route_archivo_leer="DiskManager/Data/esquema_"+_name_tabla+".txt";
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

MapaPares& SistemaOperativo::get_esquema_tabla(string _name_tabla){
    string route_archivo_leer="DiskManager/Data/esquema_"+_name_tabla+".txt";
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
                // int cont_detector_first_atributo=1;
                
                while (getline(iss,_atributo,',')) // después de cada espacio ' '
                {
                    // if (cont_detector_first_atributo==1)
                    // {
                    //     if (tolower(_atributo)==)
                    //     {
                    //         /* code */
                    //     }
                        
                    // }
                    // cont_detector_first_atributo++;
                    
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

vector<string>& SistemaOperativo::get_vector_atributos(string _name_tabla){
    
    string route_archivo_leer="DiskManager/Data/esquema_"+_name_tabla+".txt";
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

void SistemaOperativo::mostrar_esquema_map(MapaPares& map_atributos,vector<string> &vector_ordenado_atributos){
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

string SistemaOperativo::decidir_tipo_dato(string &value)
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


//--------------- WriteData ------------------
void SistemaOperativo::ingresarTablaDesdeArchivoCSV(string nombreArchivo){
    //Primero creamos el esquema de la tabla a leer
    crear_esquema_tabla(nombreArchivo);
    // de acuerdo a esquema e ir ingresando
    // this->brazoDiscoMagnetico;


}




