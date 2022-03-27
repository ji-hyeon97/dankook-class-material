<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="java.util.List" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>식품 영양 성분</title>
</head>
<body>
	<%@ include file="declaration.jsp" %>
	<%@ include file = "list.jsp" %>
	<jsp:include page="header.jsp" />

	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3">식품 영양 성분</h1>
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
					<th>개별종목정보</th>
				</tr>
			<%
				List<foodNutrientFacts> pList = manager.get(); // getlist
				for (foodNutrientFacts p : pList) {
			%>
					<tr>
					<td><%= p.getFoodCode()%></td>
					<td><%= p.getFoodName()%></td>
					<td><%= p.getFoodCategory()%></td>
					<td><%= p.getKcal()%></td>
					<td><%= p.getMoisture()%></td>
					<td><%= p.getProtein()%></td>
					<td><%= p.getFat()%></td>
					<td><%= p.getCarbohydrate()%></td>
					<td><%= p.getCalcium()%></td>
					<td><%= p.getMagnesium()%></td>
					<td><%= p.getVitaminB1()%></td>
					<td><%= p.getCholesterol()%></td>
					<td><a href="detailview.jsp?name=<%= p.getFoodCode()%>" class="btn btn-secondary" role="button"> Detail &raquo;</a></td>
					<%--get 방식으로 parameter을 넘길 수 있다. --%>
			<%
				}
			%>
			</table>
		</div>
		<hr>
	</div>
	
	
	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming for Problem Solving"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 
	
</body>
</html>