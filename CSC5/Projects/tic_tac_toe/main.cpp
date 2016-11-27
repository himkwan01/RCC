/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 15, 2014, 4:24 PM
 * Purpouse: Just for fun <tic tac toe>
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User libraries

//Global constant

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {

    //Declare variables
    char table[3][3];     //table
    char p1[2];           //coordinate
    char p2[2];           //coordinate
    bool win=false;
    bool end=false;
    int c1;
    
      //reset
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            table[i][j]=' ';
        }
    }
    
    //intro
    cout<<"Tic-Tac-Toe\n"
          "The player who play first will use O;\n"
          "In the other hand, second will use X\n";
    
    do{
        c1=1;
        cout<<"   A  B  C\n";
        cout<<" -----------\n";
        cout<<"1|"<<table[0][0]<<" | "<<table[1][0]<<" | "<<table[2][0]<<"|\n";
        cout<<" |---------|\n";
        cout<<"2|"<<table[0][1]<<" | "<<table[1][1]<<" | "<<table[2][1]<<"|\n";
        cout<<" |---------|\n";
        cout<<"3|"<<table[0][2]<<" | "<<table[1][2]<<" | "<<table[2][2]<<"|\n";
        cout<<" -----------\n";
        cout<<"\n";
        do{
            cout<<"First player please enter the coordinate in A1 form\n";
            cin>>p1;
            cout<<p1<<endl;
            if(p1[0]>67 || p1[0]<65 || p1[1]<49 || p1[1]>51 || table[p1[0]-65][p1[1]-49]!=32){
                cout<<"Invalid input\n";
            }
        }while(p1[0]>67 || p1[0]<65 || p1[1]<49 || p1[1]>51 || table[p1[0]-65][p1[1]-49]!=32);
        
        table[p1[0]-65][p1[1]-49]='O';
        
        //check
        for(int i=0;i<3;i++){
            if(table[i][0]==table[i][1] && table[i][1]==table[i][2] && table[i][0]==79){
                win=true;
            }
            if(table[0][i]==table[1][i] && table[1][i]==table[2][i] && table[0][i]==79){
                win=true;
            }
        }
        if(table[0][0]==table[1][1] && table[1][1]==table[2][2] && table[0][0]==79){
            win=true;
        }
        if(table[2][0]==table[1][1] && table[1][1]==table[0][2] && table[2][0]==79){
            win=true;
        }
        c1++;
        
        if(c1==4){
            cout<<"Game end\n";
        }
        if(win==true){
            cout<<"Player1 wins\n";
        }
        if(c1<4 && win==false){
            cout<<"   A  B  C\n";
            cout<<" -----------\n";
            cout<<"1|"<<table[0][0]<<" | "<<table[1][0]<<" | "<<table[2][0]<<"|\n";
            cout<<" |---------|\n";
            cout<<"2|"<<table[0][1]<<" | "<<table[1][1]<<" | "<<table[2][1]<<"|\n";
            cout<<" |---------|\n";
            cout<<"3|"<<table[0][2]<<" | "<<table[1][2]<<" | "<<table[2][2]<<"|\n";
            cout<<" -----------\n";
            cout<<"\n";
            
            do{
                cout<<"Second player please enter the coordinate in A1 form\n";
                cin>>p2;
                if(p2[0]>67 || p2[0]<65 || p2[1]<49 || p2[1]>51 || table[p2[0]-65][p2[1]-49]!=32){
                    cout<<"Invalid input\n";
                }
            }while(p2[0]>67 || p2[0]<65 || p2[1]<49 || p2[1]>51 || table[p2[0]-65][p2[1]-49]!=32);
            table[p2[0]-65][p2[1]-49]='X';

        //check
        for(int i=0;i<3;i++){
            if(table[i][0]==table[i][1] && table[i][1]==table[i][2] && table[i][0]==88){
                win=true;
            }
            if(table[0][i]==table[1][i] && table[1][i]==table[2][i] && table[0][i]==88){
                win=true;
            }
        }
        if(table[0][0]==table[1][1] && table[1][1]==table[2][2] && table[0][0]==88){
            win=true;
        }
        if(table[2][0]==table[1][1] && table[1][1]==table[0][2] && table[2][0]==88){
            win=true;
        }
        }
    }while(win==false);
    
    cout<<"   A  B  C\n";
    cout<<" -----------\n";
    cout<<"1|"<<table[0][0]<<" | "<<table[1][0]<<" | "<<table[2][0]<<"|\n";
    cout<<" |---------|\n";
    cout<<"2|"<<table[0][1]<<" | "<<table[1][1]<<" | "<<table[2][1]<<"|\n";
    cout<<" |---------|\n";
    cout<<"3|"<<table[0][2]<<" | "<<table[1][2]<<" | "<<table[2][2]<<"|\n";
    cout<<" -----------\n";
    cout<<"\n";
    
    
    return 0;
}

