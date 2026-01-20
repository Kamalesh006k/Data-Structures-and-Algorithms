import java.util.*;
public class Monotonic {

    public static void MonotonicStack(int[] arr){
        Stack<Integer> st = new Stack<>();
        for(int i:arr){
            while(!st.isEmpty() && st.peek()>= i){
                st.pop();
            }
            st.push(i);
        }

        for(int i: st){
            System.out.print(i+" ");
        }

    }
    public static void main(String[] args){
         Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements:");
        int n = sc.nextInt();
        int[] arr =  new int[n];
        System.out.println("Enter the Array elements....");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        MonotonicStack(arr);
        sc.close();
    }    
}
