<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import = "java.io.*,java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>HTTP Header Request Example</title>
</head>
<body>

<form action="test-request-result.jsp" method="post">
	Name: <input type="text" name="userName" /><br>
	Age: <input type="text" name="userAge" /><br>
	<input type="submit" value="login"/>
</form>

<h2>HTTP Header Request Example</h2>
         
<table width = "100%" border = "1" align = "center">
	<tr bgcolor = "#949494">
    <th>Header Name</th>
	<th>Header Value(s)</th>
	</tr>
	<%
		Enumeration headerNames = request.getHeaderNames();
		while(headerNames.hasMoreElements()) {
			String paramName = (String)headerNames.nextElement();
			out.print("<tr><td>" + paramName + "</td>\n");
			String paramValue = request.getHeader(paramName);
			out.println("<td> " + paramValue + "</td></tr>\n");
		}
	%>
</table>
         
</body>
</html>