/* 
 * File:   Prob6.h
 * Author: Himkw_000
 *
 * Created on November 25, 2014, 10:41 AM
 */

#ifndef PROB6_H
#define	PROB6_H
#include <iostream>
#include <string.h>
using namespace std;
class DayOfYear {
public:
  DayOfYear(int);
  void print();
private:
  int number;
  string inMonth;
  int day;
};

#endif	/* PROB6_H */

