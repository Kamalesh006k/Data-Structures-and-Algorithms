import java.util.*;

public class SingleLi {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static void display(Node root) {
        Node temp = root;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    static void delete(Node root, int data) {
        Node temp = root;
        while (temp.next.data != data) {
            temp = temp.next;
        }
        temp.next = temp.next.next;
    }

    static Node insert(Node root, int data) {
        Node newNode = new Node(data);
        Node temp;

        if (root == null) {
            root = newNode;
        } else {
            temp = root;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
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
            int data = sc.nextInt();
            root = insert(root, data);
        }

        System.out.println("1.Display");
        System.out.println("2.Insert at END");
        System.out.println("3.Delete");

        int k = 1;
        int i = 0;

        while (i < k) {
            System.out.print("Enter the option: ");
            int o = sc.nextInt();

            switch (o) {
                case 1:
                    display(root);
                    break;

                case 2:
                    System.out.print("Enter the element to insert: ");
                    int data1 = sc.nextInt();
                    root = insert(root, data1);
                    break;

                case 3:
                    System.out.print("Enter the element to delete: ");
                    int data2 = sc.nextInt();
                    delete(root, data2);
                    break;
            }

            System.out.print("Do you want to continue ? Yes or No: ");
            String c = sc.next();

            if (c.equals("Yes")) {
                k += 1;
                i += 1;
            } else {
                i += 1;
            }
        }

        sc.close();
    }
}
