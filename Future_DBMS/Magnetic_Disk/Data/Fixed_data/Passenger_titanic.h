#ifndef PASSENGER_TITANIC_H
#define PASSENGER_TITANIC_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Passenger_titanic
{
protected:
    unsigned int passenger_id;
    bool survived;
    unsigned int passenger_class;
    char name[100];
    char sex[6];//female and male
    unsigned int age;
    unsigned int num_siblings;
    unsigned int num_parents;
    char ticket[50];
    float passenger_fare; //tarifa de pasajero
    char passenger_cabina[20];
    char embarked;  //Puerto de embarque (C = Cherburgo; Q = Queenstown; S = Southampton)
public:
    Passenger_titanic();
    Passenger_titanic(int _passenger_id,bool _survived,int _passenger_class,
        const char* _name,const char* _sex, int _age, int _num_siblings, 
        int _num_parents, const char* _ticket,float _passenger_fare, 
        const char* _passenger_cabina,char _embarked); 

    ~Passenger_titanic();

    void print_data_passengers();
    friend class R_W_Head;
};


#endif