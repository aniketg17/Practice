import java.util.Arrays;
import java.util.Scanner;

/*
Chain Reaction is a game of choice. It takes in N integers, these integers are the location of ballons on the number line.
The aim of the game is to choose the best start point that results in the maximum number of balloon bursts. The rules are as follows:

You can only choose one balloon to hit. This hit will start the chain reaction.
After the initial hit, the balloons that are at a distance of 1 from that first ballon will burst,
this means if you hit the balloon at location 7, balloons at 6 and 8 (if they are in the there) will burst.
The balloons that burst at time 2 will cause the balloons that are within a distance of 2 from them to burst.
After this, the balloons that burst at time 3 will cause the balloons within a distance of 3 from them to burst and so on.
In general terms, at time t a set of balloons will burst, each of these bursts will cause the balloons at a distance
of t from them to burst at time t+1 and affect balloons that are within a distance of t+1, and so on.

Input Format
The first line of input contains N. The number of balloons. The remaining N lines all contain integers. These integers are the location of the balloons.

Constraints
(1≤N≤100) The locations are in the range [0,1000000000]

Output Format
Output the max number of balloons that will burst when the first hit is optimal.
 */

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
        for (int idx = 0; idx < balloons.length; idx++) { // attempt to pop first balloon at each position
            int[] copied = Arrays.copyOf(balloons, balloons.length);
            int popped = pop(idx, copied);
            max = Math.max(max, popped);
        }
        System.out.println(max);
    }

    private static int pop(int idx, int[] balloons) {
        int radius = 1;
        int start = balloons[idx]; // starting balloon
        int temp = start; // temp variable to store value for second loop
        int balloonsBurst = 1;
        balloons[idx] = -10;
        int i = idx + 1;
        int prev = 0;
        boolean burst; // boolean to check if balloon burst in 1 iteration or not. if not, then break

        while (i < balloons.length) {
            burst = false;
            while (i < balloons.length && balloons[i] - start <= radius) {
                prev = balloons[i]; // storing current variable because the array value gets changed in next line
                balloons[i] = -10;
                ++balloonsBurst;
                ++i;
                burst = true;
            }
            if (!burst) {
                break;
            }
            start = prev; // assigning last popped balloon's value
            ++radius;
        }

        // resetting variables
        start = temp;
        radius = 1;
        i = idx - 1;

        // repeating process but now decrementing pointer
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
