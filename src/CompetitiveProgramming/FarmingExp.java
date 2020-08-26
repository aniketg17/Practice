package CompetitiveProgramming;

import java.awt.*;
import java.util.*;

/*
Kirito is playing a game called Sword Art Online. He wants to level up faster,
so he arrives at a dungeon where all the monsters can be killed in one hit,
which is suitable for exp farming. Each type of monster respawns once a while,
allowing him to keep killing them and gaining the experience points.
Given a list of monster spawning rules, and assume Kirito kills a monster
immediately when it spawns, can you predict how Kirito’s kill log looks like?

Input Format

The first part of the input contains only one line, the number of spawning rules N.

The second part of the input is a list of spawning rules, in the following format:

Monster [Monster ID] [Respawn Interval]
For example:

Monster 35 15
Monster 37 40
Monster 38 2
The final part of the input contains only one line, the number of kill entries K you should output.

Constraints

N <= 1000

Monster ID >= 1

Respawn Interval <= 3000

K <= 500000

Output Format : Killed [Monster ID];  If more than one monster spawns at the same time,
Kirito kills them in the ascending order of their IDs.

Sample Input 0

2
Monster 61 200
Monster 203 300
5
Sample Output 0

Killed 61
Killed 203
Killed 61
Killed 61
Killed 203

 */


public class FarmingExp {
    public static void main(String[] args) {
        Comparator<Monster> comparator = new MonsterComparator();
        Scanner sc = new Scanner(System.in);
        int numEntries = sc.nextInt();
        sc.nextLine();
        PriorityQueue<Monster> monsters = new PriorityQueue<>(comparator);
        for (int i = 0; i < numEntries; i++) {
            String[] line = sc.nextLine().split(" ");
            Monster monster = new Monster(Integer.parseInt(line[1]), Integer.parseInt(line[2]));
            monsters.add(monster);
        }
        int numSimulations = sc.nextInt();
        sc.nextLine();
        ArrayList<String> killed = new ArrayList<>();
        killed = simulate(monsters, killed, numSimulations);
        for (String x : killed) {
            System.out.println("Killed " + x);
        }
    }

    private static class MonsterComparator implements Comparator<Monster> {

        @Override
        public int compare(Monster monster, Monster t1) {
            if (monster.time < t1.time) {
                return -1;
            } else if (monster.time > t1.time) {
                return 1;
            } else {
                if (monster.id < t1.id) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }

    public static ArrayList<String> simulate(PriorityQueue<Monster> queue,
                                              ArrayList<String> result, int numSimulations) {
        int counter = 0;
        while (counter < numSimulations) {
            Monster pop = queue.poll();
            pop.update();
            result.add(Integer.toString(pop.id));
            queue.add(pop);
            ++counter;
        }
        return result;
    }

    private static class Monster {
        private int time;
        private int id;
        private int increment;

        public Monster(int id, int time) {
            this.time = time;
            this.id = id;
            this.increment = time;
        }

        public void update() {
            this.time += increment;
        }
    }



}
