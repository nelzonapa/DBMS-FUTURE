#include "ReadWriteHead.h"

R_W_Head::R_W_Head(){}
R_W_Head::~R_W_Head(){}



//VARIABLE-LENGTH

//obtener el null bit map del objeto
char* R_W_Head::get_nullbitmap_record(Estudiante &student){
    int cantidad_atributos=student.cant_atributos+1;//más el caracter de fin de lectura '\0'
    char* nullbitmap=new char[cantidad_atributos];
    nullbitmap[cantidad_atributos]='\0';

    if (sizeof(student.id)==0)
    {
        nullbitmap[0]='1';
    }
    if (sizeof(student.id)!=0)
    {
        nullbitmap[0]='0';
    }

    if (sizeof(student.edad)==0)
    {
        nullbitmap[1]='1';
    }
    if (sizeof(student.edad)!=0)
    {
        nullbitmap[1]='0';
    }

    if ((student.name)=="")//en ascci 32 representa al vacío
    {
        nullbitmap[2]='1';
    }
    if ((student.name)!="")
    {
        nullbitmap[2]='0';
    }

    if (sizeof(student.cui)==0)
    {
        nullbitmap[3]='1';
    }
    if (sizeof(student.cui)!=0)
    {
        nullbitmap[3]='0';
    }

    if ((student.escuela)=="")
    {
        nullbitmap[4]='1';
    }
    if ((student.escuela)!="")
    {
        nullbitmap[4]='0';
    }
    // cout<<"new nullbitmap: "<<nullbitmap<<endl;
    return nullbitmap;
}

