import java.util.*;
public class StackImplementation {
    static public class Stack{
        int[] arr;
        int top = -1;

        Stack(int n){
           this.arr = new int[n];
        }

        void push(int data) {
            if (top == arr.length - 1) {
                System.out.print("Stack overflow....");
            } else {
                top += 1;
                arr[top] = data;
            }
        }

        void pop() {
            if(top == -1){
                System.out.print("Stack underflow...");
            }else top -= 1;
        }

        void peek(){
            System.out.println(arr[top]);
        }

        void display(){
            for(int i = top; i>=0; i--){
                System.out.print(arr[i]+" ");
            }
        }
    }

    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of Elements to insert in the stack: ");
        int n = sc.nextInt();
        Stack st = new Stack(n);
        System.out.println("Enter the Elements...");
        for(int i=0; i<n; i++){
            st.push(sc.nextInt());
        }
        int k = 1;
        while(k == 1){
            System.out.println("1.POP the Element.");
            System.out.println("2.Display the Top most element of the stack.");
            System.out.println("3.Display all the Elements from the top of the stack.");
            System.out.println("4.Push into Stack.");

            System.out.print("Enter your option:");
            int j = sc.nextInt();

            switch (j) {
                case 1:
                    st.pop();
                    break;
                case 2:
                    st.peek();
                    break;
                case 3:
                    st.display();
                    break;
                case 4:
                    System.out.print("Enter the data to push: ");
                    int data = sc.nextInt();
                    st.push(data);
                    break;
            }
            System.out.println();
            System.out.print("Do you want to continue: y or n ->");
            String op = sc.next();
            if(!op.equals("y")){
                k = 0;
            }
        }
        sc.close();
    }
}
