/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on November 30, 2014, 11:25 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  int v, r;
  cout<<"V=";
  cin>>v;
  cout<<"r=";
  cin>>r;
  int r3=1;
  int r4=0x9b5;
  int r5=v;
  int r6=0x3243f7;
  int r7=r;
  int r8=0x1c7;
  int r9=0x666;
  
  r3*=r4;
  r3*=r5;
  r3*=r5;
  r3>>=12;
  r6*=r7;
  r6*=r7;
  r6>>=12;
  r6*=r8;
  r6>>=16;
  int r10=r3*r6;
  r10>>=12;
  r10*=r9;
  
  r3>>=9;
  r6>>=3;
  r10>>=12;
  
  int r1=r3;
  cout<<"dynp="<<r3<<endl;
  r1=r6;
  cout<<"area="<<r1<<endl;
  r1=r10;
  cout<<"drag="<<r1<<endl;
  return 0;
}

