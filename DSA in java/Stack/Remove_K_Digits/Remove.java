import java.util.*;
public class Remove {

    static void removeZero(Stack<Character> st){
        List<Character> lst = new ArrayList<>();
        while (!st.isEmpty()) {
            lst.addFirst(st.peek());
            st.pop();
        }
        if(lst.getFirst() == '0'){
            lst.removeFirst();
        }
        for(char s: lst){
            System.out.print(s);
        }

    }

    static void remove(char[] str,int k){
        int n = str.length;
        Stack<Character> st = new Stack<>();
        for(int i=0; i<n; i++){
            while(!st.isEmpty() && st.peek()>str[i]  && k>0){
                st.pop();
                k--;
            }
            st.push(str[i]);
        }
        removeZero(st);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String str = sc.next();
        System.out.print("Enter the k digits to remove: ");
        int k = sc.nextInt();
        remove(str.toCharArray(),k);
        sc.close();
    }
}
