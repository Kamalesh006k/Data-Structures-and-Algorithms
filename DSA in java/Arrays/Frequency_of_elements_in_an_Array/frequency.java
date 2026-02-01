import java.util.*;
public class frequency {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert into the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        Map<Integer,Integer> map = new HashMap<>();
        System.out.println("Enter the Array elements.....");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
            map.put(arr[i],map.getOrDefault(arr[i],0)+1);
        }
        System.out.print("Enter the length of the query set: ");
        int m = sc.nextInt();
        int[] query = new int[m];
        System.out.println("Enter the Query elements...");
        for(int i=0; i<m; i++){
            query[i] = sc.nextInt();
        }
        for(int s:query){
            System.out.println("The Freq of "+s+" is "+map.get(s));
        }
    }
}
