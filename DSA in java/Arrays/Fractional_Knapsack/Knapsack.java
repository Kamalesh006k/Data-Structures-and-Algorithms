import java.util.*;
public class Knapsack {

    static class Node{
        int items;
        int weight;

        Node(int items,int weight){
            this.items = items;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "Items: "+items+" Weight: "+weight;
        }
    }

    

    static double knapsack(Node[] pro,int k){
       Arrays.sort(pro, new Comparator<Node>() {
        @Override
        public int compare(Node a, Node b) {
            double r1 = (double) a.items / a.weight;
            double r2 = (double) b.items / b.weight;
            return Double.compare(r2, r1);
        }
    });
        double total =0;
        int i =0;
        while(i<pro.length && k>0){
            if(pro[i].weight<=k){
                k-=pro[i].weight;
                total+= pro[i].items;
            }else{
                total+=((double)pro[i].items / (double)pro[i].weight)*k;
                break;
            }
            i++;
        }
        return total;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();
        System.out.print("Enter the value of K: ");
        int k = sc.nextInt();
        Node[] pro = new Node[n];
        for(int i=0; i<n; i++){
            int items = sc.nextInt();
            int weight = sc.nextInt();
            pro[i] = new Node(items, weight);
        }

         System.out.println("The total num of items that can be stored inside that bag: "+knapsack(pro, k));

    }
}
