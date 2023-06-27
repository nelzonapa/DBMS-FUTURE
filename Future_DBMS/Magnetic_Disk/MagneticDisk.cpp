#include "MagneticDisk.h"
MagneticDisk::MagneticDisk(){
    this->id_disk_magnetic=1;
    this->num_platos=0;
    this->capacidad_total_magneticDisk=0;
    this->num_sectores=0;
    this->num_pistas=0;
    this->capacidad_usada=0;
}

MagneticDisk::MagneticDisk(int _num_platos,int _capacidad, int _num_sectors,int _num_pistas){
    this->id_disk_magnetic=1;
    this->num_platos=_num_platos;
    this->capacidad_total_magneticDisk=_capacidad;
    this->num_sectores=_num_sectors;
    this->num_pistas=_num_pistas;
    this->capacidad_usada=0;
    /*
        OBSERVACIÓN:
        * En esta capacidad total incluimos que las tablas index de los diferentes puntos 
            en los que la usamos, tendrán su espacio MUY APARTE de las Tablas o Datos que se tengan:
            
            * Capacidad_datos_tablas = capacidad_total_magneticDisk -  Peso_total_tablas_index
    */
    //agregamos la cantidad de Platos pedidos y otros
    agregar_platos_index_data();
    agregar_superficies_index_data();
    agregar_sector_index_data();
    agregar_bloques_index_data();
}
MagneticDisk::~MagneticDisk(){}

void MagneticDisk::agregar_platos_index_data(){
    R_W_Head header;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_plato=capacidad_total_magneticDisk/num_platos;
    // cout<<"peso plato ="<<peso_plato;
    for (int i = 1; i <=num_platos; i++)
    {
        Plato_index new_plato(i,direccion_bytes,peso_plato);    //le enviamos al plato su capacidad con peso_plato
        header.write_data_platos_index(new_plato,acumulador_bytes); //Importante para caminar en el archivo binario
        /*
        cada plato tiene un peso y ello nos servirá como direccion
            * peso_plato almacena el peso correspondiente de acuerdo
            a la capacidad total del disco magnético y cuántos platos
            existen 👇
        */
        direccion_bytes+=peso_plato;  
        /*
            La ubicación en bytes de cada objeto Plato, este nos ayuda a caminar, por el archivo binario
        */
        acumulador_bytes+=sizeof(Plato_index);
        new_plato.~Plato_index();//limpio memoria
    }
    header.~R_W_Head();

}

void MagneticDisk::agregar_superficies_index_data(){
    R_W_Head header_2;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_superficie=((capacidad_total_magneticDisk/num_platos)/2);
    // cout<<"peso plato ="<<peso_superficie;
    for (int i = 1; i <=(num_platos*2); i++)
    {
        Superficie_index new_sup_index(i,direccion_bytes,peso_superficie);    //le enviamos al plato su capacidad con peso_superficie
        // new_sup_index.print_data_sup_index();
        header_2.write_superficie_index(new_sup_index,acumulador_bytes); //Importante para caminar en el archivo binario
        /*
        cada plato tiene un peso y ello nos servirá como direccion
            * peso_superficie almacena el peso correspondiente de acuerdo
            a la capacidad total del disco magnético y cuántos platos
            existen 👇
        */
        direccion_bytes+=peso_superficie;  
        /*
            La ubicación en bytes de cada objeto Plato, este nos ayuda a caminar, por el archivo binario
        */
        acumulador_bytes+=sizeof(Superficie_index);
        // cout<<"acumulador bytes: "<<acumulador_bytes<<endl;
        new_sup_index.~Superficie_index();//limpio memoria
    }
    header_2.~R_W_Head();
}

void MagneticDisk::agregar_sector_index_data(){
    R_W_Head header_2;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    //obtenemos la capacidad de cada plato
    int peso_superficie=((capacidad_total_magneticDisk/num_platos)/2);
    int peso_sector=(peso_superficie/num_sectores);// hallar el peso del sector
    for (int i = 1; i <=(num_platos*2)*num_sectores; i++)
    {
        Sector_index new_sec_index(i,direccion_bytes,peso_sector);    //le enviamos al plato su capacidad con peso_sector
        header_2.write_data_sector_index(new_sec_index,acumulador_bytes); //Importante para caminar en el archivo binario
        /*
        cada plato tiene un peso y ello nos servirá como direccion
            * peso_sector almacena el peso correspondiente de acuerdo
            a la capacidad total del disco magnético y cuántos platos
            existen 👇
        */
        direccion_bytes+=peso_sector;  
        /*
            La ubicación en bytes de cada objeto Plato, este nos ayuda a caminar, por el archivo binario
        */
        acumulador_bytes+=sizeof(Sector_index);
        new_sec_index.~Sector_index();//limpio memoria
    }
    header_2.~R_W_Head();
}

