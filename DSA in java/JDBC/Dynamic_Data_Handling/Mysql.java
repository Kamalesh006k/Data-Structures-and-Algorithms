import java.util.*;
import java.sql.*;
class Mysql {
    public static void main(String[] args) throws Exception{
        String url = "jdbc:mysql://localhost:3306/college?user=root&&password=admin@123";
        String query = "insert into student values(?,?,?,?,?)";
        int id = 17;
        String name = "Ajay Krishnan";
        int age = 20;
        String dept = "cy";
        int tid = 4;
        Connection con = DriverManager.getConnection(url);
        PreparedStatement st = con.prepareStatement(query);
        st.setInt(1,id);
        st.setString(2, name);
        st.setInt(3,age);
        st.setString(4, dept);
        st.setInt(5, tid);
        int rs = st.executeUpdate();
        System.out.println(rs);
    }
}