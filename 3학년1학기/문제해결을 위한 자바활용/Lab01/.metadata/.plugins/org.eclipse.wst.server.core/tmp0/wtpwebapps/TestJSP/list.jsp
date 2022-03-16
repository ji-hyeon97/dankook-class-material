<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="java.util.List" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<%@ include file="declaration.jsp" %>
	<jsp:include page="header.jsp" />

	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3">Person List</h1>
		</div>
	</div>
	
	<div class="container">
		<div style="padding-top: 50px">
			<table class="table table-hover">
				<tr>
					<th>Name</th>
					<th>Age</th>
					<th>Gender</th>
					<th></th>
				</tr>
			<%
				List<Person> pList = manager.get(); // getlist
				for (Person p : pList) {
			%>
					<tr>
					<td><%= p.getName() %></td>
					<td><%= p.getAge() %></td>
					<td><%= p.getGender() %></td>
					<td><a href="detailView.jsp?name=<%= p.getName() %>" class="btn btn-secondary" role="button"> Detail &raquo;</a></td>
			<%
				}
			%>
			</table>
		</div>
		<hr>
	</div>
	
	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 
	
</body>
</html>