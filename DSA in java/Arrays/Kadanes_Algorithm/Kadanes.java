import java.util.*;
public class Kadanes {

    static int MaxSumSubarray(int[] arr){
        int sum = 0,max=Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++){
            if(sum<0) sum=0;
            sum+=arr[i];
            max = Math.max(sum,max);
        }

        return max;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(MaxSumSubarray(arr));
    }
}
