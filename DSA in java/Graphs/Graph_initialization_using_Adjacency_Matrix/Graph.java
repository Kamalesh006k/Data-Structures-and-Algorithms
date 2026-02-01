import java.util.*;
import java.util.Scanner;
public class Graph {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of Nodes: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of Edges: ");
        int m = sc.nextInt();
        int[][] adj = new int[n][n];
        System.out.println("Enter the val of u and v...");
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        for(int[] k: adj){
            for(int i: k){
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}