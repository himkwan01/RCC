/* 
 * File:   Struct.h
 * Author: Tsz, Kwan
 * Created on October 16, 2014, 11:26 AM
 * Purpose: midterm
 */

#ifndef STRUCT_H
#define	STRUCT_H
struct Prog1{
    char actnum[5]; //account num
    float bln;  //balance at the beginig og the month
    float chk; //check written by this customer's account this month
    float dps; //deposits this month
};
struct Prog2{
    string name; //employee's name
    int hrs;     //hours work
    float rtpay; //rate of pay
};
struct statsResult{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency
};


#endif	/* STRUCT_H */

