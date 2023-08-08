#include "Programa.h"

Programa::Programa()
{
    int num_frames;
    cout<<"ingrese el numero de frames con el que se pueda trabajar: "<<endl;
    cin>>num_frames;
    this->buffManagerPrograma.set_num_frames(num_frames);
}

Programa::~Programa(){}

void Programa::setPtrPaginaRecibir(Pagina &pagina){
    (this->paginaRecibir)=pagina;
}

Pagina& Programa::obtenerPagina(int id_pagina){
    /*
    Primero busca en el B+ tree y este le permite sacar del disco el bloque o sector necesitado
    - Quién busca: Disk Manager
    - Una vez encontrado, retorna la página al Buffer Manager
    - Buffer manager: Agrega dato a TablaMetadta y agrega la página a Buffer Pool
    - Retorna la página al Programa
    */
    (this->buffManagerPrograma).agregarPagina_BuffPool_tablaMetadata(id_pagina);
    cout<<"..-..rr"<<endl;
    // (*this->paginaRecibir)=(this->buffManagerPrograma).get_pagina_retornar();
    cout<<"Pagina recibida, mostrando estado de la tabla de metadata"<<endl;
    (this->buffManagerPrograma).mostrar_tabla_metadata();
    // cout<<"Mostrando pagina recibida..."<<endl;
    // (*this->paginaRecibir).print_info_pagina();
    (this->paginaRecibir)=(this->buffManagerPrograma).get_pagina_retornar();
}