//Escribir registros variable-length
void R_W_Head::write_variable_data_block(Estudiante &student, int capacidad_disco){
    int longitud=0;
    const char* null_bitmap=get_nullbitmap_record(student);
    
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);
    

    Slot slot_id;
    Slot slot_edad;
    Slot slot_name;
    Slot slot_cui;
    Slot slot_escuela;

    if (!file.is_open())//1era vez
    {
        std::cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \n..."<<endl;
        fstream file("DataBase.bin",ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(capacidad_disco-1);
        file.write("", 1);
        //Para que se cree con la capacidad correcta

        /*AL LEER CUALQUIER DATA, primero agregará el header*/
        // R_W_Head head; 
        Header Head_file_principal;
        Head_file_principal.set_direc_free_space_variable(capacidad_disco);//al inicio
        write_header_file_general(Head_file_principal);
        file.seekp(capacidad_disco, std::ios::beg);//nos ubicamos al final del archivo desde el inicio
        
        int ubication;
        // int begin=(strlen(null_bitmap)-1);

        for (int i=(strlen(null_bitmap)-1); i>=0; i--)    //strlen(nullbitmap) no cuenta el termino de finde leida '\0'
        {
            ubication=Head_file_principal.get_direc_free_space_variable();
            if (null_bitmap[i]==0 && i==0)
            {
                longitud=longitud+sizeof(student.id);
                slot_id.set_offset(ubication-sizeof(student.id));
                ubication=ubication-sizeof(student.id);
                slot_id.set_length(sizeof(student.id));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.id)), sizeof(student.id));

                //Actualizamos HEADER principal
                Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general(Head_file_principal);
                
                std::cout<<"write1"<<endl;
                // file.seekp(ubication);
            }
            if (null_bitmap[i]==0 && i==1)
            {
                longitud=longitud+sizeof(student.edad);
                slot_id.set_offset(ubication-sizeof(student.edad));
                ubication=ubication-sizeof(student.edad);
                slot_id.set_length(sizeof(student.edad));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.edad)), sizeof(student.edad));

                //Actualizamos HEADER principal
                Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general(Head_file_principal);

                std::cout<<"write2"<<endl;
            }
            if (null_bitmap[i]==0 && i==2)
            {
                longitud=longitud+strlen(student.name);//strlen(palabra)*sizeof(char), pero es 1 byte, asi que no hay problema
                slot_id.set_offset(ubication-strlen(student.name));
                ubication=ubication-strlen(student.name);
                slot_id.set_length(strlen(student.name));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.name)), strlen(student.name));

                //Actualizamos HEADER principal
                Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general(Head_file_principal);

                std::cout<<"write3"<<endl;
            }
            if (null_bitmap[i]==0 && i==3)
            {
                longitud=longitud+sizeof(student.cui);
                slot_id.set_offset(ubication-sizeof(student.cui));
                ubication=ubication-sizeof(student.cui);
                slot_id.set_length(sizeof(student.cui));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.cui)), sizeof(student.cui));

                //Actualizamos HEADER principal
                Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general(Head_file_principal);

                std::cout<<"write4"<<endl;
            }
            if (null_bitmap[i]==0 && i==4)
            {
                longitud=longitud+strlen(student.escuela);
                slot_id.set_offset(ubication-strlen(student.escuela));
                ubication=ubication-strlen(student.escuela);
                slot_id.set_length(strlen(student.escuela));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.escuela)), strlen(student.escuela));

                //Actualizamos HEADER principal
                Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general(Head_file_principal);

                std::cout<<"write5"<<endl;
            }
            //otros casos no hacer nada, es decir saltarnos
        }

        ubication=Head_file_principal.get_direc_free_space_variable();
        
        //Ahora escribimos los slots del registro

        //ESCUELA
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_escuela,sizeof(Slot));
        Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
        
        //NAME
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_name,sizeof(Slot));
        Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito

        //EDAD
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_edad,sizeof(Slot));
        Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito

        //ID
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_id,sizeof(Slot));
        Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito

        write_header_file_general(Head_file_principal);
        std::cout<<"Slots escritos"<<endl;

        //Ahora introducimos el nullbitmap
        longitud=longitud+strlen(null_bitmap);
        ubication=ubication-strlen(null_bitmap);
        file.seekp(ubication);
        file.write(reinterpret_cast<char *>(&null_bitmap),strlen(null_bitmap));
        std::cout<<"nullbitmap escrito"<<endl;
        Head_file_principal.set_direc_free_space_variable(ubication);//ahora después de haber escrito
        write_header_file_general(Head_file_principal);

        //Actualizamos HEADER GENERAL del FILE
        Head_file_principal.set_num_records_general(Head_file_principal.get_num_records_general()+1);
        Head_file_principal.set_num_records_variable(Head_file_principal.get_num_records_variable()+1);
        Head_file_principal.set_ptr_direc_end_fixed(sizeof(Header));
        Head_file_principal.set_direc_free_space_variable(ubication);
        write_header_file_general(Head_file_principal);

        /*----AHORA PARA LOS SLOTS_INDEX----*/

        //UBICATION, ya tenemos el OFFSET del REGISTRO INGRESADO
        //LONGITUD, ya tenemos el LENGTH del REGISTRO INGRESADO
        Slot Slot_Tuple;
        Slot_Tuple.set_length(longitud);
        Slot_Tuple.set_offset(ubication);

        //Falta actualizar la dirección final del HEADER GENERAL:
        // (*H_file).set_direc_free_space_variable(ubication);


        //PRIMERO CREAMOS EL HEAD DE LA TABLA SLOTS_INDEX
        Head_slot_index *ptr_indexHS=new Head_slot_index();
        // (*ptr_indexHS).set_direc_final_index(sizeof(Head_slot_index));
        write_head_slots_index((*ptr_indexHS));

        int last_place=(*ptr_indexHS).get_direc_final_index();
        cout<<"last_place= "<<last_place<<endl;

        //Escribe el slot en la última parte, claro que tendremos que modificar para delete e insert
        write_data_slot_index(Slot_Tuple,last_place);
        std::cout<<"slot dentro de slot index"<<endl;
        //Actualizamos el HEADER_SLOTS_INDEX
        (*ptr_indexHS).set_num_slots_index((*ptr_indexHS).get_num_slots_index()+1);
        (*ptr_indexHS).set_direc_final_index((*ptr_indexHS).get_direc_final_index()+sizeof(Slot));
        write_head_slots_index((*ptr_indexHS));

        file.close();
    }
    else//primera vez y demás
    {
        Header *H_file_general=get_header_file();
        int ubication;
        // std::cout<<"ubication -case else-: "<<ubication<<endl;
        // int begin=(strlen(null_bitmap)-1);
        for (int i=(strlen(null_bitmap)-1); i>=0; i--)
        {
            int ubication=(*H_file_general).get_direc_free_space_variable();//del HEADER GENERAL DEL FILE

            if (null_bitmap[i]=='0' && i==0)
            {
                // std::cout<<"punto1.1"<<endl;
                longitud=longitud+sizeof(student.id);
                slot_id.set_offset(ubication-sizeof(student.id));
                ubication=ubication-sizeof(student.id);
                slot_id.set_length(sizeof(student.id));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.id)), sizeof(student.id));
                
                //Actualizamos HEADER principal
                (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general((*H_file_general));
                // file.seekp(ubication);
            }
            if (null_bitmap[i]=='0' && i==1)
            {
                // cout<<"punto1.2"<<endl;
                longitud=longitud+sizeof(student.edad);
                slot_id.set_offset(ubication-sizeof(student.edad));
                ubication=ubication-sizeof(student.edad);
                slot_id.set_length(sizeof(student.edad));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.edad)), sizeof(student.edad));

                //Actualizamos HEADER principal
                (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general((*H_file_general));
            }
            if (null_bitmap[i]=='0' && i==2)
            {
                // cout<<"punto1.3"<<endl;
                longitud=longitud+strlen(student.name);
                slot_id.set_offset(ubication-strlen(student.name));
                ubication=ubication-strlen(student.name);
                slot_id.set_length(strlen(student.name));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.name)), strlen(student.name));

                //Actualizamos HEADER principal
                (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general((*H_file_general));
            }
            if (null_bitmap[i]=='0' && i==3)
            {
                // cout<<"punto1.4"<<endl;
                longitud=longitud+sizeof(student.cui);
                slot_id.set_offset(ubication-sizeof(student.cui));
                ubication=ubication-sizeof(student.cui);
                slot_id.set_length(sizeof(student.cui));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.cui)), sizeof(student.cui));

                //Actualizamos HEADER principal
                (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general((*H_file_general));
            }
            if (null_bitmap[i]=='0' && i==4)
            {
                // cout<<"punto1.5"<<endl;
                longitud=longitud+strlen(student.escuela);
                slot_id.set_offset(ubication-strlen(student.escuela));
                ubication=ubication-strlen(student.escuela);
                slot_id.set_length(strlen(student.escuela));

                file.seekp(ubication);
                file.write(reinterpret_cast<char*>(&(student.escuela)), strlen(student.escuela));

                //Actualizamos HEADER principal
                (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
                write_header_file_general((*H_file_general));
            }
            else{
                std::cout<<"punto exception"<<endl;
            }
            //otros casos no hacer nada, es decir saltarnos
        }
        ubication=((*H_file_general).get_direc_free_space_variable());
        std::cout<<"punto2"<<endl;
        //Ahora escribimos los slots del registro de atras a adelante
        
        //ESCUELA
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_escuela,sizeof(Slot));
        (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito

        //CUI
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_cui,sizeof(Slot));
        (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
        
        //NAME
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_name,sizeof(Slot));
        (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito

        //EDAD
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_edad,sizeof(Slot));
        (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito

        std::cout<<"punto2.1"<<endl;

        //ID
        longitud=longitud+sizeof(Slot);
        ubication=ubication-sizeof(Slot);
        file.seekp(ubication);
        file.write((char *)&slot_id,sizeof(Slot));
        (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito

        write_header_file_general((*H_file_general));
        std::cout<<"Slots escritos"<<endl;

        //Ahora introducimos el NULLBITMAP
        longitud=longitud+strlen(null_bitmap);
        ubication=ubication-strlen(null_bitmap);
        file.seekp(ubication);
        file.write(reinterpret_cast<char *>(&null_bitmap),strlen(null_bitmap));
        (*H_file_general).set_direc_free_space_variable(ubication);//ahora después de haber escrito
        write_header_file_general((*H_file_general));


        //Actualizamos HEADER GENERAL del FILE
        (*H_file_general).set_num_records_general((*H_file_general).get_num_records_general()+1);
        (*H_file_general).set_num_records_variable((*H_file_general).get_num_records_variable()+1);
        (*H_file_general).set_direc_free_space_variable(ubication);
        write_header_file_general((*H_file_general));

        /*----AHORA PARA LOS SLOTS_INDEX----*/

        //UBICATION, ya tenemos el OFFSET del REGISTRO INGRESADO
        //LONGITUD, ya tenemos el LENGTH del REGISTRO INGRESADO
        Slot Slot_Tuple;
        Slot_Tuple.set_length(longitud);
        Slot_Tuple.set_offset(ubication);

        //PRIMERO obtenemos datos del HEADER_INDEX_SLOT
        Head_slot_index *ptr_indexHS=get_head_slots_index();
        // (*ptr_indexHS).set_direc_final_index(sizeof(Head_slot_index));
        // write_head_slots_index((*ptr_indexHS));

        int last_place=(*ptr_indexHS).get_direc_final_index();
        //Escribe el slot en la última parte, claro que tendremos que modificar para delete e insert
        // cout<<"punto3"<<endl;
        write_data_slot_index(Slot_Tuple,last_place);
        std::cout<<"slot dentro de slot index"<<endl;

        //Actualizamos el HEADER_SLOTS_INDEX
        (*ptr_indexHS).set_num_slots_index((*ptr_indexHS).get_num_slots_index()+1);
        (*ptr_indexHS).set_direc_final_index((*ptr_indexHS).get_direc_final_index()+sizeof(Slot));
        write_head_slots_index((*ptr_indexHS));
        

        // file.close();
        delete[] null_bitmap;
        file.close();
    }
    
}

