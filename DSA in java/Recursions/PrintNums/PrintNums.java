import java.util.*;

class PrintNums {

    static void printnums(int i){
        if(i==0){
            return;
        }
        System.out.println(i);
        printnums(i-1);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printnums(n);
        sc.close();
    }
    
}