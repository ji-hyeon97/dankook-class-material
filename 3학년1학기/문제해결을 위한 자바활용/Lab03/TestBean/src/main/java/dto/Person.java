package dto;

public class Person implements java.io.Serializable {
    protected String name;
    protected int age;
    protected Gender gender;
    protected double height;
    protected double weight;
    protected double neck;
    protected double waist;
    protected double hip;
    
    public Person() { 
    	this("", 0, null, 0.0, 0.0); 
	}

    public Person(String name, int age, Gender gender, double height, double weight) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.height = height;
        this.weight = weight;
    }

    public Person(String name, int age, Gender gender, double height, double weight, double neck, double waist, double hip) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.height = height;
        this.weight = weight;
        this.neck = neck;
        this.waist = waist;
        this.hip = hip;
    }

    public void setName(String name) { 
		this.name = name; 
	}
    
	public void setAge(int age) { 
		this.age = age; 
	}
    
	public void setGender(Gender gender) { 
		this.gender = gender; 
	}
    
	public void setHeight(double height) {
		this.height = height;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}

	public void setNeck(double neck) {
		this.neck = neck;
	}

	public void setWaist(double waist) {
		this.waist = waist;
	}

	public void setHip(double hip) {
		this.hip = hip;
	}

	public String getName() { 
		return name; 
	}

    public int getAge() { 
		return age; 
	}

    public Gender getGender() { 
		return gender; 
	}

    public double getHeight() {
		return height;
	}

	public double getWeight() {
		return weight;
	}

	public double getNeck() {
		return neck;
	}

	public double getWaist() {
		return waist;
	}

	public double getHip() {
		return hip;
	}

    public void print() { 
		System.out.println(this); 
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + ", gender=" + gender + ", height=" + height + ", weight="
				+ weight + ", neck=" + neck + ", waist=" + waist + ", hip=" + hip + "]";
	}

}
