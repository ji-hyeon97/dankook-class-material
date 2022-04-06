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
<meta charset="UTF-8">
<title>구매 테이블</title>
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
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
	String PASSWORD = "sgh97010!";
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
	try {
		String sql = "select * from buy;";
		pstmt = conn.prepareStatement(sql);
		rs = pstmt.executeQuery();
		petList = new ArrayList<>();
		while (rs.next()) {
			int num = rs.getInt("num");
			String prod_name = rs.getString("prod_name");
			String group_name = rs.getString("group_name");
			int price = rs.getInt("price");
			int amount = rs.getInt("amount");
			
			petList.add(new BuyBean(num,prod_name,group_name,price,amount));
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
<div class="jumbotron">
	<div>
		<h1>구매 테이블</h1>
		<a href="addForm.jsp" class="btn btn-primary" role="button">제품 추가</a>
        <a href="editForm.jsp" class="btn btn-info" role="button">제품 데이터변경</a>
        <a href="deleteForm.jsp" class="btn btn-success" role="button">제품 삭제</a>
	</div>
</div>
<hr>
	<div style="padding-top: 10px">
	<table class="table table-striped">
		<%
		out.print(String.format("<tr>" +
				"<td>번호</td>" +
				"<td>제품</td>" +
				"<td>제품분류</td>" +
				"<td>가격</td>" +
				"<td>수량</td>"+
				"</tr>"));
		for (BuyBean p : petList) {
			out.print(String.format(
					"<tr>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
					"</tr>",	
					p.getNum(), p.getProd_name(), p.getGroup_name(),p.getPrice(), p.getAmount()));
		}
		%>		
		</table>
	</div>
<hr>
</body>
</html>   