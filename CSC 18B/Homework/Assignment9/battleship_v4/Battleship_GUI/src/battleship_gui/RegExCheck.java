/*
 * Author: jdecker
 */
package battleship_gui;
 
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegExCheck {
    
    //First name regular expression pattern.
    public static String FNAMEPTRN = "[A-Z][a-zA-Z]*";
    //Last name regular expression pattern.
    public static String LNAMEPTRN = "[A-Z][a-zA-Z]*";
    //Email regular expression pattern.
    public static String EMAILPTRN = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"
            + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
    //Username regular expression pattern.
    //Must contain one lowercase. 4 - 10 chars.
    public static String USRNMPTRN = "^(?=.*[a-z])[a-zA-Z0-9]{4,10}$";
    //Password regular expression pattern.
    //Must contain one uppercase, one lowercase, one numeric. 8 - 15 chars.
    public static String PASSWDPTRN = "^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z]).{8,15}$";

    //Validate first name.
    public static boolean checkFirstName (String firstName){
        return firstName.matches (FNAMEPTRN);
    }
    
    //Validate last name.
    public static boolean checkLastName (String lastName){
        return lastName.matches (LNAMEPTRN);
    }
    
    //Validate email.
    public static boolean checkEmail (String emailAdd){
        return emailAdd.matches (EMAILPTRN);
    }
    
    //Validate username.
    public static boolean checkUsrnm (String userName){
        return userName.matches (USRNMPTRN);
    }
    
    //Validate password.
    public static boolean checkPasswd (String passWrd){
        return passWrd.matches (PASSWDPTRN);
    }
    
}