Estudiante* R_W_Head::read_variable_data_block(Slot &_slot){
    int ubication_read=_slot.get_offset();//apunta desde done inicia el slot
    int length_read=_slot.get_length();//cuánto de bytes debe recorrer e irá recorriendo hasta llegar a 0

    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error no se tiene Archivo DataBase.bin para read_variable_data_block"<<endl;
    }
    else{
        //-----Primero leemos el NULLBITMAP-----
        file.seekg(ubication_read);
        int size_nullbitmap=5;//tamaño del nullbitmap por ahora
        char* nullbitmap= new char[size_nullbitmap];
        //leemos el null bitmap del archivo:
        file.read(nullbitmap,size_nullbitmap);
        cout<<"nullbitmap: "<<nullbitmap<<endl;
        //Cambiamos ubicación:
        ubication_read=ubication_read+size_nullbitmap;

        //-----Ahora leemos los slots de acuerdo al nullbitmap-----
        Estudiante *student=new Estudiante();;//iremos almacenando en student
        for (int i = 0; i < size_nullbitmap; i++)
        {
            file.seekg(ubication_read);
            Slot aux_slot;
            if (nullbitmap[i]=='0' && i==0)
            {
                file.read(reinterpret_cast<char*>(&aux_slot), sizeof(Slot));
                file.seekg(aux_slot.get_offset());
                file.read((char*)&((*student).id),aux_slot.get_length());
                ubication_read=ubication_read+sizeof(Slot);//avanzamos al siguiente slot
            }
            if (nullbitmap[i]=='0' && i==1)
            {
                file.read(reinterpret_cast<char*>(&aux_slot), sizeof(Slot));
                file.seekg(aux_slot.get_offset());
                file.read((char*)&((*student).edad),aux_slot.get_length());
                ubication_read=ubication_read+sizeof(Slot);//avanzamos al siguiente slot
            }
            if (nullbitmap[i]=='0' && i==2)
            {
                file.read(reinterpret_cast<char*>(&aux_slot), sizeof(Slot));
                file.seekg(aux_slot.get_offset());
                file.read((char*)&((*student).name),aux_slot.get_length());
                ubication_read=ubication_read+sizeof(Slot);//avanzamos al siguiente slot
            }
            if (nullbitmap[i]=='0' && i==3)
            {
                file.read(reinterpret_cast<char*>(&aux_slot), sizeof(Slot));
                file.seekg(aux_slot.get_offset());
                file.read((char*)&((*student).cui),aux_slot.get_length());
                ubication_read=ubication_read+sizeof(Slot);//avanzamos al siguiente slot
            }
            if (nullbitmap[i]=='0' && i==4)
            {
                file.read(reinterpret_cast<char*>(&aux_slot), sizeof(Slot));
                file.seekg(aux_slot.get_offset());
                file.read((char*)&((*student).escuela),aux_slot.get_length());
                ubication_read=ubication_read+sizeof(Slot);//avanzamos al siguiente slot
            }
            else{
                ubication_read=ubication_read+sizeof(Slot);//avanzamos al siguiente slot
            }
        }
        file.close();
        return student;

    }
}

//Escribir en index el header de los slot_index
void R_W_Head::write_head_slots_index(Head_slot_index &H_slots_index){
    fstream file("Slots_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo Slots_index.bin - write -, creando uno nuevo"<<endl;
        fstream file("Slots_index.bin",ios::binary| ios::in| ios::out | ios::trunc);
        H_slots_index.set_direc_final_index(sizeof(Head_slot_index));
        file.seekp(0);
        file.write((char *)&H_slots_index,sizeof(Head_slot_index));//
        file.close();
        
    }
    else{
        H_slots_index.set_direc_final_index(sizeof(Head_slot_index));
        file.seekp(0);//read from the beginning, tomando header
        file.write((char *)&H_slots_index,sizeof(Head_slot_index));//
        file.close();

    }
}

//Obtener el header del slot_index
Head_slot_index* R_W_Head::get_head_slots_index(){
    fstream file("Slots_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo Slots_index.bin - get - creando uno nuevo"<<endl;
        Head_slot_index *ptr_aux_head=new Head_slot_index();
        write_head_slots_index((*ptr_aux_head));
        ptr_aux_head=get_head_slots_index();
        return ptr_aux_head;
        
    }
    else{
        /*-------------
        Para leer correctamente, debemos agregar el tamaño del Header que esta incluido
        ---------------*/
        file.seekg(0);//read from the beginning, tomando header
        Head_slot_index *ptr_head_slots_index=new Head_slot_index();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr_head_slots_index),sizeof(Head_slot_index));

        file.close();
        // (*ptr_head_slots_index).print_info_Head_slots_index();
        return ptr_head_slots_index;

    }
}

//escribir los slots en Slots_index.bin:
void R_W_Head::write_data_slot_index(Slot &slot, int ubication_write)
{
    fstream file("Slots_index.bin",ios::binary| ios::in| ios::out);
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file("Slots_index.bin",ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&slot,sizeof(Slot));//
        file.close();
        cout<<"..."<<endl;
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&slot,sizeof(Slot));
        file.close();
        cout<<"..."<<endl;

    }
}

Slot* R_W_Head::get_slot_index(int ubication){
    fstream file("Slots_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(sizeof(Head_slot_index)+ubication);//read después del HEad_slot_index
        Slot *ptr_slot=new Slot();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr_slot),sizeof(Slot));
        //NOW WE PROBE
        // (*ptr_slot).print_data_slot();
        file.close();
        return ptr_slot;

    }
}

//leer slot de slot index
void R_W_Head::read_data_slot_index(int ubication){
    fstream file("Slots_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(sizeof(Head_slot_index)+ubication);//read después del HEad_slot_index
        Slot Aux_slot;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_slot,sizeof(Slot));

        //NOW WE PROBE
        Aux_slot.print_data_slot();
        file.close();

    }
}



//FIXED-LENGTH
//definir la dirección de memoria del espacio eliminado en los fixed-length
void R_W_Head::set_direc_fixed_delete_space(int _direc_object,Header &H){
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        if (_direc_object==0)
        {
            file.seekp(_direc_object);
            //escribimos el tipo de dato header guardando la dirección de memoria
            file.write((char *)&H,sizeof(Header));
            file.close();
        }
        else{
            // _direc_object=_direc_object;
            file.seekp(_direc_object);
            //escribimos el tipo de dato header guardando la dirección de memoria
            file.write((char *)&H,sizeof(Header));

            file.close();
        }

    }
}

//obtener la dirección de memoria del espacio eliminado en los fixed-length
int R_W_Head::get_direc_fixed_delete_space(int _direc_object){
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        Header H;//tenemos la dirección del objeto a eliminar
        file.seekg(_direc_object);
        //escribimos el tipo de dato header guardando la dirección de memoria
        file.read((char *)&H,sizeof(Header));
        //Passenger ELIMINADO

        return (H.get_ptr_delete_fixed_space());
        // head.

        file.close();

    }
}

