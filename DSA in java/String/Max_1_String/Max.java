import java.util.*;
public class Max {
    
    static int MaxString(String[] str, int k){
        int i=0,j=0, MaxLength=0,count=0,len = k;
        while(j<str.length){
            if(len<=0 && !str[j+1].equals("1")){
                i=j;
                len = k;
                MaxLength = Math.max(count,MaxLength);
                count=0;
            }
            if(str[j].equals("0") && len>0){
                str[j] = "1";
                len--;
            }
            count++;
            j++;
        }
        return MaxLength;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the String: ");
        String str = sc.next();
        System.out.println("Enter the value of k: ");
        int k = sc.nextInt();
        String[] str1 = str.split("");
        System.out.println(MaxString(str1,k));
    }
}
