import java.util.Scanner;

public class Fibonacci {

    static int fib(int n){
        if(n ==0) return 0;
        else if(n == 1) return 1;
        else return fib(n-2)+fib(n-1);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Number for Fibonacci Series: ");
        int n = sc.nextInt();
        System.out.println("The Fibonacci Series is.....");
        for(int i=0; i<n; i++){
            System.out.print(fib(i)+" ");
        }
        sc.close();
    }
}
