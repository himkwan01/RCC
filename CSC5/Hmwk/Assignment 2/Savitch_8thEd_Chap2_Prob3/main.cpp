//Savitch+8thEd_Chap2_Prob3
/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on June 29, 2014, 3:54 PM
 * Purpose: Calculate Salary increase 6 month
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

    //Declare Variables
    //pay increase % each 6 month=payIncrease
    //old annual salary=annualPS,new annual salary=annualNS
    //new monthly salary=monthNS, the amouint of retroactive pay=newP
    float const payIncrease=0.076;
    float annualPS, annualNS, monthNS, newP;
    char ans;
    
    do{
        //reset
        ans=0;
        //Input
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<"Please enter your current annual salary: $";
        cin>>annualPS;

        //Cal
        annualNS=annualPS/2*(payIncrease)+annualPS;
        newP=annualNS-annualPS;
        monthNS=annualNS/12;

        //Output
        cout<<"The amount of retroactive paydue the employee is $"<<newP<<".\n";
        cout<<"The new annual salary is $"<<annualNS<<".\n";
        cout<<"The new monthly salary is $"<<monthNS<<".\n";
        
        while(ans!='Y'&&ans!='N'){
            cout<<"Do you want to repeat the program?(Y/N)?";
            cin>>ans;
        }    
    }while(ans=='Y');
    
    cout<<"Good-Bye!\n";
    //Exit stage right
    return 0;
}

