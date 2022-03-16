<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page isErrorPage="true"%>
<% response.setStatus(HttpServletResponse.SC_OK); %> <%-- 이것은 현재 페이지가 정상적으로 응답되는 페이지임을 지정하는 코드다. 이 코드를 생략하면 웹 브라우저는 자체적인 에러 페이지를 표시한다. --%>

<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>

<h1>Error!</h1>
<p>Exception : <%= exception %>
<p>toString() : <%= exception.toString() %>
<p>getClass().getName() : <%=exception.getClass().getName()%>
<p>getMessage() : <%=exception.getMessage()%>
	

</body>
</html>