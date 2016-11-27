/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on June 26, 2014, 10:17 AM
 */

//System libraries
#include <iostream>  //random num
#include <cstdlib>
#include <ctime>  //utilize time as input to seed
using namespace std;

int main(int argc, char** argv) {
//Declare Varibles
    int num, max=100, min=0, g, count=0;
    //random num
    srand (time(0)); //seed
    num=rand()%99+1;
    //loop
    while(g!=num)
    {
        //guess time
        count+=1;
        //Ouput guess range
        cout<<"There is a  number between "<<min<<" to "<<max<<"\n";
        //input guess number
        bool a;
        do{
            a = true;
        
            cout<<"Please enter the number you guess:";
            cin>>g;
            //range change
            if(g>num&&g>min&&g<max)
                max=g;
            else if(g<num&&g>min&&g<max)
                min=g;
            else if(g<min||g>max){
                cout<<"You only can input the number between "<<min<<" and "<<max<<".\n";
                a = false;
            }
        }while(!a);
    }
    //guess right
    cout<<"Congrats, the number is "<<num<<", and you guess "<<count<<" times.";
    //exit stage right
    return 0;
}

