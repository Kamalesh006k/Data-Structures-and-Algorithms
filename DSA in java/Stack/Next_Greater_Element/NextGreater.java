import java.util.*;
public class NextGreater {

    public static void Nge(int[] arr){
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] Nge = new int[n];
        for(int i=n-1; i>=0; i--){
            while(!st.isEmpty() && arr[i]>=st.peek()){
                st.pop();
            }
            if(st.isEmpty()){
                Nge[i] = -1;
            }else{
                Nge[i] = st.peek();
            }
            st.push(arr[i]);
        }
        for(int i: Nge){
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
        Nge(arr);
    }
}
