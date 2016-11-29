/* 
 * File:   SavingsAccount.cpp
 * Author: Himkw_000
 * 
 * Created on December 10, 2014, 12:37 PM
 */

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(float balance){
  if(balance<0){
    string negativeException="WithDraw not Allowed\n";
    cout<<negativeException;
    Balance=0;
  }
  else{
    Balance=balance;
  }
  FreqWithDraw=0;
  FreqDeposit=0;
}
void SavingsAccount::Transaction(float tran){
  if(tran>0){
    Balance+=Deposit(tran);
  }
  else
    if(Balance+tran>0)
      Balance+=Withdraw(tran);
    else
      cout<<"WithDraw not Allowed\n";
}
float SavingsAccount::Withdraw(float tran){
  FreqWithDraw++;
  return tran;
}
float SavingsAccount::Deposit(float tran){
  FreqDeposit++;
  return tran;
}
float SavingsAccount::Total(float intrt=0, int year=0){
  float temp=Balance;
  for(int i=0;i<year;i++){
    temp*=(1+intrt);
  }
  return temp;
}
float SavingsAccount::TotalRecursive(float intrt=0, int year=7){
  Balance*=(1+intrt);
  if(year==1){
    return Balance;
  }
  else
    //cout<<"B="<<Balance<<endl;
    return TotalRecursive(intrt, year-1);
}
void SavingsAccount::toString(){
  cout<<"Balance="<<Balance<<endl;
  cout<<"WithDraws="<<FreqWithDraw<<endl;
  cout<<"Deposit="<<FreqDeposit<<endl;
}