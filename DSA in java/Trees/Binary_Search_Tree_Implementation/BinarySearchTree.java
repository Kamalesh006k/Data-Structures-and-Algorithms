import java.util.*;

public class BinarySearchTree {

    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    static class BST {
        Node root;

        BST(Node root){
            this.root = root;
        }

        public Node insertNode(Node root, int data) {
            if (root == null) {
                return new Node(data);
            }

            if (data < root.data) {
                root.left = insertNode(root.left, data);
            } else if (data > root.data) {
                root.right = insertNode(root.right, data);
            }

            return root;
        }

        public void preOrder(Node root) {
            if (root == null) return;

            System.out.print(root.data + " ");
            preOrder(root.left);
            preOrder(root.right);
        }
        public void inOrder(Node root) {
            if (root == null) return;

            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
        public void postOrder(Node root) {
            if (root == null) return;

            postOrder(root.left);
            postOrder(root.right);
            System.out.print(root.data + " ");
        }

        public boolean findMax(Node root){
            if(root == null){
                return true;
            }

            if(findMax(root.right)){
                System.out.print(root.data);
            }

            return false;
        
        }
        public boolean findMin(Node root){
            if(root == null){
                return true;
            }

            if(findMin(root.left)){
                System.out.print(root.data);
            }

            return false;
        
        }

        void levelOrder(Node root){
            Queue<Node> q = new LinkedList<>();
            q.offer(root);
            if(q.isEmpty()){
                return;
            }
            while (!q.isEmpty()) {
                if(q.peek().left != null){
                    q.offer(q.peek().left);
                }
                if(q.peek().right != null){
                    q.offer(q.peek().right);
                }
                System.out.print(q.peek().data+" ");
                q.poll();
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BST bst = new BST(null);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            bst.root = bst.insertNode(bst.root, sc.nextInt());
        }
        String c = "y";
        while(c.equals("y")){
            System.out.print("""
                    1.Preorder Traversal
                    2.Inorder Traversal
                    3.Postorder Traversal
                    4.Levelorder Traversal
                    5.Find Maximum Element
                    6.Find Minimum Element
                    """);
            System.out.print("Enter any one option: ");
            int k = sc.nextInt();
            switch (k) {
                case 1 -> {System.out.print("Preorder Traversal: "); bst.preOrder(bst.root);}
                case 2 -> {System.out.print("Inorder Traversal: "); bst.inOrder(bst.root);}
                case 3 -> {System.out.print("Postorder Traversal: "); bst.postOrder(bst.root);}
                case 4 -> {bst.levelOrder(bst.root);}
                case 5 -> {System.out.print("Maximum Element in the BSt: "); bst.findMax(bst.root);}
                case 6 -> {System.out.print("Minimum Element in the BSt: "); bst.findMin(bst.root);}
        }
        System.out.println();
        System.out.print("Do you want to continue: y or n -> ");
        c = sc.next();
    }
}
}