import java.util.*;
public class Jump {

    static int jumpCount(int[] arr,int idx, int jump){
        if(idx == arr.length-1) return jump;
        int minjump = Integer.MAX_VALUE;
        for(int i=1; i<=arr[idx]; i++){
            minjump = Math.min(minjump,jumpCount(arr, idx+i, jump+1));
        }
        return minjump;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(jumpCount(arr,0,0));
    }
}
