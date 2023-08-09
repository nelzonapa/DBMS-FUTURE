#include "usuario.h"
Usuario::Usuario(/* args */)
{
    this->id=1; 
    this->nombre="Nelzon"; 
    this->contrasenia="12345";
}

Usuario::Usuario(int _id,  string& _nombre,  string& _contrasenia)
{
    this->id=_id; 
    this->nombre=_nombre; 
    this->contrasenia=_contrasenia;
}

Usuario::~Usuario()
{
}

// Funciones get
int Usuario::getId()  {
    return id;
}

string Usuario::getNombre()  {
    return nombre;
}

string Usuario::getContrasenia()  {
    return contrasenia;
}

// Funciones set
void Usuario::setId(int _id) {
    this->id = _id;
}

void Usuario::setNombre( string& _nombre) {
    this->nombre = _nombre;
}

void Usuario::setContrasenia( string& _contrasenia) {
    this->contrasenia = _contrasenia;
}


void Usuario::ejecutarPrograma(){
    if (this->permisoRol.getNamePermiso()=="Administrador" && this->permisoRol.getNameRol()=="Administrador")
    {
        menu_program(this->programa);
    }
    else
    {
        cout<<"Usted no tiene permiso para ingresar al sistema"<<endl;
    }
    
}

void Usuario::menu_program(Programa &programa){
    bool x=false;//para detectar si sale del programa
    int op;
    int num_pagina;
    string nombreArchivoCSV;

    while (x==false)
    {
        std::cout<<"\t---- Programa Ejecutando ----\n";
        std::cout<<"1. Obtener Pagina"<<endl;
        std::cout<<"2. Mostrar la tabla metadata"<<endl;
        std::cout<<"3. Ingresar Tabla desde Archivo csv"<<endl;
        std::cout<<"4. Salir"<<endl;
        std::cout<<"Ingrese opcion: "<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Ingrese el numero de la pagina a obtener"<<endl;
                cin>>num_pagina;
                programa.setPtrPaginaRecibir(programa.obtenerPagina(num_pagina));
                break;
            case 2:
                cout<<"Estado de la tabla metadata: ...."<<endl;
                mostrarTablaMetadata();
                break;
            case 3:
                cout<<"Para ingresar su tabla, ingrese el nombre del archivo: ...."<<endl;
                cin>>nombreArchivoCSV;
                ingresarTablaDesdeArchivo(nombreArchivoCSV);
                break;
            case 4:
                x=true;
                break;

            default:
                std::cout<<"Error, escoja entre las opciones dadas"<<endl;
                break;
        }

    }
    std::cout<<"Usted ha sido expulsado/expulsada del programa"<<endl;
    
    return;
}

void Usuario::mostrarTablaMetadata(){
    cout<<"Mostrando tabla"<<endl;
    // this->programa
}

void Usuario::ingresarTablaDesdeArchivo(string nombreArchivoCSV){
    // cout<<"cargando archivo "+nombreArchivoCSV<<endl;
    this->programa.ingresarTablaDesdeArchivoCSV(nombreArchivoCSV);
}