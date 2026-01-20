import java.util.*;

public class MinString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String:");
        String s = sc.next();
        int n = s.length();

        List<Character> fixed = new ArrayList<>();
        int count2 = 0;

        for (char c : s.toCharArray()) {
            if (c == '2') count2++;
            else fixed.add(c);
        }

        StringBuilder ans = new StringBuilder();
        int idx = 0;

        while (idx < fixed.size()) {
            char c = fixed.get(idx);

            if (c == '3' && count2 > 0) {
                while (count2 > 0) {
                    ans.append('2');
                    count2--;
                }
            }

            ans.append(c);
            idx++;
        }

        while (count2 > 0) {
            ans.append('2');
            count2--;
        }

        System.out.println("Answer:"+ans.toString());
    }
}
