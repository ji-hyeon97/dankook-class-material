<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<jsp:useBean id="person" class="dto.Person" />
<jsp:setProperty name="person" property="name" param="userName" />
<jsp:setProperty name="person" property="age" param="userAge" />

<p>Name: <jsp:getProperty name="person" property="name" />
<p>Age: <%= person.getAge() %>

</body>
</html>