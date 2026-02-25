import java.util.*;
import java.sql.*;
public class Mysql {
    public static void main(String[] args)throws Exception{
        String url = "jdbc:mysql://localhost:3306/college?user=root&&password=admin@123";
        // String user = "root";
        // String pass = "admin@123";
        String query = "update student set dept = 'CSE' where names = 'Kamaleshrajan S'";
        Connection con = DriverManager.getConnection(url);
        Statement st = con.createStatement();
        int rs = st.executeUpdate(query);

        System.out.println(rs);
    }
}
