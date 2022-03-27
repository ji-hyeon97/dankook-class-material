<<<<<<< HEAD
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>식품 영양 성분</title>
</head>
<body>

<%!
public class foodNutrientFacts{
	private String foodCode;
	private String foodName;
	private String foodCategory;
	private double kcal;
	private double moisture;
	private double protein;
	private double fat;
	private double carbohydrate;
	private double calcium;
	private double magnesium;
	private double vitaminB1;
	private double cholesterol;
	
	public foodNutrientFacts(String foodCode, String foodName, String foodCategory, double kcal,
			double moisture, double protein, double fat, double carbohydrate, double calcium,
			double magnesium, double vitaminB1, double cholesterol){
		
		this.foodCode = foodCode;
		this.foodName = foodName;
		this.foodCategory = foodCategory;
		this.kcal = kcal;
		this.moisture = moisture;
		this.protein = protein;
		this.fat = fat;
		this.carbohydrate = carbohydrate;
		this.calcium = calcium;
		this.magnesium = magnesium;
		this.vitaminB1 = vitaminB1;
		this.cholesterol = cholesterol;
	}
	
	public String getFoodCode(){
		return this.foodCode;
	}
	
	public String getFoodName(){
		return this.foodName;
	}
	
	public String getFoodCategory(){
		return this.foodCategory;
	}
	
	public double getKcal(){
		return this.kcal;
	}
	
	public double getMoisture(){
		return this.moisture;
	}
	
	public double getProtein(){
		return this.protein;
	}
	
	public double getFat(){
		return this.fat;
	}
	
	public double getCarbohydrate(){
		return this.carbohydrate;
	}
	
	public double getCalcium(){
		return this.calcium;
	}
	
	public double getMagnesium(){
		return this.magnesium;
	}
	
	public double getVitaminB1(){
		return this.vitaminB1;
	}
	
	public double getCholesterol(){
		return this.cholesterol;
	}
	
	@Override
	public String toString(){
		return "foodNutrientFacts [foodCode= "+foodCode+", foodName= " + foodName+", foodCategory= "+foodCategory+
				" ,kcal= "+kcal+"moisture= "+moisture+", protein= "+protein+", fat= "+fat+", carbohydrate= "+carbohydrate+
				", calcium= "+calcium+", magnesium= "+magnesium+", vitaminB1= "+vitaminB1+", cholesterol= "+cholesterol+"]";
	}
}

public class foodNutrientFactsManager{
	private List<foodNutrientFacts> list = new ArrayList<>();
	
	public foodNutrientFactsManager(){
		list.add(new foodNutrientFacts("D000006", "꿩불고기", "육류구이", 368.8, 412.6, 33.5, 8.5, 39.7, 105.61, 85.39, 0, 106.18));
		list.add(new foodNutrientFacts("D000007", "닭갈비", "육류구이", 595.61, 276.4, 45.9, 25.8, 44.9, 98.64, 104.42, 0.24, 193.4));
		list.add(new foodNutrientFacts("D000009", "닭꼬치", "육류구이", 176.72, 35.30, 11.56, 8.56, 13.34, 17.67, 0, 0.22, 31.44));
		list.add(new foodNutrientFacts("D000010", "더덕구이", "채소류구이", 184, 58.1, 3.1, 5.2, 5.2, 46.42, 38.21, 0.23, 0.12));
		list.add(new foodNutrientFacts("D000011", "도미구이", "어패류구이", 397, 163.3, 61.1, 16.5, 2.1, 158.8, 120.37, 0.1, 211.24));
		list.add(new foodNutrientFacts("D000012", "돼지갈비", "육류구이", 240.32, 56.3, 19.5, 14.4, 8.1, 47.21, 20.74, 0.31, 49.34));
		list.add(new foodNutrientFacts("D000015", "병어구이", "어패류구이", 488, 157.7, 54.6, 30.8, 0.2, 80.44, 118.57, 0.12, 198.51)); 
		list.add(new foodNutrientFacts("D000016", "불고기", "육류구이", 395.29, 80.1, 34.4, 25.2, 7.8, 12.31, 36.22, 0.08, 68.85));
		list.add(new foodNutrientFacts("D000017", "붕장어소금구이", "어패류구이",296.54, 44.3, 26, 16.2, 11.6, 164.09, 37.38, 0, 167.07));
		list.add(new foodNutrientFacts("D000020", "소양념갈비구이", "육류구이", 989.15, 137, 60.1, 71.6, 26.2, 85.27, 59.1, 0.25, 186.63));
		list.add(new foodNutrientFacts("D000021", "양념왕갈비", "육류구이", 480.81, 71.8, 27.1, 35.3, 13.7, 31.21, 26.29, 0, 58.52));
	}
	
	public List<foodNutrientFacts> get(){
		return list;
	}
	
	public foodNutrientFacts get(String foodCode){
		foodNutrientFacts foodnutrientfacts = null;
		for(foodNutrientFacts f : list){
			if( f !=null && f.getFoodCode().equals(foodCode)){
				foodnutrientfacts = f;
				break;
			}
		}
		return foodnutrientfacts;		
	}
}
foodNutrientFactsManager manager = new foodNutrientFactsManager();
%>
</body>
=======
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>식품 영양 성분</title>
</head>
<body>

