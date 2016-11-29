/* 
 * File:   Essay.cpp
 * Author: Himkw_000
 * 
 * Created on December 12, 2014, 2:05 AM
 */

#include "Essay.h"
using namespace std;

GradedActivity::GradedActivity(float g, float s, float cl, float c){
  score=0;
  score+=g;
  score+=c;
  score+=cl;
  score+=c;
}
Essay::Essay(float g, float s, float cl, float c)
      :GradedActivity(g, s, cl, c){
  this->g=g;
  this->c=c;
  this->cl=cl;
  this->c=c;
}
Essay::Essay():GradedActivity(){
  g=0;
  s=0;
  cl=0;
  c=0;
}

