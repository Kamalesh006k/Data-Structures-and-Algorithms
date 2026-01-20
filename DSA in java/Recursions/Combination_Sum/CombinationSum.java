import java.util.*;

public class CombinationSum {

    static void combinationSum(int i, int n, int[] arr, List<Integer> ans, List<List<Integer>> ds, int target) {
        if (i == n) {
            if (target == 0) {
                ds.add(new ArrayList<>(ans));
            }
            return;
        }

        if (arr[i] <= target) {
            ans.add(arr[i]);
            combinationSum(i, n, arr, ans, ds, target - arr[i]);
            ans.remove(ans.size() - 1);
        }

        combinationSum(i + 1, n, arr, ans, ds, target);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements.....");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the target value: ");
        int target = sc.nextInt();

        Arrays.sort(arr);

        List<List<Integer>> ds = new ArrayList<>();
        combinationSum(0, n, arr, new ArrayList<>(), ds, target);

        System.out.println(ds);
        sc.close();
    }
}
