import java.util.*;

public class SubsequenceSum {

    static void subseq(int i, int n, int[] arr, List<Integer> lst,int sum){
        if(i==n){
            System.out.println(lst+"->"+sum);
            return;
        }

        lst.add(arr[i]);
        sum+=arr[i];
        subseq(i+1, n, arr, lst,sum);
        lst.remove(lst.size()-1);
        sum-=arr[i];
        subseq(i+1, n, arr, lst,sum);
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
        int sum =0;
        subseq(i,n,arr,lst,sum);
        sc.close();
    }
}
