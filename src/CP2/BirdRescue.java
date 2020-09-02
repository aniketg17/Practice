package CP2;

import java.util.*;

// Kattis: BirdRescue

public class BirdRescue {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); //  num of friends
        int q = sc.nextInt(); // num of queries
        sc.nextLine();
        int xB = sc.nextInt();
        int yB = sc.nextInt();
        sc.nextLine();

        int[] distances = new int[2000002];

        for(int i = 0; i < n; i++) {
            ArrayList<Integer> xCoords = new ArrayList<>();
            ArrayList<Integer> yCoords = new ArrayList<>();
            xCoords.add(sc.nextInt());
            yCoords.add(sc.nextInt());
            xCoords.add(sc.nextInt());
            yCoords.add(sc.nextInt());
            sc.nextLine();
            xCoords.sort(Integer::compareTo);
            yCoords.sort(Integer::compareTo);

            // add if the val is in the middle to potentially split the area
            if(xCoords.get(0) <= xB && xB <= xCoords.get(1)) {
                xCoords.add(xB);
            }
            if(yCoords.get(0) <= yB && yB <= yCoords.get(1)) {
                yCoords.add(yB);
            }

            ArrayList<Integer> combos = new ArrayList<>();
            for(int x : xCoords) {
                for(int y : yCoords) {
                    int val = Math.abs(x - xB) + Math.abs(y - yB);
                    combos.add(val);
                }
            }
            combos.sort(Integer::compareTo);
            distances[combos.get(0)]++;
            distances[combos.get(combos.size() - 1) + 1]--;
        }

        int sum = 0;
        for(int i = 0; i < distances.length; i++) {
            sum += distances[i];
            distances[i] = sum;
        }

        for(int i = 0; i < q; i++) {
            System.out.println(distances[sc.nextInt()]);
            sc.nextLine();
        }
    }
}

