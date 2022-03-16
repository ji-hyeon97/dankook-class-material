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
	String userName = request.getParameter("userName");
	out.print("Welcome " + userName + "<br>");
	int userAge = Integer.parseInt(request.getParameter("userAge"));
	out.print("Welcome " + userAge + "<br>");
	
	if (userName.equals("Park") || userName.equals("KPark")) {
		session.setAttribute("userName", userName); // set session attribute
		session.setAttribute("userAge", userAge); // set session attribute
		response.sendRedirect("test-session-redirect.jsp");  
	} else {
		out.print("Wrong username.");  
	}
%>
</body>
</html>