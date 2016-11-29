/* 
 * File:   Prob7.h
 * Author: Himkw_000
 *
 * Created on November 28, 2014, 10:22 PM
 */

#ifndef PROB7_H
#define	PROB7_H
#include <iostream>
using namespace std;

class DayOfYear7 {
public:
  DayOfYear7(string, int);
  void p7();
  void nextday();
  void preday();
  //++a
  DayOfYear7 operator++(){
    day++;
    return *this;
  }
  //a++
  DayOfYear7 operator++(int){
    DayOfYear7 temp(inMonth, number);
    day++;
    return temp;
  }
  DayOfYear7 operator--(int){
    DayOfYear7 temp(inMonth, number);
    day--;
    return temp;
  }
  DayOfYear7 operator--(){
    day--;
    return *this;
  }
  int getDay(){
    if(day==366)day=1;
    else if(day==0)day=365;
    return day;
  }
private:
  
  int day;
  string inMonth;
  int number;
};

#endif	/* PROB7_H */

