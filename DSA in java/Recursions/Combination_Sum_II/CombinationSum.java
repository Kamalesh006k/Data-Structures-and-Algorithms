import java.util.*;

public class CombinationSum {

    static void combinationSum(int i, int n, int[] arr, List<Integer> ans, List<List<Integer>> ds, int target) {
        if (target == 0) {
            ds.add(new ArrayList<>(ans));
            return;
        }

        for (int j = i; j < n; j++) {
            if (j > i && arr[j] == arr[j - 1]) continue;
            if (arr[j] > target) break;

            ans.add(arr[j]);
            combinationSum(j + 1, n, arr, ans, ds, target - arr[j]);
            ans.remove(ans.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter the elements: ");
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
