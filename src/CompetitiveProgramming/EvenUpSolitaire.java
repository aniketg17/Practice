package CompetitiveProgramming;

import java.util.*;

public class EvenUpSolitaire {
    public static void main(String[] args) {


        ArrayList<Integer> ar = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int numOfInputs = sc.nextInt();
        sc.nextLine();

        for (int i = numOfInputs - 1; i > -1; i--) {
            ar.add(sc.nextInt());
        }


        int newSize = 0;
        int oldSize = 1;
        while (newSize != oldSize) {
            oldSize = ar.size();
            for (int i = 0; i < ar.size() - 1; i++) {
                int item1 = ar.get(i);
                int item2 = ar.get(i+1);

                if ((item1 + item2) % 2 == 0) {
                    ar.remove(i);
                    ar.remove(i);
                    i = -1;
                }
            }

            newSize = ar.size();
        }

        System.out.println(newSize);

















//        Queue q = new LinkedList();
//        Stack<Integer> stack = new Stack<>();
//        Scanner sc = new Scanner(System.in);
//        int numOfInputs = sc.nextInt();
//        sc.nextLine();
//
//        for (int i = numOfInputs - 1; i >-1; i--) {
//            q.add(sc.nextInt());
//        }
//
//        boolean addedAlready = false;
//        boolean exists = true;
//
//        while (true) {
//
//            try {
//                int item1 = (int) q.remove();
//                int item2 = (int) q.peek();
//
//                if ((item1 + item2) % 2 != 0) {
//                    stack.add(item1);
//                } else {
//                    q.remove();
//                }
//            } catch (NullPointerException | NoSuchElementException e) {
//                break;
//            }
//        }
//
//        System.out.println(stack.size());

    }

}

