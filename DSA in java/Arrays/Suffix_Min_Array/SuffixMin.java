import java.util.*;

public class SuffixMin {
    public static void SuffixMinArray(int[] arr){
        int n = arr.length;
        int[] suffixmin = new int[n];
        suffixmin[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i]<suffixmin[i+1]){
                suffixmin[i] = arr[i];
            }else{
                suffixmin[i] = suffixmin[i+1];
            }
        }
        for(int s: suffixmin){
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
        SuffixMinArray(arr);
        sc.close();
    }    
}
