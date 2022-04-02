package dao;

import java.sql.ResultSet;
import java.util.List;

import dto.Pet;


public interface PetDAO {
	int insert(Pet bean);
	int delete(String name);
	int edit(Pet bean);
	Pet select(String name);
	List<Pet> selectList();
	List<Pet> selectListByOwner(String owner);
	Pet createFromResultSet(ResultSet rs);
}
