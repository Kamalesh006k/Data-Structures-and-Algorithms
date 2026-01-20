import java.util.*;

public class SetZeroMatrix{
    static void setZeroMatrix(int[][] arr){
        int r = arr.length;
        int c = arr[0].length;
        int row = 0, col=0;
        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){
                if(arr[i][j] == 0){
                    if(i==0 || j==0){
                        if(i==0){
                            row =1;
                        }
                        if(j == 0){
                            col=1;
                        }
                    }else{
                        arr[0][j]=0;
                        arr[i][0]=0;
                    }
                }
            }
        }
        for(int i=1; i<r; i++){
            for(int j =1; j<c; j++){
                if(arr[0][j]==0 || arr[i][0]==0){
                    arr[i][j] =0;
                }
            }
        }
        if(row == 1){
            for(int i=0; i<r; i++){
                arr[0][i] = 0;
            }
        }
        if(col == 1){
            for(int i=0; i<c; i++){
                arr[i][0] = 0;
            }
        }

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
        setZeroMatrix(arr);
        System.out.println();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();

    }
}