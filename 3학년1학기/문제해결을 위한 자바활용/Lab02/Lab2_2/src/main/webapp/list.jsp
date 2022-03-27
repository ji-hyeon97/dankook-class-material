<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>2022년 1학기 시간표</title>
</head>
<body>
    <%@ include file="beautiful.jsp" %>
	<%@ include file="declaration.jsp" %>
	<jsp:include page="header.jsp" />


	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3">2022년 1학기 시간표</h1>
			<img src="images/dku.png" style="width:100px; height:100px"/>
		</div>
	</div>
	
	<div class="container">
		<div style="padding-top: 10px">
			 <table cellspacing="5" align="center" border="1" bordercolor="#5CD1E5" width="550" height="600"> 
        <p></p> 
        <caption> 
          <font size="5" face="굴림">
            <font color="#fece00">Ti</font><font color="#fe8c14">me </font>
            <font color="#8cca2d">Ta</font><font color="#4daace">ble</font> 
          </font> 
        </caption> 
        <tr align="center"> 
          <td width="50"></td> 
          <td width="100" bgcolor="#7cd2f5">월</td>
          <td width="100" bgcolor="#7cd2f5">화</td>
          <td width="100" bgcolor="#7cd2f5">수</td>
          <td width="100" bgcolor="#7cd2f5">목</td>
          <td width="100" bgcolor="#7cd2f5">금</td>
        </tr> 
        
			
        <tr align="center">
          <td bgcolor="#7cd2f5">09:00~09:30</td> 
          <td bgcolor="#FF3C3C"><a href="singleView.jsp?name=운영체제">운영체제</a></td>       
           <td></td>
           <td bgcolor="#FF913C"><a href="singleView.jsp?name=문제해결을위한자바활용">문제해결을위한자바활용</a></td>
           <td bgcolor="#FFD93C"><a href="singleView.jsp?name=컴퓨터구조및모바일프로세서">컴퓨터구조및모바일프로세서</a></td>
           <td bgcolor="#FF44C1"><a href="singleView.jsp?name=창의적사고와코딩">창의적사고와코딩</a></td>
          </tr>
          
           <tr align="center">
          <td bgcolor="#7cd2f5">09:30~10:00</td> 
          <td bgcolor="#FF3C3C"><a href="singleView.jsp?name=운영체제">운영체제</a></td>       
           <td></td>
           <td bgcolor="#FF913C"><a href="singleView.jsp?name=문제해결을위한자바활용">문제해결을위한자바활용</a></td>
           <td bgcolor="#FFD93C"><a href="singleView.jsp?name=컴퓨터구조및모바일프로세서">컴퓨터구조및모바일프로세서</a></td>
           <td bgcolor="#FF44C1"><a href="singleView.jsp?name=창의적사고와코딩">창의적사고와코딩</a></td>
          </tr>
          
          <tr align="center">
          <td bgcolor="#7cd2f5">10:00~10:30</td> 
          <td bgcolor="#FF3C3C"><a href="singleView.jsp?name=운영체제">운영체제</a></td>       
           <td></td>
           <td bgcolor="#FF913C"><a href="singleView.jsp?name=문제해결을위한자바활용">문제해결을위한자바활용</a></td>
           <td bgcolor="#FFD93C"><a href="singleView.jsp?name=컴퓨터구조및모바일프로세서">컴퓨터구조및모바일프로세서</a></td>
           <td bgcolor="#FF44C1"><a href="singleView.jsp?name=창의적사고와코딩">창의적사고와코딩</a></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">10:30~11:00</td>
            <td bgcolor="#FFD93C"><a href="singleView.jsp?name=컴퓨터구조및모바일프로세서">컴퓨터구조및모바일프로세서</a></td>
            <td bgcolor="#FF3C3C"><a href="singleView.jsp?name=운영체제">운영체제</a></td>
            <td bgcolor="#FF913C"><a href="singleView.jsp?name=문제해결을위한자바활용">문제해결을위한자바활용</a></td>
            <td bgcolor="#3CFF49"><a href="singleView.jsp?name=고급모바일실험1">고급모바일실험1</a></td>
            <td bgcolor="#FF44C1"><a href="singleView.jsp?name=창의적사고와코딩">창의적사고와코딩</a></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">11:00~11:30</td>
            <td bgcolor="#FFD93C"><a href="singleView.jsp?name=컴퓨터구조및모바일프로세서">컴퓨터구조및모바일프로세서</a></td>
            <td bgcolor="#FF3C3C"><a href="singleView.jsp?name=운영체제">운영체제</a></td>
            <td bgcolor="#FF913C"><a href="singleView.jsp?name=문제해결을위한자바활용">문제해결을위한자바활용</a></td>
            <td bgcolor="#3CFF49"><a href="singleView.jsp?name=고급모바일실험1">고급모바일실험1</a></td>
            <td></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">11:30~12:00</td>
            <td bgcolor="#FFD93C"><a href="singleView.jsp?name=컴퓨터구조및모바일프로세서">컴퓨터구조및모바일프로세서</a></td>
            <td bgcolor="#FF3C3C"><a href="singleView.jsp?name=운영체제">운영체제</a></td>
            <td bgcolor="#FF913C"><a href="singleView.jsp?name=문제해결을위한자바활용">문제해결을위한자바활용</a></td>
            <td bgcolor="#3CFF49"><a href="singleView.jsp?name=고급모바일실험1">고급모바일실험1</a></td>
            <td></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">12:00~12:30</td>
            <td bgcolor="#B1FF3C"><a href="singleView.jsp?name=알고리즘및인공지능">알고리즘및인공지능</a></td>
            <td></td>
            <td></td>
            <td bgcolor="#3CFF49"><a href="singleView.jsp?name=고급모바일실험1">고급모바일실험1</a></td>
            <td></td>
          </tr> 
          
          <tr align="center">
            <td bgcolor="#7cd2f5">12:30~13:00</td>
            <td bgcolor="#B1FF3C"><a href="singleView.jsp?name=알고리즘및인공지능">알고리즘및인공지능</a></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">13:00~13:30</td>
            <td bgcolor="#B1FF3C"><a href="singleView.jsp?name=알고리즘및인공지능">알고리즘및인공지능</a></td>
            <td></td>
            <td></td>
            <td></td>         
            <td></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">13:30~14:00</td>
            <td bgcolor="#44FFE1"><a href="singleView.jsp?name=클라우드컴퓨팅">클라우드컴퓨팅</a></td>
            <td></td>
            <td></td>
            <td bgcolor="#44FFE1"><a href="singleView.jsp?name=클라우드컴퓨팅">클라우드컴퓨팅</a></td>         
            <td></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">14:00~14:30</td>
            <td bgcolor="#44FFE1"><a href="singleView.jsp?name=클라우드컴퓨팅">클라우드컴퓨팅</a></td>
            <td></td>
            <td bgcolor="#D23CFF"><a href="singleView.jsp?name=취창업진로세미나1">취창업진로세미나1</a></td>
            <td bgcolor="#44FFE1"><a href="singleView.jsp?name=클라우드컴퓨팅">클라우드컴퓨팅</a></td>
            <td></td>
          </tr> 
          
          <tr align="center">
            <td bgcolor="#7cd2f5">14:30~15:00</td>
            <td bgcolor="#44FFE1"><a href="singleView.jsp?name=클라우드컴퓨팅">클라우드컴퓨팅</a></td>
            <td></td>
            <td bgcolor="#D23CFF"><a href="singleView.jsp?name=취창업진로세미나1">취창업진로세미나1</a></td>
            <td bgcolor="#44FFE1"><a href="singleView.jsp?name=클라우드컴퓨팅">클라우드컴퓨팅</a></td>
            <td></td>
          </tr> 
          
          <tr align="center">
            <td bgcolor="#7cd2f5">15:00~15:30</td>
            <td></td>
            <td bgcolor="#448FFF"><a href="singleView.jsp?name=데이터베이스">데이터베이스</a></td>
            <td bgcolor="#D23CFF"><a href="singleView.jsp?name=취창업진로세미나1">취창업진로세미나1</a></td>
            <td bgcolor="#448FFF"><a href="singleView.jsp?name=데이터베이스">데이터베이스</a></td>
            <td bgcolor="#B1FF3C"><a href="singleView.jsp?name=알고리즘및인공지능">알고리즘및인공지능</a></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">15:30~16:00</td>
            <td></td>
            <td bgcolor="#448FFF"><a href="singleView.jsp?name=데이터베이스">데이터베이스</a></td>
            <td bgcolor="#D23CFF"><a href="singleView.jsp?name=취창업진로세미나1">취창업진로세미나1</a></td>
            <td bgcolor="#448FFF"><a href="singleView.jsp?name=데이터베이스">데이터베이스</a></td>
            <td bgcolor="#B1FF3C"><a href="singleView.jsp?name=알고리즘및인공지능">알고리즘및인공지능</a></td>
          </tr>
          
          <tr align="center">
            <td bgcolor="#7cd2f5">16:00~16:30</td>
            <td></td>
            <td bgcolor="#448FFF"><a href="singleView.jsp?name=데이터베이스">데이터베이스</a></td>
            <td></td>
            <td bgcolor="#448FFF"><a href="singleView.jsp?name=데이터베이스">데이터베이스</a></td>
            <td bgcolor="#B1FF3C"><a href="singleView.jsp?name=알고리즘및인공지능">알고리즘및인공지능</a></td>
          </tr>
          
           <tr align="center">       
            <td bgcolor="#7cd2f5">16:30~17:00</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
      </tr>
      <tr align="center">
            <td bgcolor="#7cd2f5">17:00~17:30</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
      </tr>
      
      <tr align="center">
            <td bgcolor="#7cd2f5">17:30~18:00</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
      </tr>
    </table>
		</div>
		<hr>
	</div>
	<a href="detailView.jsp" class="btn btn-secondary" role="button">모든수업 한번에 알아보기&raquo;</a>
	
	<jsp:include page="footer.jsp">
		<jsp:param name="course" value="Advanced Java Programming for Problem Solving"/>
		<jsp:param name="year" value="2022"/>
	</jsp:include> 
	
</body>
</html>