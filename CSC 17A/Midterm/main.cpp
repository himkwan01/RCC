/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on October 16, 2014, 11:26 AM
 * Purpose: midterm
 */


//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
//User Libraries
#include "Struct.h"
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
statsResult *avgMedMode(int *, int);
void printStat(statsResult *);
void sort(int *arr, int num);
void decode(int[]);
char cf(int);
unsigned char ucf(int);
int inf(int);
unsigned int uif(int);
float ff(int);
double df(int);
short sf(int);
unsigned short usf(int);
long lf(int);
unsigned long ulf(int);
void bincvs(float, vector<int> &, vector<int> &);
void hex(vector<char> &, vector<char> &, vector<int> , vector<int> );
void oct(vector<int> &, vector<int> &, vector<int> , vector<int>);
void flo(vector<int>, vector<int>, float);
void f2dec(string, vector<int> &);
//System Begins Here
int main(int argc, char** argv) {
    cout<<showpoint<<setprecision(7);
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
            default:;
        };
    }while(inN<7);
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
    cout<<"Type 7 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    int num;
    int temp;
    string str;
    bool invalid;
    Prog1 p;
    cout<<"Please enter the account number:";
    do{
        invalid=false;
        cin>>str;
        if(str.length()!=5)
            invalid=true;
        else{
            for(int i=0;i<5;i++){
                if(str[i]<'0' ||str[i]>'9')
                    invalid=true;
            }
        }
        if(invalid)
            cout<<"Invalid input, enter again\n";
    }while(invalid);
    for(int i=0;i<5;i++){
        p.actnum[i]=str[i];
    }
    cout<<"Please enter the balance of the beginning of the month : $";
    cin>>p.bln;
    cout<<"How many checks you want to input?\n";
    cin>>num;
    p.chk=0;
    cout<<"Please enter the check with space\n";
    for(int i=0;i<num;i++){
        cin>>temp;
        p.chk+=temp;
    }cout<<"How many deposits you want to input?\n";
    cin>>num;
    p.dps=0;
    cout<<"Please enter the deposits with space\n";
    for(int i=0;i<num;i++){
        cin>>temp;
        p.dps+=temp;
    }
    temp=p.bln+p.dps-p.chk;
    if(temp<0){
        cout<<"Overdrawn\n";
        p.bln=temp-12;
        cout<<"$12 fee added for overdrawn.\n";
        cout<<"The new balance is $"<<p.bln<<"\n";
    }
    else{
        p.bln=temp;
        cout<<"The new balance is $"<<p.bln<<"\n";
    }
}
void problem2(){
    cout<<"gross pay\n";
    int num;
    int pay=0;
    cout<<"Please enter the number of employee you want to input:";
    cin>>num;
    cin.ignore();
    Prog2 *p2= new Prog2[num];
    for(int i=0;i<num;i++){
        cout<<"Please enter employee's name\n";
        getline(cin, p2[i].name);
        do{
            cout<<"Please enter "<<p2[i].name<<"'s worked hours:";
            cin>>p2[i].hrs;
        }while(p2[i].hrs<0);
        do{
            cout<<"Please enter "<<p2[i].name<<"'s pay rate per hour :$";
            cin>>p2[i].rtpay;
            cin.ignore();
        }while(p2[i].rtpay<0);
        if(p2[i].hrs<=20) pay=(p2[i].hrs*p2[i].rtpay);
        else if(p2[i].hrs<=40) pay=(p2[i].rtpay*20+(p2[i].hrs-20)*p2[i].rtpay*2);
        else pay=(p2[i].rtpay*20+p2[i].rtpay*20*2+p2[i].rtpay*3*p2[i].hrs-40);
        cout<<p2[i].name<<"'s pay is $"<<pay<<endl;
    }
    delete []p2;
}
void problem3(){
    cout<<"avg, median, mode program\n";
    int num;
    statsResult *sr;
    cout<<"size of array :";
    cin>>num;
    int *arr =new int[num];
    cout<<"Please enter the numbers with space\n";
    for(int i=0;i<num;i++)
        cin>>arr[i];
    sort(arr, num);
    sr=avgMedMode(arr, num);
    printStat(sr);
    delete sr;
    delete []arr;
}
void problem4(){
    //4digit
    //a+=3 , a%8, st<=>nd, rd<=>th
    cout<<"encode and decode program\n";
    string str;
    int a[4];
    int temp;
    bool invalid;
    do{
        invalid=false;
        cin>>str;
        if(str.length()!=4){
            invalid=true;
        }
        else{
            for(int i=0;i<4;i++){
                if(a[i]<'0' || a[i]>'7')
                    invalid=false;
            }
        }
    }while(invalid);
    for(int i=0;i<4;i++){
        a[i]=str[i]-48;
        a[i]+=3;
        a[i]%=8;
    }
    temp=a[0];
    a[0]=a[1];
    a[1]=temp;
    temp=a[2];
    a[2]=a[3];
    a[3]=temp;
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    cout<<"\n\n";
    decode(a);
    do{
        cout<<"input a number to decode :";
        invalid=false;
        cin>>str;
        if(str.length()!=4){
            invalid=true;
        }
        else{
            for(int i=0;i<4;i++){
                if(a[i]<'0' || a[i]>'7')
                    invalid=false;
            }
        }
    }while(invalid);
    for(int i=0;i<4;i++)
        a[i]=str[i]-48;
    decode(a);
    
}
void problem5(){
    cout<<setprecision(7);
    //overflow
    char c;
    unsigned char uc;
    int a=1, temp;
    unsigned int ui;
    short s;
    unsigned short us;
    long l;
    unsigned long ul;
    float f;
    double d;
    //factorial
    cout<<"largest factorial for each variable type\n";
    cout<<"Calculated by program\n";
    while(cf(a+1)/(a+1)==cf(a)){
        a++;
    }
    cout<<"byte largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<cf(a)<<endl;
    a=1;
    
    while(ucf(a+1)/(a+1)==ucf(a)){
        a++;
    }
    cout<<"unsigned byte largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<cf(a)<<endl;
    a=1;
    
    while(inf(a+1)/(a+1)==inf(a)){
        a++;
    }
    cout<<"integer largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<inf(a)<<endl;
    a=1;
    
    while(uif(a+1)/(a+1)==uif(a)){
        a++;
    }
    cout<<"unsigned integer largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<uif(a)<<endl;
    a=1;
    
    while(ff(a+1)<numeric_limits<float>::max()){
        a++;
    }
    cout<<"float largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<ff(a)<<endl;
    
    a=1;
    cout<<setprecision(15);
    while(df(a+1)<numeric_limits<double>::max()){
        a++;
    }
    cout<<"double largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<df(a)<<endl;
    a=1;
    cout<<setprecision(7);
    while(sf(a+1)/(a+1)==sf(a)){
        a++;
    }
    cout<<"short largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<sf(a)<<endl;
    a=1;
    
    while(usf(a+1)/(a+1)==usf(a)){
        a++;
    }
    cout<<"unsigned short largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<usf(a)<<endl;
    a=1;
    cout<<"size of long is "<<sizeof(long)<<"bytes\n";
    while(lf(a+1)/(a+1)==lf(a)){
        a++;
    }
    cout<<"long largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<lf(a)<<endl;
    cout<<"calculated by hand range is 12!  range(+/- 2^31-1) which is 4 bytes\n";
    a=1;
    while(ulf(a+1)/(a+1)==ulf(a)){
        a++;
    }
    cout<<"size of unsigned long is "<<sizeof(unsigned long)<<"bytes\n";
    cout<<"unsigned long largest factorial = "<<a<<endl;
    cout<<a<<"! = "<<ulf(a)<<endl;
    cout<<"calculated by hand range is 12!  range(+/- 2^31-1) which is 4 bytes\n\n";
    a=1;
}
void problem6(){
    vector<int> bin1;    //binary vector
    vector<int> bin2;
    vector<char> hex1;   //hex vector
    vector<char> hex2;
    vector<int> oct1;   //octal vector
    vector<int> oct2;
    float a=0.09, b=0.06640625;
    string af="46666601", bf="46666602", cf="B9999AFE";
    cout<<"calculated by program\n";
    bincvs(abs(a), bin1, bin2);
    cout<<"a = "<<a<<endl;
    cout<<"base 2 =";
    if(a<0) cout<<" -";
    for(int i=0;i<bin1.size();i++)
        cout<<bin1[i];
    if(bin1.size()==0)
        cout<<"0";
    cout<<".";
    for(int i=0;i<bin2.size();i++)
        cout<<bin2[i];
    cout<<"\n";
    
    hex(hex1, hex2, bin1, bin2);
    cout<<"base 16 =";
    if(a<0) cout<<" -";
    for(int i=0;i<hex1.size();i++)
        cout<<hex1[i];
    if(hex1.size()==0)
        cout<<"0";
    cout<<".";
    for(int i=0;i<hex2.size();i++)
        cout<<hex2[i];
    cout<<"\n";
    
    oct(oct1, oct2, bin1, bin2);
    cout<<"base 8 =";
//    if(a<0) cout<<" -";
    for(int i=0;i<oct1.size();i++)
        cout<<oct1[i];
    if(oct1.size()==0)
        cout<<"0";
    cout<<".";
    for(int i=0;i<oct2.size();i++)
        cout<<oct2[i];
    cout<<"\n\n";
    
//    cout<<"The number in float 8 digit hex number = ";
    flo(bin1, bin2, a);
    flo(bin1, bin2, -a);
    
    bin1.clear();
    bin2.clear();
    hex1.clear();
    hex2.clear();
    oct1.clear();
    oct2.clear();
    
    cout<<"b = "<<b<<endl;
    bincvs(b, bin1, bin2);
    cout<<"base 2 =";
    if(a<0) cout<<" -";
    for(int i=0;i<bin1.size();i++)
        cout<<bin1[i];
    if(bin1.size()==0)
        cout<<"0";
    cout<<".";
    for(int i=0;i<bin2.size();i++)
        cout<<bin2[i];
    cout<<"\n";
    
    hex(hex1, hex2, bin1, bin2);
    cout<<"base 16 =";
    if(a<0) cout<<" -";
    for(int i=0;i<hex1.size();i++)
        cout<<hex1[i];
    if(hex1.size()==0)
        cout<<"0";
    cout<<".";
    for(int i=0;i<hex2.size();i++)
        cout<<hex2[i];
    cout<<"\n";
    
    oct(oct1, oct2, bin1, bin2);
    cout<<"base 8 =";
    if(a<0) cout<<" -";
    for(int i=0;i<oct1.size();i++)
        cout<<oct1[i];
    if(oct1.size()==0)
        cout<<"0";
    cout<<".";
    for(int i=0;i<oct2.size();i++)
        cout<<oct2[i];
    cout<<"\n\n";
    
//    cout<<"The number in float 8 digit hex number = ";
    flo(bin1, bin2, b);
    
    bin1.clear();
    bin2.clear();
    hex1.clear();
    hex2.clear();
    vector<int>b1;
    cout<<"(b)\n";
    cout<<af<<" = ";
    f2dec(af, b1);
    b1.clear();
    cout<<bf<<" = ";
    f2dec(bf, b1);
    b1.clear();
    cout<<cf<<" = ";
    f2dec(cf, b1);
    b1.clear();
}
statsResult *avgMedMode(int *arr, int num){
    statsResult *s = new statsResult();
    float temp=0;
    bool swap=false;;
    s->maxFreq=0;
    s->nModes=0;
    cerr<<"function started\n";
    for(int i=0;i<num;i++){
        temp+=arr[i];
    }
    s->avg=temp/static_cast<float>(num);
    if(num%2==1)
        s->median=arr[(num-1)/2];
    else
        s->median=static_cast<float>((arr[num/2]+arr[1+(num/2)]))/2;
    s->maxFreq=0;
    temp=1;
    for(int i=0;i<num-1;i++){
        if(arr[i]==arr[i+1]){
            temp++;
        }
        else if(arr[i]!=arr[i+1]){
            if(temp>s->maxFreq)
                    s->maxFreq=temp;
            temp=1;
        }
        if(i==num-2 && s->maxFreq<temp)
            s->maxFreq=temp;
    }
    temp=1;
    for(int i=0;i<num-1;i++){
        if(arr[i]==arr[i+1]){
            temp++;
        }
        else if(arr[i]!=arr[i+1]){
            if(temp==s->maxFreq)
                    s->nModes=temp;
            temp=1;
        }
        if(i==num-2 && s->nModes==temp)
            s->nModes++;
    }
    temp=1;
    int j=0;
    s->mode = new int[s->nModes];
    for(int i=0;i<num-1;i++){
        if(arr[i]==arr[i+1]){
            temp++;
        }
        else if(arr[i]!=arr[i+1]){
            if(s->maxFreq==temp){
//                (*s).mode[j];
//                *((*s).mode+j);
                s->mode[j]=arr[i];
                j++;
            }
            temp=1;
        }
        if(i==num-2 && s->maxFreq==temp)
            s->mode[j]=arr[i];
    }
    return s;
}
void printStat(statsResult *sr){
    cout<<"average = "<<sr->avg<<"\n";
    cout<<"median = "<<sr->median<<"\n";
    cout<<"no of modes = "<<sr->nModes<<"\n";
    cout<<"max freq = "<<sr->maxFreq<<"\n";
    cout<<"mode is ";
    for(int i=0;i<sr->nModes;i++){
        cout<<sr->mode[i]<<" ";
    }
    cout<<"\n\n";
}
void decode(int a[]){
    int temp;
    cout<<"decode = ";
    for(int i=0;i<4;i++){
        if(a[i]<3)
            a[i]+=8;
        a[i]-=3;
    }
    temp=a[0];
    a[0]=a[1];
    a[1]=temp;
    temp=a[2];
    a[2]=a[3];
    a[3]=temp;
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    cout<<"\n\n";
}
char cf(int a){
    char ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
        
    return ttl;
}
unsigned char ucf(int a){
    char ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
        
    return ttl;
}
int inf(int a){
    int ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
        
    return ttl;
}
unsigned int uif(int a){
    unsigned int ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
    return ttl;
}
float ff(int a){
    float ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
    return ttl;
}
double df(int a){
    double ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=static_cast<float>(i);
    return ttl;
}
short sf(int a){
    short ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
    return ttl;
}
unsigned short usf(int a){
    unsigned short ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
    return ttl;
}
long lf(int a){
    long ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
    return ttl;
}
unsigned long ulf(int a){
    unsigned long ttl=1;
    for(int i=1;i<=a;i++)
        ttl*=i;
    return ttl;
}
void sort(int *arr, int num){
    cout<<"sorting\n";
    bool swap;
    do{
        int temp;
        swap=false;
        for(int i=0; i<num-1; i++){
            if(arr[i]>arr[i+1]){
                temp= arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swap=true;
            }
        }
    }while(swap==true);
    cout<<endl;
}
void bincvs(float a, vector<int> &v1, vector<int> &v2){
    int cnt=0;
    int shift=1;
    int temp, full;
    float fs=1;
    if(a>=1){
        temp=a;
        while(shift<=a){
            shift<<=1;
            cnt++;
        }
        shift>>=1;
        temp-=shift;
        v1.push_back(1);
        do{
            if(shift>1) shift>>=1;
            if(shift<=temp && temp>0){
                temp-=shift;
                v1.push_back(1);
            }
            else
                v1.push_back(0);
            cnt--;
        }while(cnt>1);
    }
    full=a;
    a-=full;
    while(cnt<24-v1.size() && a>0){
        fs=fs/2;
        if(a>=fs){
            a-=fs;
            v2.push_back(1);
        }
        else
            v2.push_back(0);
        cnt++;
    }
}

