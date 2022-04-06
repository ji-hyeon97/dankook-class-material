package dto;

public class BuyBean {
	private int num;
	private String prod_name;
	private String group_name;
	private int price;
	private int amount;
	
	public BuyBean() {}
	
	public BuyBean(int num, String prod_name, String group_name,
			int price, int amount) {
		this.num = num;
		this.prod_name = prod_name;
		this.group_name = group_name;
		this.price = price;
		this.amount = amount;	
	}
	
	public int getNum() {
		return this.num;
	}
	
	public String getProd_name() {
		return this.prod_name;
	}
	
	public String getGroup_name() {
		return this.group_name;
	}
	
	public int getPrice() {
		return this.price;
	}
	
	public int getAmount() {
		return this.amount;
	}
	
	public void setNum(int num) {
		this.num = num;
	}
	
	public void setProd_name(String prod_name) {
		this.prod_name = prod_name;
	}
	
	public void setGroup_name(String group_name) {
		this.group_name = group_name;
	}
	
	public void setPrice(int price) {
		this.price = price;
	}
	
	public void setAmount(int amount) {
		this.amount = amount;
	}
}