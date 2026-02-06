import java.util.*;
public class Cookies {

    static int cookies(int[] arr, int[] cookies){
        int ans =0;
        int i=0, j=0;
        Arrays.sort(arr);
        Arrays.sort(cookies);
        while(i<arr.length && j<cookies.length){
            if(arr[i]<=cookies[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        int[] cookies = new int[m];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        
        for(int i=0; i<m; i++){
            cookies[i] = sc.nextInt();
        }

        System.out.println(cookies(arr,cookies));
    }
}
