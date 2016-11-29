/* 
 * File:   main.cpp
 * Author: Tsz  Kwan
 * Created on October 14, 2014, 10:11 AM
 * Purpose: Assignment 3
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries
#include "Struct.h"
//Global Constant

//Function Prototypes
void menu();
int getN();
void prog1();
void prog2();
void prog3();
void prog4();
void prog5();
void prog6();
void prog7();
void def();
void display(Prog3 &);

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
            default:def();break;
        }
    }while(num<8);
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
    cout<<"Type 8 to exit\n";  
}
int getN(){
    int num;
    cin>>num;
    return num;
}
//chap 11 prob1
void prog1(){
    MovieData a={"titleA", "DirA", 2014, 131};
    MovieData b={"titleB", "DirB", 2001, 142};
    cout<<"Movie a"<<setw(10)<<"Movie b\n";
    cout<<a.ttle<<setw(10)<<b.ttle<<endl;
    cout<<a.dir<<setw(10)<<b.dir<<endl;
    cout<<a.yrRls<<setw(10)<<b.yrRls<<endl;
    cout<<a.runt<<setw(10)<<b.runt<<"\n\n";
}
//chap 11 prob2
void prog2(){
    MovieData a={"titleA", "DirA", 2014, 131, 130000, 140000};
    MovieData b={"titleB", "DirB", 2001, 142, 150000, 120000};
    cout<<setw(13)<<"Movie a"<<setw(27)<<"Movie b\n";
    cout<<setw(13)<<a.ttle<<setw(25)<<b.ttle<<endl;
    cout<<setw(13)<<a.dir<<setw(25)<<b.dir<<endl;
    cout<<setw(13)<<a.yrRls<<setw(25)<<b.yrRls<<endl;
    cout<<setw(13)<<a.runt<<setw(25)<<b.runt<<"\n\n";
    cout<<"First year ";
    if(a.cost>a.yrrv) cout<<"profit = $";
    else cout<<"loss = $";
    cout<<abs(a.cost-a.yrrv)<<setw(15);
    cout<<"First year ";
    if(b.cost>b.yrrv) cout<<"profit = $";
    else cout<<"loss = $";
    cout<<abs(b.cost-b.yrrv)<<"\n\n";
    
}
//chap 11 prob3
void prog3(){
    float a[4];
    string str[]={"East", "West", "North", "South"};
    Prog3 dir[4];
    for(int i=0;i<4;i++){
        cout<<"Please enter "<<str[i]<<" of First to Forth Quarter Sales with space\n";
        for(int j=0;j<4;j++){
            cin>>a[j];
        }
        dir[i].n1=a[0];
        dir[i].n2=a[1];
        dir[i].n3=a[2];
        dir[i].n4=a[3];
    }
    for(int i=0;i<4;i++){
        i=0;
        cout<<str[i];
        display(dir[i]);
    }
    cout<<"\n\n\n";
}
//chap 11 prob4
void prog4(){
    float temp;
    float high=-100;
    int highm=0;
    float low=140;
    int lowm=0;
    Prog4 p4[12];
    cout<<"This prog show the weather statistics\n\n";
    for(int i=0;i++;i<12){
        cout<<"Month "<<i+1<<endl;
        cout<<"Total rainfall = ";
        cin>>temp;
        p4[i].ttl=temp;
        do{
            cout<<"High Temperature (Fahrenheit)= ";
            cin>>temp;
        }while(temp>-100 && temp<140);
        p4[i].high=temp;
        do{
            cout<<"Low Temperature (Fahrenheit)= ";
            cin>>temp;
        }while(temp>=-100 && temp<140);
        p4[i].low=temp;
        p4[i].avg=(p4[i].high+p4[i].low)/2;
    }
    temp=0;
    for(int i=0;i<12;i++){
        temp+=p4[i].ttl; 
        if(p4[i].high>high){
            high=p4[i].high;
            highm=i+1;
        }
        if(p4[i].low<low){
            low=p4[i].low;
            lowm=i+1;
        }
    }
    float avg=temp/12;
    cout<<"The average monthly rainfall = "<<avg<<endl;
    cout<<"Total rainfall = "<<temp<<endl;
    cout<<"The month of the highest is "<<highm<<" and the temp is "<<high<<endl;
    cout<<"The month of the lowest is "<<lowm<<" and the temp is "<<low<<endl;
    cout<<"\n\n\n";
}
//chap 11 prob6
void prog5(){
    Prog5 arr[12];
    int ttl=0;
    int temp, index;
    for(int i=0;i<12;i++){
        cout<<"Please enter player name\n";
        getline(cin, arr[i].name);
        cout<<"Please enter player's number\n";
        cin>>arr[i].num;
        do{
            cout<<"Please enter points scored by player\n";
            cin>>arr[i].score;
        }while(arr[i].score<0);
        ttl+=arr[i].score;
        if(temp<arr[i].score){
            temp=arr[i].score;
            index=i;
        }
    }
    cout<<"Total points = "<<ttl<<endl;
    cout<<"Highest points scored is "<<arr[index].name<<" and scored is "<<arr[index].score<<"\n\n\n";
}
//chap 11 prob 11
void prog6(){
    MonthlyBudget stu;
    float budget[10]={500, 150, 65, 50, 250, 30, 100, 150, 75, 50};
    string sarr[10]={"Housing", "Utilities", "household Expenses", "Transportation", 
                    "Food", "Medical", "Insurance", "Entertainment", "Clothing", "Miscellaneous"};
    for(int i=0;i<10;i++){
        cout<<"Please enter the amounts spect in "<<sarr[i]<<": $";
        cin>>stu.arr[0];
    }
    for(int i=0;i<10;i++){
        if(stu.arr[i]>budget[i])
            cout<<sarr[i]<<"is over the budget"<<stu.arr[i]-budget[i]<<"\n";
        else
            cout<<sarr[i]<<"is under the budget "<<abs(stu.arr[i]-budget[i])<<"\n";
    }
    cout<<"\n\n";
}
//Chap 11 prob12
void prog7(){
    
    int num;
    cout<<"How many students you want to input?\n";
    cin>>num;
    Grade *stu = new Grade[num];
    for(int i=0;i<num;i++){
      cout<<"Name:\n";
      getline(cin,stu[i].Name);
      cout<<"ID num: ";
      cin>>stu[i].Idnum;
      cout<<"How many test score you want to enter?";
      int sc;
      int ttl=0;
      cin>>sc;
      stu[i].Tests = new int[sc];
      cout<<"please enter test score with space\n";
      for(int j=0;j<sc;j++){
        do{
          cin>>stu[i].Tests[j];
        }while(stu[i].Tests[j]<0);
        ttl+=stu[i].Tests[j];
      }
      stu[i].Average=ttl/sc;
      if(ttl/sc<=100 && ttl/sc>=91) stu[i].Grade='A';
      else if(ttl/sc<=90 && ttl/sc>=81) stu[i].Grade='B';
      else if(ttl/sc<=80 && ttl/sc>=71) stu[i].Grade='C';
      else if(ttl/sc<=70 && ttl/sc>=61) stu[i].Grade='D';
      else if(ttl/sc<=60 && ttl/sc>=0) stu[i].Grade='F';
    }
    //Output
    for(int i=0;i<num;i++){
      cout<<"Name: "<<stu[i].Name<<endl;
      cout<<"ID num: "<<stu[i].Idnum<<endl;
      cout<<"Average: "<<stu[i].Average<<endl;
      cout<<"Grade: "<<stu[i].Grade<<endl<<endl;
    }
    /*Grade *a = new Grade[num];
     * for loop
    a[0]->Tests = new int []*/
    for(int i=0;i<num;i++){
      delete[] stu[i].Tests;
    }
    delete[] stu;
}
void def(){
    cout<<"Program ends\n";
}
void display(Prog3 &dir){    
    dir.ttl=dir.n1+dir.n2+dir.n3+dir.n4;
    dir.avg=dir.ttl/4;
    cout<<"First_Quarter Sales = "<<dir.n1<<"\n";
    cout<<"Second_Quarter Sales = "<<dir.n2<<"\n";
    cout<<"Third_Quarter Sales = "<<dir.n3<<"\n";
    cout<<"Forth_Quarter Sales = "<<dir.n4<<"\n";
    cout<<"Total Annual Sales = "<<dir.ttl<<"\n";
    cout<<"Average Quarterly Sales = "<<dir.avg<<"\n";
}