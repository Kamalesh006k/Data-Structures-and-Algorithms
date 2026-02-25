import java.util.*;
import java.sql.*;
public class Mysql {
    public static void main(String[] args) throws Exception {
        String url = "jdbc:mysql://localhost:3306/college?user=root&&password=admin@123";
        String query1 = "insert into student values (18,'Ramesh',21,'CSE',2)";
        String query2 = "insert into student values (19,'Deepika',22,'EEE',3)";
        String query3 = "insert into student values (20,'Sathish',19,'IT',1)";
        String query4 = "insert into student values (21,'Varsha',20,'ECE',4)";
        Connection con = DriverManager.getConnection(url);
        Statement st = con.createStatement();
        st.addBatch(query1);
        st.addBatch(query2);
        st.addBatch(query3);
        st.addBatch(query4);

        int[] result = st.executeBatch();

        for(int i:result){
            System.out.println(i);
        }

    }
}