void R_W_Head::caminar_modificar_header(Header &header1,Header &header2,int _direc,int _direc2){
    // Header H4(0);
    int data_h1=header1.get_ptr_delete_fixed_space();
    int data_h2=header2.get_ptr_delete_fixed_space();
    int direc=_direc;
    int direc2=_direc2;
    if(data_h1==0){//en caso de que solo el HEAD principal este vacío y otros
        header1.set_ptr_delete_fixed_space(data_h2);
        header2.set_ptr_delete_fixed_space(data_h1);

        //Pasar a memoria
        set_direc_fixed_delete_space(direc,header1);
        set_direc_fixed_delete_space(direc2,header2);
        // H4.print_info_header();

    }
    else{
        //Obtenemos datos del HEADER FILE PRINCIPAL JEFE
        int direc_leida=get_direc_fixed_delete_space(0);//obtiene el dato del header JEFE
        int direc_aux;      
        //direc_aux esta almacenando la última dirección del último header leído, pero no es 0
        while(direc_leida!=0){
            direc_aux=direc_leida;
            direc_leida=get_direc_fixed_delete_space(direc_leida);
        }

        Header H3;
        H3.set_ptr_delete_fixed_space(direc_leida);
        caminar_modificar_header(H3, header2,direc_aux,direc2);
        // H4.print_info_header();
    }
    
}

void R_W_Head::delete_data_fixed_block(int id){
    int ubication_delete=sizeof(Header)+(id*sizeof(Passenger_titanic))-sizeof(Passenger_titanic);
    // cout<<"Deleteeeee1: "<<ubication_delete<<endl;
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{

        Header H2;
        H2.set_ptr_delete_fixed_space(ubication_delete);//tenemos la dirección del objeto a eliminar
        // Header H2(ubication_delete);//tenemos la dirección del objeto a eliminar

        // Header H1;//este apunta automáticamente a null
        // int ubicacion_header_principal=get_direc_fixed_delete_space(0);
        // H1.set_ptr_delete_fixed_space(ubicacion_header_principal);

        //H1 obtiene datos del header principal
        Header *ptr_H1=new Header();
        ptr_H1=get_header_file();
        
        caminar_modificar_header((*ptr_H1),H2,(*ptr_H1).get_ptr_delete_fixed_space(),H2.get_ptr_delete_fixed_space());

        file.close();

    }
}



//Agregaremos el HEADER que contiene toda la información del FILE
void R_W_Head::write_header_file_general(Header &head_delete)
{
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */
    int ubication_write=0;//posición para escribir siempre el inicio
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntentandode de nuevo..."<<endl;
        fstream file("DataBase.bin",ios::binary| ios::in| ios::out | ios::trunc);
        // int id_aux=verify_existence_fixed_record();
        file.seekp(ubication_write);
        //escribimos al pasajero en la base de datos bin
        file.write((char *)&head_delete,sizeof(Header));
        file.close();
    }
    else
    {
        // int id_aux=verify_existence_fixed_record();
        file.seekp(ubication_write);
        //we want to write the object of these class Passenger_titanic into our binary file
        file.write((char *)&head_delete,sizeof(Header));
        file.close();
    }
    
}

Header* R_W_Head::get_header_file(){
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        /*-------------
        Para leer correctamente, debemos agregar el tamaño del Header que esta incluido
        ---------------*/
        file.seekg(0);//read from the beginning, tomando header
        /*
        We want to read a block of data and save that in an object of this
        class Estudiante
        */
        Header *ptr_head_file=new Header();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr_head_file),sizeof(Header));
        // ptr_head_file->set_direc_free_space_variable();
        //NOW WE PROBE
        return ptr_head_file;
        file.close();

    }
}

//EScribir a los registros en los bloques
void R_W_Head::write_data_fixed_block(Passenger_titanic &passenger)
{
    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */

    /*----------------------*/
    //Debe escribir después del objeto HEADER que funciona con delete y add
    //Por ello le aumentaremos + sizeof(Header)
    /*----------------------*/

    int ubication_write=(((passenger.passenger_id)-1)*sizeof(Passenger_titanic))+ sizeof(Header);//posición para escribir
    //La ubicación de acuerdo a los bytes
    //Si no existe la data o es la primera vez que se mete el dato
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file("DataBase.bin",ios::binary| ios::in| ios::out | ios::trunc);
        int id_aux=verify_existence_fixed_record();
        if (id_aux==0 || id_aux<(passenger.passenger_id))
        //passenger_id de un objeto Passenger_titanic no existente es 0 y si el passenger_id es menor o igual al último passenger_id
        {
            file.seekp(ubication_write);
            //escribimos al pasajero en la base de datos bin
            file.write((char *)&passenger,sizeof(Passenger_titanic));
            file.close();
        }
        else{
            cout<<"Error, ya existe el objeto en esa posición"<<endl;
        }
    }
    else
    {
        //PARA SABER HASTA DÓNDE HAY DATOS EXISTENTES
        /*
        Condicional que lea el último objeto, luego
        que verifique que el nuevo id no este dentro de los
        ya escritos, de ser el caso, lanza error
        */
        
        /*----------------------*/
        

        int id_aux=verify_existence_fixed_record();
        if (id_aux==0 || id_aux<(passenger.passenger_id))
        //passenger_id de un objeto Passenger_titanic no existente es 0 y si el passenger_id es menor o igual al último passenger_id
        {
            file.seekp(ubication_write);
            //we want to write the object of these class Passenger_titanic into our binary file
            file.write((char *)&passenger,sizeof(Passenger_titanic));
            //Tamaño del objeto Passenger_titanic
            // cout<<"Tamaño del objeto: "<<sizeof(Passenger_titanic)<<endl;

            // //we are going to save the positiuon of the write_pointer
            // std::streampos posicion=file.tellp();
            // cout<<"la posicion del puntero de put es: "<<posicion<<endl;
            file.close();
        }
        else{
            cout<<"Error, ya existe el objeto en esa posición"<<endl;
        }
    }
}

void R_W_Head::read_data_fixed_block(int ubication_read)
{

    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        /*-------------
        Para leer correctamente, debemos agregar el tamaño del Header que esta incluido
        ---------------*/
        file.seekg(ubication_read+sizeof(Header));//read from the beginning, tomando header
        /*
        We want to read a block of data and save that in an object of this
        class Estudiante
        */
        Passenger_titanic Aux_passenger;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_passenger,sizeof(Passenger_titanic));

        //NOW WE PROBE
        Aux_passenger.print_data_passengers();
        file.close();

    }

}

