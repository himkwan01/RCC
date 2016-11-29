/* 
 * File:   Prob10.cpp
 * Author: Himkw_000
 * 
 * Created on November 29, 2014, 4:16 PM
 */
#include <string.h>
using namespace std;
#include "Prob10.h"
Month::Month(){
  name="January";
  monthNumber=1;
}
Month::Month(string name){
  this->name=name;
  if(strcmp(name.c_str(), "January")) monthNumber=1;
  else if(strcmp(name.c_str(), "February")) monthNumber=2;
  else if(strcmp(name.c_str(), "March")) monthNumber=3;
  else if(strcmp(name.c_str(), "April")) monthNumber=4;
  else if(strcmp(name.c_str(), "May")) monthNumber=5;
  else if(strcmp(name.c_str(), "June")) monthNumber=6;
  else if(strcmp(name.c_str(), "July")) monthNumber=7;
  else if(strcmp(name.c_str(), "August")) monthNumber=8;
  else if(strcmp(name.c_str(), "September")) monthNumber=9;
  else if(strcmp(name.c_str(), "October")) monthNumber=10;
  else if(strcmp(name.c_str(), "November")) monthNumber=11;
  else if(strcmp(name.c_str(), "December")) monthNumber=12;
}
Month::Month(int monthNumber){
  this->monthNumber=monthNumber;
  setMonth();
}
void Month::setMonth(){
  if(monthNumber==13)monthNumber=1;
  else if(monthNumber==0)monthNumber=12;
  
  switch(monthNumber){
    case 1: name="January"; break;
    case 2: name="February"; break;
    case 3: name="March"; break;
    case 4: name="April"; break;
    case 5: name="May"; break;
    case 6: name="June"; break;
    case 7: name="July"; break;
    case 8: name="August"; break;
    case 9: name="September"; break;
    case 10: name="October"; break;
    case 11: name="November"; break;
    case 12: name="December"; break;
  }
}
Month Month::operator ++(int){
  Month temp;
  monthNumber++;
  temp.setMonth();
  setMonth();
  return temp;
}
Month Month::operator ++(){
  monthNumber++;
  setMonth();
  return *this;
}
Month Month::operator --(int){
  Month temp;
  monthNumber--;
  temp.setMonth();
  setMonth();
  return temp;
}
Month Month::operator --(){
  monthNumber--;
  setMonth();
  return *this;
}
ostream &operator <<(ostream &strm, const Month &obj){
  strm<<obj.name<<" = "<<obj.monthNumber<<endl;
}
istream &operator >>(istream &strm, Month &obj){
  cout<<"Input Month Number : ";
  strm>>obj.monthNumber;
  obj.setMonth();
}