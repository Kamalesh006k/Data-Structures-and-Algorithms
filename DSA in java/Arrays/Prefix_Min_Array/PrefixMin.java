import java.util.*;

public class PrefixMin {
    public static void PrefixMinArray(int[] arr){
        int n = arr.length;
        int[] prefixmin = new int[n];
        prefixmin[0] = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]<prefixmin[i-1]){
                prefixmin[i] = arr[i];
            }else{
                prefixmin[i] = prefixmin[i-1];
            }
        }
        for(int s: prefixmin){
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
        PrefixMinArray(arr);
        sc.close();
    }    
}
