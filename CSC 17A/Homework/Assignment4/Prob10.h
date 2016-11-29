/* 
 * File:   Prob10.h
 * Author: Himkw_000
 *
 * Created on November 29, 2014, 4:16 PM
 */

#ifndef PROB10_H
#define	PROB10_H
#include <iostream>
#include <string.h>
using namespace std;
class Month {
public:
  Month();
  Month(string);
  Month(int);
  int getNum(){
    return monthNumber;
  }
  string getName(){
    return name;
  }
  void setNum(int num){
    monthNumber=num;
  }
  void setName(string name){
    this->name=name;
  }
  void setMonth();
  Month operator ++();
  Month operator ++(int);
  Month operator --();
  Month operator --(int);
  friend ostream &operator <<(ostream &, const Month &);
  friend istream &operator >>(istream &, Month &);
private:
  string name;
  int monthNumber;
};

#endif	/* PROB10_H */

