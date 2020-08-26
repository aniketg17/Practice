package CompetitiveProgramming;

import java.util.Arrays;

public class firstNotRepeatingCharClass {

    public static void main(String[] args) {
        String s = "ngrhhqbhnsipkcoqjyviikvxbxyphsnjpdxkhtadltsuxbfbrkof";

        System.out.println(firstNotRepeatingCharacter(s));
    }

    public static char  firstNotRepeatingCharacter(String s) {
        int[] bits = new int[26];

        Arrays.fill(bits, 0);

        for (int i = 0; i < s.length(); i++) {
            bits[(int) s.charAt(i) - 97] += 1;
        }

        for (int i = 0; i < s.length(); i++) {
            char idx = s.charAt(i);
            if (bits[(int) idx - 97] == 1) {
                return idx;
            }
        }

        return '_';
    }
}
