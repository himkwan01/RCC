/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on July 15, 2014, 8:10 PM
 */

//enter word fine
//enter letter many probs

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes
void intro();
void hangman(int count);
//Execution Begins Here
int main(int argc, char** argv) {

    //Declare variables
    char g[1];
    int win=false;
    int count=0;
    bool valid;
    bool match;
    string wordList[17]={"santa","reindeer","christmas","garland","presents",
                        "snow","caroling","noel","eggnog","faith","rudolph",
                        "jolly","nutcracker","poinsettia","frosty","yuletide",
                        "elf"};
    
    intro();

    srand(time(0));
    int choice=rand()%17;
    string sword=wordList[choice];
    cout<<sword.length()<<endl;
    cout<<sword<<endl;
    char wordO[sword.length()];
    char word[sword.length()];
    char temp[sword.length()];
    char garr[sword.length()];
    cout<<endl;
    for(int i=0;i<sword.length();i++){
        wordO[i]=sword[i];
        cout<<wordO[i];
    }
    cout<<endl;
    for(int i=0;i<sword.length();i++){
        word[i]='_';
        temp[i]=word[i];
    }
    cout<<endl;
    do{
        for(int i=0;i<sword.length();i++){
            word[i]=temp[i];     //recover
            cout<<word[i]<<" ";  //cfm
        }
        cout<<endl;
        //reset
        match=false;
        //game start
        do{
            valid=true;     //reset
            cout<<"Please guess the letter : ";
            cin>>g[0];
            for(int i=0;i<sword.length();i++){
                if(g[0]==word[i] || (g[0]>49 && g[0]<97) || g[0]>122 || g[0]<49){
                    valid=false;
                }
            }
            if(valid==false){
                cout<<"Invalid input\n";
            }
        }while(valid==false);
        if(g[0]!=49){                //guess one letter
            for(int i=0;i<sword.length();i++){
                if(g[0]==wordO[i]){
                    word[i]=wordO[i];   //replace
                    match=true;
                }
                temp[i]=word[i];
            }
            if(match==true && win==false){           //one letter correct
                cout<<"Congrats, you guess the right letter(s)\n";
            }
        }
        else{                         //guess whole word
            cout<<"Please enter the whole word you guess\n";
            cin>>garr;
            for(int i=0;i<sword.length();i++){
                word[i]=garr[i];
            }
        }
        if(!strcmp(word,wordO)){
            win=true;
            match=true;
            cout<<"You guess the right word\n";
        }
        if(match==false){              //guess wrong  
            count++;
            cout<<"Sigh! The letter you guess isn't in the word\n";
            hangman(count);
        }
        if(win==true && match==true && count<8){
            cout<<"Congrats, you win!\n";
        }
        
    }while(count<8 && win==false);
    return 0;
}

void intro(){
   
   cout<<"Hangman\n";
   cout<<"You have 8 chances to guess the word\n";
   cout<<"If you enter 1 instead of letter \n";
   cout<<"you can guess the word instead of letter\n";
   
}
void hangman(int count){
    if(count==1){
        cout<<"______________________________\n";
        cout<<"|                             |\n";
        cout<<"|                             |\n";
        cout<<"|                             |\n";
        cout<<"|                             |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==2){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|                             |\n";
        cout<<"|                             |\n";
        cout<<"|                             |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==3){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|               O             |\n";
        cout<<"|                             |\n";
        cout<<"|                             |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==4){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|               O             |\n";
        cout<<"|               |             |\n";
        cout<<"|                             |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==5){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|               O             |\n";
        cout<<"|              /|             |\n";
        cout<<"|                             |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==6){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|               O             |\n";
        cout<<"|              /|\\            |\n";
        cout<<"|                             |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==7){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|               O             |\n";
        cout<<"|              /|\\            |\n";
        cout<<"|              /              |\n";
        cout<<"|_____________________________|\n";
    }
    else if(count==8){
        cout<<"______________________________\n";
        cout<<"|               |             |\n";
        cout<<"|               O             |\n";
        cout<<"|              /|\\            |\n";
        cout<<"|              / \\            |\n";
        cout<<"|_____________________________|\n";
        cout<<"You lose!\n";
    }
}