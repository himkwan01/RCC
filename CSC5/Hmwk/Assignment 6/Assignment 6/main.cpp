/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 25, 2014, 03:39 PM
 * Purpose: Assignment 6 
 * Savitch_8thEd_Chap7_Prob1-10
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
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
float p3(float [], float, int);


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
    cout<<"Type 7 for problem 4"<<endl;
    cout<<"Type 8 for problem 5"<<endl;
    cout<<"Type 9 for problem 6"<<endl;
    cout<<"Type 10 for problem 6"<<endl;
    cout<<"Type 11 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        cout<<endl;
        return inN;
}

//Savitch_8thEd_Chap7_Prob1v1
//rainfall table
void problem1(){
    //Declare Variables
    const int MONTH=12;
    const int ROWS=12;
    int rainT[ROWS];
    float mthrain;            //average monthly rainfall
    int cMth;                 //current month
    
    do{
        cout<<"Please enter the current month in number form :";
        cin>>cMth;
        if(cMth>12 ||cMth<1) cout<<"invalid input\n";
    }while(cMth>12 || cMth<1);
    
    cout<<"Please enter the average monthly rainfall for each month of the year :";
    cin>>mthrain;
    cout<<"Please enter the actual monthly rainfall for each of the previous 12 months in order and with space\n";
    for(int i=0;i<12;i++){
        cin>>rainT[i];
        rainT[i]-=mthrain;
    }
    cout<<"\nMonth   rainfall compare to average\n";
    for(int i=0;i<12;i++){
        if(cMth==1) cout<<"Feb";
        if(cMth==2) cout<<"Mar";
        if(cMth==3) cout<<"Apr";
        if(cMth==4) cout<<"May";
        if(cMth==5) cout<<"Jun";
        if(cMth==6) cout<<"Jul";
        if(cMth==7) cout<<"Aug";
        if(cMth==8) cout<<"Sep";
        if(cMth==9) cout<<"Oct";
        if(cMth==10) cout<<"Nov";
        if(cMth==11) cout<<"Dec";
        if(cMth==12) cout<<"Jan";
        cout<<setw(20)<<rainT[i]<<"\n";
        cMth++;
        if(cMth>12){
            cMth=1;
        }
    }
    cout<<"\n\n";
    
}
//Savitch_8thEd_Chap7_Prob2
//hexadecimal
void problem2(){
    //Declare variables
    const int DIGIT=11;
    string snum1, snum2;
    char num1[DIGIT], num2[DIGIT], num3[DIGIT];     //num3=total
    int inum1, inum2, inum3;                        //change to int to cal
    bool invalid;
    bool over=false;
    
    for(int i=0;i<11;i++){
        num3[i]='0';
        num1[i]='0';
        num2[i]='0';
    }
    
    cout<<"This program can perform addition of two hexadecimal numerals each with up to 10 digits\n";
    do{
        invalid=false;
        cout<<"Please enter the first numeral\n";
        cin>>snum1;
        for(int i=0; i<snum1.length();i++)
            if(snum1[i]<'0' || (snum1[i]>'9' && snum1[i]<'a') || snum1[i]>'f')
                invalid=true;
    }while(invalid==true);
    
    do{
        invalid=false;
        cout<<"Please enter the second numeral\n";
        cin>>snum2;
        for(int i=0; i<snum2.length();i++)
            if(snum2[i]<'0' || (snum2[i]>'9' && snum2[i]<'a') || snum2[i]>'f')
                invalid=true;
    }while(invalid==true);
    
    if(snum1.length()>10 || snum2.length()>10)
        cout<<"Addition overflow";
    else{
        int j=1;
        for(int i=10;i>=11-snum1.length();i--){
            num1[i]=snum1[snum1.length()-j];
            j++;
        }
        j=1;
        for(int i=10;i>=11-snum2.length();i--){
            num2[i]=snum2[snum2.length()-j];
            j++;
        }

        for(int i=10;i>=0;i--){
            if(num1[i]>='a' && num1[i]<='f'){
                inum1=num1[i]-87;
            }
            else
                inum1=num1[i]-48;
            if(num2[i]>='a' && num2[i]<='f'){
                inum2=num2[i]-87;
            }
            else
                inum2=num2[i]-48;
            inum3=inum1+inum2;
            if(over==true){
                inum3++;
                over=false;
            }
            if(inum3>16){
                over=true;
                inum3-=16;
            }
            if(inum3>9)
                num3[i]=inum3+87;
            else
                num3[i]=inum3+48;
            if(num3[0]>48)
                invalid=true;
        }
        if(invalid==false){
            cout<<"The sum is ";
            for(int i=0;i<10;i++){
                if(num3[i]=='0')
                    num3[i]=' ';
                cout<<num3[i];
            }
        }
        else
            cout<<"Addition Overflow";
    }
    cout<<"\n\n";
}

