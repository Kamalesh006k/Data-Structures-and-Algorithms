import java.util.*;
public class Rotten {

    static int rotten(int[][] arr, boolean[][] visited){
        Queue<int[]> q = new LinkedList<>();
        int countFresh = 0;
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                if(arr[i][j] == 2){
                    q.add(new int[]{i,j,0});
                }else if(arr[i][j] == 1){
                    countFresh++;
                }
            }
        }
        int time = 0;
        int rot =0;
        while(!q.isEmpty()){
            int a = q.peek()[0];
            int b = q.peek()[1];
            int tm = q.peek()[2];
            visited[a][b] = true;
            q.poll();

            int[] delr = {-1,0,1,0};
            int[] delc = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newRow = a+delr[i];
                int newCol = b+delc[i];

                if(newCol>=0 && newCol<arr[0].length && newRow>=0 && newRow<arr.length && !visited[newRow][newCol]&& arr[newRow][newCol] == 1){
                    rot++;
                    q.add(new int[]{newRow,newCol,tm+1});
                    visited[newRow][newCol] = true;
                    arr[newRow][newCol] = 2;
                }
            }
            time = Math.max(time,tm);
        }
        if(rot == countFresh) return time;
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the row and col: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.println(rotten(arr,visited));
    }
}
