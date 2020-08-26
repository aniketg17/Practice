package CompetitiveProgramming;

import java.util.HashMap;
import java.util.Scanner;

public class NumOfDecks {

    private static HashMap<String, Integer> deck = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numLines = sc.nextInt();
        int defaultNum = 1;
        sc.nextLine();

        for (int i = 0; i < numLines; i++) {
            String line = sc.nextLine();
            if (deck.containsKey(line)) {
                deck.replace(line, deck.get(line) + 1);
            } else {
                deck.put(line, defaultNum);
            }
        }

        System.out.println(calculateSize());

    }

    private static int calculateSize() {
        if (deck.size() == 52) {
            int min = Integer.MAX_VALUE;
            for (int x : deck.values()) {
                if (x < min) {
                    min = x;
                }
            }
            return min;
        } else {
            return 0;
        }
    }
}
