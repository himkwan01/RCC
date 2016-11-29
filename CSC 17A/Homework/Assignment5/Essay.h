/* 
 * File:   Essay.h
 * Author: Himkw_000
 *
 * Created on December 12, 2014, 2:05 AM
 */

#ifndef ESSAY_H
#define	ESSAY_H
class GradedActivity{
public:
  GradedActivity(){score=0.0;}
  GradedActivity(float, float, float, float);
  GradedActivity(float s){score=s;}
  void setScore(float s){score=s;}
  float getScore()const{return score;}
protected:
  float score;
};
class Essay:public GradedActivity {
public:
  Essay();
  Essay(float, float, float, float);
private:
  float g, s, cl, c;
};

#endif	/* ESSAY_H */

