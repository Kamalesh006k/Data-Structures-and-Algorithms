import java.util.*;

public class Solution {
    public static void main(String[] args) {

        int pos = 5000;
        int neg = -5000;

        // ===== WIDTH ONLY =====
        System.out.printf("%5d%n", pos);
        System.out.printf("%5d%n", neg);

        // ===== ZERO PADDING =====
        System.out.printf("%05d%n", pos);
        System.out.printf("%05d%n", neg);

        // ===== LEFT ALIGN =====
        System.out.printf("%-5d%n", pos);
        System.out.printf("%-5d%n", neg);

        // ===== SIGN FLAGS =====
        System.out.printf("%+d%n", pos);
        System.out.printf("%+d%n", neg);

        System.out.printf("% d%n", pos);
        System.out.printf("% d%n", neg);

        System.out.printf("%(d%n", neg);

        // ===== GROUPING =====
        System.out.printf("%,d%n", pos);
        System.out.printf("%,d%n", neg);

        // ===== WIDTH + GROUPING =====
        System.out.printf("%,10d%n", pos);
        System.out.printf("%,10d%n", neg);

        // ===== WIDTH + ZERO + SIGN =====
        System.out.printf("%+010d%n", pos);
        System.out.printf("%+010d%n", neg);

        // ===== LEFT + SIGN =====
        System.out.printf("%+-10d%n", pos);
        System.out.printf("%+-10d%n", neg);

        // ===== GROUPING + SIGN =====
        System.out.printf("%+,d%n", pos);
        System.out.printf("%+,d%n", neg);

        // ===== GROUPING + PAREN =====
        System.out.printf("%,(d%n", neg);

        // ===== WIDTH + PAREN =====
        System.out.printf("%(10d%n", neg);

        // ===== ZERO + PAREN =====
        System.out.printf("%(010d%n", neg);

        // ===== HEX =====
        System.out.printf("%x%n", pos);
        System.out.printf("%X%n", pos);

        // ===== OCTAL =====
        System.out.printf("%o%n", pos);

        // ===== HEX WITH PREFIX =====
        System.out.printf("%#x%n", pos);
        System.out.printf("%#X%n", pos);

        // ===== OCTAL WITH PREFIX =====
        System.out.printf("%#o%n", pos);

        // ===== WIDTH + HEX =====
        System.out.printf("%10x%n", pos);

        // ===== ZERO + HEX =====
        System.out.printf("%010x%n", pos);

        // ===== CHAR FORMAT =====
        System.out.printf("%c%n", 65);

        // ===== STRING WIDTH =====
        System.out.printf("%10s%n", "Java");
        System.out.printf("%-10s%n", "Java");

        // ===== FLOAT =====
        double d = 1234.56789;

        System.out.printf("%f%n", d);
        System.out.printf("%.2f%n", d);
        System.out.printf("%10.2f%n", d);
        System.out.printf("%-10.2f%n", d);
        System.out.printf("%+10.2f%n", d);
        System.out.printf("%,10.2f%n", d);

        // ===== SCIENTIFIC =====
        System.out.printf("%e%n", d);
        System.out.printf("%E%n", d);

        // ===== GENERAL =====
        System.out.printf("%g%n", d);
        System.out.printf("%G%n", d);

        // ===== BOOLEAN =====
        System.out.printf("%b%n", true);
        System.out.printf("%B%n", false);

        // ===== HASH CODE =====
        System.out.printf("%h%n", pos);

        // ===== NEWLINE =====
        System.out.printf("Hello%nWorld%n");

        // ===== PERCENT =====
        System.out.printf("Success: 100%% %n");
    }
}