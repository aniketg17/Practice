package CP2;

import java.util.Arrays;
import java.util.Scanner;

public class PossiblePivots {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] min = new int[n];
        int[] max = new int[n];
        int[] vals = Arrays.stream(sc.nextLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
        int minima = Integer.MAX_VALUE;
        int maxima = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxima = Math.max(maxima, vals[i]);
            max[i] = maxima;
        }
        for (int i = n - 1; i >= 0; i--) {
            minima = Math.min(minima, vals[i]);
            min[i] = minima;
        }
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (min[i+1] >= vals[i]) {
                    ++counter;
                }
            }
            else if (i == n-1) {
                if (max[i-1] <= vals[i]) {
                    ++counter;
                }
            }
            else if (vals[i] >= max[i-1] && vals[i] <= min[i+1]) {
                ++counter;
            }
        }
        System.out.println(counter);
    }
}
