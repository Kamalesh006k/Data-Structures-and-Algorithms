import java.util.*;

public class TargetSubsequence {

    static void subseq(int i, int n, int[] arr, List<Integer> lst,int sum,int target){
        if(i==n){
            if (target == sum){
                System.out.println(lst+"->"+sum);
                return;
            }
            return;
        }
        sum+=arr[i];
        lst.add(arr[i]);
        subseq(i+1, n, arr, lst, sum, target);
        sum-=arr[i];
        lst.remove(lst.size()-1);
        subseq(i+1, n, arr, lst,sum, target);
        return;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of Elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the Elements....");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the target value:");
        int target = sc.nextInt();
        List<Integer> lst = new ArrayList<>();
        int i=0;
        int sum =0;
        subseq(i,n,arr,lst,sum,target);
        sc.close();
    }
}
