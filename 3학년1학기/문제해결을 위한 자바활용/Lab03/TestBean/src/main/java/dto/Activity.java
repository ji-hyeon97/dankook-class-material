package dto;
public enum Activity {
	LOW, MEDIUM, HIGH;

	public static Activity valueOf(int value) {
		switch(value) {
		case 0:
			return LOW;
		case 1:
			return MEDIUM;
		case 2:
			return HIGH;
		default:
			return null;
		}
	}

	public static String[] names() {
		String[] names = new String[Activity.values().length];
		for (Activity t : Activity.values()) 
			names[t.ordinal()] = t.toString();
		return names;
	}
}