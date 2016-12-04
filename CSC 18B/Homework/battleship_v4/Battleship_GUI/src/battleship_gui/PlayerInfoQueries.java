
package battleship_gui;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Jasmine
 */
public class PlayerInfoQueries {
    
   private static final String URL = "jdbc:mysql://209.129.8.4:3306/42029";
   private static final String USERNAME = "42029";
   private static final String PASSWORD = "42029csc18b";

   private Connection connection; // manages connection
   private PreparedStatement selectAllPlayers; 
   private PreparedStatement selectPlayerByUsername; 
   private PreparedStatement insertNewPlayerInfo;
   private PreparedStatement insertNewPlayerLogin;
   private PreparedStatement insertNewPlayerXref;
   private PreparedStatement selectPlayerByEither;
   private List<PlayerInfo> temp;
   // constructor
   public PlayerInfoQueries(){
      try{
        connection = 
            DriverManager.getConnection(URL, USERNAME, PASSWORD);

        // create query that selects all entries in the AddressBook
        selectAllPlayers = 
            connection.prepareStatement("SELECT * FROM battleship_entity_player");
         
        // create query that selects entries with a specific last name
        selectPlayerByUsername = connection.prepareStatement(
            "SELECT * FROM battleship_entity_login WHERE username = ?");
        selectPlayerByEither = connection.prepareStatement(
            "SELECT `battleship_entity_player`.`email`, `battleship_entity_login`."
              + "`username`, `battleship_entity_login`.`password` FROM `42029`."
              + "`battleship_xref_player_login` AS `battleship_xref_player_login`, "
              + "`42029`.`battleship_entity_player` AS `battleship_entity_player`, "
              + "`42029`.`battleship_entity_login` AS `battleship_entity_login` "
              + "WHERE `battleship_xref_player_login`.`player_id` = "
              + "`battleship_entity_player`.`player_id` AND `battleship_xref_player_login`."
              + "`login_id` = `battleship_entity_login`.`login_id` AND ( `battleship_entity_player`."
              + "`email` = ? OR `battleship_entity_login`.`username` = ? )");
        // create insert that adds a new entry into the database
        insertNewPlayerInfo = connection.prepareStatement(
            "INSERT INTO battleship_entity_player " + 
            "(first_name, last_name, email) " + 
            "VALUES (?, ?, ?)");
         
        // create insert that adds a new entry into the database
        insertNewPlayerLogin = connection.prepareStatement(
            "INSERT INTO battleship_entity_login " + 
            "(username, password) " + 
            "VALUES (?, ?)");
        //update xref
        insertNewPlayerXref = connection.prepareStatement(
            "INSERT INTO battleship_xref_player_login " +
            "(player_id, login_id) " +
            "VALUES (?, ?)");
      }
      catch (SQLException sqlException)
      {
         sqlException.printStackTrace();
         System.exit(1);
      }
   } // end PersonQueries constructor
   
   // ! useless and needed to be change
   // select all of the addresses in the database
   public List<PlayerInfo> getAllPeople(){
      List<PlayerInfo> results = null;
      ResultSet resultSet = null;
//      
      try{
        // executeQuery returns ResultSet containing matching entries
        resultSet = selectAllPlayers.executeQuery(); 
        results = new ArrayList<PlayerInfo>();
         
        while (resultSet.next()){
          results.add(new PlayerInfo(
          resultSet.getInt("player_id"),
          resultSet.getString("first_name"),
          resultSet.getString("last_name"),
          resultSet.getString("email")));
//          resultSet.getString("username"),
//          resultSet.getString("password")));
        } 
      } 
      catch (SQLException sqlException){
        sqlException.printStackTrace();         
      } 
      finally{
        try{
          resultSet.close();
        } 
        catch (SQLException sqlException){
          sqlException.printStackTrace();         
          close();
        }
      }
//      
      return results;
   } 

   // select person by username or email  
   public List<PlayerInfo> getPlayerByUsername(String username){
      List<PlayerInfo> results = null;
      ResultSet resultSet = null;

      try{
        //two para are the same thing username or email
        selectPlayerByEither.setString(1, username);  //first para
        selectPlayerByEither.setString(2, username);  //second para

        // executeQuery returns ResultSet containing matching entries
        resultSet = selectPlayerByEither.executeQuery(); 
        results = new ArrayList();

        while (resultSet.next()){
          System.out.println(resultSet.getString("username"));
          System.out.println(resultSet.getString("email"));
          System.out.println(resultSet.getString("password"));
          results.add(new PlayerInfo(resultSet.getString("email"),
//          resultSet.getString("firstName"),
//          resultSet.getString("lastName"),
//          resultSet.getString("email"),
          resultSet.getString("username"),
          resultSet.getString("password")));
        }
      } 
      catch(SQLException sqlException){
        sqlException.printStackTrace();
      } 
      finally{
        try{
          resultSet.close();
        }
        catch (SQLException sqlException){
          sqlException.printStackTrace();         
          close();
        }
      } 
      
      return results;
   } 
   
   // add an entry
   public int addPlayer(
      String fname, String lname, String email, String username, String password)
   {
      int result = 0;
      
      // set parameters, then execute insertNewPerson
      try{
        insertNewPlayerInfo.setString(1, fname);
        insertNewPlayerInfo.setString(2, lname);
        insertNewPlayerInfo.setString(3, email);
        insertNewPlayerLogin.setString(1, username);
        insertNewPlayerLogin.setString(2, password);
        temp = getAllPeople();
        insertNewPlayerXref.setString(1, String.valueOf(temp.size()+1));
        insertNewPlayerXref.setString(2, String.valueOf(temp.size()+1));
        

        // insert the new entry; returns # of rows updated
        result = insertNewPlayerInfo.executeUpdate(); 
         
        // insert the new entry; returns # of rows updated
        result += insertNewPlayerLogin.executeUpdate(); 
        result += insertNewPlayerXref.executeUpdate();
      }
      catch (SQLException sqlException){
        sqlException.printStackTrace();
        close();
      } 
      
      return result;
   } 
   
   // close the database connection
   public void close(){
      try{
        connection.close();
      } 
      catch(SQLException sqlException){
        sqlException.printStackTrace();
      } 
   } 
} // end class PersonQueries

