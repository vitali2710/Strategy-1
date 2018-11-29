//
//  main.cpp
//  units
//
//  Created by Артем Козьмин on 29/11/2018.
//  Copyright © 2018 Артем Козьмин. All rights reserved.
//
//хахаха
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef int loc_t;

class Units{
private:
    //    int id;
    loc_t HEROES;           //какому отряду принадлежат  0-никому 1-(1)герой  2-(2)герой
    string NAME;            //название отряда
    size_t DAMAGE;          //урон 1-го юнита
    size_t TYPE_DAMAGE;     //0-ближники 1- дальники
    size_t SPEED;           //скорость передвижения 1-го юнита
    size_t QUANTITY;        //количество юнитов в отряде
    size_t HEALTH;          //здоровье 1-го юнита
    size_t SQUAD_HEALTH;    //количество здоровья во всём отряде
protected:
    static int counter;
    static bool debug;
public:
    static void setDebug(bool d = true)
    {
        debug = d;
    }
    Units(loc_t heroes = 0, string name = "people",size_t damage  = 0,size_t type_damage = 0, size_t speed = 0, size_t quantity = 0,size_t health = 0, size_t squad_health = 0): HEROES(heroes),NAME(name),DAMAGE(damage),TYPE_DAMAGE(type_damage),SPEED(speed),QUANTITY(quantity),HEALTH(health),SQUAD_HEALTH(squad_health){
        counter ++;
        //        id = counter;
        if(debug){
            cout<< "Created new unit: " << HEROES << ", ";
            if(NAME != ""){
                cout << NAME;
            }else {cout << "no NAME";}
            cout <<endl<< "HEALTH 1 units:"<< HEALTH << endl;
            cout << "DAMAGE 1 units:"<< DAMAGE << endl;
            cout << "TYPE_DAMAGE 1 units:"<< TYPE_DAMAGE << endl;
            cout << "SPEED 1 units:"<< SPEED << endl;
            cout << "QUANTITY units:"<< QUANTITY << endl;
            cout << "SQUAD_HEALTH units:"<< SQUAD_HEALTH << endl;
            
            cout << "Number counter: " << counter << endl<<endl;
        }
    }
    
    
    //ВЗЯЛИ
    
    string GetNAME(void) const{return NAME;}
    size_t GetHEALTH(void) const{return HEALTH;}
    size_t GetDAMAGE(void) const{return DAMAGE;}
    size_t GetTYPE_DAMAGE(void) const{return TYPE_DAMAGE;}
    size_t GetSPEED(void) const{return SPEED;}
    size_t GetQUANTITY(void) const{return QUANTITY;}
    size_t GetSQUAD_HEALTH(void) const{return SQUAD_HEALTH;}
    loc_t GetHEROES(void) const{return HEROES;}
    
    //ПОЛОЖИЛИ
    string SetNAME(string str){
        NAME = str;
        return NAME;}
    size_t SetHEALTH(size_t health) {
        HEALTH = health;
        return HEALTH;}
    size_t SetDAMAGE(size_t damage) {
        DAMAGE = damage;
        return DAMAGE;}
    size_t SetTYPE_DAMAGE(size_t type_damage) {
        TYPE_DAMAGE = type_damage;
        return TYPE_DAMAGE;}
    size_t SetSPEED(size_t speed) {
        SPEED = speed;
        return SPEED;}
    size_t SetQUANTITY(size_t quantity) {
        QUANTITY = quantity;
        return QUANTITY;}
    size_t SetSQUAD_HEALTH(size_t squad_health) {
        SQUAD_HEALTH = squad_health;
        return SQUAD_HEALTH;}
    
    
    //Поступило в отряд
    virtual size_t Squad_Reinforcement(size_t Beginner) {
        QUANTITY=QUANTITY+Beginner;
        SQUAD_HEALTH = SQUAD_HEALTH + Beginner*HEALTH;
        return QUANTITY;}
    //Ушло из отряда
    virtual size_t Squad_Departed(size_t Departed_People) {
        if (Departed_People < QUANTITY){
            QUANTITY = QUANTITY - Departed_People;
            SQUAD_HEALTH = SQUAD_HEALTH - Departed_People*HEALTH;
        }else{
            QUANTITY = 0;
            SQUAD_HEALTH = 0;
        }
        return QUANTITY;
    }
    
    virtual ~Units(){
        if(debug){
            cout << NAME << " ,Units died, in quantity " << QUANTITY <<endl<<endl;
        }
    }
};




//МИРНЫЕ ЖИТЕЛИ

