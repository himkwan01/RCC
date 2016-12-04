/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proj1;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Random;

/**
 *
 * @author Himkw_000
 */
public class Background {
  int[][]record;    //save the inputs
  char[][] result;  //save the results
  int[] input;      //check with correct answer
  int[] answer;     //answer used to check
  int[] answerO;    //answer backup
  int count;
  int X,O;
  boolean[] same;       //para arr
  Random rand = new Random();
  boolean win;
  
  public Background(){
    record = new int[10][4];
    input = new int[4];
    result = new char[10][4];
    answerO = new int[4];
    answer = new int[4];
    same = new boolean[4];
    win=false;
    //initialize
    for(int i=0;i<10;i++){
      for(int j=0;j<4;j++){
        record[i][j]=9;
        result[i][j]=' ';
      }
    }
    for(int i=0;i<4;i++){
      same[i]=false;
    }
    count=0;
  }
  public void AnswerGen(int lv){
    System.out.println("AnswerGen Begins");
    boolean repeat;
    if(lv==0){   //easy level
      System.out.println("Easy level");
      for(int i=0;i<4;i++){
        do{
          repeat=false;
          answerO[i]=rand.nextInt(8);  //only 8 color
          for(int j=0;j<i;j++){
            if(answerO[i]==answerO[j])
              repeat=true;
          }
        }while(repeat==true);
        //copy
        answer[i]=answerO[i];
        //output to file
        AnswerSave();
        System.out.print(answerO[i]);
      }
    }
    else{
      do{
        repeat=false;
        for(int i=0;i<3;i++){
          answerO[i]=rand.nextInt(8);  //only 8 color
          for(int j=0;j<i;j++){
            if(answerO[i]==answerO[j])
              repeat=true;
          }
        }
      }while(repeat);
      //copy 1st digit to last digit
      answerO[3]=answerO[0];
      int[] index={0,1,2,3};
      for(int i=0;i<4;i++){
        int place=rand.nextInt(4);  //random place
        int temp=index[i];          //save memory
        index[i]=index[place];      //shuffle loaction
        index[place]=temp;          //replace the value
      }
      for(int i=0;i<4;i++){
        answer[i]=answerO[index[i]];
      }
      for(int i=0;i<4;i++){
        answerO[i]=answer[i];
        System.out.print(answerO[i]);
      }
      AnswerSave();
    }
  }
  private void AnswerSave(){
    try(BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Answer.txt"), "UTF-8"))){
      for(int i=0;i<4;i++){
        writer.write(String.valueOf((char)((answerO[i])+48)));
      }
      writer.close();
    }catch (IOException ex){
      //handle me
      ex.printStackTrace();
    }
  }
  public int check(){
    int temp=0;
    X=0;
    O=0;
    System.out.println("Check mehtod begins");
    for(int i=0;i<4;i++){
      System.out.println(input[i]);
      same[i]=false;
    }
    for(int i=0;i<4;i++){
      //copy
      record[count][i]=input[i];
    }
    //check matches
    for(int j=0;j<4;j++){ 
        answer[j]=answerO[j];     //recover loaction memory
        if(input[j]==answer[j]){        //same place
            X++;                     //Count X
            same[j]=true;            //remember!!!! location
            answer[j]=10;              //erase that location memory
        }
    }
    for(int j=0;j<4;j++){ 
        for(int i=0;i<4;i++){
            if(answer[i]==input[j] && same[j]==false){
                O++;
                same[j]=true;             //matches!!!! remember location
                answer[i]=10;               //erase that location memory
            }
        }
    }
    for(int i=0;i<X; i++){
        System.out.print("X");
        temp+=10;
    }
    for(int i=0;i<O;i++){
        System.out.print("O");
        temp+=1;
    }
    System.out.println("");
    System.out.println(temp);
    if(temp==40)
      win=true;
    count++;
    return temp;
  }
}
