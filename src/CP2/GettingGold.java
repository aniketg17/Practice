package CP2;

/*
Source : Nordic Collegiate Programming Contest (NCPC) 2008
We’re building an old-school back-to-basics computer game.
It’s a very simple text based adventure game where you walk around and try to find treasure,
avoiding falling into traps. The game is played on a rectangular grid and the player gets
very limited information about her surroundings.

The game will consist of the player moving around on the grid for as long as she
likes (or until she falls into a trap). The player can move up, down, left and right
(but not diagonally). She will pick up gold if she walks into the same square as the gold is.
If the player stands next to (i.e., immediately up, down, left, or right of) one or more traps,
 she will “sense a draft” but will not know from what direction the draft comes, or how many
 traps she’s near. If she tries to walk into a square containing a wall, she will notice that
 there is a wall in that direction and remain in the position where she was.

For scoring purposes, we want to show the player how much gold she could have gotten
safely. That is, how much gold can a player get playing with an optimal strategy and
always being sure that the square she walked into was safe. The player does not have access
to the map and the maps are randomly generated for each game so she has no previous knowledge of the game.
 */

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class GettingGold {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] dims = sc.nextLine().split(" ");
        int col = Integer.parseInt(dims[0]);
        int row = Integer.parseInt(dims[1]);
        int p_r = -1;
        int p_c = -1;
        String[][] grid = new String[row][col];
        boolean[][] seen = new boolean[row][col];
        for (int i = 0; i < row; i++) {
            String[] line = sc.nextLine().split("");
            for (int j = 0; j < col; j++) {
                if (line[j].equals("P")) {
                    p_r = i;
                    p_c = j;
                }
                grid[i][j] = line[j];
            }
        }
        int ans = explore(p_r, p_c, grid, seen);
        System.out.println(ans);
    }

    public static int explore(int p_r, int p_c, String[][] grid, boolean[][] seen) {
        Queue<int[]> q = new LinkedList<>();
        int counter = 0;
        int[] dr = new int[]{0,0,-1,1};
        int[] dc = new int[]{1,-1,0,0};
        q.add(new int[]{p_r, p_c});
        seen[p_r][p_c] = true;

        top: while (!q.isEmpty()) {
            int[] dims = q.remove();
            int r = dims[0];
            int c = dims[1];

            if (grid[r][c].equals("G")) {
                ++counter;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < grid.length &&
                        nc < grid[0].length && grid[nr][nc].equals("T")) {
                    continue top;
                }
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < grid.length && nc < grid[0].length &&
                        !grid[nr][nc].equals("#") && !seen[nr][nc]) {
                    q.add(new int[]{nr, nc});
                    seen[nr][nc] = true;
                }
            }
        }
        return counter;
    }
}
