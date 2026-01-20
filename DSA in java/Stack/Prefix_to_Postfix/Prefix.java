import java.util.*;

public class Prefix {

    public static Stack<String> postFix(char[] str){
        Stack<String> st = new Stack<>();
        for(int i=str.length -1; i>=0; i--){
            if(Character.isLetterOrDigit(str[i])){
                st.push(String.valueOf(str[i]));
            }else{
                String temp1 = st.peek(); st.pop();
                String temp2 = st.peek(); st.pop();
                String ans = temp1+temp2+str[i];
                st.push(ans);
            }
        }
        return st;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Prefix Expression: ");
        String str = sc.next();
        Stack<String> lst = postFix(str.toCharArray());
        System.out.print("The Infix Expression: ");
        for(String s: lst){
            System.out.print(s);
        }
        sc.close();
    }
}