int R_W_Head::verify_existence_fixed_record()
{

    fstream file("DataBase.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, no hay nada que verificar"<<endl;
    }
    else{
        file.seekg(ios::end);//read from the end of the file
        // Calculate position of last object
        std::streampos pos = file.tellg();//recogemos la ubicación
        pos -= sizeof(Passenger_titanic);//restamos para posicionarnos
        Passenger_titanic Aux_passenger;
        file.seekg(pos);
        /*
        We want to read a block of data and save that in an object of this
        class Estudiante
        */
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_passenger,sizeof(Passenger_titanic));

        //NOW WE PROBE
        // Aux_passenger.print_data_student();
        file.close();
        return Aux_passenger.passenger_id;

    }

}



void R_W_Head::write_data_sector_index(Sector_index &sector, int ubication_read)
{
    fstream file("sector_index.bin",ios::binary| ios::in| ios::out);
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file("sector_index.bin",ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_read);
        file.write((char *)&sector,sizeof(Sector_index));
        file.close();
        cout<<"..."<<endl;
    }
    else{
        file.seekp(ubication_read);
        file.write((char *)&sector,sizeof(Sector_index));
        // cout<<"Tamaño del objeto sector: "<<sizeof(Sector)<<endl;

        // //we are going to save the positiuon of the write_pointer
        // std::streampos posicion=file.tellp();
        // cout<<"la posicion del puntero de put es: "<<posicion<<endl;
        file.close();
        cout<<"sector_index..."<<endl;

    }
}

void R_W_Head::read_data_sector_index(int ubication_read)
{
    fstream file("sector_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(ubication_read);//read from the beginning
        Sector_index Aux_sector;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_sector,sizeof(Sector_index));

        //NOW WE PROBE
        Aux_sector.print_data_sector_index();
        file.close();

    }
}

void R_W_Head::write_data_Block_index(Block_index &bloque, int ubication_read)
{
    fstream file("Block_index.bin",ios::binary| ios::in| ios::out);
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file("Block_index.bin",ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_read);
        file.write((char *)&bloque,sizeof(Block_index));
        file.close();
        cout<<"..."<<endl;
    }
    else{
        file.seekp(ubication_read);
        file.write((char *)&bloque,sizeof(Block_index));
        file.close();
        cout<<"..."<<endl;

    }
}

void R_W_Head::read_data_Block_index(int ubication_read)
{
    fstream file("Block_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(ubication_read);//read from the beginning
        Block_index Aux_bloque;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_bloque,sizeof(Block_index));

        //NOW WE PROBE
        Aux_bloque.print_data_Block_index();
        file.close();

    }
}

void R_W_Head::read_data_platos_index(int ubication_read)
{
    fstream file("platos_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(ubication_read);//read from the beginning
        Plato_index Aux_plato;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_plato,sizeof(Plato_index));
        //NOW WE PROBE
        Aux_plato.print_data_plato_index();
        file.close();

    }
}

void R_W_Head::write_data_platos_index(Plato_index &plato_index, int ubication_read)
{
    string ubication_file_bin="platos_index.bin";
    fstream file(ubication_file_bin,ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file(ubication_file_bin,ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_read);
        file.write((char *)&plato_index,sizeof(Plato_index));
        cout<<"platos_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_read);
        file.write((char *)&plato_index,sizeof(Plato_index));
        // cout<<"Tamaño del objeto sector: "<<sizeof(Sector)<<endl;

        // //we are going to save the positiuon of the write_pointer
        // std::streampos posicion=file.tellp();
        // cout<<"la posicion del puntero de put es: "<<posicion<<endl;
        file.close();
        cout<<"platos_index.bin..."<<endl;

    }
}

void R_W_Head::write_superficie_index(Superficie_index &sup_index,int ubication_write)
{
    fstream file("superficie_index.bin",ios::binary| ios::in| ios::out);//OJO usamos TRUNC or si se da modificaciones
    /*
    el ios::trunc puede sobreescribir todo, además se debe usar para crear por primera vez el archivo
    en caso de no existir
    */
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \nIntente de nuevo..."<<endl;
        fstream file("superficie_index.bin",ios::binary| ios::in| ios::out | ios::trunc);
        file.seekp(ubication_write);
        file.write((char *)&sup_index,sizeof(Superficie_index));
        cout<<"superficie_index.bin..."<<endl;
        file.close();
    }
    else{
        file.seekp(ubication_write);
        file.write((char *)&sup_index,sizeof(Plato_index));
        file.close();
        cout<<"superficie_index.bin..."<<endl;

    }
}

int R_W_Head::verify_existence_superficie_index(Superficie_index &sup_index)
{

    fstream file("superficie_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo de sup_index, no hay nada que verificar"<<endl;
    }
    else{
        Superficie_index Aux_sup;
        file.seekg(ios::end);//read from the end of the file
        // Calculate position of last object
        // std::streampos pos = file.tellg();//recogemos la ubicación, nos posicionamos
        // pos -= sizeof(Superficie_index);//restamos para posicionarnos, retrocedemos
        // file.seekg(pos);
        // cout<<"position del verificador"<<pos<<endl;
        /*
        We want to read a block of data and save that in an object of this
        class Estudiante
        */
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_sup,sizeof(Superficie_index));

        //NOW WE PROBE
        // Aux_sup.print_data_sup_index();
        file.close();
        // cout<<"ID A RETORNAR: "<<Aux_sup.id_superficie<<endl;
        return Aux_sup.id_superficie;

    }

}

void R_W_Head::read_data_superficie_index(int ubication_read)
{
    fstream file("superficie_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(ubication_read);//read from the beginning
        Superficie_index Aux_sup;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&Aux_sup,sizeof(Superficie_index));
        //NOW WE PROBE
        Aux_sup.print_data_sup_index();
        file.close();

    }
    return;
}



