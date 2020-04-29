import java.awt.image.AreaAveragingScaleFilter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class HeightLineUp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numPpl = sc.nextInt();
        sc.nextLine();
        int[] people = new int[numPpl];
        for (int i = 0; i < numPpl; i++) {
            people[i] = sc.nextInt();
            sc.nextLine();
        }
        int[] ans = findLineup(people);
        for (int an : ans) {
            System.out.println(an);
        }
    }
    
    public static int[] findLineup(int[] people) {
        int[] answers = new int[people.length];
        Stack<Integer> heights = new Stack<>();

        int offset = 0;

        for (int i = 0; i < people.length; i++) {
            boolean found = false;
            while (!heights.isEmpty() && !found) {
                if (people[heights.peek()] >= people[i]) {
                    found = true;
                } else {
                    heights.pop();
                }
            }
            if (!heights.isEmpty()) {
               offset = heights.peek() + 1;
            } else {
                offset = 0;
            }
            answers[i] = i - offset;
            heights.push(i);
        }
        return answers;
    } 
}