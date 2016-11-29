/* 
 * File:   Prob1.cpp
 * Author: Himkw_000
 * 
 * Created on November 29, 2014, 5:10 PM
 */

#include "Prob1.h"
#include <iostream>
using namespace std;
 Employee::Employee(string name,int num, string date){
    this->name=name;
    this->num=num;
    this->date=date;
  }
ProductionWorker::ProductionWorker
(string name, int num, string date, 
        int shift, float pyrt)
        :Employee(name, num, date){
  this->shift=shift;
  this->pyrt=pyrt;
}
ostream &operator << (ostream &strm, const ProductionWorker &obj){
  strm<<"Name: "<<obj.name<<endl;
  strm<<"ID: "<<obj.num<<endl;
  strm<<"Hire date: "<<obj.date<<endl;
  strm<<"Shift: "<<obj.shift<<endl;
  strm<<"Hourly pay rate: $"<<obj.pyrt<<endl;
}
ShiftSupervisor::ShiftSupervisor(string name, int num, string date, 
                 float annual)
                :Employee(name, num, date){
  this->annual=annual;
  bonus=annual*0.2;
}
ostream &operator <<(ostream &strm, const ShiftSupervisor &obj){
  strm<<"Name: "<<obj.name<<endl;
  strm<<"ID: "<<obj.num<<endl;
  strm<<"Hire date: "<<obj.date<<endl;
  strm<<"Annual salary : "<<obj.annual<<endl;
  strm<<"Production bonus : "<<obj.bonus<<endl;
  strm<<"If you reach the goal, you will have "<<obj.bonus<<" bonus\n";
}