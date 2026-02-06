import java.util.*;
class Rotate {

    static void reverse(int[] arr,int start, int end){
        while(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Size of the Array: ");
        int n=sc.nextInt();
        System.out.print("Enter the number of elements to rotate: ");
        int m = sc.nextInt();
        int k = m%n;
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        reverse(arr, 0, k);
        reverse(arr, k+1, n-1);
        reverse(arr, 0, n-1);

        for(int a: arr){
            System.out.print(a+" ");
        }
    }
    
}