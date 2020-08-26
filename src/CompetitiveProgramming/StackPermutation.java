package CompetitiveProgramming;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class StackPermutation {
    public static void main(String[] args) {
        Queue<Integer> permutationNo = new LinkedList<>();
        permutationNo.add(1);
        permutationNo.add(5);
        permutationNo.add(3);
        permutationNo.add(4);
        permutationNo.add(2);
        permutationNo.add(6);

        Queue<Integer> permutationYes = new LinkedList<>();
        permutationYes.add(1);
        permutationYes.add(3);
        permutationYes.add(4);
        permutationYes.add(2);
        permutationYes.add(5);
        permutationYes.add(6);

        System.out.println(isStackPermutation(6, permutationNo));
    }

    public static boolean isStackPermutation(int maxNum, Queue<Integer> permutation) {
        assert permutation != null;

        Queue<Integer> originalList = new LinkedList<>();
        Stack<Integer> manipulation = new Stack<>();

        for (int i = 1; i <= maxNum; i++) {
            originalList.add(i);
        }

        if (permutation.size() != originalList.size()) return false;

        while (!originalList.isEmpty()) {
            int originalVal = originalList.peek();
            int permutationVal = permutation.peek();

            if (permutationVal == originalVal) {
                originalList.remove();
                permutation.remove();
            } else {
                if (!manipulation.isEmpty() && manipulation.peek() == permutationVal) {
                    manipulation.pop();
                    permutation.remove();
                } else {
                    manipulation.push(originalVal);
                    originalList.remove();
                }
            }
        }

        return permutation.isEmpty();
    }
}
