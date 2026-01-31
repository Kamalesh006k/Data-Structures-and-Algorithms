import java.util.*;
public class MaxSegTree {
    int[] SegTree;

    MaxSegTree(int n){
        SegTree = new int[n*2-1];
    }

    void build(int[] arr, int[] seg, int i,int low, int high){
        if(low == high){
            seg[i] = arr[low];
            return;
        }
        int mid = low +(high - low)/2;
        build(arr, seg,2*i+1, low, mid);
        build(arr, seg,2*i+2,mid+1, high);
        seg[i] = Math.max(seg[2*i+1],seg[2*i+2]);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to build into the arrary: ");
        int n = sc.nextInt();
        System.out.println("Enter the array elements.....");
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        MaxSegTree seg1 = new MaxSegTree(n);
        seg1.build(arr, seg1.SegTree, 0, 0, n-1);
        System.out.println("The minimum element in an array: "+seg1.SegTree[0]);
        System.out.print("Enter the number of elements to insert into the arrary: ");
        int k = sc.nextInt();
        System.out.println("Enter the array elements.....");
        int[] arr1 = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        MaxSegTree seg2 = new MaxSegTree(k);
        seg1.build(arr, seg2.SegTree, 0, 0, n-1);
        System.out.println("The minimum element in an array: "+seg2.SegTree[0]);
        sc.close();
    }
}
