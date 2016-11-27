/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 1, 2014, 10:00 PM
 * Purpose: show V of the sound
 */

//System Libraires
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Execution Begins HerE
int main(int argc, char** argv) {

    //Declare Variables
    int start; //starting temperature
    int end; //ending temperature
    float v; //velocity of sound
    cout<<fixed<<showpoint<<setprecision(1);
    //Input
    cout<<"Please enter the starting temperature in degrees Celsius: ";
    cin>>start;
    cout<<"Please enter the ending temperature in degress Celsius: ";
    cin>>end;
    //Cal and Output loop
    if(start<=end){
        do{
            v=331.3+0.61*start;
            cout<<"At "<<start<<" degrees Celsius the velocity of sound is "<<v<<" m/s\n";
            start++;
        }while(start<=end);
    }
    else{
        do{
                v=331.3+0.61*start;
                cout<<"At "<<start<<" degrees Celsius the velocity of sound is "<<v<<" m/s\n";
                start--;
            }while(start>=end);
    }
    return 0;
}

