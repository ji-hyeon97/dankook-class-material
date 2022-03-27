<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="dto.Gender"%>
<%@ page import="dto.Person"%>
<%@ page import="dao.PersonManager"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Person Calculator Table</title>
</head>
<body>
<%
	String name = request.getParameter("name");
	String ageStr = request.getParameter("age");
	String genderStr = request.getParameter("gender");
	String heightStr = request.getParameter("height");
	String weightStr = request.getParameter("weight");
	String neckStr = request.getParameter("neck");
	String waistStr = request.getParameter("waist");
	String hipStr = request.getParameter("hip");
	String activity = request.getParameter("activity");
	
	int age;
	if (ageStr.isEmpty())
		age = 0;
	else
		age = Integer.valueOf(ageStr);
	
	Gender gender;
	if (genderStr.isEmpty())
		gender = null;
	else
		gender = Gender.valueOf(genderStr);
	
	double height;
	if (heightStr.isEmpty())
		height = 0.0;
	else
		height = Double.valueOf(heightStr);

	double weight;
	if (weightStr.isEmpty())
		weight = 0.0;
	else
		weight = Double.valueOf(weightStr);

	double neck;
	if (neckStr.isEmpty())
		neck = 0.0;
	else
		neck = Double.valueOf(neckStr);

	double waist;
	if (waistStr.isEmpty())
		waist = 0.0;
	else
		waist = Double.valueOf(waistStr);
	
	double hip;
	if (hipStr.isEmpty())
		hip = 0.0;
	else
		hip = Double.valueOf(hipStr);

	Person person = new Person();
	person.setName(name);
	person.setAge(age);
	person.setGender(gender);
	person.setHeight(height);
	person.setWeight(weight);
	person.setNeck(neck);
	person.setWaist(waist);
	person.setHip(hip);
	//out.println("<br>" + person + " ");
	//out.println("Activity: " + activity + "<br>");
%>
<%
	PersonManager manager = PersonManager.getInstance();
	manager.add(person);
%>
	<div>
		<h1>BMI Calculator Table</h1>
	</div>
<hr>
	<div style="padding-top: 10px">
		<table>
			<tr>
				<th>Name</th>
				<th>Age</th>
				<th>Gender</th>
				<th>Height</th>
				<th>Weight</th>
				<th>Neck</th>
				<th>Waist</th>
				<th>Hip</th>
			</tr>	
			<%
			for (Person p : manager.getList()) {
				out.print(String.format(
						"<tr>" +
							"<td>%s</td>" +
							"<td>%d</td>" +
							"<td>%s</td>" +
							"<td>%.1f</td>" +
							"<td>%.1f</td>" +
							"<td>%.1f</td>" +
							"<td>%.1f</td>" +
							"<td>%.1f</td>" +
						"</tr>",	
						p.getName(), p.getAge(), p.getGender(),
						p.getHeight(), p.getWeight(), p.getNeck(),
						p.getWaist(), p.getHip()
						));
				}
			%>
		</table>
	</div>
<hr>
</body>
</html>   
