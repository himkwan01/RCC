/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on November 29, 2014, 5:09 PM
 * Assignment 5 chap 15-16
 */
//System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
//User Libraries
#include "Prob1.h"
#include "Time.h"
#include "Date.h"
#include "Essay.h"
//function prototypes
void menu();
int getN();
void prog1();
void prog2();
void prog3();
void prog4();
void prog5();
void prog6();
void prog7();
void prog8();
void prog9();
void prog10();
void def();
void testM(int);
void testD(int);
template <class T>
T minimum(T num1, T num2){
  if(num1>num2) return num2;
  else return num1;
}
template <class T>
T maximum(T num1, T num2){
  if(num1>num2) return num1;
  else return num2;
}
template <class T>
T absolute(T num){
  return abs(num);
}
template <class T>
void total(T num, T &ttl){
  ttl+=num;
}
int main(int argc, char** argv) {
  int num;
    do{
        menu();
        num=getN();
        switch(num){
            case 1:prog1();break;
            case 2:prog2();break;
            case 3:prog3();break;
            case 4:prog4();break;
            case 5:prog5();break;
            case 6:prog6();break;
            case 7:prog7();break;
            case 8:prog8();break;
            case 9:prog9();break;
            case 10:prog10();break;
            default:def();break;
        }
    }while(num<11);
    return 0;
}
void menu(){
    cout<<"Type 1 to run prog1\n";
    cout<<"Type 2 to run prog2\n";
    cout<<"Type 3 to run prog3\n";
    cout<<"Type 4 to run prog4\n";
    cout<<"Type 5 to run prog5\n";
    cout<<"Type 6 to run prog6\n";
    cout<<"Type 7 to run prog7\n";
    cout<<"Type 8 to run prog8\n";
    cout<<"Type 9 to run prog9\n";
    cout<<"Type 10 to run prog10\n";
    cout<<"Type 11 to exit\n";  
}
int getN(){
    int num;
    cin>>num;
    cin.ignore();
    return num;
}
//Gaddis_7thEd_Chap15_Prob1
void prog1(){
  string name;
  string date;
  int num, shift;
  float pyrt;
  cout<<"Input name\n";
  getline(cin, name);
  cout<<"Input ID : ";
  cin>>num;
  cin.ignore();
  cout<<"Input hire date with MM/DD/YY format\n";
  getline(cin, date);
  cout<<"Input shift (1=day, 2=night) :";
  cin>>shift;
  cout<<"Input hourly pay rate : ";
  cin>>pyrt;
  ProductionWorker a(name, num, date, shift, pyrt);
  cout<<a;
}
//Gaddis_7thEd_Chap15_Prob2
void prog2(){
  string name;
  string date;
  int num;
  float annual;
  cout<<"Input name\n";
  getline(cin, name);
  cout<<"Input ID : ";
  cin>>num;
  cin.ignore();
  cout<<"Input hire date with MM/DD/YY format\n";
  getline(cin, date);
  cout<<"Input annual salary: ";
  cin>>annual;
  ShiftSupervisor a(name, num, date, annual);
  //cout<<a;
}
//Gaddis_7thEd_Chap15_Prob3
void prog3(){
  float g, s, cl, c;
  cout<<"GradedActivity and Essay\n";
  cout<<"input grammar score max=30\n";
  cin>>g;
  cout<<"input spelling score max=20\n";
  cin>>s;
  cout<<"input correct length score max=20\n";
  cin>>cl;
  cout<<"input content score max=30\n";
  cin>>c;
  Essay a(g, s, cl, c);
  cout<<"score = "<<a.getScore()<<"\n\n";
}
//Gaddis_7thEd_Chap15_Prob4
void prog4(){
  cout<<"Military time conversion\n";
  int h, s;
  do{
    cout<<"Input hour in military format\n";
    cin>>h;
  }while(h<0 || h>2359);
  do{
    cout<<"Input second\n";
    cin>>s;
  }while(s<0 ||s>59);
  MilTime mh(h, s);
  cout<<"Hour="<<mh.getHour()<<endl;
  cout<<"Standard hour="<<mh.getStandHr()<<"\n\n";
}
//Gaddis_7thEd_Chap15_Prob5
void prog5(){
  cout<<"TimeClock\n";
  int sh, eh;
  do{
    do{
      cout<<"Input start time in XX:XX military format\n";
      cin>>sh;
    }while(sh<0 || sh>2359);
    do{
      cout<<"Input end time in XX:XX military format\n";
      cin>>eh;
    }while(eh<0 || eh>2359);
  }while(sh>eh);
  TimeClock p5(eh, sh);
  cout<<"The elapsed time is "<<p5.elapsed()<<" hours\n";
}
//Gaddis_7thEd_Chap16_Prob1
void prog6(){
  cout<<"Date Exceptions\n";
  int d, m, y;
  bool valid;
  do{
    valid=true;
    cout<<"Input month :";
    cin>>m;
    try{
      testM(m);
    }catch(string temp){
      cout<<temp;
      valid=false;
    }
  }while(valid==false);
  do{
    valid=true;
    cout<<"Input day :";
    cin>>d;
    try{
      testD(d);
    }catch(string temp){
      cout<<temp;
      valid=false;
    }
  }while(valid==false);
  cout<<"Input year :";
  cin>>y;
  Date p1(d, m, y);
  p1.print1();
  p1.print2();
  p1.print3();
}
//Gaddis_7thEd_Chap14_Prob3
void prog7(){
  cout<<"TimeFormatExceptions\n";
  int h, s;
  cout<<"Input hour in military format\n";
  cin>>h;
  cout<<"Input second\n";
  cin>>s;
  try{
    MilTime test(h,s);
    cout<<"Hour="<<test.getHour()<<endl;
    cout<<"Standard hour="<<test.getStandHr()<<"\n\n";
  }catch(MilTime::BadHour){
    cout<<"BadHour\n";
  }catch(MilTime::BadSeconds){
    cout<<"BadSeconds\n";
  }
}
//Gaddis_7thEd_Chap16_Prob3
void prog8(){
  cout<<"min/max template\n";
  int i1,i2;
  float f1, f2;
  cout<<"input 2 int with space\n";
  cin>>i1>>i2;
  cout<<minimum(i1,i2)<<" is minimum\n";
  cout<<maximum(i1,i2)<<" is maximum\n";
  cout<<"input 2 float with space\n";
  cin>>f1>>f2;
  cout<<minimum(f1,f2)<<" is minimum\n";
  cout<<maximum(f1,f2)<<" is maximum\n";
  
}
//Gaddis_7thEd_Chap16_Prob4
void prog9(){
  int i1,i2;
  float f1, f2;
  cout<<"absolute value template\n";
  cout<<"input a int with space\n";
  cin>>i1;
  cout<<"Absolute value = "<<absolute(i1)<<endl;
  cout<<"input a float with space\n";
  cin>>f1;
  cout<<"Absolute value = "<<absolute(f1)<<endl;
}
//Gaddis_7thEd_Chap16_Prob5
void prog10(){
  cout<<"total template\n";
  cout<<"Input integer (total 5 inputs)\n";
  int num, ttl=0;
  float fnum, fttl=0;
  for(int i=0;i<5;i++){
    cout<<i+1<<" input\n";
    cin>>num;
    total(num, ttl);
    cout<<"total = "<<ttl<<endl;
  }
  cout<<"Input float (total 5 inputs)\n";
  for(int i=0;i<5;i++){
    cout<<i+1<<" input\n";
    cin>>fnum;
    total(fnum, fttl);
    cout<<"total = "<<fttl<<endl;
  }
}
void def(){
    cout<<"Program ends\n";
}
void testM(int m){
  if(m<1 || m>12){
    string temp;
    temp="Invalid month/n";
    throw temp;
  }
}
void testD(int d){
  if(d<1 || d>31){
    string temp;
    temp="Invalid day\n";
    throw temp;
  }
}
