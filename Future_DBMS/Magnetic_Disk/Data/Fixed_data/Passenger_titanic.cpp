#include "Passenger_titanic.h"
Passenger_titanic::Passenger_titanic(){
    this->passenger_id=0;
    this->survived=false;
    this->passenger_class=0;
    strcpy(this->name,"_name");
    // this->name[100];
    strcpy(this->sex,"_sex");//female and male
    this->age=0;
    this->num_siblings=0;
    this->num_parents=0;
    strcpy(this->ticket,"_ticket");
    // this->ticket[50];
    this->passenger_fare=0; //tarifa de pasajero
    strcpy(this->passenger_cabina,"_passenger_cabina");
    // this->passenger_cabina[20];
    this->embarked='N';
}

Passenger_titanic::Passenger_titanic(int _passenger_id,bool _survived,int _passenger_class,
        const char* _name,const char* _sex, int _age, int _num_siblings, 
        int _num_parents, const char* _ticket,float _passenger_fare, 
        const char* _passenger_cabina,char _embarked)
{
    this->passenger_id=_passenger_id;
    this->survived=_survived;
    this->passenger_class=_passenger_class;
    strcpy(this->name,_name);
    // this->name[100];
    strcpy(this->sex,_sex);//female and male
    this->age=_age;
    this->num_siblings=_num_siblings;
    this->num_parents=_num_parents;
    strcpy(this->ticket,_ticket);
    // this->ticket[50];
    this->passenger_fare=_passenger_fare; //tarifa de pasajero
    strcpy(this->passenger_cabina,_passenger_cabina);
    // this->passenger_cabina[20];
    this->embarked=_embarked;
}

Passenger_titanic::~Passenger_titanic(){}

void Passenger_titanic::print_data_passengers(){
    std::cout<<passenger_id<<"\t"<<survived<<"\t"
    <<passenger_class<<"\t"<<name<<"\t"<<sex<<"\t"
    <<age<<"\t"<<num_siblings<<"\t"<<num_parents<<"\t"
    <<ticket<<"\t"<<passenger_fare<<"\t"<<passenger_cabina<<"\t"
    <<embarked<<endl;

}