import java.util.*;
public class window {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert into the Array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the Array elements....");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        int i=0;
        System.out.print("Enter the value of k: ");
        int k = sc.nextInt() -1;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> lst = new ArrayList<>();
        System.out.println("The windows of the given array...");
        while(i<=k && k<n){
            lst.add(arr[i]);
            if(i==k){
                k+=k+1;
                i++;
                ans.add(new ArrayList<>(lst));
                lst.clear();
            }else{
                i++;
            }
        }
        System.out.println(ans);
    }
}
