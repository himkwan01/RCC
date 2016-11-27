/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 1, 2014, 10:40 PM
 * Purpose: the volume of a sphere
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    float radius; //sphere radius
    float vm; //Volume
    
    //Input
    cout<<"Enter raduis of a sphere.\n";
    cin>>radius;
    
    //Cal
    vm=(4.0/3.0)*3.1415*radius*radius*radius;
    
    //Output
    cout<<"The volume is "<<vm<<"\n";
    
    //Exit stage right
    return 0;
}

