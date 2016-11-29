/* 
 * File:   Prob3.h
 * Author: Himkw_000
 *
 * Created on November 23, 2014, 11:34 PM
 */

#ifndef PROB3_H
#define	PROB3_H
#include <iostream>
#include <cstring>
using namespace std;
class Car{
public:
  Car(int, string);
  int getYear(){
    return yearModel;
  }
  string getMake(){
    return make;
  }
  int getSpeed(){
    return speed;
  }
  void accelerate(){
    speed+=5;
  }
  void brake(){
    speed-=5;
  }
private:
  int yearModel;
  string make;
  int speed;
};

#endif	/* PROB3_H */

