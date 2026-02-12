import java.util.*;
class Game {
    static void game(int sr, int sc ,boolean corner, char[][] arr, boolean[][] visited){
        
        if(corner){
            visited[sr][sc] = true;
        }else{
            visited[sr][sc] = true;
            arr[sr][sc] = 'X';
        }

        int[] delr = {-1,0,1,0};
        int[] delc = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int newRow = sr + delr[i];
            int newCol = sc+delc[i];

            if(newRow>=0 && newRow<arr.length && newCol>=0 && newCol<arr[0].length && !visited[newRow][newCol] && arr[newRow][newCol] == 'O'){
                game(newRow,newCol,corner,arr,visited);
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of r and c: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] arr = new char[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = sc.next().charAt(0);
            }
        }

        boolean[][] visited = new boolean[n][m];
        
        //checking corder element

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(arr[i][j] == 'O'){
                        game(i,j,true,arr,visited);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 'O' && !visited[i][j]) {
                    arr[i][j] = 'X';
                }
            }
        }

        System.out.println();

        for(char[] s:arr){
            for(char c:s){
                System.out.print(c+" ");
            }
            System.err.println();
        }
    }
}