package dto;

import java.sql.Date;

public class Pet {
	private String name;
	private String owner;
	private PetType species; 
	private Gender gender;
	private Date birth;
	private Date death;
	
	public Pet() {
		this(null, null, null, null, null, null);
	}
	
	public Pet(String name, String owner, PetType species, Gender gender, Date birth, Date death) {
		this.name = name;
		this.owner = owner;
		this.species = species;
		this.gender = gender;
		this.birth = birth;
		this.death = death;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getOwner() {
		return owner;
	}

	public void setOwner(String owner) {
		this.owner = owner;
	}

	public PetType getSpecies() {
		return species;
	}

	public void setSpecies(PetType species) {
		this.species = species;
	}

	public Gender getGender() {
		return gender;
	}

	public void setGender(Gender gender) {
		this.gender = gender;
	}

	public Date getBirth() {
		return birth;
	}

	public void setBirth(Date birth) {
		this.birth = birth;
	}

	public Date getDeath() {
		return death;
	}

	public void setDeath(Date death) {
		this.death = death;
	}

	@Override
	public String toString() {
		return "Pet [name=" + name + ", owner=" + owner + ", species=" + species + ", gender=" + gender + ", birth=" + birth
				+ ", death=" + death + "]";
	}
}
