import java.util.*;
public class BinaryTree {

    public static class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data = data;
            left = null;
            right = null;
        }
    }

    public static class BT{
        Node root;
        
        BT(Node root){
            this.root = root;
        }

        public void insert(int data){
            Node newNode = new Node(data);
            
            if(root == null){
                root = newNode;
            }else{
                Queue<Node> q = new LinkedList<>();
                q.offer(root);
                while(!q.isEmpty()){
                    if(q.peek().left == null){
                        q.peek().left = newNode;
                        return;
                    }else{
                        q.offer(q.peek().left);
                    }
                    if(q.peek().right == null){
                        q.peek().right = newNode;
                        return;
                    }else{
                        q.offer(q.peek().right);
                    }
                    q.poll();
                }
            }
        }

        public void PreOrder(Node root){
            if(root == null){
                return;
            }
            System.out.print(root.data+" ");
            PreOrder(root.left);
            PreOrder(root.right);
        }
        public void InOrder(Node root){
            if(root == null){
                return;
            }
            InOrder(root.left);
            System.out.print(root.data+" ");
            InOrder(root.right);
        }
        public void PostOrder(Node root){
            if(root == null){
                return;
            }
            PostOrder(root.left);
            PostOrder(root.right);
            System.out.print(root.data+" ");
        }
        public void LevelOrderTraversal(Node root){
            List<List<Integer>> ans = new ArrayList<>();
            Queue<Node> q = new LinkedList<>();
            if(root == null){
                System.out.print("Tree is Empty");
                return;
            }
            q.offer(root);
            while (!q.isEmpty()) {
                List<Integer> subList = new ArrayList<>();
                int n = q.size();
                for(int i=0; i<n; i++){
                    if(q.peek().left != null){
                        q.offer(q.peek().left);
                    }
                    if(q.peek().right != null){
                        q.offer(q.peek().right);
                    }
                    subList.add(q.peek().data);
                    q.poll();
                }
                ans.add(new ArrayList<>(subList));
            }
            System.out.print(ans);
        }

        public Node binarysorting(Node root){
            List<Integer> lst = new ArrayList<>();
            Queue<Node> q = new LinkedList<>();
            if(root == null){
                System.out.print("Tree is Empty");
                return root;
            }
            q.offer(root);
            while (!q.isEmpty()) {
                if (q.peek().left != null) {
                    q.offer(q.peek().left);
                }
                if (q.peek().right != null) {
                    q.offer(q.peek().right);
                }
                lst.add(q.peek().data);
                q.poll();
            }

            lst.sort(Comparator.naturalOrder());
            BT bts = new BT(null);
            int n = lst.size();
            int i =0;
            while(i<n){
                bts.insert(lst.getFirst());
                lst.removeFirst();
                i++;
            }

            bts.LevelOrderTraversal(bts.root);
            return bts.root;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        BT bt = new BT(null);
        int n = sc.nextInt();
        System.out.println("Enter the Elements to Insert....");
        for(int i=0; i<n; i++){
            bt.insert(sc.nextInt());
        }
        String c = "y";
        while (c.equals("y")) {
            System.out.print("""
                    1.Preorder Traversal
                    2.Inorder Traversal
                    3.Postorder Traversal
                    4.Level Order traversal
                    5.Binary Tree Sorting
                    """);
            int k = sc.nextInt();
            switch (k) {
                case 1 -> bt.PreOrder(bt.root);
                case 2 -> bt.InOrder(bt.root);
                case 3 -> bt.PostOrder(bt.root);
                case 4 -> bt.LevelOrderTraversal(bt.root);
                case 5 -> bt.root = bt.binarysorting(bt.root);
            }
            System.out.println();
            System.out.print("Do you want to continue : y or n -> ");
            c = sc.next();

        }
        sc.close();
    }
}
