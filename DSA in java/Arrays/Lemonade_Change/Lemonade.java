import java.util.*;
public class Lemonade {

    static boolean lemonade(int[] price){
        int count5 =0, count10 =0, count20 = 0;

        for(int i=0; i<price.length; i++){
            if(price[i] ==5){
                count5++;
            }else if(price[i] == 10){
                count10++;
                if(count5>0){
                    count5--;
                }else{
                    return false;
                }
            }else{
                if(count5>0 && count10>0){
                    count10--;
                    count5--;
                }else if(count5>3){
                    count5 -=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] price = new int[n];

        for(int i=0; i<n; i++){
            price[i] = sc.nextInt();
        }
        System.out.println(lemonade(price)?"True":"False");
    }
}