<%!
public class foodNutrientFacts{
	private String foodCode;
	private String foodName;
	private String foodCategory;
	private double kcal;
	private double moisture;
	private double protein;
	private double fat;
	private double carbohydrate;
	private double calcium;
	private double magnesium;
	private double vitaminB1;
	private double cholesterol;
	
	public foodNutrientFacts(String foodCode, String foodName, String foodCategory, double kcal,
			double moisture, double protein, double fat, double carbohydrate, double calcium,
			double magnesium, double vitaminB1, double cholesterol){
		
		this.foodCode = foodCode;
		this.foodName = foodName;
		this.foodCategory = foodCategory;
		this.kcal = kcal;
		this.moisture = moisture;
		this.protein = protein;
		this.fat = fat;
		this.carbohydrate = carbohydrate;
		this.calcium = calcium;
		this.magnesium = magnesium;
		this.vitaminB1 = vitaminB1;
		this.cholesterol = cholesterol;
	}
	
	public String getFoodCode(){
		return this.foodCode;
	}
	
	public String getFoodName(){
		return this.foodName;
	}
	
	public String getFoodCategory(){
		return this.foodCategory;
	}
	
	public double getKcal(){
		return this.kcal;
	}
	
	public double getMoisture(){
		return this.moisture;
	}
	
	public double getProtein(){
		return this.protein;
	}
	
	public double getFat(){
		return this.fat;
	}
	
	public double getCarbohydrate(){
		return this.carbohydrate;
	}
	
	public double getCalcium(){
		return this.calcium;
	}
	
	public double getMagnesium(){
		return this.magnesium;
	}
	
	public double getVitaminB1(){
		return this.vitaminB1;
	}
	
	public double getCholesterol(){
		return this.cholesterol;
	}
	
	@Override
	public String toString(){
		return "foodNutrientFacts [foodCode= "+foodCode+", foodName= " + foodName+", foodCategory= "+foodCategory+
				" ,kcal= "+kcal+"moisture= "+moisture+", protein= "+protein+", fat= "+fat+", carbohydrate= "+carbohydrate+
				", calcium= "+calcium+", magnesium= "+magnesium+", vitaminB1= "+vitaminB1+", cholesterol= "+cholesterol+"]";
	}
}

public class foodNutrientFactsManager{
	private List<foodNutrientFacts> list = new ArrayList<>();
	
	public foodNutrientFactsManager(){
		list.add(new foodNutrientFacts("D000006", "꿩불고기", "육류구이", 368.8, 412.6, 33.5, 8.5, 39.7, 105.61, 85.39, 0, 106.18));
		list.add(new foodNutrientFacts("D000007", "닭갈비", "육류구이", 595.61, 276.4, 45.9, 25.8, 44.9, 98.64, 104.42, 0.24, 193.4));
		list.add(new foodNutrientFacts("D000009", "닭꼬치", "육류구이", 176.72, 35.30, 11.56, 8.56, 13.34, 17.67, 0, 0.22, 31.44));
		list.add(new foodNutrientFacts("D000010", "더덕구이", "채소류구이", 184, 58.1, 3.1, 5.2, 5.2, 46.42, 38.21, 0.23, 0.12));
		list.add(new foodNutrientFacts("D000011", "도미구이", "어패류구이", 397, 163.3, 61.1, 16.5, 2.1, 158.8, 120.37, 0.1, 211.24));
		list.add(new foodNutrientFacts("D000012", "돼지갈비", "육류구이", 240.32, 56.3, 19.5, 14.4, 8.1, 47.21, 20.74, 0.31, 49.34));
		list.add(new foodNutrientFacts("D000015", "병어구이", "어패류구이", 488, 157.7, 54.6, 30.8, 0.2, 80.44, 118.57, 0.12, 198.51)); 
		list.add(new foodNutrientFacts("D000016", "불고기", "육류구이", 395.29, 80.1, 34.4, 25.2, 7.8, 12.31, 36.22, 0.08, 68.85));
		list.add(new foodNutrientFacts("D000017", "붕장어소금구이", "어패류구이",296.54, 44.3, 26, 16.2, 11.6, 164.09, 37.38, 0, 167.07));
		list.add(new foodNutrientFacts("D000020", "소양념갈비구이", "육류구이", 989.15, 137, 60.1, 71.6, 26.2, 85.27, 59.1, 0.25, 186.63));
		list.add(new foodNutrientFacts("D000021", "양념왕갈비", "육류구이", 480.81, 71.8, 27.1, 35.3, 13.7, 31.21, 26.29, 0, 58.52));
	}
	
	public List<foodNutrientFacts> get(){
		return list;
	}
	
	public foodNutrientFacts get(String foodCode){
		foodNutrientFacts foodnutrientfacts = null;
		for(foodNutrientFacts f : list){
			if( f !=null && f.getFoodCode().equals(foodCode)){
				foodnutrientfacts = f;
				break;
			}
		}
		return foodnutrientfacts;		
	}
}
foodNutrientFactsManager manager = new foodNutrientFactsManager();
%>
</body>
>>>>>>> 6f526871052167d9510e765dcf88395334345a0f
</html>