import java.util.*;
class Rotate {

    static void rotate(int[] arr,int k){
        for(int i=0; i<k; i++){
            int temp = arr[0];
            for(int j=1; j<arr.length; j++){
                arr[j-1]=arr[j];
            }
            arr[arr.length-1] = temp;
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
        rotate(arr, k);

        for(int a: arr){
            System.out.print(a+" ");
        }
    }
    
}