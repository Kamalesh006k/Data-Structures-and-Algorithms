import java.util.*;
public class Flooffill {

    static void fillColor(int srow, int scol, int[][] arr, boolean[][] visited,int newColor){
        int initCol = arr[srow][scol];
        arr[srow][scol] = newColor;
        visited[srow][scol] = true;

        int[] delr = {-1,0,1,0};
        int[] delc = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int newRow = srow + delr[i];
            int newCol = scol + delc[i];
            if(newRow >=0 && newRow<arr.length && newCol>=0 && newCol<arr[0].length && arr[newRow][newCol] == initCol && !visited[newRow][newCol]){
                fillColor(newRow, newCol, arr, visited, newColor);
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows and cols: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        System.out.println("Enter the image......");
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.print("Enter the Source row and col: ");
        int srow = sc.nextInt();
        int scol = sc.nextInt();
        System.out.print("Enter the new color to fill with: ");
        int newColor = sc.nextInt();
        fillColor(srow,scol,arr,visited,newColor);
        System.out.println("The image after colored...");
        for(int[] a:arr){
            for(int s:a){
                System.out.print(s+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}