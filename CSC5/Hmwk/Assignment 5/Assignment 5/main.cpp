/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 19, 2014, 03:39 PM
 * Purpose: Assignment 5 
 * Savitch_8thEd_Chap5_Prob1-10
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

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
void problem7();
void problem8();
void problem9();
void problem10();
void p1input(int &, int &);
void p1cvs(int &, char &);
void p1output(int , int , char );
void p2cal(int &, int &);
void p3read(int &, int &, char &);
void p4sd(float [], float &);
void p5cvs(int);
void p6(float, float);
void p7(float, float);
void p9(float, float);
void p10(float, float);

//Execution begins here
int main(int argv,char *argc[]){
    int inN;
    cout<<fixed<<showpoint<<setprecision(2);
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
        case 7: problem7();break;
        case 8: problem8();break;
        case 9: problem9();break;
        case 10: problem10();break;
        default:def(inN);
        };
    }while(inN<11);
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
    cout<<"Type 7 for problem 4"<<endl;
    cout<<"Type 8 for problem 5"<<endl;
    cout<<"Type 9 for problem 6"<<endl;
    cout<<"Type 10 for problem 6"<<endl;
    cout<<"Type 11 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        return inN;
}

//Savitch_8thEd_Chap5_Prob1
void problem1(){
    //Declare Variables
    int p11,p12;    //p11:p12 time
    char ap;        //am/pm
    
    cout<<"This program is convert 24-hour notation to 12-hour notation\n";
    p1input(p11, p12);    //input
    p1cvs(p11, ap);
    p1output(p11, p12, ap);
}
//Savitch_8thEd_Chap5_Prob2
void problem2(){
    int p11,p12;         //p11:p12 time

    cout<<"This program show the time will be after waiting period\n";
    p1input(p11,p12);
    p2cal(p11, p12);
    if(p12>=10){
    cout<<"The time will be "<<p11<<":"<<p12<<" after waiting period\n\n";
    }
    else{
        cout<<"The time will be "<<p11<<":0"<<p12<<" after waiting period\n\n";
    }
}

//Savitch_8thEd_Chap5_Prob3
void problem3(){
    //Declare variables
    int p11,p12;
    int wait;
    char ap;
   
    cout<<"This program show the time will be after waiting period\n";
    p3read(p11, p12, ap);
    p2cal(p11,p12);
    if(p11>12){
        p11-=12;
        ap='P';
    }
    if(p12>=10){
    cout<<"The time will be "<<p11<<":"<<p12<<" "<<ap<<"M after waiting period\n\n";
    }
    else{
        cout<<"The time will be "<<p11<<":0"<<p12<<" "<<ap<<"M after waiting period\n\n";
    }
    
    
}
//Savitch_8thEd_Chap5_Prob4
void problem4(){
    //Declare variables
    float p4[4];
    float sum;
    
    cout<<"Please enter 4 scores with space\n";
    for(int i=0; i<4;i++){
        cin>>p4[i];
    }
    p4sd(p4 ,sum);
    cout<<"Standard deviation is "<<sum<<"\n\n";
}
//Savitch_8thEd_Chap5_Prob5
void problem5(){
    //decalre variables
    int cent;
    
    cout<<"Please enter a amount of cents :";
    cin>>cent;
    p5cvs(cent);
}

//Savitch_8thEd_Chap5_Prob6
void problem6(){
    //Declare variables
    float feet,inches;
    
    cout<<"Please enter a length in feet and inches with space : ";
    cin>>feet>>inches;
    
    p6(feet, inches);
}

//Savitch_8thEd_Chap5_Prob7
void problem7(){
    //Declare variables
    float m,cm;
    
    cout<<"Please enter a length in meter and cetimeter with space : ";
    cin>>m>>cm;
    
    p7(m, cm);
}

//Savitch_8thEd_Chap5_Prob8
void problem8(){
    //Declare variables
    string choice;
    bool valid;
    
    do{
        valid=true;
        cout<<"Please enter 1 for feet,inches to m,cm conversion\n";
        cout<<"Please enter 2 for m,cm to feet,inches conversion\n";
        cin>>choice;
        if(choice.length()!=1){
            valid=false;
        }
        if(choice[0]!='1' && choice[0]!='2'){
            valid=false;
        }
        if(valid==false){
            cout<<"Invalid input\n";
        }
    }while(valid==false);
    if(choice[0]=='1')
        problem6();
    else if(choice[0]=='2')
        problem7();
}

