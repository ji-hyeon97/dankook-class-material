package dto;

public class FoodBean{
	private String sample_id;
	private String name;
	private String category;
	private int serving_size;
	private double calorie;
	private double water;
	private double protein;
	private double fat;
	private double carbohydrate;
	private double sugars;
	private double fiber;
	private int calcium;
	private double iron;
	private int magnesium;
	private int phosphorus;
	private int potassium;
	private int sodium;
	private double zinc;
	private double copper;
	private double  manganese;
	private double  selenium;
	
	public FoodBean() {}
	
	public FoodBean(String sample_id, String name, String category, int serving_size,
			double calorie, double water, double protein, double fat, double carbohydrate,
			double sugars, double fiber, int calcium, double iron,int magnesium,
			int phosphorus, int potassium, int sodium, double zinc, double copper, double manganese,
			double selenium) {
		this.sample_id = sample_id;
		this.name = name;
		this.category = category;
		this.serving_size = serving_size;
		this.calorie = calorie;
		this.water = water;
		this.protein = protein;
		this.fat = fat;
		this.carbohydrate = carbohydrate;
		this.sugars = sugars;
		this.fiber = fiber;
		this.calcium = calcium;
		this.iron = iron;
		this.magnesium = magnesium;
		this.phosphorus = phosphorus;
		this.potassium = potassium;
		this.sodium = sodium;
		this.zinc = zinc;
		this.copper = copper;
		this.manganese = manganese;
		this.selenium = selenium;
	}
	
	public String getSample_id() {
		return this.sample_id;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getCategory() {
		return this.category;
	}
	
	public int getServing_size() {
		return this.serving_size;
	}
	
	public double getCalorie() {
		return this.calorie;
	}
	
	public double getWater() {
		return this.water;
	}
	
	public double getProtein() {
		return this.protein;
	}
	
	public double getFat() {
		return this.fat;
	}
	
	public double getCarbohydrate() {
		return this.carbohydrate;
	}
	
	public double getSugars() {
		return this.sugars;
	}
	
	public double getFiber() {
		return this.fiber;
	}
	
	public int getCalcium() {
		return this.calcium;
	}
	
	public double getIron() {
		return this.iron;
	}
	
	public int getMagnesium() {
		return this.magnesium;
	}
	
	public int getPhosphorus() {
		return this.phosphorus;
	}
	
	public int getPotassium() {
		return this.potassium;
	}
	
	public int getSodium() {
		return this.sodium;
	}
	
	public double getZinc() {
		return this.zinc;
	}
	
	public double getCopper() {
		return this.copper;
	}
	
	public double getManganese() {
		return this.manganese;
	}
	
	public double getSelenium() {
		return this.selenium;
	}
	
	public void setSample_id(String sample_id) {
		this.sample_id = sample_id;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setCategory(String category) {
		this.category = category;
	}
	
	public void setServing_size(int serving_size) {
		this.serving_size = serving_size;
	}
	
	public void setCalorie(double calorie) {
		this.calorie = calorie;
	}
	
	public void setWater(double water) {
		this.water = water;
	}
	
	public void setProtein(double protein) {
		this.protein = protein;
	}
	
	public void setFat(double fat) {
		this.fat = fat;
	}
	
	public void setCarbohydrate(double carbohydrate) {
		this.carbohydrate = carbohydrate;
	}
	
	public void setSugars(double sugars) {
		this.sugars = sugars;
	}
	
	public void setFiber(double fiber) {
		this.fiber = fiber;
	}
	
	public void setCalcium(int calcium) {
		this.calcium = calcium;
	}
	
	public void setIron(double iron) {
		this.iron = iron;
	}
	
	public void setMagnesium(int magnesium) {
		this.magnesium = magnesium;
	}
	
	public void setPotassium(int potassium) {
		this.potassium = potassium;
	}
	
	public void setPhosphorus(int phosphorus) {
		this.phosphorus = phosphorus;
	}
	
	public void setSodium(int sodium) {
		this.sodium = sodium;
	}
	
	public void setZinc(double zinc) {
		this.zinc = zinc;
	}
	
	public void setCopper(double copper) {
		this.copper = copper;
	}
	
	public void setManganese(double manganese) {
		this.manganese = manganese;
	}
	
	public void setSelenium(double selenium) {
		this.selenium = selenium;
	}
}
