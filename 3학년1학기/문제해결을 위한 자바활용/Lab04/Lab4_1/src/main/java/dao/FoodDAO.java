package dao;

import java.sql.ResultSet;
import java.util.List;

import dto.FoodBean;


public interface FoodDAO {
	int insert(FoodBean bean);
	int delete(String id);
	int edit(FoodBean bean);
	FoodBean select(String id);
	List<FoodBean> selectList();
	List<FoodBean> selectListByCategory(String category);
	FoodBean createFromResultSet(ResultSet rs);
}