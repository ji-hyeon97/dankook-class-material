<%@page import="java.sql.*"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="dto.*"%>
<%@ page import="dao.*"%>
<%@ page import="jdbc.*"%>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>식품 영양 성분</title>
</head>
<body>
<%
request.setCharacterEncoding("UTF-8");

String sample_id = request.getParameter("sample_id");
String name = request.getParameter("name");
String category = request.getParameter("category");
int serving_size = Integer.parseInt(request.getParameter("serving_size"));
double calorie = Double.parseDouble(request.getParameter("calorie"));
double water = Double.parseDouble(request.getParameter("water"));
double protein = Double.parseDouble(request.getParameter("protein"));
double fat = Double.parseDouble(request.getParameter("fat"));
double carbohydrate = Double.parseDouble(request.getParameter("carbohydrate"));
double sugars = Double.parseDouble(request.getParameter("sugars"));
double fiber = Double.parseDouble(request.getParameter("fiber"));
int calcium = Integer.parseInt(request.getParameter("calcium"));
double iron = Double.parseDouble(request.getParameter("iron"));
int magnesium = Integer.parseInt(request.getParameter("magnesium"));
int phosphorus = Integer.parseInt(request.getParameter("phosphorus"));
int potassium = Integer.parseInt(request.getParameter("potassium"));
int sodium = Integer.parseInt(request.getParameter("sodium"));
double zinc = Double.parseDouble(request.getParameter("zinc"));
double copper = Double.parseDouble(request.getParameter("copper"));
double manganese = Double.parseDouble(request.getParameter("manganese"));
double selenium = Double.parseDouble(request.getParameter("selenium"));
%>
<%--
	Connection conn = null;
	try {
		conn = ConnectionProvider.getConnection();
	} catch (SQLException ex) {
		out.println("Fail to connection.<br>");
		out.println("SQLException: " + ex.getMessage());
	}
	FoodDAO dao = new FoodDAOImpl(conn);
	List<FoodBean> petList = dao.selectList();
--%>
<%!
	// JDBC driver name and database URL
	private static final String DB_PROPERTIES = "?useSSL=false&serverTimezone=UTC"; // MySQL Connector J 8.0
	private static final String DB_SCHEMAS = "sample_db";
	private static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver"; // deprecated "com.mysql.jdbc.Driver";  // try "com.mysql.cj.jdbc.Driver"
	private static final String DB_URL = "jdbc:mysql://localhost/" + DB_SCHEMAS + DB_PROPERTIES; 
%>
<%
	//  Database credentials
	String USER = "root";
	String PASSWORD = "mysql 비밀번호 작성";
	Connection conn = null;
	try {
		Class.forName(JDBC_DRIVER); //STEP 2: Register JDBC driver
		conn = DriverManager.getConnection(DB_URL, USER, PASSWORD); //STEP 3: Open a connection
		
	} catch (SQLException ex) {
		out.println("Fail to connection.<br>");
		out.println("SQLException: " + ex.getMessage());
	}
	List<FoodBean> petList = null;
	PreparedStatement pstmt = null;
	ResultSet rs = null;	
	//STEP 4: Execute a query
	
	String sql = "insert into mfdsfood values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	pstmt = conn.prepareStatement(sql);
			
	pstmt.setString(1, sample_id);
	pstmt.setString(2, name);
	pstmt.setString(3, category);
	pstmt.setInt(4, serving_size);
	pstmt.setDouble(5, calorie);
	pstmt.setDouble(6, water);
	pstmt.setDouble(7, protein);
	pstmt.setDouble(8, fat);
	pstmt.setDouble(9, carbohydrate);
	pstmt.setDouble(10, sugars);
	pstmt.setDouble(11, fiber);
	pstmt.setInt(12, calcium);
	pstmt.setDouble(13, iron);
	pstmt.setInt(14, magnesium);
	pstmt.setInt(15, phosphorus);
	pstmt.setInt(16, potassium);
	pstmt.setInt(17, sodium);
	pstmt.setDouble(18, zinc);
	pstmt.setDouble(19, copper);
	pstmt.setDouble(20, manganese);
	pstmt.setDouble(21, selenium);
	
	pstmt.executeUpdate();
	pstmt.close();
	conn.close();
	response.sendRedirect("lab4.jsp");
%>
</body>
</html>

	
	
	
	
	
	
	
	
	
	
	
	
			
			
			