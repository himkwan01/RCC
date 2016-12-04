/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package battleship_gui;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Random;

/**
 *
 * @author Himkw_000
 */
public class Background {
  int num=10;
  int x1, x2, y1, y2;
  char[][] ai = new char[10][10];
  int[] unit = {5, 4, 3, 3, 2};
  char[][] real = new char[num][num];
  char[][] fake = new char[num][num];
  char[][] player = new char [num][num];
  boolean valid;
  AIprop aiProp = new AIprop();
  
  
  //constructor
  public Background(){
    for(int i=0;i<num;i++){
      for(int j=0;j<num;j++){
        player[i][j]=' ';
      }
    }
  }
  
  public boolean place(String place, int count){
    valid=true;
    y1=(int)place.charAt(0)-65;
    x1=(int)place.charAt(1)-48;
    y2=(int)place.charAt(2)-65;
    x2=(int)place.charAt(3)-48;
    System.out.println(y1+" "+x1+" "+y2+" "+x2);
    valid=PlaceCheck(count);
    return valid;
  }
  private boolean PlaceCheck(int q){
    int max,min;
    int count=0;
    if(y1==y2){
      System.out.println("same y");
      if(Math.abs(x1-x2)!=unit[q]-1){
        valid=true;
        System.out.println("unit-false");
        return false;
      }
      else{
        if(x1>x2){
          System.out.println("x1>x2");
          max=x1;
          min=x2;
        }
        else{
          System.out.println("x2>x1");
          max=x2;
          min=x1;
        }
        System.out.println("max="+max);
        System.out.println("min="+min);
        System.out.println("p"+y1);
        for(int k=min;k<=max;k++){
          if(player[y1][k]==' '){
            count++;
          }
        }
        System.out.println("count="+count);
        if(count!=unit[q]){
          valid=false;
          System.out.println("overlap-false");
          return false;
        }
        if(valid){
          System.out.println("valid=true");
          for(int k=min;k<=max;k++){
            player[y1][k]=(char)(unit[q]+48);
          }
          return valid;
        }
      }
    }
    if(x1==x2){   //y is same
      if(Math.abs(y1-y2)!=unit[q]-1){ //check unit
        valid=false;
        return valid;
      }
      else{   //valid
        if(y1>y2){
          max=y1;
          min=y2;
        }
        else{
          max=y2;
          min=y1;
        }
        //debug
        System.out.println("max="+max);
        System.out.println("min="+min);
        System.out.println("p"+x1);
        //debug
        for(int k=min;k<=max;k++){
          if(player[k][x1]==' '){
            count++;
            System.out.println("Count="+count);
          }
        }
        if(count!=unit[q]){
          valid=false;
          return false;
        }
        if(valid==true){
          for(int k=min;k<=max;k++){
            player[k][x1]=(char)(unit[q]+48);
          }
          return true;
        }
      }
    }
    if(x1!=x2 && y1!=y2){
      System.out.println("ERROR: not horizontal or vertical");
      return false;
    }
    else return false;
  }
  public void ai(){
    System.out.println("AIprepare running");
    Random rand = new Random();
    for(int i=0;i<num;i++){
      for(int j=0;j<num;j++){
        real[i][j]=' ';
        fake[i][j]=' ';
      }
    }
    int count, pos;
  //    boolean valid;
      for(int q=0;q<5;q++){
      do{
        valid=true;
        count=0;
        //random coordinates
        y1=rand.nextInt(10-unit[q]);     //won't over size
        x1=rand.nextInt(10-unit[q]);
        pos=rand.nextInt(2); //random place horizontal or vertical
        if(pos==0){                 //0 horizontal
          for(int k=y1;k<y1+unit[q];k++){
              if(real[k][x1]==' '){
                  count++;
              }
          }
          if(count!=unit[q]){
              valid=false;
          }
          if(valid==true){
              for(int k=y1;k<y1+unit[q];k++){
                  real[k][x1]=(char)(unit[q]+48);
              }
          }
        }
        else{                      //1 vertical
          for(int k=x1;k<x1+unit[q];k++){
              if(real[y1][k]==' '){
                  count++;
              }
          }
          if(count!=unit[q]){
              valid=false;
          }
          if(valid==true){
              for(int k=x1;k<x1+unit[q];k++){
                  real[y1][k]=(char)(unit[q]+48);
              }
          }
        }
      }while(valid==false);
    }
    System.out.println("AI prepared");
  }
  public boolean pFireCheck(String fire){
    valid=true; //reset
    //char input to int index
    y1=(int)fire.charAt(0)-65;
    x1=(int)fire.charAt(1)-48;
    //overlap
    if(real[y1][x1]=='O' || real[y1][x1]=='X'){
      valid=false;
      System.out.println("overlap-false");
    }
    //hit
    else if(real[y1][x1]>='2' && real[y1][x1]<='5'){
      System.out.println("PLAYER hit, valid");
      real[y1][x1]='X';
      fake[y1][x1]='X';
    }
    //miss
    else{
      System.out.println("PLAYER miss, valid");
      real[y1][x1]='O';
      fake[y1][x1]='O';
    }
    return valid;
  }
  public boolean pFireCheck(int y, int x){
    valid=true; //reset
    y1=y;
    x1=x;
    //overlap
    if(real[y1][x1]=='O' || real[y1][x1]=='X'){
      valid=false;
      System.out.println("PLAYER overlap-false");
    }
    //hit
    else if(real[y1][x1]>='2' && real[y1][x1]<='5'){
      System.out.println("PLAYER hit, valid");
      real[y1][x1]='X';
      fake[y1][x1]='X';
    }
    //miss
    else{
      System.out.println("PLAYER miss, valid");
      real[y1][x1]='O';
      fake[y1][x1]='O';
    }
    return valid;
  }
  public boolean chkWin(char[][] table){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(table[i][j]>='2' && table[i][j]<='5')
          return false;
      }
    }
    return true;
  }
  public void aiFirebg(){
    Random rand = new Random();
    //delay function
    
    //fire logic
    int hplan;
    aiProp.done = false;
    for(int i=0;i<4;i++){
      aiProp.cross[i]=true;
    }
    do{
      aiProp.done=false;
      //random fire
      if(aiProp.crossdone==true && aiProp.finish==true && 
         aiProp.goback==true && aiProp.done==false && 
         aiProp.oppcombo==0 && aiProp.combo==0){
        System.out.println("random fire");
        aiProp.goback=true;
        do{
          valid=true;
          aiProp.x=rand.nextInt(num);
          aiProp.y=rand.nextInt(num);
          System.out.println(aiProp.y+" "+aiProp.x);
          if(player[aiProp.y][aiProp.x]=='O' || 
             player[aiProp.y][aiProp.x]=='X'){
            valid=false;
            System.out.println("overlap");
          }
        }while(valid==false);
        //valid random fire
        if(player[aiProp.y][aiProp.x]!=' '){ //hit
          System.out.println("hit");
          player[aiProp.y][aiProp.x]='X';
          aiProp.hx=aiProp.x;
          aiProp.hy=aiProp.y;
          aiProp.bhit=true;
          aiProp.crossdone=false;
          aiProp.finish=false;
          aiProp.bhit=true;
          aiProp.combo=0;
          aiProp.done=true;
          aiProp.oneend=false;
        }
        else{
          System.out.println("miss");
          player[aiProp.y][aiProp.x]='O';
          aiProp.done=true;
        }
      }
    
      if(aiProp.bhit==true && aiProp.finish==false && 
         aiProp.crossdone==false && aiProp.combo==0 && 
         aiProp.oppcombo==0 && aiProp.done==false){
        do{
          System.out.println("random cross");
          System.out.println("hx="+aiProp.hx);
          System.out.println("hy="+aiProp.hy);
          aiProp.y=aiProp.hy;
          aiProp.x=aiProp.hx;
          System.out.println("y="+aiProp.y);
          System.out.println("x="+aiProp.x);
          //check cross rand
          hplan=rand.nextInt(4);
          if(hplan==0) aiProp.y=aiProp.hy-1;
          if(hplan==1) aiProp.y=aiProp.hy+1;
          if(hplan==2) aiProp.x=aiProp.hx-1;
          if(hplan==3) aiProp.x=aiProp.hx+1;
          System.out.println("hplan="+hplan);
          //check over size
          if(aiProp.y<0 || aiProp.y>num-1 || aiProp.x<0 || aiProp.x>num-1){
            System.out.println("Out table");
            aiProp.cross[hplan]=false;
          }
          else if(player[aiProp.y][aiProp.x]=='X' ||
                  player[aiProp.y][aiProp.x]=='O'){
            System.out.println("overlap");
            aiProp.cross[hplan]=false;
          }
          if(aiProp.cross[0]==aiProp.cross[1] && 
             aiProp.cross[1]==aiProp.cross[2] && 
             aiProp.cross[2]==aiProp.cross[3] && 
             aiProp.cross[0]==false){
            System.out.println("Test all 4 but invalid");
            aiProp.crossdone=true;
            aiProp.finish=true;
            aiProp.goback=true;
          }
          System.out.println("cross rand gen end");
          System.out.println("Crossdone="+aiProp.crossdone);
          System.out.println("cross[hplan]="+aiProp.cross[hplan]);
        }while(aiProp.crossdone==false && aiProp.cross[hplan]==false);
        
        //valid random cross
        if(aiProp.crossdone==false){
          System.out.println("check hit or miss by cross rand xy");
          if(player[aiProp.y][aiProp.x]!=' '){ //hit
          player[aiProp.y][aiProp.x]='X';
          aiProp.done=true;
          aiProp.combo++;
          aiProp.crossdone=true;
        }
        else{
          player[aiProp.y][aiProp.x]='O';
          aiProp.done=true;
        }
        }
        else{
          System.out.println("crossdone=true, go back to rand");
          aiProp.goback=true;
        }
      }
      else if(aiProp.combo>0 && aiProp.oneend==false &&
              aiProp.done==false &&aiProp.crossdone==true){
        System.out.println("Second hit");
        valid=true;
        if(aiProp.hx==aiProp.x){
          System.out.println("same x");
          if(aiProp.hy>aiProp.y) aiProp.y=aiProp.hy-aiProp.combo-1;
          else                   aiProp.y=aiProp.hy+aiProp.combo+1;
          if(aiProp.y<0 || aiProp.y >num-1){
            valid=false;
          }
          if(valid==true){
            if(player[aiProp.y][aiProp.x]=='X' || 
               player[aiProp.y][aiProp.x]=='O'){
              valid=false;
            }
            if(player[aiProp.y][aiProp.x]=='O'){
              aiProp.finish=true;
              aiProp.goback=true;
              aiProp.crossdone=true;
              aiProp.combo=0;
              aiProp.oppcombo++;
              aiProp.oneend=true;
            }
            if(valid==true){
              if(player[aiProp.y][aiProp.x]!=' '){
                player[aiProp.y][aiProp.x]='X';
                aiProp.done=true;
                aiProp.combo++;
              }
              else{
                player[aiProp.y][aiProp.x]='O';
                aiProp.done=true;
                aiProp.oneend=true;
                aiProp.oppcombo++;
              }
            }
          }
          else{ //check ->GO TO OPPCOMBO
            System.out.println("next xy invalid change to opposite side");
            aiProp.combo=0;
            aiProp.oneend=true;
            aiProp.crossdone=true;
            aiProp.oppcombo++;
            aiProp.combohit=false;
          }
        }
        if(aiProp.hy==aiProp.y){
          System.out.print("same y");
          if(aiProp.hx>aiProp.x) aiProp.x=aiProp.hx-aiProp.combo-1;
          else                   aiProp.x=aiProp.hx+aiProp.combo+1;
          if(aiProp.x<0 || aiProp.x >num-1){
            valid=false;
            aiProp.combo=0;
            aiProp.goback=true;
            aiProp.finish=true;
          }
          if(valid==true){
            if(player[aiProp.y][aiProp.x]=='X' || 
               player[aiProp.y][aiProp.x]=='O'){
              valid=false;
              aiProp.finish=true;
              aiProp.goback=true;
            }
            if(valid==true){
              if(player[aiProp.y][aiProp.x]!=' '){
                player[aiProp.y][aiProp.x]='X';
                aiProp.combo++;
                aiProp.done=true;
              }
              else{
                player[aiProp.y][aiProp.x]='O';
                aiProp.done=true;
                aiProp.oneend=true;
                aiProp.oppcombo++;
                aiProp.combo=0;
                aiProp.combohit=false;
                System.out.println("oneend==true");
                System.out.println("done==true");
              }
            }
          }
          if(valid==false){ //GO TO OPPCOMBO
            System.out.println("next xy invalid change to other side");
            aiProp.combo=0;
            aiProp.oneend=true;
            aiProp.crossdone=true;
            aiProp.oppcombo++;
            aiProp.combohit=false;
          }
        }
      }
      //check other side
      else if(aiProp.oppcombo>0 && aiProp.oneend==true && 
              aiProp.done==false){
        System.out.println("one side end check other side");
        System.out.println("oppcombo = "+aiProp.oppcombo);
        if(aiProp.hx==aiProp.x){
          System.out.println("same x");
          if(aiProp.combohit==false){
            if(aiProp.hy>aiProp.y) aiProp.y=aiProp.hy+aiProp.oppcombo;
            else                   aiProp.y=aiProp.hy-aiProp.oppcombo;
          }
          else{
            if(aiProp.y>aiProp.hy) aiProp.y=aiProp.hy+aiProp.oppcombo;
            else                   aiProp.y=aiProp.hy-aiProp.oppcombo;
          }
          if(aiProp.y<0 || aiProp.y>num-1 || 
             player[aiProp.y][aiProp.x]=='O' || 
             player[aiProp.y][aiProp.x]=='X'){
            aiProp.oppcombo=0;
            aiProp.goback=true;
            aiProp.finish=true;
            aiProp.crossdone=true;
            aiProp.combo=0;
            aiProp.done=false;
            System.out.println("overlap or oversize");
          }
          else{
            if(player[aiProp.y][aiProp.x]!=' '){
              player[aiProp.y][aiProp.x]='X';
              aiProp.done=true;
              aiProp.oppcombo+=1;
              aiProp.combohit=true;
            }
            else{
              player[aiProp.y][aiProp.x]='O';
              aiProp.done=true;
              aiProp.combo=0;
              aiProp.oppcombo=0;
              aiProp.finish=true;
              aiProp.goback=true;
              aiProp.crossdone=true;
            }
          }
        }
        else if(aiProp.hy==aiProp.y){
          System.out.println("same y");
          if(aiProp.combohit==false){
            if(aiProp.hx>aiProp.x) aiProp.x=aiProp.hx+aiProp.oppcombo;
            else                   aiProp.x=aiProp.hx-aiProp.oppcombo;
          }
          else{
            if(aiProp.x>aiProp.hx) aiProp.x=aiProp.hx+aiProp.oppcombo;
            else                   aiProp.x=aiProp.hx-aiProp.oppcombo;
          }
          if(aiProp.x<0 || aiProp.x>num-1 || 
             player[aiProp.y][aiProp.x]=='O' || 
             player[aiProp.y][aiProp.x]=='X'){
            aiProp.oppcombo=0;
            aiProp.goback=true;
            aiProp.finish=true;
            aiProp.crossdone=true;
            aiProp.combo=0;
            aiProp.done=false;
            System.out.println("overlap or oversize");
          }
          else{
            if(player[aiProp.y][aiProp.x]!=' '){
               player[aiProp.y][aiProp.x]='X';
              aiProp.done=true;
              aiProp.oppcombo+=1;
              aiProp.combohit=true;
            }
            else{
              player[aiProp.y][aiProp.x]='O';
              aiProp.done=true;
              aiProp.combo=0;
              aiProp.oppcombo=0;
              aiProp.finish=true;
              aiProp.goback=true;
              aiProp.crossdone=true;
            }
          }
        }
      }
    }while(aiProp.done==false);
  }
  
}
