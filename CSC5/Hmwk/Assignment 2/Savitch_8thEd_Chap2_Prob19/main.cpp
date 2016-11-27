//Savitch_8thEd_Chap_Prob19
/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 2, 2014, 1:25 PM
 * Purpose: Calculate the overall average
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare variables
    int num;   //numbers of exercise to input
    int ptgt;  //point get
    int gt;    //point get total
    int full;  //point total
    int tot;   //point sum
    int ct=0;  //exercise num
    float pect;//percentage
    cout<<fixed<<showpoint<<setprecision(2);
    //Input num
    cout<<"How many exercises to input? ";
    cin>>num;
    
    //loop
    do{
        //count
        ct++;
        num--;
        //input
        cout<<"Score received for exercise "<<ct<<": ";
        cin>>ptgt;
        cout<<"Total points possible for exercise "<<ct<<": ";
        cin>>full;
        cout<<"\n";
        //sum
        gt+=ptgt;
        tot+=full;
    }while(num!=0);
    //cal %
    pect=100*static_cast<float>(gt)/tot;
    cout<<"Yout total is "<<gt<<" out of "<<tot<<", or "<<pect<<"%.\n";
    
    return 0;
}

