/* 
 * File:   AI.h
 * Author: Himkw_000
 *
 * Created on December 7, 2014, 5:01 PM
 */

#ifndef AI_H
#define	AI_H

class AI {
public:
  AI();
  void delay();
protected:
  bool done;
  bool cross[4];
  bool crossdone;
  bool goback;
  int hx, hy, x, y;
  bool finish;
  int oppcombo;
  int combo;
  char cx, cy;
  bool oneend;
  bool combohit;
  bool bhit;
};

#endif	/* AI_H */

