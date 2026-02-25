import java.util.*;
public class MaxMin {

    static int maxmin(int[] arr, int k){
        Arrays.sort(arr);
        int i=0, j=k-1, ans=Integer.MAX_VALUE;
        
        while(j<arr.length){
            ans = Math.min(arr[j]-arr[i],ans);
            i++;
            j++;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = sc.nextInt();
        System.out.print("Enter the value of k: ");
        int k = sc.nextInt();
        System.out.println("Enter the Array elements....");
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(maxmin(arr, k));
        

    }
}
