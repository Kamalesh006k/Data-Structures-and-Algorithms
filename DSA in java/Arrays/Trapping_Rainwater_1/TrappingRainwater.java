import java.util.*;
public class TrappingRainwater {

    public static void traprainwater(int[] arr){
        int n = arr.length;
        int[] prefixmax = new int[n];
        prefixmax[0] = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]>prefixmax[i-1]){
                prefixmax[i] = arr[i];
            }else{
                prefixmax[i] = prefixmax[i-1];
            }
        }

        int[] suffixmax = new int[n];
        suffixmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i]>suffixmax[i+1]){
                suffixmax[i] = arr[i];
            }else{
                suffixmax[i] = suffixmax[i+1];
            }
        }
        int total =0;
        for(int i=0; i<n; i++){
            total += Math.min(prefixmax[i],suffixmax[i])-arr[i];
        }
        System.out.print("Total amount of rain water trapped: ");
        System.out.print(total);
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
        traprainwater(arr);
    }    
}
