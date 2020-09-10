package CP2;

import java.util.ArrayList;
import java.util.HashMap;

public class BasinsGraph {
    static int counter = 0;

    public static void main(String[] args) {
        int[][] grid = {{1,5,2}, {2,4,7}, {3,6,9}};
        int[][] grid2 = {{1,0,2,5,8}, {2,3,4,7,9}, {3,5,7,8,9}, {1,2,5,4,3}, {3,3,5,2,1}};
        int[][] grid3 = {{0,2,1,3}, {2,1,0,4}, {3,3,3,3}, {5,5,2,1}};
        int[][] grid4 = {{1}};
        int[][] grid5 = {{1,0,2,5,8}, {2,3,4,7,9}, {3,5,7,9,9}, {1,2,5,5,3}, {3,3,5,1,0}};
        calculateBasins(grid5);
    }

    public static void calculateBasins(int[][] grid) {
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        constructGraph(grid, graph);
        ArrayList<Integer> sizes = new ArrayList<>();
        boolean[] seen = new boolean[grid.length * grid.length];
        for (int sink : graph.keySet()) {
            if (!seen[sink]) {
                counter = 1;
                seen[sink] = true;
                dfs(seen, graph, sink);
                sizes.add(counter);
            }
        }
        sizes.sort((a,b) -> b-a);
        for (int x : sizes) {
            System.out.println(x);
        }
    }

    public static void dfs(boolean[] seen, HashMap<Integer, ArrayList<Integer>> graph, int idx) {
        ArrayList<Integer> list = graph.get(idx);
        if (list != null) {
            for (int x : list) {
                if (!seen[x]) {
                    seen[x] = true;
                    ++counter;
                    dfs(seen, graph, x);
                }
            }
        }
    }

    public static void constructGraph(int[][] grid, HashMap<Integer, ArrayList<Integer>> graph) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                int sink = getMinimumIdx(grid, i, j);
                int curr = getIdx(grid.length, i, j);
                if (graph.getOrDefault(sink, null) == null) {
                    graph.put(sink, new ArrayList<>());
                }
                if (graph.getOrDefault(curr, null) == null) {
                    graph.put(curr, new ArrayList<>());
                }
                if (sink != curr) {
                    graph.get(sink).add(curr);
                    graph.get(curr).add(sink);
                }
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