import java.util.Arrays;
import java.util.Scanner;

public class ChainReaction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numBalloons = sc.nextInt();
        sc.nextLine();
        int[] balloons = new int[numBalloons];
        for (int i = 0; i < balloons.length; i++) {
            balloons[i] = sc.nextInt();
            sc.nextLine();
        }

        Arrays.sort(balloons);
        int max = -10;
        for (int idx = 0; idx < balloons.length; idx++) {
            int[] copied = Arrays.copyOf(balloons, balloons.length);
            int popped = pop(idx, copied);
            max = Math.max(max, popped);
        }
        System.out.println(max);
    }

    private static int pop(int idx, int[] balloons) {
        int radius = 1;
        int start = balloons[idx];
        int temp = start;
        int balloonsBurst = 1;
        balloons[idx] = -10;
        int i = idx + 1;
        int prev = 0;
        boolean burst;
        while (i < balloons.length) {
            burst = false;
            while (i < balloons.length && balloons[i] - start <= radius) {
                prev = balloons[i];
                balloons[i] = -10;
                ++balloonsBurst;
                ++i;
                burst = true;
            }
            if (!burst) {
                break;
            }
            start = prev;
            ++radius;
        }

        start = temp;
        radius = 1;
        i = idx - 1;

        while (i >= 0) {
            burst = false;
            while (i >= 0 && start - balloons[i] <= radius) {
                prev = balloons[i];
                balloons[i] = -10;
                ++balloonsBurst;
                --i;
                burst = true;
            }
            if (!burst) {
                break;
            }
            start = prev;
            ++radius;
        }

        return balloonsBurst;
    }

}
