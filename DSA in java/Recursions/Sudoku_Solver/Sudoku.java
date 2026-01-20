import java.util.*;

public class Sudoku {

    static boolean isSafe(int[][] board, int row, int col, int num){
        for(int i = 0; i<9; i++){
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;
        }

        int r = row - row%3;
        int c = col - col%3;
        for(int  )
    }

    static boolean solve(int[][] board){
        int n = board.length;
        int m = board[0].length;

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j]==0){
                    for(int num=1; k<=9; k++){
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

    }
}
