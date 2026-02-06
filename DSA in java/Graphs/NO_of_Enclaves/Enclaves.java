import java.util.*;
public class Enclaves {

    static int enclaves(int sr, int sc, boolean corner,int count, int[][] arr, boolean[][] visited){
        if(corner){
            visited[sr][sc] = true;
        }else{
            visited[sr][sc] = true;
            count++;
        }

        int[] delr = {-1,0,1,0};
        int[] delc = {0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int newRow = sr + delr[i];
            int newCol = sc + delc[i];

            if(newRow>=0 && newRow<arr.length && newCol>=0 && newCol<arr[0].length && !visited[newRow][newCol] && arr[newRow][newCol] == 1 && arr[sr][sc] == 1){
                count = enclaves(newRow, newCol, corner,count, arr, visited);
            }

        }
        return count;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the num of r and c: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        boolean[][] visited = new boolean[n][m];
        int ans =0;
        int count =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i== n-1|| j==m-1)&& arr[i][j] == 1){
                    enclaves(i,j,true,count,arr,visited);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && arr[i][j] ==1){
                    ans=enclaves(i,j,false,count,arr,visited);
                }
            }
        }

        System.out.println("The number of enclaves: "+ans);
        sc.close();
    }
}
