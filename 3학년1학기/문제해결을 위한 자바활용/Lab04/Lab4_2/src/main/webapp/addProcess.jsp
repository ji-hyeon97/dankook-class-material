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

int num = Integer.parseInt(request.getParameter("num"));
String prod_name = request.getParameter("prod_name");
String group_name = request.getParameter("group_name");
int price = Integer.parseInt(request.getParameter("price"));
int amount = Integer.parseInt(request.getParameter("amount"));

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
	List<BuyBean> petList = null;
	PreparedStatement pstmt = null;
	ResultSet rs = null;	
	//STEP 4: Execute a query
	
	String sql = "insert into buy values (?,?,?,?,?)";
	pstmt = conn.prepareStatement(sql);
			
	pstmt.setInt(1, num);
	pstmt.setString(2, prod_name);
	pstmt.setString(3, group_name);
	pstmt.setInt(4, price);
	pstmt.setInt(5, amount);

	
	pstmt.executeUpdate();
	pstmt.close();
	conn.close();
	response.sendRedirect("lab4_2.jsp");
%>
</body>
</html>