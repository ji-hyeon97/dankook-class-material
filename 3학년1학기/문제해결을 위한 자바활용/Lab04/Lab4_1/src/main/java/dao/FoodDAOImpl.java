package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import dto.FoodBean;

public class FoodDAOImpl implements FoodDAO {
	private Connection conn = null;
	
	public FoodDAOImpl(Connection conn) {
		this.conn = conn;
	}

	@Override
	public int insert(FoodBean bean) {
		PreparedStatement pstmt = null;
		try {
			String sql = "insert into mfdsfood values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, bean.getSample_id());
			pstmt.setString(2, bean.getName());
			pstmt.setString(3, bean.getCategory());
			pstmt.setInt(4, bean.getServing_size());
			pstmt.setDouble(5, bean.getCalorie());
			pstmt.setDouble(6, bean.getWater());
			pstmt.setDouble(7, bean.getProtein());
			pstmt.setDouble(8, bean.getFat());
			pstmt.setDouble(9, bean.getCarbohydrate());
			pstmt.setDouble(10, bean.getSugars());
			pstmt.setDouble(11, bean.getFiber());
			pstmt.setInt(12, bean.getCalcium());
			pstmt.setDouble(13, bean.getIron());
			pstmt.setInt(14, bean.getMagnesium());
			pstmt.setInt(15, bean.getPhosphorus());
			pstmt.setInt(16, bean.getPotassium());
			pstmt.setInt(17, bean.getSodium());
			pstmt.setDouble(18, bean.getZinc());
			pstmt.setDouble(19, bean.getCopper());
			pstmt.setDouble(20, bean.getManganese());
			pstmt.setDouble(21, bean.getSelenium());
			return pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (pstmt != null) {
				try {
					pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return 0;
	}

	@Override
	public int delete(String sample_id) {
		PreparedStatement pstmt = null;
		try {
			String sql = "delete from mfdsfood where sample_id=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, sample_id);
			return pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (pstmt != null) {
				try {
					pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return 0;
	}

	@Override
	public int edit(FoodBean bean) {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "update mfdsfood set name=?,category=?,serving_size=?,calorie=?,water=?,protein=?,fat=?,"
					+ "carbohydrate=?,sugars=?,fiber=?,calcium=?,iron=?,magnesium=?,phosphorus=?,potassium=?,"
					+ "sodium=?,zinc=?,copper=?,manganese=?,selenium=? where sample_id=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, bean.getSample_id());
			pstmt.setString(2, bean.getName());
			pstmt.setString(3, bean.getCategory());
			pstmt.setInt(4, bean.getServing_size());
			pstmt.setDouble(5, bean.getCalorie());
			pstmt.setDouble(6, bean.getWater());
			pstmt.setDouble(7, bean.getProtein());
			pstmt.setDouble(8, bean.getFat());
			pstmt.setDouble(9, bean.getCarbohydrate());
			pstmt.setDouble(10, bean.getSugars());
			pstmt.setDouble(11, bean.getFiber());
			pstmt.setInt(12, bean.getCalcium());
			pstmt.setDouble(13, bean.getIron());
			pstmt.setInt(14, bean.getMagnesium());
			pstmt.setInt(15, bean.getPhosphorus());
			pstmt.setInt(16, bean.getPotassium());
			pstmt.setInt(17, bean.getSodium());
			pstmt.setDouble(18, bean.getZinc());
			pstmt.setDouble(19, bean.getCopper());
			pstmt.setDouble(20, bean.getManganese());
			pstmt.setDouble(21, bean.getSelenium());
			return pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (rs != null) {
				try {
					rs.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
			if (pstmt != null) {
				try {
					pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return 0;
	}

	@Override
	public FoodBean select(String sample_id) {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "select * from mfdsfood where sample_id=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, sample_id);
			rs = pstmt.executeQuery();
			if (rs.next()) {
				return createFromResultSet(rs);
			}
			else {
				return null;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (rs != null) {
				try {
					rs.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
			if (pstmt != null) {
				try {
					pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return null;
	}
	
	@Override
	public FoodBean createFromResultSet(ResultSet rs) {
		try {
			String sample_id = rs.getString("sample_id");
			String name = rs.getString("name");
			String category = rs.getString("category");
			int serving_size = rs.getInt("serving_size");
			double calorie = rs.getDouble("calorie");
			double water = rs.getDouble("water");
			double protein = rs.getDouble("protein");
			double fat = rs.getDouble("fat");
			double carbohydrate = rs.getDouble("carbohydrate");
			double sugars = rs.getDouble("sugars");
			double fiber = rs.getDouble("fiber");
			int calcium = rs.getInt("calcium");
			double iron = rs.getDouble("iron");
			int magnesium = rs.getInt("magnesium");
			int phosphorus = rs.getInt("phosphorus");
			int potassium = rs.getInt("potassium");
			int sodium = rs.getInt("sodium");
			double zinc = rs.getDouble("zinc");
			double copper = rs.getDouble("copper");
			double manganese = rs.getDouble("manganese");
			double selenium = rs.getDouble("selenium");
			
			FoodBean foodbean = new FoodBean(sample_id,name,category,serving_size,calorie,water,protein,fat,carbohydrate,
					sugars,fiber,calcium,iron,magnesium,phosphorus,potassium,sodium,zinc,copper,manganese,
					selenium);
			return foodbean;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public List<FoodBean> selectList() {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "select * from mfdsfood";
			pstmt = conn.prepareStatement(sql);
			rs = pstmt.executeQuery();
			List<FoodBean> petList = new ArrayList<>();
			while (rs.next()) {
				petList.add(createFromResultSet(rs));
			}
			return petList;
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (rs != null) {
				try {
					rs.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
			if (pstmt != null) {
				try {
					pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return null;
	}
	
	@Override
	public List<FoodBean> selectListByCategory(String category) {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "select * from mfdsfood order by category=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, category);
			rs = pstmt.executeQuery();
			List<FoodBean> list = new ArrayList<>();
			while (rs.next()) {
				list.add(createFromResultSet(rs));
			}
			return list;
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (rs != null) {
				try {
					rs.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
			if (pstmt != null) {
				try {
					pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return null;
	}

}