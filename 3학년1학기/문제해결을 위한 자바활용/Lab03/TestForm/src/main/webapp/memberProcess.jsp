<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Enumeration" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("UTF-8");
	%>
    <p>아이디: <%= request.getParameter("id") %>
    <p>비밀번호: <%= request.getParameter("passwd") %>
    <p>이름: <%= request.getParameter("name") %>
    <p>연락처: <%= request.getParameter("phone1") %> - <%= request.getParameter("phone2") %> - <%= request.getParameter("phone3") %>
    <p>성별: <%= request.getParameter("gender") %>
    <p>취미: 
    	<%
			String[] hobby = request.getParameterValues("hobby");
			if (hobby != null) {
				for (int i = 0; i < hobby.length; i++) {
					out.println(" " + hobby[i]);
				}
			}
		%>	
	<p>가입인사: <%= request.getParameter("comment") %>                

	<table border="1">
		<tr>
			<th>요청 파라미터 이름</th>
			<th>요청 파라미터 값</th>
		</tr>
		<%
			request.setCharacterEncoding("UTF-8");		
			Enumeration<String> paramNames = request.getParameterNames();
			while (paramNames.hasMoreElements()) {
				String paramName = (String) paramNames.nextElement();
				out.print("<tr><td>" + paramName + " </td>\n");
				String paramValue = request.getParameter(paramName);
				out.println("<td> " + paramValue + "</td></tr>\n");
			}
		%>
	</table>
</body>
</html>