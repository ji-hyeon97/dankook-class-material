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
	String userName = (String)session.getAttribute("userName"); // get session attribute
	int userAge = (Integer)session.getAttribute("userAge"); // get session attribute
	
	if (userName.equals("Park") || userName.equals("KPark")){
		out.print(userName + "'s session page " + userAge);  
	} else {
		out.print("Wrong username.");  
	}
%>

</body>
</html>