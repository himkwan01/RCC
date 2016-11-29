/* 
 * File:   Player.h
 * Author: Tsz, Kwan
 *
 * Created on September 25, 2014, 11:49 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

struct PlayerT{
    char **pt;
};
struct PlayerG{
    int unit[5];
    int x1, x2, y1, y2;
};
//Status
struct PlayerS{
    float hit;
    float miss;
};
#endif	/* PLAYER_H */

