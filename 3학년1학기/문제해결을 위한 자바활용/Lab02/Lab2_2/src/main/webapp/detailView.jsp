<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.List" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>2022년 1학기 시간표</title>
</head>
<body>

<%@ include file = "declaration.jsp" %>
<%@ include file = "beautiful.jsp" %>

	<jsp:include page="header.jsp" />
	<div class="jumbotron">
		<div class="container">
		</div>
	</div>
	
	<div class="container">
		<div style="padding-top: 50px">
			<table class="table table-hover">
				<tr class="background1">
					<th>과목</th>
					<th>교수님</th>
					<th>학점</th>
					<th>수업장소</th>
					<th>수업시간</th>
					<th>단일페이지이동</th>
				</tr>
			<%
			List<lecture> pList = manager.get(); // getlist
			for (lecture lec : pList) {
			%>
				<tr>	
				<td><%= lec.getName() %> </td>
				<td><%= lec.getProfessor() %> </td>
				<td><%= lec.getCredits() %> </td>
				<td><%= lec.getLocation() %> </td>
				<td><%= lec.getTime() %> </td>
				<td><a href="singleView.jsp?name=<%= lec.getName()%>" class="btn btn-secondary" role="button"> Detail &raquo;</a></td>
			<%
				}
			%>
			</table>
		</div>
		<hr>
	</div>
	
	
	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming for Problem Solving"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 
	
</body>
</html>