//Assignment 4
/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 9, 2014, 11:09 AM
 * Purpose: Menu and 10prob
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
using namespace std;

//User Libraries

//Global Constant
float const COVLTGL=0.264179;  //1 liter=0.264179 gallon
float const G=6.673e-8;        //univeral gravitational constant cm^3/(g*sec^2)

//Function Prototypes
float value(int q, int wdp, int f1, int f2);         //problem 3 find the total value
float iftion_rt(float old, float now);               //problem 4 find inflation rate
float yrafter(float now);                            //problem 5 find estimated price base on iftion rt
float interest(float actble, float mthint, int mth); //problem 6 find the amtdue
void F(float m1, float m2, float dist);              //problem 7 find attractive force
void aatcnh(float loan);                             //problem 8 annual after tax cost of new house 
void hat(float weight, float height);                //problem 9 hat size
void jacket(float weight, float height, int age, int choice);    //problem 9 jacket size
void waist(float weight, int age, int choice);                   //problem 9 waist size

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable
    int choice; //menu choice
    cout<<fixed<<showpoint<<setprecision(2);
    do{
        //MENU
        cout<<"Assignment 4\n"; 
        cout<<"MENU\n";
        cout<<"Choose 1 to see Problem 1\n";
        cout<<"Choose 2 to see Problem 2\n";
        cout<<"Choose 3 to see Problem 3\n";
        cout<<"Choose 4 to see Problem 4\n";
        cout<<"Choose 5 to see Problem 5\n";
        cout<<"Choose 6 to see Problem 6\n";
        cout<<"Choose 7 to see Problem 7\n";
        cout<<"Choose 8 to see Problem 8\n";
        cout<<"Choose 9 to see Problem 9\n";
        cout<<"Choose 10 to see Problem 10\n";
        cout<<"Choose 0 to exit\n";
        
        //Input choice
        cin>>choice;
        cin.ignore();
                
        //Switch
        switch(choice){
            case 1:{
                //Savitch_8thEd_Chap4_Prob1
                //Miles per galon
                //Declare Variables
                //Input
                float liter;                  //liter of gasoline used
                float miles;                  //miles drove
                //Output
                float miles_per_gallon;       //miles per gallon
                
                //Input
                cout<<"This program is translate miles traveled and liters of gasoline used to miles per gallon\n";
                cout<<"Please enter the miles the car traveled : ";
                cin>>miles;
                cin.ignore();
                cout<<"Please enter the liters of gasoline the car used : ";
                cin>>liter;
                cin.ignore();
                //Calculation
                miles_per_gallon=miles/(liter*COVLTGL);
                //Output
                cout<<"The car delivered "<<miles_per_gallon<<" miles per gallon.\n";
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 2:{
                //Savitch_8thEd_Chap4_Prob2
                //find miles per galon of 2 cars and which one has the best fuel efficiency
                float liter1, liter2;                  //liter of gasoline used
                float miles1, miles2;                  //miles drove
                //Output
                float miles_per_gallon1, miles_per_gallon2;       //miles per gallon
                
                //Input
                cout<<"This program is translate miles traveled and liters of gasoline used to miles per gallon\n";
                cout<<"Please enter the miles first car traveled : ";
                cin>>miles1;
                cin.ignore();
                cout<<"Please enter the liters of first car gasoline used : ";
                cin>>liter2;
                cin.ignore();
                cout<<"Please enter the miles second car traveled : ";
                cin>>miles2;
                cin.ignore();
                cout<<"Please enter the liters of second car gasoline used : ";
                cin>>liter2;
                cin.ignore();
                //Calculation
                miles_per_gallon1=miles1/(liter1*COVLTGL);
                miles_per_gallon2=miles2/(liter2*COVLTGL);
                //Output
                cout<<"First car delivered "<<miles_per_gallon1<<" miles per gallon.\n";
                cout<<"Second car delivered "<<miles_per_gallon2<<" miles per gallon.\n";
                if (miles_per_gallon1>miles_per_gallon2){
                    cout<<"First car has the best fuel efficiency.\n";
                }
                else{
                    cout<<"Second car has the best fuel efficiency.\n";
                }
               //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 3:{
                //Savitch_8thEd_Chap4_Prob3
                //find the value of the user's holding
                //Declare Variables
                //Input
                int q;               //the number of shares of stock owned
                int wdp;             //whole-dollar portion
                int f1, f2;          //fraction portion f1/f2
                char dum;
                //Output
                float ttlval;
                
                //Input
                cout<<"This program is calculate the value of the user's holding\n";
                cout<<"Please enter the number of shares if stock owned : ";
                cin>>q;
                cin.ignore();
                cout<<"Please enter the price of one stock in XX X/X form : $";
                cin>>wdp>>f1>>dum>>f2;
                cin.ignore();
                //calculation
                ttlval=value(q, wdp, f1, f2);
                cout<<"The value of the users's holding is $"<<ttlval<<endl;
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 4:{
                //Savitch_8thEd_Chap4_Prob4
                //find inflation rate
                //Declare Variables
                //Input
                float old, now;     //the price of an item one year ago and now
                //Output
                float rt;           //inflation rate
                
                //Input
                cout<<"This program is find the inflation rate between one year ago and now\n";
                cout<<"Please enter the price of an item one year ago : $";
                cin>>old;
                cin.ignore();
                cout<<"Please enter the price of the same item today : $";
                cin>>now;
                cin.ignore();
                //Calculation
                rt=iftion_rt(old, now);
                //Output
                cout<<"The inflation rate is "<<rt<<" percents.\n";
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 5:{
                //Savitch_8thEd_Chap4_Prob5
                //find inflation rate and estimate the price base on inflation rate
                //Declare variables
                //Input
                float old, now;     //the price of an item one year ago and now
                //Output
                float rt;           //inflation rate
                float yr1,yr2;     //the price 1 and 2 years after now
                
                //Input
                cout<<"This program is find the inflation rate between one year ago and now\n";
                cout<<"Also, estimate the price in one and in two from now\n";
                cout<<"Please enter the price of an item one year ago : $";
                cin>>old;
                cin.ignore();
                cout<<"Please enter the price of the same item today : $";
                cin>>now;
                cin.ignore();
                //Calculation
                rt=iftion_rt(old, now);
                yr1=yrafter(now);
                now=yr1;
                yr2=yrafter(now);
                //Output
                cout<<"The inflation rate is "<<rt<<" percents.\n";
                cout<<"The estimated price of this item in one year from now is $"<<yr1<<endl;
                cout<<"The estimated price of this item in two years from now is $"<<yr2<<endl;
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 6:{
                //Savitch_8thEd_Chap4_Prob6
                //find interest due with compund interset
                //Declare Variables
                //Input
                float actble;  //account balance
                float mthint;  //monthly interest rate in %
                int mth;       //months
                //Output
                float intdue;  //interest due
                
                //Input
                cout<<"This program is calculate the total amount of interest in a credit card account\n";
                cout<<"Please enter the account balance : $";
                cin>>actble;
                cin.ignore();
                cout<<"Please enter the monthly interest rate in percentage : ";
                cin>>mthint;
                cin.ignore();
                cout<<"Please enter the months for which interest must be paid : ";
                cin>>mth;
                cin.ignore();
                //Calculation
                intdue=interest(actble, mthint, mth);
                //Output
                cout<<"The total amount of interest after "<<mth<<" months is $"<<intdue<<endl;
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 7:{
                //Savitch_8thEd_Chap4_Prob7
                //Find gravitational attractive force
                //Declare variables
                //Input 
                float m1;        //mass1
                float m2;        //mass2
                float dist;      //distance between m1, m2
                
                //Input
                cout<<"This program is calculate the gravitational attractive force between two objects\n";
                cout<<"Please enter the mass of first object in gram(g) : ";
                cin>>m1;
                cin.ignore();
                cout<<"Please enter the mass of first object in gram(g) : ";
                cin>>m2;
                cin.ignore();
                cout<<"Please enter the distance between two objects in centimeter(cm) : ";
                cin>>dist;
                cin.ignore();
                //calculation
                F(m1, m2, dist);
                //pause
                cout<<"Press any character to continue...\n";
                cin.ignore();
                break;
            }
            case 8:{
                //Savitch_8thEd_Chap4_Prob8
                // Declare variables
                //Input
                float price;    //price of the house
                float downpay;  //downpayment
                float loan;     //initial loan balance
                
                //Input
                cout<<"Please enter the price of the house : $";
                cin>>price;
                cin.ignore();
                cout<<"Please enter the amount of down payment : $";
                cin>>downpay;
                cin.ignore();
                //Calculation
                loan=price-downpay;
                aatcnh(loan);
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 9:{
                //Savitch_8thEd_Chap4_Prob9
                //clothing sizes
                //Declare variables
                //Input
                float height, weight;
                int age;
                
                //Input
                cout<<"This program is calculate the clothing sizes\n";
                cout<<"Please enter the height in inches : ";
                cin>>height;
                cin.ignore();
                cout<<"Please enter the weight in lbs : ";
                cin>>weight;
                cin.ignore();
                cout<<"Please enter the age : ";
                cin>>age;
                cin.ignore();
                //Output
                hat(weight, height);
                jacket(weight, height, age, choice);
                waist(weight, age, choice);
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 10:{
                //Savitch_8thEd_Chap4_Prob10
                //clothing sizes (current and 10 yrs later)
                //Declare variables
                //Input
                float height, weight;
                int age;
                
                //Input
                cout<<"This program is calculate the current and 10 years later clothing sizes\n";
                cout<<"Please enter the height in inches : ";
                cin>>height;
                cin.ignore();
                cout<<"Please enter the weight in lbs : ";
                cin>>weight;
                cin.ignore();
                cout<<"Please enter the age : ";
                cin>>age;
                cin.ignore();
                //Output
                hat(weight, height);
                jacket(weight, height, age, choice);
                waist(weight, age, choice);
                //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
            }
            case 0:
                cout<<"End of the program.\n";
                break;
                
            default:
                cout<<"Not a valid choice.\n";
                cout<<"Choose again.\n";
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
        }
        
    }while(choice!=0);
        
    //Exit  Stage right    
    return 0;
}
float value(int q, int wdp, int f1, int f2){
    return(q*(wdp+static_cast<float>(f1)/f2));
}
float iftion_rt(float old, float now){
    return(100*(now-old)/old);
}
float yrafter(float now){
    float rt;
    return((1+rt/100)*now);
}
float interest(float actble, float mthint, int mth){
    float intdue=0;    //total interest due
    int p6count=0;     //prob6 count
    do{
        intdue+=actble*mthint/100;
        actble*=1+mthint/100;
        p6count++;
    }while(p6count<mth);
    
    return(intdue);  //return intdue
}
void F(float m1, float m2, float dist){
    int p7count=0;
    float f;
    cout<<G<<" "<<m1<<" "<<m2<<" "<<dist<<endl;
    f=G*m1*m2/(dist*dist);
    if(f<1){
    do{
        f*=10;
        p7count--;
    }while(f<1);
    }
    if(f>10){
        do{
            f/=10;
            p7count++;
        }while(f>10);
    }
    if(p7count!=1){
    cout<<"The gravitational attractive force is "<<f<<"*10^"<<p7count<<" g*cm/sec^2 \n";
    }
    else{
        cout<<"The gravitational attractive force is "<<f<<"*10 g*cm/sec^2 \n";
    }
}
void aatcnh(float loan){
    cout<<"The annual after-tax cost of a new house for the first year of ownership is $"<<0.03*loan+loan*0.06*(1-0.35)<<endl;
}
void hat(float weight, float height){
    cout<<"The hat size is "<<2.9*weight/height<<" inches\n";
}
void jacket(float weight, float height, int age, int choice){
    float jacket;
    int p9count1;
    jacket=height*weight/288;
    if(age>30){
        p9count1=(age-30)/10;
    }
    do{
        jacket+=0.125;
        p9count1--;
    }while(p9count1>0);
    cout<<"The jacket size is "<<jacket<<" (chest in inches)\n";
    if(choice==10){
    age+=10;
    jacket=height*weight/288;
    if(age>30){
        p9count1=(age-30)/10;
    }
    do{
        jacket+=0.125;
        p9count1--;
    }while(p9count1>0);
    cout<<"The jacket size after 10 years is "<<jacket<<" (chest in inches)\n";
    }
    
    
}
void waist(float weight, int age, int choice){
    float waist;
    int p9count2;
    waist=weight/5.7;
    p9count2=(age-28)/2;
    do{
        waist+=0.1;
        p9count2--;
    }while(p9count2>0);
    cout<<"The waist size is "<<waist<<" inches\n";
    if(choice==10){
        age+=10;
        waist=weight/5.7;
    p9count2=(age-28)/2;
    do{
        waist+=0.1;
        p9count2--;
    }while(p9count2>0);
    cout<<"The waist size after 10 years is "<<waist<<" inches\n";
    }
}