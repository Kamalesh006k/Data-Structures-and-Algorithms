import java.util.*;

public class CircularDoubleLi {

    static class Node {
        int data;
        Node next;
        Node prev;

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

    static void displayReverse(Node root) {
        if (root == null) return;

        Node temp = root.prev;
        Node last = temp;

        System.out.print(temp.data + " ");
        temp = temp.prev;

        while (temp != last) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }

    static Node insert(Node root, int data) {
        Node newNode = new Node(data);

        if (root == null) {
            root = newNode;
            newNode.next = newNode;
            newNode.prev = newNode;
        } else {
            Node temp = root;
            while (temp.next != root) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
            newNode.next = root;
            root.prev = newNode;
        }
        return root;
    }

    static Node insertAtFront(Node root, int data) {
        Node newNode = new Node(data);

        if (root == null) {
            root = newNode;
            newNode.next = newNode;
            newNode.prev = newNode;
        } else {
            Node last = root.prev;
            newNode.next = root;
            newNode.prev = last;
            last.next = newNode;
            root.prev = newNode;
            root = newNode;
        }
        return root;
    }

    static Node delete(Node root, int data) {
        if (root == null) return null;

        Node temp = root;

        while (temp.data != data) {
            temp = temp.next;
            if (temp == root) {
                System.out.println("Element not found");
                return root;
            }
        }

        if (temp.next == temp) {
            return null;
        }

        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;

        if (temp == root) {
            root = temp.next;
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
        System.out.println("2.Display Reverse");
        System.out.println("3.Insert at Front");
        System.out.println("4.Insert at END");
        System.out.println("5.Delete");

        int k = 1, i = 0;

        while (i < k) {
            System.out.print("Enter the option: ");
            int o = sc.nextInt();

            switch (o) {
                case 1:
                    display(root);
                    break;
                case 2:
                    displayReverse(root);
                    break;
                case 3:
                    System.out.print("Enter the element to insert: ");
                    root = insertAtFront(root, sc.nextInt());
                    break;
                case 4:
                    System.out.print("Enter the element to insert: ");
                    root = insert(root, sc.nextInt());
                    break;
                case 5:
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
