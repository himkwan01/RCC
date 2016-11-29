/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on November 30, 2014, 11:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
void divMod(int &,int &,int &);
void scaleLeft(int &,int &,int &);
void scaleRight(int &,int &,int &);
void addSub(int &,int &, int &);
int main() {
  //declare variable
	int r0, r1, r2, f;
  time_t start, end;
	//Display the result
  do{
    cout<<"Input F:";
    cin>>f;
  }while(f<32 || f>212);
  start=time(0);
  for(int j=0;j<20;j++){
    for(int i=0;i<1000000;i++){
      r1=f;
      r1=(r1-32)*5;
      r2=9;
      //Determine the quotient and remainder
      divMod(r0, r1, r2);
    }
  }
  r1=r0;
  end=time(0);
	//Display the calculated results
	cout<<r1<<"C\n";
  cout<<"time="<<difftime(end,start)<<endl;
  
  start=time(0);
  for(int j=0;j<20;j++){
    for(int i=0;i<1000000;i++){
      r1=f;
      r1-=32;
      int r6=0x8e38f;
      r1*=r6;
      r1>>=20;
    }
  }
  end=time(0);
	//Display the calculated results
	cout<<r1<<"C\n";
  cout<<"time="<<difftime(end,start)<<endl;
	//Exit
	return 0;
}
void scaleLeft(int &r1,int &r2,int &r3){
	do{
    r3*=2;
    r2*=2;
	}while(r1>=r2);
	r3>>=1;
	r2>>=1;
}
void scaleRight(int &r1, int &r2, int &r3){
	do{
		r3>>=1;
		r2>>=1;
	}while(r1<r2);
}
void addSub(int &r0,int &r1,int &r2,int &r3){
	do{
		r0+=r3;
    r1-=r2;
    scaleRight(r1, r2, r3);
	}while(r3>=1);
}
void divMod(int &r0, int &r1,int &r2){
	r0=0;
  int r3=1;
  if(r1>=r2){
    scaleLeft(r1, r2, r3);
    addSub(r0, r1, r2, r3);
  }
}