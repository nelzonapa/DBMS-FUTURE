#include "BPlusTree.h"
BPlusTree::BPlusTree(){
    this->grado=0;
    this->direccionRaiz="0";
    this->direcfinalBPlusTree="0";
    this->nameTabla="none";
}

BPlusTree::BPlusTree(int n){
    this->grado=n;
    this->direccionRaiz="0";
    this->direcfinalBPlusTree="0";
    this->nameTabla="none";
}

BPlusTree::~BPlusTree(){}

//SETTERS
void BPlusTree::set_nameTabla(string input){
    this->nameTabla=input;
} 
void BPlusTree::set_grado(int input){
    this->grado=input;
}
void BPlusTree::set_direccionRaiz(string input){
    this->direccionRaiz=input;
} 
void BPlusTree::set_direcfinalBPlusTree(string input){
    this->direcfinalBPlusTree=input;
}

//GETTERS
string BPlusTree::get_nameTabla(){
    return this->nameTabla;
} 
int BPlusTree::get_grado(){
    return this->grado;
}
string BPlusTree::get_direccionRaiz(){
    return this->direccionRaiz;
} 
string BPlusTree::get_direcfinalBPlusTree(){
    return this->direcfinalBPlusTree;
}

//Otros

bool BPlusTree::verificarExistenciaRaiz(int direccionRaiz)
{
    //read data
    // if (data.empty)
    // {
    //     /* code */
    // }
    
}
void BPlusTree::agregarNewKey(int idRegistro,int direccionRaiz){
    // bool existeNodoRaiz=verificarExistenciaRaiz(direccionRaiz);
    // if (existeNodoRaiz==false)
    // {
        BPlusNodo nodoAux(this->grado);
        escribirNodo(stoi(this->direcfinalBPlusTree),nodoAux);
    // }
    // else
    // {
    //     //leer el nodo raiz
    // }
    
    
}
void BPlusTree::eliminarNodo(){}
void BPlusTree::reemplazarNodo(){}

//sobrecarga
std::ostream& operator<<(std::ostream& os, const BPlusTree& bplusTree) {
    // Implementa aquí la lógica para guardar los datos del objeto en el archivo
    // Escribe los datos uno por uno en el formato que desees
    // Por ejemplo, si tienes un atributo "data" en la clase, podrías hacer algo como:
    os << bplusTree.nameTabla <<",";
    os << bplusTree.grado <<",";
    os << bplusTree.direccionRaiz <<",";
    os << bplusTree.direcfinalBPlusTree <<",";

    // Devuelve el flujo de salida
    return os;
}

std::istream& operator>>(std::istream& is, BPlusTree& bplusTree) {
    // Implementa aquí la lógica para leer los datos del archivo y actualizar el objeto
    // Lee los datos uno por uno en el orden en que los guardaste en el archivo
    // Por ejemplo, si tienes un atributo "data" en la clase, podrías hacer algo como:
    string aux,cadenaAux;
    is >> cadenaAux;
    int posicionInicial=0;
    vector<string> CadenaAux;
    for(int i=0;i<=cadenaAux.size();i++)
    {
        if(cadenaAux[i]==','|| cadenaAux.size()==i){
            CadenaAux.push_back(cadenaAux.substr(posicionInicial, i-posicionInicial));
            posicionInicial = i+1;
        }
    }

    bplusTree.nameTabla=CadenaAux[0];
    bplusTree.grado=stoi(CadenaAux[1]);
    bplusTree.direccionRaiz = CadenaAux[2];
    bplusTree.direcfinalBPlusTree= CadenaAux[3];
    // Devuelve el flujo de entrada
    return is;
}

void BPlusTree::imprimirInfoBPlusTree(){
    /*ombre */
    cout<<"Info atributos"<<endl;
    cout<<"Nombre de la tabla: "<<nameTabla<<endl;
    cout<<"Grado de la tabla: "<<grado<<endl;
    cout<<"Direccion de la raiz del arbol: "<<direccionRaiz<<endl;
    cout<<"Direccion final del arbol: "<<direcfinalBPlusTree<<endl;
}
    
//prueba:
void BPlusTree::escribirNodo(int position, BPlusNodo &bPlusNodo){
    // Abrir el archivo para escritura en modo de anexar
    string filename="DiscoSectores/sector1.txt";
    fstream outFile(filename, ios::in | ios::out);
    if (!outFile) {
        cerr << "Error al abrir el archivo " << filename << endl;
    }
    else{
        outFile.seekp(position);

        // Guardar el objeto en el archivo
        outFile << bPlusNodo;
        outFile.close();

        // Abrir el archivo para lectura
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error al abrir el archivo " << filename << endl;
        }
        else{
            inFile.seekg(position);
            // Leer el objeto desde el archivo
            BPlusNodo bPlusNodo;
            inFile >> bPlusNodo;
            inFile.close();
            bPlusNodo.printInfoBPlusNode();
        }
    }
}