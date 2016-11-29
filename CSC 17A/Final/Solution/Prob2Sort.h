/* 
 * File:   Prob2Sort.h
 * Author: Himkw_000
 *
 * Created on December 8, 2014, 12:44 AM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H
#include <iostream>
using namespace std;
template<class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index = new int[NULL];};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array int size
		T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 
template<class T>
T *Prob2Sort<T>::sortArray(const T* str, int size, bool as){
  T *test = new T[size];
  T temp;
  for(int i=0;i<size;i++){
    test[i]=str[i];
  }
  bool swap;
  do{
    for(int i=0;i<size-1;i++){
      if(as==true){
        if(test[i]>test[i+1]){
          swap=true;
          temp=test[i];
          test[i+1]=test[i];
          test[i+1]=temp;
        }
      }
      else{
        if(test[i]<test[i+1]){
          swap=true;
          temp=test[i];
          test[i+1]=test[i];
          test[i+1]=temp;
        }
      }
    }
  }while(swap==true);
  return test;
}
template<class T>
//char *zc=rc.sortArray(ch2p,10,16,column,ascending);
T *Prob2Sort<T>::sortArray(const T *str,int y,int x,int col,bool as){
  T *test = new T[x*y];
//  cout<<x*y<<endl;
  for(int i=0;i<x*y;i++){
    test[i]=str[i];
  }
//  for(int i=0;i<x*y;i++){
//    cout<<test[i];
//	}
  col-=1;
  bool swap;
  T temp;
//  cout<<"sort function\n";
  do{
//    cout<<"swap=false\n";
    swap=false;
    for(int i=0;i<y-1;i++){
//      cout<<"i="<<i<<endl;
      if(as==true){
        if(test[i*x+col]>test[(i+1)*x+col]){
          swap=true;
          for(int j=0;j<x;j++){
            temp=test[i*x+j];
            test[i*x+j]=test[(i+1)*x+j];
            test[(i+1)*x+j]=temp;
          }
        }
      }
      else{
        if(test[i*x+col]<test[(i+1)*x+col]){
          swap=true;
          for(int j=0;j<x;j++){
            temp=test[i*x+j];
            test[i*x+j]=test[(i+1)*x+j];
            test[(i+1)*x+j]=temp;
          }
        }
      }
    }
  }while(swap==true);
  return test;
}
#endif	/* PROB2SORT_H */

