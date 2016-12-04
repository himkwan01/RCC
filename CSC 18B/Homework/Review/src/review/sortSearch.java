/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package review;

/**
 *
 * @author Himkw_000
 */
public class sortSearch extends baseSort{

  public sortSearch(int size) {
    super(size);
  }
  @Override
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
  @Override
  protected void print(boolean sorted) {
    if(sorted){
      sort();
    }
    for(int i=0;i<size;i++){
      System.out.println(arr[i]);
    }
  }
}
