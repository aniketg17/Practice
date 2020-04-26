import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.util.*;

public class LargestJelly {


    private static int localMax = 0;
    static ArrayList<Integer> area = new ArrayList<>();
    static ArrayList<Integer> perimeters = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        sc.nextLine();
        String[][] grid = new String[a][];
        String[][] grid3 = new String[a][];
        for (int i = 0; i < a; i++) {
            String line = sc.nextLine();
            grid[i] = line.split("");
            grid3[i] = line.split("");
        }

        runner(grid, grid3);

        ArrayList<Integer> fin = new ArrayList<>();
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < area.size(); i++) {
            if (area.get(i) > max) {
                fin.clear();
                fin.add(i);
                max = area.get(i);
                continue;
            }
            if (area.get(i) == max) {
                fin.add(i);
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < fin.size(); i++) {
            if (perimeters.get(fin.get(i)) < min) {
                min = perimeters.get(fin.get(i));
            }
        }
            System.out.println(max + " " + min);
    }


    public static void runner(String[][] arr, String[][] arr1) {
        perimeter(arr1);
        dfsArea(arr);

    }

     public static void dfsArea(String[][] grid) {
        boolean[][] seen = new boolean[grid.length][grid[0].length];
        int[] dr = new int[]{0, -1, 0, 1};
        int[] dc = new int[]{-1, 0, 1, 0};

        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j].equals("#") && !seen[i][j]) {
                    int shape = 0;
                    Stack<int[]> stack = new Stack();
                    stack.push(new int[]{i, j});
                    seen[i][j] = true;
                    while (!stack.empty()) {
                        int[] node = stack.pop();
                        int firstElement = node[0];
                        int secondElement = node[1];
                        shape++;
                        for (int k = 0; k < 4; k++) {
                            int numRows = firstElement + dr[k];
                            int numCols = secondElement + dc[k];
                            if (0 <= numRows && numRows < grid.length &&
                                    0 <= numCols && numCols < grid[0].length &&
                                    grid[numRows][numCols].equals("#") && !seen[numRows][numCols]) {
                                stack.push(new int[]{numRows, numCols});
                                seen[numRows][numCols] = true;
                            }
                        }
                    }
                    ans = Math.max(ans, shape);
                    area.add(ans);
                    ans = 0;

                }
            }
        }
    }

    private static void perimeter(String[][] grid) {

        boolean[][] seen = new boolean[grid.length][grid[0].length];
        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, 1, -1};

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j].equals("#") && !seen[i][j]) {
                    Stack<int[]> stack = new Stack<>();
                    stack.push(new int[]{i, j});
                    seen[i][j] = true;
                    while (!stack.empty()) {
                        int[] node = stack.pop();
                        int firstElement = node[0];
                        int secondElement = node[1];
                        for (int k = 0; k < 4; k++) {
                            int newRow = firstElement + dr[k];
                            int newCol = secondElement + dc[k];
                            if (newRow >= grid.length || newRow < 0 || newCol >= grid[0].length || newCol < 0) {
                                localMax = localMax + 1;
                                continue;
                            }

                            if (grid[newRow][newCol].equals(".")) {
                                localMax = localMax + 1;
                                continue;
                            }

                            if (grid[newRow][newCol].equals("#") && !seen[newRow][newCol]) {
                                stack.push(new int[]{newRow, newCol});
                                seen[newRow][newCol] = true;
                            }
                        }
                    }
                    perimeters.add(localMax);
                    localMax = 0;
                }
            }
        }
    }
}
