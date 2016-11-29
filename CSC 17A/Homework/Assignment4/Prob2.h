/* 
 * File:   Prob2.h
 * Author: Himkw_000
 *
 * Created on November 23, 2014, 10:37 PM
 */

#ifndef PROB2_H
#define	PROB2_H
using namespace std;
class Employee {
public:
  Employee();
  Employee(string, int);
  Employee(string, int, string, string);
  void setNum(int idNum){
    this->idNum=idNum;
  }
  void setDep(string dep){
    this->dep=dep;
  }
  void setPos(string pos){
    this->pos=pos;
  }
  string getName(){
    return name;
  }
  int getNum(){
    return idNum;
  }
  string getDep(){
    return dep;
  }
  string getPos(){
    return pos;
  }
private:
  string name;
  int idNum;  //id num
  string dep; //department
  string pos; //position
};

#endif	/* PROB2_H */