/*------------CSV a BIN -----------*/
void R_W_Head::leer_registros_from_csv(const string archivo_csv,const string archivo_bin, int capacity_disc_mag){

    //Abre archivo
    std::ifstream archivo(archivo_csv);
    if (!archivo) 
    {
        std::cerr <<"Error no se encontro el archivo CSV" << std::endl;
    }
    else{
        /*---------------------------------*/    
        /*PRIMERO verificará la existencia de DataBase.bin*/
        fstream file("Database.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
        //abrir file:
        if (!file.is_open())
        {
            std::cout<<"Error al abrir el archivo, archivo no existente, creando uno nuevo \n..."<<endl;
            fstream file("Database.bin",ios::binary| ios::in| ios::out | ios::trunc);
            file.seekp(capacity_disc_mag-1);
            file.write("", 1);
            R_W_Head head; 
            Header Head_file_principal;
            Head_file_principal.set_direc_free_space_variable(capacity_disc_mag);
            Head_file_principal.set_ptr_direc_end_fixed(sizeof(Header));
            Head_file_principal.set_cant_bytes_usados(sizeof(Header));
            //Escribimos el HEAD_FILE PRINCIPAL que es muy necesario
            head.write_header_file_general(Head_file_principal);
            file.close();
            leer_registros_from_csv(archivo_csv, archivo_bin,capacity_disc_mag);
        }
        else
        {
            string linea;
            std::getline(archivo,linea);//saltamos la primera línea de datos no necesarios
            // cout<<"linea salteada"<<linea<<endl;
            R_W_Head head; 
            Header *Head_file_principal=new Header();
            Head_file_principal=get_header_file();

            /*---------------------------------*/
            int cont=0;//este coleccionará la cantidad de datos y su peso que se van agregando
            //avisará si ya se pasó del límite
            while (std::getline(archivo,linea))
            {
                stringstream ss(linea);
                string element;
                Passenger_titanic pasajero;

                //LEEMOS LOS DATOS:
                // Leer el id del pasajero
                getline(ss, element, ',');
                //eliminamos posibles espacios en blanco
                element.erase(std::remove(element.begin(), element.end(), ' '), element.end());
                pasajero.passenger_id = std::stoi(element);//convertimos a entero
                // atoi(element.c_str())
                // Leer si sobrevivió
                getline(ss, element, ',');
                if (element=="1")
                    pasajero.survived = true;//convertimos a entero
                else
                    pasajero.survived = false;//convertimos a entero
                
                // Leer la clase
                getline(ss, element, ',');
                //eliminamos posibles espacios en blanco
                element.erase(std::remove(element.begin(), element.end(), ' '), element.end());
                pasajero.passenger_class = std::stoi(element);
                
                // Leer el nombre
                getline(ss, element, ',');
                string element_2;
                getline(ss, element_2, ',');
                string final_element=element+element_2;
                strcpy(pasajero.name,final_element.c_str());
                ///donde c_Str() nos ayuda a convertir de string a un char *

                // Leer el sexo
                getline(ss, element, ',');
                strcpy(pasajero.sex,element.c_str());

                // Leer la edad
                getline(ss,element,',');
                if (element==" ")
                {
                    element="0";
                    pasajero.age = std::stoi(element);
                }
                else{
                    element.erase(std::remove(element.begin(), element.end(), ' '), element.end());
                    pasajero.age = std::stoi(element);
                }

                // Leer la cantidad de siblings(herman@s)
                getline(ss, element, ',');
                //eliminamos posibles espacios en blanco
                element.erase(std::remove(element.begin(), element.end(), ' '), element.end());
                pasajero.num_siblings = std::stoi(element);

                // Leer la cantidad de padres
                getline(ss, element, ',');
                //eliminamos posibles espacios en blanco
                element.erase(std::remove(element.begin(), element.end(), ' '), element.end());
                pasajero.num_parents = std::stoi(element);

                // Leer el ticket
                getline(ss, element, ',');
                strcpy(pasajero.ticket,element.c_str());

                // Leer la tarifa de pasajero
                getline(ss, element, ',');
                //eliminamos posibles espacios en blanco
                element.erase(std::remove(element.begin(), element.end(), ' '), element.end());
                pasajero.passenger_fare = std::stod(element);//convertimos a double

                // Leer la cabina del pasajero
                getline(ss, element, ',');
                if (element==" ")
                {
                    element="---";
                    strcpy(pasajero.passenger_cabina,element.c_str());
                }
                else{
                    strcpy(pasajero.passenger_cabina,element.c_str());
                }

                // Leer el puerto de enbarque
                // getline(ss, element, ',');//hay una coma extra
                getline(ss, element, ',');
                pasajero.embarked=element[0];

                // R_W_Head head;
                head.write_data_fixed_block(pasajero);//agrega el registro

                cont++;
                if (cont*sizeof(Passenger_titanic)>capacity_disc_mag)
                {
                    cout<<"LIMITE DE LA CAPACIDAD DEL DISCO SOBREPASADO"<<endl;
                    cout<<"No todos los registros fueron cargados"<<endl;
                    break;
                }
                        
            }

            (*Head_file_principal).set_num_records_general((*Head_file_principal).get_num_records_general()+cont);
            (*Head_file_principal).set_num_records_fixed((*Head_file_principal).get_num_records_fixed()+cont);
            (*Head_file_principal).set_ptr_direc_end_fixed((*Head_file_principal).get_ptr_direc_end_fixed()+cont*sizeof(Passenger_titanic));
            (*Head_file_principal).set_cant_bytes_usados((*Head_file_principal).get_cant_bytes_usados()+(cont*sizeof(Passenger_titanic)));
            // (*Head_file_principal).set_direc_free_space_variable(capacity_disc_mag);
            head.write_header_file_general((*Head_file_principal));
        }
    }
}




//OTRAS FUNCIONES:

Plato_index* R_W_Head::search_data_platos_index_walking(int direccion)
{
    fstream file("platos_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(direccion);//read from the beginning
        Plato_index *ptr=new Plato_index();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr),sizeof(Plato_index));
        return &(*ptr);
        file.close();

    }
}

Superficie_index* R_W_Head::search_data_superficie_index_walking(int direccion)
{
    fstream file("superficie_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(direccion);//read from the beginning
        Superficie_index *ptr=new Superficie_index();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr),sizeof(Superficie_index));
        //NOW WE PROBE
        // if (direc_object_buscar)
        // {
        //     /* code */
        // }
        
        // (*ptr).print_data_plato_index();
        return &(*ptr);
        file.close();

    }
}

Sector_index* R_W_Head::search_data_sector_index_walking(int direccion)
{
    fstream file("sector_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(direccion);//read from the beginning
        Sector_index *ptr=new Sector_index();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr),sizeof(Sector_index));
        //NOW WE PROBE
        // if (direc_object_buscar)
        // {
        //     /* code */
        // }
        
        // (*ptr).print_data_plato_index();
        return &(*ptr);
        file.close();

    }
}

Block_index* R_W_Head::search_data_block_index_walking(int direccion)
{
    fstream file("Block_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(direccion);//read from the beginning
        Block_index *ptr=new Block_index();
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr),sizeof(Block_index));
        return &(*ptr);
        file.close();

    }
}

