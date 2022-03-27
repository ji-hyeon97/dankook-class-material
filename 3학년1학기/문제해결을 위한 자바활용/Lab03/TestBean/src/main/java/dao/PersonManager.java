package dao;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import dto.Gender;
import dto.Person;

public class PersonManager {
	private List<Person> data = null;

	private static PersonManager instance = new PersonManager();
	public static PersonManager getInstance(){
		return instance;
	}
	
	public PersonManager() {
		this.data = new ArrayList<Person>();
	}
	
	// get
	public Person get(int index){
		return this.data.get(index);
	}
	
	// getList
	public List<Person> getList() {
		return this.data;
	}

	// add 
	public void add(Person person) {
		this.data.add(person);
	}
	
	// addList
	public void addList(List<Person> list) {
		this.data = list;
	}
	
	// insert
	void insert(int index, Person data){
		this.data.add(index, data);
	}	

	// remove 
	public void remove(Person other) {
		Iterator<Person> it = this.data.iterator();
		while (it.hasNext()) {
		    Person p = it.next();
		    if (p == other) {
				it.remove();
		    }
		}
	}
	
	// remove all 
	public void removeAll() {
		this.data.clear();
	}
	
	// get (by name)
	public Person find(String name) {
		Person person = null;
		for (Person p : this.data) {
			if (p != null && p.getName().equals(name)) {
				person = p;
				break;
			}
		}
		return person;
	}

	// replace
	public void replace(String name, Person other) {
		int index = this.data.indexOf(find(name));
		this.data.set(index, other);
	}

}
