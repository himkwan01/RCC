/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * sum of coins
 * Created on June 25, 2014, 1:18 AM
 */
//System Library
#include <iostream>
using namespace std;
//User Library

//Global constant

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int quarter, dime, nickel;
    float total;
    
    //Input Quarters
    cout<<"Enter the numbers of quarters:";
    cin>>quarter;
    
    //Imput Dimes
    cout<<"Enter the numbers of dimes:";
    cin>>dime;
    
    //Input Nickel
    cout<<"Enter the numbers of nickels:";
    cin>>nickel;
    
    //Caluate total
    total=0.25*quarter+0.1*dime+0.05*nickel;
    
    //Ouput
    cout<<"If you have "<<quarter<<" quarters, ";
    cout<<dime<<" dimes,and "<<nickel<<" nickels.\n";
    if (total>1)
        cout<<"The coins are worth "<<total<<" dollars.\n";
    else
        cout<<"The coins are worth "<<total<<" cents.\n";
    //Exit Stage Right
    return 0;
}

