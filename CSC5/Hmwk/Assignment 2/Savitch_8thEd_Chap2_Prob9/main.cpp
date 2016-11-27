//Savitch_9thEd_Chap_Prob9
/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 1, 2014, 12:37 PM
 * Purpose: cal how many months to apy off the loan
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {

    //Declare Variables
    float const intRt=0.015; //interest rate 1.5%per month
    float const pay=50; //pay per month
    float loan=1000; //loan
    float interest; //interest
    float intSum; //total amt of interest 
    int month=0; //month pay off the loan
    //int count=24;
    cout<<fixed<<showpoint<<setprecision(2);
    do{
        //Cal
        month++;
        interest=loan*intRt;
        intSum=intSum+interest;
        loan=loan-pay+interest;
        
    }while(loan>0);
    
    //cout<<loan<<"\n";
    
    //output
        cout<<"It will take you "<<month<<" months to pay off the loan.\n";
        cout<<"The total amount of interest paid over the life of the loan is $"<<intSum<<".\n";
    return 0;
}

