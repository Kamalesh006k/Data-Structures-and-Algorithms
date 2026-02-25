import java.util.*;
import java.sql.*;
public class Mysql {
    public static void main(String[] args) throws Exception {
        String url = "jdbc:mysql://localhost:3306/college";
        String user = "root";
        String pass = "admin@123";
        String query = "select * from student";
        Connection con = DriverManager.getConnection(url,user,pass);
        Statement st = con.createStatement();
        ResultSet rs = st.executeQuery(query);

        while(rs.next()){
            System.out.print(rs.getInt(1)+" ");
            System.out.print(rs.getString(2)+" ");
            System.out.print(rs.getInt(3)+" ");
            System.out.print(rs.getString(4)+" ");
            System.out.println(rs.getString(5));
        }
    }
}
