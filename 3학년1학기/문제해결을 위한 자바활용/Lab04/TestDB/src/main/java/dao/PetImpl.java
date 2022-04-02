package dao;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import dto.Gender;
import dto.Pet;
import dto.PetType;

public class PetImpl implements PetDAO {
	private Connection conn = null;
	
	public PetImpl(Connection conn) {
		this.conn = conn;
	}

	@Override
	public int insert(Pet bean) {
		PreparedStatement pstmt = null;
		try {
			String sql = "insert into pet values (?,?,?,?,?,?)";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, bean.getName());
			pstmt.setString(2, bean.getOwner());
			pstmt.setString(3, bean.getSpecies().toString());
			pstmt.setString(4, bean.getGender().toString());
			pstmt.setDate(5, bean.getBirth());
			pstmt.setDate(6, bean.getDeath());
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
	public int delete(String name) {
		PreparedStatement pstmt = null;
		try {
			String sql = "delete from pet where name=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, name);
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
	public int edit(Pet bean) {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "update pet set owner=?, species=?, gender=?, birth=?, death=? where name=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, bean.getOwner());
			pstmt.setString(2, bean.getSpecies().toString());
			pstmt.setString(3, bean.getGender().toString());
			pstmt.setDate(4, bean.getBirth());
			pstmt.setDate(5, bean.getDeath());
			pstmt.setString(6, bean.getName());
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
	public Pet select(String name) {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "select * from pet where name=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, name);
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
	public Pet createFromResultSet(ResultSet rs) {
		try {
			String name = rs.getString("name");
			String owner = rs.getString("owner");
			PetType species = PetType.nameOf(rs.getString("species"));
			Gender sex = Gender.nameOf(rs.getString("gender"));
			Date birth = rs.getDate("birth");
			Date death = rs.getDate("death");
			Pet pet = new Pet(name, owner, species, sex, birth, death);
			return pet;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public List<Pet> selectList() {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "select * from pet";
			pstmt = conn.prepareStatement(sql);
			rs = pstmt.executeQuery();
			List<Pet> petList = new ArrayList<>();
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
	public List<Pet> selectListByOwner(String owner) {
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		try {
			String sql = "select * from pet order by owner=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, owner);
			rs = pstmt.executeQuery();
			List<Pet> list = new ArrayList<>();
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
