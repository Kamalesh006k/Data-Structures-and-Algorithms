import java.util.*;

public class Infix {

    public static int preority(char a){
        switch (a) {
            case '^' -> {return 3;}
            case '*','/' -> {return 2;}
            case '+','-' -> {return 1;}
        }
        return 0;
    }

    public static void reverse(char[] arr){
        int i=0, j=arr.length -1;
        while(i<j){
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    public static void changeParen(char[] arr){
        for(int i=0; i<arr.length; i++){
            if(arr[i]=='(') arr[i] = ')';
            if(arr[i] == ')') arr[i] = '(';
        }
    }

    public static List<Character> infix(char[] str){
        reverse(str);
        changeParen(str);
        Stack<Character> st = new Stack<>();
        List<Character> lst = new ArrayList<>();
        int n = str.length;
        for(int i=0; i<n; i++){
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>= '0' && str[i]<= '9')){
                lst.add(str[i]);
            }else if(str[i] == '('){
                st.push(str[i]);
            }else if(str[i] == ')'){
                while(!st.isEmpty() && st.peek() != '('){
                    lst.add(st.peek());
                    st.pop();
                }
                st.pop();
            }else{
                if(str[i] == '^'){
                    while(!st.isEmpty() && preority(str[i]) <= preority(st.peek())){
                        lst.add(st.peek());
                        st.pop();
                    }
                }else{
                    while(!st.isEmpty() && preority(str[i]) < preority(st.peek())){
                        lst.add(st.peek());
                        st.pop();
                    }
                }
                st.push(str[i]);
            }
        }

        while (!st.isEmpty()) {
            lst.add(st.peek());
            st.pop();
        }
        
        Collections.reverse(lst);
        return lst;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Infix Expression: ");
        String str = sc.next();
        List<Character> lst = infix(str.toCharArray());
        System.out.print("The Prefix Expression: ");
        for(char i : lst){
            System.out.print(i);
        }
        sc.close();
    }
}
 