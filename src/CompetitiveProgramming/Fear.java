package CompetitiveProgramming;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Fear {

    private static String[][] grid;
    private static boolean[][] seen;
    private static int rows;
    private static int fearCounter = 0;
    private static int cols;
    private static int threshold;
    private static Deque<int[]> deque = new ArrayDeque<>();
    private static int[][] timeGrid;
    private final static int[] dx = {-1,0,1,0};
    private final static int[] dy = {0,-1,0,1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        rows = sc.nextInt();
        cols = sc.nextInt();
        threshold = sc.nextInt();
        sc.nextLine();
        grid = new String[rows][];
        timeGrid = new int[rows][cols];
        seen = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            String line = sc.nextLine();
            grid[i] = line.split("");
        }
        runner();
    }

    private static void runner() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                timeGrid[i][j] = -1;
                seen[i][j] = false;
                if (grid[i][j].equals("0")) {
                    deque.addLast(new int[]{i, j});
                    timeGrid[i][j] = 0;
                    seen[i][j] = true;
                }
            }
        }
        bfs();
    }

    private static void bfs() {
        int currentmax = 0;
        while (!deque.isEmpty()) {
            int[] coords = deque.removeFirst();
            int x = coords[0];
            int y = coords[1];
            if (grid[x][y].equals("F")) {
                continue;
            }
            grid[x][y] = "F";
            seen[x][y] = true;
            fearCounter++;
            if (fearCounter >= threshold) {
                System.out.println(currentmax);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !grid[nx][ny].equals("F")) {
                    if (isInFear(nx, ny) && !seen[nx][ny]) {
                        deque.addLast(new int[] {nx, ny});
                        timeGrid[nx][ny] = timeGrid[x][y] + 1;
                        currentmax = timeGrid[nx][ny];
                    }
                }
            }
        }
        System.out.println("To victory and beyond!");

    }

    private static boolean isInFear(int x, int y) {
        double val = Double.parseDouble(grid[x][y]);
        double fcount = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny].equals("F")) {
                fcount++;
            }
        }
        double num = numOfNeighbours(x, y);
        double a = fcount / num;
        double thresh = val / (double) 4;
        return a >= thresh;
    }

    private static double numOfNeighbours(int x, int y) {
        double numNeighbours = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                ++numNeighbours;
            }
        }
        return numNeighbours;
    }
}
