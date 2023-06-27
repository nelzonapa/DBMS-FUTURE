#include <string>

using namespace std;

class Estudiante
{
public:
    int id;
    int edad;
    const char *name;
    int cui;
    const char *escuela;
    int cant_atributos=5;

public:
    Estudiante(){
        this->id=0;
        this->edad=0;
        this->name="";
        this->cui=0;
        this->escuela="";
    } 
    Estudiante(int _id, int _edad, const char *_name, int _cui, const char *_escuela){
        this->id=id;
        this->edad=_edad;
        this->name=_name;
        this->cui=_cui;
        this->escuela=_escuela;
    }
    ~Estudiante(){}

    //SET
    void set_id(int _input){
        this->id=_input;
    }
    void set_edad(int _input){
        this->edad=_input;
    }
    void set_name(char* _input){
        this->name=_input;
    }
    void set_cui(int _input){
        this->cui=_input;
    }
    void set_escuela(char* _input){
        this->escuela=_input;
    }

    void print_info_student(){
        cout<<"id\t\t| edad\t\t| nombre\t\t| cui\t\t| escuela\t\t"<<endl;
        cout<<this->id<<"\t\t"<<this->edad<<"\t\t"<<this->name<<"\t\t"<<this->cui<<"\t\t"<<this->escuela<<"\t\t"<<endl;
    }
};
