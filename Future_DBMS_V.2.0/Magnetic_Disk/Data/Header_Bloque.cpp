#ifndef HEADER_BLOQUE_H
#define HEADER_BLOQUE_H

class Header_Bloque
{
private:
    //general
    unsigned int num_records_general_bloque;
    unsigned int cant_bytes_usados_bloque;
    
    //fixed length
    unsigned int direc_delete_fixed_space_bloque;
    unsigned int direc_end_fixed_bloque;
    unsigned int num_records_fixed_bloque;

    //variable length
    unsigned int num_records_variable_bloque;
    unsigned int direc_free_space_variable_bloque; //apunta a donde inicias las tuplas de variable length
public:
    Header_Bloque(/* args */);
    ~Header_Bloque();
};

#endif