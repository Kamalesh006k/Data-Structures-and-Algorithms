import java.util.*;
public class Rainwater {

    static int rainwater(int[] arr){
        int i=0, j=arr.length-1, totalTrapped =0;
        int imax =0, jmax =0;
        while(i<=j){
            if(arr[i]<arr[j]){
                if(imax<arr[i]){
                    imax = arr[i];
                }else{
                    totalTrapped += imax - arr[i];
                }
                i++;
            }else{
                if(jmax<arr[j]){
                    jmax = arr[j];
                }else{
                    totalTrapped += jmax - arr[j];
                }
                j--;
            }
        }
        return totalTrapped;
    } 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the num of element of the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the Array Elements.....");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
                
        }
        System.out.println("The total Rain water Trapped: "+rainwater(arr));
    }
}
