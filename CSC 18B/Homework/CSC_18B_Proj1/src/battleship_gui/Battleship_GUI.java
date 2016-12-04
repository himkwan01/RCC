/*
 * File: Battleship_GUI
 * Programmer: Jasmine Anica
 * Class: CSC 18C
 * Date: 3/18/15
 */
package battleship_gui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author Jasmine
 */
public class Battleship_GUI extends JFrame {
    
    
  /**
   * @param args the command line arguments
   */
  
  //Program Begins Here
  public static void main(String[] args) {

    java.awt.EventQueue.invokeLater(new Runnable() {
      public void run() {
      try
      {
        //animation before prog start
        Thread.sleep(3000);
      }
      catch (InterruptedException ex)
      {
        // Do something, if there is a exception
        System.out.println(ex.toString());
      }
        JFrame_Battleship menu = new JFrame_Battleship();
        menu.setVisible(true);
        menu.setResizable(false);
      }
    });
  }
}
