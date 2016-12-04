/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package battleship_gui;

/**
 *
 * @author Himkw_000
 */
public class AIprop {
  public AIprop(){
    for(int i=0;i<4;i++){
      cross[i]=true;
    }
    crossdone=true;
    goback = true;
    finish = true;
    oppcombo = 0;
    combo = 0;
    oneend = true;
    combohit =false;
    bhit = false;
  }
  boolean done;
  boolean crossdone;
  boolean[] cross = new boolean[4];
  boolean goback;
  int hx, hy, x, y;
  boolean finish;
  int oppcombo;
  int combo;
  boolean oneend;
  boolean combohit;
  boolean bhit;
}
