/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on November 30, 2014, 11:20 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  int f, r1, r2, r0;
  do{
    cout<<"Input F : ";
    cin>>f;
  }while(f<32 || f>212);
  f-=32;
  r1=f;
  int r6=0x8e38f;
  r1*=r6;
  r1>>=20;
  cout<<"C="<<r1;
  return 0;
}

