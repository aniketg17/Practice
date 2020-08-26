package CompetitiveProgramming;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class MaxAreaIsland {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        sc.nextLine();
        int arr[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
            sc.nextLine();
        }
        System.out.println(maxAreaOfIsland(arr));
    }

    public static int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int ans = dfs(grid, i, j, m, n);
                    max = Math.max(max, ans);
                }
            }
        }
        return max;
    }

    public static int dfs(int[][] arr, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || arr[i][j] != 1 ) {
            return 0;
        }

        arr[i][j] = 2;

        return (1 + dfs(arr, i - 1, j, m, n) + dfs(arr, i + 1, j, m, n) +
                dfs(arr, i, j - 1, m, n) + dfs(arr, i, j + 1, m, n));
    }


}
