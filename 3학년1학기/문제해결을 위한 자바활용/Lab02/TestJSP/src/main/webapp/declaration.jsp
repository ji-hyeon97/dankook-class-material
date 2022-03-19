<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>

<%!
public enum Gender {
	FEMALE, MALE
}

public class Person {
	private String name;
	private int age;
	private Gender gender;
	
	public Person(String name, int age, Gender gender) {
		this.name = name;
		this.age = age;
		this.gender = gender;
	}
	
	public String getName() {
		return this.name;
	}
	
	public int getAge() {
		return this.age;
	}
	
	public Gender getGender() {
		return this.gender;
	}
	
	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + ", gender=" + gender + "]";
	}
}

public class PersonManager {
	private List<Person> list = new ArrayList<>();
	
	public PersonManager() {
		list.add(new Person("Dooly", 100, Gender.MALE));
		list.add(new Person("Heedong", 3, Gender.MALE));
		list.add(new Person("Douner", 1000, Gender.FEMALE));
		list.add(new Person("Ddochi", 30, Gender.FEMALE));
		list.add(new Person("Michol", 20, Gender.MALE));
	}
	
	public List<Person> get() {
		return list;
	}
	
	// get (by name)
	public Person get(String name) {
		Person person = null;
		for (Person p : list) {
			if (p != null && p.getName().equals(name)) {
				person = p;
				break;
			}
		}
		return person;
	}

}

PersonManager manager = new PersonManager();
%>
</body>
</html>