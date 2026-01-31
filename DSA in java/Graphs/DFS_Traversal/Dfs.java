import java.util.*;
public class Dfs {

    // void bfs(int v, ArrayList<ArrayList<Integer>> adj){
    //     boolean[] visited = new boolean[v+1];
    //     Arrays.fill(visited,false);
    //     List<Integer> dfs = new ArrayList<>();
    //     Queue<Integer> q = new LinkedList<>();

    //     q.add(1);
    //     while(!q.isEmpty()){
    //         int current = q.poll();
    //         visited[current] = true;
    //         dfs.add(current);

    //         for (int s : adj.get(current)) {
    //             if (!visited[s]) {
    //                 visited[s] = true;
    //                 q.add(s);
    //             }
    //         }
    //     }
    //     System.out.println(dfs);
    // }

    void dfs(int n,int idx, ArrayList<ArrayList<Integer>> adj,List<Integer> ans,boolean[] visited){
        visited[idx] = true;
        ans.add(idx);
        for(int s:adj.get(idx)){
            if(!visited[s]){
                dfs(n,s,adj,ans,visited);
            }
        }
        return;
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
        System.out.print("Enter the starting index: ");
        int st = sc.nextInt();
        for(ArrayList<Integer> s:adj){
            for(int k:s){
                System.out.print(k+" ");
            }
            System.out.println();
        }
        boolean[] visited = new boolean[n+1];
        Arrays.fill(visited, false);
        List<Integer> ans =  new ArrayList<>();
        Dfs g = new Dfs();
        g.dfs(n,st,adj,ans,visited);
        System.out.println(ans);
    }
}
