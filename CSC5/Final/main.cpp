/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 28, 2014, 10:37 AM
 * Purpose: Final
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

//Global Constants
const int COLS=200;
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
void extra();
void p1cvs(unsigned short);
void fillVec(vector<int> &, vector<int> &, int, int [][COLS]);
void prntVec(int [][COLS], int, int, vector<int>, vector<int>);
void p4(short int [], int []);
void prttable(int [][COLS]);
void sumtable(int [][COLS]);

//Execution begins here
int main(int argv,char *argc[]){
    int inN;
    cout<<fixed<<showpoint<<setprecision(2);
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
        case 7:extra();break;
        default:def(inN);
        };
    }while(inN<8);
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
    cout<<"Type 7 for extra"<<endl;
    cout<<"Type 8 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        cout<<endl;
        return inN;
}

void problem1(){
    //Declare variables
    unsigned short n1;
    
    cout<<"Input a number around 0 and 65535 :";
    cin>>n1;
    p1cvs(n1);
}
void problem2(){
    //Declare variables
    int p21, p22, count=0;
    char ans;
    
    do{
    srand(static_cast<unsigned int>(time(0)));
    p21=rand()%1000+1;
        do{
            cout<<"I have a number between 1 and 1000\n";
            cout<<"Can you guess my number ? You will be\n";
            cout<<"given a maximum of 10 guesses.\n";
            cout<<"Please type your guess :";
            cin>>p22;
            if(p22==p21){
                cout<<"Congratulations, You guessed the number!\n";
                cout<<"Would you like to play again (y or n)?";
                cin>>ans;
            }
            else{
                count++;
                if(p22>p21){
                    cout<<"Too high. Try again.\n";
                }
                else if(p22<p21){
                    cout<<"Too low. Try again.\n";
                }
                else if(count>10){
                    cout<<"Too many tries\n";
                }
            }
        }while(p22!=p21 && count<10);
    }while(ans=='y');
}
void problem3(){
    //Declare variables
    const int ROWS=4;
    vector<int> v1,v2;
    int size, show;
    int table[ROWS][COLS];
    
    
    cout<<"Please decide the size of the vector :";
    cin>>size;
    fillVec(v1, v2, size, table);
    cout<<"Please decide the number of columns :";
    cin>>show;
    prntVec(table, show, size, v1, v2);
}
void problem4(){
    //Declare variables
    const int N=5;
    short int rndseq[]={9,51,78,111,121};
    int freq[N]={0};
    //RANDOM FUNCTION
    p4(rndseq,freq);
    for(int i=0;i<5;i++){
    cout<<rndseq[i]<<" occured "<<freq[i]<<" times"<<endl;
    }
    cout<<endl;
}
void problem5(){
    //Declare variables
    const int ROWS=10, COL=15;
    ifstream input;
    char table[ROWS][COL];
    char temp;
    bool swap;
    
    //INPUT FILE
    input.open("input.dat");
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            input>>table[i][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<table[i][j];
        }
        cout<<endl;
    }
    input.close();
    
    cout<<"\n\n";
        do{
            swap=false;
            for(int i=0;i<10;i++){
                int q=0;
                while(table[i][q]==table[i+1][q]&&q<15){q++;}
                if(table[i][q]<table[i+1][q]){
                    for(int k=0;k<15;k++){
                        temp=table[i][k];
                        table[i][k]=table[i+1][k];
                        table[i+1][k]=temp;
                    }
                    swap=true;
                }
            }
        }while(swap==true);
    //Output
    for(int i=0;i<10;i++){
        for(int p=0;p<15;p++){
            cout<<table[i][p];
        }
        cout<<endl;
    }
    
    
    cout<<"\n\n";
}
void problem6(){
    //Declare variables
    ifstream input;
    ofstream output;
    const int ROWS=6;
    int table[ROWS][COLS];
    
    //reset
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            table[i][j]=0;
        }
    }
    //input from file
    input.open("table.dat");
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            input>>table[i][j];
        }
    }
    input.close();
    
    cout<<"Intput from table.dat\n";
    prttable(table);
    //Calculation
    sumtable(table);
    //output to file
    cout<<"output to augtable.dat\n\n";
    prttable(table);
    output.open("augtable.dat");
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            output<<setw(6)<<table[i][j]<<" ";
        }
        output<<endl;
    }
    output.close();
    cout<<endl;
}
//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
void p1cvs(unsigned short n1){
    //Declare variables
    unsigned long i=0;
    short n2;
    do{
        i*=10;
        i+=n1%10;
        n1/=10;
    }while(n1!=0);
    if(i>32767)
        cout<<"no conversion possible\n";
    else
        n2=i;
        cout<<"The conversion is "<<n2<<"\n";
}
void fillVec(vector<int> &v1, vector<int> &v2, int size,int table[][COLS]){
    //Declare variables
    int even, odd;
    
    srand(static_cast<unsigned int>(time(0)));
    
    while(size>0){
        do{
            even=rand()%90+10;
        }while(even%2==1);
        v1.push_back(even);
        do{
            odd=rand()%90+10;
        }while(odd%2==0);
        v2.push_back(odd);
        size--;
    }
    for(int i=0;i<v1.size();i++){
        table[0][i]=v1[i];
        table[1][i]=v2[i];
    }
}
void prntVec(int table[][COLS], int show, int size, vector<int> v1, vector<int> v2){
    //Declare variables
    int row, j=0;
    row=size/show;
    cout<<"This is array\n";
    cout<<"even ";
    for(int j=0;j<row;j++){
        for(int i=0+show*j;i<show*(j+1);i++){
            cout<<table[0][i]<<" ";
        }
        cout<<"\n     ";
    }
    for(int i=row*show;i<size;i++){
        cout<<table[0][i]<<" ";
    }
    
    cout<<endl<<"odd  ";
    for(int j=0;j<row;j++){
        for(int i=0+show*j;i<show*(j+1);i++){
            cout<<table[1][i]<<" ";
        }
        cout<<"\n     ";
    }
    for(int i=row*show;i<size;i++){
        cout<<table[1][i]<<" ";
    }
    cout<<"\n\n";
    
    cout<<"This is vector\n";
    cout<<"even ";
    for(int j=0;j<row;j++){
        for(int i=0+show*j;i<show*(j+1);i++){
            cout<<v1[i]<<" ";
        }
        cout<<"\n     ";
    }
    for(int i=row*show;i<size;i++){
        cout<<v1[i]<<" ";
    }
    
    cout<<endl<<"odd  ";
    for(int j=0;j<row;j++){
        for(int i=0+show*j;i<show*(j+1);i++){
            cout<<v2[i]<<" ";
        }
        cout<<"\n     ";
    }
    for(int i=row*show;i<size;i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}
void p4(short int rndseq[], int freq[]){
    //Declare variables
    int j;
    const int NTIMES=10000;
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<NTIMES;i++){
        j=rand()%5;
        freq[j]++;
    }
    
}
void extra(){
    //Declare variables
    const int NUM=4;
    char a[NUM], b[NUM], ref[]={'D','C','B','A','J','I','H','G','F','E'};
    int v1,v2;
    
    cout<<"DCBAJIHGFE\n";
    cout<<"Please enter the first 4 letter word\n";
    cin>>a;
    cout<<"Please enter the second 4 letter word\n";
    cin>>b;
    
    int i=0;
    while(a[i]==b[i]){i++;}
        for(int j=0;j<9;j++){
            if(a[i]==ref[j]){
                v1=j;
            }
            if(b[i]==ref[j]){
                v2=j;
            }
        }
    if(v1<v2)
        cout<<"First 4 letter words is larger\n\n";
    else
        cout<<"Second 4 letter words is lager\n\n";
}
void prttable(int table[][COLS]){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            cout<<setw(6)<<table[i][j];
        }
        cout<<"\n";
    }
}
void sumtable(int table[][COLS]){
    int count;
            
    count=0;
    cout<<endl;
    do{
        for(int j=0;j<6;j++){
            table[count][6]+=table[count][j];
        }
        count++;
    }while(count<5);
    count=0;
    do{
        for(int i=0;i<5;i++){
            table[5][count]+=table[i][count];
        }
        count++;
    }while(count<7);
}