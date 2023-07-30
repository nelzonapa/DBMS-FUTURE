// #include <iostream>
// #include "DiskManager/DiskManager.h"
// #include "DiskManager/DiskManager.cpp"

// // #include "DiscoMagnetico/SistemaOperativo.h"
// // #include "DiscoMagnetico/SistemaOperativo.cpp"

// #include "Main_Memory/BufferManager/BufferManager.h"
// #include "Main_Memory/BufferManager/BufferManager.cpp"


// // #include "Main_Memory/BufferPool/BufferPool.h"

// using namespace std;

// void insertar_registros_desde_file(const string &nombre_tabla,const string &doc_csv);
// void insertar_registro(const string &nombre_tabla,const string &registro);
// void menu_program();

// void leer_registro(int num_registro);
// void leer_bloque(int num_bloque);
// void leer_sector(int num_sector);
// void leer_pista(int num_pista);
// void leer_superficie(int num_superficie);
// void leer_plato(int num_plato);
// void leer_disco(int id_disco);

// void crear_buffer_pool();


// void menu_program(){
//     cout<<"Bienvenido al nuevo DBMS Future"<<endl;
//     bool x=false;//para detectar si sale del programa
//     int op;//detectar la opcion
//     string nombre_tabla;//para cuando ingresemos archivo
//     string registro;
//     string doc_csv;

//     while (x==false)
//     {
//         std::cout<<"\t----- MENU -----\n";
//         std::cout<<"1. Ingresar registro"<<endl;
//         std::cout<<"2. Ingresar registros de archivo"<<endl;
//         /*--------------------------*/
//         std::cout<<"3. Crear Buffer Pool"<<endl;
//         /*--------------------------*/
//         std::cout<<"4. Salir"<<endl;
//         std::cout<<"Ingrese opcion: "<<endl;
//         cin>>op;
//         switch(op)
//         {
//             case 1:
//                 cout<<"INSERT INTO: (nombre de tabla)"<<endl;
//                 cin>>nombre_tabla;
//                 cout<<"VALUES (registro a ingresar)..."<<endl;
//                 cin>>registro;
//                 insertar_registro(nombre_tabla,registro);
//                 break;
//             case 2:
//                 cout<<"INSERT INTO: (nombre de tabla)"<<endl;
//                 cin>>nombre_tabla;
//                 cout<<"VALUES (nombre archivo con registros)..."<<endl;
//                 cin>>doc_csv;
//                 insertar_registros_desde_file(nombre_tabla,doc_csv);
//                 break;
//             case 3:
//                 crear_buffer_pool();
//                 break;
//             case 4:
//                 x=true;
//                 break;

//             default:
//                 std::cout<<"Error, escoja entre las opciones dadas"<<endl;
//                 break;
//         }

//     }
//     std::cout<<"Usted ha sido expulsado/expulsada del programa"<<endl;
    
//     return;
// }

// void insertar_registros_desde_file(const string &nombre_tabla,const string &doc_csv){
//     ifstream archivo(doc_csv);
//     if (!archivo) {
//         cout<<"Error al abrir el archivo CSV."<<endl;
//     }
//     else
//     {
//         // Descartar la primera línea (encabezados)
//         string linea;
//         getline(archivo, linea);
//         // cout<<linea<<endl;
//         while (getline(archivo,linea))
//         {
//             // Leer las líneas
//             cout<<linea<<endl;
//             insertar_registro(nombre_tabla,linea);
//         }
//         archivo.close();
//     }
// }

// void insertar_registro(const string &nombre_tabla,const string &registro){
//     string name_tabla;
//     cout<<"Tabla: "<<endl;
//     cin>>name_tabla;
    
//     //Ya sabemos el nombre de la tabla
    
//     //Ahora el registro debe seguir la estructura de la tabla:
//     //PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Cabin,Embarked,
    
//     vector<string> datos;
//     istringstream iss(registro);
//     string campo;

//     while (getline(iss, campo, ',')) 
//     {
//         datos.push_back(campo);
//     }
//     //enviamos el registro a ser evaluado en Buffer manager que se guia del esquema
//     // Buffer_Manager
//     //en este caso nos saltaremos el buffer manager, e interactuaremos directamente con 
//     //el esquema - data dictionary del disco
// }

// void crear_buffer_pool(){
//     int num_paginas;
//     cout<<"Ejecutando BufferManager..."<<endl;
//     cout<<"Creando buffer_pool..."<<endl;
//     cout<<"Ingrese el tamanio que tendra su buffer pool(# paginas): ";
//     cin>>num_paginas;
//     BufferManager buffer_manager(num_paginas);
//     cout<<"Buffer pool creado exitosamente.."<<endl;
//     vector<Pagina>*ptr_buff_p=new vector<Pagina>();
//     (*ptr_buff_p)=buffer_manager.get_buffer_pool();
//     buffer_manager.LRU((*ptr_buff_p),2);
//     buffer_manager.LRU((*ptr_buff_p),5);
//     buffer_manager.LRU((*ptr_buff_p),2);
//     buffer_manager.LRU((*ptr_buff_p),6);
//     buffer_manager.LRU((*ptr_buff_p),1);
//     buffer_manager.LRU((*ptr_buff_p),3);
//     buffer_manager.LRU((*ptr_buff_p),8);
//     return;
// }


// int main(){
//     // DiskManager disk_aux;
//     // disk_aux.menu();
//     menu_program();
//     // execute_buffer_manager();
//     return 0;
// }
// //solo para probar