import java.util.*;

public class Jump{

    static boolean possible(int[] arr){
        int maxJump=0, i=0;
        while(i<arr.length){
            maxJump = Math.max(maxJump, i+arr[i]);
            if(i>=maxJump) return false;
            i++;
        }
        return true;
    }
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(possible(arr)?"It is possible to jump to the end":"It is not possible to jump to the end");
    }
}