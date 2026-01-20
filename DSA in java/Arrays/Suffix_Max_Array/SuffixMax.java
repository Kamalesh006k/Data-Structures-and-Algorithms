import java.util.*;

public class SuffixMax {
    public static void SuffixMaxArray(int[] arr){
        int n = arr.length;
        int[] suffixmax = new int[n];
        suffixmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i]>suffixmax[i+1]){
                suffixmax[i] = arr[i];
            }else{
                suffixmax[i] = suffixmax[i+1];
            }
        }
        for(int s: suffixmax){
            System.out.print(s+" ");
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
        SuffixMaxArray(arr);
        sc.close();
    }    
}
