/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package review;

import java.util.Random;

/**
 *
 * @author Himkw_000
 */
public class baseSort extends absSort{
  int[] arr;
  int size;
  Random rand = new Random();
  public baseSort(int size){
    this.size = size;
    fillArray(size);
  }
  @Override
  public void fillArray(int size){
    arr = new int[size];
    for(int i=0;i<size;i++){
      arr[i] = rand.nextInt(90)+10;
    }
  }

  protected void sort() {
    boolean swap;
    int temp;
    do{
      swap=false;
      for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
          swap = true;
          temp = arr[i];
          arr[i] = arr[i+1];
          arr[i+1] = temp;
        }
      }
    }while(swap);
  }

  protected void print(boolean sorted) {
    if(sorted){
      sort();
    }
    for(int i=0;i<size;i++){
      System.out.println(arr[i]);
    }
  }
  public boolean binarySearch(int a){
    sort();
    int mid=size/2;
    int max=size;
    int min=0;
    
    do{
      if(arr[mid]==a)
        return true;
      if(arr[mid]>a){
        max=mid;
        mid=(min+max)/2;
      }
      else{
        min=mid;
        mid=(min+max)/2;
      }
    }while(min!=mid);
    
    return false;
  }
}
