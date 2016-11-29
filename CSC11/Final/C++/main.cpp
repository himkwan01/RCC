/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on December 7, 2014, 9:14 PM
 * Purpose: CSC 11 final C++ version
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void intro();
void prog1();
void prog2();
void prog3();
void prog4();

//System Begins Here
int main(int argc, char** argv) {
  cout<<fixed<<showpoint<<setprecision(2);
  //declare variables
  int r1;
  do{
    intro();
    cin>>r1;
    switch(r1){
      case 1: prog1(); break;
      case 2: prog2(); break;
      case 3: prog3(); break;
      case 4: prog4(); break;
      default:break;
    }
  }while(r1<5);
  cout<<"Press "<<r1<<" to exit\n";
  return 0;
}
void intro(){
  cout<<"Menu\n";
  cout<<"Press 1 to run prog1\n";
  cout<<"Press 2 to run prog2\n";
  cout<<"Press 3 to run prog3\n";
  cout<<"Press 4 to run prog4\n";
  cout<<"Press 5 to exit\n";
}

void prog1(){
  srand(time(0));
  int input;
  bool done;
  char a;
  cout<<"I have a number between 1 and 1000\nCan you guess my number?\n";
  cout<<"You will be given a maximum of 10 guesses.\n";
  do{
    int ans=rand()%1000;
    int count=1;
    done=false;
    do{
      cout<<count<<" try\n";
      cin>>input;
      if(count==11)cout<<"Too many tries\n";
      else if(input<ans)
        cout<<"2. Too low.  Try again.\n";
      else if(input>ans)
        cout<<"3. Too High. Try again.\n";
      else{
        cout<<"Congratulations, You guessed the number!\n";
        done=true;
      }
      count++;
    }while(count<=11 && done==false);
    do{
      cout<<"Would you like to play again(y or n)?\n";
      cin>>a;
    }while(a!='n' && a!='y');
  }while(a=='y');
}
void prog2(){
  int year;
  float prtvle;
  float intrt;
  cout<<"Input the number of years 1-20\n";
  cin>>year;
  cout<<"Inptut the percentage of the interest rate (5%-10%) 5% input 5\n";
  cin>>intrt;
  cout<<"Input the present value $1000-5000\n";
  cin>>prtvle;
  float *t = new float[year];
  intrt/=100;
  intrt+=1;
  for(int i=0;i<year;i++){
    t[i]=prtvle*intrt;
    prtvle=t[i];
    cout<<i+1<<" year, the value = $"<<t[i]<<endl;
  }
  delete []t;
}
void prog3(){
  int in;
  float output;
  float x0=0, x1;
  cout<<"Square root\n";
  cout<<"input a integer between 1 and 10000\n";
  cin>>in;
  if(in<10) x0=100;
  else if(in<100) x0=200;
  else if(in<1000) x0=300;
  else if(in<10000) x0=500;
  else if(in==10000) x0=600;
  x1=0.5*(x0+static_cast<float>(in)/x0);
  do{
    x0=x1;
    x1=0.5*(x0+static_cast<float>(in)/x0);
  }while(x0!=x1);
  cout<<"the square is "<<x1<<endl;
  
}
void prog4(){
  int x;
  int a=0x12b02;
  int b=0xe04188;
  int ans;
  cout<<"find ax^2 +bx\n";
  cout<<"input x (0-255)\n";
  cin>>x;
  ans=a*x;
  ans>>=4;
  ans*=x;
  b*=x;
  b>>=8;
  ans+=b;
  ans>>=16;
  cout<<"answer = "<<ans<<endl;
}