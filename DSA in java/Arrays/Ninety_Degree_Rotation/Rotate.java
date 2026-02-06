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

    static void Transpose(int[][] arr){
        for(int i=0;  i<arr.length; i++){
            for(int j=i+1; j<arr[0].length; j++){
                int temp = arr[i][j];
                arr[i][j] = arr[j][i]
                ;
                arr[j][i] = temp;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n and m: ");
        int n=sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        Transpose(arr);
        for(int[] a: arr){
            reverse(a, 0, a.length-1);
        }
        for(int[] k: arr){
            for(int s: k){
                System.out.print(s+" ");
            }
            System.out.println();
        }
    }
    
}