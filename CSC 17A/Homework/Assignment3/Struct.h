/* 
 * File:   Struct.h
 * Author: Himkw_000
 *
 * Created on October 15, 2014, 10:43 AM
 */

#ifndef STRUCT_H
#define	STRUCT_H
struct MovieData{
        string ttle;
        string dir;
        int yrRls;
        float runt;
        float cost;
        float yrrv;
};
struct Prog3{
    float n1, n2, n3, n4;
    float ttl;
    float avg;
};
struct Prog4{
    float ttl;
    float high;
    float low;
    float avg;
};
struct Prog5{
    string name;
    int num;
    int score;
};
struct MonthlyBudget{
    float arr[10];
};
struct Grade{
    string Name;
    int Idnum;
    int *Tests;
    float Average;
    char Grade;
};



#endif	/* STRUCT_H */

