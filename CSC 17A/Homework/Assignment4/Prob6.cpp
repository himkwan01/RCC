/* 
 * File:   Prob6.cpp
 * Author: Himkw_000
 * 
 * Created on November 25, 2014, 10:41 AM
 */
#include <cstring>
#include <iostream>
using namespace std;
#include "Prob6.h"

DayOfYear::DayOfYear(int number){
  this->number=number;
}
void DayOfYear::print(){
  int temp=number;
  
  int i=0;
  bool done=false;
  string month[12]={"January","February","March","April","May","June",
                    "July","August","September","October","November",
                    "December"};
  int year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  do{
//    cout<<"loop\n";
//    cout<<number<<endl<<year[i]<<endl;
    if(temp-year[i]<0){
      if(temp==0){
        temp=year[i-1];
        i--;
      }
      cout<<"Day "<<number<<" would be "<<month[i]<<" ";
      
      cout<<temp<<endl;
      done=true;
    }
    else{
      temp-=year[i];
      i++;
    }
  }while(done==false);
  
}
