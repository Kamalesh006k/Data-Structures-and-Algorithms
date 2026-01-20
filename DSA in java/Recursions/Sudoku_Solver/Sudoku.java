import java.util.*;

public class Sudoku {

    static boolean isSafe(int[][] board, int row, int col, int num){
        for(int i = 0; i<9; i++){
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;
        }

        int r = row - row%3;
        int c = col - col%3;
        for(int i=r; i<3; i++){
            for(int j=c; j<3; j++){
                if(board[i][j] == num){
                    return false;
                }
            }
        }
        return true;
    }

    static boolean solve(int[][] board){
        int n = board.length;
        int m = board[0].length;

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j]==0){
                    for(int num=1; num<=9; num++){
                        if(isSafe(board,i,j,num)){
                            board[i][j] = num;

                            if(solve(board)){
                                return true;
                            }

                            board[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
        int[][] board = new int[9][9];
        System.out.println("Enter Your Puzzel Below ....");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        if(solve(board)){
            System.out.println("Puzzel solved.....");
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        }else{
            System.out.print("Answer does not exist");
        }
        sc.close();
    }
}
