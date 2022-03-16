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
	
	if(userName.equals("Park") || userName.equals("KPark")) {
		request.setAttribute("userName", userName); // set request attribute
		request.setAttribute("userAge", userAge); // set request attribute
		pageContext.forward("test-request-redirect.jsp");
		//response.sendRedirect("test-request-redirect.jsp");  
	} else {
		out.print("userName is not Park.");  
	}
%>
</body>
</html>