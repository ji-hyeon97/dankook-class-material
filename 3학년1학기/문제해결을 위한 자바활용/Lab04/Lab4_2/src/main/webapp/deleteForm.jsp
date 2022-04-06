<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>구매 테이블</title>
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
</head>
<body>
	<jsp:include page="header.jsp" />

	<div class="jumbotron">
		<div class="container">
			<h3 class="display-3">제품 데이터삭제</h3>
			</div></div>

 
<form action="deleteProcess.jsp" name="member" method="post">
<div class="container">  
    <div class="form-group">
      <label>번호</label>
      <input type="text" class="form-control" name = "num"/>
    </div>   
    
    <button type="submit" class="btn btn-primary" onclick="msg()">전송</button>
 </div> </form>  
</body>
<script>

function msg(){
	alert("데이터 삭제 요청 하셨습니다");
}
</script>
</html>