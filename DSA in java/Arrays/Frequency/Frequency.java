import java.util.*;
public class Frequency {

    static void findFreq(int[] arr, int[] freq){
        int n = arr.length;
        int i=0;
        while(i<n){
            for(int j=0; j<9; j++){
                if(arr[i]==j){
                    freq[j]++;
                }
            }
            i++;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n= sc.nextInt();
        int[] arr = new int[n];
        int[] freq = new int[9];
        Arrays.fill(freq,0);
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        findFreq(arr,freq);
        System.out.print("The Frequency of each element....");
        for(int i=0; i<n; i++){
            System.out.println(arr[i]+"->"+freq[arr[i]]);
        }
    }
}