void R_W_Head::reading_metadata_object(int id_objeto, int num_platos, int num_sectors,int num_pistas, int cant_objetos){
    //necesitamos el peso del objeto, dependiendo de su id, sabremos la dirección en bytes.
    int peso_objeto=sizeof(Passenger_titanic);
    
    int direc_bytes_objeto=(id_objeto*peso_objeto)-peso_objeto;
    //le resto el peso del objeto para obtener la dirección correcta y exacta
    cout<<endl<<"El peso del objeto buscado es: "<<peso_objeto<<" Y se ubica en la direccion(bytes): "<<direc_bytes_objeto<<endl;
    

    int n_plato,n_sup,n_sector,n_pista,n_bloque;
    // fstream
    std::cout<<endl<<"Metadata:"<<endl;
    // # disco #plato, #sector, #pista, #bloque y lo demás



    /*----------------------PARTE HALLAR EL PLATO------------------------*/
    //direc_bytes_objeto>direc_plat1 && direc_bytes_objeto<direc.plato2  =>  objeto está dentro del plato1
    Plato_index *ptr;

    R_W_Head header;
    int direccion=0;
    for (int i = 1; i <=num_platos; i++)
    {
        ptr=header.search_data_platos_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr).direc_plato==direc_bytes_objeto) //direc_bytes_objeto==direc_plat1
        {
            n_plato=(*ptr).id_plato;
            // cout<<n_plato<<", ";//numero de plato
            break;
        }
        else if((*ptr).direc_plato<direc_bytes_objeto)
        {//direc_bytes_objeto>direc_plat1
            n_plato=(*ptr).id_plato;
            direccion+=sizeof(Plato_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr).direc_plato>direc_bytes_objeto)  //direc_bytes_objeto<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    // (*ptr).print_data_plato_index();
    std::cout<<endl<<"(Disco 1, Plato "<<n_plato<<", ";



    /*----------------------PARTE HALLAR EL NÚMERO DE LA SUPERFICIE------------------------*/
    //direc_bytes_objeto>direc_plat1 && direc_bytes_objeto<direc.plato2  =>  objeto está dentro del plato1
    Superficie_index *ptr_sup;

    // int peso_superficie=((*ptr).capacidad_plato/2);
    direccion=n_plato*sizeof(Superficie_index)-sizeof(Superficie_index);//🔬🔬🔬    //LA DIRECCIÓN A LEER AHORA depende del n_plato(id)
    for (int i = 1; i <=2; i++)   //solo lee 2 superficies que le corresponden NO TODAS
    {
        ptr_sup=header.search_data_superficie_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr_sup).direc_superficie==direc_bytes_objeto) //direc_bytes_objeto==direc_plat1
        {
            n_sup=(*ptr_sup).id_superficie;
            break;
        }
        else if((*ptr_sup).direc_superficie<direc_bytes_objeto)
        {//direc_bytes_objeto>direc_plat1
            n_sup=(*ptr_sup).id_superficie;
            direccion+=sizeof(Superficie_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr_sup).direc_superficie>direc_bytes_objeto)  //direc_bytes_objeto<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    std::cout<<"Superficie: "<<n_sup<<", ";


    /*----------------------PARTE HALLAR EL SECTOR------------------------*/
    //direc_bytes_objeto>direc_plat1 && direc_bytes_objeto<direc.plato2  =>  objeto está dentro del plato1
    Sector_index *ptr_sector;

    int direc_aux_fin_sector=n_sup*num_sectors*sizeof(Sector_index);
    int peso_sectores=num_sectors*sizeof(Sector_index);
    direccion=direc_aux_fin_sector-peso_sectores;//🔬🔬🔬
    for (int i = 1; i <=num_sectors; i++)//solo leerá a los SECTORES QUE LE CORRESPONDE
    {
        ptr_sector=header.search_data_sector_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr_sector).direc_sector_index==direc_bytes_objeto) //direc_bytes_objeto==direc_plat1
        {
            n_sector=(*ptr_sector).id_sector_index;
            break;
        }
        else if((*ptr_sector).direc_sector_index<direc_bytes_objeto)
        {//direc_bytes_objeto>direc_plat1
            n_sector=(*ptr_sector).id_sector_index;
            direccion+=sizeof(Sector_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr_sector).direc_sector_index>direc_bytes_objeto)  //direc_bytes_objeto<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    std::cout<<"Sector: "<<n_sector<<", ";



    /*----------------------PARTE HALLAR LA PISTA Y BLOQUE------------------------*/
    //direc_bytes_objeto>direc_plat1 && direc_bytes_objeto<direc.plato2  =>  objeto está dentro del plato1
    Block_index *ptr_block;

    int direccion_aux=n_sector*num_pistas*sizeof(Block_index);
    /*dirección aux nos permitirá ubicarnos al final de de todos los bloques correspondientes*/
    int peso_bloques_sector=num_pistas*sizeof(Block_index);
    direccion=direccion_aux-peso_bloques_sector;
    for (int i = 1; i <=num_pistas; i++)//solo leerá a los SECTORES QUE LE CORRESPONDE
    {
        ptr_block=header.search_data_block_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr_block).direc_Block==direc_bytes_objeto) //direc_bytes_objeto==direc_plat1
        {
            n_bloque=(*ptr_block).id_Block;
            n_pista=i;//remember, los 2 coinciden con el número de pista
            break;
        }
        else if((*ptr_block).direc_Block<direc_bytes_objeto)
        {//direc_bytes_objeto>direc_plat1
            n_bloque=(*ptr_block).id_Block;
            n_pista=i;
            direccion+=sizeof(Sector_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr_block).direc_Block>direc_bytes_objeto)  //direc_bytes_objeto<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    std::cout<<"Pista: "<<n_pista<<", Bloque: "<<n_bloque<<")"<<endl;

    /*----------------------PARTE HALLAR EL OBJETO------------------------*/
    cout<<"El objeto es: "<<endl;
    read_data_fixed_block(direc_bytes_objeto);
    
}
//este nos servirá cómo previa función para sacar los METADATOS

Block_index* R_W_Head::return_data_block(int ubication_read)
{

    fstream file("Block_index.bin",ios::binary| ios::in| ios::out);//aquí sacamos el trunc
    //abrir file:
    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        file.seekg(ubication_read);//read from the beginning
        /*
        We want to read a block of data and save that in an object of this
        class Estudiante
        */
        Block_index *ptr=new Block_index;
        //we are gonna use the read method, we are gonna read from the file
        file.read((char *)&(*ptr),sizeof(Block_index));

        //NOW WE PROBE
        return (ptr);
        file.close();

    }

}

