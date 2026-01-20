import java.util.*;
public class SpiralTraversals{

    static List<Integer> spiralTraversal(int n, int[][] arr){
        List<Integer> lst = new ArrayList<>();
        int rs =0 , cs =0, re = arr.length-1, ce = arr[0].length-1;
        while (rs<=re && cs<=ce) {
            for(int i=cs; i<=ce; i++){
                lst.add(arr[rs][i]);
            }
            rs++;
            for(int i=rs; i<=re; i++){
                lst.add(arr[i][ce]);
            }
            ce--;
            if(ce>=cs && re>=rs){
                for(int i=ce; i>=cs; i--){
                    lst.add(arr[re][i]);
                }
                re--;
            }
            if(re >= rs && cs<=ce){
                for(int i=re; i>=rs; i--){
                    lst.add(arr[i][cs]);
                }
                cs++;
            }
        }
        return lst;
    }
    public static void main(String[] args){
        Scanner  sc = new Scanner(System.in);
        System.out.print("Enter The dimension of the matrix:");
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        List<Integer> result = spiralTraversal(n, arr);
        System.out.println(result);
        sc.close();
    }
    
}
