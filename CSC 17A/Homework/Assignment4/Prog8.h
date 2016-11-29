/* 
 * File:   Prog8.h
 * Author: Himkw_000
 *
 * Created on November 28, 2014, 11:24 PM
 */

#ifndef PROG8_H
#define	PROG8_H

class NumDays {
public:
  NumDays(int hr=0){
    this->hr=hr;
    setDay();
  }
  NumDays operator +(const NumDays &);
  NumDays operator -(const NumDays &);
  NumDays operator ++();
  NumDays operator --();
  NumDays operator ++(int);
  NumDays operator --(int);
  int getHr(){
    return hr;
  }
  void setHr(int hr){
    this->hr=hr;
  }
  float getDay(){
    return day;
  }
private:
  void setDay(){
    day=static_cast<float>(hr)/8;
  }
  int hr;
  float day;
};

#endif	/* PROG8_H */

