package CP2;

import java.util.ArrayList;
import java.util.HashMap;

public class BasinsUnion {

    public static void main(String[] args) {
        int[][] grid = {{1,5,2}, {2,4,7}, {3,6,9}};
        int[][] grid2 = {{1,0,2,5,8}, {2,3,4,7,9}, {3,5,7,8,9}, {1,2,5,4,3}, {3,3,5,2,1}};
        int[][] grid3 = {{0,2,1,3}, {2,1,0,4}, {3,3,3,3}, {5,5,2,1}};
        int[][] grid4 = {{1}};
        int[][] grid5 = {{1,0,2,5,8}, {2,3,4,7,9}, {3,5,7,9,9}, {1,2,5,5,3}, {3,3,5,1,0}};
        calculateBasins(grid5);
    }

    public static void calculateBasins(int[][] grid) {
        int[] parents = new int[grid.length * grid.length];
        setUnion(grid, parents);
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                int curr = getIdx(grid.length, i, j);
                int min = getMinimumIdx(grid, i, j);
                union(parents, curr, min);
            }
        }
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                int idx = getIdx(grid.length, i, j);
                int parent = getParent(parents, idx);
                count.put(parent, count.getOrDefault(parent, 0) + 1);
            }
        }
        ArrayList<Integer> sort = new ArrayList<>(count.values());
        sort.sort((a,b) -> b-a);
        for (int x : sort) {
            System.out.println(x);
        }
    }

    public static void union(int[] parents, int val1, int val2) {
        int p1 = getParent(parents, val1);
        int p2 = getParent(parents, val2);
        if (p1 != p2) {
            parents[p1] = p2;
        }
    }

    public static int getParent(int[] parents, int val1) {
        while (val1 != parents[val1]) {
            parents[val1] = parents[parents[val1]];
            val1 = parents[val1];
        }
        return val1;
    }

    public static void setUnion(int[][] grid, int[] parents) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                int idx = getIdx(grid.length, i, j);
                parents[idx] = idx;
            }
        }
    }

    public static int getMinimumIdx(int[][] grid, int r, int c) {
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        int min = grid[r][c];
        int idx = getIdx(grid.length, r , c);
        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if (nr >= 0 && nr < grid.length && nc >= 0 && nc < grid.length) {
                if (min > grid[nr][nc]) {
                    min = Math.min(min, grid[nr][nc]);
                    idx = getIdx(grid.length, nr, nc);
                }
            }
        }
        return idx;
    }

    public static int getIdx(int n, int r, int c) {
        return r*n + c;
    }
}
