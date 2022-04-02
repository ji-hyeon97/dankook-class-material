package dto;

public enum PetType {
	bird, cat, dog, fish, hamster, rabbit, snake, turtle;
	
	public static PetType nameOf(String value) { // String bird -> PetType BIRD
		if (value == null || value.isEmpty())
			return null;
		return PetType.valueOf(value);
	}
}
