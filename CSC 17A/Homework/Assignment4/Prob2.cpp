/* 
 * File:   Prob2.cpp
 * Author: Himkw_000
 * 
 * Created on November 23, 2014, 10:37 PM
 */
#include <cstring>
#include <iostream>
using namespace std;
#include "Prob2.h"

Employee::Employee(){
  name="";
  idNum=0;
  dep="";
  pos="";
}
Employee::Employee(string n, int num){
  name=n;
  idNum=num;
  dep="";
  pos="";
}
Employee::Employee(string n, int num, string d, string p){
  name=n;
  idNum=num;
  dep=d;
  pos=p;
}

