/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package review;

import java.util.Scanner;
import review.baseSort;
/**
 *
 * @author Himkw_000
 */
public class Review {

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    // TODO code application logic here
    Scanner cin = new Scanner(System.in);
    
    System.out.print("Size of the array: ");
    int size = cin.nextInt();
    baseSort review = new sortSearch(size);
    System.out.println("sortsearch class");
    review.print(false);
    System.out.println();
    review.print(true);
    System.out.println();
    System.out.println("baseSort class");
    review = new baseSort(size);
    review.print(false);
    System.out.println();
    review.print(true);
    System.out.println("Enter a num to search:");
    if(review.binarySearch(cin.nextInt()))
      System.out.println("The number is inside the array");
    else 
      System.out.println("The number isn't insdie the array");
        
  }
  
}
