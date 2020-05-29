import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

/*
Problem description:
You are on an 𝑛×𝑚 grid where each square on the grid has a digit on it.
From a given square that has digit 𝑘 on it, a Move consists of
jumping exactly 𝑘 squares in one of the four cardinal directions.
A move cannot go beyond the edges of the grid; it does not wrap.
What is the minimum number of moves required
to get from the top-left corner to the bottom-right corner?
 */

public class KattisGrid {
    private static int[] dx = {1,0,-1,0};
    private static int[] dy = {0,1,0,-1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        sc.nextLine();
        int[][] grid = new int[rows][cols];
        String[][] stringGrid = new String[rows][cols];
        populateGrid(grid, grid.length, grid[0].length, sc, stringGrid);
        int result = shortestPathLength(grid, grid.length, grid[0].length);
        System.out.println(result);
    }

    public static void populateGrid(int[][] grid, int rows, int cols, Scanner sc, String[][] stringGrid) {
        for (int i = 0; i < rows; i++) {
            stringGrid[i] = sc.nextLine().split("");
            for (int j = 0; j < cols; j++) {
                grid[i][j] = Integer.parseInt(stringGrid[i][j]);
            }
        }
    }

    public static int shortestPathLength(int[][] grid, int rows, int cols) {
        ArrayDeque<int[]> idx = new ArrayDeque<>();
        idx.add(new int[]{0,0});
        int[][] dist = new int[rows][cols];
        for (int x = 0; x < dist.length; x++) {
            for (int i = 0; i < dist[0].length; i++) {
                dist[x][i] = -100;
            }
        }
        dist[0][0] = 0;
        while (!idx.isEmpty()) {
            int[] coord = idx.removeFirst();
            int row = coord[0];
            int col = coord[1];
            int multiplier = grid[row][col];
            for (int i = 0; i < 4; i++) {
                int newDx = multiplier * dx[i], newRow = newDx + row;
                int newDy = multiplier * dy[i], newCol = newDy + col;
                if (newRow == rows - 1 && newCol == cols - 1) {
                    return dist[row][col] + 1;
                }
                if (!(newRow < 0 || newRow >= rows ||
                        newCol < 0 || newCol >= cols ||
                        grid[newRow][newCol] == -10 || grid[newRow][newCol] == 0 ||
                        dist[newRow][newCol] != -100)) {
                        dist[row + newDx][col + newDy] = dist[row][col] + 1;
                        idx.addLast(new int[] {row + newDx, col + newDy});
                }
            }
            grid[row][col] = -10;
        }
        return -1;
    }
}
