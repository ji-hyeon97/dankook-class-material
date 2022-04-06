<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>식품 영양 성분</title>
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
</head>
<body>
	<jsp:include page="header.jsp" />

	<div class="jumbotron">
		<div class="container">
			<h1 class="display-3">식품 영양 성분</h1>
			</div></div>

 
<form action="addProcess.jsp" name="member" method="post">
<div class="container">  
    <div class="form-group">
      <label>sampled_id</label>
      <input type="text" class="form-control" name = "sample_id"/>
    </div>
    
    <div class="form-group">
      <label>name</label>
      <input type="text" class="form-control" name = "name"/>
    </div>
    
    <div class="form-group">
      <label>category</label>
      <input type="text" class="form-control" name = "category"/>
    </div>
    
    <div class="form-group">
      <label>serving_size</label>
      <input type="text" class="form-control" name = "serving_size"/>
    </div>    
    
    <div class="form-group">
    <label>calorie</label>
    <input type="text" class="form-control" name="calorie"/>
    </div>
    
    <div class="form-group">
    <label>water</label>
    <input type="text" class="form-control" name="water"/>
    </div>
    
    <div class="form-group">
    <label>protein</label>
    <input type="text" class="form-control" name="protein"/>
    </div>
    
    <div class="form-group">
    <label>fat</label>
    <input type="text" class="form-control" name="fat"/>
    </div>
    
    <div class="form-group">
    <label>carbohydrate</label>
    <input type="text" class="form-control" name="carbohydrate"/>
    </div>
    
    <div class="form-group">
    <label>sugars</label>
    <input type="text" class="form-control" name="sugars"/>
    </div>
    
    <div class="form-group">
    <label>fiber</label>
    <input type="text" class="form-control" name="fiber"/>
    </div>
    
    <div class="form-group">
    <label>calcium</label>
    <input type="text" class="form-control" name="calcium"/>
    </div>
    
    <div class="form-group">
    <label>iron</label>
    <input type="text" class="form-control" name="iron"/>
    </div>
    
    <div class="form-group">
    <label>magnesium</label>
    <input type="text" class="form-control" name="magnesium"/>
    </div>
    
    <div class="form-group">
    <label>phosphorus</label>
    <input type="text" class="form-control" name="phosphorus"/>
    </div>
    
    <div class="form-group">
    <label>potassium</label>
    <input type="text" class="form-control" name="potassium"/>
    </div>
    
    <div class="form-group">
    <label>sodium</label>
    <input type="text" class="form-control" name="sodium"/>
    </div>
    
    <div class="form-group">
    <label>zinc</label>
    <input type="text" class="form-control" name="zinc"/>
    </div>
    
    <div class="form-group">
    <label>copper</label>
    <input type="text" class="form-control" name="copper"/>
    </div>
    
    <div class="form-group">
    <label>manganese</label>
    <input type="text" class="form-control" name="manganese"/>
    </div>
    
    <div class="form-group">
    <label>selenium</label>
    <input type="text" class="form-control" name="selenium"/>
    </div>    
    
    <button type="submit" class="btn btn-primary" onclick="msg()">전송</button>
 </div> </form>  
</body>
<script>

function msg(){
	alert("식품정보가 전송 되었습니다!");
}
</script>
</html>