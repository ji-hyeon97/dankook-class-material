package dao;

import java.sql.ResultSet;
import java.util.List;

import dto.BuyBean;

public interface BuyDAO {
	int insert(BuyBean bean);
	int delete(int num);
	int edit(BuyBean bean);
	BuyBean select(int num);
	List<BuyBean> selectList();
	List<BuyBean> selectListByCategory(String prod_name);
	BuyBean createFromResultSet(ResultSet rs);
}
