/* 
 * File:   Prob1Random.cpp
 * Author: Himkw_000
 * 
 * Created on December 7, 2014, 11:24 PM
 */

#include "Prob1Random.h"
#include <iostream>
using namespace std;
Prob1Random::Prob1Random(const char a,const char *b){
  srand(time(0));
  set = new unsigned char[static_cast<int>(a)];
  nset = a;
  freq = new int[static_cast<int>(a)];
  for(int i=0;i<static_cast<int>(a);i++){
    set[i]=b[i];
    freq[i]=0;
  }
//  for(int i=0;i<static_cast<int>(a);i++)
//    cout<<set[i];
  numRand=0;
  
}
Prob1Random::~Prob1Random(){
  delete []set;
  delete []freq;
}