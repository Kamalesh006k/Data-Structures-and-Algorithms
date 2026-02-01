import java.util.*;

class Permutation{

    public static void permutation(int[] arr,int n, Stack<Integer> lst, List<List<Integer>> ans,boolean[] freq){
        if(n == lst.size()){
            ans.add(new ArrayList<>(lst));
            return;
        }
        for(int j=0; j<arr.length; j++){
            if(!freq[j]){
                lst.push(arr[j]);
                freq[j] = true;
                permutation(arr,n, lst, ans, freq);
                lst.pop();
                freq[j] = false;
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n= sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        List<List<Integer>> ans = new ArrayList<>();
        Stack<Integer> lst = new Stack<>();
        boolean[] freq = new boolean[n];
        Arrays.fill(freq,false);
        permutation(arr,n,lst,ans,freq);
        System.out.print(ans);
    }
}