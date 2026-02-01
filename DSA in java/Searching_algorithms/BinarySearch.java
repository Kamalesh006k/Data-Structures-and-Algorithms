
import java.util.*;
public class BinarySearch {

    static int binarySearch(int[] arr, int target){
        Arrays.sort(arr);
        int i = 0;
        int j = arr.length-1;

        
        while(i<=j){
            int mid = i+(j-i)/2;
            if(arr[mid] == target){
                return mid;
            }else if(target < arr[mid]){
                j = mid-1;
            }else if(target > arr[mid]){
                i = mid+1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the target value: ");
        int target = sc.nextInt();
        System.out.println("The element found at index position: "+ (binarySearch(arr,target)==-1 ? "Element not found": binarySearch(arr, target)));
    }
}