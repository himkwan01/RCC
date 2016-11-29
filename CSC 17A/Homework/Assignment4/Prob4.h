/* 
 * File:   Prob4.h
 * Author: Himkw_000
 *
 * Created on November 25, 2014, 10:22 AM
 */

#ifndef PROB4_H
#define	PROB4_H
#include <cstring>
#include <iostream>
using namespace std;

class Personal{
public:
  Personal(string, string, int, string);
  string getName(){
    return name;
  }
  string getAddr(){
    return addr;
  }
  int getAge(){
    return age;
  }
  string getTel(){
    return tel;
  }
private:
  string name;
  string addr;
  int age;
  string tel;
};

#endif	/* PROB4_H */

