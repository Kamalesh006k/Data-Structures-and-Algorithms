import java.util.*;
public class Island {
    int Island =0;

    void dfs(int[][] arr, boolean[][] visited, int rs, int cs, int n, int m){
        visited[rs][cs] = true;
        for(int row=-1; row<=1; row++){
            for(int col = -1; col<=1; col++){
                int newRow = rs+row;
                int newCol = cs+col;

                if(newRow >= 0 && newCol>=0 && newRow<n && newCol<m && !visited[newRow][newCol] && arr[newRow][newCol]==1){
                    dfs(arr, visited, newRow, newCol, n, m);
                }
            }
        }
        return;
    }
    


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n and m: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        boolean[][] visited = new boolean[n][m];
        for(boolean[] a: visited){
            Arrays.fill(a, false);
        }
        Island k = new Island();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    if(!visited[i][j]){
                        count++;
                        k.dfs(arr,visited,i,j,n,m);

                    }
                }
            }
        }
        System.out.println(count);
        sc.close();
        // for(int[] s: clone){
        //     for(int i: s){
        //         System.out.println(i);
        //     }
        // }
    }
}
