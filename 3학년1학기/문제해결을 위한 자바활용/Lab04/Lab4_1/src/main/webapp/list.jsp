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
<title>식품 영양 성분</title>
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
	List<FoodBean> petList = null;
	PreparedStatement pstmt = null;
	ResultSet rs = null;	
	//STEP 4: Execute a query
	try {
		String sql = "select * from mfdsfood;";
		pstmt = conn.prepareStatement(sql);
		rs = pstmt.executeQuery();
		petList = new ArrayList<>();
		while (rs.next()) {
			String sample_id = rs.getString("sample_id");
			String name = rs.getString("name");
			String category = rs.getString("category");
			int serving_size = rs.getInt("serving_size");
			double calorie = rs.getDouble("calorie");
			double water = rs.getDouble("water");
			double protein = rs.getDouble("protein");
			double fat = rs.getDouble("fat");
			double carbohydrate = rs.getDouble("carbohydrate");
			double sugars = rs.getDouble("sugars");
			double fiber = rs.getDouble("fiber");
			int calcium = rs.getInt("calcium");
			double iron = rs.getDouble("iron");
			int magnesium = rs.getInt("magnesium");
			int phosphorus = rs.getInt("phosphorus");
			int potassium = rs.getInt("potassium");
			int sodium = rs.getInt("sodium");
			double zinc = rs.getDouble("zinc");
			double copper = rs.getDouble("copper");
			double manganese = rs.getDouble("manganese");
			double selenium = rs.getDouble("selenium");
			petList.add(new FoodBean(sample_id,name,category,serving_size,calorie,water,protein,fat,carbohydrate,
					sugars,fiber,calcium,iron,magnesium,phosphorus,potassium,sodium,zinc,copper,manganese,selenium));
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
		<h1>FoodBean Table</h1>
		<a href="addForm.jsp" class="btn btn-primary" role="button">데이터 추가</a>
        <a href="editForm.jsp" class="btn btn-info" role="button">데이터 변경</a>
        <a href="deleteForm.jsp" class="btn btn-success" role="button">데이터 삭제</a>
	</div>
</div>
<hr>
	<div style="padding-top: 10px">
	<table class="table table-striped">
		<%
		out.print(String.format("<tr>" +
				"<td>sample_id</td>" +
				"<td>name</td>" +
				"<td>category</td>" +
				"<td>serving_size</td>" +
				"<td>calorie</td>" +
				"<td>water</td>" +
				"<td>protein</td>" +
				"<td>fat</td>" +
				"<td>carbohydrate</td>" +
				"<td>sugars</td>" +
				"<td>fiber</td>" +
				"<td>calcium</td>" +
				"<td>iron</td>" +
				"<td>magnesium</td>" +
				"<td>phosphorus</td>" +
				"<td>potassium</td>" +
				"<td>sodium</td>" +
				"<td>zinc</td>" +
				"<td>copper</td>" +
				"<td>manganese</td>" +
				"<td>selenium</td>" +
				"</tr>"));
		for (FoodBean p : petList) {
			out.print(String.format(
					"<tr>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
						"<td>%s</td>" +
					"</tr>",	
					p.getSample_id(), p.getName(), p.getCategory(),
					p.getServing_size(), p.getCalorie(), p.getWater(),
					p.getProtein(), p.getFat(), p.getCarbohydrate(),
					p.getSugars(), p.getFiber(), p.getCalcium(),
					p.getIron(), p.getMagnesium(), p.getPhosphorus(),
					p.getPotassium(), p.getSodium(), p.getZinc(),
					p.getCopper(), p.getManganese(), p.getSelenium()
			));
		}
		%>		
		</table>
	</div>
<hr>
</body>
</html>   