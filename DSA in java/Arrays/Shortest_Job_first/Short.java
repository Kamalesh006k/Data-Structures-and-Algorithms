import java.util.*;
public class Short {

    static int waitTime(int[] arr){
        Arrays.sort(arr);
        int waitingTime =0, T=0,i=0;
        while (i<arr.length) {
            waitingTime += T;
            T += arr[i];
            i++;
        }

        return waitingTime/arr.length;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("The average waiting time: "+waitTime(arr));
    }
}
