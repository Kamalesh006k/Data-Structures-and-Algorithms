import java.util.*;
import java.sql.*;
public class Mysql {
    public static void main(String[] args) throws Exception {
        String url = "jdbc:mysql://localhost:3306/college?user=root&&password=admin@123";
        String query1 = "update student set age = 25 where id = 18";
        String query2 = "update student set dept = 'IT' where id = 19";
        String query3 = "update student set teacher = 2 where id = 20";
        String query4 = "update student set names = 'Varsha R' where id = 21";
        Connection con = DriverManager.getConnection(url);
        con.setAutoCommit(false);
        Statement st = con.createStatement();
        st.addBatch(query1);
        st.addBatch(query2);
        st.addBatch(query3);
        st.addBatch(query4);

        try {
            int[] result = st.executeBatch();

            for (int i : result) {
                System.out.println("Rows affected: " + i);
            }

            con.commit(); 
            System.out.println("Transaction Successful");

        } catch (Exception e) {
            con.rollback();
            System.out.println("Transaction Failed");
            e.printStackTrace();
        }

        st.close();
        con.close();


    }
}
