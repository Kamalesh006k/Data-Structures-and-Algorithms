import java.util.*;

public class BalancedBrackets {

    static Boolean balance(char[] charArray,Stack<Character> lst, int n){
        for(int i=0; i<n; i++){
            if(charArray[i] == '(' || charArray[i] =='{' || charArray[i] == '['){
                lst.push(charArray[i]);
            }else if((!lst.isEmpty()) && ((lst.peek()=='(' && charArray[i]==')')||(lst.peek()=='{' && charArray[i]=='}')||(lst.peek()=='[' && charArray[i]==']'))){
                lst.pop();
            }else{
                return false;
            }
        }

        if(lst.isEmpty()){
            return true;
        }
        return false;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        Stack<Character> lst = new Stack<>();
        int n = str.length();
        char[] charArray = new char[n];
        charArray = str.toCharArray();
        if(balance(charArray,lst,n)){
            System.out.println("Yes, It is balanced");
        }else{
            System.out.println("No, It is not balanced");
        }
        sc.close();
    }
}
