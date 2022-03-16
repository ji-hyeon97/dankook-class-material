<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%
	out.print("servletName: " + config.getServletName() + "<br>");
	String website = config.getInitParameter("courseBlog"); 
	out.print("Course Blog: " + website);
%>
</body>
</html>