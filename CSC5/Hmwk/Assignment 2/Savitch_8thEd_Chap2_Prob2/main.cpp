/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on June 29, 2014, 3:15 PM
 * Purpose: maximum soda avoid death
 */

//System Libraries
#include <iostream>
using namespace std;


//User Libraries

//Global Constant

//Function Prototypes

//Execution BEgins Here
int main(int argc, char** argv) {

    //Declare Variables
    //artificial sweetener in soda=artswt, mouse Weight=mouseW
    //amounat of artificial sweetener to kill the mouse=amtK_M
    //dieter weight=dieter, ratio of art to kill mouse=ratioK_M
    //amount of Soda kill per kg=amtSodaK, amount of soda Safe=amtSodaP
    //repeat answer=ans
    float const artswt=0.001;
    float mouseW, amtK_M, dieter, ratioK_M, amtSodaK;
    int amtSodaP;
    char ans;
    //Input
    cout<<"Please enter the amout of artificial sweetener needed to kill a mouse:";
    cin>>amtK_M;
    cout<<"Please enter the weight of the mouse(in kg):";
    cin>>mouseW;
    //Calculate Ratio
    ratioK_M=amtK_M/mouseW;
    amtSodaK=ratioK_M/artswt;

    do{
        //reset
        ans=0;
        //Input dieter Weight stop dieting
        cout<<"Please enter the weight which the dieter will stop dieting at(in kg):";
        cin>>dieter;
        //Calculate the possible numbers of soda to drink
        amtSodaP=amtSodaK*dieter-1;
        //Output amtSodaP
        cout<<"It is possible to drink "<<amtSodaP<<" diet soda without dying as a result.\n";
        
        while(ans!='Y'&&ans!='N'){
            //Repeat Q
            cout<<"Do you wnat to repeat the program?(Y/N)?";
            cin>>ans;
        }    
    }while(ans=='Y');
    
    cout<<"Good-Bye!\n";
    //Exit stage right
    return 0;
}

