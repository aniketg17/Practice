import java.awt.image.AreaAveragingScaleFilter;
import java.util.ArrayList;
import java.util.Scanner;

public class HeightLineUp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numPpl = sc.nextInt();
        sc.nextLine();
        int[] answers = new int[numPpl];
        int[] people = new int[numPpl];
        for (int i = 0; i < numPpl; i++) {
            people[i] = sc.nextInt();
            sc.nextLine();
        }

        int start = 0;
        int end;

        answers[0] = 0;

        for (end = 1; end < numPpl; end++) {
            if (people[end] <= people[start]) {
                answers[end] = 0;
                start++;
            } else {
                int count = 0;
                for (; start >= 0 && people[start] < people[end]; start--) {
                    count += 1;
                }
                answers[end] = count;
                start = end;
            }
        }

        for (int x : answers) {
            System.out.println(x);
        }
    }
}