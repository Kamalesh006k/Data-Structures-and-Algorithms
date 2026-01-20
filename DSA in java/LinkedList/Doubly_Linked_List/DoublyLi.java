import java.util.*;
public class DoublyLi {
    static class Node{
        int data;
        Node next;
        Node prev;

        Node(int data){
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }
    
    static void display(Node root){
        Node temp = root;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
    static void displayReverse(Node root){
        Node temp = root;
        while(temp.next != null){
            temp = temp.next;
        }
        while (temp != null) {
            System.out.print(temp.data+" ");
            temp = temp.prev;
        }
        System.out.println();
    }
    static void delete(Node root, int data){
        Node temp = root;
        while(temp.data != data){
            temp = temp.next;
        }
        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;

    }

    static Node insert(Node root,int data){
        Node newNode = new Node(data);
        Node temp;
        if(root == null){
            root = newNode;
        }else{
            temp = root;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
        return root;
    }
    static Node insertAtFront(Node root,int data){
        Node newNode = new Node(data);
        Node temp;
        if(root == null){
            root = newNode;
        }else{
            temp = root;
            root = newNode;
            root.next = temp;
            temp.prev = root;
        }
        return root;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n = sc.nextInt();
        Node root=null;
        for(int i=1; i<=n; i++){
            System.out.print("Enter the element "+i+" : ");
            int data = sc.nextInt();
            root = insert(root, data);
        }
        System.out.println("1.Display");
        System.out.println("2.Display Reverse");
        System.out.println("3.Insert at Front");
        System.out.println("4.Insert at END");
        System.out.println("5.Delete");
        int k = 1;
        int i =0;
        while(i<k){
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
                int data = sc.nextInt();
                root = insertAtFront(root, data);
                break;
            case 4:
                System.out.print("Enter the element to insert: ");
                int data1 = sc.nextInt();
                root = insert(root, data1);
                break;
            
            case 5:
                System.out.print("Enter the element to delete: ");
                int data2 = sc.nextInt();
                delete(root, data2);
                break;
        }
        System.out.print("Do you want to contiue ? Yes or No: ");
        String c = sc.next();
        if(c.equals("Yes")){
            k += 1;
            i+=1;
        }else{
            i+=1;
        }

        }
        sc.close();
    }
}
