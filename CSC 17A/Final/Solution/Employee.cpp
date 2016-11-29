/* 
 * File:   Employee.cpp
 * Author: Himkw_000
 * 
 * Created on December 8, 2014, 12:34 PM
 */

#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;
Employee::Employee(char MyName[],char JobTitle[], float HourlyRate){
  for(int i=0;i<sizeof(MyName)*4;i++){
    this->MyName[i]=MyName[i];
  }
  for(int i=0;i<sizeof(JobTitle)*4;i++){
    this->JobTitle[i]=JobTitle[i];
  }
  if(HourlyRate>0 && HourlyRate<200)
    this->HourlyRate=HourlyRate;
  else{
    this->HourlyRate=0;
    cout<<"Unacceptable Hourly Rate\n";
  }
//  cout<<this->MyName<<endl;
//  cout<<this->JobTitle<<endl;
  HoursWorked=0;
  GrossPay=0;
  NetPay=0;
}
float Employee::getGrossPay(float HourlyRate, int HoursWorked){
  GrossPay=0;
  if(HoursWorked<=40){
    GrossPay=HoursWorked*HourlyRate;
  }
  else if(HoursWorked<=50){
    GrossPay=40*HourlyRate+(HoursWorked-40)*HourlyRate*1.5;
  }
  else{
    GrossPay=55*HourlyRate+(HoursWorked-50)*2*HourlyRate;
  }
  return GrossPay;
}
float Employee::getNetPay(float GrossPay){
  if(GrossPay<=500)NetPay=GrossPay*0.1;
  else if(GrossPay<=1000)NetPay=500*0.1+(GrossPay-500)*0.2;
  else NetPay=500*0.1+500*0.2+(GrossPay-1000)*0.3;
  NetPay=GrossPay-NetPay;
  return NetPay;
}
float Employee::CalculatePay(float HourlyRate, int HoursWorked){
  return getNetPay(getGrossPay(setHourlyRate(HourlyRate),
                    setHoursWorked(HoursWorked)));
}
void Employee::toString(){
  cout<<fixed<<showpoint<<setprecision(2);
  cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
  cout<<"Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked;
  cout<<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
}
float Employee::setHourlyRate(float HourlyRate){
  if(HourlyRate<0 || HourlyRate>200){
    cout<<"Unacceptable Hourly Rate\n";
    HourlyRate=0;
  }
  else
    this->HourlyRate=HourlyRate;
  return HourlyRate;
}
int Employee::setHoursWorked(int HoursWorked){
  if(HoursWorked<0 || HoursWorked>84){
    cout<<"Unacceptable Hours Worked\n";
    HoursWorked=0;
  }
  this->HoursWorked=HoursWorked;
  return HoursWorked;
}

