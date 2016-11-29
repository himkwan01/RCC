/* 
 * File:   Prob1.h
 * Author: Himkw_000
 *
 * Created on November 23, 2014, 10:19 PM
 */
#include <iostream>
using namespace std;
#ifndef PROB1_H
#define	PROB1_H

class Date {
public:
  Date(int d=0, int m=0, int y=0);
  string getMstr();
  void print1();
  void print2();
  void print3();
  Date operator +(const Date &);
  Date operator -(const Date &);
  Date operator ++();
  Date operator --();
  Date operator ++(int);
  Date operator --(int);
  friend ostream &operator << (ostream &, const Date &); //page 866 
  friend istream &operator >> (istream &, Date &); //type print2
  void setDate();
  int getDay(){
    return day;
  }
private:
  int month;
  int day;
  int year;
};
#endif	/* PROB1_H */

