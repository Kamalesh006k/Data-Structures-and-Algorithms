import java.util.*;

public class DiagonalTraversal {
    static int[] diagonalTraversal(int n, int[][] arr){
        int[] ans = new int[n*n];
        int i=0;
        int dir=1;
        int row =0;
        int col =0;
        int rowEnd = arr.length-1;
        int colEnd = arr[0].length-1;
        while(i< n*n){
            if(dir == 1){
                if(col >= colEnd && row<rowEnd){
                    ans[i++] = arr[row][col];
                    row++;
                    dir=0;
                }else if(row <=0 && col<=colEnd){
                    ans[i++] = arr[row][col];
                    col++;
                    dir=0;
                }else{
                    ans[i++] = arr[row][col];
                    row--;
                    col++;
                }
            }else{
                if(row >= rowEnd && col<colEnd){
                    ans[i++] = arr[row][col];
                    col++;
                    dir = 1;
                }else if(row<rowEnd && col <= 0){
                    ans[i++] = arr[row][col];
                    row++;
                    dir = 1;
                }else{
                    ans[i++] = arr[row][col];
                    row++;
                    col--;

                }

            }
        }
        return ans;
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
        int[] result = diagonalTraversal(n, arr);
        for(int i : result){
            System.out.print(i+" ");
        }
        sc.close();
    }
}
