/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on June 27, 2014, 2:16 PM
 * Puupose:Cal how many boxes needed
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Libraries

//Global Constant

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Constant Metric Ton
    float const meTon=35273.92;
    //Declare Variables box weight, box needed
    float boxW;
    int boxN;
    // Declare Y/N ans
    char ans;
    
    do{
        //reset
        ans=0;
    //Input box weight
    cout<<"Please Enter the weight of a package of breakfast cereal in ounces: ";
    cin>>boxW;
    //Calculate
    boxN=meTon/boxW+1;
    //Output
    cout<<boxN<<"boxes needed to yield 1 metric ton of cereal.\n";
    //Question of repeat
    while(ans!='Y'&&ans!='N'){
    cout<<"Do you wnat to repeat the program?(Y/N)?";
    cin>>ans;
    }    
    }while(ans=='Y');
    
    cout<<"Good-Bye!\n";
    //Exit stage right
    return 0;
}

