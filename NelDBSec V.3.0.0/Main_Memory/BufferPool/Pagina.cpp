#include "Pagina.h"

Pagina::Pagina(){
    cout<<"gaaaa"<<endl;
    this->id_pagina=0;
    cout<<"gaaaa"<<endl;
    map <int,vector<string>> mapita;
    (this->mapPagina)=mapita;
    cout<<"gaaaa"<<endl;
}

Pagina::~Pagina(){}

bool Pagina::vacioPtrMapRegistros(){
    if (this->mapPagina.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Pagina::print_info_pagina(){
    for (auto it = ((this->mapPagina).begin()); it != ((this->mapPagina).end()); ++it) 
    {
        cout<<"Clave: "<<it->first<<", Valores: ";
        vector<string>& vector_valores = it->second;
        for (vector<string>::const_iterator vec_it = vector_valores.begin(); vec_it != vector_valores.end(); ++vec_it) {
            cout<<(*vec_it)<<" ";
        }
        cout<<endl;
    }
}

int Pagina::get_id_pagina(){
    return this->id_pagina;
}