import java.sql.*;

public class SampleDBPetTest {
	
	// JDBC driver name and database URL
	private static final String PROPERTIES = "?useSSL=false"; // MySQL Connector J 8.0
	private static final String DB_SCHEMAS = "sampledb";
	private static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver"; // deprecated "com.mysql.jdbc.Driver";  
	private static final String DB_URL = "jdbc:mysql://localhost:3306/" + DB_SCHEMAS + PROPERTIES; 

	//  Database credentials
	private static final String USER = "root";
	private static final String PASS = "ace12345";
	
	public static Connection getConnection() throws SQLException {
		try {
			Class.forName(JDBC_DRIVER); //STEP 2: Register JDBC driver
		} catch (ClassNotFoundException e) {
			e.getMessage();
		} 
		return DriverManager.getConnection(DB_URL,USER,PASS); //STEP 3: Open a connection
	}

	   
	public static void main(String[] args) {
		Connection conn = null;
		Statement stmt = null;
		
		try {
			conn = getConnection();

			//STEP 4: Execute a query
			System.out.println("Creating statement...");
			stmt = conn.createStatement();
			//STEP 5: Extract data from result set
			ResultSet rs = stmt.executeQuery("SELECT name, owner, species, gender, birth, death from pet where owner='Gwen'");
			printData(rs);
			
			//STEP 6: INSERT,UPDATE,DELETE
			String command = "INSERT INTO pet VALUES ('Puffball', 'Diane', 'hamster', 'f', '1999-03-30', NULL);\r\n";
			//String command = "UPDATE pet set owner ='Benny' where name='Puffball'";
			//String command = "DELETE from pet where name='Puffball'";
			int ret = stmt.executeUpdate(command);
			printTable(stmt);

			//STEP 6: Clean-up environment
			stmt.close();
			conn.close();
		} catch(SQLException se){
			//Handle errors for JDBC
			se.printStackTrace();
		} catch(Exception e){
			//Handle errors for Class.forName
			e.printStackTrace();
		} finally {
			//finally block used to close resources
			try {
				if(stmt!=null) stmt.close();
			} catch(SQLException se2){
			}// nothing we can do

			try {
				if(conn!=null) conn.close();
			} catch(SQLException se){
				se.printStackTrace();
			}//end finally try

		}//end try
		System.out.println("Goodbye!");
	}//end main
	
	private static void printData(ResultSet rs) throws SQLException {
		while(rs.next()) {
			//Retrieve by column name
			String name  = rs.getString("name");
			String owner  = rs.getString("owner");
			String species  = rs.getString("species");
			String gender = rs.getString("gender");
			Date birth = rs.getDate("birth");
			Date death = rs.getDate("death");

			//Display values
			System.out.print("name: " + name);
			System.out.print(", owner: " + owner);
			System.out.print(", species: " + species);
			System.out.print(", gender: " + gender);
			System.out.print(", birth: " + birth);
			System.out.println(", death: " + death);
		}
		System.out.println("..");
	}
	
	private static void printTable(Statement stmt) throws SQLException {
		String sql = "SELECT name, owner, species, gender, birth, death FROM pet";
		ResultSet rs = stmt.executeQuery(sql);
		while(rs.next()) {
			//Retrieve by column name
			String name  = rs.getString("name");
			String owner  = rs.getString("owner");
			String species  = rs.getString("species");
			String gender = rs.getString("gender");
			Date birth = rs.getDate("birth");
			Date death = rs.getDate("death");

			//Display values
			System.out.print("name: " + name);
			System.out.print(", owner: " + owner);
			System.out.print(", species: " + species);
			System.out.print(", sex: " + gender);
			System.out.print(", birth: " + birth);
			System.out.println(", death: " + death);
		}
		System.out.println("end of rs..");
		rs.close();
	}

}
