/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 20, 2014, 11:00 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes
void problem1(int &, int &, int &, int &);
void problem2(int &, int &, int &, int &);
void problem3(int &, int &, int &, int &);
int main(int argc, char** argv) {
    int r0, r1, r2, r3, r4;
    do{
        cout<<"Press 1 to run prog1\n";
        cout<<"Press 2 to run prog2\n";
        cout<<"Press 3 to run prog3\n";
        cin>>r1;
        switch(r1){
            case 1: problem1(r0, r1, r2, r3); break;
            case 2: problem2(r0, r1, r2, r3); break;
            case 3: problem3(r0, r1, r2, r3); break;
        }
    }while(r1<4);
    return 0;
}
void problem1(int &r0, int &r1, int &r2, int &r3){
    do{
        r3=0;
        cout<<"first 20 hrs normal pay\n";
        cout<<"20-40 hrs excess double\n";
        cout<<"more than 40 excess triple\n";
        cout<<"Input hours worked and pay rate with space\n";
        cin>>r1>>r2;
        if(r1<=20){
            r0=r1*r2;
            cout<<"normal\n";
        }
        else if(r1<=40){
            r0=r2*20+(r1-20)*r2*2;
            cout<<"double\n";
        }
        else if(r1<=60){
            r0=r2*60+(r1-40)*r2*3;
            cout<<"triple\n";
        }
        else{
            cout<<"invalid\n";
            r3=1;
        }
    }while(r3==1);
    cout<<r0<<endl;
}
void problem2(int &r0, int &r1, int &r2, int &r3){
    char r4;
    r0=0;
    cout<<"a: $30 (first 11hrs), $3/hrs(12-22hrs), $6/hrs(more than 22hrs)\n";
    cout<<"b: $35 (first 22hrs), $2/hrs(23-44hrs), $4/hrs(more than 44hrs)\n";
    cout<<"c: $40 (first 33hrs), $1/hrs(34-66hrs), $2/hrs(more than 66hrs)\n";
    cout<<"Input the plan(a,b,c) and hours with space\n";
    cin>>r4>>r2;
    if(r4=='a'){
        if(r2<=11) r0=30;
        else if(r2<=22) r0=30+(r2-11)*3;
        else r0=30+11*3+(r2-22)*6;
    }
    else if(r4=='b'){
        if(r2<=22) r0=35;
        else if(r2<=44) r0=35+(r2-22)*2;
        else r0=35+22*2+(r2-44)*4;
    }
    else if(r4=='c'){
        if(r2<=33) r0=40;
        else if(r2<=66) r0=40+(r2-33);
        else r0=40+33+(r2-66)*2;
    }
    else cout<<"invalid\n";
    cout<<r0<<endl;
}
void problem3(int &r0, int &r1, int &r2, int &r3){
    int r4;
    cout<<"number of term = ";
    cin>>r0;
    r1=0;
    r2=1;
    r4=r0-1;
    if(r0==1)
        r2=r1;
    else if(r0>1){
        for(int i=r0-1;i>1;i--){
            r2=r2+r1;
            r1=r2-r1;
        }
    }
    else 
        cout<<"invalid\n";
    r0=r2;
    cout<<r0<<endl;
}
