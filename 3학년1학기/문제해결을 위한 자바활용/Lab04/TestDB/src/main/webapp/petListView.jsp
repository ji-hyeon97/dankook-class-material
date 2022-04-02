<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="dto.*"%>
<%@ page import="dao.*"%>
<%@ page import="jdbc.*"%>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.sql.*"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>TestDB</title>
</head>
<body>
<%--
	Connection conn = null;
	try {
		conn = ConnectionProvider.getConnection();
	} catch (SQLException ex) {
		out.println("Fail to connection.<br>");
		out.println("SQLException: " + ex.getMessage());
	}
	PetDAO dao = new PetImpl(conn);
	List<Pet> petList = dao.selectList();
--%>
<%!
	// JDBC driver name and database URL
	private static final String DB_PROPERTIES = "?useSSL=false&serverTimezone=UTC"; // MySQL Connector J 8.0
	private static final String DB_SCHEMAS = "sampledb";
	private static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver"; // deprecated "com.mysql.jdbc.Driver";  // try "com.mysql.cj.jdbc.Driver"
	private static final String DB_URL = "jdbc:mysql://localhost/" + DB_SCHEMAS + DB_PROPERTIES; 
%>
<%
	//  Database credentials
	String USER = "root";
	String PASSWORD = "ace12345";

	Connection conn = null;
	try {
		Class.forName(JDBC_DRIVER); //STEP 2: Register JDBC driver
		conn = DriverManager.getConnection(DB_URL, USER, PASSWORD); //STEP 3: Open a connection
		
	} catch (SQLException ex) {
		out.println("Fail to connection.<br>");
		out.println("SQLException: " + ex.getMessage());
	}

	List<Pet> petList = null;
	PreparedStatement pstmt = null;
	ResultSet rs = null;	
	//STEP 4: Execute a query
	try {
		String sql = "select * from pet";
		pstmt = conn.prepareStatement(sql);
		rs = pstmt.executeQuery();
		petList = new ArrayList<>();
		while (rs.next()) {
			String name = rs.getString("name");
			String owner = rs.getString("owner");
			PetType species = PetType.nameOf(rs.getString("species"));
			Gender gender = Gender.nameOf(rs.getString("gender"));
			Date birth = rs.getDate("birth");
			Date death = rs.getDate("death");
			petList.add(new Pet(name, owner, species, gender, birth, death));
		}
	} catch (SQLException ex) {
		out.println("SQLException: " + ex.getMessage());
	} finally {
		if (rs != null)
			rs.close();
		if (pstmt != null)
			pstmt.close();
	}
	
	if (conn != null)
		conn.close();
%>
	<div>
		<h1>Pet Table</h1>
	</div>
<hr>
	<div style="padding-top: 10px">
		<%
		out.print(String.format("<table>"));
		out.print(String.format("<tr>" +
				"<td>Name</td>" +
				"<td>Owner</td>" +
				"<td>Species</td>" +
				"<td>Gender</td>" +
				"<td>Birth</td>" +
				"<td>Death</td>" +
				"</tr>"));
		for (Pet p : petList) {
			out.print(String.format(
					"<tr>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
					"</tr>",	
					p.getName(), p.getOwner(), p.getSpecies(),
					p.getGender(), p.getBirth(), p.getDeath()
			));
		}
		out.print(String.format("</table>"));
		%>		
	</div>
<hr>
</body>
</html>   
