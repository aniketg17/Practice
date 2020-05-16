public class sortedSquarredArray {

    /*
    Question: Produce an array containing the squares of the input array
    in sorted order.
     */

    public static void main(String[] args) {
        int[] unsorted1 = {-7,-3,-1,4,8,12};
        int[] unsorted2 = {-4,-1,0,3,10};
        int[] unsorted3 = {-7,-3,2,3,11};
        int[] unsorted4 = {2,2};
        int[] sorted = sortSquaredArray(unsorted4);
        for (int x : sorted) {
            System.out.print(x + ",");
        }
    }

    public static int[] sortSquaredArray(int[] array) {
        int[] sorted = new int[array.length];

        int idx = array.length - 1;
        int j = array.length - 1;
        int i = 0;
        for (; array[i] < 0; i++) {
            while (idx >= 0 && j >= 0 && Math.abs(array[j]) >= Math.abs(array[i])) {
                sorted[idx] = (int) Math.pow(array[j], 2);
                --j;
                --idx;
            }
            if (idx < 0) break;
            sorted[idx] = (int) Math.pow(array[i], 2);
            --idx;
        }

        while (j >= i) {
            sorted[idx] = (int) Math.pow(array[j], 2);
            --j;
            --idx;
        }

        return sorted;
    }
}
