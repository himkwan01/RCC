/* 
 * File:   main.cpp
 * Author: Tsz, 
 * sum and product of two int
 * Created on June 24, 2014, 11:50 AM
 */

//System Library
#include <iostream>
using namespace std;

//User Library

//Global Constant

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //Declare variables
    int a_no, b_no, sum, pro;
    //input ints
    cout<<"Press return after entering first integer:";
    cin>>a_no;
    cout<<"Press return after entering second integer:";
    cin>>b_no;

    //Calculation
    sum = a_no+b_no;
    pro = a_no*b_no;
    //Output Here
    cout<<"The sum of two intergers is "<<sum<<", \n";
    cout<<"and the product is "<<pro<<".\n ";
    //end
    cout<<"This is the end of the program.\n";
    //Exit stage right       
    return 0;
}

