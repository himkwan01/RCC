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
public class Validate {
  public boolean place(String f){
    return f.matches("[A-J]{1}[0-9]{1}[A-J]{1}[0-9]{1}");
  }
  public boolean fire(String f){
    return f.matches("[A-J]{1}[0-9]{1}");
  }
}
