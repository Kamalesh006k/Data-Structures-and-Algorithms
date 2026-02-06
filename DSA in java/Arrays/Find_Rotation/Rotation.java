import java.util.*;
public class Rotation {

    static boolean isRotatedArray(int[] arr1, int[] arr2) {

        if (arr1.length != arr2.length)
            return false;

        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for (int x : arr1)
            s1.append("#"+x);
        for (int x : arr2)
            s2.append("#").append(x);

        String temp = s1.toString() + s1.toString();

        return temp.contains(s2.toString());
    }

    public static void main(String[] args) {
        Scanner sc = new  Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        System.out.println("Enter the first Array elements....");
        for(int i=0; i<n; i++){
            arr1[i] = sc.nextInt();
        }
        System.out.println("Enter the second Array elements....");
        for(int i=0; i<n; i++){
            arr2[i] = sc.nextInt();
        }

        System.out.println(isRotatedArray(arr1, arr2)?"YES":"NO");
    }
}
