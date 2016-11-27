/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on July 9, 2014, 10:30 AM
 */

//Sysrem Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>      //seed
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int gen[4];  //random num
    char spades;   //spades
    char card;     //card rank
    int left;      //money left
    int bet;       //bet value
    bool repeat = false;
    
    srand (time(0));    //seed
    //first four card
    for(int i=1;i<5;i++){
        do{
            repeat = false;
            gen[i]=rand()%4+1;
            //check repeat
            for(int j=0;j<i;j++){
                if(gen[i]==gen[j])
                    repeat = true;
            }
        }while(repeat);
        //output check
        cout<<gen[i]<<" ";
    }

    return 0;
}

