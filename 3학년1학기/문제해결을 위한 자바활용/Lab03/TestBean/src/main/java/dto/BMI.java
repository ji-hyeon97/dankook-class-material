package dto;

public enum BMI {
	UNDERWEIGHT, NORMAL, OVERWEIGHT, OBESITY;

	public static BMI valueOf(int value) {
		switch(value) {
		case 0:	return UNDERWEIGHT;
		case 1:	return NORMAL;
		case 2:	return OVERWEIGHT;
		case 3:	return OBESITY;
		default: return null;
		}
	}

	public static String[] names() {
		String[] names = new String[BMI.values().length];
		for (BMI t : BMI.values()) 
			names[t.ordinal()] = t.toString();
		return names;
	}
}
