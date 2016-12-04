package battleship_gui;

/**
 *
 * @author Jasmine
 */
public class PlayerInfo {

  private int login_id;
  private int player_id;
  private String firstName;
  private String lastName;
  private String email;
  private String username;
  private String password;
  // constructor
  public PlayerInfo(){
  } 

   // constructor
  public PlayerInfo(int login_id, String firstName, String lastName, 
      String email, String username, String password){
    setlogin_id(login_id);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setUsername(username);
    setPassword(password);
  } 
  public PlayerInfo(String email, String username, String password){
    setEmail(email);
    setUsername(username);
    setPassword(password);
  } 
  public PlayerInfo(int player_id, String first_name, String last_name, String email){
    setPlayer_id(player_id);
    setFirstName(first_name);
    setLastName(last_name);
    setEmail(email);
  }
  // sets the login_id
  public void setlogin_id(int login_id){
    this.login_id = login_id;
  }

  // returns the login_id 
  public int getlogin_id(){
    return login_id;
  }
  //set player id
  public void setPlayer_id(int player_id){
    this.player_id=player_id;
  }
  //return player id
  public int getPlayer_id(){
    return player_id;
  }
  // sets the firstName
  public void setFirstName(String firstName){
    this.firstName = firstName;
  } 

  // returns the first name 
  public String getFirstName(){
    return firstName;
  } 
   
  // sets the lastName
  public void setLastName(String lastName){
    this.lastName = lastName;
  } 

  // returns the last name 
  public String getLastName(){
   return lastName;
  }
   
   // sets the email address
   public void setEmail(String email){
      this.email = email;
   }

   // returns the email address
   public String getEmail(){
      return email;
   }
   
    // sets the username
   public void setUsername(String username){
      this.username = username;
   }

   // returns the username
  public String getUsername(){
    return username;
  } 
   
  // sets the password
  public void setPassword(String password){
    this.password = password;
  }

  // returns the password
  public String getPassword(){
    return password;
  } 
   
} // end class PlayerInfo


