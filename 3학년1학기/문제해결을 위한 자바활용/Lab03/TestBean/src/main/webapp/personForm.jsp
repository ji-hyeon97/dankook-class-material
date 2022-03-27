<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="dto.Gender"%>
<%@ page import="dto.Person"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Use JavaBean & Form Processing</title>
</head>
<body>
<script language="javascript">
function calculate() {
	var age = document.personForm.age.value;
	var height = document.personForm.height.value;
	var weight = document.personForm.weight.value;
	//var target = document.getElementById("activity");
	//var activity = target.options[target.selectedIndex].value;
    var activity = document.personForm.activity.value;
    
	// bmi
	var bmi = weight / (height * 0.01) / (height * 0.01);
    if (bmi >= 0.0 && bmi < 20.0) 
    	document.personForm.bmi.value = "UNDERWEIGHT";
	else if (bmi >= 20.0 && bmi < 24.0) 
		document.personForm.bmi.value = "NORMAL";
	else if (bmi >= 24.0 && bmi < 30.0) 
		document.personForm.bmi.value = "OVERWEIGHT";
	else 
		document.personForm.bmi.value = "OBESITY";		

    // ideal weight
	if (document.getElementById('MALE').checked)
		document.personForm.idealWeight.value = height * height * 22 * 0.0001;
	else if (document.getElementById('FEMALE').checked)
		document.personForm.idealWeight.value = height * height * 21 * 0.0001;

    // daily caclory intake
    var activityCalory = 1.0;
    if (activity == "LOW")
        activityCalory = 1.3;
    else if (activity == "MEDIUM")
        activityCalory = 1.5;
    else if (activity == "HIGH")
        activityCalory = 1.75;
	//alert("activity=" + activity + " activityCalory=" + activityCalory);
	
    if (document.getElementById('MALE').checked)
    	document.personForm.caloryIntake.value = 66.47 + (13.75 * weight) + (5.0 * height) - (6.76 * age) * activityCalory;
	else if (document.getElementById('FEMALE').checked)
		document.personForm.caloryIntake.value = 655.1 + (9.05 * weight) + (1.85 * height) - (4.68 * age) * activityCalory;
}
</script>


	<jsp:useBean id="person" class="dto.Person" scope="session" />
	<p>Name: <%= person.getName() %>
	<p>Age: <%= person.getAge() %>

<br>PersonProcess<br>
<form action="personProcess.jsp" method="post">
   Name: <input name="userName" property="" />
   Age: <input name="userAge" property="10" />
   <input type="submit" value="Submit"><br />
</form>
	<hr>
	<%
	person.setName("PARK");
	person.setAge(50);
	person.setGender(Gender.FEMALE);
	%>
	<p>Name: <%= person.getName() %></p>
	<p>Age: <%= person.getAge() %></p>
	</hr>
	
	<hr>
	<jsp:setProperty name="person" property="name" value="MORE TEST" />
	<jsp:setProperty name="person" property="age" value="22" />
	<p>Name: <jsp:getProperty name="person" property="name" /></p>
	<p>Age: <jsp:getProperty name="person" property="age" /></p>
	</hr>
	
	<hr>
	<form name="personForm">
		Name: <input type="text" name="name" size="10"><br />
		Age: <input type="text" name="age" size="10"><br />
		Gender: <input type="radio" id="MALE" name="gender" value="MALE" checked="checked">Male
				<input type="radio" id="FEMALE" name="gender" value="FEMALE">Female<br />
		Height(cm): <input type="text" name="height" size="10"><br />
		Weight(kg): <input type="text" name="weight" size="10"><br />
		Neck(cm): <input type="text" name="neck" size="10"><br />
		Waist(cm): <input type="text" name="waist" size="10"><br />
		Hip(cm): <input type="text" name="hip" size="10"><br />
		Activity: <select name="activity" id="activity">
				<option value="LOW">Low</option>
				<option value="MEDIUM">Medium</option>
				<option value="HIGH">High</option>
				</select>
				<br />
		<input type="button" value="Calculate" onClick="calculate()"><br />
		Your BMI: <input type="text" name="bmi" size="10"><br />
		Your Ideal Weight(kg): <input type="text" name="idealWeight" size="10"><br />
		Your Calory Intake(cal): <input type="text" name="caloryIntake" size="10"><br />
		<input type="reset" value="Reset" />
	</form>
<p></p>
<br></br>
<hr>
	<form name="personCalculator" action="personCalculator.jsp" method="post">
		Name: <input type="text" name="name" value="Park" size="10"><br />
		Age: <input type="text" name="age" value="25" size="10"><br />
		Gender: <input type="radio" id="MALE" name="gender" value="MALE" checked="checked">Male
				<input type="radio" id="FEMALE" name="gender" value="FEMALE">Female<br />
		Height(cm): <input type="text" name="height" value="180" size="10"><br />
		Weight(kg): <input type="text" name="weight" value="70" size="10"><br />
		Neck(cm): <input type="text" name="neck" value="40" size="10"><br />
		Waist(cm): <input type="text" name="waist" value="80" size="10"><br />
		Hip(cm): <input type="text" name="hip" value="90" size="10"><br />
		Activity: <select name="activity" id="activity">
				<option value="LOW">Low</option>
				<option value="MEDIUM">Medium</option>
				<option value="HIGH">High</option>
				</select>
				<br />
		<input type="submit" value="Submit"><br />
	</form>
</body>
</html>