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
			<h3 class="display-3">제품 수정하기</h3>
			</div></div>

 
<form action="editProcess.jsp" name="member" method="post">
<div class="container">  
    <div class="form-group">
      <label>번호</label>
      <input type="text" class="form-control" name = "num"/>
    </div>
    
    <div class="form-group">
      <label>제품</label>
      <input type="text" class="form-control" name = "prod_name"/>
    </div>
    
    <div class="form-group">
      <label>제품분류</label>
      <input type="text" class="form-control" name = "group_name"/>
    </div>
    
    <div class="form-group">
      <label>가격</label>
      <input type="text" class="form-control" name = "price"/>
    </div>    
    
    <div class="form-group">
    <label>수량</label>
    <input type="text" class="form-control" name="amount"/>
    </div>  
    
    <button type="submit" class="btn btn-primary" onclick="msg()">전송</button>
 </div> </form>  
</body>
<script>

function msg(){
	alert("제품 정보가 전송되었습니다!");
}
</script>
</html>