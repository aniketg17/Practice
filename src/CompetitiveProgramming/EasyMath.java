package CompetitiveProgramming;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class EasyMath {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] math = line.split("/");
        long numerator = Long.parseLong(math[0]);
        long denominator = Long.parseLong(math[1]);

        for (int i = 2; i <= Math.max(numerator, denominator); i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
            }
        }
        System.out.println(numerator + "/"+  denominator);
    }
}
