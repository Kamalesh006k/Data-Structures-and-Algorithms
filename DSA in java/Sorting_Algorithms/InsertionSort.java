import java.util.*;
public class InsertionSort{
    
    static void insertionsort(int[] arr, int n){
        for(int i=1; i<n; i++){
            int j = i-1;
            int key = arr[i];
            while(j>=0 && key<arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    
   public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        insertionsort(arr,n);
        System.out.println("OUTPUT");
        
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        sc.close();
    }
}