/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * freefall distance
 * Created on June 25, 2014, 1:40 AM
 */

//System Library
#include <iostream>
using namespace std;

//User LIbrary

//Global Constant

//Function PRototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    float sec, d;
    int a=32;
    //Input time
    cout<<"Enter the time in seconds after the object is dropped:";
    cin>>sec;
    
   //Cal distance
    d=a*sec*sec/2;
    
    //Ouput
    cout<<"The distance an object would drop \n";
    cout<<"if it is in freefall for "<<sec<<" seconds is "<<d<<" feets.\n";
    //Exit stage right
    return 0;
}

