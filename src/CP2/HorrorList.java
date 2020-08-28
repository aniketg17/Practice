package CP2;

/*
It was time for the 7th Nordic Cinema Popcorn Convention, and this year the manager Ian had a brilliant idea.
In addition to the traditional film program, there would be a surprise room where a
 small group of people could stream a random movie from a large collection,
 while enjoying popcorn and martinis.
However, it turned out that some people were extremely disappointed, because they
got to see movies like Ghosts of Mars, which instead caused them to tear out their hair in
despair and horror.

To avoid this problem for the next convention, Ian has come up with a solution,
but he needs your help to implement it. When the group enters the surprise room,
they will type in a list of movies in a computer. This is the so-called horror list,
which consists of bad movies that no one in the group would ever like to see.
Of course, this list varies from group to group.

You also have access to the database Awesome Comparison of Movies which tells
ou which movies are directly similar to which. You can assume that movies that are
similar to bad movies will be almost as bad.
 */

import java.util.*;

public class HorrorList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int horrorLength = sc.nextInt();
        int similarityLength = sc.nextInt();
        sc.nextLine();
        int[] scores = new int[N]; // scores
        Arrays.fill(scores, Integer.MAX_VALUE); // equal to infinity

        String[] horrorID = sc.nextLine().split(" ");
        for (String s : horrorID) {
            int id = Integer.parseInt(s);
            scores[id] = 0;
        }
        ArrayList<Integer>[] neighbours = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            neighbours[i] = new ArrayList<>();
        }
        for (int i = 0; i < similarityLength; i++) {
            String[] vals = sc.nextLine().split(" ");
            int id1 = Integer.parseInt(vals[0]);
            int id2 = Integer.parseInt(vals[1]);
            neighbours[id1].add(id2);
            neighbours[id2].add(id1);
        }

        for (int i = 0; i < N; i++) {
            if (scores[i] == 0) {
                bfs(neighbours, scores, i);
            }
        }

        int max = -10;
        int maxIdx = -1;
        for (int i = 0; i < scores.length; i++) {
            if (scores[i] > max) {
                max = scores[i];
                maxIdx = i;
            }
        }
        System.out.println(maxIdx);
    }


    public static void bfs(ArrayList<Integer>[] allNeighbours,
                           int[] scores, int start) {
        Queue<Data> q = new LinkedList<>();
        boolean[] seen = new boolean[allNeighbours.length];
        seen[start] = true;
        q.add(new Data(start, 0));

        while (!q.isEmpty()) {
            Data val = q.poll();
            int idx = val.idx;
            int level = val.level;
            if (level < scores[idx]) {
                scores[idx] = level;
            }
            ArrayList<Integer> neighbours = allNeighbours[idx];
            for (Integer x : neighbours) {
                if (!seen[x]) {
                    q.add(new Data(x, level+1));
                    seen[x] = true;
                }
            }
        }
    }

    static class Data {
        int idx;
        int level;

        public Data(int idx, int level) {
            this.idx = idx;
            this.level = level;
        }
    }
}
