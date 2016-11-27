/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on July 3, 2014, 11:09 AM
 * Purpose: Menu and 10prob
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes
void program8();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable
    int choice; //menu choice
    int const MSIZE=2;
    cout<<fixed<<showpoint<<setprecision(2);
    do{
        //MENU
        cout<<"Assignment 3\n"; 
        cout<<"MENU\n";
        cout<<"Choose 1 to see Problem 1\n";
        cout<<"Choose 2 to see Problem 2\n";
        cout<<"Choose 3 to see Problem 3\n";
        cout<<"Choose 4 to see Problem 4\n";
        cout<<"Choose 5 to see Problem 5\n";
        cout<<"Choose 6 to see Problem 6\n";
        cout<<"Choose 7 to see Problem 7\n";
        cout<<"Choose 8 to see Problem 8\n";
        cout<<"Choose 9 to see Problem 9\n";
        cout<<"Choose 10 to see Problem 10\n";
        cout<<"Choose 0 to exit\n";
        
        //Input choice
        cin>>choice;
        cin.ignore();
                
        //Switch
        switch(choice){
            case 1:
                //Savitch_8thEd_Chap3_Prob1
                //Rock-paper-scissors game
                //Declare Variables
                //Input
                char first, second;//input of 2 users
                int A, B; //change to int
                int stprob;
                
                //intro and rules
                cout<<"Paper-Rock_Scissor game~\n";
                cout<<"You can enter p, r, or s in upper case or lower case\n";
                //1st player
                cout<<"1st player\n";
                do{
                    //reset
                    stprob=1;
                    //input
                    cout<<"Please enter your choice: ";
                    cin>>first;
                    cin.ignore();
                    //change to int
                    if(first=='P' || first=='p'){
                        A=1;
                    }
                    else if(first=='R' || first=='r'){
                        A=2;
                    }
                    else if(first=='S' || first=='s'){
                        A=3;
                    }
                    else{
                        stprob=0;
                        cout<<"Invalid input!\n";
                    }
                //check valid loop
                }while(stprob==0);
                //2nd player
                cout<<"2nd player\n";
                do{
                    //rest
                    stprob=1;
                    //input
                    cout<<"Please enter your choice: ";
                    cin>>second;
                    cin.ignore();
                    //change to int
                    if(second=='P' || second=='p'){
                        B=1;
                    }
                    else if(second=='R' || second=='r'){
                        B=2;
                    }
                    else if(second=='S' || second=='s'){
                        B=3;
                    }
                    else{
                        stprob=0;
                        cout<<"Invalid input!\n";
                    }
                //check valid loop       
                }while(stprob==0);
                //compare
                //same=draw
                if(A==B){      
                    //announces
                    cout<<"Nobody wins\n";
                }
                //Rock(2)+paper(1)=3
                else if(A+B==3){
                    //announces
                    cout<<"Paper covers rock\n";
                    //check who is lager and ouput
                    if(A>B){
                        cout<<"2nd player wins\n";
                    }
                    else{
                        cout<<"1st player wins\n";
                    }
                }
                //Paper(1)+scissors(3)=4
                else if(A+B==4){
                    //announces
                    cout<<"Scissors cut paper\n";
                    //check who is lager and ouput
                    if(A>B){
                        cout<<"1st player wins\n";
                    }
                    else{
                        cout<<"2nd player wins\n";
                    }    
                }
                //the last possibility
                //rock(2)+scissors(3)=5 
                else{
                    //announces
                    cout<<"Rock breaks scissors\n";
                    //check who is lager and ouput
                    if(A>B){
                        cout<<"2nd player wins\n";
                    }
                    else{
                        cout<<"1st player wins\n";
                    }
                }
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 2:
                //Savitch_8thEd_Chap3_Prob2
                //amount due with interest
                //Declare Variables
                //Input
                float actble; //account balance
                float ftint;  //interest of first 1000
                float sdint;  //interest of the rest
                ftint=0.015;
                sdint=0.01;
                //Output
                float minpay;       //minimum payment
                float amtdue;      //total amount due
                float intdue;      //interest due
                
                //Input
                cout<<"Please enter your credit account balance : ";
                cin>>actble;
                cin.ignore();
                //cal interest due
                //more than 1000
                if(actble>1000){
                    //first $1000
                    intdue=1000*ftint;
                    //other + first $1000 interest
                    intdue+=(actble-1000)*sdint;
                }
                //less than 1000
                else{
                    intdue=actble*ftint;
                }
                //cal amount due
                amtdue=actble+intdue; 
                //cal minpay
                minpay=amtdue*0.1;
                //check minpay larger or less than 10
                if(amtdue<=10){
                    minpay=amtdue;
                }
                //Output
                cout<<"If your credit account has $"<<actble<<".\n";
                cout<<"The total amount due is $"<<amtdue<<".\n";
                cout<<"The total interest due is $"<<intdue<<".\n";
                cout<<"The minimum payment is $"<<minpay<<".\n";
               //pause
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 3:
                //Savitch_8thEd_Chap3_Prob3
                //horoscope signs
                //Declare Variables
                //Input
                unsigned int mth, day;     //birthday
                unsigned short sum;        //mth*100+day
                unsigned int dif, Dif;     //difference
                int chk;                   //valid check
                
                do{
                    //Input
                    chk=1;
                    cout<<"Please enter your birthday in MM DD form : ";
                    cin>>mth>>day;
                    cin.ignore();
                    //cal
                    sum=mth*100+day;
                    if((sum>=321 && sum<=331 )|| (sum<=419&&sum>=401)){
                        dif=sum-321;
                        Dif=419-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Aries.\n";
                    }
                    else if((sum>=420 && sum<=430) || (sum<=520 && sum>=501)){
                        dif=sum-420;
                        Dif=520-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Taurus.\n";
                    }
                    else if((sum>=521 && sum<=531) || (sum<=621 && sum>=601)){
                        dif=sum-521;
                        Dif=621-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Gemini.\n";
                    }
                    else if((sum>=622 && sum<=630) || (sum>=701 && sum<=722)){
                        dif=sum-622;
                        Dif=722-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Cancer.\n";
                    }
                    else if((sum>=723 && sum<=731) || (sum>=801 && sum<=822)){
                        dif=sum-723;
                        Dif=822-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Leo.\n";
                    }
                    else if((sum>=823 && sum<=831) || (sum>=901 &&sum<=922)){
                        dif=sum-823;
                        Dif=922-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Virgo.\n";
                    }
                    else if((sum>=923 && sum<=930) || (sum>=1001 && sum<=1022)){
                        dif=sum-923;
                        Dif=1022-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Libra.\n";
                    }
                    else if((sum>=1023 && sum<=1031) || (sum>=1101 && sum<=1121)){
                        dif=sum-1023;
                        Dif=1121-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Scorpio.\n";
                    }
                    else if((sum>=1122 && sum<=1130) || (sum>=1201 && sum<=1221)){
                        dif=sum-1122;
                        Dif=1221-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Sagittarius.\n";
                    }
                    else if((sum>=1222 && sum<=1231)||(sum>=101 && sum<=119)){
                        dif=sum-1222;
                        Dif=119-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Capricorn.\n";
                    }
                    else if((sum>=120 && sum<=131) || (sum>=201 && sum<=218)){
                        dif=sum-120;
                        Dif=218-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Aquarius.\n";
                    }
                    else if((sum>=219 && sum<=229) || (sum>=301 && sum<=320)){
                        dif=sum-219;
                        Dif=320-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Pisces.\n";
                    }
                    else{
                        cout<<"Invalid input.\n";
                        chk=0;
                    }
                }while(chk==0);    
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 4:
                //Savitch_8thEd_Chap3_Prob4
                //horoscope signs and compatible
                //Declare Variables
                //Input
                //unsigned int mth, day;     //birthday
                //unsigned short sum;        //mth*100+day
                //unsigned int dif, Dif;     //difference
                //int chk;                   //valid check
                int gp;                    //element group
                
                do{
                    //Input
                    chk=1;
                    cout<<"Please enter your birthday in MM DD form : ";
                    cin>>mth>>day;
                    cin.ignore();
                    //cal
                    sum=mth*100+day;
                    //find the right horoscope sign and check whether is cusp or not
                    if((sum>=321 && sum<=331 )|| (sum<=419&&sum>=401)){
                        dif=sum-321;
                        Dif=419-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Aries, ";
                        gp=1;
                    }
                    else if((sum>=420 && sum<=430) || (sum<=520 && sum>=501)){
                        dif=sum-420;
                        Dif=520-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Taurus, ";
                        gp=2;
                    }
                    else if((sum>=521 && sum<=531) || (sum<=621 && sum>=601)){
                        dif=sum-521;
                        Dif=621-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Gemini, ";
                        gp=3;
                    }
                    else if((sum>=622 && sum<=630) || (sum>=701 && sum<=722)){
                        dif=sum-622;
                        Dif=722-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Cancer, ";
                        gp=4;
                    }
                    else if((sum>=723 && sum<=731) || (sum>=801 && sum<=822)){
                        dif=sum-723;
                        Dif=822-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";    
                        }
                        cout<<"Your horoscope sign is Leo, ";
                        gp=1;
                    }
                    else if((sum>=823 && sum<=831) || (sum>=901 &&sum<=922)){
                        dif=sum-823;
                        Dif=922-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Virgo, ";
                        gp=2;
                    }
                    else if((sum>=923 && sum<=930) || (sum>=1001 && sum<=1022)){
                        dif=sum-923;
                        Dif=1022-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Libra, ";
                        gp=3;
                    }
                    else if((sum>=1023 && sum<=1031) || (sum>=1101 && sum<=1121)){
                        dif=sum-1023;
                        Dif=1121-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Scorpio, ";
                        gp=4;
                    }
                    else if((sum>=1122 && sum<=1130) || (sum>=1201 && sum<=1221)){
                        dif=sum-1122;
                        Dif=1221-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Sagittarius, ";
                        gp=1;
                    }
                    else if((sum>=1222 && sum<=1231)||(sum>=101 && sum<=119)){
                        dif=sum-1222;
                        Dif=119-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Capricorn, ";
                        gp=2;
                    }
                    else if((sum>=120 && sum<=131) || (sum>=201 && sum<=218)){
                        dif=sum-120;
                        Dif=218-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Aquarius, ";
                        gp=3;
                    }
                    else if((sum>=219 && sum<=229) || (sum>=301 && sum<=320)){
                        dif=sum-219;
                        Dif=320-sum;
                        if(dif<=2 || Dif<=2){
                            cout<<"Your birthday is on \"cusp\"\n";
                        }
                        cout<<"Your horoscope sign is Pisces, ";
                        gp=4;
                    }
                    else{
                        cout<<"Invalid input.\n";
                        chk=0;
                    }
                }while(chk==0);
                if(gp==1){
                cout<<"and it is a FIRE sign.\n";
                cout<<"It would be most comfortable with Aries, Leo, and Sagittarius.\n";
                }
                else if(gp==2){
                    cout<<"and it is a EARTH sign.\n";
                    cout<<"It would be most comfortable with Taurus, Virgo, and Capricorn.\n";
                }
                else if(gp==3){
                    cout<<"and it is a AIR sign\n";
                    cout<<"It would be most comfortable with Gemini, Libra, and Aquarius.\n";
                }
                else if(gp==4){
                    cout<"and it is a WATER sign.\n";
                    cout<<"It would be most comfortable with Cancer, Scorpio, and Pisces.\n";
                }
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 5:
                //Savitch_8thEd_Chap3_Prob5
                //the cost of a lone-distance call
                //Declare variables
                //Input
                char wkd[MSIZE];  //day of the week
                int iwkd;         //change wkd to num
                int h, m;
                int length;       //length of the call(min)
                float art;        //rate in a time
                float brt;        //rate in b time
                float crt;        //rate in c time
                //Ouput
                float cost;       //total cost
                art=0.4;
                brt=0.25;
                crt=0.15;
                
                //Input
                //Check valid
                do{
                    //input day of the week
                    cout<<"Please enter the day of the week (e.g. Mo, Tu, We) :";
                    cin>> wkd;
                    cin.ignore();
                    //change char to num
                    if(!strcmp(wkd,"Mo")||!strcmp(wkd,"MO")||!strcmp(wkd,"mo")) 
                        iwkd=1;
                    else if(!strcmp(wkd,"Tu")||!strcmp(wkd,"TU")||!strcmp(wkd,"tu")) 
                        iwkd=2;
                    else if(!strcmp(wkd,"We")||!strcmp(wkd,"WE")||!strcmp(wkd,"we")) 
                        iwkd=3;
                    else if(!strcmp(wkd,"Th")||!strcmp(wkd,"TH")||!strcmp(wkd,"th")) 
                        iwkd=4;
                    else if(!strcmp(wkd,"Fr")||!strcmp(wkd,"FR")||!strcmp(wkd,"fr")) 
                        iwkd=5;
                    else if(!strcmp(wkd,"Sa")||!strcmp(wkd,"SA")||!strcmp(wkd,"sa")) 
                        iwkd=6;
                    else if(!strcmp(wkd,"Su")||!strcmp(wkd,"SU")||!strcmp(wkd,"su")) 
                        iwkd=7;
                    else{
                        iwkd=0;
                        cout<<"Invalid input!\n";
                    }
                }while(iwkd==0);
                //input time
                do{
                    cout<<"Please enter the time the call started in 24-hours notation and XX:XX from : ";
                    cin>>h;
                    cin.get();
                    cin>>m;
                    cin.ignore();
                    cout<<h<<":"<<m<<endl;
                    if(h>24|| m>60)
                        cout<<"Invalid input!\n";
                }while(h>24 || m>60);
                //Input call length
                cout<<"Please input the length of the call in minutes : ";
                cin>>length;
                cin.ignore();
                //check
                if(iwkd!=6 && iwkd!=7){
                    if(h>=8 && h<=18){
                        //plan A
                        cost=static_cast<float>(length)*art;
                        
                    }
                    else{
                        //plan B
                        cost=static_cast<float>(length)*brt;
                    }
                }
                else{
                    //plan C
                    cost=static_cast<float>(length)*crt;
                }
                cout<<"The cost of the call is $ "<<cost<<"\n";
                cout<<"Press ENTER to continue..."<<endl;
                cin.ignore();
                break;
            case 6:
                //Savitch_8thEd_Chap3_Prob6
                //solve quadratic equation
                //Declare variables
                //Input
                float a, b, c;     //ax^2+bx+c=0
                //Output
                float delta;        //b^2-4ac
                int delta_chk;      //delta check change solve equation 
                float ransA;        //ans real part
                float ransB;
                float ians;        //imagine part
                
                //Input
                cout<<"The form of quadratic equation is ax^2+bx+c=0\n";
                cout<<"Please enter a, b, c in space : ";
                cin>>a>>b>>c;
                cin.ignore();
                //cal delta
                delta=b*b-4*a*c;
                //cout<<delta<<endl;
                //check real root
                if(delta>0){
                    cout<<"The equation has two different real roots.\n";
                    delta_chk=1;
                }
                else if(delta==0){
                    cout<<"The equation has two equal real roots.\n";
                    delta_chk=2;
                }
                else{
                    cout<<"The equation doesn't have any real roots.\n";
                    delta_chk=0;
                }
                //cal ans
                if(delta_chk==2){
                    ransA=(-b)/(2*a);
                    cout<<"The root of the equation is "<<ransA<<endl;
                }
                else if(delta_chk==1){
                    ransA=((-b+sqrt(delta))/(2*a));
                    ransB=((-b)-sqrt(delta)/(2*a));
                    cout<<"The roots of the equation are "<<ransA<<" and "<<ransB<<endl;
                }
                else{
                    ransA=(-b)/(2*a);
                    ians=(sqrt(-delta))/(2*a);
                    cout<<"The roots of the equation are "<<ransA<<" + "<<ians<<"i "<<" and "<<ransA<<" - "<<ians<<"i\n";
                }
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 7:
                //Savitch_8thEd_Chap3_Prob7
                //change year from arabic numerals to roman numerals
                //Declare variables
                //Input
                int yr;
                int st, nd, rd, th;          //int form
                //output
                char cst, cnd, crd, cth;     //ouput in roman
                cst='M';
                //input
                do{
                cout<<"Please enter the year in Arabic numerals and this program will output in Roman numerals : ";
                cin>>yr;
                cin.ignore(); 
                }while(yr>3000 || yr<1000);
                //separate
                st=yr/1000;
                nd=(yr-st*1000)/100;
                rd=(yr-st*1000-nd*100)/10;
                th=yr-st*1000-nd*100-rd*10;
                //Output
                cout<<"The year you entered in Roman numerals is ";
                //thousands
                while(st>0){
                    st--;
                    cout<<cst;
                }
                //hundreds
                if(nd>1 && nd<4){
                    cnd='C';
                    while(nd>0){
                        nd--;
                        cout<<cnd;
                    }
                }
                else if(nd<3 && nd<6){
                    if(nd==4){
                        cout<<"CD";
                    }
                    else if(nd==5){
                        cnd='D';
                        cout<<cnd;
                    }
                }
                else if(nd>5 && nd<9){
                    cout<<"D";
                    cnd='C';
                    while(nd>5){
                        nd--;
                        cout<<cnd;
                    }
                }
                else if(nd==9){
                    cout<<"CM";
                }
                //tens
                if(rd>1 && rd<4){
                    crd='X';
                    while(rd>0){
                        rd--;
                        cout<<crd;
                    }
                }
                else if(rd<3 && rd<6){
                    if(rd==4){
                        cout<<"XL";
                    }
                    else if(rd==5){
                        crd='L';
                        cout<<crd;
                    }
                }
                else if(rd>5 && rd<9){
                    cout<<"L";
                    crd='X';
                    while(rd>5){
                        rd--;
                        cout<<crd;
                    }
                }
                else if(rd==9){
                    cout<<"XC";
                }
                //last digit
                if(th>1 && th<4){
                    cth='I';
                    while(th>0){
                        th--;
                        cout<<cth;
                    }
                }
                else if(th<3 && th<6){
                    if(th==4){
                        cout<<"IV";
                    }
                    else if(th==5){
                        cth='V';
                        cout<<cth;
                    }
                }
                else if(th>5 && th<9){
                    cout<<"V";
                    cth='I';
                    while(th>5){
                        th--;
                        cout<<cth;
                    }
                }
                else if(th==9){
                    cout<<"IX";
                }
                cout<<"\n";
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 8:
                program8();
                break;
                
            case 9:
                //Savitch_8thEd_Chap3_Prob9
                //compound loan
                //Declare variables
                //Input
                float intrt;     //interest rate in %
                float loan;      //loan amount
                float loanS;
                float mthpay;    //month payment
                float intmth;    //month interest
                float mthct;
                //Output
                float ttlint;    //total amount of interest
                float anint;     //annual interest
                
                //Input
                ttlint=0;
                mthct=0;
                cout<<"Please enter loan amount : $";
                cin>>loan;  //save data
                loanS=loan;
                cin.ignore();
                cout<<"Please enter the percentage of interest rate : ";
                cin>>intrt;
                cin.ignore();
                //cal mthpay
                intrt/=100;
                mthpay=loan/20;
                //int loop
                do{
                    intmth=intrt*loan/12;
                    loan=loan-mthpay+intmth;
                    ttlint+=intmth;
                    mthct++;
                }while(loan>0);
                anint=(100*12*ttlint/mthct)/loanS;
                //Output
                cout<<"The loan takes "<<mthct<<" months to pay off.\n";
                cout<<"The monthly payments is $"<<mthpay<<endl;
                cout<<"The total interest is $"<<ttlint<<endl;
                cout<<"The annual interest is "<<anint<<" percent. \n";
                
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 10:
                //Savitch_8thEd_Chap3_Prob10
                //Fibonacci Sequence
                //Declare Variables
                //Input
                int green;     //initial size of a green crud population
                int greenold;  //(n-1)term
                int numday;    //number of days
                int grow;      //grow time
                int count;     //count loop
                //Output
                int final;  //the number of pounds of green crud after that many days
                
                //input
                cout<<"Please enter the initial size of a green crud population in pounds : ";
                cin>>green;
                cin.ignore();
                cout<<"Please enter the number of days : ";
                cin>>numday;
                cin.ignore();
                count=0;
                greenold=0;
                //cal
                grow=numday/5;    //grow time
                //loop and replace
                do{
                   count++;
                   final=green+greenold;
                   greenold=green;
                   green=final;
                }while(count<grow);
                //Output
                cout<<"The number of pounds of green crud after "<<numday<<" days is "<<final<<"\n";
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
                break;
                
            case 0:
                cout<<"End of the program.\n";
                break;
                
            default:
                cout<<"Not a valid choice.\n";
                cout<<"Choose again.\n";
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
        }
        
    }while(choice!=0);
        
    //Exit  Stage right    
    return 0;
}
void program8(void){
                //Savitch_8thEd_Chap3_Prob8
                //Black Jack
                //Declare variables
                //Input
                unsigned int cdnum;   //number of cards
                //Ouput
                int ptb;              //pt of each card(bigger)
                int pts;              //smaller
                int totalb;           //total pt(bigger)
                int totals;           //smaller
                totalb=0; 
                totals=0;
                ptb=0;
                pts=0;
                //Input num of cards
                do{
                cout<<"Please enter the numbers of cards you have : ";
                cin>>cdnum;
                cin.ignore();
                cout<<"Ten, Jack, Queen, King, and Ace are T, J, Q, K, A\n";
                if(cdnum<=0 || cdnum>=6){
                    cout<<"Invalid input!\n";
                }
                }while(cdnum<=0 || cdnum>=6);
                char cpt[cdnum];     //cdnum of variables
                for(int i=0; i<cdnum; i++){
                    cout<<"Please enter "<<i+1<<" card : ";
                    cin>>cpt[i];
                    cin.ignore();
                    if(cpt[i]>=50 && cpt[i]<=57){
                        ptb=static_cast<int>(cpt[i])-48;
                        pts=static_cast<int>(cpt[i])-48;
                    }
                    //card=10, j, q, k
                    else if(cpt[i]=='T' || cpt[i]=='t' || cpt[i]=='J' || cpt[i]=='j' || cpt[i]=='Q' || cpt[i]=='q' || cpt[i]=='K' || cpt[i]=='k'){
                        ptb=10;
                        pts=10;
                    }
                    //card=Ace
                    else if(cpt[i]=='A' || cpt[i]=='a'){
                        ptb=11;
                        pts=1;
                    }
                    //other
                    //invalid
                    else{
                        cout<<"Invalid input!\n";
                        i--;
                    }
                    //sum of pt
                    totalb+=ptb;
                    totals+=pts;
                }
                //NO ACE
                if(totalb==totals){
                    if(totalb>21){
                        cout<<"Busted\n";
                    }
                    else{
                        cout<<"Your points is "<<totalb<<". \n";
                    }
                }
                else{
                    if(totals>21){
                        cout<<"Busted\n";
                    }
                    else if(totalb<21){
                        cout<<"Your points is "<<totalb<<". \n";
                    }
                    else if(totalb>21 && totals<21){
                    cout<<"Your points is "<<totals<<". \n";    
                    }
                }
                cout<<"Press ENTER to continue...\n";
                cin.ignore();
}