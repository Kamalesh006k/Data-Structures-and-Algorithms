import java.util.*;
public class Subarray {

    static void subArray(int[] arr,int start, int end , List<Integer> list, List<List<Integer>> ans){
        if(start == arr.length ){
            return;
        }
        if(end == arr.length){
            subArray(arr, start+1, start+1,list,ans);
        }else{
            list.clear();
            for(int i=start; i<=end; i++){
                list.add(arr[i]);
            }
            ans.add(new ArrayList<>(list));
            subArray(arr, start, end+1,list, ans);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n;  i++){
            arr[i] = sc.nextInt();
        }
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        subArray(arr, 0, 0,list, ans);
        System.out.println(ans);
    }
}
