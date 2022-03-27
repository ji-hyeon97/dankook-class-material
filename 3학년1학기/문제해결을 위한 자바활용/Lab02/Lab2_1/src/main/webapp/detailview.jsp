<<<<<<< HEAD
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>식품 영양 성분</title>
</head>
<body>

<%@ include file = "declaration.jsp" %>
<%@ include file = "list.jsp" %>
<%
	String name = request.getParameter("name");
    foodNutrientFacts foodnutrientfacts = manager.get(name);
%>


	<jsp:include page="header.jsp" />
	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3"><%= foodnutrientfacts.getFoodName()%> 정보</h1>
		</div>
	</div>
	
	<div class="container">
		<div style="padding-top: 50px">
			<table class="table table-hover">
				<tr class="background1">
					<th>식품코드</th>
					<th>식품명</th>
					<th>식품상세분류</th>
					<th>에너지(㎉)</th>
					<th>수분(g)</th>
					<th>단백질(g)</th>
					<th>지방(g)</th>
					<th>탄수화물(g)</th>
					<th>칼슘(㎎)</th>
					<th>마그네슘(㎎)</th>
					<th>비타민 B1(㎎)</th>
					<th>콜레스테롤(㎎)</th>
				</tr>
				
				<tr>	
				<td><%= foodnutrientfacts.getFoodCode() %> </td>
				<td><%= foodnutrientfacts.getFoodName() %> </td>
				<td><%= foodnutrientfacts.getFoodCategory() %> </td>
				<td><%= foodnutrientfacts.getKcal() %> </td>
				<td><%= foodnutrientfacts.getMoisture() %> </td>
				<td><%= foodnutrientfacts.getProtein() %> </td>
				<td><%= foodnutrientfacts.getFat() %> </td>
				<td><%= foodnutrientfacts.getCarbohydrate() %> </td>
				<td><%= foodnutrientfacts.getCalcium() %> </td>
				<td><%= foodnutrientfacts.getMagnesium() %> </td>
				<td><%= foodnutrientfacts.getVitaminB1() %> </td>
				<td><%= foodnutrientfacts.getCholesterol() %> </td>
				</tr>
				</table>
			</div>
		</div>
		
	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 

</body>
</html>
=======
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>식품 영양 성분</title>
</head>
<body>

<%@ include file = "declaration.jsp" %>
<%@ include file = "list.jsp" %>
<%
	String name = request.getParameter("name");
    foodNutrientFacts foodnutrientfacts = manager.get(name);
%>


	<jsp:include page="header.jsp" />
	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3"><%= foodnutrientfacts.getFoodName()%> 정보</h1>
		</div>
	</div>
	
	<div class="container">
		<div style="padding-top: 50px">
			<table class="table table-hover">
				<tr class="background1">
					<th>식품코드</th>
					<th>식품명</th>
					<th>식품상세분류</th>
					<th>에너지(㎉)</th>
					<th>수분(g)</th>
					<th>단백질(g)</th>
					<th>지방(g)</th>
					<th>탄수화물(g)</th>
					<th>칼슘(㎎)</th>
					<th>마그네슘(㎎)</th>
					<th>비타민 B1(㎎)</th>
					<th>콜레스테롤(㎎)</th>
				</tr>
				
				<tr>	
				<td><%= foodnutrientfacts.getFoodCode() %> </td>
				<td><%= foodnutrientfacts.getFoodName() %> </td>
				<td><%= foodnutrientfacts.getFoodCategory() %> </td>
				<td><%= foodnutrientfacts.getKcal() %> </td>
				<td><%= foodnutrientfacts.getMoisture() %> </td>
				<td><%= foodnutrientfacts.getProtein() %> </td>
				<td><%= foodnutrientfacts.getFat() %> </td>
				<td><%= foodnutrientfacts.getCarbohydrate() %> </td>
				<td><%= foodnutrientfacts.getCalcium() %> </td>
				<td><%= foodnutrientfacts.getMagnesium() %> </td>
				<td><%= foodnutrientfacts.getVitaminB1() %> </td>
				<td><%= foodnutrientfacts.getCholesterol() %> </td>
				</tr>
				</table>
			</div>
		</div>
		
	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 

</body>
</html>
>>>>>>> 6f526871052167d9510e765dcf88395334345a0f
