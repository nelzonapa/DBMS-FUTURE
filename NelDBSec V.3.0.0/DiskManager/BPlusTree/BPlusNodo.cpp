#include "BPlusNodo.h"

BPlusNodo::BPlusNodo(int grado)
{
    this->gradoBplusNodo=grado;
    this->esHoja=true;
    setEspacioVectorDirecciones(grado);
    setEspacioVectorKeys(grado-1);
}

BPlusNodo::BPlusNodo()
{
    this->esHoja=true;
}

BPlusNodo::~BPlusNodo(){}

void BPlusNodo::setEspacioVectorDirecciones(int tamanio){
    for (int i = 0; i < tamanio; i++) {
        std::string dato="-1";
        this->vecDirecciones.push_back(dato);
    }
}
void BPlusNodo::setEspacioVectorKeys(int tamanio){
    for (int i = 0; i < tamanio; i++) {
        std::string dato="-1";
        this->keys.push_back(dato);
    }
}
void BPlusNodo::setEsHoja(bool input){
    this->esHoja=input;
}

void BPlusNodo::setgrado(int input){
    this->gradoBplusNodo=input;
}

vector<string> BPlusNodo::Ordenar(vector<string> key){
    vector<int> aux;
        for(int i=0;i<key.size();i++){
        aux.push_back(stoi(key[i]));
    }
    sort(aux.begin(), aux.end());
        // Paso 3: Convertir los enteros a cadenas de texto (strings)
    vector<string> vector_strings;
    for (int num : aux) {
        vector_strings.push_back(to_string(num));
    }
    return vector_strings;
}

int BPlusNodo::getGradoBplusNodo(){ 
    return gradoBplusNodo; 
};
vector<string> BPlusNodo::getVecDirecciones(){ 
    return vecDirecciones;
};
vector<string> BPlusNodo::getKeys(){ 
    return keys; 
};
bool BPlusNodo::getEsHoja(){ 
    return esHoja; 
};

//Ingresar Datos a vectores:
bool BPlusNodo::ingresarElementVectorDirecciones(string direccion){
    //keys a poner es (grado - 1)
    if ((this->gradoBplusNodo-1) < this->vecDirecciones.size()) 
    {
        // Insertar el direccion en la posición indicada
        this->vecDirecciones.push_back(direccion);
        vecDirecciones = Ordenar(vecDirecciones);
        return true;
    } 
    else 
    {
        // Si la posición está fuera de los límites del vector, agregar el direccion al final
        cout<<"Grado en raiz sobrepasado - direcciones"<<endl;
        return false;//falló insertion
    }
}


bool BPlusNodo::ingresarElementVectorKeys(string key){
    //keys a poner es (grado - 1)
    if ((this->gradoBplusNodo-1) < this->keys.size()) 
    {
        // Insertar el direccion en la posición indicada
        this->keys.push_back(key);
        
        keys = Ordenar(keys);

        return true;
    } 
    else 
    {
        // Si la posición está fuera de los límites del vector, agregar el direccion al final
        cout<<"grado en raiz sobrepasado - keys"<<endl;
        return false;//falló insertion
    }
}



//Sobrecarga:
//sobrecarga
std::ostream& operator<<(std::ostream& os, const BPlusNodo& bPlusNodo) {
    // Implementa aquí la lógica para guardar los datos del objeto en el archivo
    // Escribe los datos uno por uno en el formato que desees
    // Por ejemplo, si tienes un atributo "data" en la clase, podrías hacer algo como:
    os << "#"; 
    for (size_t i = 0; i < bPlusNodo.vecDirecciones.size(); i++) {
        os << bPlusNodo.vecDirecciones[i] << "|";
    }
    os <<",";
    for (size_t i = 0; i < bPlusNodo.keys.size(); i++) {
        os << bPlusNodo.keys[i] << "|";
    }
    os <<",";
    os << bPlusNodo.esHoja<<",";
    // Devuelve el flujo de salida
    return os;
}

std::istream& operator>>(std::istream& is, BPlusNodo& bPlusNodo) {
    // Implementa aquí la lógica para leer los datos del archivo y actualizar el objeto
    // Lee los datos uno por uno en el orden en que los guardaste en el archivo
    // Por ejemplo, si tienes un atributo "data" en la clase, podrías hacer algo como:
    string cadenaAux;
    is >> cadenaAux;
    int posicionInicial=0;
    vector<string> VectorAux;
    for(int i=0;i<=cadenaAux.size();i++)
    {
        if(cadenaAux[i]==','|| cadenaAux.size()==i){
            VectorAux.push_back(cadenaAux.substr(posicionInicial, i-posicionInicial));
            posicionInicial = i+1;
        }
    }

    // bPlusNodo.nameTabla=VectorAux[0];
    //Ya tienen los datos del vector
    string direccionesAux=VectorAux[0];
    int posIni=0;
    for(int i=0;i<=direccionesAux.size();i++)
    {
        if(direccionesAux[i]=='|'|| direccionesAux.size()==i){
            bPlusNodo.vecDirecciones.push_back(direccionesAux.substr(posIni, i-posIni));
            posIni = i+1;
        }
    }


    // bPlusNodo.nameTabla=VectorAux[0];
    //Ya tienen los datos del vector
    string direccionesAux2=VectorAux[1];
    int posIni2=0;
    for(int i=0;i<=direccionesAux2.size();i++)
    {
        if(direccionesAux2[i]=='|'|| direccionesAux2.size()==i){
            bPlusNodo.keys.push_back(direccionesAux2.substr(posIni2, i-posIni2));
            posIni2 = i+1;
        }
    }
    bPlusNodo.esHoja=(VectorAux[2]=="1");
    // Devuelve el flujo de entrada
    return is;
}


void BPlusNodo::printInfoBPlusNode(){
    cout<<"Vector de vecDirecciones: ";
    for (size_t i = 0; i < this->vecDirecciones.size(); i++) {
        cout << this->vecDirecciones[i]<<" | ";
    }
    cout<<"Keys: ";
    for (size_t i = 0; i < this->keys.size(); i++) {
        cout << this->keys[i]<<" | ";
    }
    cout<<"esHoja: "<<this->esHoja<<endl;
}
