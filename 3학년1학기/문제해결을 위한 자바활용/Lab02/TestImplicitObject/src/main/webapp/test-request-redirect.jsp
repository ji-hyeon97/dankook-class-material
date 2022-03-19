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
	String userName = (String) request.getAttribute("userName"); // get request attribute
	out.print("Welcome userName is " + userName + "<br>");
	int userAge = (Integer) request.getAttribute("userAge"); // get request attribute
	out.print("Welcome userAge is " + userAge + "<br>");
%>
</body>
</html>