void hex(vector<char> &hex1, vector<char> &hex2, vector<int> v1, vector<int> v2){
    int temp=0;
    int shift=1;
    int times;
    int last;
    if(v1.size()<=4){
        for(int i=v1.size()-1;i>=0;i--){
            shift<<=v1.size()-1;
            temp+=v1[i]*shift;
            shift=1;
        }
        if(temp>10){
            temp-=10;
            hex1.push_back(temp+65);
        }
        else
            hex1.push_back(temp+48);
    }
    else{
        times=v1.size()/4;
        last=v1.size()%4;
        if(last!=0){
            for(int i=0;i<last;i++){
                shift<<=last-i-1;
                temp+=v2[i]*shift;
                shift=1;
            }
            if(temp>10){
                temp-=10;
                hex1.push_back(temp+65);
            }
            else
                hex1.push_back(temp+48);
            temp=0;
        }
        for(int j=1;j<=times;j++){
            for(int i=last+4*(j-1);i<4*j+last;i++){
                shift<<=3-i%4;
                temp+=v1[i]*shift;
                shift=1;
            }
            if(temp>10){
                temp-=10;
                hex1.push_back(temp+65);
            }
            else
                hex1.push_back(temp+48);
            temp=0;
        }
    }
    temp=0;
    if(v2.size()<=4){
        for(int i=0;i<v2.size();i++){
            shift<<=3-i;
            temp+=(v2[i]*shift);
            shift=1;
        }
        if(temp>10){
            temp-=10;
            hex2.push_back(temp+65);
        }
        else
            hex2.push_back(temp+48);
        temp=0;
    }
    else{
        cout<<"larger than 4\n";
        times=v2.size()/4;
        last=v2.size()%4;
        for(int j=1;j<=times;j++){
            for(int i=4*(j-1);i<4*j;i++){
                shift<<=3-i%4;
                temp+=(v2[i]*shift);
                shift=1;
            }
            if(temp>=10){
                temp-=10;
                hex2.push_back(temp+65);
            }
            else
                hex2.push_back(temp+48);
            temp=0;
        }
        for(int i=v2.size()-last;i<v2.size();i++){
            cout<<"last for loop\n";
            shift<<3-i%4;
            temp+=(v2[i]*shift);
            shift=1;
        }
        if(temp>0){
            if(temp>10){
                temp-=10;
                hex2.push_back(temp+65);
            }
            else
                hex2.push_back(temp+48);
            temp=0;
        }
    }
}
void oct(vector<int> &oct1, vector<int> &oct2, vector<int> v1, vector<int> v2){
    int temp=0;
    int shift=1;
    int times;
    int last;
    if(v1.size()<=3){
        for(int i=v1.size()-1;i>=0;i--){
            shift<<=v1.size()-1;
            temp+=v1[i]*shift;
            shift=1;
        }
        oct1.push_back(temp);
    }
    else{
        times=v1.size()/3;
        last=v1.size()%3;
        if(last!=0){
            for(int i=0;i<last;i++){
                shift<<=last-i-1;
                temp+=v2[i]*shift;
                shift=1;
            }
            oct1.push_back(temp);
            temp=0;
        }
        for(int j=1;j<=times;j++){
            for(int i=0+last+3*(j-1);i<3*j+last;i++){
                shift<<=2-i%3;
                temp+=v1[i]*shift;
                shift=1;
            }
            oct1.push_back(temp);
            temp=0;
        }
    }
    temp=0;
    if(v2.size()<=3){
        for(int i=0;i<v2.size();i++){
            shift<<=2-i;
            temp+=(v2[i]*shift);
            shift=1;
        }
        oct2.push_back(temp);
        temp=0;
    }
    else{
        times=v2.size()/3;
        last=v2.size()%3;
        for(int j=1;j<=times;j++){
            for(int i=3*(j-1);i<3*j;i++){
                shift<<=2-i%3;
                temp+=(v2[i]*shift);
                shift=1;
            }
            oct2.push_back(temp);
            temp=0;
        }
        for(int i=v2.size()-last;i<v2.size();i++){
            shift<<=2-i%3;
            temp+=(v2[i]*shift);
            shift=1;
        }
        if(temp>0){
            oct2.push_back(temp);
            temp=0;
        }
    }
}
void flo(vector<int> v1, vector<int> v2, float a){
    int iflo[32];
    char flo[8];
    int temp;
//    int a;
    int shift=1, cnt=1;
    int pow=0;
    //init
    for(int i=0;i<32;i++){
        iflo[i]=0;
    }
    //copy v1(integer part) into [32]
    if(v1.size()>0){     //1-23, [0]=0(sign bit)
        for(int i=0;i<v1.size() && i<23;i++){
            iflo[i+1]=v1[i];
        }
        //copy v2(dec part) into 32
        for(int i=v1.size();i<v1.size()+v2.size() && i<23;i++){
            iflo[i+1]=v2[i-v1.size()];
        }
        //find pow
        pow=v1.size();
    }
    else{     //less than 1 remove 0
        temp=0;
        //find pow, move forward, and pop back
        for(int i=0;i<v2.size()-1;i++){
            if(v2[i]==0 && v2[i+1]==1){
                temp=i+1;
                break;
            }
            else if(v2[i]==1)
                break;
        }
        for(int i=0;i<v2.size()-temp;i++){
            v2[i]=v2[i+temp];
        }
        for(int i=0;i<temp;i++){
            v2.pop_back();
            //cnt shift
            pow-=1;
        }
        
        for(int i=0;i<v2.size() && i<23;i++){
            iflo[i+1]=v2[i];
        }
    }
    //0-23 negative
    if(a<0){
//        cout<<a<<endl;
        for(int i=0;i<24;i++){
            if(iflo[i]==1)iflo[i]=0;
            else iflo[i]=1;
        }
        bool carry=true;
        for(int i=23;i>=0 && carry==true;i--){
            iflo[i]+=1;
            carry=false;
            if(iflo[i]==2){
                carry=true;
                iflo[i]=0;
            }
        }
    }
    //write power part index 24-31
    if(pow<0) iflo[24]=1;
    
    v1.clear();
    v2.clear();
    
    bincvs(abs(pow), v1, v2);
    if(v1.size()>7) cout<<"Overflow\n\n";
    else{
        for(int i=31, j=v1.size()-1;i>=25 && j>=0;i--, j--){
            iflo[i]=v1[j];
        }
        if(pow<0){
//            cout<<"CHARNGE POW PART\n";
            bool carry=true;
            //not v1
            for(int i=25;i<32;i++){
                if(iflo[i]==1) iflo[i]=0;
                else iflo[i]=1;
            }
            for(int i=31;i>=25 && carry==true;i--){
                if(carry=true){
                    iflo[i]+=1;
                    carry=false;
                }
                if(iflo[i]==2){
                    iflo[i]=0;
                    carry=true;
                }
                else if(iflo[i]==3){
                    iflo[i]=1;
                    carry=true;
                }
            }
        }
    }
//    for(int i=0;i<32;i++){
//        cout<<iflo[i];
//    }
//    cout<<endl;
    
    //change 32 int to 8 char float
    cout<<a<<" float = ";
    for(int j=0;j<8;j++){
        temp=0;
        shift=1;
        for(int i=0+4*j;i<4*(j+1);i++){
            shift<<=3-i%4;
            temp+=(iflo[i]*shift);
            shift=1;
        }
        if(temp>=10) flo[j]=temp+55;
        else flo[j]=temp+48;
        cout<<flo[j];
    }
    cout<<"\n";
    cout<<endl;
    
}
void f2dec(string c, vector<int> &v1){
    int flo[32];
    float temp;
    int shift=1;
    int power;
    float shiftdec=1;
    int cnt=0;
    //change to base 2 float
    for(int i=0;i<c.length();i++){
        if(c[i]>='A' && c[i]<='F'){
            temp=(c[i]-55);
        }
        else temp=(c[i]-48);

        if(temp<8 && temp>=4) v1.push_back(0);
        else if(temp<4 && temp>=2){
            v1.push_back(0);
            v1.push_back(0);
        }
        else if(temp<2 && temp>0){
            for(int i=0;i<3;i++)
                v1.push_back(0);
        }
        else if(temp==0){
            for(int i=0;i<4;i++){
                v1.push_back(0);
            }
        }
        if(temp>1){
            while(shift<=temp){
                shift<<=1;
                cnt++;
            }
            shift>>=1;
            temp-=shift;
            v1.push_back(1);
            do{
                if(shift>1) shift>>=1;
                if(shift<=temp && temp>0){
                    temp-=shift;
                    v1.push_back(1);
                }
                else
                    v1.push_back(0);
                cnt--;
            }while(cnt>1);
            cnt=0;
        }
        else if(temp>0) v1.push_back(1);
        temp=0;
    }
    if(v1[0]==1){
        bool carry=true;
        for(int i=23;i>=1 && carry==true;i--){
            v1[i]-=1;
            carry=false;
            if(v1[i]==-1){
                carry=true;
                v1[i]=1;
            }
        }
        for(int i=1;i<24;i++){
            if(v1[i]==1) v1[i]=0;
            else v1[i]=1;
        }
    }
    if(v1[24]==1){
        bool carry=true;
        for(int i=31;i>=25 && carry==true;i--){
            v1[i]-=1;
            carry=false;
            if(v1[i]==-1){
                carry=true;
                v1[i]=1;
            }
        }
        for(int i=25;i<32;i++){
            if(v1[i]==1) v1[i]=0;
            else v1[i]=1;
        }
    }
    power=0;
    for(int i=25;i<32;i++){
        shift<<=7-i%8;
        power+=(v1[i]*shift);
        shift=1;
    }
    if(v1[24]==0){ 
//        cout<<"pow="<<power<<endl;
        temp=0;
        for(int i=23;i>=power+1;i--){
            shiftdec=pow(2,-1*(i-power));
            temp+=v1[i]*shiftdec;
        }
//        cout<<temp<<endl;
//        cout<<endl;
        for(int i=1;i<power+1;i++){
            shift<<=(power-1);
            temp+=(v1[i]*shift);
            shift=1;
        }
    }
    else{
        temp=0;
        for(int i=23;i>=1;i--){
            shiftdec=pow(2,-1*(i+power));
            temp+=v1[i]*shiftdec;
        }
    }
    if(v1[0]==1)cout<<"-";
    v1.clear();
    cout<<temp<<endl;
}