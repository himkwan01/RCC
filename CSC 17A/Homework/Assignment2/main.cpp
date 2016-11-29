/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on September 24, 2014, 9:49 AM
 * Purpose: As2
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;

//Global Constants
//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
int length(char *);
void p2rvs(char *);
int p3cnt(char *);
void p5cap(char *);
void p8ltln();
//Execution begins here
int main(int argv,char *argc[]){
    cout<<fixed<<showpoint<<setprecision(2);
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1: problem1();break;
        case 2: problem2();break;
        case 3: problem3();break;
        case 4: problem4();break;
        case 5: problem5();break;
        case 6: problem6();break;
        case 7: problem7();break;
        case 8: problem8();break;
        case 9: problem9();break;
        case 10: problem10();break;
        default:def(inN);
        };
    }while(inN<11);
    return 0;
}

//Menu Function
void Menu(){
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 7"<<endl;
    cout<<"Type 8 for problem 8"<<endl;
    cout<<"Type 9 for problem 9"<<endl;
    cout<<"Type 10 for problem 10"<<endl;
    cout<<"Type 11 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        cin.ignore();
        cout<<endl;
        return inN;
}
//Gaddis_7thEd_Chap10_Prob1
void problem1(){
    //Declare variables
    const int NUM=51;
    char str[NUM];
    int i=0;
    
    cout<<"String length\n\n";
    cout<<"Input string less than 50 characters\n";
    cin.getline(str, NUM);
    
    int len = length(str);
    cout<<"The string length is "<<len<<"\n\n";
}
//Gaddis_7thEd_Chap10_Prob2
void problem2(){
    //Declare variables
    const int NUM=51;
    char str[NUM];
    int i=0;
    
    cout<<"Backward String\n\n";
    cout<<"Input string less than 50 characters\n";
    cin.getline(str, NUM);
    
    p2rvs(str);
}
//Gaddis_7thEd_Chap10_Prob3
void problem3(){
    //Declare variables
    const int NUM=81;
    char str[NUM];
    
    cout<<"Word Counter\n\n";
    cout<<"Input few words less than 80 characters\n";
    cin.getline(str, NUM);
    
    int now=p3cnt(str);
    cout<<"Number of words is "<<now<<"\n\n";
}
//Gaddis_7thEd_Chap10_Prob4
void problem4(){
    const int NUM=81;
    char str[NUM];
    
    cout<<"Word Counter and average numbers of letters\n\n";
    cout<<"Input few words less than 80 characters\n";
    cin.getline(str, NUM);
    int now=p3cnt(str);
    float avg=(static_cast<float>(length(str)-now+1))/now;
    
    cout<<"Number of words is "<<now<<"\n\n";
    cout<<"Average number of letters is "<<avg<<"\n\n";
}
//Gaddis_7thEd_Chap10_Prob5
void problem5(){
    const int NUM=100;
    char str[NUM];
    
    cout<<"Sentence Capitalizer\n\n";
    cin.getline(str,NUM);
    
    p5cap(str);
    
}
//Gaddis_7thEd_Chap12_Prob1
void problem6(){
    string text, temp;
    int cnt=0;
    fstream io;
    cout<<"Please enter of the file name with the file format\n";
    getline(cin,text);
    io.open(text.c_str(), ios::in);
    if(io.fail()){
        cout<<"Open fail\n\n";
    }
    else{
        while(io>>temp && cnt<10){
            cout<<temp<<endl;
            cnt++;
        }
        io.close();
        if(cnt<9){
            cout<<"There are total "<<cnt+1<<" lines\n";
        }
    }
    
}
//Gaddis_7thEd_Chap12_Prob2
void problem7(){
    string text,temp;
    int cnt=0;
    fstream io;
    cout<<"File Display prog\n\n";
    cout<<"Please enter of the file name with the file format\n";
    getline(cin,text);
    io.open(text.c_str(), ios::in);
    if(io.fail()){
        cout<<"open fail\n\n";
    }
    else{
        while(io>>temp){
            cout<<temp<<endl;
            cnt++;
            if(cnt==23){
                cnt=0;
                cout<<"Press enter to continue display the content\n";            
                cin.ignore();
            }
        }
        io.close();
    }
}
//Gaddis_7thEd_Chap12_Prob3
void problem8(){
    fstream io;
    string str;
    cout<<"Punch line\n\n";
    io.open("joke.txt", ios::in);
    while(getline(io, str)) cout<<str<<endl;
    io.close();
    p8ltln();
}
//Gaddis_7thEd_Chap12_Prob4
void problem9(){
    string str;
    int cnt=0;
    fstream io;
    char c;
    cout<<"Tail prog\n\n";
    cout<<"Please enter of the file name with the file format\n";
    getline(cin,str);
    io.open(str.c_str(), ios::in);
    if(io.is_open()){
        io.seekg(-1, ios_base::end);  //go to last one before eof        
        int ten=0;
        while(cnt<10){
            io.get(c);
            if((int)io.tellg()<=1){
                io.seekg(0);
                ten=cnt;
                cnt==10;
            }
            else if(c=='\n'){
                cnt++;
                ten=cnt;
                if(cnt<9)
                    io.seekg(-2, ios_base::cur);
            }
            else{
                io.seekg(-2, ios_base::cur);
            }
        }
        for(int i=0;i<ten;i++){
            getline(io, str);
            cout<<str<<endl;
        }
        if (ten!=10)
            cout<<"There are only "<<ten<<" lines\n";
    }
}
//Gaddis_7thEd_Chap12_Prob5
void problem10(){
    string text, temp;
    int cnt=1;
    fstream io;
    cout<<"File Display prog\n\n";
    cout<<"Please enter of the file name with the file format\n";
    getline(cin,text);
    io.open(text.c_str(), ios::in);
    if(io.fail()){
        cout<<"Open fail\n\n";
    }
    else{
        while(io>>temp){
            cout<<cnt<<":"<<temp<<endl;
            cnt++;
        }
        io.close();
    }
}
int length(char *cptr){
    int i=0;
    while(*(cptr+i)!='\0'){
        i++;
    }
    return i;
}
void p2rvs(char *cptr){
    int len=0;
    while(*(cptr+len)!='\0')
        len++;
    for(int i=len-1;i>=0;i--){
        cout<<*(cptr+i);
    }
    cout<<"\n\n";
}
int p3cnt(char *cptr){
    int i=0;
    int cnt=0;
    while(*(cptr+i)!='\0'){
        if(*(cptr+i)==' ')
            cnt++;
        i++;
    }
    cnt++;
    return cnt;
}
void p5cap(char *cptr){
    int i=0;
    while(*(cptr+i)!='\0'){
        if(i==0 || islower(*cptr))
            *cptr=toupper(*cptr);
        if(i>1 && (*(cptr+i-2)=='.' || *(cptr+i-2)=='?' || *(cptr+i-2)=='!') && islower(*(cptr+i)) && *(cptr+i-1)==' ')
            *(cptr+i)=toupper(*(cptr+i));
        else if(i>3 && (*(cptr+i-3)=='?' || *(cptr+i-3)=='!') && islower(*(cptr+i)) && *(cptr+i-2)=='"' && *(cptr+i-1)==' ')
            *(cptr+i)=toupper(*(cptr+i));
        else if(i>3 && (*(cptr+i-3)=='?' || *(cptr+i-3)=='!') && islower(*(cptr+i)) && *(cptr+i-2)==' ' && *(cptr+i-1)=='"')
            *(cptr+i)=toupper(*(cptr+i));
        cout<<*(cptr+i);
        i++;
    }
    cout<<"\n\n";
}
void p8ltln(){
    fstream io;
    char c;
    int cnt=0;
    io.open("punchline.txt", ios::in);
    if(io.is_open()){
        io.seekg(-1, ios_base::end);  //go to last one before eof        
        while(cnt<2){
            io.get(c);
            if(io.tellg()<=1){
                io.seekg(0);
                cnt==2;
            }
            else if(c=='\n'){
                cnt++;
                if(cnt==1)
                    io.seekg(-2, ios_base::cur);
            }
            else{
                io.seekg(-2, ios_base::cur);
            }
        }
        string str;
        getline(io, str);
        cout<<str<<endl;
    }
    io.close();
}
//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
