import java.util.*;

class BackTrack{

    static void printnums(int i){
        if(i==0){
            return;
        }
        printnums(i-1);
        System.out.println(i);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printnums(n);
        sc.close();
    }
    
}