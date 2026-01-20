import java.util.*;
public class MaxConsecutiveOnes {
    static int maxConsecutiveOnes(int[] arr){
        int max =0;
        int count =0;
        int n = arr.length;
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                count++;
                max = Math.max(max,count);
            }else{
                count=0;
            }
       }
       return max;
    }
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements:");
        int n = sc.nextInt();
        int[] arr =  new int[n];
        System.out.print("Enter the Array elements....");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.print(maxConsecutiveOnes(arr));
        sc.close();
    }
}