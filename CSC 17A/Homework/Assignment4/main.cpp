/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on November 23, 2014, 10:17 PM
 * Purpose: AS 4 ch 13, 14
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
//User Libraries
#include "Prob1.h"
#include "Prob2.h"
#include "Prob3.h"
#include "Prob4.h"
#include "Prob5.h"
#include "Prob6.h"
#include "Prob7.h"
#include "Prog8.h"
#include "Prob10.h"
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
//Gaddis_7thEd_Chap13_Prob1
void prog1(){
  int d, m, y;
  do{
    cout<<"Input month :";
    cin>>m;
  }while(m<1 || m>12);
  do{
    cout<<"Input day :";
    cin>>d;
  }while(d<1 || d>31);
  cout<<"Input year :";
  cin>>y;
  Date p1(d, m, y);
  p1.print1();
  p1.print2();
  p1.print3();
}
//Gaddis_7thEd_Chap13_Prob2
void prog2(){
  string n, d, p;
  int num;
  Employee e1("Susan Meyers", 47899, "Accounting", "Vice President");
  Employee e2("Mark Jones", 39119, "IT", "Programmer");
  Employee e3("Joy Rogers", 81774, "Manufacturing", "Engineer");
  cout<<e1.getName()<<endl;
  cout<<e1.getNum()<<endl;
  cout<<e1.getDep()<<endl;
  cout<<e1.getPos()<<endl;
  cout<<e2.getName()<<endl;
  cout<<e2.getNum()<<endl;
  cout<<e2.getDep()<<endl;
  cout<<e2.getPos()<<endl;
  cout<<e3.getName()<<endl;
  cout<<e3.getNum()<<endl;
  cout<<e3.getDep()<<endl;
  cout<<e3.getPos()<<endl;
}
//Gaddis_7thEd_Chap13_Prob3
void prog3(){
  int yr;
  string make;
  cout<<"Input year model :";
  cin>>yr;
  cout<<"Input make of the car\n";
  getline(cin, make);
  Car car(yr, make);
  for(int i=0;i<5;i++){
    car.accelerate();
    cout<<"Accelerate\n";
    cout<<"Speed = "<<car.getSpeed()<<endl;
  }
  for(int i=0;i<5;i++){
    car.brake();
    cout<<"Brake\n";
  }
  cout<<"Speed = "<<car.getSpeed()<<endl;
}
//Gaddis_7thEd_Chap13_Prob4
void prog4(){
  Personal Me("Brian", "1234 A ave, Riverside", 20, "999-999-9999");
  Personal Tom("Tom", "4321 B ave, Riverside", 21, "111-111-1111");
  Personal K("K", "1357 C ave, Corona", 25, "123-456-7890");
  cout<<"Print data\n";
  cout<<Me.getName()<<endl;
  cout<<Me.getAddr()<<endl;
  cout<<Me.getAge()<<endl;
  cout<<Me.getTel()<<endl;
  cout<<endl;
  cout<<Tom.getName()<<endl;
  cout<<Tom.getAddr()<<endl;
  cout<<Tom.getAge()<<endl;
  cout<<Tom.getTel()<<endl;
  cout<<endl;
  cout<<K.getName()<<endl;
  cout<<K.getAddr()<<endl;
  cout<<K.getAge()<<endl;
  cout<<K.getTel()<<endl;
  cout<<endl;
}
//Gaddis_7thEd_Chap13_Prob5
void prog5(){
  RetailItem Item1("Jacket", 12, 59.95);
  RetailItem Item2("Designer Jeans", 40, 34.95);
  RetailItem Item3("Shirt", 20, 24.95);
  
  cout<<"Print data/n";
  cout<<Item1.getDes()<<endl;
  cout<<Item1.getUnit()<<endl;
  cout<<Item1.getPrice()<<endl;
  cout<<endl;
  cout<<Item2.getDes()<<endl;
  cout<<Item2.getUnit()<<endl;
  cout<<Item2.getPrice()<<endl;
  cout<<endl;
  cout<<Item3.getDes()<<endl;
  cout<<Item3.getUnit()<<endl;
  cout<<Item3.getPrice()<<endl;
  cout<<endl;
}
//Gaddis_7thEd_Chap14_Prob2
void prog6(){
  int num;
  do{
    cout<<"Input a day: ";
    cin>>num;
  }while(num<1 || num>365);
  DayOfYear test(num);
  test.print();
}
//Gaddis_7thEd_Chap14_Prob3
void prog7(){
  const string month[12]={"January ","February ","March ","April ","May ","June ",
                    "July ","August ","September ","October ","November ",
                    "December "};
  string inMonth;
  bool invalid;
  const int year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int day;
  int i=-1;
  do{
    i=-1;
    cout<<"Input month (e.g. January) \n";
    getline(cin, inMonth);
    cout<<"Input day :";
    cin>>day;
    do{
      i++;
    }while(strcmp(inMonth.c_str(), month[i].c_str())!=0 && i<12);
    if(day>year[i]){
      cout<<"invalid input\n";
    }
  }while(day>year[i]);
  DayOfYear7 prog7(inMonth, day);
  DayOfYear7 temp(inMonth, day);
  prog7.p7();
  cout<<"prefix ++\n";
  temp=++prog7;
  cout<<temp.getDay()<<endl;
  cout<<"prefix --\n";
  temp=--prog7;
  cout<<temp.getDay()<<endl;
  cout<<"postfix ++\n";
  temp=prog7++;
  cout<<temp.getDay()<<endl;
  cout<<"postfix --\n";
  temp=prog7--;
  cout<<temp.getDay()<<endl;
}
//Gaddis_7thEd_Chap14_Prob4
void prog8(){
  NumDays a(12);
  NumDays b(8);
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
  cout<<"A=A+B\n";
  a=a+b;
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
  cout<<"A=A-B\n";
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
  cout<<"a=b++\n";
  a=b++;
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
  cout<<"a=++b\n";
  a=++b;
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
  cout<<"a=b--\n";
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
  cout<<"a=--b\n";
  a=--b;
  cout<<"A, Day = "<<a.getDay()<<" hr = "<<a.getHr()<<endl;
  cout<<"B, Day = "<<b.getDay()<<" hr = "<<b.getHr()<<endl;
}
//Gaddis_7thEd_Chap14_Prob9
void prog9(){
  int d, m, y;
  do{
    cout<<"Input month :";
    cin>>m;
  }while(m<1 || m>12);
  do{
    cout<<"Input day :";
    cin>>d;
  }while(d<1 || d>31);
  cout<<"Input year :";
  cin>>y;
  Date a(d, m, y);
  Date b(d+1, m, y);
  cout<<"Overloading <<\n";
  cout<<"A = "<<a<<"b="<<b;
  cout<<"C=A-B\n";
  Date c;
  c=a-b;
  cout<<"day="<<c.getDay()<<endl;
  cout<<"a=b++\n";
  cout<<"Overloading <<\n";
  cout<<"A = "<<a<<"b="<<b;
  cout<<"a=++b\n";
  cout<<"Overloading <<\n";
  cout<<"A = "<<a<<"b="<<b;
  cout<<"a=b--\n";
  cout<<"Overloading <<\n";
  cout<<"A = "<<a<<"b="<<b;
  cout<<"a=--b\n";
  cout<<"Overloading <<\n";
  cout<<"A = "<<a<<"b="<<b;
  cout<<"Overloading >>\n";
  cin>>a;
  cout<<"A = "<<a;
}
//Gaddis_7thEd_Chap14_Prob7
void prog10(){
  cout<<"Month class\n";
  Month p10;
  Month temp;
  cout<<"overloading operator >> \n";
  cin>>p10;
  cout<<"Overloading operator << \n";
  cout<<"A = "<<p10;
  cout<<"B = "<<temp;
  cout<<"A=B++\n";
  p10=temp++;
  cout<<"A = "<<p10;
  cout<<"B = "<<temp;
  cout<<"A=++B\n";
  p10=++temp;
  cout<<"A = "<<p10;
  cout<<"B = "<<temp;
  cout<<"A=B--\n";
  p10=temp--;
  cout<<"A = "<<p10;
  cout<<"B = "<<temp;
  cout<<"A=--B\n";
  p10=--temp;
  cout<<"A = "<<p10;
  cout<<"B = "<<temp;
}
void def(){
    cout<<"Program ends\n";
}
