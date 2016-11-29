/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on December 4, 2014, 11:26 AM
 * Purpose: final
 */


//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <fstream>
using namespace std;
//User Libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Employee.h"
#include "SavingsAccount.h"
//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

float f2dec(string, vector<int> &);
//System Begins Here
int main(int argc, char** argv) {
    cout<<showpoint<<setprecision(7);
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1: problem1();break;
        case 2: problem2();break;
        case 3: problem3();break;
        case 4: problem4();break;
        case 5: problem5();break;
        case 6: problem6();break;
            default:;
        };
    }while(inN<7);
    return 0;
}

//Menu Function
void Menu(){
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        cin.ignore();
        return inN;
}

void problem1(){
  char n=5;
	char rndseq[]={16,34,57,79,144};
	int ntimes=100000;
	Prob1Random a(n,rndseq);
	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}
	int *x=a.getFreq();
	unsigned char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}
void problem2(){
  cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*17];
	char *ch2p=ch2;
  int i=0;
	while(infile.get(ch2[i])){cout<<ch2[i];i++;}
	infile.close();
	cout<<endl;
//  for(int i=0;i<170;i++){
//    cout<<ch2p[i];
//  }
//  cout<<"\n\n";
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	
	char *zc=rc.sortArray(ch2p,10,17,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<17;j++)
		{
			cout<<zc[i*17+j];
		}
	}
	delete []zc;
	cout<<endl;
}
void problem3(){
  cout<<"Entering problem number 3"<<endl;
  int rows=5;
	int cols=6;
//  Prob3Table<int> test("Problem3.txt", rows, cols);
  Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
  const int *naugT=tab.getTable();
  for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
}
void problem4(){
  SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
      <<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
      <<mine.TotalRecursive((float)(0.10),7)
    	<<" Recursive Calculation "<<endl;
    
}
void problem5(){
   Employee Mark("Mark","Boss",215.50);
   Mark.setHoursWorked(-3);
   Mark.toString();
   Mark.CalculatePay(Mark.setHourlyRate(20.0),
                     Mark.setHoursWorked(25));
   Mark.toString();
   Mark.CalculatePay(Mark.setHourlyRate(40.0),
                     Mark.setHoursWorked(25));
   Mark.toString();
   Mark.CalculatePay(Mark.setHourlyRate(60.0),
                     Mark.setHoursWorked(25));
   Mark.toString();
   Employee Mary("Mary","VP",50.0);
   Mary.toString();
   Mary.CalculatePay(Mary.setHourlyRate(50.0),
                     Mary.setHoursWorked(40));
   Mary.toString();
   Mary.CalculatePay(Mary.setHourlyRate(50.0),
                     Mary.setHoursWorked(50));
   Mary.toString();
   Mary.CalculatePay(Mary.setHourlyRate(50.0),
                     Mary.setHoursWorked(60));
   Mary.toString();
   
}
void problem6(){
    vector<int> bin1;    //binary vector
    bool invalid;
    string af="4207999A", bf="44861333", cf="3D8F5C29", temp;
    cout<<"Calculated by program\n";
    bin1.clear();
    cout<<af<<" = "<<f2dec(af, bin1)<<endl;
    bin1.clear();
    cout<<bf<<" = "<<f2dec(bf, bin1)<<endl;
    bin1.clear();
    cout<<cf<<" = "<<f2dec(cf, bin1)<<endl;
    bin1.clear();
    do{
      invalid=false;
      cout<<"You can input a IEE 754 Float to convert to decimal\n";
      cout<<"Please write upper case A-F\n";
      getline(cin, temp);
      if(temp.length()!=8){
        invalid=true;
      }
      else{
        for(int i=0;i<temp.length();i++){
          if(temp[i]<'0' || (temp[i]>'9' && temp[i]<'A') || temp[i]>'F')
            invalid=true;
        }
      }
    }while(invalid==true);
    cout<<temp<<" = "<<f2dec(temp, bin1)<<endl;
    cout<<"\nAnswer correct?\n10pts extra credit?\n\n";
}
float f2dec(string c, vector<int> &v1){
    int flo[32];
    vector<int>Int;
    vector<int>dec;
    float temp;
    int shift=1;
    int power;
    float shiftdec=1;
    int cnt=0;
    //string -> bin cvs
    //change to base 2 float
    for(int i=0;i<c.length();i++){
        if(c[i]>='A' && c[i]<='F'){
            temp=(c[i]-55);
        }
        else temp=(c[i]-48);
         //add 0 at the begin
        if(temp<8 && temp>=4) v1.push_back(0);
        else if(temp<4 && temp>=2){
            v1.push_back(0);
            v1.push_back(0);
        }
        else if(temp<2 && temp>0){
            for(int i=0;i<3;i++)
                v1.push_back(0);
        }
        else if(temp==0){
            for(int i=0;i<4;i++){
                v1.push_back(0);
            }
        }
        if(temp>1){
            while(shift<=temp){
                shift<<=1;
                cnt++;
            }
            shift>>=1;
            temp-=shift;
            v1.push_back(1);
            do{
                if(shift>1) shift>>=1;
                if(shift<=temp && temp>0){
                    temp-=shift;
                    v1.push_back(1);
                }
                else
                    v1.push_back(0);
                cnt--;
            }while(cnt>1);
            cnt=0;
        }
        else if(temp>0) v1.push_back(1);
        temp=0;
    }
    /* string to bin cvs end
     * works fine
     * read power
     */
    power=0;
    for(int i=1;i<9;i++){
      power+=(v1[i]*pow(2,(8-i)));
    }
    power-=127;
    cout<<"power = "<<power<<endl;
    if(power>0){
      Int.push_back(1);
      for(int i=9;i<power+9;i++){
        Int.push_back(v1[i]);
      }
      for(int i=9+power;i<31;i++){
        dec.push_back(v1[i]);
      }
//      for(int i=0;i<Int.size();i++){
//        cout<<Int[i]<<" ";
//      }
//      cout<<endl;
      temp=0;
      //integer part
      for(int i=0;i<Int.size();i++){
        temp+=Int[i]*pow(2, power-i);
      }
//      cout<<"Temp = "<<temp<<endl;
      //dec part
      for(int i=0;i<dec.size();i++){
        temp+=dec[i]*(pow(2, -1-i));
      }
//      cout<<"Temp = "<<temp<<endl;
    }
    else if(power<0){
      
      for(int i=0;i<abs(power)-1;i++){
        dec.push_back(0);
      }
      dec.push_back(1);
      for(int i=9;i<31;i++){
        dec.push_back(v1[i]);
      }
      temp=0;
      //dec
      for(int i=dec.size()-1;i>=0;i--){
        temp+=dec[i]*(pow(2, -1-i));
      }
//      for(int i=0;i<dec.size();i++){
//        temp+=dec[i]*(pow(2, -1-i));
//      }
      cout<<"dsize "<<dec.size()<<endl;
    }
//    cout<<"Isize"<<Int.size()<<endl;
//    cout<<"dsize"<<dec.size()<<endl;
    if(v1[0]==1)temp*=-1;
//    v1.clear();
    return temp;
}