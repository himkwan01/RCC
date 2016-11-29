/* 
 * File:   Prob4.cpp
 * Author: Himkw_000
 * 
 * Created on November 29, 2014, 5:12 PM
 */

#include "Time.h"

float TimeClock::elapsed(){
  int temp;
  if(endTime-(endTime/100)*100<milHour-(milHour/100)*100){
    temp=endTime-100+60;
  }
  temp-=milHour;
  return static_cast<float>(temp)/100;
}