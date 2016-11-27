/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on July 15, 2014, 2:18 PM
 */

//can use string to compare str[i]
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {

    string sa;
    char a[4];
    int pin;
    bool invalid;
    do{
        
        invalid=false;
        cin>>sa;
        if(sa.length()!=4){
            
            invalid=true;
        }
        //show
        for(int i=0;i<sa.length();i++){
            a[i]=sa[i];
            cout<<a[i];
        }
        cout<<endl;
        for(int i=0;i<4;i++){
            if(a[i]<'0' || a[i]>'9'){
                invalid=true;
            }
        }
        if(invalid==true){
            cout<<"Invalid input\n";
        }
    }while(invalid==true);
    cout<<endl;

    
    pin=(a[0]-48)*1000+(a[1]-48)*100+(a[2]-48)*10+a[3]-48;
    cout<<pin<<endl;
    cout<<"gd\n";

    return 0;
}

