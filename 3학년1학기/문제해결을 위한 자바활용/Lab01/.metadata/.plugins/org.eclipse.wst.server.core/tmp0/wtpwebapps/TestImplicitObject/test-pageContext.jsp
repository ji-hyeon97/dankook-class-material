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
String name = (String)pageContext.getAttribute("name", PageContext.SESSION_SCOPE); 
out.print("Name: " + name);   
int age = (int)pageContext.getAttribute("age", PageContext.SESSION_SCOPE); 
out.print("Age: " + age);   
%>

</body>
</html>