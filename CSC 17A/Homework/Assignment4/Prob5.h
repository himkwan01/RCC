/* 
 * File:   Prob5.h
 * Author: Himkw_000
 *
 * Created on November 25, 2014, 10:31 AM
 */

#ifndef PROB5_H
#define	PROB5_H
#include <iostream>
using namespace std;
class RetailItem {
public:
  RetailItem(string, int, float);
  void setUnit(int unit){
    unitsOnHand=unit;
  }
  void setPrice(float price){
    this->price=price;
  }
  string getDes(){
    return description;
  }
  int getUnit(){
    return unitsOnHand;
  }
  float getPrice(){
    return price;
  }
private:
  string description;  //holds a brief description of the item
  int unitsOnHand;  //holds the number of units currently in inventory
  float price;
};

#endif	/* PROB5_H */

