<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>

<p><a href="test-request.jsp">Click here to see request</a></p> 

<p><a href="test-response.jsp">Click here to see response</a></p>  

<p><a href="test-out.jsp">Click here to see out</a></p>  

<p><a href="test-session.jsp">Click here to see session</a></p> 

<p><a href="test-config-result.jsp">Click here to see config</a></p>

<p><a href="test-application-result.jsp">Click here to see application</a></p>

<%   
String name = "AJ22";  
int age = 2022;
pageContext.setAttribute("name", name, PageContext.SESSION_SCOPE);
pageContext.setAttribute("age", age, PageContext.SESSION_SCOPE);
%> 
<p><a href="test-pageContext.jsp">Click to see pageContext</a></p>

<p><a href="test-exception.jsp">Click here to see exception</a></p>

</body>
</html>