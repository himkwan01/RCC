/* 
 * File:   AI.h
 * Author: Tsz, Kwan
 *
 * Created on September 30, 2014, 10:34 AM
 */

#ifndef AI_H
#define	AI_H
struct AIT{
    char **fake, **real;
};
struct AIG{
    bool over;
    bool done;
    bool cross[4];
    bool crossdone;
    bool goback;
    int hx, hy, x, y;
    bool finish;
    int oppcombo;
    int combo;
    char cx, cy;
    bool hit;
    bool oneend;
    bool combohit;
};
struct AIS{
    float miss, hit;
};


#endif	/* AI_H */