class Civilians : public Units{
    
public:
    Civilians(loc_t heroes = 0, string name = "Civilians",size_t damage  = 0,size_t type_damage = 0, size_t speed = 0, size_t quantity = 0,size_t health = 0, size_t squad_health = 0) : Units(heroes, name, damage, type_damage, speed, quantity, health, squad_health)
    {
        if(debug){
            cout<< "created new Civilians"<< GetHEROES()<<", ";
            if(GetNAME() != ""){
                cout << GetNAME();
            }else {cout << "no NAME";}
            cout << "HEALTH 1 units:"<< GetHEALTH() << endl;
            cout << "DAMAGE 1 units:"<< GetDAMAGE() << endl;
            cout << "TYPE_DAMAGE 1 units:"<< GetTYPE_DAMAGE() << endl;
            cout << "SPEED 1 units:"<< GetSPEED() << endl;
            cout << "QUANTITY units:"<< GetQUANTITY() << endl;
            cout << "SQUAD_HEALTH units:"<< GetSQUAD_HEALTH() << endl << endl;
            
        }
    }
    
    
    
    virtual size_t Squad_Reinforcement(size_t Beginner) {
        SetQUANTITY(GetQUANTITY()+Beginner);
        SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner*GetHEALTH());
        return GetQUANTITY();}
    virtual size_t Squad_Departed(size_t Departed_People) {
        if (Departed_People < GetQUANTITY()){
            SetQUANTITY(GetQUANTITY() - Departed_People);
            SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People*GetHEALTH());
        }else{
            SetQUANTITY(0);
            SetSQUAD_HEALTH(0);
        }
        return GetQUANTITY();
    }
    
    
    virtual ~Civilians(){
        if(debug){
            cout << GetNAME() << " ,Civilians died, in quantity " << GetQUANTITY() <<endl<<endl;
        }
    }
};






//ВОЕННЫЕ



class Military : public Units{
    
public:
    Military(loc_t heroes = 0, string name = "Military",size_t damage  = 0,size_t type_damage = 0, size_t speed = 0, size_t quantity = 0,size_t health = 0, size_t squad_health = 0) : Units(heroes, name, damage, type_damage, speed, quantity,health, squad_health)
    {
        if(debug){
            if(debug){
                cout<< "created new Military: "<< GetHEROES()<<", ";
                if(GetNAME() != ""){
                    cout << GetNAME();
                }else {cout << "no NAME";}
                cout <<endl<< "HEALTH 1 units:"<< GetHEALTH() << endl;
                cout << "DAMAGE 1 units:"<< GetDAMAGE() << endl;
                cout << "TYPE_DAMAGE 1 units:"<< GetTYPE_DAMAGE() << endl;
                cout << "SPEED 1 units:"<< GetSPEED() << endl;
                cout << "QUANTITY units:"<< GetQUANTITY() << endl;
                cout << "SQUAD_HEALTH units:"<< GetSQUAD_HEALTH() << endl<<endl;
                
            }
        }
    }
    
    virtual size_t Squad_Reinforcement(size_t Beginner) {
        SetQUANTITY(GetQUANTITY()+Beginner);
        SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner*GetHEALTH());
        return GetQUANTITY();}
    virtual size_t Squad_Departed(size_t Departed_People) {
        if (Departed_People < GetQUANTITY()){
            SetQUANTITY(GetQUANTITY() - Departed_People);
            SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People*GetHEALTH());
        }else{
            SetQUANTITY(0);
            SetSQUAD_HEALTH(0);
        }
        return GetQUANTITY();
    }
    
    virtual ~Military(){
        if(debug){
            cout << GetNAME() << " ,Military died, in quantity " << GetQUANTITY() <<endl<<endl;
        }
    }
};


int Units::counter = 0;


bool Units::debug = true;


//loc_t HEROES;           //какому отряду принадлежат  0-нейтралы 1-(1)герой  2-(2)герой
//string NAME;            //название отряда
//size_t DAMAGE;          //урон 1-го юнита
//size_t TYPE_DAMAGE;     //0-ближники 1- дальники
//size_t SPEED;           //скорость передвижения 1-го юнита
//size_t QUANTITY;        //количество юнитов в отряде
//size_t HEALTH;          //здоровье 1-го юнита
//size_t SQUAD_HEALTH;    //количество здоровья во всём отряде
int main() {
    Units *latnic1 = new Military(1,"latnic1",11,0,6,150,30,4500);
    Units *latnic2 = new Military(1,"latnic2",10,0,5,150,30,4500);
    Units *latnic3 = new Military(1,"asdasd",10,0,3,4,1,24);
    delete latnic1;
    delete latnic2;
    delete latnic3;
    return 0;
}



