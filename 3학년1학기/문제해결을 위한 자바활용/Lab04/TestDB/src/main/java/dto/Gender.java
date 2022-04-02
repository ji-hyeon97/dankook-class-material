package dto;

public enum Gender {
	f, m;
	
	public static Gender nameOf(String value) { // String f -> Gender f
		if (value == null || value.isEmpty())
			return null;
		return Gender.valueOf(value);
	}
	
}
