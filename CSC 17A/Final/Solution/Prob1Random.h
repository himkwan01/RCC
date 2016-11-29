/* 
 * File:   Prob1Random.h
 * Author: Himkw_000
 *
 * Created on December 7, 2014, 11:24 PM
 */

#ifndef PROB1RANDOM_H
#define	PROB1RANDOM_H
#include <ctime>
#include <cstdlib>
using namespace std;
class Prob1Random
{
	private:
		unsigned char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		unsigned char randFromSet(void){                   //Returns a random number from the set
      numRand++;
      int temp=rand()%5;
      freq[temp]++;
      return set[temp];
    }
    int *getFreq(void) const{                 //Returns the frequency histogram
      return freq;
    }
    unsigned char *getSet(void) const{                 //Returns the set used
      return set;
    }
    int getNumRand(void) const{               //Gets the number of times randFromSet has
		     return numRand;                     //been called
    }
};

#endif	/* PROB1RANDOM_H */

