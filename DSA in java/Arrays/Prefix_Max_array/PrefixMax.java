import java.util.*;

public class PrefixMax {
    public static void PrefixMaxArray(int[] arr){
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
        for(int s: prefixmax){
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
        PrefixMaxArray(arr);
        sc.close();
    }    
}
