import java.util.*;
public class PointUpdate {
    int[] SegTree;

    PointUpdate(int n){
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
    void pointUpdate(int[] arr, int[] seg, int i,int low, int high,int idx, int val){
        if(low == high){
            seg[i] = val;
            return;
        }
        int mid = low +(high - low)/2;
        if(idx <= mid){
            pointUpdate(arr, seg,2*i+1, low, mid,idx,val);
        }else{
            pointUpdate(arr, seg,2*i+2,mid+1, high,idx,val);
        }
        seg[i] = Math.min(seg[2*i+1],seg[2*i+2]);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert into the arrary: ");
        int n = sc.nextInt();
        System.out.print("Enter the array elements.....");
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        PointUpdate seg1 = new PointUpdate(n);
        seg1.build(arr, seg1.SegTree, 0, 0, n-1);
        System.out.print("Enter the index and value to update: ");
        int idx = sc.nextInt();
        int val = sc.nextInt();
        seg1.pointUpdate(arr, seg1.SegTree, 0, 0, n-1,idx, val);
        for(int s: seg1.SegTree){
            System.out.print(s+" ");
        }
        sc.close();
    }
}