void MagneticDisk::agregar_bloques_index_data(){
    R_W_Head header_2;
    int acumulador_bytes=0;    //este acumula los bytes que ocupa el objeto en el archivo
    int direccion_bytes=0;    //dirección 0 en bytes
    int peso_superficie=((capacidad_total_magneticDisk/num_platos)/2);
    int peso_sector=(peso_superficie/num_sectores);//peso del sector
    int peso_block=peso_sector/num_pistas;
    for (int i = 1; i <=(num_platos*2)*num_sectores*num_pistas; i++)
    {
        Block_index new_block_index(i,direccion_bytes,peso_block);    //le enviamos al plato su capacidad con peso_block
        header_2.write_data_Block_index(new_block_index,acumulador_bytes); //Importante para caminar en el archivo binario
        /*
        cada plato tiene un peso y ello nos servirá como direccion
            * peso_block almacena el peso correspondiente de acuerdo
            a la capacidad total del disco magnético y cuántos platos
            existen 👇
        */
        direccion_bytes+=peso_block;  
        /*
            La ubicación en bytes de cada objeto Plato, este nos ayuda a caminar, por el archivo binario
        */
        acumulador_bytes+=sizeof(Block_index);
        new_block_index.~Block_index();//limpio memoria
    }
    header_2.~R_W_Head();
}

void MagneticDisk::modificar_cap_total(int _cap_total){
    this->capacidad_total_magneticDisk=_cap_total;
    //se actualiza automáticamente
    agregar_platos_index_data();
    return;
}

void MagneticDisk::modificar_num_platos(int _num_platos){
    this->num_platos=_num_platos;
    //como modifica la cantida de platos
    agregar_platos_index_data();
    return;
}

void MagneticDisk::modificar_cantidad_usada(int _new_cant){
    this->capacidad_usada=_new_cant;
}


// -------------------------------------------------------------------------------------------

void MagneticDisk::print_info_magentic_disk(){
    cout<<endl<<"Capacidad del disco magnetico: "<<this->capacidad_total_magneticDisk<<endl;
    cout<<endl<<"Tamaño del FILE ingresado: "<<this->capacidad_usada<<endl;
    cout<<endl<<"Numero de objetos en el FILE: "<<this->capacidad_usada/sizeof(Passenger_titanic)<<endl;
    cout<<endl<<"El peso de cada objeto es: "<<sizeof(Passenger_titanic)<<endl;
    print_info_platos_index();
    print_data_superficie_index();
    print_data_sector_index();
    print_data_block_index();
    print_blocks_info();
}

void MagneticDisk::print_info_platos_index(){
    std::cout<<endl<<"\t Platos:"<<endl;
    std::cout << "id_plato\tdirec_plato\tpeso_bytes_plato\t"<< std::endl;
    R_W_Head header;
    int direccion=0;
    for (int i = 1; i <=num_platos; i++)
    {
        header.read_data_platos_index(direccion);
        direccion+=sizeof(Plato_index);//ubicación en bytes de cada objeto sector
    }
}

void MagneticDisk::print_data_superficie_index(){
    std::cout<<endl<<"\t Superficies:"<<endl;
    std::cout << "id_superficie\tdirec_superficie\tpeso_bytes_superficie\t"<< std::endl;
    R_W_Head header;
    int direccion=0;
    // cout<<"peso de Superficie_index= "<<sizeof(Superficie_index);
    // cout<<"Direccion dada= "<<direccion;
    // header.read_data_superficie_index(direccion);
    for (int i = 1; i <=(num_platos*2); i++)
    {
        header.read_data_superficie_index(direccion);
        direccion+=sizeof(Superficie_index);//ubicación en bytes de cada objeto sector
    }
    header.~R_W_Head();
}

void MagneticDisk::print_data_sector_index(){
    std::cout<<endl<<"\t Sectores:"<<endl;
    std::cout << "id_sector\tdirec_sector\tpeso_bytes_sector\t"<< std::endl;
    R_W_Head header;
    int direccion=0;
    int _num_sectores=(num_platos*2*num_sectores);
    for (int i = 1; i <=_num_sectores; i++)
    {
        header.read_data_sector_index(direccion);
        direccion+=sizeof(Sector_index);//ubicación en bytes de cada objeto sector
    }
    header.~R_W_Head();
}

