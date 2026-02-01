import java.util.*;
public class RangeQueries {
    int[] SegTree;

    RangeQueries(int n){
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
        seg[i] = Math.min(seg[2*i+1],seg[2*i+2]);
    }

    int rangeQuery(int[] arr, int[] seg, int i, int low, int high, int l, int r){
        if(low>=l && high<=r){
            return seg[i];
        }
        if(high<l || low>r){
            return Integer.MAX_VALUE;
        }
        int mid = low+(high-low)/2;
        int left = rangeQuery(arr, seg, 2*i+1, low, mid, l, r);
        int right = rangeQuery(arr, seg, 2*i+2, mid+1, high, l, r);
        return Math.min(left,right);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert into the arrary: ");
        int n = sc.nextInt();
        System.out.println("Enter the array elements.....");
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        RangeQueries rq = new RangeQueries(n);
        rq.build(arr, rq.SegTree, 0, 0, n-1);
        System.out.println("Enter the left range value: ");
        int l = sc.nextInt();
        System.out.println("Enter the right range value: ");
        int r = sc.nextInt();
        int min = rq.rangeQuery(arr,rq.SegTree,0,0,n-1,l,r);
        System.out.println("The minimum element in the given range: "+min);
        sc.close();
    }
}
