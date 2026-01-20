import java.util.*;

public class CircularSingleLi {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    static void display(Node root) {
        if (root == null) return;

        Node temp = root;
        System.out.print(temp.data + " ");
        temp = temp.next;

        while (temp != root) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    static Node insert(Node root, int data) {
        Node newNode = new Node(data);

        if (root == null) {
            root = newNode;
            newNode.next = newNode;
        } else {
            Node temp = root;
            while (temp.next != root) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = root;
        }
        return root;
    }

    static Node insertAtFront(Node root, int data) {
        Node newNode = new Node(data);

        if (root == null) {
            root = newNode;
            newNode.next = newNode;
        } else {
            Node temp = root;
            while (temp.next != root) {
                temp = temp.next;
            }
            newNode.next = root;
            temp.next = newNode;
            root = newNode;
        }
        return root;
    }

    static Node delete(Node root, int data) {
        if (root == null) return null;

        Node curr = root;
        Node prev = null;

        while (curr.data != data) {
            prev = curr;
            curr = curr.next;
            if (curr == root) {
                System.out.println("Element not found");
                return root;
            }
        }

        if (curr.next == curr) {
            return null;
        }

        if (curr == root) {
            Node temp = root;
            while (temp.next != root) {
                temp = temp.next;
            }
            root = root.next;
            temp.next = root;
        } else {
            prev.next = curr.next;
        }

        return root;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n = sc.nextInt();

        Node root = null;
        for (int i = 1; i <= n; i++) {
            System.out.print("Enter the element " + i + " : ");
            root = insert(root, sc.nextInt());
        }

        System.out.println("1.Display");
        System.out.println("2.Insert at Front");
        System.out.println("3.Insert at END");
        System.out.println("4.Delete");

        int k = 1, i = 0;

        while (i < k) {
            System.out.print("Enter the option: ");
            int o = sc.nextInt();

            switch (o) {
                case 1:
                    display(root);
                    break;
                case 2:
                    System.out.print("Enter the element to insert: ");
                    root = insertAtFront(root, sc.nextInt());
                    break;
                case 3:
                    System.out.print("Enter the element to insert: ");
                    root = insert(root, sc.nextInt());
                    break;
                case 4:
                    System.out.print("Enter the element to delete: ");
                    root = delete(root, sc.nextInt());
                    break;
            }

            System.out.print("Do you want to continue ? Yes or No: ");
            String c = sc.next();
            if (c.equals("Yes")) {
                k++;
                i++;
            } else {
                i++;
            }
        }
        sc.close();
    }
}