void MagneticDisk::print_data_block_index(){
    std::cout<<endl<<"\t Bloques:"<<endl;
    std::cout << "id_bloque\tdirec_bloque\tpeso_bytes_bloque\t"<< std::endl;
    R_W_Head header;
    int direccion=0;
    int _num_sectores=(num_platos*2*num_sectores);
    int _num_bloques=_num_sectores*num_pistas;
    for (int i = 1; i <=_num_bloques; i++)
    {
        header.read_data_Block_index(direccion);
        direccion+=sizeof(Block_index);//ubicación en bytes de cada objeto sector
    }
    header.~R_W_Head();
}

void MagneticDisk::print_blocks_info(){
    int cantidad_bloques=num_platos*2*num_pistas*num_sectores;
    int peso_block=(((capacidad_total_magneticDisk/num_platos)/2)/num_sectores)/num_pistas;
    cout<<"Cantidad de bloques existentes: "<<cantidad_bloques<<endl;
    cout<<"Cantidad de objetos por bloques: "<<peso_block/sizeof(Passenger_titanic)<<endl;
}

void MagneticDisk::print_data_passengers(){
    std::cout<<endl<<"\t Pasajeros:"<<endl;
    std::cout <<"passenger_id\tsurvived\tpassenger_class\tname\t";
    cout<<"\tsex\tage\tnum_siblings\tnum_parents\tticket\tpassenger_fare";
    cout<<"\tpassenger_cabina\tembarked"<<endl;
    R_W_Head header;
    int direccion=0;
    int peso_block=(((capacidad_total_magneticDisk/num_platos)/2)/num_sectores)/num_platos;
    int cantidad_bloques=((num_platos*2)*num_sectores)*num_platos;
    int num_objetos_total=this->capacidad_usada/sizeof(Passenger_titanic);
    for (int i = 1; i <=num_objetos_total; i++)//cantidad de objetos
    {   
        header.read_data_fixed_block(direccion);
        direccion+=sizeof(Passenger_titanic);//ubicación en bytes de cada objeto sector
    }
    header.~R_W_Head();
}

void MagneticDisk::print_data_passengers_filtro(string signo,int id){
    std::cout<<endl<<"\t Pasajeros:"<<endl;
    std::cout <<"passenger_id\tsurvived\tpassenger_class\tname\t";
    cout<<"\tsex\tage\tnum_siblings\tnum_parents\tticket\tpassenger_fare";
    cout<<"\tpassenger_cabina\tembarked"<<endl;
    R_W_Head header;
    int direccion1=0;
    int direccion2=id*sizeof(Passenger_titanic)-sizeof(Passenger_titanic);
    int peso_block=(((capacidad_total_magneticDisk/num_platos)/2)/num_sectores);
    int cantidad_bloques=((num_platos*2)*num_sectores)*num_pistas;
    if (signo=="<")
    {
        for (int i = 0; i <id; i++)
        {   
            header.read_data_fixed_block(direccion1);
            direccion1+=sizeof(Passenger_titanic);//ubicación en bytes de cada objeto sector
        }
    }
    else if (signo==">")
    {
        int num_objetos_total=this->capacidad_usada/sizeof(Passenger_titanic);
        for (int i = id; i <=num_objetos_total; i++)
        {   
            header.read_data_fixed_block(direccion2);
            direccion2+=sizeof(Passenger_titanic);//ubicación en bytes de cada objeto sector
        }
    }
    else if (signo=="=")
    {
        header.read_data_fixed_block(direccion2);
    }
    else{
        cout<<"Datos no reconocidos"<<endl;
    }
    
    header.~R_W_Head();
}



int MagneticDisk::return_n_platos(){
    return this->num_platos;
}
int MagneticDisk::return_n_sectores(){
    return this->num_sectores;
}
int MagneticDisk::return_n_pistas(){
    return this->num_pistas;
}
int MagneticDisk::return_n_objetos(){
    return (this->capacidad_usada/sizeof(Passenger_titanic));
}

int MagneticDisk::return_capacity_disco_mag(){
    return (this->capacidad_total_magneticDisk);
}

int MagneticDisk::return_cant_objects_block(){
    int peso_block=(((capacidad_total_magneticDisk/num_platos)/2)/num_sectores)/num_pistas;
    int cant_objects_por_bloque=peso_block/sizeof(Passenger_titanic);
    return cant_objects_por_bloque;
}