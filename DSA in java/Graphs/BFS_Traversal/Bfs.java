import java.util.*;
public class Bfs {

    void bfs(int v, ArrayList<ArrayList<Integer>> adj){
        boolean[] visited = new boolean[v+1];
        Arrays.fill(visited,false);
        List<Integer> dfs = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        q.add(1);
        while(!q.isEmpty()){
            int current = q.poll();
            visited[current] = true;
            dfs.add(current);

            for (int s : adj.get(current)) {
                if (!visited[s]) {
                    visited[s] = true;
                    q.add(s);
                }
            }
        }
        System.out.println(dfs);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n+1);
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        System.out.print("Enter the number of edges: ");
        int m = sc.nextInt();
        System.out.println("Enter the values of u and v....");
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        for(ArrayList<Integer> s:adj){
            for(int k:s){
                System.out.print(k+" ");
            }
            System.out.println();
        }

        Bfs g = new Bfs();
        g.bfs(n, adj);
    }
}
