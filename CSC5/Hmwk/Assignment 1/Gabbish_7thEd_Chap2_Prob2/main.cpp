/* 
 * File:   main.cpp
 * Author: Tsz,Kwan
 * Gabbis_7thEd_Chap2_Prob2
 * Sales Prediction
 * Created on June 25, 2014, 10:28 AM
 */

//System Library
#include <iostream>
using namespace std;

//User Library

//Global Constant

//Function prototpyes

//Exection Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float precent=0.62f, total=4.6f, div;
    //Cal
    div=precent*total;
    //Ouput
    cout<<"The East Coast division will generate "<<div<<" milllion ";
    cout<<"if the company has $4.6 million in sales this year.\n";
    //Exit Stage Right
    return 0;
}

