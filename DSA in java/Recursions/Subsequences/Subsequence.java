import java.util.*;

public class Subsequence {

    static void subseq(int i, int n, int[] arr, List<Integer> lst){
        if(i==n){
            System.out.println(lst);
            return;
        }

        lst.add(arr[i]);
        subseq(i+1, n, arr, lst);
        lst.remove(lst.size()-1);
        subseq(i+1, n, arr, lst);
        return;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        List<Integer> lst = new ArrayList<>();
        int i=0;
        subseq(i,n,arr,lst);
        sc.close();
    }
}
