/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on June 29, 2014, 3:54 PM
 * Purpose: Mad Lid
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes

//Execution Begins Hereusing namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    string sir, stnm, ndnm, fd, adj, color, animal;
    int num;
    //input
    cout<<"Please enter your instructor last name: ";
    cin>>sir;
    cout<<"Plase enter your first name and last name with space: ";
    cin>>stnm>>ndnm;
    cout<<"Please enter a number between 100 and 120: ";
    cin>>num;
    cout<<"Please enter an adjective: ";
    cin>>adj;
    cout<<"Please enter a color: ";
    cin>>color;
    cout<<"Please enter an animal: ";
    cin>>animal;
    //Output
    cout<<"Dear Instructor "<<sir<<"\n";
    cout<<"\n";
    cout<<"I am sorry that I am unable to turn in my homework at this time, First, I ate a rotten ";
    cout<<fd<<", which made me turn "<<color<<" and extremely ill. I came down with a fever of ";
    cout<<num<<". Next my "<<adj<<" pet "<<animal<<" must have smelled the remains of the ";
    cout<<fd<<" on my homework, because he ate it. I am currently rewriting my homeworks and hope you will accept it late.\n";
    cout<<"\n";
    cout<<"Sincerely,\n";
    cout<<stnm<<", "<<ndnm;
    //Exit stage right
    return 0;
}

