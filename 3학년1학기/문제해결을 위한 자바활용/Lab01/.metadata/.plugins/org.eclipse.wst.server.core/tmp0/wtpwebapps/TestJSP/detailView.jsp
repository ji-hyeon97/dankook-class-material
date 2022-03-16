<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>

<%@ include file = "declaration.jsp" %>
<%
	String name = request.getParameter("name");
	Person person = manager.get(name);
%>


	<jsp:include page="header.jsp" />
	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3"><%= name %> Information</h1>
		</div>
	</div>

	<div class="container">
		<div class="row">
			<div class="col-md-6">
				<h3> <%= person.getName() %> </h3>
				<h4><%= person.getAge() %> </h4>
				<h4><%= person.getGender() %> </h4>
			</div>
		</div>
	</div>

	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 

</body>
</html>