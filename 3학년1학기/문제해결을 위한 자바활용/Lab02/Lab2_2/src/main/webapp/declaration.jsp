<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>나만의 웹사이트 만들기</title>
</head>
<body>

<%!
public class lecture{
	private String name;
	private String professor;
	private String credits;
	private String location;
	private String time;
	
	public lecture(String name, String professor, String credits, String location, String time){		
		this.name = name;
		this.professor = professor;
		this.credits = credits;
		this.location = location;
		this.time = time;
	}
	
	public String getName(){
		return this.name;
	}
	
	public String getProfessor(){
		return this.professor;
	}
	
	public String getCredits(){
		return this.credits;
	}
	
	public String getLocation(){
		return this.location;
	}
	
	public String getTime(){
		return this.time;
	}
	
	@Override
	public String toString(){
		return "lecture [name= "+name+", professor= "+professor+", credits="+credits+
				", location= "+location+", time= "+time+"]";
				}
}

public class lectureManager{
	private List<lecture> list = new ArrayList<>();
	
	public lectureManager(){
		list.add(new lecture("운영체제", "김승훈교수님", "3학점", "2공524", "월 9:00~10:30, 화 10:30~12:00"));
		list.add(new lecture("컴퓨터구조및모바일프로세서", "유시환교수님", "3학점", "국제205_pc", "월 10:30~12:00, 목 9:00~10:30"));
		list.add(new lecture("알고리즘및인공지능", "김태윤교수님", "3학점", "줌강의", "월 12:00~13:30, 금 15:00~16:30"));
		list.add(new lecture("클라우드컴퓨팅", "유시환교수님", "3학점", "국제210", "월 13:30~15:00, 목 13:30~15:00"));
		list.add(new lecture("데이터베이스", "박지환교수님", "3학점", "국제210", "화 15:00~16:30, 목 15:00~16:30"));
		list.add(new lecture("문제해결을위한자바활용", "박경신교수님", "3학점", "2공420", "수 9:00~12:00"));
		list.add(new lecture("취창업진로세미나1", "정영기교수님", "2학점", "줌강의", "수 14:00~16:00")); 
		list.add(new lecture("고급모바일실험1", "유시환교수님", "1학점", "국제210", "목 10:30~12:30"));
		list.add(new lecture("창의적사고와코딩", "박소현교수님", "2학점", "소프트306", "금 9:00~11:00"));
	}
	
	public List<lecture> get(){
		return list;
	}
	
	public lecture get(String name){
		lecture lec = null;
		for(lecture l : list){
			if( l !=null && l.getName().equals(name)){
				lec = l;
				break;
			}
		}
		return lec;		
	}
}
lectureManager manager = new lectureManager();
%>
</body>
</html>