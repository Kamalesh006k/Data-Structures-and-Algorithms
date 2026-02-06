import java.util.*;
public class Cycle {

    static boolean findCycle(int i, ArrayList<ArrayList<Integer>> adj, boolean[] visited){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i,-1});
        visited[i] = true;
        while (!q.isEmpty()) {
            for(int s: adj.get(q.peek()[0])){
                if(!visited[s]){
                    visited[s] = true;
                    q.add(new int[]{s,q.peek()[0]});
                }else{
                    if(q.peek()[1] != s) return true;
                }
            }
            q.poll();
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the num of nodes and edges: ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[] visited = new boolean[n+1];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++){
            adj.add(new ArrayList<>());
        }
        System.out.println("Enter the Edges....");
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        boolean cycle = false;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (findCycle(i, adj, visited)) {
                    cycle = true;
                    break;
                }
            }
        }

        System.out.println(cycle ? "Cycle Detected" : "No Cycle");
    }
}
