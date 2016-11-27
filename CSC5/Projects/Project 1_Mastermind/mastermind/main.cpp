/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 9, 2014, 12:39 PM
 * Purpose: Mastermind
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

//User LIbraries

//Global Constant

//Function Prototypes
void intro();
char show();
int check(int [],int [], int& X, int& O, int count);
void result(int, int, int [], time_t, time_t);
void game(int, int, int, int[], int[]);
//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    char choice;            //chooose level
    char display;           //question of display
    int count=0;            //10guesses
    int realO[4];           //save
    int real[4];            //four digit rand
    bool repeat = false;    //check rand same
    int X,O;                //X right place, O right num
    ofstream output;
    
    srand (time(0));        //seed

    output.open("note.dat");
    if(output.fail()){
        cout<<"Output file opening failed.\n";
    }
    do{
        intro();
        cin>>choice;   //choose level
        cin.ignore();

        //Input
        switch(choice){
            case'E':case'e':
                //ask display
                display=show();
                output<<"Correct answer is :";
                //rand num (no repeat)
                for(int i=0; i<4; i++){
                    do{
                        repeat = false;
                        realO[i]=rand()%10;
                        for(int j=0;j<i;j++){
                            if(realO[i]==realO[j])
                                repeat = true;
                        }
                    }while(repeat);
                    real[i]=realO[i];
                    if(display=='y' || display=='Y'){
                        cout<<realO[i];
                    }
                    output<<realO[i];                    
                }
                cout<<endl;

                //game begins
                game(count, X, O, realO, real);
                break;
            case 'H': case'h':{
                //ask display
                display=show();
                output<<"Correct answer is :";
                //rand num (2same num)
                do{
                    repeat = false;
                    for(int i=0; i<3; i++){
                        realO[i]=rand()%10;
                        for(int j=0;j<i;j++){
                                if(realO[i]==realO[j])
                                    repeat = true;
                        }
                    }
                }while(repeat==true);
                //copy 1st digit to last digit
                realO[3]=realO[0];
                //shuffle
                int index[4]={0,1,2,3};
                for(int i=0;i<4;i++){
                    int place=rand()%4;     //rand place
                    int temp=index[i];      //save memory location value
                    index[i]=index[place];  //shuffle location
                    index[place]=temp;      //replace the value
                }
                for(int i=0;i<4;i++){       //copy
                    real[i]=realO[index[i]];
                }
                for(int i=0;i<4;i++){       //replace realO[i]instead of realO[index[i] easy to use function
                    realO[i]=real[i];
                    output<<realO[i];
                    //display
                    if(display=='Y' || display=='y'){
                        cout<<realO[i];
                    }
                }
                cout<<endl;

                //game begins
                game(count, X, O, realO, real);
                break;
            }
            default:
                cout<<"Not a valid choice.\n";
                cout<<"Choose again.\n";
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
        }
        }while(choice!='E' && choice!='e' && choice!='H' && choice!='h');
        output.close();
    return 0;
}
void intro(){
    //intro
    cout<<"*************************************************************\n";
    cout<<"**                      Mastermind Game!                    **\n";
    cout<<"**            The number is between 0000 to 9999            **\n"; 
    cout<<"**   After you type in your answer, it will show Xs and Os  **\n";
    cout<<"**    X means one of the number is at the right position    **\n";
    cout<<"**            O means one of the number matches             **\n";
    cout<<"**                  2 LEVEL Easy and Hard                   **\n";
    cout<<"**    In easy level, the number doesn't contain same digit  **\n";
    cout<<"**     In hard level, the number contains 2 same number     **\n";
    cout<<"**           You have 10 chances to guess the number        **\n";
    cout<<"**************************************************************\n";
    cout<<"Choose the level E/H :";
}
char show(){
//ask display
    char display;
    do{
        cout<<"Do you want to display the number? (Y/N) :";
        cin>>display;
        cin.ignore();
        if(display!='n' && display!='N' && display!='y' && display!='Y'){
            cout<<"Invalid input!\n";
        }
    }while(display!='n' && display!='N' && display!='y' && display!='Y');
    return(display);
}
int check(int realO[],int real[], int& X, int& O, int count){
    string sg;
    bool valid;             //bool sg valid
    int garr[4];            //guess in int type
    bool same[4];           //remember
    //reset
    X=0;
    O=0;
    do{
        valid=true;      //reset
        //input
        cout<<"Please enter your answer : ";
        cin>>sg;
        if(sg.length()!=4){
            valid=false;
        }
        for(int i=0;i<4;i++){
            if(sg[i]<'0' || sg[i]>'9'){
                valid=false;
            }
        }
        //if not all true = some digits not in range 0 - 9
        if(valid==false){
            cout<<"Invalid input!\n";
        }
    }while(valid==false);
    for(int i=0;i<4;i++){                 //transfer cg(char)to garr(int)
        garr[i]=sg[i]-48;
        cout<<garr[i];
    }
    cout<<"  ";
    //check matches
    for(int j=0;j<4;j++){ 
        real[j]=realO[j];     //recover loaction memory
        if(garr[j]==real[j]){        //same place
            X++;                     //Count X
            same[j]=true;            //remember!!!! location
            real[j]=10;              //erase that location memory
        }
    }
    for(int j=0;j<4;j++){ 
        for(int i=0;i<4;i++){
            if(real[i]==garr[j] && same[j]==false){
                O++;
                same[j]=true;             //matches!!!! remember location
                real[i]=10;               //erase that location memory
            }
        }
    }
    for(int i=0;i<X; i++){
        cout<<"X";
    }
    cout<<" ";
    for(int i=0;i<O;i++){
        cout<<"O";
    }
    cout<<endl;
    return(count++);
}
void result(int count, int X, int realO[], time_t tstart, time_t tend){
    if(count>=10 && X!=4){
        cout<<"You lose!\n";
    }
    else{
        cout<<"You win!\n";
    }
    cout<<"The number is ";
    for(int i=0;i<4;i++){
        cout<<realO[i];
    }
    cout<<endl;
    cout<<"You use "<<difftime(tend, tstart)<<" second(s).\n";
}
void game(int count, int X, int O, int realO[], int real[]){
    time_t tstart, tend;
    
    tstart=time(0);
    do{
        //Input & check matches
        check(realO, real, X, O, count);
    }while(count<10 && X!=4);
    //Result
    tend=time(0);
    result(count, X, realO, tstart, tend);
}