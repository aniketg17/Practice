public class sortedSquarredArray {

    /*
    Question: Produce an array containing the squares of the input array
    in sorted order.
     */

    public static void main(String[] args) {
        int[] unsorted1 = {-7,-3,-1,4,8,12};
        int[] unsorted2 = {-4,-1,0,3,10};
        int[] unsorted3 = {-7,-3,2,3,11};
        int[] unsorted4 = {-1};
        int[] sorted = sortSquaredArray(unsorted4);
        for (int x : sorted) {
            System.out.print(x + ",");
        }
    }

    public static int[] sortSquaredArray(int[] array) {
        int[] sorted = new int[array.length];

        int start = 0;
        int end = array.length - 1;
        int idx = end;
        for (; start < array.length && array[start] < 0; start++) {
            while (end >= 0 && Math.abs(array[start]) <= array[end]) {
                sorted[idx] = (int) Math.pow(array[end], 2);
                --idx;
                --end;
            }

            sorted[idx] = (int) Math.pow(array[start], 2);
            --idx;
        }

        while (end >= start) {
            sorted[idx] = (int) Math.pow(array[end], 2);
            --idx;
            --end;
        }

        return sorted;
    }
}
