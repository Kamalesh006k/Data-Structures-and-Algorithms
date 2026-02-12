import java.util.*;
public class Distance {
    static void distance(int[][] arr,int[][] ans, boolean[][] visited){
        Queue<int[]> q = new LinkedList<>();
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                if(arr[i][j] == 1){
                    q.add(new int[]{i,j,0});
                }
            }
        }
        int[] delr = {-1,0,1,0};
        int[] delc = {0,1,0,-1};
        while(!q.isEmpty()){
            int r = q.peek()[0];
            int c = q.peek()[1];
            int tm = q.peek()[2];
            visited[r][c] = true;
            ans[r][c] = tm;
            q.poll();

            for(int i=0; i<4; i++){
                int newRow = r + delr[i];
                int newCol = c + delc[i];

                if(newRow>=0 && newRow<arr.length && newCol>=0 && newCol<arr[0].length && arr[newRow][newCol] == 0 && !visited[newRow][newCol]){
                    q.add(new int[]{newRow,newCol,tm+1});
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of r and c: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] =  sc.nextInt();
            }
        }
        boolean[][] visited = new boolean[n][m];
        int[][] ans = new int[n][m];
        for(int[] k:ans){
            Arrays.fill(k, -1);
        }
        distance(arr,ans,visited);
        for(int[] s: ans){
            for(int a: s){
                System.out.print(a+" ");
            }
            System.out.println();
        }
    }
}
