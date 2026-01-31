import java.util.*;
public class Provinces {

    // void bfs(int v, ArrayList<ArrayList<Integer>> adj){
    //     boolean[] visited = new boolean[v+1];
    //     Arrays.fill(visited,false);
    //     List<Integer> Provinces = new ArrayList<>();
    //     Queue<Integer> q = new LinkedList<>();

    //     q.add(1);
    //     while(!q.isEmpty()){
    //         int current = q.poll();
    //         visited[current] = true;
    //         Provinces.add(current);

    //         for (int s : adj.get(current)) {
    //             if (!visited[s]) {
    //                 visited[s] = true;
    //                 q.add(s);
    //             }
    //         }
    //     }
    //     System.out.println(Provinces);
    // }

    void provinces(int n,int idx, ArrayList<ArrayList<Integer>> adj,List<Integer> ans,boolean[] visited){
        visited[idx] = true;
        ans.add(idx);
        for(int s:adj.get(idx)){
            if(!visited[s]){
                provinces(n,s,adj,ans,visited);
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
        System.out.println("The adjacency List....");
        for(ArrayList<Integer> s:adj){
            for(int k:s){
                System.out.print(k+" ");
            }
            System.out.println();
        }
        boolean[] visited = new boolean[n+1];
        Arrays.fill(visited, false);
        List<Integer> ans =  new ArrayList<>();
        Provinces g = new Provinces();
        int count =0;
        for(int i=st; i<=n; i++){
            if(!visited[i]){
                g.provinces(n,i,adj,ans,visited);
                count++;
            }
        }
        System.out.println("The number of provinces: "+count);
    }
}
