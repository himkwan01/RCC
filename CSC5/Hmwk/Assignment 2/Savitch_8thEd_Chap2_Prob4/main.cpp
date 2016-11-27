//Savitch_8thEd_Chap2_Prob4
/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on June 29, 2014, 3:54 PM
 * Purpose: Calculate Salary with variable months
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
    //pay increase % for 6 month=payIncrease
    //old annual salary=annualPS,new annual salary=annualNS
    //new monthly salary=monthNS, the amount of retroactive pay=newP
    //months
    float const PAYUP=0.076;
    float annualPS, annualNS, monthNS, newP;
    int months, monthsO;
    char ans;
    cout<<fixed<<showpoint<<setprecision(2);
    do{
        //reset
        ans=0;
        //Input original salary
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<"Please enter your current annual salary: $";
        cin>>annualPS;
        //Input months
        cout<<"Please enter the number of the months: ";
        cin>>months;
        monthsO=months; //store
        
        //maximum=6
        if(months>6){
            months=6;
        }
        //cal
        newP=annualPS/12*PAYUP; //newP=each month pay+
        annualNS=annualPS+newP*months; //NS=PS+newP*months
        newP = newP*months; //total newP=newP*months
        monthNS=annualNS/12; //monthsNS=anuual/12
    
        //Output
        cout<<"After "<<monthsO<<" months,";
        cout<<"the amount of retroactive paydue the employee  is $"<<newP<<".\n";
        cout<<"the new annual salary is $"<<annualNS<<".\n";
        cout<<"the new monthly salary is $"<<monthNS<<".\n";
        
        while(ans!='Y'&&ans!='N'){
            cout<<"Do you wnat to repeat the program?(Y/N)?";
            cin>>ans;
        }    
    }while(ans=='Y');
    
    cout<<"Good-Bye!\n";
    //Exit stage right
    return 0;
}