void R_W_Head::reading_metadata_bloque(int id_bloque, int num_platos, int num_sectors,int num_pistas, int cant_objetos){

    int peso_objeto=sizeof(Passenger_titanic);
    
    int peso_bloque_index=sizeof(Block_index);
    
    int direc_bytes_bloque=(id_bloque*peso_bloque_index)-peso_bloque_index;//direccion en bytes del bloque index
    //le resto el peso del objeto para obtener la dirección correcta y exacta
    cout<<endl<<"El bloque_index buscado se ubica en la direccion(bytes): "<<direc_bytes_bloque<<" de la lista index de bloques"<<endl;
    
    int n_plato,n_sup,n_sector,n_pista,n_bloque;//valores auxs
    std::cout<<endl<<"Metadata:"<<endl;

    /*----------------------PARTE HALLAR EL PLATO------------------------*/
    //direc_bytes_bloque>direc_plat1 && direc_bytes_bloque<direc.plato2  =>  objeto está dentro del plato1
    Plato_index *ptr;

    R_W_Head header;
    int direccion=0;
    for (int i = 1; i <=num_platos; i++)
    {
        ptr=header.search_data_platos_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr).direc_plato==direc_bytes_bloque) //direc_bytes_bloque==direc_plat1
        {
            n_plato=(*ptr).id_plato;
            // cout<<n_plato<<", ";//numero de plato
            break;
        }
        else if((*ptr).direc_plato<direc_bytes_bloque)
        {//direc_bytes_bloque>direc_plat1
            n_plato=(*ptr).id_plato;
            direccion+=sizeof(Plato_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr).direc_plato>direc_bytes_bloque)  //direc_bytes_bloque<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    // (*ptr).print_data_plato_index();
    std::cout<<endl<<"(Disco 1, Plato "<<n_plato<<", ";



    /*----------------------PARTE HALLAR EL NÚMERO DE LA SUPERFICIE------------------------*/
    //direc_bytes_bloque>direc_plat1 && direc_bytes_bloque<direc.plato2  =>  objeto está dentro del plato1
    Superficie_index *ptr_sup;

    // int peso_superficie=((*ptr).capacidad_plato/2);
    direccion=n_plato*sizeof(Superficie_index)-sizeof(Superficie_index);//🔬🔬🔬    //LA DIRECCIÓN A LEER AHORA depende del n_plato(id)
    for (int i = 1; i <=2; i++)   //solo lee 2 superficies que le corresponden NO TODAS
    {
        ptr_sup=header.search_data_superficie_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr_sup).direc_superficie==direc_bytes_bloque) //direc_bytes_bloque==direc_plat1
        {
            n_sup=(*ptr_sup).id_superficie;
            break;
        }
        else if((*ptr_sup).direc_superficie<direc_bytes_bloque)
        {//direc_bytes_bloque>direc_plat1
            cout<<endl<<"::::"<<(*ptr_sup).direc_superficie<<endl;
            n_sup=(*ptr_sup).id_superficie;
            cout<<endl<<":::"<<direc_bytes_bloque<<endl;
            cout<<endl<<":::"<<n_sup<<endl;
            direccion+=sizeof(Superficie_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr_sup).direc_superficie>direc_bytes_bloque)  //direc_bytes_bloque<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    std::cout<<"Superficie: "<<n_sup<<", ";


    /*----------------------PARTE HALLAR EL SECTOR------------------------*/
    //direc_bytes_bloque>direc_plat1 && direc_bytes_bloque<direc.plato2  =>  objeto está dentro del plato1
    Sector_index *ptr_sector;

    int direc_aux_fin_sector=n_sup*num_sectors*sizeof(Sector_index);
    int peso_sectores=num_sectors*sizeof(Sector_index);
    direccion=direc_aux_fin_sector-peso_sectores;//🔬🔬🔬
    for (int i = 1; i <=num_sectors; i++)//solo leerá a los SECTORES QUE LE CORRESPONDE
    {
        ptr_sector=header.search_data_sector_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr_sector).direc_sector_index==direc_bytes_bloque) //direc_bytes_bloque==direc_plat1
        {
            n_sector=(*ptr_sector).id_sector_index;
            break;
        }
        else if((*ptr_sector).direc_sector_index<direc_bytes_bloque)
        {//direc_bytes_bloque>direc_plat1
            n_sector=(*ptr_sector).id_sector_index;
            direccion+=sizeof(Sector_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr_sector).direc_sector_index>direc_bytes_bloque)  //direc_bytes_bloque<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    std::cout<<"Sector: "<<n_sector<<", ";



    /*----------------------PARTE HALLAR LA PISTA Y BLOQUE------------------------*/
    //direc_bytes_bloque>direc_plat1 && direc_bytes_bloque<direc.plato2  =>  objeto está dentro del plato1
    Block_index *ptr_block;

    int direccion_aux=n_sector*num_pistas*sizeof(Block_index);
    /*dirección aux nos permitirá ubicarnos al final de de todos los bloques correspondientes*/
    int peso_bloques_sector=num_pistas*sizeof(Block_index);
    direccion=direccion_aux-peso_bloques_sector;
    for (int i = 1; i <=num_pistas; i++)//solo leerá a los SECTORES QUE LE CORRESPONDE
    {
        ptr_block=header.search_data_block_index_walking(direccion);//objeto leido almacenado}
        if ((*ptr_block).direc_Block==direc_bytes_bloque) //direc_bytes_bloque==direc_plat1
        {
            n_bloque=(*ptr_block).id_Block;
            n_pista=i;//remember, los 2 coinciden con el número de pista
            break;
        }
        else if((*ptr_block).direc_Block<direc_bytes_bloque)
        {//direc_bytes_bloque>direc_plat1
            n_bloque=(*ptr_block).id_Block;
            n_pista=i;
            direccion+=sizeof(Sector_index);//ubicación en bytes de cada objeto sector
        }
        else if((*ptr_block).direc_Block>direc_bytes_bloque)  //direc_bytes_bloque<direc.plato2 
        {
            break;
        }
        else
        {
            break;
        }
        
    }
    std::cout<<"Pista: "<<n_pista<<", Bloque: "<<n_bloque<<")"<<endl;

    /*----------------------IMPRIMIENDO LO QUE CONTIENE EL BLOQUE------------------------*/
    //DE ACUERDO al numero del bloque mostraremos los datos que le corresponden
    // Block_index *ptr_block_2=return_data_block(0);
    int peso_bloque=(*ptr_block).peso_Block;
    int num_objetos_per_block=cant_objetos/peso_bloque;//cant_objetos son todos los objetos en total / peso de un bloque
    cout<<"Este bloque tiene la capacidad para almacenar: "<<num_objetos_per_block<<"objetos"<<endl;
    cout<<"Los objetos que pertenecen al bloque son: "<<endl;
    print_data_passengers_bloque(n_bloque,num_objetos_per_block);
    
    
}

void R_W_Head::print_data_passengers_bloque(int id_bloque,int num_objetos_per_block){
    std::cout<<endl<<"\t Pasajeros:"<<endl;
    std::cout <<"passenger_id\tsurvived\tpassenger_class\tname\t";
    cout<<"\tsex\tage\tnum_siblings\tnum_parents\tticket\tpassenger_fare";
    cout<<"\tpassenger_cabina\tembarked"<<endl;

    R_W_Head header;
    int direc_final_objeto_aux=id_bloque*num_objetos_per_block*sizeof(Passenger_titanic);
    int peso_objetos=num_objetos_per_block*sizeof(Passenger_titanic);
    int direccion=direc_final_objeto_aux-peso_objetos;
    for (int i = 1; i <=num_objetos_per_block; i++)
    {   
        header.read_data_fixed_block(direccion);
        direccion+=sizeof(Passenger_titanic);//ubicación en bytes de cada objeto sector
    }
    
    header.~R_W_Head();
}

void R_W_Head::print_header_fixed_data(){
    Header *ptr_header=new Header();
    ptr_header=get_header_file();
    int direc_header_principal=(*ptr_header).get_ptr_delete_fixed_space();
    cout<<"DIRECCION_DELETED en header: "<<direc_header_principal<<endl;
}