//Savitch_8thEd_Chap5_Prob9
void problem9(){
    //Declare variables
    float lb,ons;   //pounds, ounces
    
    cout<<"this program will change lbs and ounces to kg and g\n";
    cout<<"Please input pounds and ounces with space\n";
    cin>>lb>>ons;
    p9(lb,ons);
}

//Savitch_8thEd_Chap5_Prob10
void problem10(){
    //Declare variables
    float kg,g;
    
    cout<<"this program will change kg and g to lbs and pounds\n";
    cout<<"Please input kg and g with space\n";
    cin>>kg>>g;
    
    p10(kg,g);
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void p1input(int &p11, int &p12){
    //Declare variables
    char dum;
    
    cout<<"Please enter the time in 24-hour notation XX:XX form : ";
    cin>>p11>>dum>>p12;
}

void p1cvs(int &p11, char &ap){
    if(p11>12){
        ap='P';
        p11-=12;
    }
    else{
        ap='A';
    }
}

void p1output(int p11, int p12, char ap){
    cout<<"The hour you enter in 12-hour notation is "<<p11<<":"<<p12<<" "<<ap<<"M\n\n";
}

void p2cal(int &p11, int &p12){
    //Declare variables
    int wait;            //waiting time
    
    cout<<"Please enter the waiting time in minutes : ";
    cin>>wait;
    while(wait>60){
        p11+=1;
        wait-=60;
    }
    p12+=wait;
    while(p12>60){
        p11+=1;
        p12-=60;
    }
}

void p3read(int &p11, int &p12, char &ap){
    //Declare variables
    char dum;
    
    cout<<"Please enter the time in 12-hour notation 12:34AM form : ";
    cin>>p11>>dum>>p12>>ap>>dum;
}
void p4sd(float p4[4] ,float &sum){
    float mean=0;
    
    for(int i=0; i<4;i++){
        mean+=p4[i];
    }
    mean/=4;
    cout<<"Average = "<<mean<<endl;
    for(int i=0;i<4;i++){
        p4[i]=pow((p4[i]-mean),2);
    }
    sum=p4[0]+p4[1]+p4[2]+p4[3];
    sum=sqrt(sum/4);
}
void p5cvs(int cent){
    //Declare Variables
    int q, d, p;    //quarters, dimes, pennies
    
    q=cent/25;
    d=(cent-q*25)/10;
    p=cent-q*25-d*10;
    cout<<q<<" quarter(s) "<<d<<" dime(s) and "<<p<<" penny(pennies)\n\n";
}
void p6(float feet, float inches){
    int m;
    float cm;
    
    cm=(feet+inches/12)*0.3048*100;
    m=cm/100;
    cm-=static_cast<float>(m)*100;
    
    cout<<feet<<" feet and "<<inches<<" inches equal to "<<m<<" meter(s) and "<<cm<<" centimter(s)\n\n";
}
void p7(float m, float cm){
    float feet;
    float inches;
    int temp;
    
    feet=(m+cm*100)/0.3048;
    temp=feet;
    inches=(feet-static_cast<float>(temp))*12;
    
    cout<<m<<" meter(s) and "<<cm<<" centimeter(s) equal to "<<temp<<" feet(s) and "<<inches<<" inches\n\n";
}
void p9(float lb, float ons){
    float kg,g;        //kilogram,gram
    int temp;
    
    kg=(lb+ons/16)/2.2046;
    temp=kg;
    g=(kg-static_cast<float>(temp))*1000;
    
    cout<<"It is "<<temp<<" kg and "<<g<<" garm\n\n";
}
void p10(float kg, float g){
    float lb,ons;
    int temp;
    
    lb=(kg+g/1000)*2.2046;
    temp=lb;
    ons=(lb-static_cast<float>(temp))*16;
    
    cout<<"It is "<<temp<<" pounds and "<<ons<<" ounces\n\n";
}