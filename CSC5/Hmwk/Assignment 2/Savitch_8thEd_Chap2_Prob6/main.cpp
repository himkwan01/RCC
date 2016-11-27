/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on June 29, 2014, 3:54 PM
 * Purpose: Fire law
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
    //maximum room capacity=rmcap
    //the number of people attending the meeting=ppl
    // the difference between rmcap and ppl
    int rmcap, ppl, ans;
    char Ans;
    
    //Input
    do{
    cout<<"Please enter the maximum rrom capcity: ";
    cin>>rmcap;
    cout<<"Please enter the number of people attending the meeting: ";
    cin>>ppl;
    //Process
    if(rmcap>ppl){
        ans=rmcap-ppl;
        cout<<"It is legal to hold the meeting, and "<<ans<<" additional people may legally attend.\n";
    }
    else if(rmcap==ppl){
        cout<<"It is legal to hold the meeting, and there isn't any space to let additional people legally attend.\n";
    }

    else{
        ans=ppl-rmcap;
        cout<<"The meeting cannot be held as planned due to fire regulations.\n";
        cout<<ans<<" people must be excluded in order to meet the fire regulation.\n";
    }
        while(Ans!='Y'&&Ans!='N'){
                cout<<"Do you wnat to repeat the program?(Y/N)?";
                cin>>Ans;
            }    
    }while(Ans=='Y');
    
    cout<<"Good-Bye!\n";
    //Exit stage right
    return 0;
}

