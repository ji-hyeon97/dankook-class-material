<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>식품 영양 성분</title>
</head>
<body>

<%
	String course = request.getParameter("course");
	int year = Integer.parseInt(request.getParameter("year"));
%>
<nav class="navbar navbar-expand navbar-dark bg-dark">
	<div class="container">
		<h4 class="btn btn-secondary">Copyright <%= year %> <%= course %> (<%= new java.util.Date() %>)</h4>
	</div>
</nav>


</body>
</html>