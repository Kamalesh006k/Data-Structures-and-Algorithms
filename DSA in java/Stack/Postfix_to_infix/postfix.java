import java.util.*;

public class postfix {

    public static Stack<String> postFix(char[] str){
        Stack<String> st = new Stack<>();
        for(int i=0; i<str.length; i++){
            if(Character.isLetterOrDigit(str[i])){
                st.push(String.valueOf(str[i]));
            }else{
                String temp1 = st.peek(); st.pop();
                String temp2 = st.peek(); st.pop();
                String ans = "("+temp2+str[i]+temp1+")";
                st.push(ans);
            }
        }
        return st;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Postfix Expression: ");
        String str = sc.next();
        Stack<String> lst = postFix(str.toCharArray());
        System.out.print("The Infix Expression: ");
        for(String s: lst){
            System.out.print(s);
        }
        sc.close();
    }
}
