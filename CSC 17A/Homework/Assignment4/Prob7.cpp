/* 
 * File:   Prob7.cpp
 * Author: Himkw_000
 * 
 * Created on November 28, 2014, 10:22 PM
 */

#include "Prob7.h"
#include "Prob6.h"
#include <iostream>
#include <string.h>
using namespace std;
DayOfYear7::DayOfYear7(string inMonth, int number){
  this->inMonth=inMonth;
  this->number=number;
}
void DayOfYear7::p7(){
  string month[12]={"January","February","March","April","May","June",
                    "July","August","September","October","November",
                    "December"};
  int year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  day=0;
  int i=-1;
  do{
    i++;
  }while(strcmp(inMonth.c_str(), month[i].c_str())!=0 && i<12);
  cout<<"i="<<i<<endl;
  for(int a=0;a<i;a++){
    day+=year[i];
  }
  day+=number;
  cout<<inMonth<<" "<<number<<" = day "<<day<<endl;
}

void DayOfYear7::preday(){
  day--;
  if(day==0)day=365;
}
