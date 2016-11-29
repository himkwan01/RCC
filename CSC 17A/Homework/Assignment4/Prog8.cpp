/* 
 * File:   Prog8.cpp
 * Author: Himkw_000
 * 
 * Created on November 28, 2014, 11:24 PM
 */

#include "Prog8.h"

NumDays NumDays::operator +(const NumDays &right){
  NumDays temp;
  temp.hr=hr+right.hr;
  temp.setDay();
  return temp;
}
NumDays NumDays::operator -(const NumDays &right){
  NumDays temp;
  temp.hr=hr-right.hr;
  temp.setDay();
  return temp;
}
NumDays NumDays::operator ++(){
  hr++;
  setDay();
  return *this;
}
NumDays NumDays::operator --(){
  hr--;
  setDay();
  return *this;
}
NumDays NumDays::operator ++(int){
  NumDays temp;
  temp.setDay();
  hr++;
  return temp;
}
NumDays NumDays::operator --(int){
  NumDays temp;
  temp.setDay();
  hr--;
  return temp;
}