//Savitch_8thEd_Chap7_Prob4
//s.d.
void problem3(){
    //Declare variables
    const int Q=50;
    float num[Q];
    float sum=0;
    float avg;
    int n;
    float sd;
    
    cout<<"standard deviation\n";
    cout<<"How many numbers you want to input?";
    cin>>n;
    
    cout<<"Please enter the numbers with space";
    for(int i=0;i<n;i++){
        cin>>num[i];
        sum+=num[i];
    }
    sd=p3(num, sum,n);
    cout<<"standard deviation is "<<sd<<"\n\n";
}
//Savitch_8thEd_Chap7_Prob11
//plane seat plan
void problem4(){
    //Declare variables
    const int ROWS=7, COLS=5;
    char table[ROWS][COLS];
    string seat;
    char ans;
    bool invalid;
    
    for(int i=0;i<7;i++){
        table[i][0]=i+49;
        for(int j=1;j<5;j++){
            table[i][j]=j+64;
        }
    }
    
    //display
    for(int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    do{
        do{
            invalid=false;
            cout<<"Please pick a seat in 1A form :";
            cin>>seat;
            if(seat.length()!=2)
                invalid=true;
            else if(seat[0]<'1' || seat[0]>'7' || seat[1]<'A' || seat[1]>'D')
                invalid=true;
            if(table[seat[0]-49][seat[1]-64]!='X')
                table[seat[0]-49][seat[1]-64]='X';
            else
                invalid=true;
            if(invalid==true)
                cout<<"invalid input\n";
        }while(invalid==true);
        for(int i=0;i<7;i++){
            for(int j=0;j<5;j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
        do{
            invalid=false;
            cout<<"Do you want to continue? (Y/N)";
            cin>>ans;
            if(ans!='Y' && ans!='N')
                invalid=true;
        }while(invalid==true);
    }while(ans=='Y');
    
    cout<<"\n\n";
}
//Savitch_8thEd_Chap7_Prob19
void problem5(){
    //decalre variables
    const int COLS=10, Q=5;
    int num[COLS];
    int pin[Q];
    int right[Q]={1,2,3,4,5};
    bool gd=true;
    
    srand(static_cast<unsigned int>(time(0)));
    cout<<"PIN:      ";
    for(int i=0;i<10;i++)
        cout<<i<<" ";
    cout<<"\nNUM:      ";
    for(int i=0;i<10;i++){
        num[i]=rand()%3+1;
        cout<<num[i]<<" ";
        
    }
    cout<<"\nThe pin is 12345\n";
    cout<<"Please enter the number that correspond to the PIN instead of actual number\n";
    cout<<"WITH SPACE!\n";
    for(int i=0;i<5;i++){
        cin>>pin[i];
        if(pin[i]!=num[right[i]])
            gd=false;
    }
    if(gd==true) cout<<"Correct";
    else cout<<"wrong";
    cout<<"\n\n";
    
}

//Gaddish_7thEd_Chap7_Prob1
//largest and smallest
void problem6(){
    //Declare variables
    const int I=10;
    float array[I];
    float min, max;   //smallest largest
    
    cout<<"Please enter 10 number with space\n";
    for(int i=0;i<10;i++){
        cin>>array[i];
    }
    min=array[0];
    max=array[0];
    for(int i=0;i<10;i++){
        if(max<array[i])
            max=array[i];
        if(min>array[i])
            min=array[i];
    }
    cout<<"the largest value is "<<max<<endl;
    cout<<"the smallest value is "<<min<<"\n\n";
}

//Gaddish_7thEd_Chap7_Prob2
//rainfall stat
void problem7(){
    //Declare variables
    const int MTH=12;
    float mth[MTH];     //rainfall@month
    bool invalid;
    float yr;      //rainfall@yr
    float max=0, min=1000;          //highest, lowest rainfall
    
    do{
        invalid=false;
        yr=0;
        max=0;
        min=1000;
        cout<<"Please enter total rainfall for 12 months with space\n";
        for(int i=0;i<12;i++){
            cin>>mth[i];
            if(mth[i]<0){
                invalid=true;
            }
            else{
                yr+=mth[i];
                if(max<mth[i]) max=mth[i];
                if(min>mth[i]) min=mth[i];
            }
            
        }
        if(invalid==true)
            cout<<"invalid input\n";
    }while(invalid==true);
    
    cout<<"The total rainfall for the year is "<<yr<<endl;
    cout<<"The averagemonthly rainfall is "<<yr/12<<endl;
    cout<<"The highest amount of rainfall is "<<max<<endl;
    cout<<"The lowest amount of rainfall is "<<min<<"\n\n";
    
}
//Gaddish_7thEd_Chap7_Prob8
//Payroll
void problem8(){
    //Declare variables
    const int NUM=7;
    int empId[NUM]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[NUM];
    float payrate[NUM];
    float wages[NUM];
    
    for(int i=0;i<7;i++){
        do{
            cout<<"ID: "<<empId[i]<<endl;
            cout<<"Please enter the hours worked : ";
            cin>>hours[i];
            cout<<"Please enter the pay rate : ";
            cin>>payrate[i];
            if(payrate[i]<6 || hours[i]<0)
                cout<<"Hours or pay rate is inavlid\n";
        }while(payrate[i]<6 || hours[i]<0);
        wages[i]=hours[i]*payrate[i];
    }
    cout<<"ID          Gross wages";
    for(int i=0;i<7;i++){
        cout<<empId[i]<<"    "<<wages[i]<<endl;
    }
}

//Gaddish_7thEd_Chap7_Prob9
//license exam
void problem9(){
    //Declare variables
    const int N=20;
    char correct[N]={'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'};
    char guess[N];        //input
    int count=0;          //count correct
    bool invalid;
    
    cout<<"Driver license test checkig\n";
    do{
        invalid=false;
        cout<<"Please input the answers with space\n";
        for(int i=0;i<20;i++){
            cin>>guess[i];
            if(guess[i]<'A' || guess[i]>'D')
                invalid=true;
        }
        if(invalid==true)
            cout<<"At least one answer is invalid\n";
    }while(invalid==true);
    for(int i=0;i<20;i++){
        if(guess[i]==correct[i])
            count++;
    }
    if(count>15)
        cout<<"Pass\n\n";
    else
        cout<<"Fail\n\n";
}

//Gaddish_7thEd_Chap7_Prob13
//lottery application
void problem10(){
    //Declare variables
    const int D=5; //digit
    int lottery[D];
    int user[D];
    bool prize=true;
    
    srand(static_cast<unsigned int>(time(0)));
    cout<<"Please input a 5-digit number with space:";
    for(int i=0;i<5;i++){
        lottery[i]=rand()%10;
        cin>>user[i];
        if(user[i]!=lottery[i])
            prize=false;
    }
    cout<<"lottery is ";
    for(int i=0;i<5;i++)
        cout<<lottery[i];
    cout<<"\nuser 's input is ";
    for(int i=0;i<5;i++)
        cout<<user[i];
    cout<<endl;
    if(prize==true)
        cout<<"All matches!\n\n";
    else
        cout<<"you lose\n\n";
    
    
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
float p3(float num[], float sum, int n){
    float avg;
    
    avg=sum/static_cast<float>(n);
    sum=0;
    for(int i=0;i<n;i++){
        sum+=pow(num[i]-avg,2);
    }
    return sum/static_cast<float>(n);
}