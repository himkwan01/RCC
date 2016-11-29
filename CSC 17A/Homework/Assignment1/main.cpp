/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on September 18, 2014, 12:05 PM
 * 17A AS1
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//Global Libraries

//Global Constant

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
int *fillArray(int);
float mean(int[], int);
float median(int[], int);
int *mode(int[], int);
void sort(int[], int);
int *arrExpd(int[], int);
int *rvsArr(int [], int);
//System Begins Here
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
        default:def(inN);
        };
    }while(inN<7);
    return 0;
}
void Menu(){
    cout<<"Type 1 for mode array problem"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 to exit \n"<<endl;
}
//mode array prob
void problem1(){
    //Declare Variables
    int num;
    int *array;
    float avg;
    float med;
    int *mod;
    //input
    cout<<"Input the num of the array :";
    cin>>num;
    array=fillArray(num);
    for(int i=0;i<num;i++){
        cout<<*(array+i)<<endl;
    }
    cout<<endl;
    //sorting
    sort(array, num);
    
    //find mena median mode
    avg=mean(array, num);
    med=median(array, num);
    mod=mode(array, num);
    //output
    cout<<"avgerage = "<<avg<<endl;
    cout<<"median = "<<med<<endl;
    cout<<"mode array = {";
    for(int i=0; i<mod[0]+2;i++){
        cout<<" "<<*(mod+i);
    }
    cout<<" }\n";
    delete array;
    delete mod;
}
//Gaddis_7thEd_Chap9_Prob1
void problem2(){
    //Declare Variables
    int num;
    int *array;
    
    cout<<"Please enter the number of the elements :";
    cin>>num;
    
    array=fillArray(num);
    for(int i=0;i<num;i++){
        cout<<array[i]<<endl;
    }
    delete array;
}
//Gaddis_7thEd_Chap9_Prob2
void problem3(){
    //Declare Variables
    int num;
    float avg;
    cout<<"How many test scores you want to enter?\n";
    cin>>num;
    int *score = new int[num];
    cout<<"Input the data with space\n";
    for(int i=0;i<num;i++){
        cin>>score[i];
    }
    sort(score, num);
    avg=mean(score, num);
    cout<<"Average is "<<avg<<endl;
    delete []score;
}
//Gaddis_7thEd_Chap9_Prob3
void problem4(){
    //Declare Variables
    int num;
    float avg;
    cout<<"How many test scores you want to enter?\n";
    cin>>num;
    int *score = new int[num];
    cout<<"Input the data with space\n";
    for(int i=0;i<num;i++){
        cin>>score[i];
    }
    sort(score, num);
    cout<<score[0]<<" will be dropped\n";
    for(int i=0;i<num-1;i++){
        *(score+i)=*(score+i+1);
    }
    avg=mean(score, num-1);
    cout<<"Average is "<<avg<<endl;
    delete []score;
}
//Gaddis_7thEd_Chap9_Prob11
void problem5(){
    //Declare Variables
    int num;
    
    cout<<"Expand Array\n";
    cout<<"Please enter the size of the array : ";
    cin>>num;
    int *oarr = new int[num];
    cout<<"Please enter the numbers with space\n";
    for(int i=0;i<num;i++){
        cin>>oarr[i];
    }
    int *exarr=arrExpd(oarr, num);
    delete []oarr;
    for(int i=0;i<num*2;i++){
        cout<<*(exarr+i)<<" ";
    }
    cout<<"\n\n";
    delete exarr;
}
//Gaddis_7thEd_Chap9_Prob10
void problem6(){
    //Declare Variables
    int num;
    cout<<"Please enter the size of the array : ";
    cin>>num;
    int *arr = new int[num];
    cout<<"Please enter the numbers with spcae\n";
    for(int i=0;i<num;i++){
        cin>>*(arr+i);
    }
    int *newArr=rvsArr(arr, num);
    delete []arr;
    for(int i=0;i<num;i++){
        cout<<*(newArr+i)<<" ";
    }
    delete newArr;
    cout<<"\n\n";
    
}
int *fillArray(int num){
    srand(static_cast<unsigned int>(time(0)));
    cout<<"num is "<<num<<endl;
    int *arrp = new int[num];
    for(int i=0;i<num;i++){
        *(arrp+1)=rand()%5;
    }
    return arrp;
}
void sort(int array[], int num){
    bool swap;
    do{
        int temp;
        swap=false;
        for(int i=0; i<num-1; i++){
            if(array[i]>array[i+1]){
                temp= array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swap=true;
            }
        }
    }while(swap==true);
    for(int i=0;i<num;i++){
        cout<<array[i]<<endl;
    }
    cout<<endl;
}
float mean(int array[], int num){
    float ttl=0;
    for(int i=0;i<num;i++){
        ttl+=array[i];
    }
    return ttl/num;
}
float median(int array[], int num){
    float mid=(num+1)/2-1;
    cout<<"middle"<<mid<<endl;
    int imid=mid;
    if(mid==imid){
        return static_cast<float>(array[imid]);
    }
    else{
        return static_cast<float>(array[imid]+array[imid+1])/2;
    }
    
}
int *mode(int array[], int num){
    int nom;
    int *md;
    int inum=array[0];
    int mode;
    int cntmod=0;
    int count1=1, count2=0;
    
    
    for(int i=0; i<num-1;i++){
        if(array[i]==array[i+1]){
            count1++;
//            cout<<"i = "<<i<<endl;
//            cout<<"count = "<<count1<<endl;
//            cout<<"cntmod = "<<cntmod<<endl;
        }
        else if(count1>cntmod) {
//            cout<<"else if\n";
            cntmod = count1; // mode is the biggest ocurrences
            count1 = 1; // reset count for the new number
        }
        if(i==num-1 && count1>cntmod){
            cntmod = count1; // mode is the biggest ocurrences
        }
    }
    for(int i=0; i<num-1;i++){
        if(array[i]==array[i+1]){
            count1++;
            cout<<"i = "<<i<<endl;
            cout<<"count = "<<count1<<endl;
            cout<<"cntmod = "<<cntmod<<endl;
        }
        else if(count1==cntmod) {
            cout<<"else if\n";
            count2++;
        }
        if(i==num-1 && count1==cntmod){
            count2++;
        }
    }
    if(cntmod==1) nom=0, cntmod=0;
    cout<<"count2(nom) = "<<count2<<endl;
    nom=count2;
    md = new int[nom+2];
    md[1]=cntmod;
    md[0]=nom;
    cout<<"nom"<<nom<<endl;
    count2=0;
    count1=1;
    
    for(int i=0;i<num-1;i++){
        if(array[i]==array[i+1]){
            count1++;
        }
        else if(count1==cntmod){
            md[count2+2]=array[i];
            count2++;
            count1=1;
        }
        if(count1==cntmod && i==num-1){
            md[count2+2]=array[i];
            count2++;
            count1=1;
        }
        
    }
    cout<<md[0]<<" "<<md[1]<<endl;
    
    return md;
}
int *arrExpd(int oarr[], int num){
    int *newarr = new int[num*2];
    for(int i=0;i<num*2;i++){
        if(i<num){
            *(newarr+i)=*(oarr+i);
        }
        else{
            *(newarr+i)=0;
        }
    }
    return newarr;
}
int *rvsArr(int arr[], int num){
    int *narr = new int[num];
    int temp=0;
    for(int i=0;i<num;i++){
        do{
            temp*=10;
            temp+=arr[i]%10;
            arr[i]/=10;
        }while(arr[i]!=0);
        *(narr+i)=temp;
        temp=0;
    }
    return narr;
}
//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
//Choose problem number function
int getN(){
        int inN;
        cin>>inN;
        cout<<endl;
        return inN;
}