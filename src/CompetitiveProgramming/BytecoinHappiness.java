package CompetitiveProgramming;

import java.util.ArrayList;
import java.util.Scanner;

public class BytecoinHappiness {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long numOfInput = sc.nextLong();
        sc.nextLine();
        ArrayList<Long> arrayList = new ArrayList<>();
        for (int i = 0; i < numOfInput; i++) {
            long input = sc.nextLong();
            arrayList.add(input);
        }

        long happiness =  0;

        for (int i = 0; i < arrayList.size() - 1; i++) {
            if (arrayList.get(i + 1) > arrayList.get(i)) {
                long difference = (arrayList.get(i+1) - arrayList.get(i));
                happiness += square(difference);
            } else {
                long difference = arrayList.get(i) - arrayList.get(i + 1);
                happiness -= cube(difference);
            }

        }

        long HappinessLong = happiness;

        long happinessHolder = HappinessLong;

        long maxHappiness = Long.MIN_VALUE;

        for (int i = 1; i < arrayList.size() - 1; i++) {
            if (arrayList.get(i) > arrayList.get(i-1)) {  // removing the link between i and i-1
                long difference = (arrayList.get(i) - arrayList.get(i - 1));
                HappinessLong -= square(difference);
            } else {
                long difference = (arrayList.get(i - 1) - arrayList.get(i));
                HappinessLong += cube(difference);
            }

            if (arrayList.get(i+1) > arrayList.get(i)) { // removing the link between i and i+1
                long differnce = (arrayList.get(i+1) - arrayList.get(i));
                HappinessLong -= square(differnce);
            } else {
                long differnce = (arrayList.get(i) - arrayList.get(i + 1));
                HappinessLong += cube(differnce);
            }

            if (arrayList.get(i+1) > arrayList.get(i-1)) { // linking i-1 and i+1
                long differnce = (arrayList.get(i+1) - arrayList.get(i-1));
                HappinessLong += square(differnce);
            } else {
                long difference = arrayList.get(i-1) - arrayList.get(i + 1);
                HappinessLong -= cube(difference);
            }

            maxHappiness = Long.max(HappinessLong, maxHappiness);

            HappinessLong = happinessHolder;

        }

        System.out.println(maxHappiness);

    }

    private static long cube(long x) {
        return x*x*x;
    }

    private static long square(long x) {
        return x*x;
    }
}

