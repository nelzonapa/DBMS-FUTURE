#include <iostream>
#include "GestionPermisos/inicioSesion.cpp"

using namespace std;

int main(){
    string usuario;
    string contrasenia;
    inicioSesion nuevoInicio;
    bool sesion=false;
    while (sesion==false)
    {
        cout<<"Ingrese su nombre de usuario: "<<endl;
        cin>>usuario;
        cout<<"Ingrese su contrasenia: "<<endl;
        cin>>contrasenia;
        sesion=nuevoInicio.autenticar(usuario,contrasenia);
        if (sesion==false)
        {
            cout<<"Datos inválidos"<<endl;
        }
        else{
            cout<<"Bienvenido "<<usuario<<endl;
            nuevoInicio.getUsuario().ejecutarPrograma();
        }
    }
    
    
    return 0;
}