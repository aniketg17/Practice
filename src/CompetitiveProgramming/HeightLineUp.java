package CompetitiveProgramming;

import java.awt.image.AreaAveragingScaleFilter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;


/*
    Find number of people shorter than the current student
    behind him for each student and then output and then
    output as an array.
    Constraint: O(n)
 */





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
        Stack<Integer> heights = new Stack<>();
        int[] answer = new int[people.length];

        for (int i = 0; i < people.length; i++) {
            while (!heights.isEmpty()) {
                if (people[heights.peek()] >= people[i]) {
                    break;
                } else {
                    heights.pop();
                }
            }
            if (heights.isEmpty()) {
                answer[i] = i;
            } else {
                answer[i] = i - heights.peek() - 1;
            }
            heights.push(i);
        }
        return answer;
    } 
}