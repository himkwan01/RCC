/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 14, 2014, 03:39 PM
 * Purpose: Midterm
 */
//question p6 exact e or e^x
//p3 4 digit
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

//Execution begins here
int main(int argv,char *argc[]){
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
        return inN;
}

//Solution to problem 1
void problem1(){
    //Declare Variables
    int n1, s1; //n1 is number, s1 is spaces
    cout<<"Please enter a integer : ";
    cin>>n1;
    do{                //display int loop
        s1=n1-1;       //copy int to display spaces
        while(s1>0){   //spcaes loop
            cout<<" ";
            s1--;
        }
        cout<<n1<<endl;
        n1--;
    }while(n1>0);
    cout<<endl;
}

//Solution to problem 2
void problem2(){
    char p2[4];                       //store 4 character to check
    cout<<"Please enter a 4 digit number\n";
    for(int i=0;i<4;i++){
        cin>>p2[i];                   //display input
        cout<<p2[i]<<" ";
        if(p2[i]>48 && p2[i]<=57){    //if input between 0-9 in int type
            while(p2[i]>48 && p2[i]<=57){
                cout<<"*";            //display * loop
                p2[i]--;
            }
        }
        else{                          //not 0-9 display ?
            cout<<"?";
        }
        cout<<endl<<endl;
    }
}

//Solution to problem 3
void problem3(){
    //Declare variables
    string spin;
    bool invalid;                 //check whether is 4digit or not
    unsigned short pin;           //pin in short type
    unsigned short ble;           //balance initially placed in the card
    unsigned short debits;        //all debits charged
    unsigned short add;           //credits added
    float p3;                     //new balance
    cout<<fixed<<showpoint<<setprecision(2);
   
    do{                        //check number of digits
        invalid=false;
        cout<<"Please enter the pin number : ";
        cin>>spin;
        if(spin.length()!=4){
            invalid=true;
        }
        if(invalid==true){
            cout<<"Invalid input!\n";
        }
    }while(invalid==true);
    cout<<"Your pin is "<<spin<<endl;
    pin=(spin[0]-48)*1000+(spin[1]-48)*100+(spin[2]-48)*10+spin[3]-48;
    cout<<"Please enter balance initially placed on the card : $";
    cin>>ble;
    cout<<"Please enter debits charged : $";
    cin>>debits;
    cout<<"Please enter added credits : $";
    cin>>add;
    p3=ble+add-debits;
    if(p3<0){
        cout<<"There is an additional $27.75 for overdrawn.\n";
        cout<<"In order to allow further charges to occur the card would have to be zeroed out and a new credit balance applied.\n";
        p3-=27.75;
    }
    cout<<"New balance is $"<<p3<<endl<<endl;
}

//Solution to problem 4
void problem4(){
    //Declare variables
    char plan;
    int hr,hrb,hra;   //A 1-8 B9-18 C 19~
    float pa=19.95,pb=24.95,pc=29.75;
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Which package are you using? A/B/C\n";
    cin>>plan;
    cout<<"How many hours you access?\n";
    cin>>hr;
    hra=(24.95-19.95)/0.75+5;
    hrb=(29.75-24.75)/0.75+15;
    if(hr>20){
        pa+=15*0.75+hr-20;
    }
    else if(hr<20 &&hr>5){
        pa+=(hr-5)*0.75;
    }
    if(hr>25){
        pb+=10*0.75+(hr-25)*0.5;
    }
    if(hr<25 && hr >15){
        pb+=(hr-15)*0.75;
    }
    if(plan=='A' || plan=='a')
        cout<<"The monthly charge is $"<<pa<<endl;
    if(plan=='B' || plan=='b')
        cout<<"The monthly charge is $"<<pb<<endl;
    if(plan=='C' || plan=='c')
        cout<<"The monthly charge is $"<<pc<<endl;
    cout<<"You should change to b package if the hours you access is larger than "<<hra<<" and less than "<<hrb<<endl;
    cout<<"You should change to c package if the hours you access is larger than "<<hrb<<endl<<endl;
    
}

//Solution to problem 5
void problem5(){
    //Declare variables
    int hrw;    //hour work
    int work;   //work pay
    int ttl;    //gross pay
    cout<<"Please enter the hours worked : ";
    cin>>hrw;
    cout<<"Please enter the rate of pay : $";
    cin>>work;
    if(hrw>50) ttl=work*40+work*10*2+(hrw-50)*3*work;
    else if (hrw>40) ttl=work*40+(hrw-40)*2;
    else ttl=work*hrw;
    cout<<"The gross pay is $"<<ttl<<endl<<endl;
}

//Solution to problem 6
void problem6(){
    int term;
    int x;
    float e1=1, e2=1;     //e1=e, ex=e^x
    float fr=1;           //factorial
    cout<<setprecision(15);
    cout<<"Please enter x : ";
    cin>>x;
    cout<<"Please enter the number of terms : ";
    cin>>term;
    for(int i=1;i<5000;i++){
        fr*=i;  //fr=fr*i
        e1+=1/fr;
    }
    e1=pow(e1,x);
    fr=1;
    for(int i=1;i<term;i++){
        fr*=i;
        e2+=1/fr;
    }
    e2=pow(e2,x);
    cout<<"Exact: "<<e1<<" approx :"<<e2<<endl;
    cout<<"The percentage error is "<<abs(100*(e2-e1)/e1)<<"%\n\n";
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}